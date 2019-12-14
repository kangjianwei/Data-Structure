/*************************
 *                       *
 * �ļ���: ��10 �ڲ����� *
 *                       *
 * �ļ���: TInsertSort.c *
 *                       *
 * ��  ��: 10.3          *
 *                       *
 *************************/

#ifndef TINSERTSORT_C
#define TINSERTSORT_C

#include "TInsertSort.h" 	//**��10 �ڲ�����**//

void TInsertSort(SLinkList_sort *L)
{
	int i, j, k;
	
	for(i=1; i<=(*L).length; i++)		//��ָ��������� 
	{
		for(k=0,j=(*L).r[k].next; j&&LT((*L).r[j].rc.key, (*L).r[i].rc.key); k=j,j=(*L).r[k].next)
			;
					
		(*L).r[i].next = j;
		(*L).r[k].next = i;
	}
	
	Arrange(L);							//�Լ�¼�������� 
}

/*�T�T�T�T�[
�U�㷨10.3�U 
�^�T�T�T�T*/
void Arrange(SLinkList_sort *L)
{
	int p, q, i;
	SLNode tmp;
	
	p = (*L).r[0].next;					//pֻ�ǵ�һ����¼�ĵ�ǰλ��
	
	for(i=1; i<=(*L).length; i++)		//L.r[1..i-1]�м�¼�Ѱ��ؼ�����������		
	{									//��i����¼��L�еĵ�ǰλ��Ӧ��С��i 
		while(p<i)						//�ҵ���i����¼������pָʾ����L�е�ǰλ�� 
			p = (*L).r[p].next;
		
		q = (*L).r[p].next;				//qָʾ��δ�����ı�β 
		
		if(p!=i)
		{
			tmp = (*L).r[p];			//������¼��ʹ��i����¼��λ 
			(*L).r[p] = (*L).r[i];
			(*L).r[i] = tmp;
			
			(*L).r[i].next = p;			//ָ�����ߵļ�¼��ʹ���Ժ����whileѭ���һ� 
		}
		
		p = q;							//pָʾ��δ�����ı�β��Ϊ�ҵ�i+1����¼��׼�� 
	}
}

#endif
