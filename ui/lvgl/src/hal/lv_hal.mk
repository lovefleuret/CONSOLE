CSRCS += lv_hal_disp.c
CSRCS += lv_hal_indev.c
CSRCS += lv_hal_tick.c

DEPPATH += --dep-path $(CONSOLE)/$(LVGL_DIR_NAME)/src/hal
VPATH += :$(CONSOLE)/$(LVGL_DIR_NAME)/src/hal

CFLAGS += "-I$(CONSOLE)/$(LVGL_DIR_NAME)/src/hal"
