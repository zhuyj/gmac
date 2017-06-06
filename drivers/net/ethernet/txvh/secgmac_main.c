/*
 * secgmac_main.c: TXVH secgmac ethernet driver.
 *
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/pci.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/delay.h>
#include <linux/ethtool.h>
#include <linux/mii.h>
#include <linux/if_vlan.h>
#include <linux/crc32.h>
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include <linux/pm_runtime.h>
#include <linux/firmware.h>
#include <linux/pci-aspm.h>
#include <linux/prefetch.h>
#include <linux/ipv6.h>
#include <net/ip6_checksum.h>

#include <asm/io.h>
#include <asm/irq.h>

#define TXVH_VERSION "0.1"
#define MODULENAME "txvh_secgmac"
#define PFX MODULENAME ": "

#define secgmac_debug(fmt, args...) \
	do { if (printk_ratelimit()) { \
		char tmp[256] = {0}; \
		sprintf(tmp, fmt, ## args); \
		printk("secgmac func:%s, line:%d, %s\n", \
			__FUNCTION__, __LINE__, tmp);} }while (0);

#define SECGMAC_MSG_DEFAULT \
	(NETIF_MSG_DRV | NETIF_MSG_PROBE | NETIF_MSG_IFUP | NETIF_MSG_IFDOWN)

#define TX_SLOTS_AVAIL(tp) \
	(tp->dirty_tx + NUM_TX_DESC - tp->cur_tx)

/* A skbuff with nr_frags needs nr_frags+1 entries in the tx queue */
#define TX_FRAGS_READY_FOR(tp,nr_frags) \
	(TX_SLOTS_AVAIL(tp) >= (nr_frags + 1))

/* Maximum number of multicast addresses to filter (vs. Rx-all-multicast).
   The RTL chips use a 64 element hash table based on the Ethernet CRC. */
static const int multicast_filter_limit = 32;

#define MAX_READ_REQUEST_SHIFT	12
#define TX_DMA_BURST	7	/* Maximum PCI burst, '7' is unlimited */
#define InterFrameGap	0x03	/* 3 means InterFrameGap = the shortest one */

#define SECGMAC_BAR_SIZE		0x4000
#define SECGMAC_NAPI_WEIGHT	64
#define NUM_TX_DESC	64	/* Number of Tx descriptor registers */
#define NUM_RX_DESC	256U	/* Number of Rx descriptor registers */
#define R8169_TX_RING_BYTES	(NUM_TX_DESC * sizeof(struct TxDesc))
#define R8169_RX_RING_BYTES	(NUM_RX_DESC * sizeof(struct RxDesc))

#define SECGMAC_TX_TIMEOUT	(6*HZ)
#define RTL8169_PHY_TIMEOUT	(10*HZ)

/* write/read MMIO register */
#define RTL_W8(reg, val8)	writeb ((val8), ioaddr + (reg))
#define RTL_W16(reg, val16)	writew ((val16), ioaddr + (reg))
#define RTL_W32(reg, val32)	writel ((val32), ioaddr + (reg))
#define RTL_R8(reg)		readb (ioaddr + (reg))
#define RTL_R16(reg)		readw (ioaddr + (reg))
#define RTL_R32(reg)		readl (ioaddr + (reg))

enum rtl_tx_desc_version {
	RTL_TD_0	= 0,
	RTL_TD_1	= 1,
};

#define JUMBO_1K	ETH_DATA_LEN
#define JUMBO_4K	(4*1024 - ETH_HLEN - 2)
#define JUMBO_6K	(6*1024 - ETH_HLEN - 2)
#define JUMBO_7K	(7*1024 - ETH_HLEN - 2)
#define JUMBO_9K	(9*1024 - ETH_HLEN - 2)

static const struct pci_device_id secgmac_pci_tbl[] = {
	{ PCI_DEVICE(0x16c3, 0xabcd), },
	{ PCI_VENDOR_ID_DLINK, 0xabcd, 0xabcd, 0xabcd,},
	{0,},
};

MODULE_DEVICE_TABLE(pci, secgmac_pci_tbl);

static int rx_buf_sz = 16383;
static struct {
	u32 msg_enable;
} debug = { -1 };

enum rtl_desc_bit {
	/* First doubleword. */
	DescOwn		= (1 << 31), /* Descriptor is owned by NIC */
	RingEnd		= (1 << 30), /* End of descriptor ring */
	FirstFrag	= (1 << 29), /* First segment of a packet */
	LastFrag	= (1 << 28), /* Final segment of a packet */
};

/* Generic case. */
enum rtl_tx_desc_bit {
	/* First doubleword. */
	TD_LSO		= (1 << 27),		/* Large Send Offload */
#define TD_MSS_MAX			0x07ffu	/* MSS value */

	/* Second doubleword. */
	TxVlanTag	= (1 << 17),		/* Add VLAN tag */
};

/* 8169, 8168b and 810x except 8102e. */
enum rtl_tx_desc_bit_0 {
	/* First doubleword. */
#define TD0_MSS_SHIFT			16	/* MSS position (11 bits) */
	TD0_TCP_CS	= (1 << 16),		/* Calculate TCP/IP checksum */
	TD0_UDP_CS	= (1 << 17),		/* Calculate UDP/IP checksum */
	TD0_IP_CS	= (1 << 18),		/* Calculate IP checksum */
};

/* 8102e, 8168c and beyond. */
enum rtl_tx_desc_bit_1 {
	/* First doubleword. */
	TD1_GTSENV4	= (1 << 26),		/* Giant Send for IPv4 */
	TD1_GTSENV6	= (1 << 25),		/* Giant Send for IPv6 */
#define GTTCPHO_SHIFT			18
#define GTTCPHO_MAX			0x7fU

	/* Second doubleword. */
#define TCPHO_SHIFT			18
#define TCPHO_MAX			0x3ffU
#define TD1_MSS_SHIFT			18	/* MSS position (11 bits) */
	TD1_IPv6_CS	= (1 << 28),		/* Calculate IPv6 checksum */
	TD1_IPv4_CS	= (1 << 29),		/* Calculate IPv4 checksum */
	TD1_TCP_CS	= (1 << 30),		/* Calculate TCP/IP checksum */
	TD1_UDP_CS	= (1 << 31),		/* Calculate UDP/IP checksum */
};

enum rtl_rx_desc_bit {
	/* Rx private */
	PID1		= (1 << 18), /* Protocol ID bit 1/2 */
	PID0		= (1 << 17), /* Protocol ID bit 2/2 */

#define RxProtoUDP	(PID1)
#define RxProtoTCP	(PID0)
#define RxProtoIP	(PID1 | PID0)
#define RxProtoMask	RxProtoIP

	IPFail		= (1 << 16), /* IP checksum failed */
	UDPFail		= (1 << 15), /* UDP/IP checksum failed */
	TCPFail		= (1 << 14), /* TCP/IP checksum failed */
	RxVlanTag	= (1 << 16), /* VLAN tag available */
};

#define RsvdMask	0x3fffc000

struct TxDesc {
	__le32 opts1;
	__le32 opts2;
	__le64 addr;
};

struct RxDesc {
	__le32 opts1;
	__le32 opts2;
	__le64 addr;
};

struct ring_info {
	struct sk_buff	*skb;
	u32		len;
	u8		__pad[sizeof(void *) - sizeof(u32)];
};

enum features {
	RTL_FEATURE_WOL		= (1 << 0),
	RTL_FEATURE_MSI		= (1 << 1),
	RTL_FEATURE_GMII	= (1 << 2),
};

struct rtl8169_counters {
	__le64	tx_packets;
	__le64	rx_packets;
	__le64	tx_errors;
	__le32	rx_errors;
	__le16	rx_missed;
	__le16	align_errors;
	__le32	tx_one_collision;
	__le32	tx_multi_collision;
	__le64	rx_unicast;
	__le64	rx_broadcast;
	__le32	rx_multicast;
	__le16	tx_aborted;
	__le16	tx_underun;
};

struct rtl8169_tc_offsets {
	bool	inited;
	__le64	tx_errors;
	__le32	tx_multi_collision;
	__le16	tx_aborted;
};

enum rtl_flag {
	RTL_FLAG_TASK_ENABLED,
	RTL_FLAG_TASK_SLOW_PENDING,
	RTL_FLAG_TASK_RESET_PENDING,
	RTL_FLAG_TASK_PHY_PENDING,
	RTL_FLAG_MAX
};

struct rtl8169_stats {
	u64			packets;
	u64			bytes;
	struct u64_stats_sync	syncp;
};

#define MAC_Function_SIGN	(tp->bar1_addr+0X00)

