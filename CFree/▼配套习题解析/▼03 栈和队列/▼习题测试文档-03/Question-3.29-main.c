#include <stdio.h>
#include <stdlib.h>							//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  			//**▲01 绪论**//

/* 宏定义 */
#define MAXQSIZE 100					//最大队列长度

/* 类型定义 */
typedef int QElemType;
typedef struct
{
	QElemType *base;
	int front;	
	int rear;
	int tag;							//0表示空，1表示满 
}SqQueue;

/* 函数原型 */
Status EnQueue_3_29(SqQueue *Q, QElemType e);
Status DeQueue_3_29(SqQueue *Q, QElemType *e);
Status InitQueue_3_29(SqQueue *Q);
void Output_3_29(SqQueue Q);

int main(int argc, char *argv[])
{
	SqQueue Q;
	int i;
	QElemType e;
	
	printf("初始化队列...\n");
	InitQueue_3_29(&Q);
	printf("\n");

	printf("进行 5 次连续入队操作...\n");
	for(i=1; i<=5; i++)
	{
		EnQueue_3_29(&Q, i);
		printf("元素 \"%d\" 入队后，队列中的元素为：", i);	
		Output_3_29(Q);
		printf("\n");	
	}
	printf("\n");

	printf("进行 5 次连续出队操作...\n");
	for(i=1; i<=5; i++)
	{
		DeQueue_3_29(&Q, &e);
		printf("元素 \"%d\" 出队后，队列中的元素为：", e);	
		Output_3_29(Q);
		printf("\n");	
	}
	printf("\n");
	
	return 0;
}

Status InitQueue_3_29(SqQueue *Q)
{
	(*Q).base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if(!((*Q).base))
		exit(OVERFLOW);
	
	(*Q).front = (*Q).rear = 0;
	(*Q).tag = 0;
}

/*━━━━━━┓
┃题3.29：入队┃
┗━━━━━━*/
Status EnQueue_3_29(SqQueue *Q, QElemType e)
{
	if((*Q).rear==(*Q).front && (*Q).tag==1)	//队列满
		return ERROR;

	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear+1)%MAXQSIZE;

	if((*Q).rear==(*Q).front)					//入队后队满 
		(*Q).tag = 1;

	return OK;
}

/*━━━━━━┓
┃题3.29：出队┃
┗━━━━━━*/
Status DeQueue_3_29(SqQueue *Q, QElemType *e)
{
	if((*Q).front==(*Q).rear && (*Q).tag==0)	//队列空
		return ERROR;

	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front+1)%MAXQSIZE;

	if((*Q).rear==(*Q).front)					//出队后队空 
		(*Q).tag = 0;

	return OK;
}

void Output_3_29(SqQueue Q)
{
	int i;
	
	for(i=Q.front; i!=Q.rear; i=(i+1)%MAXQSIZE)
		printf("%d ", Q.base[i]);
}
