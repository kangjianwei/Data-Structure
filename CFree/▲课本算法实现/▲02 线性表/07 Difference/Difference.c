/*************************************
 *					                 *
 * �ļ���: ��02 ���Ա�\07 Difference *
 * 					    			 *
 * �ļ���: Difference.c 			 *
 * 				        			 *
 * ��  ��: 2.17         			 * 
 *                      			 *
 *************************************/

#ifndef DIFFERENCE_C
#define DIFFERENCE_C

#include "Difference.h"						//**��02 ���Ա�**//

/*�T�T�T�T�T�[
�U �㷨2.17 �U 
�^�T�T�T�T�T*/
void difference(SLinkList *S, LElemType_S A[], int len_A, LElemType_S B[], int len_B)
{
	int i, j;
	int r, p, k;
	LElemType_S b;
	
	InitSpace_SL();
	*S = Malloc_SL();						//ͷ��� 
	r = *S;									//rָ��S�ĵ�ǰ����㣨βָ�룩 
	SPACE[r].cur = 0;
	
	for(j=0; j<len_A; j++)					//��������A������ 
	{
		i = Malloc_SL();					//������ 
		SPACE[i].data = A[j];				//¼��A��Ԫ��ֵ	 
		SPACE[r].cur = i;					//���뵽��β 
		r = i;
	}
	SPACE[r].cur =0;						//β���ָ��Ϊ��
	
	for(j=0; j<len_B; j++)					//¼��B��Ԫ��ֵ
	{
		b = B[j];		
		p = *S;								//pָ�򼯺�A��ͷ���
		k = SPACE[*S].cur;					//kָ�򼯺�A�ĵ�һ�����
		while(k && SPACE[k].data!=b)
		{									//�ڼ���A�в���b 
			p = k;
			k = SPACE[k].cur; 
		}
		
		if(!k)								//A���Ҳ���b����b����A
		{									//����Ԫ�ؽ�����r����β��
			i = Malloc_SL();
			SPACE[i].data = b;
			SPACE[i].cur = SPACE[r].cur;	 
			SPACE[r].cur = i;				//rʼ��ָ������A�в����Ԫ��	
		} 
		else								//A�д���b����b��A��ɾ�� 
		{
			SPACE[p].cur = SPACE[k].cur;
			Free_SL(k);
			if(k==r)
				r = p;
		}				
	} 	
}

#endif
