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
	int					  nNodeCount;
	struct tSLLNode		* pHeadNode;
	struct tSLLNode		* pTailNode;
};

struct tSLLIterator
{
	struct tSingleLinkedList	* pSLL;
	struct tSLLNode				* pNode;
};

// Linked List Related Functions
extern struct tSingleLinkedList * sll_init();
extern void sll_append(struct tSingleLinkedList *,void * );
extern void sll_prepend(struct tSingleLinkedList *,void *);
extern void * sll_pop_head(struct tSingleLinkedList *);
extern void * sll_peek_head(struct tSingleLinkedList *);
extern void * sll_peek_tail(struct tSingleLinkedList *);
extern void sll_destroy(struct tSingleLinkedList *);

//cursor
extern void insert_after_iterator(struct tSLLIterator *,void *);

// Iterator Related Functions
extern struct tSLLIterator * sll_iterator_init(struct tSingleLinkedList *);
extern struct tSLLIterator * sll_iterator_reset(struct tSLLIterator *);
extern struct tSLLIterator * sll_iterator_next(struct tSLLIterator *);
extern bool sll_iterator_is_last(struct tSLLIterator *);
extern bool sll_iterator_has_end(struct tSLLIterator *);
extern void sll_iterator_set_data(struct tSLLIterator *,void *);
extern void * sll_iterator_get_data(struct tSLLIterator *);
extern void sll_iterator_destroy(struct tSLLIterator *);

#endif
