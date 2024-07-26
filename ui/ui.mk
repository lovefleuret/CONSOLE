include $(CONSOLE)/lvgl/lvgl.mk
include $(CONSOLE)/lv_drivers/lv_drivers.mk

CSRCS += $(wildcard $(CONSOLE)/ui/*.c)
