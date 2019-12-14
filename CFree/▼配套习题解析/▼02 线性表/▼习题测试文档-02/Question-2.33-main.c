#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include <ctype.h>										//�ṩisalpha��isdigitԭ�� 
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//

/* ���Ͷ��� */
typedef char LElemType_L;
typedef struct LNode					//˫ѭ������ṹ��
{
	LElemType_L data;
	struct LNode* next;
}LNode;
typedef LNode* LinkList;				//ָ��ṹ��ָ��

/* ����ԭ�� */
Status Algo_2_33(LinkList L, LinkList L_char, LinkList L_num, LinkList L_other);
Status InitList_2_33(LinkList *L);
	//�������ʼ�� 
Status CreatList_2_33(LinkList L, int n, LElemType_L Data[]);
Status InitList_CL_2_33(LinkList *L);
	//��ѭ�������ʼ��
void Output_2_33(LinkList L);
	//���������
void Output_CL_2_33(LinkList L);
	//�����ѭ������

int main(int argc, char *argv[])
{
	LinkList L, L_char, L_num, L_other;
	LElemType_L *a = "2a3@A5e$T*";
	
	InitList_2_33(&L);
	CreatList_2_33(L, 10, a);
	
	printf("L = ");
	Output_2_33(L);
	printf("\n\n");	
	
	printf("��ֵ�����֮��...\n");
	InitList_CL_2_33(&L_char);
	InitList_CL_2_33(&L_num);
	InitList_CL_2_33(&L_other);
	Algo_2_33(L, L_char, L_num, L_other);
	printf("L_char = ");
	Output_CL_2_33(L_char);
	printf("\n");
	printf("L_num = ");
	Output_CL_2_33(L_num);
	printf("\n");
	printf("L_other = ");
	Output_CL_2_33(L_other);
	printf("\n\n");
			
	return 0;
}

/*������������������������������������������������������������
����2.33�����ַ����ͣ���ĸ�����֡�������������Ա�Ϊѭ������
������������������������������������������������������������*/
Status Algo_2_33(LinkList L, LinkList L_char, LinkList L_num, LinkList L_other)
{
	LinkList r, rc, rn, ro, s;
	
	if(!L)
		return ERROR;
		
	r = L->next;
	rc = L_char;
	rn = L_num;
	ro = L_other;
	
	while(r)
	{
		s = (LinkList)malloc(sizeof(LNode));
		if(!s)
			exit(OVERFLOW);
		s->data = r->data;
		
		if(isalpha(r->data))					//���ֵΪ�ַ� 
		{
			s->next = rc->next;
			rc->next = s;
			rc = rc->next;
		}
		else if(isdigit(r->data))				//���ֵΪ����
		{
			s->next = rn->next;
			rn->next = s;
			rn = rn->next;		
		}
		else									//���� 
		{
			s->next = ro->next;
			ro->next = s;
			ro = ro->next;		
		}
		
		r = r->next;
	}
	
	return OK;
}

Status InitList_2_33(LinkList *L)				//�������ʼ�� 
{
	*L = (LinkList)malloc(sizeof(LNode));		
	if(!(*L))
		exit(OVERFLOW);
	
	(*L)->next = NULL;
	
	return OK;
}

Status CreatList_2_33(LinkList L, int n, LElemType_L Data[])
{
	LinkList s, r;
	int i;
	
	if(!L || L->next)
		return ERROR;
	
	for(i=1,r=L; i<=n; i++)
	{
		s = (LinkList)malloc(sizeof(LNode));
		if(!s)
			exit(OVERFLOW);
		s->data = Data[i-1];
		
		s->next = r->next;
		r->next = s;
		r = r->next;
	} 	
	
	return OK;
}

Status InitList_CL_2_33(LinkList *L)			//��ѭ�������ʼ�� 
{
	*L = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	
	(*L)->next = *L;
	
	return OK;
}

void Output_2_33(LinkList L)					//��������� 
{
	LinkList p;
	
	if(L)
	{	
		p = L->next;
		while(p)
		{
			printf("%2c ", p->data);
			p = p->next;
		}	
	}
}

void Output_CL_2_33(LinkList L)					//�����ѭ������ 
{
	LinkList p;
	
	if(L)
	{	
		p = L->next;
		while(p!=L)
		{
			printf("%2c ", p->data);
			p = p->next;
		}	
	}
}
