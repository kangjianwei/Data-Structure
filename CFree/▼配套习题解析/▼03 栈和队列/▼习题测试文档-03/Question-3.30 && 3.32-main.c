#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  		//**��01 ����**//

/* �궨�� */
#define MAXQSIZE 5						//�����г���
#define MAX 100000

/* ���Ͷ��� */
typedef int QElemType;
typedef struct
{
	QElemType *base;
	int rear;
	int length;							//����Ԫ�ظ��� 
}SqQueue;

/* ����ԭ�� */
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

	printf("�������� 3.30 ��֤...������\n");	
	{
		SqQueue Q;
		QElemType e;		
		printf("��ʼ������...\n");
		InitQueue_3_30(&Q);
		printf("\n");
	
		printf("���� 5 ��������Ӳ���...\n");
		for(i=1; i<=5; i++)
		{
			EnQueue_3_30(&Q, i);
			printf("Ԫ�� \"%d\" ��Ӻ󣬶����е�Ԫ��Ϊ��", i);	
			Output_3_30(Q);
			printf("\n");	
		}
		printf("\n");
	
		printf("���� 5 ���������Ӳ���...\n");
		for(i=1; i<=5; i++)
		{
			DeQueue_3_30(&Q, &e);
			printf("Ԫ�� \"%d\" ���Ӻ󣬶����е�Ԫ��Ϊ��", e);	
			Output_3_30(Q);
			printf("\n");	
		}
		printf("\n");	
	}

	printf("�������� 3.32 ��֤...������\n");
	{
		int n, fib[100];	
		Algo_3_32(MAXQSIZE, fib, &n);
		printf("%d ��쳲��������е�ǰ %d ��Ϊ�������� 0 ���\n", MAXQSIZE, n+1);
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

/*��������������������������
����3.30���ж϶����Ƿ�������
��������������������������*/
Status QueueFull_3_30(SqQueue Q)		//�ж϶����Ƿ����� 
{
	if(Q.length==MAXQSIZE)
		return TRUE;
	else
		return FALSE;
} 

/*��������������
����3.30����ө�
��������������*/
Status EnQueue_3_30(SqQueue *Q, QElemType e)
{
	if(QueueFull_3_30(*Q))				//������
		return ERROR;
		
	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear+1)%MAXQSIZE;

	(*Q).length++;

	return OK;
}

/*��������������
����3.30�����ө�
��������������*/
Status DeQueue_3_30(SqQueue *Q, QElemType *e)
{
	int head;
	head = ((*Q).rear + MAXQSIZE - (*Q).length)%MAXQSIZE;

	if(!((*Q).length))					//���п�
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

/*������������������������������������������������
����3.32����k��쳲��������������ض�������ǰn+1�
������������������������������������������������*/
Status Algo_3_32(int k, int fib[], int *n)		//������0��ʼ����
{
	int i, sum;
	SqQueue Q;
	QElemType e;
	
	if(k<2 || MAX<0)
		return ERROR;
	
	InitQueue_3_30(&Q);
	
	for(i=0; i<=k-2; i++)		//ǰk-1��Ϊ0 
		EnQueue_3_30(&Q, 0);
	EnQueue_3_30(&Q, 1);		//��k��Ϊ1
	
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
