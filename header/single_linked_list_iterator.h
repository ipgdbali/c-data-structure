#ifndef SINGLE_LINKED_LIST_ITERATOR_H
#define SINGLE_LINKED_LIST_ITERATOR_H

#include "single_linked_list.h" 

struct tSLLIterator
{
	struct tSingleLinkedList	* pSLL;
	struct tSLLNode				* pNode;
	struct tSLLNode				* pPrevNode;
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
 * Check Iterator Position to First Node / Head Node
 */
extern bool sll_iterator_is_first(struct tSLLIterator *);
/*
 * Check Iterator Position to Last Node / Tail Node
 */
extern bool sll_iterator_is_last(struct tSLLIterator *);
/*
 * Iterator is null
 */
extern bool sll_iterator_is_null(struct tSLLIterator *);
/*
 * Set Data for Node pointed by Iterator
 */
extern void sll_iterator_set_data(struct tSLLIterator *,void *,size_t);
/*
 * Get Data for Node pointed by Iterator
 */
extern void sll_iterator_get_data(struct tSLLIterator *,void *,size_t *);
/*
 * Return Const Pointer Data of Current Node
 */
extern void const * const sll_iterator_peek_curr(struct tSLLIterator *);
/*
 * Return Const Pointer Data of Current Node
 */
extern void const * const sll_iterator_peek_prev(struct tSLLIterator *);
/*
 * Return Const Pointer Data of Next Node
 */
extern void const * const sll_iterator_peek_next(struct tSLLIterator *);
/*
 * Destroy Iterator
 */
extern void sll_iterator_destroy(struct tSLLIterator *);

/*
 * Insert Node after node pointed by iterator
 */
extern void sll_iterator_insert_after(struct tSLLIterator *,void const * const,size_t);
/*
 * Insert Node before Node  pointed by iterator
 */
extern void sll_iterator_insert_before(struct tSLLIterator *,void const * const, size_t);


#endif
