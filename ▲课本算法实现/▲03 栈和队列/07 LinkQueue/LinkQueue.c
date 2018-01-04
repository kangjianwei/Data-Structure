/**************************************
 *                                    *
 * 文件夹: ▲03 栈和队列\07 LinkQueue *
 *                                    *
 * 文件名: LinkQueue.c                *
 *                                    *
 *************************************/

#ifndef LINKQUEUE_C
#define LINKQUEUE_C

#include "LinkQueue.h" 					//**▲03 栈和队列**//
	
Status InitQueue_L(LinkQueue *Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front)
		exit(OVERFLOW);

	(*Q).front->next = NULL;

	return OK;
}

void ClearQueue_L(LinkQueue *Q)
{
	(*Q).rear = (*Q).front->next;
	
	while((*Q).rear)
	{
		(*Q).front->next = (*Q).rear->next;		
		free((*Q).rear);		
		(*Q).rear = (*Q).front->next;
	}
	
	(*Q).rear = (*Q).front;
}

void DestroyQueue_L(LinkQueue *Q)
{
	while((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;	
	}
}

Status QueueEmpty_L(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
} 

int QueueLength_L(LinkQueue Q)
{
	int count = 0;
	QueuePtr p = Q.front;
	
	while(p!=Q.rear)
	{
		count++;
		p = p->next;
	}
	
	return count;
} 

Status GetHead_L(LinkQueue Q, QElemType_L *e)
{
	QueuePtr p;
	
	if(Q.front==Q.rear)
		return ERROR;
		
	p = Q.front->next;
	*e = p->data;
	
	return OK;
} 

Status EnQueue_L(LinkQueue *Q, QElemType_L e)
{
	QueuePtr p;
	
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);

	p->data = e;
	p->next = NULL;
	
	(*Q).rear->next = p;
	(*Q).rear=p;

	return OK;
} 

Status DeQueue_L(LinkQueue *Q, QElemType_L *e)
{
	QueuePtr p;
	
	if((*Q).front==(*Q).rear)
		return ERROR;
		
	p = (*Q).front->next;
	*e = p->data;
	
	(*Q).front->next = p->next;
	if((*Q).rear==p)
		(*Q).rear = (*Q).front;
		
	free(p);
	
	return OK;
} 

void QueueTraverse_L(LinkQueue Q, void (Visit)(QElemType_L))
{
	QueuePtr p;
	
	p = Q.front->next;
	
	while(p)
	{
		Visit(p->data);
		p = p->next;
	}
} 

#endif
