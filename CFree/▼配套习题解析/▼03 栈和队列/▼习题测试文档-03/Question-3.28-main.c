#include <stdio.h>
#include <stdlib.h>							//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  			//**▲01 绪论**//

/* 类型定义 */
typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode;
typedef QNode* QueuePtr;
typedef struct
{
	QueuePtr rear;
}LinkQueue;

/* 函数原型 */
Status InitQueue_3_28(LinkQueue *Q);
Status EnQueue_3_28(LinkQueue *Q, QElemType e);
Status DeQueue_3_28(LinkQueue *Q, QElemType *e);
void Output_3_28(LinkQueue Q);

int main(int argc, char *argv[])
{
	LinkQueue Q;
	int i;
	QElemType e;
	
	printf("初始化队列...\n");
	InitQueue_3_28(&Q);
	printf("\n");

	printf("进行 5 次连续入队操作...\n");
	for(i=1; i<=5; i++)
	{
		EnQueue_3_28(&Q, i);
		printf("元素 \"%d\" 入队后，队列中的元素为：", i);	
		Output_3_28(Q);
		printf("\n");	
	}
	printf("\n");

	printf("进行 5 次连续出队操作...\n");
	for(i=1; i<=5; i++)
	{
		DeQueue_3_28(&Q, &e);
		printf("元素 \"%d\" 出队后，队列中的元素为：", e);	
		Output_3_28(Q);
		printf("\n");	
	}
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━┓
┃题3.28：队列初始化┃
┗━━━━━━━━━*/
Status InitQueue_3_28(LinkQueue *Q)					//队列初始化 
{
	(*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).rear)
		exit(OVERFLOW);

	(*Q).rear->next = (*Q).rear;

	return OK;
}

/*━━━━━━┓
┃题3.28：入队┃
┗━━━━━━*/
Status EnQueue_3_28(LinkQueue *Q, QElemType e)	//入队 
{
	QueuePtr p;
	
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);
	p->data = e;

	p->next = (*Q).rear->next;
	(*Q).rear->next = p;
	(*Q).rear = p;

	return OK;
} 

/*━━━━━━┓
┃题3.28：出队┃
┗━━━━━━*/
Status DeQueue_3_28(LinkQueue *Q, QElemType *e)	//出队 
{
	QueuePtr h, p;
	
	h = (*Q).rear->next;
	if(h->next==(*Q).rear->next)
		return ERROR;
		
	p = h->next;
	*e = p->data;
	
	h->next = p->next;
	
	if(p==(*Q).rear)							//队列只有一个元素 
		(*Q).rear = h;

	free(p);

	return OK;
}

void Output_3_28(LinkQueue Q)
{
	QueuePtr p;
	
	for(p=Q.rear->next->next; p!=Q.rear->next; p=p->next)
		printf("%d ", p->data);
}
