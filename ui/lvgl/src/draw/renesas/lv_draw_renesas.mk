CSRCS += lv_gpu_d2_ra6m3.c
CSRCS += lv_gpu_d2_draw_label.c

DEPPATH += --dep-path $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/renesas
VPATH += :$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/renesas

CFLAGS += "-I$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/renesas"
