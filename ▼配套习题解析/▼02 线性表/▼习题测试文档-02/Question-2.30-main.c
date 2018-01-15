#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  									//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_30(LinkList La, LinkList Lb, LinkList Lc);
	
void PrintElem(LElemType_L e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	LinkList La, Lb, Lc;
	int i;	
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int b[] = {1,2,2,3,5,7,8,8,9,11};
	int c[] = {2,3,3,4,5,6,7,8,11,12};
	
	if(InitList_L(&La) && InitList_L(&Lb) && InitList_L(&Lc)) //链表L创建成功
	{
		for(i=1; i<=10; i++)
		{
			ListInsert_L(La, i, a[i-1]);
			ListInsert_L(Lb, i, b[i-1]);
			ListInsert_L(Lc, i, c[i-1]);		
		} 	
	}
	
	printf("La = ");
	ListTraverse_L(La, PrintElem);
	printf("\n");	
	printf("Lb = ");
	ListTraverse_L(Lb, PrintElem);
	printf("\n");	
	printf("Lc = ");
	ListTraverse_L(Lc, PrintElem);
	printf("\n\n");	
		
	Algo_2_30(La, Lb, Lc);
	printf("La = La-Lb∩Lc = ");
	ListTraverse_L(La, PrintElem); 			//输出L
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━┓
┃题2.30：A=A-B∩C┃
┗━━━━━━━━*/
Status Algo_2_30(LinkList La, LinkList Lb, LinkList Lc)
{
	LinkList pa, pb, pc, pre;
	
	if(!La || !Lb || !Lc)
		return ERROR;
		
	pa = La->next;
	pb = Lb->next;
	pc = Lc->next;
	pre = La;
	
	while(pa && pb && pc)
	{
		if(pb->data<pc->data)
			pb = pb->next;
		else if(pb->data>pc->data)
			pc = pc->next;
		else
		{
			while(pa && pa->data<pb->data)
			{
				pre = pa;
				pa = pa->next;
			}
			
			while(pa && pa->data==pb->data)
			{
				pre->next = pa->next;
				free(pa);
				pa = pre->next;
			}
			
			if(pa)
			{
				pb = pb->next;
				pc = pc->next;
			}
		}	
	}	
	
	return OK;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
