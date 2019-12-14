#include <stdio.h>
#include <stdlib.h>							//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  			//**��01 ����**//

/* �궨�� */
#define MAXQSIZE 100					//�����г���

/* ���Ͷ��� */
typedef int QElemType;
typedef struct
{
	QElemType *base;
	int front;	
	int rear;
	int tag;							//0��ʾ�գ�1��ʾ�� 
}SqQueue;

/* ����ԭ�� */
Status EnQueue_3_29(SqQueue *Q, QElemType e);
Status DeQueue_3_29(SqQueue *Q, QElemType *e);
Status InitQueue_3_29(SqQueue *Q);
void Output_3_29(SqQueue Q);

int main(int argc, char *argv[])
{
	SqQueue Q;
	int i;
	QElemType e;
	
	printf("��ʼ������...\n");
	InitQueue_3_29(&Q);
	printf("\n");

	printf("���� 5 ��������Ӳ���...\n");
	for(i=1; i<=5; i++)
	{
		EnQueue_3_29(&Q, i);
		printf("Ԫ�� \"%d\" ��Ӻ󣬶����е�Ԫ��Ϊ��", i);	
		Output_3_29(Q);
		printf("\n");	
	}
	printf("\n");

	printf("���� 5 ���������Ӳ���...\n");
	for(i=1; i<=5; i++)
	{
		DeQueue_3_29(&Q, &e);
		printf("Ԫ�� \"%d\" ���Ӻ󣬶����е�Ԫ��Ϊ��", e);	
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

/*��������������
����3.29����ө�
��������������*/
Status EnQueue_3_29(SqQueue *Q, QElemType e)
{
	if((*Q).rear==(*Q).front && (*Q).tag==1)	//������
		return ERROR;

	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear+1)%MAXQSIZE;

	if((*Q).rear==(*Q).front)					//��Ӻ���� 
		(*Q).tag = 1;

	return OK;
}

/*��������������
����3.29�����ө�
��������������*/
Status DeQueue_3_29(SqQueue *Q, QElemType *e)
{
	if((*Q).front==(*Q).rear && (*Q).tag==0)	//���п�
		return ERROR;

	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front+1)%MAXQSIZE;

	if((*Q).rear==(*Q).front)					//���Ӻ�ӿ� 
		(*Q).tag = 0;

	return OK;
}

void Output_3_29(SqQueue Q)
{
	int i;
	
	for(i=Q.front; i!=Q.rear; i=(i+1)%MAXQSIZE)
		printf("%d ", Q.base[i]);
}
