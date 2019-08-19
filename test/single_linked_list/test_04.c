#include <stdio.h>
#include "single_linked_list.h"

int main(int argc,char * argv[])
{
	struct tSingleLinkedList	*pSLL;
	char strNama[125];
	int len;
	pSLL = sll_init();

	do
	{
		printf("Masukkan Nama [MAX=125] : ");
		fgets(strNama,125,stdin);
		len = strlen(strNama);
		strNama[len - 1] = 0;
		len--;
		if(len > 0)
			sll_prepend(pSLL,strNama,len + 1);
	}while(len > 0);
	printf("Result :\n");
	len = 0;
	do
	{
		len++;
		sll_get_head(pSLL,strNama,NULL);
		printf("[%d] %s\n",len,strNama);
	}while(sll_pop_head(pSLL));
	sll_destroy(pSLL);
	
	return 0;
}
