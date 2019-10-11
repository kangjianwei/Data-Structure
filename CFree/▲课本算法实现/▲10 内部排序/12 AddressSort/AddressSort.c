/*************************
 *                       *
 * 文件夹: ▲10 内部排序 *
 *                       *
 * 文件名: AddressSort.c *
 *                       *
 * 算  法: 10.18         *
 *                       *
 *************************/

#ifndef ADDRESSSORT_C
#define ADDRESSSORT_C

#include "AddressSort.h"	//**▲10 内部排序**//

void AddressSort(SqList_sort *L)
{
	int i, j, tmp;
	int adr[MAXSIZE+1];					//地址数组 
	Status tag;
	
	for(i=1; i<=(*L).length; i++)
		adr[i] = i;
	
	for(i=(*L).length; i>=2; i--)		//使用了起泡排序做示范，也可以用别的排序方法 
	{
		tag = FALSE;					//tag标记遍历过程是否发生的交换
		
		for(j=1; j<=i-1; j++)
		{
			if(LT((*L).r[adr[j+1]].key, (*L).r[adr[j]].key))
			{
				tmp = adr[j+1];
				adr[j+1] = adr[j];
				adr[j] = tmp;
				
				tag = TRUE;				//若遍历不发生交换，说明序列已经有序 
			}		
		}
		
		if(!tag)
			break;
	}
	
	Rearrange(L, adr);
}

/*═════╗
║ 算法10.18║ 
╚═════*/
void Rearrange(SqList_sort *L, int adr[])
{
	int i, j, k;
	
	for(i=1; i<=(*L).length; i++)
	{
		if(adr[i]!=i)
		{
			j = i;
			(*L).r[0] = (*L).r[i];
			
			while(adr[j]!=i)
			{
				k = adr[j];
				(*L).r[j] = (*L).r[k];
				adr[j] = j;
				j = k;
			}
			
			(*L).r[j] = (*L).r[0];
			adr[j] = j;
		}
	}
} 

#endif
