/*************************
 *                       *
 * �ļ���: ��10 �ڲ����� *
 *                       *
 * �ļ���: InsertSort.c  *
 *                       *
 * ��  ��: 10.1          *
 *                       *
 *************************/

#ifndef INSERTSORT_C
#define INSERTSORT_C

#include "InsertSort.h" 							//**��10 �ڲ�����**//

/*�T�T�T�T�[
�U�㷨10.1�U 
�^�T�T�T�T*/
void InsertSort(SqList_sort *L)
{
	int i, j;
	
	for(i=2; i<=(*L).length; i++)
	{
		if(LT((*L).r[i].key, (*L).r[i-1].key))		//"<"���轫L.r[i]���������ӱ� 
		{
			(*L).r[0] = (*L).r[i];					//����Ϊ�ڱ� 
			(*L).r[i] = (*L).r[i-1];
			for(j=i-1; LT((*L).r[0].key, (*L).r[j].key); --j)
				(*L).r[j+1] = (*L).r[j];			//��¼����
			(*L).r[j+1] = (*L).r[0];				//���뵽��ȷλ�� 
		}
	}
}

#endif
