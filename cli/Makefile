CLIOBJ_DIR := $(shell pwd)/obj

cli:$(CLIOBJ_DIR)/cli_main.o $(CLIOBJ_DIR)/cli_add.o $(CLIOBJ_DIR)/cli_minus.o
	@gcc $^ -o ../bin/$@
	@echo "build $@ complete"

$(CLIOBJ_DIR)/cli_main.o:./cli_main.c
	gcc -c $< -o $@

$(CLIOBJ_DIR)/cli_add.o:./src/cli_add.c ./inc/cli_add.h
	gcc -c $< -o $@

$(CLIOBJ_DIR)/cli_minus.o:./src/cli_minus.c ./inc/cli_minus.h
	gcc -c $< -o $@
clean:
	@rm ./obj/*
	@rm ../bin/*
	@echo "clean complete"
