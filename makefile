
bin/debug/single_linked_list.o : source/single_linked_list.c
	gcc -Iheader -g -c $< -o $@
