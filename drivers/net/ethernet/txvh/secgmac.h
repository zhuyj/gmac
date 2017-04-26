//mac init
#define  MAC_addr_L		0x12345678
#define  MAC_addr_H		0x00001122

#define DRAM1_BASE		0x00040000
#define DRAM0_BASE		0x00010000

////////////////////////////////////////////////////
//MAC_rx_desc in dram1 每个链表1536B, 10包
#define  MAC_RX_BUF			DRAM1_BASE
#define  MAC_RX_BUF_LEN		1536
#define  MAC_RX_BUF_BigPCnt	1
#define  MAC_RX_desc			16
#define  MAC_RX_desc_cnt		10
#define  MAC_RX_desc_ADDR		0X3e00

//MAC_tx_desc in dram0 每个链表1536B,10包
#define  MAC_TX_BUF			DRAM0_BASE
#define  MAC_TX_BUF_LEN			1536
#define  MAC_TX_BUF_BigPCnt		1
#define  MAC_TX_desc			16
#define  MAC_TX_desc_cnt		10
#define  MAC_TX_desc_ADDR   		0X3e00

////////////////////////////////////////////////////
//RX MAC  BAR3  DRAM1_BASE
#define  PCIE_TX_BUF			DRAM1_BASE
#define  PCIE_TX_BUF_LEN		1536
#define  PCIE_TX_BUF_BigPCnt		1
#define  PCIE_TX_desc			16
#define  PCIE_TX_desc_cnt		10
#define  PCIE_TX_desc_ADDR	   	0X3e00

//TX MAC  BAR2  DRAM0_BASE
#define  PCIE_RX_BUF			DRAM0_BASE
#define  PCIE_RX_BUF_LEN		1536
#define  PCIE_RX_BUF_BigPCnt		1
#define  PCIE_RX_desc			16
#define  PCIE_RX_desc_cnt		10
#define  PCIE_RX_desc_ADDR		0X3e00

typedef struct desc
{
	unsigned int sta_ctrl;
	unsigned int ctrl_cnt;
	unsigned int buf1_addr;
	unsigned int buf2_addr;
}typ_desc;

///////////////////////////////////////////////////DRAM0
#define		BAR1_RAM			DRAM2_BASE //0x70000

typ_desc *MAC_rx_desc[MAC_RX_desc_cnt];
typ_desc *MAC_tx_desc[MAC_TX_desc_cnt];

//#define  MAC_Function_SIGN			((unsigned int *)(BAR1_RAM+0X00))
#define  FIMWARE_WORK_STATE			((unsigned int *)(BAR1_RAM+0X04))
#define  MAC_addr_buf_H 			((unsigned int *)(BAR1_RAM+0X08))
#define  MAC_addr_buf_L 			((unsigned int *)(BAR1_RAM+0X0c))

//MAC 缓存 处理指针 
#define	deal_MAC_rx_desc_numb			((unsigned int *)(BAR1_RAM+0X10))
#define	deal_MAC_tx_desc_numb			((unsigned int *)(BAR1_RAM+0X14))

//PCIE_TX_BUF==MAC_RX_BUF
//#define  PCIE_TX_BUF_W_SP 			((unsigned int *)(BAR1_RAM+0X18))
//#define  PCIE_TX_BUF_R_SP 			((unsigned int *)(BAR1_RAM+0X1C))

//PCIE_RX_BUF==MAC_TX_BUF
//#define  PCIE_RX_BUF_W_SP 			((unsigned int *)(BAR1_RAM+0X20))
//#define  PCIE_RX_BUF_R_SP 			((unsigned int *)(BAR1_RAM+0X24))

//申请读取PCIE_TX_BUF 
//"1" 产生中断 FIMWARE SET
//"0" 清除中断 驱动 clr
#define		PCIE_apply_read_init		((unsigned int *)(BAR1_RAM+0X28))

//#define		PCIE_apply_write_init		((unsigned int *)(BAR1_RAM+0X2c))
//"1" 产生中断 FIMWARE set
//"0" 清除中断 驱动 clr

//读取PCIE_TX_BUF 1包ing
//"1" 产生中断 驱动 SET 
//"0" 清除中断 FIMWARE clr
#define		PCIE_read_over		 	((unsigned int *)(BAR1_RAM+0X30))

//写入PCIE_RX_BUF 1包ing
//"1" 产生中断 驱动 SET 
//"0" 清除中断 FIMWARE clr
//#define		PCIE_write_over			((unsigned int *)(BAR1_RAM+0X34))

//可读取PCIE_TX_BUF个数
#define		PCIE_BAR_READ_CNT		((unsigned int *)(BAR1_RAM+0X38))

//可写入PCIE_RX_BUF个数
#define		PCIE_BAR_WRITE_CNT		((unsigned int *)(BAR1_RAM+0X3c))

#define		test_deal_mac_rx		((unsigned int *)(BAR1_RAM+0X40))
#define		test_deal_mac_tx		((unsigned int *)(BAR1_RAM+0X44))
