#include <stdio.h>
#include <stdlib.h>													//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  									//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_19_1(LinkList L, int mink, int maxk); 
Status Algo_2_19_2(LinkList L, int mink, int maxk);
Status Algo_2_20(LinkList L);
	
void PrintElem(LElemType_L e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	LinkList L;
	int mink, maxk_1, maxk_2, i;
	int a[] = {1, 2, 2, 3, 4, 4, 5, 6, 7, 7};
	
	mink = 2;
	maxk_1 = 4;
	maxk_2 = 6;
	
	InitList_L(&L);
	
	for(i=0; i<10; i++)
		ListInsert_L(L, i+1, a[i]);
	
	printf("原链表L = ");
	ListTraverse_L(L, PrintElem);
	printf("\n\n");
	
	printf("███题 2.19 验证...███\n");
	printf("删除链表中大于 %d 且小于 %d 的元素之后...\n", mink, maxk_1);
	Algo_2_19_1(L, mink, maxk_1);	
	printf("L = ");
	ListTraverse_L(L, PrintElem);
	printf("\n");

	printf("删除链表中大于 %d 且小于 %d 的元素之后...\n", mink, maxk_2);
	Algo_2_19_2(L, mink, maxk_2);	
	printf("L = ");
	ListTraverse_L(L, PrintElem);
	printf("\n\n");
	
	printf("███题 2.20 验证...███\n");
	printf("去掉链表中多余的重复元素...\n");
	Algo_2_20(L);	
	printf("L = ");
	ListTraverse_L(L, PrintElem);
	printf("\n\n");	
	
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题2.19：删除递增线性表中元素大于mink小于maxk之间的结点┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
/* 方法1 */
Status Algo_2_19_1(LinkList L, int mink, int maxk)
{
	LinkList p, pre, s;

	if(!L || !L->next)			//L不存在或为空表时，无法删除 
		return ERROR;

	if(mink>=maxk)				//阙值设置错误 
		return ERROR;
			
	pre = L;
	p = pre->next;				//p指向首结点 

	while(p && p->data<maxk) 	//上限 
	{
		if(p->data<=mink) 		//下限 
		{
			pre = p;
			p = p->next;
		}
		else					//删掉满足条件的结点 
		{
			s = p;
			pre->next = p->next;
			p = p->next;
			free(s);
		}
	}
	
	return OK;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题2.19：删除递增线性表中元素大于mink小于maxk之间的结点┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
/* 方法2 */
Status Algo_2_19_2(LinkList L, int mink, int maxk)
{
	LinkList p, pre, s;

	if(!L || !L->next)				//L不存在或为空表时，无法删除 
		return ERROR;

	if(mink>=maxk)					//阙值设置错误 
		return ERROR;

	pre = L;
	p = pre->next;					//p指向首结点 


	while(p && p->data<=mink)		//下限
	{
		pre = p;
		p = p->next;
	}

	if(p)
	{
		while(p && p->data<maxk)	//上限
		{
			s = p;
			pre->next = p->next;
			p = p->next;
			free(s);
		}
		return OK;
	}
}

/*━━━━━━━━━━━━━━━━┓
┃题2.20：删除表中值相同的多余结点┃
┗━━━━━━━━━━━━━━━━*/
Status Algo_2_20(LinkList L)
{
	LinkList p, pre, s;
		
	if(!L || !L->next)				//L不存在或为空表时，无法删除 
		return ERROR;

	pre = L->next;
	p = pre->next;					//p指向首结点
	
	while(p)
	{
		if(pre->data==p->data)
		{
			s = p;
			pre->next = p->next;
			p = p->next;
			free(s);
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}	
	
	return OK;
} 

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
