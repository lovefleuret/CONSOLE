DEPPATH += --dep-path $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp
VPATH += :$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp

CFLAGS += "-I$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp"

include $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp/pxp/lv_draw_nxp_pxp.mk
include $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp/vglite/lv_draw_nxp_vglite.mk
