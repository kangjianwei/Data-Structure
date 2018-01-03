/*****************************
 *							 *
 * 文件夹: ▲02 线性表       *
 * 							 *
 * 文件名: ExtenLinkedList.c *
 * 				     		 *
 * 算  法: 2.20              * 
 *                           *
 *****************************/

#ifndef EXTENLINKEDLIST_C
#define EXTENLINKEDLIST_C

#include "ExtenLinkedList.h"				//**▲02 线性表**//

Status MakeNode_E(Link *p, LElemType_E e)
{
	*p = (Link)malloc(sizeof(ELNode));		//申请空间 	
	if(!(*p))
		exit(OVERFLOW);
				
	(*p)->data = e;
	(*p)->next = NULL;
	
	return OK; 
} 

void FreeNode_E(Link *p)					//释放空间 
{
	free(*p);
	*p = NULL;
} 

Status InitList_E(ELinkList *L)
{
	Link p;
	
	p = (Link)malloc(sizeof(ELNode));
	if(!p)
		exit(OVERFLOW);		
	p->next = NULL;
	
	(*L).head = (*L).tail = p;
	(*L).len = 0;
	
	return OK;
} 

void ClearList_E(ELinkList *L)
{
	Link p, q;
	
	p = (*L).head->next;
		
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	(*L).head->next = NULL;
	(*L).tail = (*L).head;
	(*L).len = 0;		
}

void DestroyList_E(ELinkList *L)
{
	ClearList_E(L);
	
	free((*L).head);

	(*L).head = (*L).tail = NULL;
} 


void InsFirst_E(ELinkList *L, Link h, Link s)
{
	s->next = h->next;
	h->next = s;
	
	if(h==(*L).tail)					//若h为尾结点 
		(*L).tail = h->next;

	(*L).len++;
} 

Status DelFirst_E(ELinkList *L, Link h, Link *q)
{
	*q = h->next;
	
	if(*q)								//链表非空 
	{
		h->next = (*q)->next;
		if(!h->next)					//h后只有一个结点 
			(*L).tail = h;

		(*L).len--;						//并不释放被删结点所占空间 

		return OK;
	}

	return ERROR;
} 

void Append_E(ELinkList *L, Link s)
{
	int count = 0;
	
	(*L).tail->next = s;
	
	while(s)							//考虑s为空的情况 
	{
		(*L).tail = s;
		s = s->next;
		count++;
	}

	(*L).len += count;
} 

Status Remove_E(ELinkList *L, Link *q)
{
	Link p;
	
	if(!(*L).len)
	{
		*q = NULL;
		return ERROR;
	}
	
	*q = (*L).tail;
	
	p = (*L).head;						//寻找尾结点的前驱 
	while(p->next!=(*L).tail)
		p = p->next;
	p->next = NULL;
	(*L).tail = p;

	(*L).len--;
	
	return OK;
} 

void InsBefore(ELinkList *L, Link *p, Link s)
{										
	Link q;
	
	q = PriorPos_E(*L, *p);				//寻找p的前驱 
	if(!q)								//若p无前驱（只有一个结点） 
		q = (*L).head;

	s->next = *p;
	q->next = s;
	*p = s;
	
	(*L).len++;							//修改len，需用到*L 			
} 

void InsAfter(ELinkList *L, Link *p, Link s)
{
	if(*p==(*L).tail)
		(*L).tail = s;

	s->next = (*p)->next;
	(*p)->next = s;
	*p = s;

	(*L).len++;
} 

void SetCurElem_E(Link p, LElemType_E e)
{
	p->data = e;
} 

LElemType_E GetCurElem_E(Link p)
{
	return p->data;
} 

Status ListEmpty_E(ELinkList L)
{
	if(L.len)
		return FALSE;
	else
		return TRUE;
} 

int ListLength_E(ELinkList L)
{
	return L.len;
} 

PositionPtr GetHead_E(ELinkList L)
{
	return L.head;
}

PositionPtr GetLast_E(ELinkList L)
{
	return L.tail;
}

PositionPtr PriorPos_E(ELinkList L, Link p)
{
	Link q;
	
	q = L.head->next;
	if(q==p)							//首结点无前驱 
		return NULL;
	else	
	{
		while(q->next!=p)				//寻找p的前驱 
			q = q->next;

		return q; 
	} 
} 

PositionPtr NextPos_E(Link p)
{
	return p->next; 
} 

Status LocatePos_E(ELinkList L, int i, Link *p)
{
	int count = 0;
	*p = L.head;						//i=0时返回头指针 
	
	if(i<0 || i>L.len)
		return ERROR;

	while(count<i)
	{
		count++;
		*p = (*p)->next;
	}
	
	return OK;
} 

PositionPtr LocateElem_E(ELinkList L, LElemType_E e, Status(Compare)(LElemType_E,LElemType_E))
{
	Link p = L.head->next;

	while(p && !(Compare(e, p->data)))
		p = p->next;

	return p;	
}

Status ListTraverse_E(ELinkList L, void(Visit)(LElemType_E))
{
	Link p;
	int j;
	
	p = L.head->next;
	
	for(j=1; j<=L.len; j++)
	{
		Visit(p->data);
		p = p->next;
	}
	
	return OK;
} 

/*═════╗
║ 算法2.20 ║ 
╚═════*/
/* 算法2.9的改写 */
Status ListInsert_L_E(ELinkList *L, int i, LElemType_E e)	
{
	Link h, s;
	
	if(!LocatePos_E(*L, i-1, &h))		//定位第i-1个结点位置 
		return ERROR;					//i值不合法
		
	if(!MakeNode_E(&s, e))				//创建结点 
		return ERROR;					//内存申请失败

	InsFirst_E(L, h, s);

	return OK; 
} 

/* 算法2.10的改写，调用了本文档中定义的函数 */
Status ListDelete_L_E(ELinkList *L, int i, LElemType_E *e)
{
	Link p, q;
	
	if(i<1 || i>(*L).len)
		return ERROR;

	LocatePos_E(*L, i-1, &p);	
	DelFirst_E(L, p, &q);
	
	*e = q->data;
	free(q);
	q = NULL;
	
	return OK;
}

#endif
