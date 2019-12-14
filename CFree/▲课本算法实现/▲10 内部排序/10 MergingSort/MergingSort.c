/*******************************
 *                             *
 * 文件夹: ▲10 内部排序       *
 *                             *
 * 文件名: MergingSort.c       *
 *                             *
 * 算  法: 10.12、10.13、10.14 *
 *                             *
 *******************************/

#ifndef MERGINGSORT_C
#define MERGINGSORT_C

#include "MergingSort.h"	//**▲10 内部排序**//

/*═════╗
║ 算法10.12║ 
╚═════*/
void Merge(RcdType SR[], RcdType TR[], int i, int m, int n)
{
	int j, k;
	
	for(j=m+1,k=i; i<=m&&j<=n; ++k)			//将SR中记录由小到大地并入TR 
	{
		if(LQ(SR[i].key, SR[j].key))
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
		
	while(i<=m)								//将剩余的SR[i..m]复制到TR 
		TR[k++] = SR[i++];
	
	while(j<=n)								//将剩余的SR[j..n]复制到TR 
		TR[k++] = SR[j++];
}

/*═════╗
║ 算法10.13║ 
╚═════*/
void MSort(RcdType SR[], RcdType TR[], int s, int t)
{
	int m;
	RcdType R[MAXSIZE+1];
	
	if(s==t)
		TR[s] = SR[s];
	else
	{
		m = (s+t)/2;						//将SR[s..t]平分为SR[s..m]和SR[m+1..t] 
		MSort(SR, R, s, m);					//递归地将SR[s..m]归并为有序的R[s..m] 
		MSort(SR, R, m+1, t);				//递归地将SR[m+1..t]归并为有序的R[m+1..t] 
		Merge(R, TR, s, m, t);				//将R[s..m]和R[m+1..t]归并到TR[s..t] 
	}
}

/*═════╗
║ 算法10.14║ 
╚═════*/
void MergeSort(SqList_sort *L)
{	
	MSort((*L).r, (*L).r, 1, (*L).length);
}

#endif
