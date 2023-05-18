OBJDIR := $(shell pwd)/obj
INCDIR := $(shell pwd)/inc

SRCS := $(wildcard *.c) $(wildcard ./src/*.c)
INC := $(foreach path,${INCDIR},-I${path})

VPATH := $(sort $(dir $(SRCS)))
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRCS)))
DEPS := $(patsubst %.o, %.d, $(OBJS))

cli:$(OBJDIR)/cli_main.o $(OBJDIR)/cli_add.o $(OBJDIR)/cli_minus.o
	@gcc $^ -o ../bin/$@
	@echo "build $@ complete"

$(OBJDIR)/%.o:%.c
	@mkdir -p $(OBJDIR)
	gcc -c $(INC) -MMD $< -o $@
	@echo "CC $@"

-include $(DEPS)

info:
	@echo "OBJS = $(OBJS)"
	@echo "SRCS = $(SRCS)"
	@echo "INCDIR = $(INCDIR)"
	@echo "INC = $(INC)"

clean:
	@rm -rf $(OBJDIR)
	@echo "clean complete"
