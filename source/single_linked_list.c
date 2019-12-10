#include "single_linked_list.h"

bool sll_init(struct tSingleLinkedList * pSLL,bool bDeepCopy)
{
	if(pSLL == NULL)
		return false;
	pSLL->nNodeCount = 0;
	pSLL->pHeadNode = NULL;
	pSLL->pTailNode = NULL;
	pSLL->bDeepCopy = bDeepCopy;
	return true;
}

void sll_destroy(struct tSingleLinkedList * pSLL)
{
	struct tSLLNode *pNode;

	while(pSLL->pHeadNode != NULL)
	{
		//get Head Node, store it in pNode
		pNode = pSLL->pHeadNode;
		
		//Advance Head Node
		pSLL->pHeadNode = pSLL->pHeadNode->pNextNode;

		//Delete NodeData
		if(pSLL->bDeepCopy)
			free(pNode->pNodeData);

		//Delete HeadNode in pNode
		free(pNode);
	}
}

bool sll_append(struct tSingleLinkedList * pSLL,void * pNodeData,size_t size)
{
	struct tSLLNode * pNode;

	//pSLL must not NULL
	if(pSLL != NULL)
	{

		//Create A New Node
		pNode = _createNode(pSLL,pNodeData,size);

		//New Node will be Tail Node,
		//Let its Next Node to NULL
		pNode->pNextNode = NULL;

		//if There is Tail Node
		if(pSLL->pTailNode != NULL && pSLL->pHeadNode != NULL)
			pSLL->pTailNode->pNextNode = pNode;
		else
			pSLL->pHeadNode = pNode;

		//Set Tail Node Pointer to New Node
		pSLL->pTailNode = pNode;

		//Increase Node Count
		pSLL->nNodeCount++;
		return true;
	}
	else
		return false; 
}

bool sll_prepend(struct tSingleLinkedList * pSLL,void * pNodeData,size_t size)
{
	struct tSLLNode * pNode;

	if(pSLL != NULL)
	{
		pNode = _createNode(pSLL,pNodeData,size);

		if(pSLL->pHeadNode != NULL && pSLL->pTailNode != NULL)
			pNode->pNextNode = pSLL->pHeadNode;
		else
			pSLL->pTailNode = pNode;
		pSLL->pHeadNode = pNode;

		//Increase Node Count
		pSLL->nNodeCount++;
		return true;
	}
	else
		return false;
}

bool sll_pop_head(struct tSingleLinkedList * pSLL)
{
	struct tSLLNode * pNode;

	if(pSLL->pHeadNode != NULL)
	{
		//free NodeData
		pNode = pSLL->pHeadNode;

		if(pSLL->bDeepCopy)
			free(pNode->pNodeData);

		//free pNode
		pSLL->pHeadNode = pSLL->pHeadNode->pNextNode;
		free(pNode);

		//Decrease Node Count
		pSLL->nNodeCount--;
		return true;
	}
	else
		return false;
}

bool sll_get_node_data(struct tSLLNode *pSLLNode,void *pNodeData)
{
	if(pSLLNode != NULL)
	{
		memcpy(pNodeData,pSLLNode->pNodeData,pSLLNode->szNodeData);
		return true;
	}
	else
		return false;
}

size_t sll_get_node_data_size(struct tSLLNode const * pSLLNode)
{
	return pSLLNode->szNodeData;
}
		
struct tSLLNode *sll_get_head_node(struct tSingleLinkedList const * pSLL)
{
	return pSLL->pHeadNode;
}

struct tSLLNode *sll_get_tail_node(struct tSingleLinkedList const * pSLL)
{
	return pSLL->pTailNode;
}

bool sll_get_deep_copy(struct tSingleLinkedList const * pSLL)
{
	return pSLL->bDeepCopy;
}

size_t sll_get_node_count(struct tSingleLinkedList const * pSLL)
{
	return pSLL->nNodeCount;
}

struct tSLLNode * _createNode(struct tSingleLinkedList *pSLL,void *pData,size_t const size)
{
	struct tSLLNode *pNode;

	pNode = (struct tSLLNode *)malloc(sizeof(struct tSLLNode));
	if(pNode == NULL)
		return NULL;

	if(pSLL->bDeepCopy)
	{
		pNode->pNodeData = (void *)malloc(size);
		memcpy(pNode->pNodeData,pData,size);
	}
	else
		pNode->pNodeData = pData;

	pNode->szNodeData = size;

	return pNode;
}
