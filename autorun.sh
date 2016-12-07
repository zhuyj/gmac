#!/bin/sh

# invoke insmod with all arguments we got
# and use a pathname, as insmod doesn't look in . by default

TARGET_PATH=$(find /lib/modules/$(uname -r)/kernel/drivers/net/ethernet -name realtek -type d)
if [ "$TARGET_PATH" = "" ]; then
	TARGET_PATH=$(find /lib/modules/$(uname -r)/kernel/drivers/net -name realtek -type d)
fi
if [ "$TARGET_PATH" = "" ]; then
	TARGET_PATH=/lib/modules/$(uname -r)/kernel/drivers/net
fi
echo
echo "Check old driver and unload it."

check=`lsmod | grep txwh`
if [ "$check" != "" ]; then
        echo "rmmod txwh"
        /sbin/rmmod txwh
fi

echo "Build the module and install"
echo "-------------------------------" >> log.txt
date 1>>log.txt
make $@ all 1>>log.txt || exit 1
module=`ls src/*.ko`
module=${module#src/}
module=${module%.ko}

if [ "$module" = "" ]; then
	echo "No driver exists!!!"
	exit 1
fi

echo "DEPMOD $(uname -r)"
depmod `uname -r`
echo "load module $module"
modprobe $module

is_update_initramfs=n
distrib_list="ubuntu debian"

if [ -r /etc/debian_version ]; then
	is_update_initramfs=y
elif [ -r /etc/lsb-release ]; then
	for distrib in $distrib_list
	do
		/bin/grep -i "$distrib" /etc/lsb-release 2>&1 /dev/null && \
			is_update_initramfs=y && break
	done
fi

if [ "$is_update_initramfs" = "y" ]; then
	if which update-initramfs >/dev/null ; then
		echo "Updating initramfs. Please wait."
		update-initramfs -u -k $(uname -r)
	else
		echo "update-initramfs: command not found"
		exit 1
	fi
fi

sleep 3
sh ./test.sh
sleep 2
arp -s 1.2.3.5 50:7B:9D:4E:53:28
sleep 1
ping -c 2 -I 1.2.3.4 1.2.3.5 
echo "Completed."
exit 0

