#include "single_linked_list.h"

bool sll_init(struct tSingleLinkedList * pSLL)
{
	if(pSLL == NULL)
		return false;
	pSLL->nNodeCount = 0;
	pSLL->pHeadNode = NULL;
	pSLL->pTailNode = NULL;
	return true;
}

void sll_destroy(struct tSingleLinkedList * pSLL)
{
	struct tSLLNode *pNode;

	while(pSLL->pHeadNode != NULL)
	{
		pNode = pSLL->pHeadNode;
		pSLL->pHeadNode = pSLL->pHeadNode->pNextNode;
		free(pNode->pNodeData);
		free(pNode);
	}while(pSLL->pHeadNode != NULL);
}

bool sll_append(struct tSingleLinkedList * pSLL,void const * pNodeData,size_t size)
{
	struct tSLLNode * pNode;

	//pSLL must not NULL
	if(pSLL == NULL)
		return false;

	//Create Node Data
	pNode = _createNode(pNodeData,size);

	pNode->pNextNode = NULL;
	if(pSLL->pTailNode != NULL)
		pSLL->pTailNode->pNextNode = pNode;
	else
		pSLL->pHeadNode = pNode;
	pSLL->pTailNode = pNode;
	pSLL->nNodeCount++;

	return true;
}

bool sll_prepend(struct tSingleLinkedList *pSLL,void const * pNodeData,size_t size)
{
	struct tSLLNode * pNode;

	if(pSLL == NULL)
		return false;

	pNode = _createNode(pNodeData,size);

	if(pSLL->pHeadNode != NULL)
		pNode->pNextNode = pSLL->pHeadNode;
	else
		pSLL->pTailNode = pNode;
	pSLL->pHeadNode = pNode;
	pSLL->nNodeCount++;
	return true;
}

bool sll_head_data(struct tSingleLinkedList *pSLL,void * pNodeData,size_t * size)
{
	if(pNodeData != NULL)
		memcpy(pNodeData,pSLL->pHeadNode->pNodeData,pSLL->pHeadNode->szNodeData);

	if(size != NULL)
		*size = pSLL->pHeadNode->szNodeData;
}

bool sll_tail_data(struct tSingleLinkedList *pSLL,void * pNodeData,size_t * size)
{
	if(pNodeData != NULL)
		memcpy(pNodeData,pSLL->pTailNode->pNodeData,pSLL->pTailNode->szNodeData);

	if(size != NULL)
		*size = pSLL->pTailNode->szNodeData;
}

void const * sll_peek_head(struct tSingleLinkedList *pSLL)
{
	if(pSLL->pHeadNode != NULL)
		return pSLL->pHeadNode->pNodeData;
	else
		return NULL;
}

void const * sll_peek_tail(struct tSingleLinkedList *pSLL)
{
	if(pSLL->pTailNode != NULL)
		return pSLL->pTailNode->pNodeData;
	else
		return NULL;
}

bool sll_pop_head(struct tSingleLinkedList *pSLL)
{
	struct tSLLNode * pNode;

	if(pSLL->pHeadNode != NULL)
	{
		//free NodeData
		pNode = pSLL->pHeadNode;
		free(pNode->pNodeData);

		//free pNode
		pSLL->pHeadNode = pSLL->pHeadNode->pNextNode;
		free(pNode);

		//Decrease Node Count
		pSLL->nNodeCount--;

		if(pSLL->pHeadNode == NULL)
			return false;
		else
			return true;
	}
	else
		return false;
}

size_t sll_node_count(struct tSingleLinkedList *pSLL)
{
	return pSLL->nNodeCount;
}

struct tSLLNode * _createNode(void const *pData,size_t size)
{
	struct tSLLNode *pNode;

	pNode = (struct tSLLNode *)malloc(sizeof(struct tSLLNode));
	if(pNode == NULL)
		return NULL;

	//Copy Node Data
	pNode->pNodeData = (void *)malloc(size);
	memcpy(pNode->pNodeData,pData,size);
	pNode->szNodeData = size;
}
