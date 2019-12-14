#include <stdio.h>	
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/01 SequenceList/SequenceList.c"	//**��02 ���Ա�**//#include <stdio.h>	

/* ����ԭ�� */
Status Algo_2_21(SqList L);
	
void PrintElem(LElemType_Sq e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	SqList L;
	int i;
	
	if(InitList_Sq(&L))					//����L�����ɹ�
	{
		for(i=1; i<=10; i++)			//����L��Ԫ��1~10 
			ListInsert_Sq(&L, i, i);	
	}
	
	printf("L = ");
	ListTraverse_Sq(L, PrintElem); 			//���L
	printf("\n\n");	
	
	printf("����˳���...\n"); 
	Algo_2_21(L);
	printf("��ʱL = ");
	ListTraverse_Sq(L, PrintElem); 			//���L
	printf("\n\n");
		
	return 0;
}

/*��������������������
����2.21��˳������é�
��������������������*/
Status Algo_2_21(SqList L)
{
	int i;
	int j;
	LElemType_Sq tmp;
	
	if(L.length==0)
		return ERROR;
	
	for(j=1,i=(L.length)/2; j<=i; j++)
	{
		tmp = L.elem[j-1];
		L.elem[j-1] = L.elem[L.length-j];
		L.elem[L.length-j] = tmp;
	}
	
	return OK;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}
