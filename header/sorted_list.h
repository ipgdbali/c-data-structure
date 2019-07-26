#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "single_linked_list.h"

int compare(void * left,void * right)
{
	return 0;
}

extern struct tSortedList * sl_init(bool unique,(*cmp)(void *,void*));

extern bool sl_push(struct tSortedList * pSortedList,const char * string);

extern struct tCursor * sl_get_head_iterable(struct tSortedList * pSortedList);

extern void sl_destroy(struct tSortedList * pSortedList);

#endif
