/*************************
 *                       *
 * �ļ���: ��10 �ڲ����� *
 *                       *
 * �ļ���: AddressSort.c *
 *                       *
 * ��  ��: 10.18         *
 *                       *
 *************************/

#ifndef ADDRESSSORT_C
#define ADDRESSSORT_C

#include "AddressSort.h"	//**��10 �ڲ�����**//

void AddressSort(SqList_sort *L)
{
	int i, j, tmp;
	int adr[MAXSIZE+1];					//��ַ���� 
	Status tag;
	
	for(i=1; i<=(*L).length; i++)
		adr[i] = i;
	
	for(i=(*L).length; i>=2; i--)		//ʹ��������������ʾ����Ҳ�����ñ�����򷽷� 
	{
		tag = FALSE;					//tag��Ǳ��������Ƿ����Ľ���
		
		for(j=1; j<=i-1; j++)
		{
			if(LT((*L).r[adr[j+1]].key, (*L).r[adr[j]].key))
			{
				tmp = adr[j+1];
				adr[j+1] = adr[j];
				adr[j] = tmp;
				
				tag = TRUE;				//������������������˵�������Ѿ����� 
			}		
		}
		
		if(!tag)
			break;
	}
	
	Rearrange(L, adr);
}

/*�T�T�T�T�T�[
�U �㷨10.18�U 
�^�T�T�T�T�T*/
void Rearrange(SqList_sort *L, int adr[])
{
	int i, j, k;
	
	for(i=1; i<=(*L).length; i++)
	{
		if(adr[i]!=i)
		{
			j = i;
			(*L).r[0] = (*L).r[i];
			
			while(adr[j]!=i)
			{
				k = adr[j];
				(*L).r[j] = (*L).r[k];
				adr[j] = j;
				j = k;
			}
			
			(*L).r[j] = (*L).r[0];
			adr[j] = j;
		}
	}
} 

#endif
