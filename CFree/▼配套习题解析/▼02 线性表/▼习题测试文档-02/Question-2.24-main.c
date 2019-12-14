#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  									//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_24(LinkList La, LinkList *Lb, LinkList *Lc);
	
void PrintElem(LElemType_L e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	LinkList La, Lb, Lc;
	int i, mark;
	
	if(InitList_L(&La) && InitList_L(&Lb) && InitList_L(&Lc))	//链表L创建成功
	{
		for(i=1; i<=5; i++)			//创建链表La和Lb
		{
			ListInsert_L(La, i, 2*i-1);
			ListInsert_L(Lb, i, 2*i);		
		} 	
	}
	
	printf("创建好的链表为：\n");
	printf("La = ");
	ListTraverse_L(La, PrintElem); 	
	printf("\n");	
	printf("Lb = ");
	ListTraverse_L(Lb, PrintElem); 			//输出链表
	printf("\n\n");	

	Algo_2_24(La, &Lb, &Lc);	
	printf("归并La和Lb为Lc = ");
	ListTraverse_L(Lc, PrintElem); 	
	printf("\n\n");			
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━┓
┃题2.24：归并两个递增单链表为一个递减单链表┃
┗━━━━━━━━━━━━━━━━━━━━━*/
Status Algo_2_24(LinkList La, LinkList *Lb, LinkList *Lc)
{
	LinkList pa, pb, s;

	if(!La || !Lb || (!La->next && !(*Lb)->next))	//La或Lb有一个不存在或两个均为空表时，合并错误
		return ERROR;
	
	*Lc = La;										//利用A的头结点作C的头结点
	pa = La->next;
	pb = (*Lb)->next;
	La->next = NULL;
	
	while(pa && pb)									//采用头插法建立递减链表 
	{
		if(pa->data<=pb->data)
		{
			s = pa->next;
			pa->next = La->next;
			La->next = pa;
			pa = s;
		}
		else
		{
			s = pb->next;
			pb->next = La->next;
			La->next = pb;
			pb = s;
		}
	}
	
	while(pa)
	{
		s = pa->next;
		pa->next = La->next;
		La->next = pa;
		pa = s;
	}
	
	while(pb)
	{
		s = pb->next;
		pb->next = La->next;
		La->next = pb;
		pb = s;
	}
		
	free(*Lb);
	
	return OK;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
