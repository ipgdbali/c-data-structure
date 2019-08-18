#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "single_linked_list_iterator.h"

struct tSortedList
{
	bool bDuplicate;
	struct tSingleLinkedList	*	pLinkedList;
	int (*cmp_func)(void const *,void const *);
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
extern struct tSortedList * sl_init(bool,int (*)(void const *,void const *));

extern bool sl_push(struct tSortedList * ,void const *,size_t);

extern struct tSortedList const * const sl_get_linked_list(struct tSortedList const * const);

extern void sl_destroy(struct tSortedList *);

#endif
