BIN_DIR := bin
BIN_FILES=$(patsubst %.c,$(BIN_DIR)/%,$(wildcard *.c))

$(info $(BIN_FILES))
.PHONY: all clean 

all : $(BIN_FILES)

$(BIN_DIR)/% : %.c
	gcc -g -I./../../header $< ./../../bin/debug/single_linked_list.o -o $@

clean :
	rm $(BIN_DIR)/*

