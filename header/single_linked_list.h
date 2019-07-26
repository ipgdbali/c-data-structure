#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct tSLLNode
{
	void			* pNodeData;
	struct tSLLNode * pNextNode;
};

struct tSingleLinkedList
{
	struct tSLLNode * pHeadNode;
	struct tSLLNode * pTailNode;
};

struct tSLLIterator
{
	struct tSingleLinkedList	* pSLL;
	struct tSLLNode				* pNode;
};

// Linked List Related Functions
extern struct tSingleLinkedList * sll_init();
extern void sll_append_tail(struct tSingleLinkedList *pSLL,void * pNodeData);
extern void sll_append_head(struct tSingleLinkedList *pSLL,void *pNodeData);
extern void sll_destroy(struct tSingleLinkedList * pSLL);

extern void insert_after_cursor(struct tSLLIterator * pIterator,void * pNodeData);

// Cursor Related Functions
extern struct tSLLIterator * sll_iterator_init(struct tSingleLinkedList * pSLL);
extern struct tSLLIterator * sll_iterator_reset(struct tSLLIterator * pIterator);
extern struct tSLLIterator *sll_iterator_next(struct tSLLIterator * pIterator);
extern bool sll_iterator_is_last(struct tSLLIterator * pIterator);
extern bool sll_iterator_has_end(struct tSLLIterator * pIterator);
extern void sll_iterator_set_data(struct tSLLIterator * pIterator,void * pNodeData);
extern void * sll_iterator_get_data(struct tSLLIterator * pIterator);
extern void sll_iterator_destroy(struct tSLLIterator * pIterator);

#endif
