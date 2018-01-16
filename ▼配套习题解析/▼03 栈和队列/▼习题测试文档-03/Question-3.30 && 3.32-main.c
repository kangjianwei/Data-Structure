#include <stdio.h>
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  		//**▲01 绪论**//

/* 宏定义 */
#define MAXQSIZE 5						//最大队列长度
#define MAX 100000

/* 类型定义 */
typedef int QElemType;
typedef struct
{
	QElemType *base;
	int rear;
	int length;							//队列元素个数 
}SqQueue;

/* 函数原型 */
Status Algo_3_32(int k, int fib[], int *n);
Status InitQueue_3_30(SqQueue *Q);
Status QueueFull_3_30(SqQueue Q);
Status EnQueue_3_30(SqQueue *Q, QElemType e);
Status DeQueue_3_30(SqQueue *Q, QElemType *e);
void Output_3_30(SqQueue Q);
int SumQueue_3_32(SqQueue Q);

int main(int argc, char *argv[])
{
	int i;

	printf("███题 3.30 验证...███\n");	
	{
		SqQueue Q;
		QElemType e;		
		printf("初始化队列...\n");
		InitQueue_3_30(&Q);
		printf("\n");
	
		printf("进行 5 次连续入队操作...\n");
		for(i=1; i<=5; i++)
		{
			EnQueue_3_30(&Q, i);
			printf("元素 \"%d\" 入队后，队列中的元素为：", i);	
			Output_3_30(Q);
			printf("\n");	
		}
		printf("\n");
	
		printf("进行 5 次连续出队操作...\n");
		for(i=1; i<=5; i++)
		{
			DeQueue_3_30(&Q, &e);
			printf("元素 \"%d\" 出队后，队列中的元素为：", e);	
			Output_3_30(Q);
			printf("\n");	
		}
		printf("\n");	
	}

	printf("███题 3.32 验证...███\n");
	{
		int n, fib[100];	
		Algo_3_32(MAXQSIZE, fib, &n);
		printf("%d 阶斐波那契数列的前 %d 项为（包括第 0 项）：\n", MAXQSIZE, n+1);
		for(i=0; i<=n+1; i++)
			printf("%d ", fib[i]);
		printf("\n\n");	
	}
	
	return 0;
}

Status InitQueue_3_30(SqQueue *Q)
{
	(*Q).base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if(!((*Q).base))
		exit(OVERFLOW);
	
	(*Q).rear = 0;
	(*Q).length = 0;
}

/*━━━━━━━━━━━━┓
┃题3.30：判断队列是否已满┃
┗━━━━━━━━━━━━*/
Status QueueFull_3_30(SqQueue Q)		//判断队列是否已满 
{
	if(Q.length==MAXQSIZE)
		return TRUE;
	else
		return FALSE;
} 

/*━━━━━━┓
┃题3.30：入队┃
┗━━━━━━*/
Status EnQueue_3_30(SqQueue *Q, QElemType e)
{
	if(QueueFull_3_30(*Q))				//队列满
		return ERROR;
		
	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear+1)%MAXQSIZE;

	(*Q).length++;

	return OK;
}

/*━━━━━━┓
┃题3.30：出队┃
┗━━━━━━*/
Status DeQueue_3_30(SqQueue *Q, QElemType *e)
{
	int head;
	head = ((*Q).rear + MAXQSIZE - (*Q).length)%MAXQSIZE;

	if(!((*Q).length))					//队列空
		return ERROR;

	*e = (*Q).base[head];

	(*Q).length--; 

	return OK;
}

void Output_3_30(SqQueue Q)
{
	int r, count;
	
	r = (Q.rear + MAXQSIZE - Q.length)%MAXQSIZE;
	
	for(count=1; count<=Q.length; r=(r+1)%MAXQSIZE,count++)
		printf("%d ", Q.base[r]);
}

int SumQueue_3_32(SqQueue Q)
{
	int i, sum;
	
	for(i=0,sum=0; i<Q.length; i++)
		sum += Q.base[i];
	
	return sum;
}

/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃题3.32：求k阶斐波那契数列满足特定条件的前n+1项┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/
Status Algo_3_32(int k, int fib[], int *n)		//项数从0开始计数
{
	int i, sum;
	SqQueue Q;
	QElemType e;
	
	if(k<2 || MAX<0)
		return ERROR;
	
	InitQueue_3_30(&Q);
	
	for(i=0; i<=k-2; i++)		//前k-1项为0 
		EnQueue_3_30(&Q, 0);
	EnQueue_3_30(&Q, 1);		//第k项为1
	
	for(i=0; i<=k-1; i++)
		fib[i] = Q.base[i];
	*n = k-2;
	
	if(MAX>0)
	{
		do
		{
			(*n)++;
			sum = SumQueue_3_32(Q);
			fib[(*n)+1] = sum;
			Q.base[Q.rear] = sum;
			Q.rear = (Q.rear+1)%MAXQSIZE;
		}while(sum<=MAX);
	}

	return OK;
}
