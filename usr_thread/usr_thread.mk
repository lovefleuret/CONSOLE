USR_DIR ?= usr_thread



CSRCS += $(shell find -L $(CONSOLE)/$(USR_DIR) -name "*.c")
CFLAGS += -I$(CONSOLE)/$(USR_DIR)/usr_gui/src
CFLAGS += -I$(CONSOLE)/$(USR_DIR)/at24c02_thread
CFLAGS += -I$(CONSOLE)/$(USR_DIR)/dht11_thread
CFLAGS += -I$(CONSOLE)/$(USR_DIR)/sr501