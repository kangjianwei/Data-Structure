#include <stdio.h>
#include <stdlib.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"

/* 类型定义 */
typedef struct LNode
{
	int elem;
	struct LNode* pre;
	struct LNode* next;
}LNode;
typedef LNode* DCLinkLIst;

/*全局变量*/
DCLinkLIst sp;

/* 函数原型 */
DCLinkLIst Algo_9_30(DCLinkLIst DL, int key);
void CreateList_9_30(FILE* fp, DCLinkLIst *DL);
void PrintList_9_30(DCLinkLIst DL);

int main(int argc, char *argv[])
{
	DCLinkLIst DL;
	FILE *fp;
	LNode *p;
	int key = 59;
	
	fp = fopen("Data/Algo_9_30.txt","r");
	CreateList_9_30(fp, &DL);
	PrintList_9_30(DL);
	printf("\n");

	p = Algo_9_30(DL, key);
	if(p)
		printf("关键字 %d 查找成功！\n", p->elem);
	else
		printf("查找失败！！\n");
	printf("\n");
	
	return 0;
}

DCLinkLIst Algo_9_30(DCLinkLIst DL, int key)
{
	while(1)
	{
		if(sp->elem==key)
			return sp;
		else if(sp->elem<key)
		{
			if(sp->next!=DL && sp->next->elem<=key)
				sp = sp->next;
			else
				return NULL;
		}
		else
		{
			if(sp->pre!=DL && sp->pre->elem>=key)
				sp = sp->pre;
			else
				return NULL;
		}	
	}
}

void CreateList_9_30(FILE* fp, DCLinkLIst *DL)
{
	int tmp;
	DCLinkLIst p;
	
	*DL = NULL;
	
	while(Scanf(fp, "%d", &tmp)==1)
	{
		p = (DCLinkLIst)malloc(sizeof(LNode));
		p->elem = tmp;
		
		if(*DL==NULL)
			*DL = sp = p;
		else
		{
			sp->next = p;
			sp->next->pre = sp;
			sp = sp->next;
		}
	}
	
	sp->next = *DL;
	sp->next->pre = sp;
	sp = sp->next;	
}

void PrintList_9_30(DCLinkLIst DL)
{
	LNode *p;
	int count = 0;
	
	p = DL;
	if(p)
		printf("%2d ", p->elem);
	count++;
	
	while(p->next!=DL)
	{
		p = p->next;
		printf("%2d ", p->elem);	
		count++;
		
		if(count%10==0)
			printf("\n");
	}
}
