
struct tLinkedListNode
{
	void	*pData;
	int		iData;
	struct tLinkedListNode *pNext;
};

typedef tLinkedListNode tLinkedListNode;

tLinkedListNode * getLinkedListHead();
tLinkedListNode * getLinkedListTail();
bool addBeforeFirst(tLinkedListNode *);
bool addLast(tLinkedListNode *);

tLinkedListNode * getNextNode();
