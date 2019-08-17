#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "single_linked_list_iterator.h"

struct tSortedList
{
	bool bDuplicate;
	struct tSingleLinkedList	*	pLinkedList;
	int (*cmp_func)(void const * const,void const * const);
};

/*
 * Init Sorted List
 * Params :
 *  - bool : allow Duplicate ?
 *  - pointer to compare function return int
 *    LHS < RHS : < 0
 *    LHS = RHS : = 0
 *    LHS > RHS : > 0
 */
extern struct tSortedList * sl_init(bool,int (*)(void const * const ,void const * const));

extern bool sl_push(struct tSortedList * ,void const * const,size_t);
extern struct tSLLIterator * sl_get_head_iterator(struct tSortedList *);

extern void sl_destroy(struct tSortedList *);

#endif