struct secgmac_private {
	void __iomem *mmio_addr, *bar1_addr, *bar2_addr, *bar3_addr;	/* memory map physical address */
	spinlock_t lock;
	struct pci_dev *pci_dev;
	struct net_device *dev;
	struct napi_struct napi;
	u32 msg_enable;
	u32 cur_rx; /* Index into the Rx descriptor buffer of next Rx pkt. */
	u32 cur_tx; /* Index into the Tx descriptor buffer of next Rx pkt. */
	u32 secgmac_curtx;
	u32 dirty_tx;
	struct rtl8169_stats rx_stats;
	struct rtl8169_stats tx_stats;
	struct TxDesc *TxDescArray;	/* 256-aligned Tx descriptor ring */
	struct RxDesc *RxDescArray;	/* 256-aligned Rx descriptor ring */
	dma_addr_t TxPhyAddr;
	dma_addr_t RxPhyAddr;
	void *Rx_databuff[NUM_RX_DESC];	/* Rx data buffers */
	struct ring_info tx_skb[NUM_TX_DESC];	/* Tx data buffers */
	struct timer_list rx_timer;
	u16 cp_cmd;

	u16 event_slow;

	struct mdio_ops {
		void (*write)(struct secgmac_private *, int, int);
		int (*read)(struct secgmac_private *, int);
	} mdio_ops;

	struct pll_power_ops {
		void (*down)(struct secgmac_private *);
		void (*up)(struct secgmac_private *);
	} pll_power_ops;

	struct jumbo_ops {
		void (*enable)(struct secgmac_private *);
		void (*disable)(struct secgmac_private *);
	} jumbo_ops;

	struct csi_ops {
		void (*write)(struct secgmac_private *, int, int);
		u32 (*read)(struct secgmac_private *, int);
	} csi_ops;

	int (*set_speed)(struct net_device *, u8 aneg, u16 sp, u8 dpx, u32 adv);
	int (*get_settings)(struct net_device *, struct ethtool_cmd *);
	void (*phy_reset_enable)(struct secgmac_private *tp);
	void (*hw_start)(struct net_device *);
	unsigned int (*phy_reset_pending)(struct secgmac_private *tp);
	unsigned int (*link_ok)(void __iomem *);
	int (*do_ioctl)(struct secgmac_private *tp, struct mii_ioctl_data *data, int cmd);
	bool (*tso_csum)(struct secgmac_private *, struct sk_buff *, u32 *);

	struct {
		DECLARE_BITMAP(flags, RTL_FLAG_MAX);
		struct mutex mutex;
		struct work_struct work;
	} wk;

	unsigned features;

	struct mii_if_info mii;
	dma_addr_t counters_phys_addr;
	struct rtl8169_counters *counters;
	struct rtl8169_tc_offsets tc_offset;
	u32 opts1_mask;

	struct rtl_fw {
		const struct firmware *fw;

#define RTL_VER_SIZE		32

		char version[RTL_VER_SIZE];

		struct rtl_fw_phy_action {
			__le32 *code;
			size_t size;
		} phy_action;
	} *rtl_fw;
#define RTL_FIRMWARE_UNKNOWN	ERR_PTR(-EAGAIN)

	u32 ocp_base;
};

MODULE_AUTHOR("TXVH gmac crew <netdev@vger.kernel.org>");
MODULE_DESCRIPTION("TXVH gmac Gigabit Ethernet driver");
module_param_named(debug, debug.msg_enable, int, 0);
MODULE_PARM_DESC(debug, "Debug verbosity level (0=none, ..., 16=all)");
MODULE_LICENSE("GPL");
MODULE_VERSION(TXVH_VERSION);

static void rtl_lock_work(struct secgmac_private *tp)
{
	mutex_lock(&tp->wk.mutex);
}

static void rtl_unlock_work(struct secgmac_private *tp)
{
	mutex_unlock(&tp->wk.mutex);
}

static void rtl_writephy(struct secgmac_private *tp, int location, u32 val)
{
	tp->mdio_ops.write(tp, location, val);
}

static int rtl_readphy(struct secgmac_private *tp, int location)
{
	return tp->mdio_ops.read(tp, location);
}

static void rtl_ack_events(struct secgmac_private *tp, u16 bits)
{
#if 0
	void __iomem *ioaddr = tp->mmio_addr;

	RTL_W16(IntrStatus, bits);
	mmiowb();
#endif
}

#define RTL_EVENT_NAPI_RX	(RxOK | RxErr)
#define RTL_EVENT_NAPI_TX	(TxOK | TxErr)
#define RTL_EVENT_NAPI		(RTL_EVENT_NAPI_RX | RTL_EVENT_NAPI_TX)

static unsigned int secgmac_gmii_reset_pending(struct secgmac_private *tp)
{
	//void __iomem *ioaddr = tp->mmio_addr;

	//return (RTL_R32(csr0) & 0x1) == 0x1;
	writel(0x1, MAC_Function_SIGN);
	return 1;
}
#if 0
static unsigned int rtl8169_xmii_reset_pending(struct secgmac_private *tp)
{
	return rtl_readphy(tp, MII_BMCR) & BMCR_RESET;
}

static unsigned int rtl8169_tbi_link_ok(void __iomem *ioaddr)
{
	return RTL_R32(TBICSR) & TBILinkOk;
}
#endif
static unsigned int secgmac_gmii_link_ok(void __iomem *ioaddr)
{
	return 1;//RTL_R8(PHYstatus) & LinkStatus;
}

static void secgmac_gmii_reset_enable(struct secgmac_private *tp)
{
	//void __iomem *ioaddr = tp->mmio_addr;

	//RTL_W32(csr0, RTL_R32(csr0) | 0x1);
	writel(0x1, MAC_Function_SIGN);
}

#if 0
static void rtl8169_xmii_reset_enable(struct secgmac_private *tp)
{
	unsigned int val;

	val = rtl_readphy(tp, MII_BMCR) | BMCR_RESET;
	rtl_writephy(tp, MII_BMCR, val & 0xffff);
}
#endif

static void __secgmac_check_link_status(struct net_device *dev,
					struct secgmac_private *tp,
					void __iomem *ioaddr, bool pm)
{
//	if (tp->link_ok(ioaddr)) {
	//	rtl_link_chg_patch(tp);
		/* This is to cancel a scheduled suspend if there's one. */
//		if (pm)
//			pm_request_resume(&tp->pci_dev->dev);
		netif_carrier_on(dev);
		if (net_ratelimit())
			netif_info(tp, ifup, dev, "link up\n");
//	} else {
//		netif_carrier_off(dev);
//		netif_info(tp, ifdown, dev, "link down\n");
//		if (pm)
//			pm_schedule_suspend(&tp->pci_dev->dev, 5000);
//	}
}

static void secgmac_check_link_status(struct net_device *dev,
				      struct secgmac_private *tp,
				      void __iomem *ioaddr)
{
	__secgmac_check_link_status(dev, tp, ioaddr, false);
}

#define WAKE_ANY (WAKE_PHY | WAKE_MAGIC | WAKE_UCAST | WAKE_BCAST | WAKE_MCAST)

static u32 __rtl8169_get_wol(struct secgmac_private *tp)
{
//	void __iomem *ioaddr = tp->mmio_addr;
//	u8 options;
	u32 wolopts = 0;

	return wolopts;
}

static void secgmac_get_drvinfo(struct net_device *dev,
				struct ethtool_drvinfo *info)
{
	struct secgmac_private *tp = netdev_priv(dev);
	struct rtl_fw *rtl_fw = tp->rtl_fw;

	strlcpy(info->driver, MODULENAME, sizeof(info->driver));
	strlcpy(info->version, TXVH_VERSION, sizeof(info->version));
	strlcpy(info->bus_info, pci_name(tp->pci_dev), sizeof(info->bus_info));
	BUILD_BUG_ON(sizeof(info->fw_version) < sizeof(rtl_fw->version));
	if (!IS_ERR_OR_NULL(rtl_fw))
		strlcpy(info->fw_version, rtl_fw->version,
			sizeof(info->fw_version));
}

static int secgmac_set_speed_gmii(struct net_device *dev,
				 u8 autoneg, u16 speed, u8 duplex, u32 ignored)
{
	//struct secgmac_private *tp = netdev_priv(dev);
	//void __iomem *ioaddr = tp->mmio_addr;
	int ret = 0;
	/* speed at 100M, set csr6.16 and csr6.17 to zero, to make
	 * speed as 100M
	 */
	//RTL_W32(csr6, RTL_R32(csr6) & ~(0x1 << 16 | 0x1 << 17));
//	u32 reg;
#if 0
	reg = RTL_R32(TBICSR);
	if ((autoneg == AUTONEG_DISABLE) && (speed == SPEED_1000) &&
	    (duplex == DUPLEX_FULL)) {
		RTL_W32(TBICSR, reg & ~(TBINwEnable | TBINwRestart));
	} else if (autoneg == AUTONEG_ENABLE)
		RTL_W32(TBICSR, reg | TBINwEnable | TBINwRestart);
	else {
		netif_warn(tp, link, dev,
			   "incorrect speed setting refused in TBI mode\n");
		ret = -EOPNOTSUPP;
	}
#endif
	return ret;
}

static netdev_features_t rtl8169_fix_features(struct net_device *dev,
	netdev_features_t features)
{
//	struct secgmac_private *tp = netdev_priv(dev);

	if (dev->mtu > TD_MSS_MAX)
		features &= ~NETIF_F_ALL_TSO;
#if 0
	if (dev->mtu > JUMBO_1K &&
	    !rtl_chip_infos[tp->mac_version].jumbo_tx_csum)
		features &= ~NETIF_F_IP_CSUM;
#endif
	return features;
}

