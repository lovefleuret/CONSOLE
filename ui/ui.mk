include $(CONSOLE)/$(UI_DIR_NAME)/lvgl/lvgl.mk
include $(CONSOLE)/$(UI_DIR_NAME)/lv_drivers/lv_drivers.mk

CSRCS += $(wildcard $(CONSOLE)/ui/*.c)
