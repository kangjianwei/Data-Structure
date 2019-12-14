#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  									//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_24(LinkList La, LinkList *Lb, LinkList *Lc);
	
void PrintElem(LElemType_L e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	LinkList La, Lb, Lc;
	int i, mark;
	
	if(InitList_L(&La) && InitList_L(&Lb) && InitList_L(&Lc))	//����L�����ɹ�
	{
		for(i=1; i<=5; i++)			//��������La��Lb
		{
			ListInsert_L(La, i, 2*i-1);
			ListInsert_L(Lb, i, 2*i);		
		} 	
	}
	
	printf("�����õ�����Ϊ��\n");
	printf("La = ");
	ListTraverse_L(La, PrintElem); 	
	printf("\n");	
	printf("Lb = ");
	ListTraverse_L(Lb, PrintElem); 			//�������
	printf("\n\n");	

	Algo_2_24(La, &Lb, &Lc);	
	printf("�鲢La��LbΪLc = ");
	ListTraverse_L(Lc, PrintElem); 	
	printf("\n\n");			
	
	return 0;
}

/*��������������������������������������������
����2.24���鲢��������������Ϊһ���ݼ�������
��������������������������������������������*/
Status Algo_2_24(LinkList La, LinkList *Lb, LinkList *Lc)
{
	LinkList pa, pb, s;

	if(!La || !Lb || (!La->next && !(*Lb)->next))	//La��Lb��һ�������ڻ�������Ϊ�ձ�ʱ���ϲ�����
		return ERROR;
	
	*Lc = La;										//����A��ͷ�����C��ͷ���
	pa = La->next;
	pb = (*Lb)->next;
	La->next = NULL;
	
	while(pa && pb)									//����ͷ�巨�����ݼ����� 
	{
		if(pa->data<=pb->data)
		{
			s = pa->next;
			pa->next = La->next;
			La->next = pa;
			pa = s;
		}
		else
		{
			s = pb->next;
			pb->next = La->next;
			La->next = pb;
			pb = s;
		}
	}
	
	while(pa)
	{
		s = pa->next;
		pa->next = La->next;
		La->next = pa;
		pa = s;
	}
	
	while(pb)
	{
		s = pb->next;
		pb->next = La->next;
		La->next = pb;
		pb = s;
	}
		
	free(*Lb);
	
	return OK;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
