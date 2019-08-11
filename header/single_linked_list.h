#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct tSLLNode
{
	void			* pNodeData;
	size_t			  szNodeData;
	struct tSLLNode * pNextNode;
};

struct tSingleLinkedList
{
	size_t				  nNodeCount;
	struct tSLLNode		* pHeadNode;
	struct tSLLNode		* pTailNode;
};

/*
 * Initialize Single Linked List
 */
extern struct tSingleLinkedList * sll_init();
/*
 * Appending Node to after tail
 */
extern void sll_append(struct tSingleLinkedList *,void *,size_t);
/*
 * Prepending Node Before Head
 */
extern void sll_prepend(struct tSingleLinkedList *,void *,size_t);

/*
 * Poping Head Node
 */
extern bool sll_pop_head(struct tSingleLinkedList *);

/*
 * Peek Head Node
 * if void * is NULL then size_t fill with size only
 */
extern bool sll_peek_head(struct tSingleLinkedList *,void *,size_t *);
/*
 * Counting Node
 */
extern size_t sll_node_count(struct tSingleLinkedList *);
/*
 * Destroying Single Linked List
 */
extern void sll_destroy(struct tSingleLinkedList *);

#endif
