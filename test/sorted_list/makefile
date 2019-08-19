.PHONY: all clean


HEADER_DIR=../../header
OBJ_DIR=../../bin/debug

BINARY_FILES:=$(patsubst %.c,%,$(wildcard *.c))

$(info $(BINARY_FILES))

all : $(BINARY_FILES)

% : %.c 
	gcc -g -I$(HEADER_DIR) $< $(OBJ_DIR)/sorted_list.o $(OBJ_DIR)/single_linked_list_iterator.o $(OBJ_DIR)/single_linked_list.o -o $@


clean :
	rm $(BINARY_FILES)

