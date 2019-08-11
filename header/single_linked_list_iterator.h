#ifndef SINGLE_LINKED_LIST_ITERATOR_H
#define SINGLE_LINKED_LIST_ITERATOR_H

#include "single_linked_list.h" 

struct tSLLIterator
{
	struct tSingleLinkedList	* pSLL;
	struct tSLLNode				* pNode;
};

/*
 * Initializing Iterator and set Iterator to HeadNode
 */
extern struct tSLLIterator * sll_iterator_init(struct tSingleLinkedList *);

/*
 * Reset Iterator to Head Node
 */
extern struct tSLLIterator * sll_iterator_reset(struct tSLLIterator *);
/*
 * Extend Iterator to Next Node
 */
extern struct tSLLIterator * sll_iterator_next(struct tSLLIterator *);
/*
 * Check Iterator Position to Last Node
 */
extern bool sll_iterator_is_last(struct tSLLIterator *);
/*
 * Iterator has pass Last Node
 */
extern bool sll_iterator_has_end(struct tSLLIterator *);
/*
 * Set Data for Node pointed by Iterator
 */
extern void sll_iterator_set_data(struct tSLLIterator *,void *,size_t);
/*
 * Get Data for Node pointed by Iterator
 */
extern void sll_iterator_get_data(struct tSLLIterator *,void *,size_t *);
/*
 * Destroy Iterator
 */
extern void sll_iterator_destroy(struct tSLLIterator *);

/*
 * Insert Node after node pointed by iterator
 */
extern void insert_after_iterator(struct tSLLIterator *,void *,size_t);

#endif
