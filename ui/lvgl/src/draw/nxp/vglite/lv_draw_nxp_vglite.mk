CSRCS += lv_draw_vglite.c
CSRCS += lv_draw_vglite_arc.c
CSRCS += lv_draw_vglite_blend.c
CSRCS += lv_draw_vglite_line.c
CSRCS += lv_draw_vglite_rect.c
CSRCS += lv_vglite_buf.c
CSRCS += lv_vglite_utils.c

DEPPATH += --dep-path $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp/vglite
VPATH += :$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp/vglite

CFLAGS += "-I$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/nxp/vglite"
