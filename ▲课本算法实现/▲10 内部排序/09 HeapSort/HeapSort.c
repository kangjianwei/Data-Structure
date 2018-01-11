/*************************
 *                       *
 * 文件夹: ▲10 内部排序 *
 *                       *
 * 文件名: HeapSort.c    *
 *                       *
 * 算  法: 10.10、10.11  *
 *                       *
 *************************/

#ifndef HEAPSORT_C
#define HEAPSORT_C

#include "HeapSort.h" 							//**▲10 内部排序**//

/*═════╗
║ 算法10.10║ 
╚═════*/
void HeapAdjust(HeapType *H, int s, int m)
{
	int j;
	RcdType rc;
	
	rc = (*H).r[s];
	
	for(j=2*s; j<=m; j*=2)						//沿key较大的孩子结点向下筛选 
	{
		if(j<m&&LT((*H).r[j].key, (*H).r[j+1].key))
			j++;								//j为key较大的记录的下标 
		
		if(!LT(rc.key, (*H).r[j].key))
			break;								//rc应插入在位置s上 
		
		(*H).r[s] = (*H).r[j];
		
		s = j;
	}
	
	(*H).r[s] = rc;							//插入 
} 

/*═════╗
║ 算法10.11║ 
╚═════*/
void HeapSort(HeapType *H)
{
	int i;
	RcdType tmp;
	
	for(i=(*H).length/2; i>0; i--)			//把H.r[1..H.length]建成大顶堆 
		HeapAdjust(H, i, (*H).length);
	
	for(i=(*H).length; i>1; i--)
	{
		tmp = (*H).r[1];					//将堆顶记录和当前未经排序子序列Hr[1..i]中最后一个记录交换 
		(*H).r[1] = (*H).r[i];
		(*H).r[i] = tmp;
		
		HeapAdjust(H, 1, i-1);				//将H.r[1..i-1]重新调整为大顶堆 
	}
}

#endif
