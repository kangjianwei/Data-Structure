#include <stdio.h>
#include <stdlib.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"
#include "../../../���α��㷨ʵ��/��01 ����/Scanf.c"

/* ���Ͷ��� */
typedef struct LNode
{
	int elem;
	struct LNode* next;
}LNode;
typedef struct 
{ 
	LNode* h;		//h�̶�ָ��ѭ�������е���С�ؼ��� 
	LNode* t;		//t�������и�����ÿ�β��ҽ�����ָ���ϴβ�����ĵط� 
}CLinkLIst;

/* ����ԭ�� */
LNode* Algo_9_29(CLinkLIst *CL, int key);
void CreateList_9_29(FILE* fp, CLinkLIst *CL);
void PrintList_9_29(CLinkLIst CL);

int main(int argc, char *argv[])
{
	CLinkLIst CL;
	FILE *fp;
	LNode *p;
	int key = 59;
	
	fp = fopen("Data/Algo_9_29.txt","r");
	CreateList_9_29(fp, &CL);
	PrintList_9_29(CL);
	printf("\n");

	p = Algo_9_29(&CL, key);
	if(p)
		printf("�ؼ��� %d ���ҳɹ���\n", p->elem);
	else
		printf("����ʧ�ܣ���\n");
	printf("\n");
	
	return 0;
}

LNode* Algo_9_29(CLinkLIst *CL, int key)
{
	LNode *p;
	
	while(1)
	{
		if(key<CL->t->elem)
		{
			for(p=CL->h; p->elem<key&&p->next!=CL->t; p=p->next)
				;						//��h������ 
			
			CL->t = p;
			
			if(p->elem!=key)
				return NULL;
			else
				return p;
		}	
		else if(key>CL->t->elem)		//��t������ 
		{
			if(CL->t->next!=CL->h)
				CL->t = CL->t->next;
			else
				return NULL;
		}
		else
			return CL->t;
	}
	
	return p;
}

void CreateList_9_29(FILE* fp, CLinkLIst *CL)
{
	int tmp;
	LNode *p;
	
	CL->h = CL->t = NULL;
	
	while(Scanf(fp, "%d", &tmp)==1)
	{
		p = (LNode*)malloc(sizeof(LNode));
		p->elem = tmp;
		
		if(!CL->h)
			CL->h = CL->t = p;
		else
		{
			CL->t->next = p;
			CL->t = CL->t->next;
		}
	}
	
	CL->t->next = CL->h;			//��β���� 
	CL->t = CL->t->next;			//t��ʼʱָ����ͷ 
}

void PrintList_9_29(CLinkLIst CL)
{
	LNode *p;
	int count = 0;
	
	p = CL.h;
	if(p)
		printf("%2d ", p->elem);
	count++;
	
	while(p->next!=CL.h)
	{
		p = p->next;
		printf("%2d ", p->elem);	
		count++;
		
		if(count%10==0)
			printf("\n");
	}
}
