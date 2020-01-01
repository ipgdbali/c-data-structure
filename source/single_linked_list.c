#include "single_linked_list.h"

void sll_init(struct tSingleLinkedList * pSLL,bool bDeepCopy)
{
	assert(pSLL != NULL);

	pSLL->nNodeCount = 0;
	pSLL->pHeadNode = NULL;
	pSLL->pTailNode = NULL;
	pSLL->bDeepCopy = bDeepCopy;
}

void sll_destroy(struct tSingleLinkedList * pSLL)
{
	struct tSLLNode *pNode;

	assert(pSLL != NULL);

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

bool sll_append(struct tSingleLinkedList * pSLL,const void * pNodeData,size_t size)
{
	struct tSLLNode * pNode;

	//pSLL must not NULL
	assert(pSLL != NULL);
	
	//Create A New Node
	pNode = _createNode(pSLL,pNodeData,size);
	if(pNode == NULL)
		return false;
	
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

bool sll_prepend(struct tSingleLinkedList * pSLL,const void * pNodeData,size_t size)
{
	struct tSLLNode * pNode;

	assert(pSLL != NULL);

	pNode = _createNode(pSLL,pNodeData,size);
	if(pNode == NULL)
		return false;

	if(pSLL->pHeadNode != NULL && pSLL->pTailNode != NULL)
		pNode->pNextNode = pSLL->pHeadNode;
	else
		pSLL->pTailNode = pNode;
	pSLL->pHeadNode = pNode;

	//Increase Node Count
	pSLL->nNodeCount++;
	return true;
}

size_t sll_pop_head(struct tSingleLinkedList * pSLL)
{
	struct tSLLNode * pNode;

	assert(pSLL != NULL);

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
	}

	return pSLL->nNodeCount;
}

bool sll_get_node_data(struct tSingleLinkedList * pSLL,enum eNodeKind nodeKind,void *pNodeData)
{
	struct tSLLNode *	pSLLNode;

	assert(pSLL != NULL);

	switch(nodeKind)
	{
		case eHeadNode:
			pSLLNode = pSLL->pHeadNode;
			break;

		case eTailNode:
			pSLLNode = pSLL->pTailNode;
			break;
	}
	if(pSLLNode != NULL)
	{

		if(pSLL->bDeepCopy)	
			memcpy(pNodeData,pSLLNode->pNodeData,pSLLNode->szNodeData);
		else
			assert(true);

	}
	else
	{
		return false;
	}
}

size_t sll_get_node_data_size(struct tSingleLinkedList * pSLL,enum eNodeKind nodeKind)
{
	struct tSLLNode *	pSLLNode;

	assert(pSLL != NULL);
	switch(nodeKind)
	{
		case eHeadNode:
			pSLLNode = pSLL->pHeadNode;
			break;

		case eTailNode:
			pSLLNode = pSLL->pTailNode;
			break;
	}

	return pSLLNode->szNodeData;
}
		
bool sll_get_deep_copy(struct tSingleLinkedList const * pSLL)
{
	return pSLL->bDeepCopy;
}

size_t sll_get_node_count(struct tSingleLinkedList const * pSLL)
{
	return pSLL->nNodeCount;
}

struct tSLLNode * _createNode(struct tSingleLinkedList *pSLL,const void *pData,size_t const size)
{
	struct tSLLNode *pNode;

	assert(pSLL != NULL);

	pNode = (struct tSLLNode *)malloc(sizeof(struct tSLLNode));
	if(pNode == NULL)
		return NULL;

	if(pSLL->bDeepCopy)
	{
		pNode->pNodeData = (void *)malloc(size);
		memcpy(pNode->pNodeData,pData,size);
	}
	else
	{
		pNode->pNodeData = pData;
	}
	pNode->pNextNode = NULL;
	pNode->szNodeData = size;
	return pNode;
}