static void __rtl8169_set_features(struct net_device *dev,
				   netdev_features_t features)
{
//	struct secgmac_private *tp = netdev_priv(dev);
	//void __iomem *ioaddr = tp->mmio_addr;
//	u32 rx_config;

	//rx_config = RTL_R32(RxConfig);
	//if (features & NETIF_F_RXALL)
	//	rx_config |= (AcceptErr | AcceptRunt);
	//else
	//	rx_config &= ~(AcceptErr | AcceptRunt);

	//RTL_W32(RxConfig, rx_config);

//	if (features & NETIF_F_RXCSUM)
//		tp->cp_cmd |= RxChkSum;
//	else
//		tp->cp_cmd &= ~RxChkSum;

//	if (features & NETIF_F_HW_VLAN_CTAG_RX)
//		tp->cp_cmd |= RxVlan;
//	else
//		tp->cp_cmd &= ~RxVlan;

//	tp->cp_cmd |= RTL_R16(CPlusCmd) & ~(RxVlan | RxChkSum);

	//RTL_W16(CPlusCmd, tp->cp_cmd);
	//RTL_R16(CPlusCmd);
}

static int rtl8169_set_features(struct net_device *dev,
				netdev_features_t features)
{
	struct secgmac_private *tp = netdev_priv(dev);

	features &= NETIF_F_RXALL | NETIF_F_RXCSUM | NETIF_F_HW_VLAN_CTAG_RX;

	rtl_lock_work(tp);
	if (features ^ dev->features)
		__rtl8169_set_features(dev, features);
	rtl_unlock_work(tp);

	return 0;
}

static inline u32 rtl8169_tx_vlan_tag(struct sk_buff *skb)
{
	return (skb_vlan_tag_present(skb)) ?
		TxVlanTag | swab16(skb_vlan_tag_get(skb)) : 0x00;
}
#if 0
static void rtl8169_rx_vlan_tag(struct RxDesc *desc, struct sk_buff *skb)
{
	u32 opts2 = le32_to_cpu(desc->opts2);

	if (opts2 & RxVlanTag)
		__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), swab16(opts2 & 0xffff));
}
#endif
static int secgmac_gset_gmii(struct net_device *dev, struct ethtool_cmd *cmd)
{
//	struct secgmac_private *tp = netdev_priv(dev);
//	void __iomem *ioaddr = tp->mmio_addr;
	u32 status;

	cmd->supported =
		SUPPORTED_100baseT_Full | SUPPORTED_Autoneg | SUPPORTED_TP;
	cmd->port = PORT_TP;
	cmd->transceiver = XCVR_INTERNAL;

	status = 0; //RTL_R32(TBICSR);
	cmd->advertising = ADVERTISED_Autoneg | ADVERTISED_TP;
	//cmd->autoneg = !!(status & TBINwEnable);

	ethtool_cmd_speed_set(cmd, SPEED_100);
	cmd->duplex = DUPLEX_FULL; /* Always set */

	return 0;
}

#if 0
static int rtl8169_gset_xmii(struct net_device *dev, struct ethtool_cmd *cmd)
{
	struct secgmac_private *tp = netdev_priv(dev);

	return mii_ethtool_gset(&tp->mii, cmd);
}
#endif

static int secgmac_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
	struct secgmac_private *tp = netdev_priv(dev);
	int rc;

	rtl_lock_work(tp);
	rc = tp->get_settings(dev, cmd);
	rtl_unlock_work(tp);

	return rc;
}

static u32 rtl8169_get_msglevel(struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);

	return tp->msg_enable;
}

static void rtl8169_set_msglevel(struct net_device *dev, u32 value)
{
	struct secgmac_private *tp = netdev_priv(dev);

	tp->msg_enable = value;
}

static const char rtl8169_gstrings[][ETH_GSTRING_LEN] = {
	"tx_packets",
	"rx_packets",
	"tx_errors",
	"rx_errors",
	"rx_missed",
	"align_errors",
	"tx_single_collisions",
	"tx_multi_collisions",
	"unicast",
	"broadcast",
	"multicast",
	"tx_aborted",
	"tx_underrun",
};

static int rtl8169_get_sset_count(struct net_device *dev, int sset)
{
	switch (sset) {
	case ETH_SS_STATS:
		return ARRAY_SIZE(rtl8169_gstrings);
	default:
		return -EOPNOTSUPP;
	}
}

static void rtl8169_get_ethtool_stats(struct net_device *dev,
				      struct ethtool_stats *stats, u64 *data)
{
	struct secgmac_private *tp = netdev_priv(dev);
	//struct device *d = &tp->pci_dev->dev;
	struct rtl8169_counters *counters = tp->counters;

	ASSERT_RTNL();

//	pm_runtime_get_noresume(d);

//	if (pm_runtime_active(d))
//		rtl8169_update_counters(dev);

//	pm_runtime_put_noidle(d);

	data[0] = le64_to_cpu(counters->tx_packets);
	data[1] = le64_to_cpu(counters->rx_packets);
	data[2] = le64_to_cpu(counters->tx_errors);
	data[3] = le32_to_cpu(counters->rx_errors);
	data[4] = le16_to_cpu(counters->rx_missed);
	data[5] = le16_to_cpu(counters->align_errors);
	data[6] = le32_to_cpu(counters->tx_one_collision);
	data[7] = le32_to_cpu(counters->tx_multi_collision);
	data[8] = le64_to_cpu(counters->rx_unicast);
	data[9] = le64_to_cpu(counters->rx_broadcast);
	data[10] = le32_to_cpu(counters->rx_multicast);
	data[11] = le16_to_cpu(counters->tx_aborted);
	data[12] = le16_to_cpu(counters->tx_underun);
}

static void rtl8169_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
	switch(stringset) {
	case ETH_SS_STATS:
		memcpy(data, *rtl8169_gstrings, sizeof(rtl8169_gstrings));
		break;
	}
}

static const struct ethtool_ops secgmac_ethtool_ops = {
	.get_drvinfo		= secgmac_get_drvinfo,
//	.get_regs_len		= secgmac_get_regs_len,
	.get_link		= ethtool_op_get_link,
	.get_settings		= secgmac_get_settings,
	//.set_settings		= secgmac_set_settings,
	.get_msglevel		= rtl8169_get_msglevel,
	.set_msglevel		= rtl8169_set_msglevel,
//	.get_regs		= rtl8169_get_regs,
//	.get_wol		= rtl8169_get_wol,
//	.set_wol		= rtl8169_set_wol,
	.get_strings		= rtl8169_get_strings,
	.get_sset_count		= rtl8169_get_sset_count,
	.get_ethtool_stats	= rtl8169_get_ethtool_stats,
	.get_ts_info		= ethtool_op_get_ts_info,
};

#define PHY_READ		0x00000000
#define PHY_DATA_OR		0x10000000
#define PHY_DATA_AND		0x20000000
#define PHY_BJMPN		0x30000000
#define PHY_MDIO_CHG		0x40000000
#define PHY_CLEAR_READCOUNT	0x70000000
#define PHY_WRITE		0x80000000
#define PHY_READCOUNT_EQ_SKIP	0x90000000
#define PHY_COMP_EQ_SKIPN	0xa0000000
#define PHY_COMP_NEQ_SKIPN	0xb0000000
#define PHY_WRITE_PREVIOUS	0xc0000000
#define PHY_SKIPN		0xd0000000
#define PHY_DELAY_MS		0xe0000000

#if 0
struct fw_info {
	u32	magic;
	char	version[RTL_VER_SIZE];
	__le32	fw_start;
	__le32	fw_len;
	u8	chksum;
} __packed;
#endif

static void rtl_release_firmware(struct secgmac_private *tp)
{
	if (!IS_ERR_OR_NULL(tp->rtl_fw)) {
		release_firmware(tp->rtl_fw->fw);
		kfree(tp->rtl_fw);
	}
	tp->rtl_fw = RTL_FIRMWARE_UNKNOWN;
}

static void secgmac_rx_poll_timer(unsigned long __opaque)
{
	struct net_device *dev = (struct net_device *)__opaque;
	struct secgmac_private *tp = netdev_priv(dev);

//	rtl_schedule_task(tp, RTL_FLAG_TASK_PHY_PENDING);
//	secgmac_debug("timer begin!");

	/* this will open soon. this is to avoid the recv disturbing the tx */
	napi_schedule(&tp->napi);
}

static void secgmac_release_board(struct pci_dev *pdev, struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);

	iounmap(tp->mmio_addr);
	tp->mmio_addr = NULL;
	iounmap(tp->bar1_addr);
	tp->bar1_addr = NULL;
	iounmap(tp->bar2_addr);
	tp->bar2_addr = NULL;
	iounmap(tp->bar3_addr);
	tp->bar3_addr = NULL;
	pci_release_regions(pdev);
	pci_clear_mwi(pdev);
	pci_disable_device(pdev);
	free_netdev(dev);
}

