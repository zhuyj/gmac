#!/bin/sh
if [ -f config-txvh ]; then
	if [ ! -f .config ]; then
		cp -f config-txvh .config
		make oldconfig
	fi
fi
make drivers/net/ethernet/txvh/txvh_gmac.ko
#rmmod txvh_gmac
