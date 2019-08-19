#include "single_linked_list_iterator.h"

struct tSLLIterator * sll_iterator_init(struct tSingleLinkedList * pSLL)
{
	struct tSLLIterator *pSLLIter;

	pSLLIter = (struct tSLLIterator *)malloc(sizeof(struct tSLLIterator));
	if(pSLLIter == NULL)
		return NULL;
	pSLLIter->pSLL = pSLL;
	pSLLIter->pNode = NULL;
	return pSLLIter;
}

struct tSLLIterator * sll_iterator_reset(struct tSLLIterator * pSLLIter)
{
	pSLLIter->pNode = pSLLIter->pSLL->pHeadNode;
	return pSLLIter;
}

struct tSLLIterator *sll_iterator_next(struct tSLLIterator * pSLLIter)
{
	pSLLIter->pNode = pSLLIter->pNode->pNextNode;
	return pSLLIter;
}

bool sll_iterator_is_first(struct tSLLIterator * pSLLIter)
{
	return (pSLLIter->pNode == pSLLIter->pSLL->pHeadNode);
}

bool sll_iterator_is_last(struct tSLLIterator * pSLLIter)
{
	return (pSLLIter->pNode == pSLLIter->pSLL->pTailNode);
}

bool sll_iterator_is_null(struct tSLLIterator * pSLLIter)
{
	return (pSLLIter->pNode == NULL);
}

void sll_iterator_set_data(struct tSLLIterator * pSLLIter,void * pNodeData,size_t size)
{
		free(pSLLIter->pNode->pNodeData);
		pSLLIter->pNode->pNodeData = (void *)malloc(size);
		memcpy(pSLLIter->pNode->pNodeData,pNodeData,size);
		pSLLIter->pNode->szNodeData = size;
}

void sll_iterator_get_data(struct tSLLIterator * pSLLIter,void * pNodeData,size_t * size)
{
	if(pSLLIter->pNode != NULL)
	{
		if(pNodeData != NULL)
			memcpy(pNodeData,pSLLIter->pNode->pNodeData,pSLLIter->pNode->szNodeData);
		if(size != NULL)
			(*size) = pSLLIter->pNode->szNodeData;
	}
}

void const  * sll_iterator_peek_curr(struct tSLLIterator * pSLLIter)
{
	if(pSLLIter->pNode != NULL)
		return pSLLIter->pNode->pNodeData;
	else
		return NULL;
}

void const  * sll_iterator_peek_next(struct tSLLIterator * pSLLIter)
{
	if(pSLLIter->pNode->pNextNode != NULL)
		return pSLLIter->pNode->pNextNode->pNodeData;
	else
		return NULL;
}

void sll_iterator_destroy(struct tSLLIterator * pSLLIter)
{
	if(pSLLIter != NULL)
		free(pSLLIter);
}

void sll_iterator_insert_after(struct tSLLIterator * pSLLIter,void const  * pNodeData,size_t size)
{
	struct tSLLNode * pNode;

	pNode = (struct tSLLNode *)malloc(sizeof(struct tSLLNode));
	if(pNode == NULL)
		return;

	pNode->szNodeData = size;
	pNode->pNodeData = (void *)malloc(pNode->szNodeData);
	memcpy(pNode->pNodeData,pNodeData,pNode->szNodeData);

	pNode->pNextNode = pSLLIter->pNode->pNextNode;
	pSLLIter->pNode->pNextNode = pNode;

	//Add Node Count
	pSLLIter->pSLL->nNodeCount++;
}
