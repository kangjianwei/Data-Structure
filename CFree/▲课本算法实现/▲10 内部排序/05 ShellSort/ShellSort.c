/*************************
 *                       *
 * 文件夹: ▲10 内部排序 *
 *                       *
 * 文件名: ShellSort.c   *
 *                       *
 * 算  法: 10.4、10.5    *
 *                       *
 *************************/

#ifndef SHELLSORT_C
#define SHELLSORT_C

#include "ShellSort.h" 							//**▲10 内部排序**//

/*════╗
║算法10.4║ 
╚════*/
void ShellInsert(SqList_sort *L, int dk)
{
	int i, j;
	
	for(i=dk+1; i<=(*L).length; i++)			//dk为前后记录的位置增量，r[0]作暂存单元 
	{
		if(LT((*L).r[i].key, (*L).r[i-dk].key))	//将L.r[i]插入有序增量子表 
		{
			(*L).r[0] = (*L).r[i];				//暂存在L.r[0] 
			
			for(j=i-dk; j>0&&LT((*L).r[0].key, (*L).r[j].key); j-=dk)
				(*L).r[j+dk] = (*L).r[j];		//记录后移，查找插入位置 
			
			(*L).r[j+dk] = (*L).r[0];			//插入 
		}
	} 
} 

/*════╗
║算法10.5║ 
╚════*/
void ShellSort(SqList_sort *L, int dlta[], int t)
{
	int k; 
	
	for(k=0; k<t; k++)
		ShellInsert(L, dlta[k]);				//一趟增量为dlta[k]的插入排序 
}

#endif