static int secgmac_set_mac_address(struct net_device *dev, void *p)
{
//	struct secgmac_private *tp = netdev_priv(dev);
//	struct device *d = &tp->pci_dev->dev;
	struct sockaddr *addr = p;

	if (!is_valid_ether_addr(addr->sa_data))
		return -EADDRNOTAVAIL;

	memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);

//	pm_runtime_get_noresume(d);

//	if (pm_runtime_active(d))
//		rtl_rar_set(tp, dev->dev_addr);

//	pm_runtime_put_noidle(d);

	return 0;
}

static int secgmac_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
	struct secgmac_private *tp = netdev_priv(dev);
	struct mii_ioctl_data *data = if_mii(ifr);

	return netif_running(dev) ? tp->do_ioctl(tp, data, cmd) : -ENODEV;
}

static int secgmac_gmii_ioctl(struct secgmac_private *tp,
			  struct mii_ioctl_data *data, int cmd)
{
	switch (cmd) {
	case SIOCGMIIPHY:
		data->phy_id = 32; /* Internal PHY */
		return 0;

	case SIOCGMIIREG:
		data->val_out = rtl_readphy(tp, data->reg_num & 0x1f);
		return 0;

	case SIOCSMIIREG:
		rtl_writephy(tp, data->reg_num & 0x1f, data->val_in);
		return 0;
	}
	return -EOPNOTSUPP;
}

static void rtl_disable_msi(struct pci_dev *pdev, struct secgmac_private *tp)
{
	if (tp->features & RTL_FEATURE_MSI) {
		pci_disable_msi(pdev);
		tp->features &= ~RTL_FEATURE_MSI;
	}
}

#if 0
static void rtl_init_mdio_ops(struct secgmac_private *tp)
{
	struct mdio_ops *ops = &tp->mdio_ops;

	switch (tp->mac_version) {
	case RTL_GIGA_MAC_VER_27:
		ops->write	= r8168dp_1_mdio_write;
		ops->read	= r8168dp_1_mdio_read;
		break;
	case RTL_GIGA_MAC_VER_28:
	case RTL_GIGA_MAC_VER_31:
		ops->write	= r8168dp_2_mdio_write;
		ops->read	= r8168dp_2_mdio_read;
		break;
	case RTL_GIGA_MAC_VER_40:
	case RTL_GIGA_MAC_VER_41:
	case RTL_GIGA_MAC_VER_42:
	case RTL_GIGA_MAC_VER_43:
	case RTL_GIGA_MAC_VER_44:
	case RTL_GIGA_MAC_VER_45:
	case RTL_GIGA_MAC_VER_46:
	case RTL_GIGA_MAC_VER_47:
	case RTL_GIGA_MAC_VER_48:
	case RTL_GIGA_MAC_VER_49:
	case RTL_GIGA_MAC_VER_50:
	case RTL_GIGA_MAC_VER_51:
		ops->write	= r8168g_mdio_write;
		ops->read	= r8168g_mdio_read;
		break;
	default:
		ops->write	= r8169_mdio_write;
		ops->read	= r8169_mdio_read;
		break;
	}
}

static void rtl_speed_down(struct secgmac_private *tp)
{
	u32 adv;
	int lpa;

	rtl_writephy(tp, 0x1f, 0x0000);
	lpa = rtl_readphy(tp, MII_LPA);

	if (lpa & (LPA_10HALF | LPA_10FULL))
		adv = ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full;
	else if (lpa & (LPA_100HALF | LPA_100FULL))
		adv = ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
		      ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full;
	else
		adv = ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
		      ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full |
		      (tp->mii.supports_gmii ?
		       ADVERTISED_1000baseT_Half |
		       ADVERTISED_1000baseT_Full : 0);

	rtl8169_set_speed(tp->dev, AUTONEG_ENABLE, SPEED_1000, DUPLEX_FULL,
			  adv);
}
#endif

static void rtl_wol_suspend_quirk(struct secgmac_private *tp)
{
#if 0
	void __iomem *ioaddr = tp->mmio_addr;

	switch (tp->mac_version) {
	case RTL_GIGA_MAC_VER_25:
	case RTL_GIGA_MAC_VER_26:
	case RTL_GIGA_MAC_VER_29:
	case RTL_GIGA_MAC_VER_30:
	case RTL_GIGA_MAC_VER_32:
	case RTL_GIGA_MAC_VER_33:
	case RTL_GIGA_MAC_VER_34:
	case RTL_GIGA_MAC_VER_37:
	case RTL_GIGA_MAC_VER_38:
	case RTL_GIGA_MAC_VER_39:
	case RTL_GIGA_MAC_VER_40:
	case RTL_GIGA_MAC_VER_41:
	case RTL_GIGA_MAC_VER_42:
	case RTL_GIGA_MAC_VER_43:
	case RTL_GIGA_MAC_VER_44:
	case RTL_GIGA_MAC_VER_45:
	case RTL_GIGA_MAC_VER_46:
	case RTL_GIGA_MAC_VER_47:
	case RTL_GIGA_MAC_VER_48:
	case RTL_GIGA_MAC_VER_49:
	case RTL_GIGA_MAC_VER_50:
	case RTL_GIGA_MAC_VER_51:
		RTL_W32(RxConfig, RTL_R32(RxConfig) |
			AcceptBroadcast | AcceptMulticast | AcceptMyPhys);
		break;
	default:
		break;
	}
#endif
}

static void rtl8169_init_ring_indexes(struct secgmac_private *tp)
{
	tp->dirty_tx = tp->cur_tx = tp->cur_rx = 0;
}

static void secgmac_hw_reset(struct secgmac_private *tp)
{
	//void __iomem *ioaddr = tp->mmio_addr;

	/* soft reset */
	writel(0x1, MAC_Function_SIGN);

//	rtl_udelay_loop_wait_low(tp, &rtl_chipcmd_cond, 100, 100);
}

static void rtl8169_hw_reset(struct secgmac_private *tp)
{
}

static void rtl_set_rx_mode(struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);
	//void __iomem *ioaddr = tp->mmio_addr;
	u32 mc_filter[2];	/* Multicast hash filter */
	//int rx_mode;
	//u32 tmp = 0;

	if (dev->flags & IFF_PROMISC) {
		/* Unconditionally log net taps. */
		netif_notice(tp, link, dev, "Promiscuous mode enabled\n");
//		rx_mode =
//		    AcceptBroadcast | AcceptMulticast | AcceptMyPhys |
//		    AcceptAllPhys;
		mc_filter[1] = mc_filter[0] = 0xffffffff;
	} else if ((netdev_mc_count(dev) > multicast_filter_limit) ||
		   (dev->flags & IFF_ALLMULTI)) {
		/* Too many to filter perfectly -- accept all multicasts. */
		//rx_mode = AcceptBroadcast | AcceptMulticast | AcceptMyPhys;
		mc_filter[1] = mc_filter[0] = 0xffffffff;
	} else {
		struct netdev_hw_addr *ha;

		//rx_mode = AcceptBroadcast | AcceptMyPhys;
		mc_filter[1] = mc_filter[0] = 0;
		netdev_for_each_mc_addr(ha, dev) {
			int bit_nr = ether_crc(ETH_ALEN, ha->addr) >> 26;
			mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
			//rx_mode |= AcceptMulticast;
		}
	}

//	if (dev->features & NETIF_F_RXALL)
//		rx_mode |= (AcceptErr | AcceptRunt);
#if 0
	tmp = (RTL_R32(RxConfig) & ~RX_CONFIG_ACCEPT_MASK) | rx_mode;

	if (tp->mac_version > RTL_GIGA_MAC_VER_06) {
		u32 data = mc_filter[0];

		mc_filter[0] = swab32(mc_filter[1]);
		mc_filter[1] = swab32(data);
	}

	if (tp->mac_version == RTL_GIGA_MAC_VER_35)
		mc_filter[1] = mc_filter[0] = 0xffffffff;

	RTL_W32(MAR0 + 4, mc_filter[1]);
	RTL_W32(MAR0 + 0, mc_filter[0]);

	RTL_W32(RxConfig, tmp);
#endif
}

static int rtl8169_change_mtu(struct net_device *dev, int new_mtu)
{
//	struct secgmac_private *tp = netdev_priv(dev);

	if (new_mtu < ETH_ZLEN)
#if 0
	    || (new_mtu > rtl_chip_infos[tp->mac_version].jumbo_max)
#endif
		return -EINVAL;
#if 0
	if (new_mtu > ETH_DATA_LEN)
		rtl_hw_jumbo_enable(tp);
	else
		rtl_hw_jumbo_disable(tp);
#endif
	dev->mtu = new_mtu;
	netdev_update_features(dev);

	return 0;
}

static inline void rtl8169_make_unusable_by_asic(struct RxDesc *desc)
{
	desc->addr = cpu_to_le64(0x0badbadbadbadbadull);
	desc->opts1 &= ~cpu_to_le32(DescOwn | RsvdMask);
}

static void rtl8169_free_rx_databuff(struct secgmac_private *tp,
				     void **data_buff, struct RxDesc *desc)
{
	dma_unmap_single(&tp->pci_dev->dev, le64_to_cpu(desc->addr), rx_buf_sz,
			 DMA_FROM_DEVICE);

	kfree(*data_buff);
	*data_buff = NULL;
	rtl8169_make_unusable_by_asic(desc);
}

