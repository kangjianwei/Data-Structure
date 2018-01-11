/*************************
 *                       *
 * 文件夹: ▲10 内部排序 *
 *                       *
 * 文件名: BubbleSort.c  *
 *                       *
 *************************/

#ifndef BUBBLESORT_C
#define BUBBLESORT_C

#include "BubbleSort.h" 				//**▲10 内部排序**//

void BubbleSort(SqList_sort *L)
{
	int i, j;
	RcdType tmp;
	Status tag;
	
	for(i=(*L).length; i>=2; i--)
	{
		tag = FALSE;					//tag标记遍历过程是否发生的交换 
		
		for(j=1; j<=i-1; j++)
		{
			if(LT((*L).r[j+1].key, (*L).r[j].key))
			{
				tmp = (*L).r[j+1];
				(*L).r[j+1] = (*L).r[j];
				(*L).r[j] = tmp;
				
				tag = TRUE;				//若遍历不发生交换，说明序列已经有序 
			} 
		}
		
		if(!tag)
			break;
	} 
}

#endif
