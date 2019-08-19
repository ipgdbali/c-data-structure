#include "sorted_list.h"

struct tSortedList * sl_init(bool bAllowDuplicate,int (*cmp_func)(void const *,void const *))
{
	struct 	tSortedList * pSL;
	pSL = (struct tSortedList *)malloc(sizeof(struct tSortedList));

	pSL->pLinkedList = sll_init();
	pSL->cmp_func = cmp_func;
	pSL->bAllowDuplicate = bAllowDuplicate;

	return pSL;
}

bool sl_push(struct tSortedList *pSL,void const * pNodeData,size_t size)
{
	struct tSLLIterator * pIter;

	if(sll_node_count(pSL->pLinkedList) == 0 )
	{
		sll_append(pSL->pLinkedList,pNodeData,size);
	}
	else
	{
		pIter = sll_iterator_init(pSL->pLinkedList);
		for(pIter = sll_iterator_reset(pIter);!sll_iterator_is_null(pIter);sll_iterator_next(pIter))
		{

			if(
			pSL->cmp_func(pNodeData,sll_iterator_peek_curr(pIter)) < 0 &&
			sll_iterator_is_first(pIter))
			{
				//if node data < head data
				sll_prepend(pSL->pLinkedList,pNodeData,size);
				break;
			}
			else
			if(pSL->cmp_func(pNodeData,sll_iterator_peek_curr(pIter)) > 0)
			{

				if(
				(
				sll_iterator_is_last(pIter) ||
				pSL->cmp_func(pNodeData,sll_iterator_peek_next(pIter)) < 0
				) )
				{

					//if prev data < node data < curr data
					sll_iterator_insert_after(pIter,pNodeData,size);
					break;
				}
				else
				if(
				pSL->cmp_func(pNodeData,sll_iterator_peek_next(pIter)) == 0 &&
				pSL->bAllowDuplicate)
				{
					//if prev data < node data < curr data
					sll_iterator_insert_after(pIter,pNodeData,size);
					break;
				}
			}
			else
			if	(
				pSL->cmp_func(pNodeData,sll_iterator_peek_curr(pIter)) == 0 &&
				pSL->bAllowDuplicate
				)
			{
				sll_iterator_insert_after(pIter,pNodeData,size);
				break;
			}
		}
		sll_iterator_destroy(pIter);
	}
}

struct tSingleLinkedList * sl_get_linked_list(struct tSortedList const * pSortedList)
{
	return pSortedList->pLinkedList;
}

void sl_destroy(struct tSortedList *pSL)
{
	sll_destroy(pSL->pLinkedList);
	free(pSL);
}
