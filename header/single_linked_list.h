#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdlib.h>
#include <assert.h>

struct tSingleLinkedListNode
{
	void * pNodeData;
	tSingleLinkedListNode * pNextNode;
};

struct tSingleLinkedList
{
	struct tSingleLinkedListNode * pHeadNode;
	struct tSingleLinkedListNode * pTail;
};

struct tCursor
{
	struct tSingleLinkedListNode * pNode;
};

// Linked List Related Functions
extern struct tSingleLinkedList * sll_init()
extern void sll_append_tail(struct tSingleLinkedList *pSLL,void * pNodeData)
extern void sll_append_head(struct tSingleLinkedList *pSLL,void *pNodeData)
extern void sll_destroy(tSingleLinkedList * pSLL)

// Cursor Related Functions
extern struct tCursor * cursor_init(struct tSingleLinkedList * pSLL)
extern struct tCursor *cursor_next(struct tCursor * pCursor)
extern bool cursor_is_last(struct tCursor * pCursor)
extern void cursor_set_data(struct tCursor * pCursor,void * pNodeData)
extern void * cursor_get_data(struct tCursor * pCursor)
extern void cursor_free(struct tCursor * pCursor)

#endif
