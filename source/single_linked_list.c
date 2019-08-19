#include "single_linked_list.h"

struct tSingleLinkedList * sll_init()
{
	struct tSingleLinkedList * pSLL;
	pSLL = (struct tSingleLinkedList *)malloc(sizeof(struct tSingleLinkedList));
	if(pSLL == NULL)
		return NULL;
	pSLL->nNodeCount = 0;
	pSLL->pHeadNode = NULL;
	pSLL->pTailNode = NULL;
	return pSLL;
}

bool sll_append(struct tSingleLinkedList *pSLL,void const * pNodeData,size_t size)
{
	struct tSLLNode * pNode;

	if(pSLL == NULL)
		return false;

	pNode = (struct tSLLNode *)malloc(sizeof(struct tSLLNode));
	if(pNode == NULL)
		return false;

	//Copy Node Data
	pNode->pNodeData = (void *)malloc(size);
	memcpy(pNode->pNodeData,pNodeData,size);
	pNode->szNodeData = size;
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

	pNode = (struct tSLLNode *)malloc(sizeof(struct tSLLNode));
	if(pNode == NULL)
		return false;

	//Copy Node Data
	pNode->pNodeData = (void *)malloc(size);
	memcpy(pNode->pNodeData,pNodeData,size);
	pNode->szNodeData = size;

	if(pSLL->pHeadNode != NULL)
		pNode->pNextNode = pSLL->pHeadNode;
	else
		pSLL->pTailNode = pNode;
	pSLL->pHeadNode = pNode;
	pSLL->nNodeCount++;
	return true;
}

bool sll_pop_head(struct tSingleLinkedList *pSLL)
{
	struct tSLLNode * pNode;

	if(pSLL->pHeadNode != NULL)
	{
		pNode = pSLL->pHeadNode;
		free(pNode->pNodeData);
		pSLL->pHeadNode = pSLL->pHeadNode->pNextNode;
		free(pNode);
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
