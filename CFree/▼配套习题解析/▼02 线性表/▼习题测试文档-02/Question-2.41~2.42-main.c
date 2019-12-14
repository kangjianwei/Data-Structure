#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��		
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//

/* ���Ͷ��� */
typedef struct						//ϡ�����ʽ��ʽ�ṹ
{
	int coef;						//ϵ�� 
	int exp;						//ָ�� 
}PolyTerm;
typedef struct PolyNode
{
	PolyTerm data;
	struct PolyNode *next;
}PolyNode;
typedef PolyNode *PolyLink;
typedef PolyLink LinkedPoly;

/* ����ԭ�� */
Status Algo_2_41(LinkedPoly P);
Status Algo_2_42(LinkedPoly *P, LinkedPoly *P_Odd, LinkedPoly *P_Even);
Status CreatPoly_L(LinkedPoly *P, int n, PolyTerm Data[]);
Status OutputPoly_L(LinkedPoly P);

int main(int argc, char *argv[])
{
	LinkedPoly P1, P2;
	PolyTerm a[7] = {-2,1,4,2,2,3,11,5,-7,6,8,9,-3,10};

	CreatPoly_L(&P1, 7, a);
	CreatPoly_L(&P2, 7, a);
	printf("Pn(x) = ");
	OutputPoly_L(P1);
	printf("\n\n");
	
	printf("�������� 2.41 ��֤...������\n");
	{
		
		Algo_2_41(P1);
		printf("�����ʽ�ĵ�����֮��...\n");
		printf("Pn(x) = ");
		OutputPoly_L(P1);
		printf("\n\n");	
	}

	
	printf("�������� 2.42 ��֤...������\n");
	{
		LinkedPoly P_odd, P_even;	
		Algo_2_42(&P2, &P_odd, &P_even);
		printf("��ָ����ż�Բ�ֶ���ʽ֮��...\n");
		printf("����� P_odd = ");
		OutputPoly_L(P_odd);
		printf("\n");
		printf("ż���� P_even = ");
		OutputPoly_L(P_even);
		printf("\n\n");	
	}
	
	return 0;
}

/*������������������
����2.41���󵼺�����
������������������*/
Status Algo_2_41(LinkedPoly P)
{
	LinkedPoly r, pre;
	
	if(!P)
		return ERROR;
	
	pre = P;
	r = P->next;
	while(r!=P)
	{
		if(r->data.exp)
		{
			r->data.coef *= r->data.exp;	//ϵ����ָ����� 
			r->data.exp--;					//ָ����һ
			pre = r;
		}				 
		else								//ɾ����ǰ��� 
		{
			pre->next = r->next;
			free(r);				
		}
		
		r = pre->next;
	}
	
	return OK;
}

/*��������������������������������
����2.42����ָ����ż�Բ�ֶ���ʽ��
��������������������������������*/
Status Algo_2_42(LinkedPoly *P, LinkedPoly *P_Odd, LinkedPoly *P_Even)
{
	LinkedPoly r, s, p, q;
	
	*P_Odd = (LinkedPoly)malloc(sizeof(PolyNode)); 
	*P_Even = (LinkedPoly)malloc(sizeof(PolyNode));
	if(!(*P_Odd) || !(*P_Even))
		exit(OVERFLOW);
	(*P_Odd)->next = *P_Odd;
	(*P_Even)->next = *P_Even;
	
	if(!(*P))
		return ERROR;
	
	p = *P_Odd;
	q = *P_Even;
	r=(*P)->next;
	
	while(r!=(*P))
	{
		s = r;
		r = r->next;

		if(s->data.exp%2)							//ָ��Ϊ���
		{
			s->next = p->next;
			p->next = s;
			p = p->next;
		}
		else
		{
			s->next = q->next;
			q->next = s;
			q = q->next;
		}
	}

	free(*P);
	*P = NULL;
}

Status CreatPoly_L(LinkedPoly *P, int n, PolyTerm Data[])	//���޵��д��� 
{
	int i;
	LinkedPoly s, r;
	
	*P = (LinkedPoly)malloc(sizeof(PolyNode));				//����ͷ��� 
	if(!(*P))
		exit(OVERFLOW);
	(*P)->next = *P;
	
	for(i=0,r=*P; i<n; i++)
	{
		s = (LinkedPoly)malloc(sizeof(PolyNode)); 
		if(!s)
			exit(OVERFLOW);		
		s->data = Data[i];
		
		s->next = r->next;
		r->next = s;
		
		r = r->next;
	}
	
	return OK;
}

Status OutputPoly_L(LinkedPoly P)
{
	int i;
	LinkedPoly r;
	
	if(!P)
		return ERROR;
	
	for(r=P->next; r!=P; r=r->next)
	{
		if(r==P->next)
			printf("%d" , r->data.coef);
		else
		{
			if(r->data.coef<0)
			{
				printf(" - ");
				printf("%d", -r->data.coef);
			}
			else
			{
				printf(" + ");
				printf("%d", r->data.coef);			
			}
		}
		
		if(r->data.exp)
		{
			printf("x");
			
			if(r->data.exp!=1)
				printf("^%d", r->data.exp);		
		}
	}
	
	return OK;
}
