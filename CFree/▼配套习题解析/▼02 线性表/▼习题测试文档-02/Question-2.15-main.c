#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  									//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_15(LinkList ha, LinkList hb, LinkList *hc);
	
void PrintElem(LElemType_L e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	LinkList ha, hb, hc;
	int i;
	
	if(InitList_L(&ha) && InitList_L(&hb) && InitList_L(&hc))	//链表创建成功
	{
		for(i=1; i<=5; i++)					//链表赋值
			ListInsert_L(ha, i, i);		
		for(i=1; i<=7; i++)					//链表赋值
			ListInsert_L(hb, i, 2*i);		
	}
	
	printf("ha = ");
	ListTraverse_L(ha, PrintElem); 				//输出
	printf("\n");
	printf("hb = ");
	ListTraverse_L(hb, PrintElem); 	
	printf("\n\n");	
	
	Algo_2_15(ha, hb, &hc);
	printf("连接ha和hb之后的链表为：\nhc = "); 
	ListTraverse_L(hc, PrintElem); 	
	printf("\n\n");	
		
	return 0;
}

/*━━━━━━━━━┓
┃题2.15：连接ha和hb┃
┗━━━━━━━━━*/
Status Algo_2_15(LinkList ha, LinkList hb, LinkList *hc)
{
	LinkList pa, pb;					//pa、pb分别指向ha、hb头结点 

	if(ha && hb)
	{
		pa = ha;
		pb = hb;
		
		while(pa->next && pb->next)
		{
			pa = pa->next;
			pb = pb->next;
		}
		
		if(!pa->next)
		{
			*hc = ha;
			pa->next = hb->next;		
		}
		
		if(!pb->next)
		{
			*hc = hb;
			pb->next = ha->next;
		}
		
		return OK;
	}
	
	return ERROR;	
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
