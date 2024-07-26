CSRCS += lv_gpu_d2_ra6m3.c
CSRCS += lv_gpu_d2_draw_label.c

DEPPATH += --dep-path $(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/renesas
VPATH += :$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/renesas

CFLAGS += "-I$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/renesas"
