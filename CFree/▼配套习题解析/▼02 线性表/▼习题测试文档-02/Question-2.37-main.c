#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  										//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/08 DualCycleLinkedList/DualCycleLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_37(DuLinkList L);
	
void PrintElem(LElemType_DC e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	DuLinkList L;
	int i;
	
	InitList_DuL(&L);
	for(i=1; i<=10; i++)
		ListInsert_DuL(L, i, i);
	ListTraverse_DuL(L, PrintElem);
	printf("\n\n");
	
	Algo_2_37(L);
	printf("��������� L = ");
	ListTraverse_DuL(L, PrintElem);
	printf("\n\n");
		
	return 0;
}

/*��������������������������������������
����2.37������ż�������������Ԫ��λ��
��������������������������������������*/
Status Algo_2_37(DuLinkList L)
{
	DuLinkList head, tail, p;
	
	if(!L)
		return ERROR;
	
	head = L->next;				//�����ƽ� 
	tail = L->prior;				//�̶����� 
	
	while(head!=tail)
	{
		if(head->next!=tail)
		{
			p = head->next;			//ժ�´˽��
			 
			p->next->prior= head;
			head->next = p->next;
			
			p->next = tail->next;
			p->prior = tail;
			tail->next->prior= p;
			tail->next = p;
			
			head = head->next;
		}
		else
			break;
	}
	
	return OK;	
}

void PrintElem(LElemType_DC e)
{
	printf("%d ", e);
}
