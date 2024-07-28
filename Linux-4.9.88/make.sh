#!/bin/bash
make mrproper
make 100ask_imx6ul1_defconfig
bear --append make zImage -j4
bear --append make dtbs
