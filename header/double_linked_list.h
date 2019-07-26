#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

struct tDLLNode
{
	void * pNodeData;
	struct tDLLNode	* pPrevNode;
	struct tDLLNode	* pNextNode;
};


struct tDoubleLinkedList
{
	struct tDLLNode	* pHeadNode;
	struct tDLLNode	* pTailNode;
};

struct tDLLIterator
{
	struct tDLLNode	* pNode;
}

extern struct tDoubleLinkedList * dll_init();
extern void dll_destroy(struct tDoubleLinkedList * pDLL);

extern void dll_append_after_tail(struct tDoubleLinkedList * pDLL,void * pNodeData);
extern void dll_prepend_before_tail(struct tDoubleLinkedList * pDLL,void * pNodeData);

extern struct tDLLIterator * dll_iterator_init(struct tDoubleLinkedList * pDLL);
extern void dll_iterator_destroy(struct tDLLIterator * pIterator);

// Movement
extern struct tDLLIterator * dll_iterator_first(struct tDoubleLinekdListIterator *pIterator);
extern struct tDLLIterator * dll_iterator_last(struct tDLLIterator *pIterator);
extern struct tDLLIterator * dll_iterator_next(struct tDLLIterator *pIterator);
extern struct tDLLIterator * dll_iterator_prev(struct tDLLIterator *pIterator);

//Status
extern bool dll_iterator_is_first(struct tDLLIterator * pIterator);
extern bool dll_iterator_is_last(struct tDLLIterator * pIterator);
extern bool dll_iterator_is_null(struct tDLLIterator * pIterator);

//Get & Set Data
void * dll_iterator_get_data(struct tDLLIterator * pIterator);
void dll_iterator_set_data(struct tDoubleLinekdListIterator * pIterator,void * pNodeData);

#endif
