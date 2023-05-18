CFLAGS ?= $(CFLAGS_COMMON)
OBJ_DIR := $(CLI_DIR)/obj
INC_DIR := $(CLI_DIR)/inc
INC_DIR += $(COMMON_INC_DIR)

SRCS := $(wildcard *.c) $(wildcard ./src/*.c)
INC := $(foreach path,${INC_DIR},-I${path})

VPATH := $(sort $(dir $(SRCS)))
OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))
DEPS := $(patsubst %.o, %.d, $(OBJS))

cli:$(OBJS)
	@gcc $(CFLAGS_COMMON) $^ -o ../bin/$@
	@echo "build $@ complete"

$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(OBJ_DIR)
	gcc -c $(CFLAGS_COMMON) $(INC) -MMD $< -o $@
	@echo "CC $@"

-include $(DEPS)

info:
	@echo "OBJS = $(OBJS)"
	@echo "SRCS = $(SRCS)"
	@echo "INC_DIR = $(INC_DIR)"
	@echo "INC = $(INC)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "clean complete"
