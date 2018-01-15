#include <stdio.h>
#include <stdlib.h>													//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  									//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
Status Algo_2_16(LinkList *la, LinkList *lb, int i, int j, int len);
Status Algo_2_17(LinkList *L, int i, LElemType_L b);
Status Algo_2_18(LinkList *L, int i);
void InitList_2_16(LinkList *L);
	//初始化L 
void Output_2_16(LinkList L);
	//输出L
	 
int main(int argc, char *argv[])
{
	int i;
	LinkList la, lb;
	
	InitList_2_16(&la);
	InitList_2_16(&lb);
	
	printf("███题 2.17 验证...███\n");
	for(i=1; i<=10; i++)
	{
		Algo_2_17(&la, i, 2*i-1);
		Algo_2_17(&lb, i, 2*i);	
	}

	printf("创建好的无头结点链表为：\n");
	printf("la = ");		
	Output_2_16(la);
	printf("\n");
	printf("lb = ");
	Output_2_16(lb);
	printf("\n\n");

	printf("███题 2.16 验证...███\n");		
	printf("将la中从第2个结点起的5个结点插入到lb的第6个结点之前...\n");
	Algo_2_16(&la, &lb, 2, 6, 5); 
	printf("la = ");		
	Output_2_16(la);
	printf("\n");
	printf("lb = ");
	Output_2_16(lb);
	printf("\n\n");	

	printf("███题 2.18 验证...███\n");		
	printf("删除lb第6个结点起的5个结点...\n");
	for(i=1; i<=5; i++)
		Algo_2_18(&lb, 6);
	printf("删除完成后：lb = ");
	Output_2_16(lb);
	printf("\n\n");	
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题2.16：删除la中第i个结点起的len个结点并添加到lb第j个结点之前 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
/* 本题中的链表无头结点 */
Status Algo_2_16(LinkList *la, LinkList *lb, int i, int j, int len)
{
	LinkList p, q, s, prep;
	int k;
	
	if(i<0 || j<0 || len<0)
		return INFEASIBLE;
	
	p = *la;
	k = 1;
	prep = NULL;
	while(p && k<i)					//在la中查找第i个结点，用p标记 
	{
		prep = p;
		p = p->next;
		k++; 
	}
	if(!p)							//找不到第i个元素 
		return INFEASIBLE;

	q = p;							//p指向la表中第i个结点 
	while(q && k<i+len-1)			//查找la表中第i+len-1个结点，用q标记 
	{
		q = q->next;
		k++;
	}
	if(!q)							
		return INFEASIBLE;
		
	if(!prep)						//i=1的情况 
		*la = q->next;
	else							//完成删除 
		prep->next = q->next;

	if(j==1)
	{
		q->next = *lb;
		*lb = p;
	}
	else
	{
		s = *lb;
		k = 1;
		while(s && k<j-1)			//查找lb表中第j-1个元素 
		{
			s = s->next;
			k++;
		}
		if(!s)
			return INFEASIBLE;
			
		q->next = s->next;
		s->next = p;				//完成插入 
		
		return OK;
	}

}

/*━━━━━━━━━━━━━━━┓
┃题2.17：将b插入为L的第i个结点 ┃
┗━━━━━━━━━━━━━━━*/
/* 本题中的链表无头结点 */
Status Algo_2_17(LinkList *L, int i, LElemType_L b)
{
	LinkList p, q;
	int count;
	
	p = (LinkList)malloc(sizeof(LNode));
	if(!p)
		exit(OVERFLOW);
	p->data = b;
	
	if(i>0)
	{
		if(i==1)
		{
			p->next = *L;
			*L = p;
			return OK;			
		}
		else
		{
			if(*L)
			{
				count = 1;
				q = *L;
				while(count<i-1 && q)
				{
					count++;
					q = q->next;	
				}
				
				if(q)
				{
					p->next = q->next;
					q->next = p;
					return OK;
				}
			}		
		}
	}

	return ERROR;
}

/*━━━━━━━━━━━━┓
┃题2.18：删除L的第i个结点┃
┗━━━━━━━━━━━━*/
/* 本题中的链表无头结点 */
Status Algo_2_18(LinkList *L, int i)
{
	LinkList p, q;
	int count;
	
	if(i>0)
	{
		p = *L;
		count = 1;
		while(p && count<i-1)
		{
			count++;
			p = p->next;
		}
		
		if(p)
		{
			if(count>i-1)					//删除头结点
			{
				*L = (*L)->next;
				free(p);
				return OK;
			}
			else
			{
				if(p->next)					//第i个结点存在
				{
					q = p->next;
					p->next = q->next;
					free(q);
					return OK;
				} 
			}
		}
	}
	
	return ERROR;
}

void InitList_2_16(LinkList *L)
{
	*L = NULL;
}

void Output_2_16(LinkList L)
{
	LinkList p = L;
	
	while(p)
	{
		printf("%2d ", p->data);
		p = p->next;
	}
}