static inline void rtl8169_mark_to_asic(struct RxDesc *desc, u32 rx_buf_sz)
{
	u32 eor = le32_to_cpu(desc->opts1) & RingEnd;

	/* Force memory writes to complete before releasing descriptor */
	dma_wmb();

	desc->opts1 = cpu_to_le32(DescOwn | eor | rx_buf_sz);
}

static inline void rtl8169_map_to_asic(struct RxDesc *desc, dma_addr_t mapping,
				       u32 rx_buf_sz)
{
	desc->addr = cpu_to_le64(mapping);
	rtl8169_mark_to_asic(desc, rx_buf_sz);
}

static inline void *rtl8169_align(void *data)
{
	return (void *)ALIGN((long)data, 16);
}

static struct sk_buff *rtl8169_alloc_rx_data(struct secgmac_private *tp,
					     struct RxDesc *desc)
{
	void *data;
	dma_addr_t mapping;
	struct device *d = &tp->pci_dev->dev;
	struct net_device *dev = tp->dev;
	int node = dev->dev.parent ? dev_to_node(dev->dev.parent) : -1;

	data = kmalloc_node(rx_buf_sz, GFP_KERNEL, node);
	if (!data)
		return NULL;

	if (rtl8169_align(data) != data) {
		kfree(data);
		data = kmalloc_node(rx_buf_sz + 15, GFP_KERNEL, node);
		if (!data)
			return NULL;
	}

	mapping = dma_map_single(d, rtl8169_align(data), rx_buf_sz,
				 DMA_FROM_DEVICE);
	if (unlikely(dma_mapping_error(d, mapping))) {
		if (net_ratelimit())
			netif_err(tp, drv, tp->dev, "Failed to map RX DMA!\n");
		goto err_out;
	}

	rtl8169_map_to_asic(desc, mapping, rx_buf_sz);
	return data;

err_out:
	kfree(data);
	return NULL;
}

static void rtl8169_rx_clear(struct secgmac_private *tp)
{
	unsigned int i;

	for (i = 0; i < NUM_RX_DESC; i++) {
		if (tp->Rx_databuff[i]) {
			rtl8169_free_rx_databuff(tp, tp->Rx_databuff + i,
					    tp->RxDescArray + i);
		}
	}
}

static inline void rtl8169_mark_as_last_descriptor(struct RxDesc *desc)
{
	desc->opts1 |= cpu_to_le32(RingEnd);
}

static int rtl8169_rx_fill(struct secgmac_private *tp)
{
	unsigned int i;

	for (i = 0; i < NUM_RX_DESC; i++) {
		void *data;

		if (tp->Rx_databuff[i])
			continue;

		data = rtl8169_alloc_rx_data(tp, tp->RxDescArray + i);
		if (!data) {
			rtl8169_make_unusable_by_asic(tp->RxDescArray + i);
			goto err_out;
		}
		tp->Rx_databuff[i] = data;
	}

	rtl8169_mark_as_last_descriptor(tp->RxDescArray + NUM_RX_DESC - 1);
	return 0;

err_out:
	rtl8169_rx_clear(tp);
	return -ENOMEM;
}

static int rtl8169_init_ring(struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);

	rtl8169_init_ring_indexes(tp);

	memset(tp->tx_skb, 0x0, NUM_TX_DESC * sizeof(struct ring_info));
	memset(tp->Rx_databuff, 0x0, NUM_RX_DESC * sizeof(void *));

	return rtl8169_rx_fill(tp);
}

static void rtl8169_unmap_tx_skb(struct device *d, struct ring_info *tx_skb,
				 struct TxDesc *desc)
{
	unsigned int len = tx_skb->len;

	dma_unmap_single(d, le64_to_cpu(desc->addr), len, DMA_TO_DEVICE);

	desc->opts1 = 0x00;
	desc->opts2 = 0x00;
	desc->addr = 0x00;
	tx_skb->len = 0;
}

static void rtl8169_tx_clear_range(struct secgmac_private *tp, u32 start,
				   unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++) {
		unsigned int entry = (start + i) % NUM_TX_DESC;
		struct ring_info *tx_skb = tp->tx_skb + entry;
		unsigned int len = tx_skb->len;

		if (len) {
			struct sk_buff *skb = tx_skb->skb;

			rtl8169_unmap_tx_skb(&tp->pci_dev->dev, tx_skb,
					     tp->TxDescArray + entry);
			if (skb) {
				tp->dev->stats.tx_dropped++;
				dev_kfree_skb_any(skb);
				tx_skb->skb = NULL;
			}
		}
	}
}

static void rtl8169_tx_clear(struct secgmac_private *tp)
{
	rtl8169_tx_clear_range(tp, tp->dirty_tx, NUM_TX_DESC);
	tp->cur_tx = tp->dirty_tx = 0;
}

static void secgmac_tx_timeout(struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);

	secgmac_debug(" tx time out! ");
        napi_disable(&tp->napi);
        netif_stop_queue(dev);
        synchronize_sched();

        secgmac_hw_reset(tp);

        napi_enable(&tp->napi);
        netif_wake_queue(dev);
        secgmac_check_link_status(dev, tp, tp->mmio_addr);
}

#if 0
static int rtl8169_xmit_frags(struct secgmac_private *tp, struct sk_buff *skb,
			      u32 *opts)
{
	struct skb_shared_info *info = skb_shinfo(skb);
	unsigned int cur_frag, entry;
	struct TxDesc *uninitialized_var(txd);
	struct device *d = &tp->pci_dev->dev;

	entry = tp->cur_tx;
	for (cur_frag = 0; cur_frag < info->nr_frags; cur_frag++) {
		const skb_frag_t *frag = info->frags + cur_frag;
		dma_addr_t mapping;
		u32 status, len;
		void *addr;

		entry = (entry + 1) % NUM_TX_DESC;

		txd = tp->TxDescArray + entry;
		len = skb_frag_size(frag);
		addr = skb_frag_address(frag);
		mapping = dma_map_single(d, addr, len, DMA_TO_DEVICE);
		if (unlikely(dma_mapping_error(d, mapping))) {
			if (net_ratelimit())
				netif_err(tp, drv, tp->dev,
					  "Failed to map TX fragments DMA!\n");
			goto err_out;
		}

		/* Anti gcc 2.95.3 bugware (sic) */
		status = opts[0] | len |
			(RingEnd * !((entry + 1) % NUM_TX_DESC));

		txd->opts1 = cpu_to_le32(status);
		txd->opts2 = cpu_to_le32(opts[1]);
		txd->addr = cpu_to_le64(mapping);

		tp->tx_skb[entry].len = len;
	}

	if (cur_frag) {
		tp->tx_skb[entry].skb = skb;
		txd->opts1 |= cpu_to_le32(LastFrag);
	}

	return cur_frag;

err_out:
	rtl8169_tx_clear_range(tp, tp->cur_tx + 1, cur_frag);
	return -EIO;
}
#endif

static netdev_tx_t secgmac_start_xmit(struct sk_buff *skb,
				      struct net_device *dev);
#if 0
/* r8169_csum_workaround()
 * The hw limites the value the transport offset. When the offset is out of the
 * range, calculate the checksum by sw.
 */
static void r8169_csum_workaround(struct secgmac_private *tp,
				  struct sk_buff *skb)
{
	if (skb_shinfo(skb)->gso_size) {
		netdev_features_t features = tp->dev->features;
		struct sk_buff *segs, *nskb;

		features &= ~(NETIF_F_SG | NETIF_F_IPV6_CSUM | NETIF_F_TSO6);
		segs = skb_gso_segment(skb, features);
		if (IS_ERR(segs) || !segs)
			goto drop;

		do {
			nskb = segs;
			segs = segs->next;
			nskb->next = NULL;
			secgmac_start_xmit(nskb, tp->dev);
		} while (segs);

		dev_consume_skb_any(skb);
	} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
		if (skb_checksum_help(skb) < 0)
			goto drop;

		secgmac_start_xmit(skb, tp->dev);
	} else {
		struct net_device_stats *stats;

drop:
		stats = &tp->dev->stats;
		stats->tx_dropped++;
		dev_kfree_skb_any(skb);
	}
}
#endif

