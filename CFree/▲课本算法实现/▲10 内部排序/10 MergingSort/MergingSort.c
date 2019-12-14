/*******************************
 *                             *
 * �ļ���: ��10 �ڲ�����       *
 *                             *
 * �ļ���: MergingSort.c       *
 *                             *
 * ��  ��: 10.12��10.13��10.14 *
 *                             *
 *******************************/

#ifndef MERGINGSORT_C
#define MERGINGSORT_C

#include "MergingSort.h"	//**��10 �ڲ�����**//

/*�T�T�T�T�T�[
�U �㷨10.12�U 
�^�T�T�T�T�T*/
void Merge(RcdType SR[], RcdType TR[], int i, int m, int n)
{
	int j, k;
	
	for(j=m+1,k=i; i<=m&&j<=n; ++k)			//��SR�м�¼��С����ز���TR 
	{
		if(LQ(SR[i].key, SR[j].key))
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
		
	while(i<=m)								//��ʣ���SR[i..m]���Ƶ�TR 
		TR[k++] = SR[i++];
	
	while(j<=n)								//��ʣ���SR[j..n]���Ƶ�TR 
		TR[k++] = SR[j++];
}

/*�T�T�T�T�T�[
�U �㷨10.13�U 
�^�T�T�T�T�T*/
void MSort(RcdType SR[], RcdType TR[], int s, int t)
{
	int m;
	RcdType R[MAXSIZE+1];
	
	if(s==t)
		TR[s] = SR[s];
	else
	{
		m = (s+t)/2;						//��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t] 
		MSort(SR, R, s, m);					//�ݹ�ؽ�SR[s..m]�鲢Ϊ�����R[s..m] 
		MSort(SR, R, m+1, t);				//�ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����R[m+1..t] 
		Merge(R, TR, s, m, t);				//��R[s..m]��R[m+1..t]�鲢��TR[s..t] 
	}
}

/*�T�T�T�T�T�[
�U �㷨10.14�U 
�^�T�T�T�T�T*/
void MergeSort(SqList_sort *L)
{	
	MSort((*L).r, (*L).r, 1, (*L).length);
}

#endif
