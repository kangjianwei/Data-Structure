#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  									//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_22(LinkList L);
	
void PrintElem(LElemType_L e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	LinkList L;
	int i;
	
	if(InitList_L(&L))					//链表L创建成功
	{
		for(i=1; i<=10; i++)			//链表L中元素1~10 
			ListInsert_L(L, i, i);	
	}
	
	printf("L = ");
	ListTraverse_L(L, PrintElem); 		//输出L
	printf("\n\n");	
	
	printf("逆置单链表...\n"); 
	Algo_2_22(L);
	printf("此时L = ");
	ListTraverse_L(L, PrintElem); 		//输出L
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━┓
┃题2.22：单链表逆置┃
┗━━━━━━━━━*/
Status Algo_2_22(LinkList L)
{
	LinkList pre, p; 
	
	if(!L || !L->next)				//链表不存在或链表为空 
		return ERROR;

	p = L->next;
	L->next = NULL;

	while(p)						//头插法 
	{
		pre = p;
		p = p->next;
		pre->next = L->next;
		L->next = pre;
	}

	return OK;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
