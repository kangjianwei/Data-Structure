#include <stdio.h>
#include <stdlib.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"

/* 类型定义 */
typedef struct LNode
{
	int elem;
	struct LNode* next;
}LNode;
typedef struct 
{ 
	LNode* h;		//h固定指向循环链表中的最小关键字 
	LNode* t;		//t在链表中浮动，每次查找结束后指向上次查找完的地方 
}CLinkLIst;

/* 函数原型 */
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
		printf("关键字 %d 查找成功！\n", p->elem);
	else
		printf("查找失败！！\n");
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
				;						//从h往后找 
			
			CL->t = p;
			
			if(p->elem!=key)
				return NULL;
			else
				return p;
		}	
		else if(key>CL->t->elem)		//从t往后找 
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
	
	CL->t->next = CL->h;			//首尾相连 
	CL->t = CL->t->next;			//t初始时指向链头 
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
