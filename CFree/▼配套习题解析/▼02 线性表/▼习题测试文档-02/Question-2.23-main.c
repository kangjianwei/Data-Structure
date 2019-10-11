#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  									//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_23_1(LinkList La, LinkList *Lb, LinkList *Lc);
Status Algo_2_23_2(LinkList La, LinkList *Lb, LinkList *Lc);
	
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

	printf("验证题 2.23 的方法1输入 1 ，验证题 2.23 的方法2输入 2 ：");
	fflush(stdin);
	scanf("%d", &mark);
	printf("\n");
		
	printf("创建好的链表为：\n");
	printf("La = ");
	ListTraverse_L(La, PrintElem); 	
	printf("\n");	
	printf("Lb = ");
	ListTraverse_L(Lb, PrintElem); 			//输出链表
	printf("\n\n");	

	if(mark==1)
	{
		printf("题 2.23 方法1 验证...\n");
		Algo_2_23_1(La, &Lb, &Lc);
	}

	if(mark==2)
	{
		printf("题 2.23 方法2 验证...\n");
		Algo_2_23_2(La, &Lb, &Lc);
	}
	
	printf("归并La和Lb为Lc = ");
	ListTraverse_L(La, PrintElem); 	
	printf("\n\n");			
	
	return 0;
}

/*━━━━━━━━━━━┓
┃题2.23：归并两个单链表┃
┗━━━━━━━━━━━*/
/* 方法一：顺序链接 */
Status Algo_2_23_1(LinkList La, LinkList *Lb, LinkList *Lc)
{
	LinkList prea, pa, pb;

	if(!La || !(*Lb) || (!La->next && !(*Lb)->next))//La或Lb有一个不存在或两个均为空表时，合并错误
		return ERROR;
	
	*Lc = La;									 	//利用A的头结点作C的头结点
	prea = La;
	pa = La->next;
	pb = (*Lb)->next;

	while(pa && pb)
	{
		(*Lb)->next = pb->next;
		prea = pa;
		pa = pa->next;
		prea->next = pb;
		pb->next = pa;
		prea = pb;
		pb = (*Lb)->next;
	}
	
	if(!pa)											//Lb还有剩余
		prea->next = pb;

	free((*Lb));
	*Lb = NULL;
		
	return OK;
}

/*━━━━━━━━━━━┓
┃题2.23：归并两个单链表┃
┗━━━━━━━━━━━*/
/* 方法二：交替链接 */
Status Algo_2_23_2(LinkList La, LinkList *Lb, LinkList *Lc)
{
	LinkList cur, pa, pb;
	int i = 0;

	if(!La || !(*Lb) || (!La->next && !(*Lb)->next))//La或Lb有一个不存在或两个均为空表时，合并错误
		return ERROR;
	
	*Lc = La;			//利用A的头结点作C的头结点 
	cur = (*Lc);
	pa = La->next;
	pb = (*Lb)->next;
	
	while(pa && pb)
	{
		i++;
		if(i%2)
		{
			cur->next = pa;
			cur = pa;
			pa = pa->next;
		}
		else
		{
			cur->next = pb;
			cur = pb;
			pb = pb->next;
		}		
	}
	
	if(!pa)					//La先扫描完 
		cur->next = pb;

	if(!pb)					//Lb先扫描完，注意与方法一的区别
		cur->next = pa;

	free((*Lb));
	*Lb = NULL;
	
	return OK;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