#define  PCIE_RX_BUF			(tp->bar2_addr)
#define  PCIE_RX_BUF_LEN		0x600
static netdev_tx_t secgmac_start_xmit(struct sk_buff *skb,
				      struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);
	unsigned int entry = tp->cur_tx % 2;
	u32 pkt_size;
	struct ethhdr *eth;

	spin_lock(&tp->lock);
	pkt_size = readl(PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry + 0x5FC);
	if (pkt_size != 0) {
		dev_kfree_skb_any(skb);
		spin_unlock(&tp->lock);
		return NETDEV_TX_OK;
	}

	eth = (struct ethhdr *)skb->data;
	secgmac_debug("\nDst MAC addr: %pM\nSrc MAC addr: %pM\nProtocol: %#06hx",
		       eth->h_dest, eth->h_source, ntohs(eth->h_proto));

	pkt_size = skb_headlen(skb);
	memset_io(PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry, 0, PCIE_RX_BUF_LEN);
	memcpy_toio(PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry, skb->data, pkt_size);
	writeb(skb->data[0], PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry + 0x5FB);
	if (pkt_size > 64) {
		writeb(skb->data[64], PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry + 0x5FA);
		secgmac_debug("0-3 bytes:0x%4x, 4-7 bytes:0x%4x,8-11 bytes:0x%4x,12-15 bytes:0x%4x, 0x5FB:0x%x, 0x5FA:0x%x",
		      readl(PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry),
		      readl(4+PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry),
		      readl(8+PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry),
		      readl(12+PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry),
		      readb(0x5FB+PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry),
		      readb(0x5FA+PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry));
	} else {
		writeb(skb->data[64], PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry + 0x5FA);
		secgmac_debug("0-3 bytes:0x%4x, 4-7 bytes:0x%4x,8-11 bytes:0x%4x,12-15 bytes:0x%4x, 0x5FB:0x%x",
		      readl(PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry),
		      readl(4+PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry),
		      readl(8+PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry),
		      readl(12+PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry),
		      readb(0x5FB+PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry));
	}
	writel(pkt_size, PCIE_RX_BUF + PCIE_RX_BUF_LEN * entry + 0x5FC);//skb length
	spin_unlock(&tp->lock);
	tp->cur_tx = entry + 1;

	dev->stats.tx_packets++;
	dev->stats.tx_bytes += pkt_size;

	if (skb_is_nonlinear(skb)) {
		secgmac_debug("This is the non linear skb!");
	}

	dev_kfree_skb_any(skb);
	return NETDEV_TX_OK;
}

static inline int rtl8169_fragmented_frame(u32 status)
{
	return (status & (FirstFrag | LastFrag)) != (FirstFrag | LastFrag);
}

static inline void rtl8169_rx_csum(struct sk_buff *skb, u32 opts1)
{
	u32 status = opts1 & RxProtoMask;

	if (((status == RxProtoTCP) && !(opts1 & TCPFail)) ||
	    ((status == RxProtoUDP) && !(opts1 & UDPFail)))
		skb->ip_summed = CHECKSUM_UNNECESSARY;
	else
		skb_checksum_none_assert(skb);
}

static irqreturn_t secgmac_interrupt(int irq, void *dev_instance)
{
//	struct net_device *dev = dev_instance;
//	struct secgmac_private *tp = netdev_priv(dev);
	int handled = 0;
	//u16 status;

	secgmac_debug(" ");
#if 0
	status = rtl_get_events(tp);
	if (status && status != 0xffff) {
		status &= RTL_EVENT_NAPI | tp->event_slow;
		if (status) {
			handled = 1;

			//rtl_irq_disable(tp);
			napi_schedule(&tp->napi);
		}
	}
#endif
	return IRQ_RETVAL(handled);
}

#define  PCIE_TX_BUF			(tp->bar3_addr)
#define  PCIE_TX_BUF_LEN		0x600
static int secgmac_poll(struct napi_struct *napi, int budget)
{
	struct secgmac_private *tp = container_of(napi, struct secgmac_private, napi);
	struct net_device *dev = tp->dev;
	int work_done= 1, i;
	struct ethhdr *eth;

//	secgmac_debug("netpoll begin!");
	for (i=0; i<2; i++) {
		struct sk_buff *skb;
		u32 pkt_size;

		pkt_size = readl(PCIE_TX_BUF + PCIE_TX_BUF_LEN * i + 0x5FC);
		if (pkt_size == 0) {
			continue;
		}

		secgmac_debug("packet arrives! pkt_size:0x%08x", pkt_size);
		skb = napi_alloc_skb(napi, 0x5FC);

		spin_lock(&tp->lock);
		memcpy_fromio(skb->data, PCIE_TX_BUF + PCIE_TX_BUF_LEN * i, pkt_size);
		spin_unlock(&tp->lock);

		eth = (struct ethhdr *)skb->data;
		secgmac_debug("Dst MAC addr: %pM\nSrc MAC addr: %pM\nProtocol: %#06hx",
			       eth->h_dest, eth->h_source, ntohs(eth->h_proto));

		skb_put(skb, pkt_size);
		skb->protocol = eth_type_trans(skb, dev);
		secgmac_debug("protocol:0x%04x, pkt_type:0x%x", ntohs(skb->protocol), skb->pkt_type);

		napi_gro_receive(&tp->napi, skb);

		if (skb->pkt_type == PACKET_MULTICAST)
			dev->stats.multicast++;

		spin_lock(&tp->lock);
		writel(0x0, PCIE_TX_BUF + PCIE_TX_BUF_LEN * i + 0x5FC);
		spin_unlock(&tp->lock);

		dev->stats.rx_packets++;
		dev->stats.rx_bytes += pkt_size;
	}

	/* To inform the rx is complete */
	napi_complete(napi);

	mmiowb();
	mod_timer(&tp->rx_timer, jiffies + (1+HZ/20));

	return work_done;
}

static void rtl8169_rx_missed(struct net_device *dev, void __iomem *ioaddr)
{
	//struct secgmac_private *tp = netdev_priv(dev);

//	if (tp->mac_version > RTL_GIGA_MAC_VER_06)
//		return;

	//dev->stats.rx_missed_errors += (RTL_R32(RxMissed) & 0xffffff);
//	RTL_W32(RxMissed, 0);
}

static void secgmac_down(struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);
	void __iomem *ioaddr = tp->mmio_addr;

	del_timer_sync(&tp->rx_timer);

	napi_disable(&tp->napi);
	netif_stop_queue(dev);

	rtl8169_hw_reset(tp);
	/*
	 * At this point device interrupts can not be enabled in any function,
	 * as netif_running is not true (secgmac_interrupt, rtl8169_reset_task)
	 * and napi is disabled (secgmac_poll).
	 */
	rtl8169_rx_missed(dev, ioaddr);

	/* Give a racing hard_start_xmit a few cycles to complete. */
	synchronize_sched();

	rtl8169_tx_clear(tp);

	rtl8169_rx_clear(tp);

//	rtl_pll_power_down(tp);
}

static int secgmac_close(struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);
	struct pci_dev *pdev = tp->pci_dev;

	pm_runtime_get_sync(&pdev->dev);

	/* Update counters before going down */
	//rtl8169_update_counters(dev);

	secgmac_debug(" ");
	rtl_lock_work(tp);
	clear_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);

	secgmac_down(dev);
	rtl_unlock_work(tp);

	cancel_work_sync(&tp->wk.work);

	free_irq(pdev->irq, dev);

	dma_free_coherent(&pdev->dev, R8169_RX_RING_BYTES, tp->RxDescArray,
			  tp->RxPhyAddr);
	dma_free_coherent(&pdev->dev, R8169_TX_RING_BYTES, tp->TxDescArray,
			  tp->TxPhyAddr);
	tp->TxDescArray = NULL;
	tp->RxDescArray = NULL;
#if 0
	kfree(tp->secgmac_txdescArray);
	tp->secgmac_txdescArray = NULL;

	kfree(tp->secgmac_rxdescArray);
	tp->secgmac_rxdescArray = NULL;
#endif
	pm_runtime_put_sync(&pdev->dev);

	return 0;
}

#ifdef CONFIG_NET_POLL_CONTROLLER
static void rtl8169_netpoll(struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);

	secgmac_interrupt(tp->pci_dev->irq, dev);
}
#endif

static int secgmac_open(struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);
	void __iomem *ioaddr = tp->mmio_addr;
	struct pci_dev *pdev = tp->pci_dev;
	int retval = -ENOMEM;

	secgmac_debug(" ");
	/* soft reset */
	writel(0x1, MAC_Function_SIGN);

//	pm_runtime_get_sync(&pdev->dev);

	/*
	 * Rx and Tx descriptors needs 256 bytes alignment.
	 * dma_alloc_coherent provides more.
	 */
	tp->TxDescArray = dma_alloc_coherent(&pdev->dev, R8169_TX_RING_BYTES,
					     &tp->TxPhyAddr, GFP_KERNEL);
	if (!tp->TxDescArray)
		goto err_pm_runtime_put;

	tp->RxDescArray = dma_alloc_coherent(&pdev->dev, R8169_RX_RING_BYTES,
					     &tp->RxPhyAddr, GFP_KERNEL);
	if (!tp->RxDescArray)
		goto err_free_tx_0;

	retval = rtl8169_init_ring(dev);
	tp->cur_tx = 0;
	if (retval < 0)
		goto err_release_fw_2;

//	INIT_WORK(&tp->wk.work, rtl_task);

//	rtl_request_firmware(tp);

	retval = pci_enable_msi(pdev);
	if (!retval) {
		secgmac_debug("msi interrupt is supported!\n");
	} else {
		secgmac_debug("msi interrupt is not supported! retval:%d\n", retval);
	}

	retval = request_irq(pdev->irq, secgmac_interrupt,
			     (tp->features & RTL_FEATURE_MSI) ? 0 : IRQF_SHARED,
			     dev->name, dev);
	if (retval < 0)
		goto err_release_fw_2;
	secgmac_debug("request_irq retval:0x%x", retval);

	rtl_lock_work(tp);

	set_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);

	napi_enable(&tp->napi);
	/* Begin to run poll */
