#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  										//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/08 DualCycleLinkedList/DualCycleLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_37(DuLinkList L);
	
void PrintElem(LElemType_DC e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	DuLinkList L;
	int i;
	
	InitList_DuL(&L);
	for(i=1; i<=10; i++)
		ListInsert_DuL(L, i, i);
	ListTraverse_DuL(L, PrintElem);
	printf("\n\n");
	
	Algo_2_37(L);
	printf("重新排序后 L = ");
	ListTraverse_DuL(L, PrintElem);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━┓
┃题2.37：按奇偶次序重排链表各元素位序┃
┗━━━━━━━━━━━━━━━━━━*/
Status Algo_2_37(DuLinkList L)
{
	DuLinkList head, tail, p;
	
	if(!L)
		return ERROR;
	
	head = L->next;				//向右推进 
	tail = L->prior;				//固定不动 
	
	while(head!=tail)
	{
		if(head->next!=tail)
		{
			p = head->next;			//摘下此结点
			 
			p->next->prior= head;
			head->next = p->next;
			
			p->next = tail->next;
			p->prior = tail;
			tail->next->prior= p;
			tail->next = p;
			
			head = head->next;
		}
		else
			break;
	}
	
	return OK;	
}

void PrintElem(LElemType_DC e)
{
	printf("%d ", e);
}
