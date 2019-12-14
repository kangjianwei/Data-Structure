/*************************
 *                       *
 * �ļ���: ��10 �ڲ����� *
 *                       *
 * �ļ���: HeapSort.c    *
 *                       *
 * ��  ��: 10.10��10.11  *
 *                       *
 *************************/

#ifndef HEAPSORT_C
#define HEAPSORT_C

#include "HeapSort.h" 							//**��10 �ڲ�����**//

/*�T�T�T�T�T�[
�U �㷨10.10�U 
�^�T�T�T�T�T*/
void HeapAdjust(HeapType *H, int s, int m)
{
	int j;
	RcdType rc;
	
	rc = (*H).r[s];
	
	for(j=2*s; j<=m; j*=2)						//��key�ϴ�ĺ��ӽ������ɸѡ 
	{
		if(j<m&&LT((*H).r[j].key, (*H).r[j+1].key))
			j++;								//jΪkey�ϴ�ļ�¼���±� 
		
		if(!LT(rc.key, (*H).r[j].key))
			break;								//rcӦ������λ��s�� 
		
		(*H).r[s] = (*H).r[j];
		
		s = j;
	}
	
	(*H).r[s] = rc;							//���� 
} 

/*�T�T�T�T�T�[
�U �㷨10.11�U 
�^�T�T�T�T�T*/
void HeapSort(HeapType *H)
{
	int i;
	RcdType tmp;
	
	for(i=(*H).length/2; i>0; i--)			//��H.r[1..H.length]���ɴ󶥶� 
		HeapAdjust(H, i, (*H).length);
	
	for(i=(*H).length; i>1; i--)
	{
		tmp = (*H).r[1];					//���Ѷ���¼�͵�ǰδ������������Hr[1..i]�����һ����¼���� 
		(*H).r[1] = (*H).r[i];
		(*H).r[i] = tmp;
		
		HeapAdjust(H, 1, i-1);				//��H.r[1..i-1]���µ���Ϊ�󶥶� 
	}
}

#endif
