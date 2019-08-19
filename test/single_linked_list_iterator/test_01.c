#include <stdio.h>
#include "single_linked_list_iterator.h"

int main(int argc,char * argv[])
{
	struct tSingleLinkedList	*pSLL;
	struct tSLLIterator			*pSLLIter;

	pSLL = sll_init();

	for(int li = 1;li <= 100;li++)
		sll_append(pSLL,&li,sizeof(int));

	printf("Node Count = %d\n",sll_node_count(pSLL));

	pSLLIter = sll_iterator_init(pSLL);
	for(sll_iterator_reset(pSLLIter);sll_iterator_is_null(pSLLIter) != true; sll_iterator_next(pSLLIter))
	{
		int li;
		sll_iterator_get_data(pSLLIter,&li,NULL);
		printf("%d ",li);
	}
	printf("\n");
	for(sll_iterator_reset(pSLLIter);sll_iterator_is_null(pSLLIter) != true; sll_iterator_next(pSLLIter))
	{
		int li;
		sll_iterator_get_data(pSLLIter,&li,NULL);
		printf("%d ",li);
	}

	sll_iterator_destroy(pSLLIter);


	printf("\n");
	sll_destroy(pSLL);

	return 0;
}
