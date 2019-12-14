/**************************
 *                        *
 * 文件夹: ▲10 内部排序  *
 *                        *
 * 文件名: 2-InsertSort.c *
 *                        *
 **************************/

#ifndef TWOWAYINSERTSORT_C
#define TWOWAYINSERTSORT_C

#include "2-InsertSort.h" 					//**▲10 内部排序**//

void TwoTayInsertSort(SqList_sort *L)
{
	int first, final, i, j;
	RcdType d[MAXSIZE];						//从0号单元开始存储 
	
	if((*L).length>0)
	{
		d[0] = (*L).r[1];
		first = final = 0;
	}
	
	for(i=2; i<=(*L).length; i++)				 
	{
		if(LT((*L).r[i].key, d[first].key))
		{
			first = (first-1+MAXSIZE)%MAXSIZE;
			d[first] = (*L).r[i];
		}
		else if(LT((*L).r[i].key, d[final].key))
		{
			j = final;
			do
			{
				d[(j+1)%MAXSIZE] = d[j];
				j = (j-1+MAXSIZE)%MAXSIZE;
			}while(LT((*L).r[i].key, d[j].key));
			
			d[(j+1)%MAXSIZE] = (*L).r[i];
			final = (final+1)%MAXSIZE;
		}
		else
		{
			final = (final+1)%MAXSIZE;
			d[final] = (*L).r[i];
		}
	}
	
	for(i=1,j=first; i<=(*L).length; i++,j=(j+1)%MAXSIZE)
		(*L).r[i] = d[j];
}

#endif
