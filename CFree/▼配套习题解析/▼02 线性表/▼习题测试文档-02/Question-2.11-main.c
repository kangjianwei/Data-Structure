#include <stdio.h>
#include <stdlib.h>											//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/01 SequenceList/SequenceList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_11(SqList *va, LElemType_Sq x);
	
void PrintElem(LElemType_Sq e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	SqList L;
	int i;
	
	if(InitList_Sq(&L))					//����L�����ɹ�
	{
		for(i=1; i<=10; i++)			//����L��Ԫ��1~20 
			ListInsert_Sq(&L, i, 2*i);	
	}
	
	printf("L = ");
	ListTraverse_Sq(L, PrintElem); 			//���L
	printf("\n\n");	
	
	printf("��Ԫ�� \"5\" ���뵽����L��...\n"); 
	Algo_2_11(&L, 5);
	printf("��ʱL = ");
	ListTraverse_Sq(L, PrintElem); 			//���L
	printf("\n\n");
		
	return 0;
}

/*��������������������������������
����2.11����x���뵽��������va�� ��
��������������������������������*/
Status Algo_2_11(SqList *va, LElemType_Sq x)
{
	int i;
	LElemType_Sq *newbase;
	
	if(!(*va).length)
		return ERROR;
	
	if((*va).length==(*va).listsize)	//���洢�ռ��������迪���¿ռ� 
	{
		newbase = (LElemType_Sq*)realloc((*va).elem, ((*va).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));
		if(!newbase)
			exit(OVERFLOW);

		(*va).elem = newbase;
		(*va).listsize += LISTINCREMENT;
	}
	
	for(i=(*va).length; i>=1; i--)
	{
		if((*va).elem[i-1]>x)
			(*va).elem[i] = (*va).elem[i-1];
		else	
			break;
	}
	
	(*va).elem[i] = x;
	(*va).length++;
	
	return OK;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}
