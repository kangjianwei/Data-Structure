/*************************
 *                       *
 * �ļ���: ��10 �ڲ����� *
 *                       *
 * �ļ���: BubbleSort.c  *
 *                       *
 *************************/

#ifndef BUBBLESORT_C
#define BUBBLESORT_C

#include "BubbleSort.h" 				//**��10 �ڲ�����**//

void BubbleSort(SqList_sort *L)
{
	int i, j;
	RcdType tmp;
	Status tag;
	
	for(i=(*L).length; i>=2; i--)
	{
		tag = FALSE;					//tag��Ǳ��������Ƿ����Ľ��� 
		
		for(j=1; j<=i-1; j++)
		{
			if(LT((*L).r[j+1].key, (*L).r[j].key))
			{
				tmp = (*L).r[j+1];
				(*L).r[j+1] = (*L).r[j];
				(*L).r[j] = tmp;
				
				tag = TRUE;				//������������������˵�������Ѿ����� 
			} 
		}
		
		if(!tag)
			break;
	} 
}

#endif
