#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  									//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_23_1(LinkList La, LinkList *Lb, LinkList *Lc);
Status Algo_2_23_2(LinkList La, LinkList *Lb, LinkList *Lc);
	
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

	printf("��֤�� 2.23 �ķ���1���� 1 ����֤�� 2.23 �ķ���2���� 2 ��");
	fflush(stdin);
	scanf("%d", &mark);
	printf("\n");
		
	printf("�����õ�����Ϊ��\n");
	printf("La = ");
	ListTraverse_L(La, PrintElem); 	
	printf("\n");	
	printf("Lb = ");
	ListTraverse_L(Lb, PrintElem); 			//�������
	printf("\n\n");	

	if(mark==1)
	{
		printf("�� 2.23 ����1 ��֤...\n");
		Algo_2_23_1(La, &Lb, &Lc);
	}

	if(mark==2)
	{
		printf("�� 2.23 ����2 ��֤...\n");
		Algo_2_23_2(La, &Lb, &Lc);
	}
	
	printf("�鲢La��LbΪLc = ");
	ListTraverse_L(La, PrintElem); 	
	printf("\n\n");			
	
	return 0;
}

/*������������������������
����2.23���鲢����������
������������������������*/
/* ����һ��˳������ */
Status Algo_2_23_1(LinkList La, LinkList *Lb, LinkList *Lc)
{
	LinkList prea, pa, pb;

	if(!La || !(*Lb) || (!La->next && !(*Lb)->next))//La��Lb��һ�������ڻ�������Ϊ�ձ�ʱ���ϲ�����
		return ERROR;
	
	*Lc = La;									 	//����A��ͷ�����C��ͷ���
	prea = La;
	pa = La->next;
	pb = (*Lb)->next;

	while(pa && pb)
	{
		(*Lb)->next = pb->next;
		prea = pa;
		pa = pa->next;
		prea->next = pb;
		pb->next = pa;
		prea = pb;
		pb = (*Lb)->next;
	}
	
	if(!pa)											//Lb����ʣ��
		prea->next = pb;

	free((*Lb));
	*Lb = NULL;
		
	return OK;
}

/*������������������������
����2.23���鲢����������
������������������������*/
/* ���������������� */
Status Algo_2_23_2(LinkList La, LinkList *Lb, LinkList *Lc)
{
	LinkList cur, pa, pb;
	int i = 0;

	if(!La || !(*Lb) || (!La->next && !(*Lb)->next))//La��Lb��һ�������ڻ�������Ϊ�ձ�ʱ���ϲ�����
		return ERROR;
	
	*Lc = La;			//����A��ͷ�����C��ͷ��� 
	cur = (*Lc);
	pa = La->next;
	pb = (*Lb)->next;
	
	while(pa && pb)
	{
		i++;
		if(i%2)
		{
			cur->next = pa;
			cur = pa;
			pa = pa->next;
		}
		else
		{
			cur->next = pb;
			cur = pb;
			pb = pb->next;
		}		
	}
	
	if(!pa)					//La��ɨ���� 
		cur->next = pb;

	if(!pb)					//Lb��ɨ���꣬ע���뷽��һ������
		cur->next = pa;

	free((*Lb));
	*Lb = NULL;
	
	return OK;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
