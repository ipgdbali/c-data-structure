#include "sorted_list.h"
#include <stdio.h>
#include <string.h>

//Sorting descending

int cmp_func(void const * const pLeft, void const * const pRight)
{
	char const * const strLeft = pLeft;
	char const * const strRight = pRight;

	return strcmp(pLeft,pRight) * -1;
}

int main(int argc,char * argv[])
{

	struct tSortedList *pSortedList;
	struct tSLLIterator * pSLLIter;
	char strNama[125];
	int len;

	pSortedList = sl_init(true,cmp_func);
	while(!feof(stdin))
	{
		scanf("%s\n",strNama);
		sl_push(pSortedList,strNama,strlen(strNama));
	}
	pSLLIter = sll_iterator_init(sl_get_linked_list(pSortedList));
	sll_iterator_reset(pSLLIter);
	for(sll_iterator_reset(pSLLIter);!sll_iterator_is_null(pSLLIter);sll_iterator_next(pSLLIter))
	{
		printf("%s\n", (char *)sll_iterator_peek_curr(pSLLIter) );
	}

	sll_iterator_destroy(pSLLIter);
	sl_destroy(pSortedList);
	return 0;
}
