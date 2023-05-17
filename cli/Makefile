CLIOBJ_DIR := $(shell pwd)/obj

cli:$(CLIOBJ_DIR)/cli_main.o $(CLIOBJ_DIR)/cli_add.o $(CLIOBJ_DIR)/cli_minus.o
	@gcc $^ -o ../bin/$@
	@echo "build $@ complete"

$(CLIOBJ_DIR)/cli_main.o:./cli_main.c
	@mkdir -p $(CLIOBJ_DIR)
	gcc -c $< -o $@

$(CLIOBJ_DIR)/cli_add.o:./src/cli_add.c ./inc/cli_add.h
	@mkdir -p $(CLIOBJ_DIR)
	gcc -c $< -o $@

$(CLIOBJ_DIR)/cli_minus.o:./src/cli_minus.c ./inc/cli_minus.h
	@mkdir -p $(CLIOBJ_DIR)
	gcc -c $< -o $@

clean:
	@rm -rf $(CLIOBJ_DIR)
	@echo "clean complete"
