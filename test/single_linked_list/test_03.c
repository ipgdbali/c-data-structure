#include <stdio.h>
#include <string.h>
#include "single_linked_list.h"

int main(int argc,char * argv[])
{
	struct tSingleLinkedList SLL;
	char strNama[125];
	int len;
	
	sll_init(&SLL,true);

	do
	{
		printf("Masukkan Nama [MAX=125] : ");
		fgets(strNama,125,stdin);
		len = strlen(strNama);
		//dismis enter
		strNama[len - 1] = 0;
		len--;
		if(len > 0)
			sll_append(&SLL,strNama,len + 1);
	}while(len > 0);
	printf("\nResult :\n");

	len = 0;

	do
	{
		len++;
		sll_get_node_data(&SLL,eHeadNode,strNama);
		printf("[%d] %s\n",len,strNama);
	}while(sll_pop_head(&SLL) > 0);

	sll_destroy(&SLL);
	
	return 0;
}
