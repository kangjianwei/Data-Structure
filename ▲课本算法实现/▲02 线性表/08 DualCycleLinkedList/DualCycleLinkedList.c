/**********************************************
 *							     			  *
 * 文件夹: ▲02 线性表\08 DualCycleLinkedList *
 * 							     			  *
 * 文件名: DualCycleLinkedList.c 			  *
 * 				     		     			  *
 * 算  法: 2.18、2.19            			  * 
 *                               			  *
 **********************************************/

#ifndef DUALCYCLELINKEDLIST_C
#define DUALCYCLELINKEDLIST_C

#include "DualCycleLinkedList.h" 		//**▲02 线性表**//

Status InitList_DuL(DuLinkList *L)
{
	*L = (DuLinkList)malloc(sizeof(DuLNode));
	if(!(*L))
		exit(OVERFLOW);

	(*L)->next = (*L)->prior = *L;

	return OK;
} 

Status ClearList_DuL(DuLinkList L)
{
	DuLinkList p, q;
	
	p = L->next;
	
	while(p!=L)
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	L->next = L->prior = L;

	return OK;
}

void DestroyList_DuL(DuLinkList *L)
{
	ClearList_DuL(*L);
	
	free(*L);

	*L = NULL;	
}

Status ListEmpty_DuL(DuLinkList L)
{
	if(L && L->next==L && L->prior==L)
		return TRUE;
	else
		return FALSE;	
} 

int ListLength_DuL(DuLinkList L)
{
	DuLinkList p;				
	int count;

	if(L)
	{
		count = 0;
		p = L;					//p指向头结点
		
		while(p->next!=L)		//p没到表头
		{
			count++;
			p = p->next;
		}
	}

	return count;
} 

Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e)
{
	DuLinkList p;
	int count;
	
	if(L)
	{
		count = 1;
		p = L->next;
		
		while(p!=L && count<i)
		{
			count++;
			p = p->next;
		}
		
		if(p!=L)
		{
			*e = p->data;
			return OK;
		}	
	}

	return ERROR;
} 

int LocateElem_DuL(DuLinkList L, LElemType_DC e, Status(Compare)(LElemType_DC, LElemType_DC))
{
	DuLinkList p;
	int count;
	
	if(L)
	{
		count = 1;
		p = L->next;
		
		while(p!=L && !Compare(e, p->data))
		{
			count++;
			p = p->next;	
		}
				
		if(p!=L)
			return count;		
	}
	
	return 0;
} 

Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e)
{
	DuLinkList p;
	
	if(L)
	{
		p = L->next;
		
		while(p!=L && p->data!=cur_e)
			p = p->next;
		
		if(p!=L && p->prior!=L)				//p不为首结点
		{
			*pre_e = p->prior->data;
			return OK;
		}			
	}

	return ERROR;	
} 

Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e)
{
	DuLinkList p;
	
	if(L)
	{
		p = L->next;
		
		while(p!=L && p->data!=cur_e)
			p = p->next;
		
		if(p!=L && p->next!=L)
		{
			*next_e = p->next->data;
			return OK;
		}		
	}

	
	return ERROR;
}

DuLinkList GetElemPtr_DuL(DuLinkList L, int i)
{										
	int count;
	DuLinkList p;
	
	if(L && i>0)
	{
		count = 1;
		p = L->next;
		
		while(p!=L && count<i)
		{
			count++;
			p = p->next;
		}
	
		if(p!=L)
			return p;
	}

	return NULL;
}

/*═════╗
║ 算法2.18 ║ 
╚═════*/
/* 与课本双链表插入算法略有不同，根源在于GetElemP_DuL不同 */
Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e)
{
	DuLinkList p, s;
	
	if(i<1 || i>ListLength_DuL(L)+1)	//先对i做出限制 
		return ERROR;

	p = GetElemPtr_DuL(L, i);			//确定第i个结点指针 
	if(!p)								//此处若p=NULL，说明i = ListLength_DuL(L)+1
		p = L;							//令p指向头指针	
	
	s = (DuLinkList)malloc(sizeof(DuLNode));
	if(!s)
		exit(OVERFLOW);
	s->data = e;
	
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	
	return OK;		
} 

/*═════╗
║ 算法2.19 ║ 
╚═════*/
Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e)
{
	DuLinkList p;
	
	if(!(p=GetElemPtr_DuL(L, i)))		//i值不合法
		return ERROR;
	
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;

	free(p);
	p = NULL;
	
	return OK;
} 

void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC))
{
	DuLinkList p;

	p = L->next;					//p指向头结点，正向访问链表
	
	while(p!=L)
	{
		Visit(p->data);
		p = p->next;
	}
} 

#endif 
