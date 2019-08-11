.PHONY: all clean

all : test_01 test_02 test_03 test_04

test_01 : test_01.c 
	gcc -I./../../header test_01.c ./../../bin/debug/single_linked_list.o -o test_01

test_02 : test_02.c
	gcc -I./../../header test_02.c ./../../bin/debug/single_linked_list.o -o test_02

test_03 : test_03.c
	gcc -I./../../header test_03.c ./../../bin/debug/single_linked_list.o -o test_03

test_04 : test_04.c
	gcc -I./../../header test_04.c ./../../bin/debug/single_linked_list.o -o test_04

clean :
	rm test_01 test_02 test_03 test_04

