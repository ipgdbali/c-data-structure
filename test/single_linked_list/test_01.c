#include "single_linked_list.h"
#include <stdio.h>

int main(int argc,char * argv[])
{
	struct tSingleLinkedList	*pSLL;
	struct tCursor				*pCursor;
	struct tCursor				*pcsTmp;

	pSLL = sll_init();

	for(int li = 0;li < 100;li++)
	{
		int * tmp = (int *) malloc(sizeof(int));
		(*tmp) = li + 1;
		sll_append_tail(pSLL,(void*)tmp);
	}

	pCursor = cursor_init(pSLL);

	while(!cursor_has_end(pCursor))
	{
		printf("%d ",*(int*)cursor_get_data(pCursor));
		pCursor = cursor_next(pCursor);
	}

	printf("\n");

	cursor_destroy(pCursor);
	sll_destroy(pSLL);

	return 0;
}
