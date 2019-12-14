/*************************
 *                       *
 * �ļ���: ��10 �ڲ����� *
 *                       *
 * �ļ���: ShellSort.c   *
 *                       *
 * ��  ��: 10.4��10.5    *
 *                       *
 *************************/

#ifndef SHELLSORT_C
#define SHELLSORT_C

#include "ShellSort.h" 							//**��10 �ڲ�����**//

/*�T�T�T�T�[
�U�㷨10.4�U 
�^�T�T�T�T*/
void ShellInsert(SqList_sort *L, int dk)
{
	int i, j;
	
	for(i=dk+1; i<=(*L).length; i++)			//dkΪǰ���¼��λ��������r[0]���ݴ浥Ԫ 
	{
		if(LT((*L).r[i].key, (*L).r[i-dk].key))	//��L.r[i]�������������ӱ� 
		{
			(*L).r[0] = (*L).r[i];				//�ݴ���L.r[0] 
			
			for(j=i-dk; j>0&&LT((*L).r[0].key, (*L).r[j].key); j-=dk)
				(*L).r[j+dk] = (*L).r[j];		//��¼���ƣ����Ҳ���λ�� 
			
			(*L).r[j+dk] = (*L).r[0];			//���� 
		}
	} 
} 

/*�T�T�T�T�[
�U�㷨10.5�U 
�^�T�T�T�T*/
void ShellSort(SqList_sort *L, int dlta[], int t)
{
	int k; 
	
	for(k=0; k<t; k++)
		ShellInsert(L, dlta[k]);				//һ������Ϊdlta[k]�Ĳ������� 
}

#endif
