.PHONY: all clean


HEADER_DIR=../../header
OBJ_DIR=../../bin

all : test_01

% : %.c 
	gcc -g -I$(HEADER_DIR) $< $(OBJ_DIR)/debug/sorted_list.o $(OBJ_DIR)/debug/single_linked_list_iterator.o $(OBJ_DIR)/debug/single_linked_list.o -o $@


clean :
	rm test_01

