cp /mnt/zImage /boot
cp /mnt/dtb文件  /boot
cp /mnt/lib/modules /lib -rfd
sync

make modules //编译内核模块
make ARCH=arm INSTALL_MOD_PATH="挂在目录" modules_install
