#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  									//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_28__1(LinkList La, LinkList Lb, LinkList Lc);
Status Algo_2_28__2(LinkList La, LinkList Lb);
	
void PrintElem(LElemType_L e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	LinkList La, Lb, Lc_1, *Lc_2;
	int i;
	int a[10] = {1,2,2,3,4,5,6,7,7,8};
	int b[10] = {2,2,3,4,4,6,7,8,8,9}; 
	
	if(InitList_L(&La) && InitList_L(&Lb))	//链表创建成功
	{
		for(i=1; i<=10; i++)				//链表赋值
		{
			ListInsert_L(La, i, a[i-1]);		
			ListInsert_L(Lb, i, b[i-1]);		
		}
	}
	
	printf("La = ");
	ListTraverse_L(La, PrintElem); 				//输出
	printf("\n");
	printf("Lb = ");
	ListTraverse_L(Lb, PrintElem); 	
	printf("\n\n");		
	
	printf("题 2.28 第(1)问验证：\n");
	InitList_L(&Lc_1);
	Algo_2_28__1(La, Lb, Lc_1);
	printf("Lc = La∩Lb = ");
	ListTraverse_L(Lc_1, PrintElem); 			//输出L
	printf("\n\n");

	printf("题 2.28 第(2)问验证：\n");
	Algo_2_28__2(La, Lb);
	Lc_2 = &La;
	printf("Lc = La∩Lb = ");
	ListTraverse_L(*Lc_2, PrintElem); 			//输出L
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━┓
┃题2.28：C=A∩B┃
┗━━━━━━━*/
/* (1) */
Status Algo_2_28__1(LinkList La, LinkList Lb, LinkList Lc)
{
	LinkList pa, pb, pc, s;

	if(!La || !Lb)
		return ERROR;
	
	pa = La->next;
	pb = Lb->next;
	pc = Lc;
	
	while(pa && pb)
	{
		if(pa->data==pb->data)
		{
			if(pc==Lc || pc->data!=pa->data)
			{
				s = (LinkList)malloc(sizeof(LNode));
				if(!s)
					exit(OVERFLOW);
				s->data = pa->data;
				s->next = NULL;
				
				pc->next = s;
				pc = pc->next;
			}
			
			pa = pa->next;
			pb = pb->next;
		}
		else if(pa->data<pb->data)
			pa = pa->next;
		else
			pb = pb->next;
	}
	
	return OK;
}

/*━━━━━━━┓
┃题2.28：C=A∩B┃
┗━━━━━━━*/
/* (2) */
Status Algo_2_28__2(LinkList La, LinkList Lb)
{
	LinkList pa, pb, p;

	if(!La || !Lb)
		return ERROR;
	
	pa = La->next;
	pb = Lb->next;
	p = La;
	
	while(pa && pb)
	{
		if(pa->data==pb->data)
		{
			if(p==La || p->data!=pa->data)
			{
				p->next = pa;
				p = pa;
				pa = pa->next;
			}
			else
			{
				p->next = pa->next;
				free(pa);
				pa = p->next;
			}

			pb = pb->next;
		}
		else if(pa->data<pb->data)
		{
			p->next = pa->next;
			free(pa);
			pa = p->next;		
		}
		else
			pb = pb->next;
	}
	
	return OK;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
