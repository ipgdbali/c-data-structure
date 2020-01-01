#include <stdio.h>
#include "single_linked_list.h"

int main(int argc,char * argv[])
{
	struct tSingleLinkedList	SLL;

	sll_init(&SLL,true);

	for(int li = 1;li <= 100;li++)
		sll_append(&SLL,&li,sizeof(int));

	printf("Node Count = %d\n",sll_get_node_count(&SLL));

	for(int li = 0;li < 100;li++)
	{
		int val;
		sll_get_node_data(&SLL,eHeadNode,&val);
		printf("%3d ",val);
		if((li + 1) % 10 == 0)
			printf("\n");
		sll_pop_head(&SLL);
	}

	printf("\n");
	sll_destroy(&SLL);

	return 0;
}
