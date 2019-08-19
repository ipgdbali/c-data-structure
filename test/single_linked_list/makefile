.PHONY: all clean 

BINARY_FILES=$(patsubst %.c,%,$(wildcard *.c))

all : $(BINARY_FILES)

% : %.c
	gcc -I./../../header $< ./../../bin/debug/single_linked_list.o -o $@

clean :
	rm $(BINARY_FILES)

