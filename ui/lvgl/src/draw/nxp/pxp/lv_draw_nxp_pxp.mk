CSRCS += lv_draw_pxp.c
CSRCS += lv_draw_pxp_blend.c
CSRCS += lv_gpu_nxp_pxp_osa.c
CSRCS += lv_gpu_nxp_pxp.c

DEPPATH += --dep-path $(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/nxp/pxp
VPATH += :$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/nxp/pxp

CFLAGS += "-I$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/nxp/pxp"
