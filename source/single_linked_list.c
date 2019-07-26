#include "single_linked_list.h"

struct tSingleLinkedList * sll_init()
{
	struct tSingleLinkedList * sll;
	sll = (struct tSingleLinkedList *)malloc(sizeof(struct tSingleLinkedList));
	sll->pHeadNode = NULL;
	return sll;
}

void sll_append_tail(struct tSingleLinkedList *pSLL,void * pNodeData)
{
	struct tSingleLinkedListNode * pNode;

	assert(pSLL != NULL);

	pNode = (struct tSingleLinkedListNode *)malloc(sizeof(struct tSingleLinkedListNode));
	pNode->pNodeData = pNodeData;
	pNode->pNextNode = NULL;
	if(pSLL->pTailNode != NULL)
		pSLL->pTailNode->pNextNode = pNode;
	else
		pSLL->pHeadNode = pNode;
	pSLL->pTailNode = pNode;
}

void sll_append_head(struct tSingleLinkedList *pSLL,void *pNodeData)
{
	struct tSingleLinkedListNode * pNode;

	assert(pSLL != NULL);

	pNode = (struct tSingleLinkedListNode *)malloc(sizeof(struct tSingleLinkedListNode));
	pNode->pNodeData = pNodeData;
	if(pSLL->pHeadNode != NULL)
		pNode->pNextNode = pSLL->pHeadNode;
	else
		pSLL->pTailNode = pNode;
	pSLL->pHeadNode = pNode;
}

void sll_destroy(struct tSingleLinkedList * pSLL)
{
	struct tSingleLinkedListNode *pNode;
	do
	{
		pNode = pSLL->pHeadNode;
		pSLL->pHeadNode = pSLL->pHeadNode->pNextNode;
		free(pNode->pNodeData);
		free(pNode);
	}while(pSLL->pHeadNode != NULL);

	free(pSLL);
}

void insert_after_cursor(struct tCursor * pCursor,void * pNodeData)
{
	struct tSingleLinkedListNode * pNode;

	assert(pCursor != NULL);

	pNode = (struct tSingleLinkedListNode *)malloc(sizeof(struct tSingleLinkedListNode));
	pNode->pNodeData = pNodeData;
	pNode->pNextNode = pCursor->pNode->pNextNode;
	pCursor->pNode->pNextNode = pNode;
}

//CURSOR
struct tCursor * cursor_init(struct tSingleLinkedList * pSLL)
{
	struct tCursor *pCursor;

	pCursor = (struct tCursor *)malloc(sizeof(struct tCursor));
	pCursor->pSLL = pSLL;
	pCursor->pNode = pSLL->pHeadNode;
	return pCursor;
}

struct tCursor * cursor_reset(struct tCursor * pCursor)
{
	pCursor->pNode = pCursor->pSLL->pHeadNode;
	return pCursor;
}

struct tCursor *cursor_next(struct tCursor * pCursor)
{
	pCursor->pNode = pCursor->pNode->pNextNode;
	return pCursor;
}

bool cursor_is_last(struct tCursor * pCursor)
{
	return (pCursor->pNode == pCursor->pSLL->pTailNode);
}

bool cursor_has_end(struct tCursor * pCursor)
{
	return (pCursor->pNode == NULL);
}

void cursor_set_data(struct tCursor * pCursor,void * pNodeData)
{
	pCursor->pNode->pNodeData = pNodeData;
}

void * cursor_get_data(struct tCursor * pCursor)
{
	return pCursor->pNode->pNodeData;
}

void cursor_destroy(struct tCursor * pCursor)
{
	free(pCursor);
}

