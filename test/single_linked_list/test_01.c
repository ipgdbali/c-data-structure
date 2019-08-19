#include <stdio.h>
#include "single_linked_list.h"

int main(int argc,char * argv[])
{
	struct tSingleLinkedList	*pSLL;

	pSLL = sll_init();

	for(int li = 1;li <= 100;li++)
		sll_append(pSLL,&li,sizeof(int));

	printf("Node Count = %d\n",sll_node_count(pSLL));

	for(int li = 0;li< 100 ;li++)
	{
		int val;
		printf("%3d ",*(int*)sll_peek_head(pSLL));
		if(val % 30 == 0)
			printf("\n");
		sll_pop_head(pSLL);
	}

	printf("\n");
	sll_destroy(pSLL);

	return 0;
}
