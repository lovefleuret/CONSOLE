CSRCS += lv_gpu_stm32_dma2d.c

DEPPATH += --dep-path $(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/stm32_dma2d
VPATH += :$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/stm32_dma2d

CFLAGS += "-I$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/stm32_dma2d"
