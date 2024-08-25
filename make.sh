#!/bin/bash
read -p "USE_BEAR=1? [y/n] " answer
#如果是y 执行make USE_BEAR=1 否则执行make USE_BEAR=0
if [ $answer == "y" ]; then
    bear make USE_BEAR=1 -j3
else
    make USE_BEAR=0
fi

