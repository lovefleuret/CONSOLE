CSRCS += lv_gpu_swm341_dma2d.c

DEPPATH += --dep-path $(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/swm341_dma2d
VPATH += :$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/swm341_dma2d

CFLAGS += "-I$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/swm341_dma2d"
