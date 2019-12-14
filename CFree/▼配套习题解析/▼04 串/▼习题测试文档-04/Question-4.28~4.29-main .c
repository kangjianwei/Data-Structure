#include <stdio.h>
#include <stdlib.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	         //**��01 ����**//

/* ���ṹ���Ͷ��� */
typedef struct strLNode			//�����Ǹ�˫��������ѭ������ģʽ����δ��nextֵ֮ǰ���������� 
{
	char chdata;
	struct strLNode *succ;		//succָ���� 
	struct strLNode *next;		//next�������У�ָ��ǰ�� 
}strLNode;						//next��ģʽ���У�ָ��ǰ���ʧ��ʱ����һ��Ӧ�ñȽϵĽ�� 
typedef strLNode *LString;

/* ����ԭ�� */
Status Algo_4_28_1(LString T);
Status Algo_4_28_2(LString T) ;
int Algo_4_29(LString S, LString T, int pos);
Status AssignLString(LString *S, char *s);
Status PrintLString(LString S);

int main(int argc, char *argv[])
{
	int pos, i1, i2;
	LString S, T1, T2;
	char *s = "abaaabaababaabcaabaabcacabaabcaabaabcac";
	char *t = "abaabcac";
	LString p;
	AssignLString(&S, s);					//���� 
	AssignLString(&T1, t);					//ģʽ��
	AssignLString(&T2, t);
		
	printf("��  �� ��S  = ");
	PrintLString(S);
	printf("\n");
	printf("ģʽ�� ��T1 = "); 
	PrintLString(T1);
	printf("\n");
	printf("ģʽ�� ��T2 = "); 
	PrintLString(T2);
	printf("\n\n");
	
	printf("�������� 4.28 ��֤...������\n");
	Algo_4_28_1(T1);	
	Algo_4_28_2(T2);
	printf("����next��...\n");
	printf("\n");

	printf("�������� 4.29 ��֤...������\n");		
	i1 = Algo_4_29(S, T1, 1);
	printf("ģʽ�� T1 �� %d ���ַ����һ��ƥ��ɹ���λ��Ϊi1 = %d\n", 1, i1);

	i2 = Algo_4_29(S, T2, 1);
	printf("ģʽ�� T2 �� %d ���ַ����һ��ƥ��ɹ���λ��Ϊi2 = %d\n", 1, i2);
	printf("\n");
	
	return 0;
}

/*��������������������
����4.28-1����nextֵ��
��������������������*/
/* ����1����nextֵ */
Status Algo_4_28_1(LString T)
{
	strLNode *i, *j;
	
	if(!T || !T->succ)
		return ERROR;
		
	i = T->succ;				//i = 1
	j = T;						//j = 0
	
	i->next = T;				//��һ���ַ���ʧ��
	
	while(i->succ)
	{
		if(j==T || i->chdata==j->chdata)
		{
			i = i->succ;
			j = j->succ;
			i->next = j;
		}
		else
			j = j->next;
	}
	
	return OK;
} 

/*��������������������
����4.28-2����nextֵ��
��������������������*/
/* ����2����nextvalֵ�����Ľ������next���� */
Status Algo_4_28_2(LString T) 
{
	strLNode *i, *j;
	
	if(!T || !T->succ)
		return ERROR;
		
	i = T->succ;				//i = 1
	j = T;						//j = 0
	
	i->next = T;				//��һ���ַ���ʧ��
	
	while(i->succ)
	{
		if(j==T || i->chdata==j->chdata)
		{
			i = i->succ;
			j = j->succ;
			
			if(i->chdata!=j->chdata)	
				i->next = j;
			else
				i->next = j->next;
		}
		else
			j = j->next;
	}
	
	return OK;	
}

/*������������������
����4.29��KMP�㷨 ��
������������������*/
int Algo_4_29(LString S, LString T, int pos)
{
	int count, m;
	strLNode *i, *j;	//i����S��j����T 
	strLNode *p, *q;
	
	if(pos<1 || !S || !S->succ || !T || !T->succ)
		return 0;
	
	for(count=1,i=S->succ; count<pos; count++,i=i->succ)
		;					//��iָ���pos�����

	j = T->succ;
	p = i;

	while(i && j)
	{
		if(j==T || i->chdata==j->chdata)
		{
			i = i->succ; 
			j = j->succ;
		}
		else
		{
			j = j->next;
			if(j==T->succ)
				p = i;		//�������¿�ʼƥ��ʱi�����
		}
	}

	if(!j)
	{
		for(count=1,q=S->succ; q!=p; count++,q=q->succ)
			;				//�ҳ���һ�����ƥ���λ��					 
		return count;	
	}
	else
		return 0;	
}

Status AssignLString(LString *S, char *s)
{
	int i;
	LString pre, p;
	
	*S = (LString)malloc(sizeof(strLNode));
	if(!(*S))
		exit(OVERFLOW);
	(*S)->next = (*S)->succ = NULL;

	for(i=0,pre=*S; i<strlen(s); i++)
	{
		p = (LString)malloc(sizeof(strLNode));
		if(!p)
			exit(OVERFLOW);
		p->chdata = s[i];
		p->next = pre;
		p->succ = pre->succ;
		pre->succ = p;
		pre = pre->succ;
	}
	
	return OK;
}

Status PrintLString(LString S)
{
	LString p;
	
	if(!S)
		return ERROR;
	
	for(p=S->succ; p; p=p->succ)
		printf("%c", p->chdata);
	
	return OK;
}
