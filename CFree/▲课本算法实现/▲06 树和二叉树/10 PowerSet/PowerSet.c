/***************************************
 *							           *
 * �ļ���: ��06 ���Ͷ�����\10 PowerSet *
 * 						               *
 * �ļ���: PowerSet.c                  *
 * 						               *
 * ��  ��: 6.14��6.15                  * 
 * 						               *
 ***************************************/

#ifndef POWERSET_C
#define POWERSET_C

#include "PowerSet.h" 							//**06 ���Ͷ�����**//

Status CreatePowerSet_PS(FILE *fp, LinkList *A)
{
	int i, j;
	PElemType e;								//����Ԫ������Ϊint 
	
	InitList_L(A);
	Scanf(fp, "%d", &j);
	printf("¼�뼯�� A ��Ԫ�ظ��� %d...\n", j);
	
	for(i=1; i<=j; i++)
	{
		Scanf(fp, "%d", &e);
		printf("¼��� %d ��Ԫ�أ�%d\n", i, e);
		ListInsert_L(*A, i, e);
	}
	
	return OK; 
}

/*�T�T�T�T�T�T�T�T�T�[
�U �㷨6.14 && 6.15 �U 
�^�T�T�T�T�T�T�T�T�T*/
void GetPowerSet_PS(int i, LinkList A, LinkList B)
{
	int k;
	LElemType_L x;
	
	if(i>ListLength_L(A))
		Output_PS(B);	
	else
	{
		GetElem_L(A, i, &x);
		k = ListLength_L(B);
		
		ListInsert_L(B, k+1, x);				//+��i��Ԫ�� 
		GetPowerSet_PS(i+1, A, B);
		
		ListDelete_L(B, k+1, &x);				//-��i��Ԫ��
		GetPowerSet_PS(i+1, A, B);
	}	 
}

void Output_PS(LinkList A)
{
	LinkList p;
	int len = ListLength_L(A);
	
	if(len)
	{
		for(p=A->next; p; p=p->next)
			printf("%d ", p->data);
	}
	else
		printf("��");

	printf("\n");
}

#endif 
