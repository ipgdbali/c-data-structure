#include "single_linked_list.h"
#include <stdio.h>

int main(int argc,char * argv[])
{
	struct tSingleLinkedList	*pSLL;
	struct tSLLIterator				*pCursor;
	struct tSLLIterator				*pcsTmp;

	pSLL = sll_init();

	for(int li = 0;li < 100;li++)
	{
		int * tmp = (int *) malloc(sizeof(int));
		(*tmp) = li + 1;
		sll_append_tail(pSLL,(void*)tmp);
	}

	pCursor = sll_iterator_init(pSLL);

	while(!sll_iterator_has_end(pCursor))
	{
		printf("%d ",*(int*)sll_iterator_get_data(pCursor));
		pCursor = sll_iterator_next(pCursor);
	}

	printf("\n");

	sll_iterator_destroy(pCursor);
	sll_destroy(pSLL);

	return 0;
}
