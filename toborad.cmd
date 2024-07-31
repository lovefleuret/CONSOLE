cp /mnt/zImage /boot
cp /mnt/dtb文件  /boot
cp /mnt/lib/modules /lib -rfd
sync

make modules //编译内核模块
