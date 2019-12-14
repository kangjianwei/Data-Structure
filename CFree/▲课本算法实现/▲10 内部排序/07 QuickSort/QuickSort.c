/****************************
 *                          *
 * �ļ���: ��10 �ڲ�����    *
 *                          *
 * �ļ���: QuickSort.c      *
 *                          *
 * ��  ��: 10.6��10.7��10.8 *
 *                          *
 ****************************/

#ifndef QUICKSORT_C
#define QUICKSORT_C

#include "QuickSort.h" 		//**��10 �ڲ�����**//

/*�T�T�T�T�T�T�[
�U �㷨10.6(a)�U 
�^�T�T�T�T�T�T*/
int Partition_1(SqList_sort *L, int low, int high)
{
	int pivotkey;	
	RcdType tmp;
	
	pivotkey = (*L).r[low].key;					//���ӱ��һ����¼�������¼ 
	
	while(low<high)								//�ӱ�����˽�������м�ɨ�� 
	{
		while(low<high && (*L).r[high].key>=pivotkey)
			high--;
		
		tmp = (*L).r[high];						//���������¼С�ļ�¼�������Ͷ� 
		(*L).r[high] = (*L).r[low];
		(*L).r[low] = tmp;
		
		while(low<high && (*L).r[low].key<=pivotkey)
			low++;
		
		tmp = (*L).r[high];						//���������¼��ļ�¼�������߶�
		(*L).r[high] = (*L).r[low];
		(*L).r[low] = tmp; 
	}
	
	return low;									//������������λ�� 
}

/*�T�T�T�T�T�T�[
�U �㷨10.6(b)�U 
�^�T�T�T�T�T�T*/
int Partition_2(SqList_sort *L, int low, int high)
{
	int pivotkey;
	
	(*L).r[0] = (*L).r[low];					//���ӱ��һ����¼�������¼
	pivotkey = (*L).r[low].key;					//�����¼�ؼ��� 
	
	while(low<high)								//�ӱ�����˽�������м�ɨ�� 
	{
		while(low<high && (*L).r[high].key>pivotkey)
			high--;
		
		(*L).r[low] = (*L).r[high];				//���������¼С�ļ�¼�������Ͷ� 
		
		while(low<high && (*L).r[low].key<=pivotkey)
			low++;
		
		(*L).r[high] = (*L).r[low];				//���������¼��ļ�¼�������߶�
	}
	
	(*L).r[low] = (*L).r[0];					//�����¼��λ 
	
	return low;									//������������λ�� 
}

/*�T�T�T�T�[
�U�㷨10.7�U 
�^�T�T�T�T*/
void QSort(SqList_sort *L, int low, int high)
{
	int pivotloc;
													
	if(low<high)								//���ȴ���1 
	{
	//	pivotloc = Partition_1(L, low, high);	//��(*L).r[row..high]һ��Ϊ��
		
		pivotloc = Partition_2(L, low, high);	//��(*L).r[row..high]һ��Ϊ��
	
		QSort(L, 1, pivotloc-1);				//�Ե��ӱ�ݹ�����pivotloc������λ�� 
		QSort(L, pivotloc+1, high);				//�Ը��ӱ�ݹ����� 
	} 
}

/*�T�T�T�T�[
�U�㷨10.8�U 
�^�T�T�T�T*/
void QuickSort(SqList_sort *L)
{
	QSort(L, 1, (*L).length);
}

#endif
