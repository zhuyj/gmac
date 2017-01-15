#!/bin/sh
if [ -f config-txvh ]; then
	if [ ! -f .config ]; then
		cp -f config-txvh .config
		make oldconfig
	fi
fi
mv drivers/net/ethernet/txvh/secgmac.ko drivers/net/ethernet/txvh/secgmac.ko-bak
make drivers/net/ethernet/txvh/secgmac.ko
if [ -f drivers/net/ethernet/txvh/secgmac.ko ]; then
	if [ -f /lib/modules/4.8.4/kernel/drivers/net/ethernet/txvh/secgmac.ko ]; then
		rmmod secgmac
		cp -f drivers/net/ethernet/txvh/secgmac.ko /lib/modules/4.8.4/kernel/drivers/net/ethernet/txvh/secgmac.ko
		md5sum drivers/net/ethernet/txvh/secgmac.ko
		md5sum /lib/modules/4.8.4/kernel/drivers/net/ethernet/txvh/secgmac.ko
		update-initramfs -u -k $(uname -r)
		modprobe secgmac
	fi
fi
#rmmod txvh_gmac
