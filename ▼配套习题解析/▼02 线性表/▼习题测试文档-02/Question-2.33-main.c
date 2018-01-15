#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include <ctype.h>										//提供isalpha、isdigit原型 
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//

/* 类型定义 */
typedef char LElemType_L;
typedef struct LNode					//双循环链表结构体
{
	LElemType_L data;
	struct LNode* next;
}LNode;
typedef LNode* LinkList;				//指向结构的指针

/* 函数原型 */
Status Algo_2_33(LinkList L, LinkList L_char, LinkList L_num, LinkList L_other);
Status InitList_2_33(LinkList *L);
	//单链表初始化 
Status CreatList_2_33(LinkList L, int n, LElemType_L Data[]);
Status InitList_CL_2_33(LinkList *L);
	//单循环链表初始化
void Output_2_33(LinkList L);
	//输出单链表
void Output_CL_2_33(LinkList L);
	//输出单循环链表

int main(int argc, char *argv[])
{
	LinkList L, L_char, L_num, L_other;
	LElemType_L *a = "2a3@A5e$T*";
	
	InitList_2_33(&L);
	CreatList_2_33(L, 10, a);
	
	printf("L = ");
	Output_2_33(L);
	printf("\n\n");	
	
	printf("拆分单链表之后...\n");
	InitList_CL_2_33(&L_char);
	InitList_CL_2_33(&L_num);
	InitList_CL_2_33(&L_other);
	Algo_2_33(L, L_char, L_num, L_other);
	printf("L_char = ");
	Output_CL_2_33(L_char);
	printf("\n");
	printf("L_num = ");
	Output_CL_2_33(L_num);
	printf("\n");
	printf("L_other = ");
	Output_CL_2_33(L_other);
	printf("\n\n");
			
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题2.33：按字符类型（字母、数字、其他）拆分线性表为循环链表┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
Status Algo_2_33(LinkList L, LinkList L_char, LinkList L_num, LinkList L_other)
{
	LinkList r, rc, rn, ro, s;
	
	if(!L)
		return ERROR;
		
	r = L->next;
	rc = L_char;
	rn = L_num;
	ro = L_other;
	
	while(r)
	{
		s = (LinkList)malloc(sizeof(LNode));
		if(!s)
			exit(OVERFLOW);
		s->data = r->data;
		
		if(isalpha(r->data))					//结点值为字符 
		{
			s->next = rc->next;
			rc->next = s;
			rc = rc->next;
		}
		else if(isdigit(r->data))				//结点值为数字
		{
			s->next = rn->next;
			rn->next = s;
			rn = rn->next;		
		}
		else									//其它 
		{
			s->next = ro->next;
			ro->next = s;
			ro = ro->next;		
		}
		
		r = r->next;
	}
	
	return OK;
}

Status InitList_2_33(LinkList *L)				//单链表初始化 
{
	*L = (LinkList)malloc(sizeof(LNode));		
	if(!(*L))
		exit(OVERFLOW);
	
	(*L)->next = NULL;
	
	return OK;
}

Status CreatList_2_33(LinkList L, int n, LElemType_L Data[])
{
	LinkList s, r;
	int i;
	
	if(!L || L->next)
		return ERROR;
	
	for(i=1,r=L; i<=n; i++)
	{
		s = (LinkList)malloc(sizeof(LNode));
		if(!s)
			exit(OVERFLOW);
		s->data = Data[i-1];
		
		s->next = r->next;
		r->next = s;
		r = r->next;
	} 	
	
	return OK;
}

Status InitList_CL_2_33(LinkList *L)			//单循环链表初始化 
{
	*L = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	
	(*L)->next = *L;
	
	return OK;
}

void Output_2_33(LinkList L)					//输出单链表 
{
	LinkList p;
	
	if(L)
	{	
		p = L->next;
		while(p)
		{
			printf("%2c ", p->data);
			p = p->next;
		}	
	}
}

void Output_CL_2_33(LinkList L)					//输出单循环链表 
{
	LinkList p;
	
	if(L)
	{	
		p = L->next;
		while(p!=L)
		{
			printf("%2c ", p->data);
			p = p->next;
		}	
	}
}
