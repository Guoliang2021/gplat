export ROOT_DIR := $(shell pwd)
export COMMON_DIR := $(ROOT_DIR)/common
export CLI_DIR := $(ROOT_DIR)/cli
export BIN_DIR := $(ROOT_DIR)/bin

export COMMON_INC_DIR := $(COMMON_DIR)/inc
export CFLAGS_COMMON := -g -fsanitize=address

all:
	@make -s -C $(CLI_DIR)
clean:
	@make clean -s -C $(CLI_DIR)

info:
	@echo " ROOT_DIR $(ROOT_DIR)"
	@echo " COMMON_DIR $(COMMON_DIR)"
	@echo " COMMON_INC_DIR $(COMMON_INC_DIR)"
	@echo " CLI_DIR $(CLI_DIR)"
	@echo " BIN_DIR $(BIN_DIR)"
