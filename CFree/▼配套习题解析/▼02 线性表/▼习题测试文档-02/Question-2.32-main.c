#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//

/* 类型定义 */
typedef int LElemType_L;
typedef struct LNode					//双循环链表结构体
{
	LElemType_L data;
	struct LNode* next;
	struct LNode* pre;
}LNode;
typedef LNode* LinkList;				//指向结构的指针 

/* 函数原型 */
Status Algo_2_32(LinkList L);
Status InitList_2_32(LinkList *L);
Status CreatList_2_32(LinkList L, int n, LElemType_L Data[]);
void Output_2_32(LinkList L);
void OutputReverse_2_32(LinkList L);

int main(int argc, char *argv[])
{
	LinkList L;
	LElemType_L a[10] = {1,2,3,4,5,6,7,8,9,10};
	
	InitList_2_32(&L);
	CreatList_2_32(L, 10, a);
	
	printf("L = ");
	Output_2_32(L);
	printf("\n\n");		

	printf("为链表设置前驱后逆序输出链表...\n");
	Algo_2_32(L);
	printf("L = ");
	OutputReverse_2_32(L);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━┓
┃题2.32：为单循环链表各结点设置前驱┃
┗━━━━━━━━━━━━━━━━━*/
Status Algo_2_32(LinkList L)
{
	LinkList r;
	
	if(!L)
		return ERROR;
	
	for(r=L; r->next!=L; r=r->next)
		r->next->pre = r;
	
	L->pre = r;
	
	return OK;
}

Status InitList_2_32(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	
	(*L)->pre = NULL; 
	(*L)->next = *L;
	
	return OK;
}

Status CreatList_2_32(LinkList L, int n, LElemType_L Data[])
{
	LinkList s, r;
	int i;
	
	if(!L || L->next!=L)
		return ERROR;
	
	for(i=1,r=L; i<=n; i++)
	{
		s = (LinkList)malloc(sizeof(LNode));
		if(!s)
			exit(OVERFLOW);
		s->data = Data[i-1];
		s->pre = NULL;
		
		s->next = r->next;
		r->next = s;
		r = r->next;
	} 	
	
	return OK;
}

void Output_2_32(LinkList L)
{
	LinkList p;
	
	if(L)
	{	
		p = L->next;
		while(p!=L)
		{
			printf("%2d ", p->data);
			p = p->next;
		}	
	}
}

void OutputReverse_2_32(LinkList L)
{
	LinkList p;
	
	if(L)
	{	
		p = L->pre;
		while(p!=L)
		{
			printf("%2d ", p->data);
			p = p->pre;
		}	
	}
}
