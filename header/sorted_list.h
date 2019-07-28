#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "single_linked_list.h"

struct tSortedList
{
	struct tSingleLinkedList	*	pLinkedList;
	struct tSLLIterator			*	pIter;
	int (*compare_func)(void *,void*);
};

extern struct tSortedList * sl_init(bool,int (*)(void *,void*));
extern bool sl_push(struct tSortedList * ,void *);
extern struct tSLLIterator * sl_get_head_iterator(struct tSortedList *);

extern void sl_destroy(struct tSortedList *);

#endif
