#include <stdio.h>	
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/01 SequenceList/SequenceList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_10(SqList *a, int i, int k);
	
void PrintElem(LElemType_Sq e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	SqList L;
	int i;
	
	if(InitList_Sq(&L))					//����L�����ɹ�
	{
		for(i=1; i<=20; i++)			//����L��Ԫ��1~20 
			ListInsert_Sq(&L, i, i);	
	}
	
	printf("L = ");
	ListTraverse_Sq(L, PrintElem); 		//���L
	printf("\n\n");	
	
	printf("ɾ���� 5 ��Ԫ����� 10 ��Ԫ��...\n"); 
	Algo_2_10(&L, 5, 10);
	printf("��ʱL = ");
	ListTraverse_Sq(L, PrintElem); 		//���L
	printf("\n\n");
		
	return 0;
}

/*��������������������������������������������
����2.10��ɾ��˳����дӵ�i��Ԫ�����k��Ԫ�ة�
��������������������������������������������*/
Status Algo_2_10(SqList *a, int i, int k)
{
	int j;
	
	if(i<1 || i>(*a).length || k<0 || i+k-1>(*a).length)
		return ERROR;
	
	for(j=i+k; j<=(*a).length; j++)
		(*a).elem[j-k-1] = (*a).elem[j-1];
	
	(*a).length -= k;
	
	return OK;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}
