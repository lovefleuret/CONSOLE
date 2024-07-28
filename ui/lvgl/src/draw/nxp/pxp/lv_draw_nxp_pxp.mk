CSRCS += lv_draw_pxp.c
CSRCS += lv_draw_pxp_blend.c
CSRCS += lv_gpu_nxp_pxp_osa.c
CSRCS += lv_gpu_nxp_pxp.c

DEPPATH += --dep-path $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp/pxp
VPATH += :$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp/pxp

CFLAGS += "-I$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp/pxp"
