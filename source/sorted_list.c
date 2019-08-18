#include "sorted_list.h"

struct tSortedList * sl_init(bool bAllowDuplicate,int (*cmp_func)(void const *,void const *))
{
	struct 	tSortedList * pSL;
	pSL = (struct tSortedList *)malloc(sizeof(struct tSortedList));
	pSL->pLinkedList = sll_init();
	pSL->cmp_func = cmp_func;
	pSL->bDuplicate = bAllowDuplicate;
	return pSL;
}

bool sl_push(struct tSortedList *pSL,void const * pNodeData,size_t size)
{
	struct tSLLIterator * pIter;

	pIter = sll_iterator_init(pSL->pLinkedList);
	for(pIter = sll_iterator_reset(pIter);sll_iterator_is_null(pIter);sll_iterator_next(pIter))
	{

		if(pSL->cmp_func(pNodeData,sll_iterator_peek_curr(pIter)) < 0)
		{
			if(sll_iterator_is_first(pIter) && pSL->bDuplicate)
				//if node data < head data
				sll_prepend(pSL->pLinkedList,pNodeData,size);
		}
		else
		if(pSL->cmp_func(pNodeData,sll_iterator_peek_curr(pIter)) > 0)
		{

			if(
			(
			sll_iterator_is_last(pIter) || 	
			pSL->cmp_func(pNodeData,sll_iterator_peek_next(pIter)) < 0
			) && pSL->bDuplicate)

				//if prev data < node data < curr data
				sll_iterator_insert_after(pIter,pNodeData,size);
		}
	}
	sll_iterator_destroy(pIter);
}

struct tSortedList const * const sl_get_linked_list(struct tSortedList const * const pSortedList)
{
	return pSortedList;
}

void sl_destroy(struct tSortedList *pSL)
{
	sll_destroy(pSL->pLinkedList);
	free(pSL);
}
