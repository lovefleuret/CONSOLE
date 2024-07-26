DEPPATH += --dep-path $(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/nxp
VPATH += :$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/nxp

CFLAGS += "-I$(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/nxp"

include $(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/nxp/pxp/lv_draw_nxp_pxp.mk
include $(CONSOLE)/$(LVGL_DIR_NAME)/src/draw/nxp/vglite/lv_draw_nxp_vglite.mk
