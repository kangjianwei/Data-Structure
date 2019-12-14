#include <stdio.h>
#include <stdlib.h>													//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  									//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_31(LinkList L, LinkList s);
void InitList_2_31(LinkList *L);
Status CreatList_2_31(LinkList *L, int n, LElemType_L Data[]);
void Output_2_31(LinkList L);

int main(int argc, char *argv[])
{
	LinkList L, s;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	
	InitList_2_31(&L);
	CreatList_2_31(&L, 10, a);
	
	printf("L = ");
	Output_2_31(L);
	printf("\n\n");	
	
	s = L->next->next->next->next;
	printf("ɾ�� %d ��ǰ����...\n", s->data);
	Algo_2_31(L, s);
	printf("L = ");
	Output_2_31(L);
	printf("\n\n");	
		
	return 0;
}

/*������������������������������
����2.31��ɾ��sָ�����ǰ�� ��
������������������������������*/
/* ����������Ϊ��ͷ���ĵ�ѭ������ */
Status Algo_2_31(LinkList L, LinkList s)
{
	LinkList r, p;
	
	if(s->next==s)
		return ERROR;
	
	r = s;
	
	while(r->next->next!=s)
		r = r->next;
	
	p = r->next;
	r->next = p->next;
	if(p==L)
		L = p->next;
	
	free(p);
	
	return OK;
}

void InitList_2_31(LinkList *L)
{
	*L = NULL;
}

Status CreatList_2_31(LinkList *L, int n, LElemType_L Data[])
{
	LinkList s, r;
	int i;
	
	if(*L)									//����֮ǰ��֤����Ϊ��
		return ERROR;
	
	for(i=1; i<=n; i++)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = Data[i-1];
		if(!s)
			exit(OVERFLOW);
		
		if(i==1)
		{
			*L = s;
			s->next = *L;
			r = *L;
		}
		else
		{
			s->next = r->next;
			r->next = s;
			r = r->next;
		}
	} 	
	
	return OK;
}

void Output_2_31(LinkList L)
{
	LinkList p;
	
	if(L)
	{
		printf("%2d ", L->data);
		
		p = L->next;
		while(p!=L)
		{
			printf("%2d ", p->data);
			p = p->next;
		}	
	}
}
