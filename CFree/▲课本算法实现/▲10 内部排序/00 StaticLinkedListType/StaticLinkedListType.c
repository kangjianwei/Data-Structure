/**********************************
 *                                *
 * 文件夹: ▲10 内部排序          *
 *                                *
 * 文件名: StaticLinkedListType.c *
 *                                *
 **********************************/

#ifndef STATICLINKEDLISTTYPE_C
#define STATICLINKEDLISTTYPE_C

#include "StaticLinkedListType.h" 		//**▲10 内部排序**//

Status CreateSortList(FILE *fp, SLinkList_sort *L)
{
	int i;
	
	Scanf(fp, "%d", &((*L).length));
	
	if((*L).length>MAXSIZE)
		return ERROR;

	(*L).r[0].rc.key = MAXINT;
	(*L).r[0].next = 0;

	for(i=1; i<=(*L).length; i++)
	{
		Scanf(fp, "%d", &((*L).r[i].rc.key));
		(*L).r[i].next = -1;
	}

	return OK;
}

void Traverse(SLinkList_sort L, void(Visit)(KeyType))
{
	int i;
	
	for(i=1; i<=L.length; i++)
		Visit(L.r[i].rc.key);
	
	printf("\n");
}

#endif
