#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  									//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_22(LinkList L);
	
void PrintElem(LElemType_L e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	LinkList L;
	int i;
	
	if(InitList_L(&L))					//����L�����ɹ�
	{
		for(i=1; i<=10; i++)			//����L��Ԫ��1~10 
			ListInsert_L(L, i, i);	
	}
	
	printf("L = ");
	ListTraverse_L(L, PrintElem); 		//���L
	printf("\n\n");	
	
	printf("���õ�����...\n"); 
	Algo_2_22(L);
	printf("��ʱL = ");
	ListTraverse_L(L, PrintElem); 		//���L
	printf("\n\n");
		
	return 0;
}

/*��������������������
����2.22�����������é�
��������������������*/
Status Algo_2_22(LinkList L)
{
	LinkList pre, p; 
	
	if(!L || !L->next)				//�������ڻ�����Ϊ�� 
		return ERROR;

	p = L->next;
	L->next = NULL;

	while(p)						//ͷ�巨 
	{
		pre = p;
		p = p->next;
		pre->next = L->next;
		L->next = pre;
	}

	return OK;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
