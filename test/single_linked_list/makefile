all : test_01 test_02

test_01	: test_01.c ./../../bin/debug/single_linked_list.o
	gcc -g -I./../../header $^  -o test_01

test_02 : test_02.c ./../../bin/debug/single_linked_list.o
	gcc -g -I./../../header $^ -o test_02
