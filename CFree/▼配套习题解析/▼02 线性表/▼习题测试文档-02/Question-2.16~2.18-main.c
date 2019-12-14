#include <stdio.h>
#include <stdlib.h>													//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  									//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
Status Algo_2_16(LinkList *la, LinkList *lb, int i, int j, int len);
Status Algo_2_17(LinkList *L, int i, LElemType_L b);
Status Algo_2_18(LinkList *L, int i);
void InitList_2_16(LinkList *L);
	//��ʼ��L 
void Output_2_16(LinkList L);
	//���L
	 
int main(int argc, char *argv[])
{
	int i;
	LinkList la, lb;
	
	InitList_2_16(&la);
	InitList_2_16(&lb);
	
	printf("�������� 2.17 ��֤...������\n");
	for(i=1; i<=10; i++)
	{
		Algo_2_17(&la, i, 2*i-1);
		Algo_2_17(&lb, i, 2*i);	
	}

	printf("�����õ���ͷ�������Ϊ��\n");
	printf("la = ");		
	Output_2_16(la);
	printf("\n");
	printf("lb = ");
	Output_2_16(lb);
	printf("\n\n");

	printf("�������� 2.16 ��֤...������\n");		
	printf("��la�дӵ�2��������5�������뵽lb�ĵ�6�����֮ǰ...\n");
	Algo_2_16(&la, &lb, 2, 6, 5); 
	printf("la = ");		
	Output_2_16(la);
	printf("\n");
	printf("lb = ");
	Output_2_16(lb);
	printf("\n\n");	

	printf("�������� 2.18 ��֤...������\n");		
	printf("ɾ��lb��6��������5�����...\n");
	for(i=1; i<=5; i++)
		Algo_2_18(&lb, 6);
	printf("ɾ����ɺ�lb = ");
	Output_2_16(lb);
	printf("\n\n");	
		
	return 0;
}

/*����������������������������������������������������������������
����2.16��ɾ��la�е�i��������len����㲢��ӵ�lb��j�����֮ǰ ��
����������������������������������������������������������������*/
/* �����е�������ͷ��� */
Status Algo_2_16(LinkList *la, LinkList *lb, int i, int j, int len)
{
	LinkList p, q, s, prep;
	int k;
	
	if(i<0 || j<0 || len<0)
		return INFEASIBLE;
	
	p = *la;
	k = 1;
	prep = NULL;
	while(p && k<i)					//��la�в��ҵ�i����㣬��p��� 
	{
		prep = p;
		p = p->next;
		k++; 
	}
	if(!p)							//�Ҳ�����i��Ԫ�� 
		return INFEASIBLE;

	q = p;							//pָ��la���е�i����� 
	while(q && k<i+len-1)			//����la���е�i+len-1����㣬��q��� 
	{
		q = q->next;
		k++;
	}
	if(!q)							
		return INFEASIBLE;
		
	if(!prep)						//i=1����� 
		*la = q->next;
	else							//���ɾ�� 
		prep->next = q->next;

	if(j==1)
	{
		q->next = *lb;
		*lb = p;
	}
	else
	{
		s = *lb;
		k = 1;
		while(s && k<j-1)			//����lb���е�j-1��Ԫ�� 
		{
			s = s->next;
			k++;
		}
		if(!s)
			return INFEASIBLE;
			
		q->next = s->next;
		s->next = p;				//��ɲ��� 
		
		return OK;
	}

}

/*��������������������������������
����2.17����b����ΪL�ĵ�i����� ��
��������������������������������*/
/* �����е�������ͷ��� */
Status Algo_2_17(LinkList *L, int i, LElemType_L b)
{
	LinkList p, q;
	int count;
	
	p = (LinkList)malloc(sizeof(LNode));
	if(!p)
		exit(OVERFLOW);
	p->data = b;
	
	if(i>0)
	{
		if(i==1)
		{
			p->next = *L;
			*L = p;
			return OK;			
		}
		else
		{
			if(*L)
			{
				count = 1;
				q = *L;
				while(count<i-1 && q)
				{
					count++;
					q = q->next;	
				}
				
				if(q)
				{
					p->next = q->next;
					q->next = p;
					return OK;
				}
			}		
		}
	}

	return ERROR;
}

/*��������������������������
����2.18��ɾ��L�ĵ�i����㩧
��������������������������*/
/* �����е�������ͷ��� */
Status Algo_2_18(LinkList *L, int i)
{
	LinkList p, q;
	int count;
	
	if(i>0)
	{
		p = *L;
		count = 1;
		while(p && count<i-1)
		{
			count++;
			p = p->next;
		}
		
		if(p)
		{
			if(count>i-1)					//ɾ��ͷ���
			{
				*L = (*L)->next;
				free(p);
				return OK;
			}
			else
			{
				if(p->next)					//��i��������
				{
					q = p->next;
					p->next = q->next;
					free(q);
					return OK;
				} 
			}
		}
	}
	
	return ERROR;
}

void InitList_2_16(LinkList *L)
{
	*L = NULL;
}

void Output_2_16(LinkList L)
{
	LinkList p = L;
	
	while(p)
	{
		printf("%2d ", p->data);
		p = p->next;
	}
}
