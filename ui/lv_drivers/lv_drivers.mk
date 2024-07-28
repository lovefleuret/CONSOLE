LV_DRIVERS_DIR_NAME ?= lv_drivers

override CFLAGS := -I$(CONSOLE) $(CFLAGS)

CSRCS += $(wildcard $(CONSOLE)/$(UI_DIR_NAME)/$(LV_DRIVERS_DIR_NAME)/*.c)
CSRCS += $(wildcard $(CONSOLE)/$(UI_DIR_NAME)/$(LV_DRIVERS_DIR_NAME)/wayland/*.c)
CSRCS += $(wildcard $(CONSOLE)/$(UI_DIR_NAME)/$(LV_DRIVERS_DIR_NAME)/indev/*.c)
CSRCS += $(wildcard $(CONSOLE)/$(UI_DIR_NAME)/$(LV_DRIVERS_DIR_NAME)/gtkdrv/*.c)
CSRCS += $(wildcard $(CONSOLE)/$(UI_DIR_NAME)/$(LV_DRIVERS_DIR_NAME)/display/*.c)
CSRCS += $(wildcard $(CONSOLE)/$(UI_DIR_NAME)/$(LV_DRIVERS_DIR_NAME)/sdl/*.c)
