#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct tSLLNode
{
	const void		* pNodeData;
	size_t			  szNodeData;
	struct tSLLNode * pNextNode;
};

struct tSingleLinkedList
{
	bool				  bDeepCopy;
	size_t				  nNodeCount;
	struct tSLLNode		* pHeadNode;
	struct tSLLNode		* pTailNode;
};

enum eNodeKind	{eHeadNode,eTailNode};

/*
 * FUNCTION sll_init()
 *		Initialized A Single Linked List.
 *		Has to be destroyed with sll_destroy after used.
 *		Data passed to Single Linked List, can be duplicated with new
 *		allocated memory (malloc) or just copy the pointer.
 *
 * PARAMETER
 *	 - struct tSingleLinkedList
 *		LinkedList to be Created
 *
 *	 - bool
 *		If data to be copied put TRUE (Deep Copy).
 *		To just copy pointer, put FALSE
 *
 * RETURN
 *		void
 */
extern void sll_init(struct tSingleLinkedList *,bool);

/*
 * FUNCTION sll_destroy()
 *		Destroying A Single Linked List
 *		Single Linked List that has been destroy cannot be used.
 *		If Deep Copy is used, data inside single linked list is freed.
 *
 *  Parameters
 *		struct tSingleLinkedList
 *			Pointer to SingleLinkedList needs to be destroyed
 *
 *	Return
 *		void
 */
extern void sll_destroy(struct tSingleLinkedList *);

/*
 * FUNCTION 
 *		bool sll_append(struct tSingleLinkedList *,void const * size_t)
 *
 * DESCRIPTION
 *		Appending Data to Tail Node of Single Linked List.
 *
 * PARAMETERS
 *	 - struct tSingleLinkedList
 *		Linkedlist to be appended to
 *
 *	 - void const *
 *		data that needs to be appended
 *
 *	 - size_t
 *		size of data that needs to be appended
 *
 * RETURN 
 *	 bool
 *	 - FALSE
 *	 	If Not Succeed
 *	 - TRUE
 *		If Succeeded
 */
extern bool sll_append(struct tSingleLinkedList *pSLL,const void * pData,size_t size);

/*
 * FUNCTION sll_prepend
 *		Prepending Data Before Head Node of Single Linked List
 *		New Data will be the Head Node
 *
 * Parameters
 *	- struct tSingleLinkedList *
 *		LinkedList to be appended to
 *	- void const *
 *		Data that needs to be appended
 *	- size_t
 *		Size of data that needs to be appended
 *
 * Return 
 *	bool
 *	- FALSE 
 *		if not success
 *	- TRUE
 *		if succeess
 */
extern bool sll_prepend(struct tSingleLinkedList *pSLL,const void * pData,size_t size);

/*
 * FUNCTION sll_pop_head
 *		Advancing HeadNode anda dispose previous HeadNode
 *
 *	Parameters
 *	 - struct tSingleLinkedList
 *		Pointer to SingleLinkedList thats needs to be popped
 *  
 *  Return : bool
 *		-FALSE	: if there is no head node
 *		-TRUE	: Sucess 
 */

extern bool sll_pop_head(struct tSingleLinkedList *);

/*
 *
 *
 *
 */
extern bool sll_get_node_data(struct tSingleLinkedList * pSLL,enum eNodeKind nodeKind,void *pNodeData);

/*
 *
 *
 *
 */
extern size_t sll_get_node_data_size(struct tSingleLinkedList * pSLL,enum eNodeKind nodeKind);

/*
 *
 *
 */
extern bool sll_get_deep_copy(struct tSingleLinkedList const * pSLL);

/*
 * FUNCTION sll_get_node_count
 *		Returning Number of Node in Single Linked List
 *
 *  Parameters	:
 *	 - struct tSingleLinkedList *
 *		Pointer to SingleLinkedList to get the number of node
 *
 *	Return		: size_t
 *		Number of Node in SingleLinkedList
 *			
 */
extern size_t sll_get_node_count(struct tSingleLinkedList const *);

/*
 * PRIVATE FUNCTION _createNode
 *		Create A SingleLinkedList Node with data and size
 *
 * Parameters
 *  - void const *
 *		Data to be saved inside Single Linked List Node
 *	- size_t
 *		Size of Data to be save inside Single Linked List Node
 *	
 *	Return		: struct tSLLNode *
 *		Pointer to Single Linked List's Node contains with data and size
 *
 */
extern struct tSLLNode * _createNode(struct tSingleLinkedList *,const void *,size_t const);


#endif
