CSRCS += lv_arc.c
CSRCS += lv_bar.c
CSRCS += lv_btn.c
CSRCS += lv_btnmatrix.c
CSRCS += lv_canvas.c
CSRCS += lv_checkbox.c
CSRCS += lv_dropdown.c
CSRCS += lv_img.c
CSRCS += lv_label.c
CSRCS += lv_line.c
CSRCS += lv_roller.c
CSRCS += lv_slider.c
CSRCS += lv_switch.c
CSRCS += lv_table.c
CSRCS += lv_textarea.c

DEPPATH += --dep-path $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/widgets
VPATH += :$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/widgets

CFLAGS += "-I$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/widgets"
