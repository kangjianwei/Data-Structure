#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/08 CylSeqQueue/CylSeqQueue.c"  //**▲03 栈和队列**//

/* 函数原型 */
Status EnQueue_3_33(CSqQueue *Q, QElemType_CSq e);
Status DeQueue_3_33(CSqQueue *Q, QElemType_CSq *e);
	
void PrintElem(QElemType_CSq e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	CSqQueue Q;
	QElemType_CSq e;
	int i;
	
	printf("初始化队列...\n");
	InitQueue_CSq(&Q);
	printf("\n");	

	printf("进行 5 次连续入队操作...\n");
	for(i=5; i>=1; i--)
	{
		EnQueue_3_33(&Q, i);
		printf("元素 \"%d\" 入队后，队列中的元素为：", i);
		QueueTraverse_CSq(Q, PrintElem);
		printf("\n");
	}
	printf("\n");
	
	printf("进行 5 次连续出队操作...\n");
	for(i=1; i<=5; i++)
	{
		DeQueue_3_33(&Q, &e);
		printf("元素 \"%d\" 出队后，队列中的元素为：", e);	
		QueueTraverse_CSq(Q, PrintElem);
		printf("\n");	
	}
	printf("\n");	
	
	return 0;
}

/*━━━━━━┓
┃题3.33：入队┃
┗━━━━━━*/
Status EnQueue_3_33(CSqQueue *Q, QElemType_CSq e)
{
	int a, b;
	
	a = (*Q).base[(*Q).front];						//队头元素值
 	b = (*Q).base[((*Q).rear-1+MAXQSIZE)%MAXQSIZE];	//队尾元素值 
	
	if(((*Q).rear+1)%MAXQSIZE==(*Q).front)			//队列满
		return ERROR;

	if(QueueEmpty_CSq(*Q) || e>=(a+b)/2)				//队列为空或者e不小于平均值，插在队尾
	{					
		(*Q).base[(*Q).rear] = e;
		(*Q).rear = ((*Q).rear+1)%MAXQSIZE;
	}
	else											//队列不为空且e小于平均值，插在队头 
	{						
		(*Q).front = ((*Q).front-1+MAXQSIZE)%MAXQSIZE; 
		(*Q).base[(*Q).front] = e;
	}
	
	return OK;
}

/*━━━━━━┓
┃题3.33：出队┃
┗━━━━━━*/
Status DeQueue_3_33(CSqQueue *Q, QElemType_CSq *e)
{
	if(DeQueue_CSq(Q, e))		
		return OK;
	else
		return ERROR;;
}

void PrintElem(QElemType_CSq e)
{
	printf("%d ", e);
}
