#include <stdio.h>
#include <stdlib.h>													//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  									//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
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
	printf("删除 %d 的前驱后...\n", s->data);
	Algo_2_31(L, s);
	printf("L = ");
	Output_2_31(L);
	printf("\n\n");	
		
	return 0;
}

/*━━━━━━━━━━━━━━┓
┃题2.31：删除s指向结点的前驱 ┃
┗━━━━━━━━━━━━━━*/
/* 本题中链表为无头结点的单循环链表 */
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
	
	if(*L)									//创建之前保证链表为空
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
