#!/bin/bash
make mrproper
make imx6ull_defconfig
bear --append make zImage -j4
bear --append make dtbs