//	napi_schedule(&tp->napi);
	mod_timer(&tp->rx_timer, jiffies + (1+HZ/20));
	secgmac_debug("napi enable!");
//	rtl8169_init_phy(dev, tp);

	__rtl8169_set_features(dev, dev->features);

//	rtl_pll_power_up(tp);

//	rtl_hw_start(dev);
	//printk("txvh func:%s, line:%d\n", __FUNCTION__, __LINE__);
//	if (!rtl8169_init_counter_offsets(dev))
//		netif_warn(tp, hw, dev, "counter reset/update failed\n");

	netif_start_queue(dev);

	rtl_unlock_work(tp);

//	tp->saved_wolopts = 0;
//	pm_runtime_put_noidle(&pdev->dev);

	secgmac_check_link_status(dev, tp, ioaddr);

	dev->stats.tx_packets = 0;
	dev->stats.rx_packets = 0;

	dev->stats.tx_bytes = 0;
	dev->stats.rx_bytes = 0;

	dev->stats.multicast = 0;
out:
	return retval;

err_release_fw_2:
	rtl_release_firmware(tp);
	rtl8169_rx_clear(tp);
//	kfree(tp->secgmac_rxdescArray);
//err_release_fw_1:
//	kfree(tp->secgmac_txdescArray);
//err_free_rx_1:
	dma_free_coherent(&pdev->dev, R8169_RX_RING_BYTES, tp->RxDescArray,
			  tp->RxPhyAddr);
	tp->RxDescArray = NULL;
err_free_tx_0:
	dma_free_coherent(&pdev->dev, R8169_TX_RING_BYTES, tp->TxDescArray,
			  tp->TxPhyAddr);
	tp->TxDescArray = NULL;
err_pm_runtime_put:
	pm_runtime_put_noidle(&pdev->dev);
	goto out;
}

static struct rtnl_link_stats64 *
rtl8169_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *stats)
{
	struct secgmac_private *tp = netdev_priv(dev);
	void __iomem *ioaddr = tp->mmio_addr;
	struct pci_dev *pdev = tp->pci_dev;
	struct rtl8169_counters *counters = tp->counters;
	unsigned int start;

	pm_runtime_get_noresume(&pdev->dev);

	if (netif_running(dev) && pm_runtime_active(&pdev->dev))
		rtl8169_rx_missed(dev, ioaddr);

	do {
		start = u64_stats_fetch_begin_irq(&tp->rx_stats.syncp);
		stats->rx_packets = tp->rx_stats.packets;
		stats->rx_bytes	= tp->rx_stats.bytes;
	} while (u64_stats_fetch_retry_irq(&tp->rx_stats.syncp, start));

	do {
		start = u64_stats_fetch_begin_irq(&tp->tx_stats.syncp);
		stats->tx_packets = tp->tx_stats.packets;
		stats->tx_bytes	= tp->tx_stats.bytes;
	} while (u64_stats_fetch_retry_irq(&tp->tx_stats.syncp, start));

	stats->rx_dropped	= dev->stats.rx_dropped;
	stats->tx_dropped	= dev->stats.tx_dropped;
	stats->rx_length_errors = dev->stats.rx_length_errors;
	stats->rx_errors	= dev->stats.rx_errors;
	stats->rx_crc_errors	= dev->stats.rx_crc_errors;
	stats->rx_fifo_errors	= dev->stats.rx_fifo_errors;
	stats->rx_missed_errors = dev->stats.rx_missed_errors;
	stats->multicast	= dev->stats.multicast;

	/*
	 * Fetch additonal counter values missing in stats collected by driver
	 * from tally counters.
	 */
//	if (pm_runtime_active(&pdev->dev))
//		rtl8169_update_counters(dev);

	/*
	 * Subtract values fetched during initalization.
	 * See rtl8169_init_counter_offsets for a description why we do that.
	 */
	stats->tx_errors = le64_to_cpu(counters->tx_errors) -
		le64_to_cpu(tp->tc_offset.tx_errors);
	stats->collisions = le32_to_cpu(counters->tx_multi_collision) -
		le32_to_cpu(tp->tc_offset.tx_multi_collision);
	stats->tx_aborted_errors = le16_to_cpu(counters->tx_aborted) -
		le16_to_cpu(tp->tc_offset.tx_aborted);

	pm_runtime_put_noidle(&pdev->dev);

	return stats;
}

static void rtl8169_net_suspend(struct net_device *dev)
{
	struct secgmac_private *tp = netdev_priv(dev);

	if (!netif_running(dev))
		return;

	netif_device_detach(dev);
	netif_stop_queue(dev);

	rtl_lock_work(tp);
	napi_disable(&tp->napi);
	clear_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);
	rtl_unlock_work(tp);

//	rtl_pll_power_down(tp);
}

static void rtl_wol_shutdown_quirk(struct secgmac_private *tp)
{
}

static void rtl_shutdown(struct pci_dev *pdev)
{
	struct net_device *dev = pci_get_drvdata(pdev);
	struct secgmac_private *tp = netdev_priv(dev);
	struct device *d = &pdev->dev;

	secgmac_debug(" ");
	pm_runtime_get_sync(d);

	rtl8169_net_suspend(dev);

	/* Restore original MAC address */
	//rtl_rar_set(tp, dev->perm_addr);

	rtl8169_hw_reset(tp);

	if (system_state == SYSTEM_POWER_OFF) {
		if (__rtl8169_get_wol(tp) & WAKE_ANY) {
			rtl_wol_suspend_quirk(tp);
			rtl_wol_shutdown_quirk(tp);
		}

		pci_wake_from_d3(pdev, true);
		pci_set_power_state(pdev, PCI_D3hot);
	}

	pm_runtime_put_noidle(d);
}

static void secgmac_remove_one(struct pci_dev *pdev)
{
	struct net_device *dev = pci_get_drvdata(pdev);
	struct secgmac_private *tp = netdev_priv(dev);

	netif_napi_del(&tp->napi);

	unregister_netdev(dev);

	dma_free_coherent(&tp->pci_dev->dev, sizeof(*tp->counters),
			  tp->counters, tp->counters_phys_addr);

	rtl_release_firmware(tp);

	if (pci_dev_run_wake(pdev))
		pm_runtime_get_noresume(&pdev->dev);

	/* restore original MAC address */
	//rtl_rar_set(tp, dev->perm_addr);

	rtl_disable_msi(pdev, tp);
	secgmac_release_board(pdev, dev);
}

static const struct net_device_ops secgmac_netdev_ops = {
	.ndo_open		= secgmac_open,
	.ndo_stop		= secgmac_close,
	.ndo_get_stats64	= rtl8169_get_stats64,
	.ndo_start_xmit		= secgmac_start_xmit,
	.ndo_tx_timeout		= secgmac_tx_timeout,
	.ndo_validate_addr	= eth_validate_addr,
	.ndo_change_mtu		= rtl8169_change_mtu,
	.ndo_fix_features	= rtl8169_fix_features,
	.ndo_set_features	= rtl8169_set_features,
	.ndo_set_mac_address	= secgmac_set_mac_address,
	.ndo_do_ioctl		= secgmac_ioctl,
	.ndo_set_rx_mode	= rtl_set_rx_mode,
#ifdef CONFIG_NET_POLL_CONTROLLER
	.ndo_poll_controller	= rtl8169_netpoll,
#endif

};

static int secgmac_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
	//const struct rtl_cfg_info *cfg = rtl_cfg_infos + ent->driver_data;
	const unsigned int region = 0; //cfg->region;
	struct secgmac_private *tp;
//	struct mii_if_info *mii;
	struct net_device *dev;
	void __iomem *ioaddr, *bar1_addr, *bar2_addr, *bar3_addr;
//	int chipset, i;
	int rc;

	secgmac_debug(" ");
	if (netif_msg_drv(&debug)) {
		printk(KERN_INFO "%s Gigabit Ethernet driver %s loaded\n",
		       MODULENAME, TXVH_VERSION);
	}

	secgmac_debug(" ");
	dev = alloc_etherdev(sizeof (*tp));
	if (!dev) {
		rc = -ENOMEM;
		goto out;
	}

	secgmac_debug(" ");
	SET_NETDEV_DEV(dev, &pdev->dev);
	dev->netdev_ops = &secgmac_netdev_ops;
	tp = netdev_priv(dev);
	tp->dev = dev;
	tp->pci_dev = pdev;
	tp->msg_enable = netif_msg_init(debug.msg_enable, SECGMAC_MSG_DEFAULT);
	
	secgmac_debug(" ");
#if 0
	mii = &tp->mii;
	mii->dev = dev;
	mii->mdio_read = rtl_mdio_read;
	mii->mdio_write = rtl_mdio_write;
	mii->phy_id_mask = 0x1f;
	mii->reg_num_mask = 0x1f;
