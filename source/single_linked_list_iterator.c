#include "single_linked_list_iterator.h"

struct tSLLIterator * sll_iterator_init(struct tSingleLinkedList * pSLL)
{
	struct tSLLIterator *pSLLIter;

	pSLLIter = (struct tSLLIterator *)malloc(sizeof(struct tSLLIterator));
	if(pSLLIter == NULL)
		return NULL;
	pSLLIter->pSLL = pSLL;
	pSLLIter->pNode = pSLL->pHeadNode;
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

bool sll_iterator_is_last(struct tSLLIterator * pSLLIter)
{
	return (pSLLIter->pNode == pSLLIter->pSLL->pTailNode);
}

bool sll_iterator_has_end(struct tSLLIterator * pSLLIter)
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

void sll_iterator_destroy(struct tSLLIterator * pSLLIter)
{
	free(pSLLIter);
}

void insert_after_iterator(struct tSLLIterator * pSLLIter,void * pNodeData,size_t size)
{
	struct tSLLNode * pNode;

	assert(pSLLIter != NULL);

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

