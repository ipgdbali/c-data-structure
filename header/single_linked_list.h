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
 * FUNCTION sll_init()
 *		Returning A Pointer to Initialized Single Linked List
 *		Has to be destroyed with sll_destroy after used.
 *
 *	Parameter :
 *	 - struct tSingleLinkedList
 *		LinkedList to be Created
 *
 *	Return
 *		bool
 *		- FALSE	: UnSuccess
 *		- TRUE	: Success
 */
extern bool sll_init(struct tSingleLinkedList *);

/*
 * FUNCTION sll_destroy()
 *		Destroying Single Linked List
 *		Single Linked List that has been destroy cannot be used.
 *		Beside node, data inside node is also freed.
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
 * FUNCTION sll_append
 *		Appending Data to Tail Node of Single Linked List.
 *		Data will be copied to node using malloc (not just its pointer)
 *
 *  Parameters
 *	 - struct tSingleLinkedList
 *		Linkedlist to be appended to
 *	 - void const *
 *		data that needs to be appended
 *	 - size_t
 *		size of data that needs to be appended
 *
 *  Return 
 *	 bool
 *	 - FALSE
 *	 	If Not Succeed
 *	 - TRUE
 *		If Succeeded
 */
extern bool sll_append(struct tSingleLinkedList *,void const *,size_t);

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
extern bool sll_prepend(struct tSingleLinkedList *,void const * ,size_t);

/*
 * FUNCTION sll_head_data
 *		Get Copy of Tail's Data AND/OR its size.
 *		Put Buffer to NULL to get its size (only)
 *			
 *  Parameters
 *		- struct tSingleLinkedList *
 *			Pointer to tSingleLinkedList struct where this function is to operate
 *		- void *
 *			Buffer where data to be copied
 *		- size_t *
 *			Size of Buffers
 *
 *	Return : bool
 *		- TRUE	: Succeded
 *		- FALSE	: Not Succeeded
 *
 */
extern bool sll_head_data(struct tSingleLinkedList *,void *,size_t * );

/*
 * FUNCTION sll_tail_data
 *		Get Copy of Tail Data AND/OR its size.
 *		Put Buffer to NULL to get its size (only)
 *			
 *  Parameters
 *		- struct tSingleLinkedList *
 *			Pointer to tSingleLinkedList struct where this function is to operate
 *		- void *
 *			Buffer where data to be copied
 *		- size_t *
 *			Size of Buffers
 *
 *	Return : bool
 *		- TRUE	: Succeded
 *		- FALSE	: Not Succeeded
 *
 */
extern bool sll_tail_data(struct tSingleLinkedList *,void *,size_t * );

/*
 * FUNCTION sll_peek_head
 *		Peek Head Node of Single Linked List
 *
 *  Parameter
 *	 - struct tSingleLinkedList *
 *		Pointer to struct tSingleLinkedList to be peeked
 *
 *	Return void const *
 *		Pointer to Data Inside Head Node
 */
extern void const * sll_peek_head(struct tSingleLinkedList *);

/*
 * FUNCTION sll_peek_tail
 *		Peeks Tail Node of Single Linked List
 *
 *	Parameters
 *	 - struct tSingleLinkedList *
 *		Pointer to SingleLinkedList to be peeked
 *	
 *	Return : void const *
 *		Pointer to Data Inside Tail Node
 *	
 */
extern void const * sll_peek_tail(struct tSingleLinkedList *);

/*
 * FUNCTION sll_pop_head
 *		Advancing HeadNode anda dispose previous HeadNode
 *
 *	Parameters
 *	 - struct tSingleLinkedList
 *		Pointer to SingleLinkedList thats needs to be popped
 *  
 *  Return : bool
 *		-FALSE	: if has no node
 *		-TRUE	: something else
 */
extern bool sll_pop_head(struct tSingleLinkedList *);

/*
 * FUNCTION sll_node_count
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
extern size_t sll_node_count(struct tSingleLinkedList *);

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
extern struct tSLLNode * _createNode(void const *,size_t);


#endif
