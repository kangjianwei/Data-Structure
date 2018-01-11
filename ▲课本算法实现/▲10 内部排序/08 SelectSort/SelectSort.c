/*************************
 *                       *
 * 文件夹: ▲10 内部排序 *
 *                       *
 * 文件名: SelectSort.c  *
 *                       *
 * 算  法: 10.9          *
 *                       *
 *************************/

#ifndef SELECTSORT_C
#define SELECTSORT_C

#include "SelectSort.h" 							//**▲10 内部排序**//

/*════╗
║算法10.9║ 
╚════*/
void SelectSort(SqList_sort *L)
{
	int i, j;
	RcdType tmp;
	
	for(i=1; i<(*L).length; i++)
	{
		j = SelectMinKey(*L, i);
		
		if(i!=j)
		{
			tmp = (*L).r[i];
			(*L).r[i] = (*L).r[j];
			(*L).r[j] = tmp;
		}
	}
}

int SelectMinKey(SqList_sort L, int i)
{
	int min, k;
	
	min = i;
	L.r[0] = L.r[i];
	
	for(k=i; k<=L.length; k++)
	{
		if(L.r[k].key<L.r[0].key)
		{
			min = k;
			L.r[0] = L.r[k];		
		}
	}
	
	return min;
}

#endif
