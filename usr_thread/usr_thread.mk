USR_DIR ?= usr_thread



CSRCS += $(shell find -L $(CONSOLE)/$(USR_DIR) -name "*.c")
CFLAGS += -I$(CONSOLE)/$(USR_DIR)/usr_gui/src