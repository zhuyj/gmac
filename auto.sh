#!/bin/sh
if [ -f config-txvh ]; then
	if [ ! -f .config ]; then
		cp -f config-txvh .config
		make oldconfig
	fi
fi

if [ -f drivers/net/ethernet/txvh/secgmac.ko ]; then
	rm -f drivers/net/ethernet/txvh/secgmac.ko
fi
make drivers/net/ethernet/txvh/secgmac.ko
if [ -f drivers/net/ethernet/txvh/secgmac.ko ]; then
	if [ -f /lib/modules/$(uname -r)/kernel/drivers/net/ethernet/txvh/secgmac.ko ]; then
		rmmod secgmac
		cp -f drivers/net/ethernet/txvh/secgmac.ko /lib/modules/$(uname -r)/kernel/drivers/net/ethernet/txvh/secgmac.ko
		md5sum drivers/net/ethernet/txvh/secgmac.ko
		md5sum /lib/modules/$(uname -r)/kernel/drivers/net/ethernet/txvh/secgmac.ko
		modprobe secgmac
		update-initramfs -u -k $(uname -r)
	fi
fi
#rmmod txvh_gmac
