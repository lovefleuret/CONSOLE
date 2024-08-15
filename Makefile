# Makefile
#
# 全速编译命令： make clean && make -j$(nproc)


KCONFIG = config
CONFIG = .config
CONFIG_TIMESTAMP = .config.timestamp
DRIVER_DIR = ./hardware_driver
KERNEL_DIR = ./Linux-4.9.88-kernel
-include $(CONFIG)
TOOL = ./scripts/mconf
TRACK = bear

# CC ?= gcc
CC := arm-buildroot-linux-gnueabihf-gcc	
LVGL_DIR_NAME ?= lvgl
UI_DIR_NAME ?= ui
CONSOLE ?= ${shell pwd}

CFLAGS ?= -O3 -g0 -I$(CONSOLE)/$(UI_DIR_NAME)  -Wall -Wshadow -Wundef -Wmissing-prototypes -Wno-discarded-qualifiers -Wall -Wextra -Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith -fno-strict-aliasing -Wno-error=cpp -Wuninitialized -Wmaybe-uninitialized -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic -Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated -Wempty-body -Wtype-limits -Wshift-negative-value -Wstack-usage=2048 -Wno-unused-value -Wno-unused-parameter -Wno-missing-field-initializers -Wuninitialized -Wmaybe-uninitialized -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wpointer-arith -Wno-cast-qual -Wmissing-prototypes -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wno-discarded-qualifiers -Wformat-security -Wno-ignored-qualifiers -Wno-sign-compare
CFLAGS += -I $(shell pwd)/include -I $(shell pwd)/kawaii-mqtt/common/log -I $(shell pwd)/kawaii-mqtt/platform/linux
CFLAGS += -I $(shell pwd)/kawaii-mqtt/mqtt/  \
          -I $(shell pwd)/kawaii-mqtt/common \
			-I $(shell pwd)/kawaii-mqtt/network/mbedtls/include \
			-I $(shell pwd)/kawaii-mqtt/network \
			-I $(shell pwd)/kawaii-mqtt/mqttclient \
			-I $(shell pwd)/kawaii-mqtt/network/mbedtls/wrapper \
			-I $(shell pwd)/kawaii-mqtt/network/mbedtls/include/mbedtls \
			-I $(CONSOLE)/ui \
			-I $(CONSOLE)/usr_thread \
			-I $(CONSOLE)/kawaii-mqtt \


ifeq ($(CONFIG_DEBUG), y)
	CFLAGS += -DCONFIG_DEBUG
endif

LDFLAGS ?= -lm 
LDFLAGS += -lpthread

BIN = CONSOLE.bin


# Collect the files to compile
MAINSRC = ./main.c 


# include $(CONSOLE)/lv_demos/lv_demo.mk
include $(CONSOLE)/kawaii-mqtt/kawai-mqtt.mk
include $(CONSOLE)/ui/ui.mk
include $(CONSOLE)/usr_thread/usr_thread.mk

OBJEXT ?= .o

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))

MAINOBJ = $(MAINSRC:.c=$(OBJEXT))

SRCS = $(ASRCS) $(CSRCS) $(MAINSRC)
OBJS = $(AOBJS) $(COBJS) $(MAINOBJ)



all: default driver kernel
	@echo -e "\e[47m------------------------------------------------------------------------------\e[0m"
	@echo -e "\e[47m---------------------------Build all files success*_*-------------------------\e[0m"
	@echo -e "\e[47m------------------------------------------------------------------------------\e[0m"

driver: kernel
	$(TRACK) $(MAKE) -C $(DRIVER_DIR)

kernel:
	$(TRACK) $(MAKE) -C $(KERNEL_DIR) imx6ull_defconfig
	$(TRACK) $(MAKE) -C $(KERNEL_DIR) dtbs
	$(TRACK) $(MAKE) -C $(KERNEL_DIR) zImage -j4

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC $<"


# Ensure all object files are rebuilt if .config changes
$(AOBJS) $(COBJS) $(MAINOBJ): $(CONFIG_TIMESTAMP)

# Update timestamp if .config changes
$(CONFIG_TIMESTAMP): $(CONFIG)
	@touch $(CONFIG_TIMESTAMP)


default: $(AOBJS) $(COBJS) $(MAINOBJ)
	$(CC) -o $(BIN) $(MAINOBJ) $(AOBJS) $(COBJS) $(LDFLAGS)
	mkdir -p $(CONSOLE)/obj $(CONSOLE)/bin
	mv $(BIN) $(CONSOLE)/bin/


# 配置菜单
menuconfig:
	@if [ ! -f $(KCONFIG)/Kconfig ]; then \
		echo "Kconfig file not found!"; \
		exit 1; \
	fi
	$(TOOL) $(KCONFIG)/Kconfig
	@touch $(CONFIG)

# 生成 .config 文件
.config:
	touch .config
	$(MAKE) menuconfig

clean_app: 
	rm -f $(BIN) $(AOBJS) $(COBJS) $(MAINOBJ) ./bin/* ./obj/*
	rm -f $(CONFIG_TIMESTAMP)
	@echo -e "\e[47m------------------------------------------------------------------------------\e[0m"
	@echo -e "\e[47m---------------------------Clean all app_files success*_*-------------------------\e[0m"
	@echo -e "\e[47m------------------------------------------------------------------------------\e[0m"

kernel_clean: driver_clean
	$(MAKE) -C $(KERNEL_DIR) mrproper


driver_clean:
	$(MAKE) -C $(DRIVER_DIR) clean


distclean: clean_app kernel_clean driver_clean
	@echo -e "\e[47m------------------------------------------------------------------------------\e[0m"
	@echo -e "\e[47m---------------------------Distclean all files success*_*---------------------\e[0m"
	@echo -e "\e[47m------------------------------------------------------------------------------\e[0m"

.PHONY: all clean menuconfig distclean driver_clean kernel_clean clean_app
