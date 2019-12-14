/******************************
 *                            *
 * �ļ���: ��10 �ڲ�����      *
 *                            *
 * �ļ���: SequenceListType.c *
 *                            *
 ******************************/

#ifndef SEQUENCELISTTYPE_C
#define SEQUENCELISTTYPE_C

#include "SequenceListType.h" 		//**��10 �ڲ�����**//

Status CreateSortList(FILE *fp, SqList_sort *L)
{
	int i;
	
	Scanf(fp, "%d", &((*L).length));
	
	if((*L).length>MAXSIZE)
		return ERROR;

	for(i=1; i<=(*L).length; i++)
		Scanf(fp, "%d", &((*L).r[i].key));

	return OK;
}

void Traverse(SqList_sort L, void(Visit)(KeyType))
{
	int i;
	
	for(i=1; i<=L.length; i++)
		Visit(L.r[i].key);
	
	printf("\n");
}

#endif
