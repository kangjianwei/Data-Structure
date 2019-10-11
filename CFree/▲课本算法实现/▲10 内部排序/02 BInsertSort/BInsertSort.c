/*************************
 *                       *
 * 文件夹: ▲10 内部排序 *
 *                       *
 * 文件名: BInsertSort.c *
 *                       *
 * 算  法: 10.2          *
 *                       *
 *************************/

#ifndef BINSERTSORT_C
#define BINSERTSORT_C

#include "BInsertSort.h" 	//**▲10 内部排序**//

/*════╗
║算法10.2║ 
╚════*/
void BInsertSort(SqList_sort *L)
{
	int i, j, low, high, m;
	
	for(i=2; i<=(*L).length; ++i)
	{
		(*L).r[0] = (*L).r[i];						//将(*L).r[i]暂存到(*L).r[0] 
		low = 1;
		high = i - 1;
		
		while(low<=high)							//在r[low..high]中折半查找有序插入的位置	
		{
			m = (low+high)/2;						//折半 
			
			if(LT((*L).r[0].key, (*L).r[m].key))	//插入点在低半区 
				high = m - 1;
			else									//插入点在高半区 
				low = m + 1;

		}
			
		for(j=i-1; j>=high+1; --j)					//记录后移 
			(*L).r[j+1] = (*L).r[j];
		
		(*L).r[high+1] = (*L).r[0];					//插入 
	}
}

#endif
