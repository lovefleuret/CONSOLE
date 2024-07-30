#!/bin/bash
make mrproper
make imx6ul1_defconfig
bear --append make zImage -j4
bear --append make dtbs
