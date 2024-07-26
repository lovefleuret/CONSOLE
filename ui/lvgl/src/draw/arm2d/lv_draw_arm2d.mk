CSRCS += lv_gpu_arm2d.c

DEPPATH += --dep-path $(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/arm2d
VPATH += :$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/arm2d

CFLAGS += "-I$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/arm2d"
