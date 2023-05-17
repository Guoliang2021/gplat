OBJDIR := $(shell pwd)/obj

SRCS := $(wildcard *.c) $(wildcard ./src/*.c)

VPATH := $(sort $(dir $(SRCS)))
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRCS)))

cli:$(OBJDIR)/cli_main.o $(OBJDIR)/cli_add.o $(OBJDIR)/cli_minus.o
	@gcc $^ -o ../bin/$@
	@echo "build $@ complete"

$(OBJDIR)/%.o:%.c
	@mkdir -p $(OBJDIR)
	gcc -c $< -o $@

info:
	@echo "OBJS = $(OBJS)"
	@echo "SRCS = $(SRCS)"

clean:
	@rm -rf $(OBJDIR)
	@echo "clean complete"
