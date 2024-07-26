#
# Makefile
#
# ⭐全速编译命令： make clean && make -j$(nproc)

CC ?= gcc
# CC := arm-buildroot-linux-gnueabihf-gcc	# 注意配置工具链！
LVGL_DIR_NAME ?= lvgl
CONSOLE ?= ${shell pwd}

CFLAGS ?= -O3 -g0 -I$(CONSOLE)/include $(CONSOLE) -Wall -Wshadow -Wundef -Wmissing-prototypes -Wno-discarded-qualifiers -Wall -Wextra -Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith -fno-strict-aliasing -Wno-error=cpp -Wuninitialized -Wmaybe-uninitialized -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic -Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated -Wempty-body -Wtype-limits -Wshift-negative-value -Wstack-usage=2048 -Wno-unused-value -Wno-unused-parameter -Wno-missing-field-initializers -Wuninitialized -Wmaybe-uninitialized -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wpointer-arith -Wno-cast-qual -Wmissing-prototypes -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wno-discarded-qualifiers -Wformat-security -Wno-ignored-qualifiers -Wno-sign-compare
CFLAGS += -I $(shell pwd)/include -I $(shell pwd)/kawaii-mqtt/common/log -I $(shell pwd)/kawaii-mqtt/platform/linux
CFLAGS += -I $(shell pwd)/kawaii-mqtt/mqtt/  \
          -I $(shell pwd)/kawaii-mqtt/common \
	  -I $(shell pwd)/kawaii-mqtt/network/mbedtls/include \
	  -I $(shell pwd)/kawaii-mqtt/network \
	  -I $(shell pwd)/kawaii-mqtt/mqttclient \
	  -I $(shell pwd)/kawaii-mqtt/network/mbedtls/wrapper \
	  -I $(shell pwd)/kawaii-mqtt/network/mbedtls/include/mbedtls


LDFLAGS ?= -lm 
LDFLAGS += -lpthread

BIN = LVGL


#Collect the files to compile
MAINSRC = ./main.c

include $(CONSOLE)/lvgl/lvgl.mk
include $(CONSOLE)/lv_drivers/lv_drivers.mk
# include $(CONSOLE)/lv_100ask_teach_demos/lv_100ask_teach_demos.mk
# include $(CONSOLE)/lv_demos/lv_demo.mk
include $(CONSOLE)/led/led.mk
include $(CONSOLE)/kawaii-mqtt/kawai-mqtt.mk


OBJEXT ?= .o

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))

MAINOBJ = $(MAINSRC:.c=$(OBJEXT))

SRCS = $(ASRCS) $(CSRCS) $(MAINSRC)
OBJS = $(AOBJS) $(COBJS)

## MAINOBJ -> OBJFILES

all: default

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"
    
default: $(AOBJS) $(COBJS) $(MAINOBJ)
	$(CC) -o $(BIN) $(MAINOBJ) $(AOBJS) $(COBJS) $(LDFLAGS)
	mkdir -p $(CONSOLE)/obj $(CONSOLE)/bin
	find . -type f -name "*.o" -exec mv {} $(CONSOLE)/obj/ \;
	mv $(BIN) $(CONSOLE)/bin/

clean: 
	rm -f $(BIN) $(AOBJS) $(COBJS) $(MAINOBJ) ./bin/* ./obj/*


