/*************************
 *                       *
 * 文件夹: ▲10 内部排序 *
 *                       *
 * 文件名: InsertSort.c  *
 *                       *
 * 算  法: 10.1          *
 *                       *
 *************************/

#ifndef INSERTSORT_C
#define INSERTSORT_C

#include "InsertSort.h" 							//**▲10 内部排序**//

/*════╗
║算法10.1║ 
╚════*/
void InsertSort(SqList_sort *L)
{
	int i, j;
	
	for(i=2; i<=(*L).length; i++)
	{
		if(LT((*L).r[i].key, (*L).r[i-1].key))		//"<"，需将L.r[i]插入有序子表 
		{
			(*L).r[0] = (*L).r[i];					//复制为哨兵 
			(*L).r[i] = (*L).r[i-1];
			for(j=i-1; LT((*L).r[0].key, (*L).r[j].key); --j)
				(*L).r[j+1] = (*L).r[j];			//记录后移
			(*L).r[j+1] = (*L).r[0];				//插入到正确位置 
		}
	}
}

#endif
