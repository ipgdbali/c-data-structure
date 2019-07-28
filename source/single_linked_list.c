#include "single_linked_list.h"

struct tSingleLinkedList * sll_init()
{
	struct tSingleLinkedList * sll;
	sll = (struct tSingleLinkedList *)malloc(sizeof(struct tSingleLinkedList));
	sll->nNodeCount = 0;
	sll->pHeadNode = NULL;
	sll->pTailNode = NULL;
	return sll;
}

void sll_append(struct tSingleLinkedList *pSLL,void * pNodeData)
{
	struct tSLLNode * pNode;

	assert(pSLL != NULL);

	pNode = (struct tSLLNode *)malloc(sizeof(struct tSLLNode));
	pNode->pNodeData = pNodeData;
	pNode->pNextNode = NULL;
	if(pSLL->pTailNode != NULL)
		pSLL->pTailNode->pNextNode = pNode;
	else
		pSLL->pHeadNode = pNode;
	pSLL->pTailNode = pNode;
	pSLL->nNodeCount++;
}

void sll_prepend(struct tSingleLinkedList *pSLL,void *pNodeData)
{
	struct tSLLNode * pNode;

	assert(pSLL != NULL);

	pNode = (struct tSLLNode *)malloc(sizeof(struct tSLLNode));
	pNode->pNodeData = pNodeData;
	if(pSLL->pHeadNode != NULL)
		pNode->pNextNode = pSLL->pHeadNode;
	else
		pSLL->pTailNode = pNode;
	pSLL->pHeadNode = pNode;
	pSLL->nNodeCount++;
}

void * sll_pop_head(struct tSingleLinkedList *pSLL)
{
	void * pNodeData;
	struct tSLLNode * pNode;

	pNode = pSLL->pHeadNode;
	pNodeData = pNode->pNodeData;
	pSLL->pHeadNode = pSLL->pHeadNode->pNextNode;
	return pNodeData;
}

void * sll_peek_head(struct tSingleLinkedList * pSLL)
{
	return pSLL->pHeadNode->pNodeData;
}

void * sll_peek_tail(struct tSingleLinkedList * pSLL)
{
	return pSLL->pTailNode->pNodeData;
}

void sll_destroy(struct tSingleLinkedList * pSLL)
{
	struct tSLLNode *pNode;

	if(pSLL->pHeadNode != NULL)
	do
	{
		pNode = pSLL->pHeadNode;
		pSLL->pHeadNode = pSLL->pHeadNode->pNextNode;
		free(pNode->pNodeData);
		free(pNode);
	}while(pSLL->pHeadNode != NULL);

	free(pSLL);
}

void insert_after_iterator(struct tSLLIterator * pSLLIter,void * pNodeData)
{
	struct tSLLNode * pNode;

	assert(pSLLIter != NULL);

	pNode = (struct tSLLNode *)malloc(sizeof(struct tSLLNode));
	pNode->pNodeData = pNodeData;
	pNode->pNextNode = pSLLIter->pNode->pNextNode;
	pSLLIter->pNode->pNextNode = pNode;

	//Add Node Count
	pSLLIter->pSLL->nNodeCount++;
}

struct tSLLIterator * sll_iterator_init(struct tSingleLinkedList * pSLL)
{
	struct tSLLIterator *pSLLIter;

	pSLLIter = (struct tSLLIterator *)malloc(sizeof(struct tSLLIterator));
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

void sll_iterator_set_data(struct tSLLIterator * pSLLIter,void * pNodeData)
{
	pSLLIter->pNode->pNodeData = pNodeData;
}

void * sll_iterator_get_data(struct tSLLIterator * pSLLIter)
{
	return pSLLIter->pNode->pNodeData;
}

void sll_iterator_destroy(struct tSLLIterator * pSLLIter)
{
	free(pSLLIter);
}

