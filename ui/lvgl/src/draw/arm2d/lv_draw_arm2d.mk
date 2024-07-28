CSRCS += lv_gpu_arm2d.c

DEPPATH += --dep-path $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/arm2d
VPATH += :$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/arm2d

CFLAGS += "-I$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/arm2d"
