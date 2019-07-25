#include "single_linked_list.h"

struct tSingleLinkedList * sll_init()
{
	struct tSingleLinkedList * sll;
	sll = (struct tSingleLinkedList *)malloc(sizeof(tSingleLinkedList));
	return sll;
}

void sll_append_tail(struct tSingleLinkedList *pSLL,void * pNodeData)
{
	struct tSingleLinkedListNode * pNode;

	assert(pSLL != NULL);

	pNode = (struct tSingleLinkedListNode *)malloc(sizeof(struct tSingleLinkedListNode));
	pNode->pNodeData = pNodeData;
	pNode->pNodeData = NULL;
	pSLL->pTail->pNextNode = pNode;
	pSLL->pTail = pNode;
}

void sll_append_head(struct tSingleLinkedList *pSLL,void *pNodeData)
{
	struct tSingleLinkedListNode * pNode;

	assert(pSLL != NULL);

	pNode = (struct tSingleLinkedListNode *)malloc(sizeof(struct tSingleLinkedListNode));
	pNode->pNodeData = pNodeData;
	pNode->pNextNode = pSLL->pHeadNode;
	pSLL->pHeadNode = pNode;
}

void sll_destroy(tSingleLinkedList * pSLL)
{
	free(pSLL);
}

//CURSOR
struct tCursor * cursor_init(struct tSingleLinkedList * pSLL)
{
	struct tCursor *pCursor;

	pCursor = (struct tCursor *)malloc(sizeof(struct tCursor));
	pCursor->pNode = pSLL->pHeadNode;
	return pCursor;
}

struct tCursor *cursor_next(struct tCursor * pCursor)
{
	pCursor->pNode = pCursor->pNode->pNextNode;
	return pCursor;
}

bool cursor_is_last(struct tCursor * pCursor)
{
	return (pCursor->pNode->pNextNode == NULL);
}

void cursor_set_data(struct tCursor * pCursor,void * pNodeData)
{
	pCursor->pNode->pNodeData = pNodeData;
}

void * cursor_get_data(struct tCursor * pCursor)
{
	return pCursor->pNode->pNodeData;
}

void cursor_free(struct tCursor * pCursor)
{
	free(pCursor);
}

