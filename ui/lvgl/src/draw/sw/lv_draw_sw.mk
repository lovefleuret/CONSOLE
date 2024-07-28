CSRCS += lv_draw_sw.c
CSRCS += lv_draw_sw_arc.c
CSRCS += lv_draw_sw_blend.c
CSRCS += lv_draw_sw_dither.c
CSRCS += lv_draw_sw_gradient.c
CSRCS += lv_draw_sw_img.c
CSRCS += lv_draw_sw_letter.c
CSRCS += lv_draw_sw_line.c
CSRCS += lv_draw_sw_polygon.c
CSRCS += lv_draw_sw_rect.c
CSRCS += lv_draw_sw_transform.c
CSRCS += lv_draw_sw_layer.c

DEPPATH += --dep-path $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/sw
VPATH += :$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/sw

CFLAGS += "-I$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/draw/sw"
