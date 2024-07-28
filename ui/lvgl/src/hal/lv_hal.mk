CSRCS += $(wildcard $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/hal/*.c)

DEPPATH += --dep-path $(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/hal
VPATH += :$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/hal

CFLAGS += "-I$(CONSOLE)/$(UI_DIR_NAME)/$(LVGL_DIR_NAME)/src/hal"