#endif
	//mii->supports_gmii = !!(cfg->features & RTL_FEATURE_GMII);

	/* disable ASPM completely as that cause random device stop working
	 * problems as well as full system hangs for some PCIe devices users */
	pci_disable_link_state(pdev, PCIE_LINK_STATE_L0S | PCIE_LINK_STATE_L1 |
				     PCIE_LINK_STATE_CLKPM);

	/* enable device (incl. PCI PM wakeup and hotplug setup) */
	rc = pci_enable_device(pdev);
	if (rc < 0) {
		netif_err(tp, probe, dev, "enable failure\n");
		goto err_out_free_dev_1;
	}

	if (pci_set_mwi(pdev) < 0)
		netif_info(tp, probe, dev, "Mem-Wr-Inval unavailable\n");

	/* make sure PCI base addr 0 is MMIO */
	if (!(pci_resource_flags(pdev, region) & IORESOURCE_MEM)) {
		netif_err(tp, probe, dev,
			  "region #%d not an MMIO resource, aborting\n",
			  region);
		rc = -ENODEV;
		goto err_out_mwi_2;
	}

	/* check for weird/broken PCI region reporting */
	if (pci_resource_len(pdev, region) < SECGMAC_BAR_SIZE) {
		netif_err(tp, probe, dev,
			  "Invalid PCI region size(s), aborting\n");
		rc = -ENODEV;
		goto err_out_mwi_2;
	}
	secgmac_debug("bar 0 length:0x%llx", pci_resource_len(pdev, 0));

	rc = pci_request_regions(pdev, MODULENAME);
	if (rc < 0) {
		netif_err(tp, probe, dev, "could not request regions\n");
		goto err_out_mwi_2;
	}

	/* ioremap MMIO region bar0 */
	ioaddr = ioremap(pci_resource_start(pdev, 0), pci_resource_len(pdev, 0));
	if (!ioaddr) {
		netif_err(tp, probe, dev, "cannot remap MMIO, aborting\n");
		rc = -EIO;
		goto err_out_free_res_3;
	}
	tp->mmio_addr = ioaddr;

	/* ioremap bar1,
	 */
	bar1_addr = ioremap(pci_resource_start(pdev, 1), pci_resource_len(pdev, 1));
	if (bar1_addr == NULL) {
		rc = -EIO;
		secgmac_debug("bar1_addr error!");
		goto err_out_free_res_3;
	}
	tp->bar1_addr = bar1_addr;

	/* ioremap bar2, bar2 for data */
	bar2_addr = ioremap(pci_resource_start(pdev, 2), pci_resource_len(pdev, 2));
	if (bar2_addr == NULL) {
		rc = -EIO;
		secgmac_debug("bar2_addr error!");
		goto err_out_free_res_3;
	}
	tp->bar2_addr = bar2_addr;

	/* ioremap bar3, bar3 for data */
	bar3_addr = ioremap(pci_resource_start(pdev, 3), pci_resource_len(pdev, 3));
	if (bar3_addr == NULL) {
		rc = -EIO;
		secgmac_debug("bar3_addr error!");
		goto err_out_free_res_3;
	}
	tp->bar3_addr = bar3_addr;

	if (!pci_is_pcie(pdev))
		netif_info(tp, probe, dev, "not PCI Express\n");

	/* Identify chip attached to board */
//	rtl8169_get_mac_version(tp, dev, cfg->default_ver);

	tp->cp_cmd = 0;

	if ((sizeof(dma_addr_t) > 4) &&
	    (pci_is_pcie(pdev)) &&
	    !pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {

		/* CPlusCmd Dual Access Cycle is only needed for non-PCIe */
//		if (!pci_is_pcie(pdev))
//			tp->cp_cmd |= PCIDAC;
		dev->features |= NETIF_F_HIGHDMA;
	} else {
		secgmac_debug("set 32 bit DMA mask");
		rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
		if (rc < 0) {
			netif_err(tp, probe, dev, "DMA configuration failed\n");
			goto err_out_unmap_4;
		}
		secgmac_debug("set 32 bit DMA mask successfully!");
	}

	//rtl_init_rxcfg(tp);

	//rtl_irq_disable(tp);

//	rtl_hw_initialize(tp);

	secgmac_hw_reset(tp);

	rtl_ack_events(tp, 0xffff);

	pci_set_master(pdev);

	//rtl_init_mdio_ops(tp);
	//rtl_init_pll_power_ops(tp);
	//rtl_init_jumbo_ops(tp);
	//rtl_init_csi_ops(tp);

	spin_lock_init(&tp->lock);

	tp->set_speed = secgmac_set_speed_gmii;
	tp->get_settings = secgmac_gset_gmii;
	tp->phy_reset_enable = secgmac_gmii_reset_enable;
	tp->phy_reset_pending = secgmac_gmii_reset_pending;
	tp->link_ok = secgmac_gmii_link_ok;
	tp->do_ioctl = secgmac_gmii_ioctl;

	mutex_init(&tp->wk.mutex);
	u64_stats_init(&tp->rx_stats.syncp);
	u64_stats_init(&tp->tx_stats.syncp);

	eth_random_addr(dev->dev_addr);

	dev->ethtool_ops = &secgmac_ethtool_ops;
	dev->watchdog_timeo = SECGMAC_TX_TIMEOUT;
	netif_napi_add(dev, &tp->napi, secgmac_poll, SECGMAC_NAPI_WEIGHT);
	/* don't enable SG, IP_CSUM and TSO by default - it might not work
	 * properly for all devices */
	dev->features |= NETIF_F_RXCSUM |
		NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX;

	dev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_TSO |
		NETIF_F_RXCSUM | NETIF_F_HW_VLAN_CTAG_TX |
		NETIF_F_HW_VLAN_CTAG_RX;
	dev->vlan_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_TSO |
		NETIF_F_HIGHDMA;

	//tp->cp_cmd |= RxChkSum | RxVlan;
#if 0
	/*
	 * Pretend we are using VLANs; This bypasses a nasty bug where
	 * Interrupts stop flowing on high load on 8110SCd controllers.
	 */
	if (tp->mac_version == RTL_GIGA_MAC_VER_05)
		/* Disallow toggling */
		dev->hw_features &= ~NETIF_F_HW_VLAN_CTAG_RX;

	if (tp->txd_version == RTL_TD_0)
		tp->tso_csum = rtl8169_tso_csum_v1;
	else if (tp->txd_version == RTL_TD_1) {
		tp->tso_csum = rtl8169_tso_csum_v2;
		dev->hw_features |= NETIF_F_IPV6_CSUM | NETIF_F_TSO6;
	} else
		WARN_ON_ONCE(1);
#endif
	dev->hw_features |= NETIF_F_RXALL;
	dev->hw_features |= NETIF_F_RXFCS;

#if 0
	tp->hw_start = cfg->hw_start;
	tp->event_slow = cfg->event_slow;

	tp->opts1_mask = (tp->mac_version != RTL_GIGA_MAC_VER_01) ?
		~(RxBOVF | RxFOVF) : ~0;
#endif
	setup_timer(&tp->rx_timer, secgmac_rx_poll_timer, (unsigned long)dev);
	tp->rtl_fw = RTL_FIRMWARE_UNKNOWN;

	tp->counters = dma_alloc_coherent (&pdev->dev, sizeof(*tp->counters),
					   &tp->counters_phys_addr, GFP_KERNEL);
	if (!tp->counters) {
		rc = -ENOMEM;
		goto err_out_msi_5;
	}

	rc = register_netdev(dev);
	if (rc < 0)
		goto err_out_cnt_6;

	pci_set_drvdata(pdev, dev);
	netif_info(tp, probe, dev, "%s at 0x%p, 0x%p, 0x%p, 0x%p, %pM, IRQ %d\n",
		   "secgmac", ioaddr, bar1_addr, bar2_addr, bar3_addr, dev->dev_addr,
		   pdev->irq);
//	device_set_wakeup_enable(&pdev->dev, tp->features & RTL_FEATURE_WOL);
//	if (pci_dev_run_wake(pdev))
//		pm_runtime_put_noidle(&pdev->dev);

	netif_carrier_off(dev);

out:
	secgmac_debug("rc:0x%x", rc);
	return rc;

err_out_cnt_6:
	dma_free_coherent(&pdev->dev, sizeof(*tp->counters), tp->counters,
			  tp->counters_phys_addr);
err_out_msi_5:
	netif_napi_del(&tp->napi);
	rtl_disable_msi(pdev, tp);
err_out_unmap_4:
	iounmap(ioaddr);
err_out_free_res_3:
	pci_release_regions(pdev);
err_out_mwi_2:
	pci_clear_mwi(pdev);
	pci_disable_device(pdev);
err_out_free_dev_1:
	free_netdev(dev);
	goto out;
}

static struct pci_driver secgmac_pci_driver = {
	.name		= MODULENAME,
	.id_table	= secgmac_pci_tbl,
	.probe		= secgmac_init_one,
	.remove		= secgmac_remove_one,
	.shutdown	= rtl_shutdown,
//	.driver.pm	= RTL8169_PM_OPS,
};

module_pci_driver(secgmac_pci_driver);
