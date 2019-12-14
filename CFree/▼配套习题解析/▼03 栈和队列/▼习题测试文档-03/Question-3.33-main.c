#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/08 CylSeqQueue/CylSeqQueue.c"  //**��03 ջ�Ͷ���**//

/* ����ԭ�� */
Status EnQueue_3_33(CSqQueue *Q, QElemType_CSq e);
Status DeQueue_3_33(CSqQueue *Q, QElemType_CSq *e);
	
void PrintElem(QElemType_CSq e);
	//���Ժ�������ӡ���� 

int main(int argc, char *argv[])
{
	CSqQueue Q;
	QElemType_CSq e;
	int i;
	
	printf("��ʼ������...\n");
	InitQueue_CSq(&Q);
	printf("\n");	

	printf("���� 5 ��������Ӳ���...\n");
	for(i=5; i>=1; i--)
	{
		EnQueue_3_33(&Q, i);
		printf("Ԫ�� \"%d\" ��Ӻ󣬶����е�Ԫ��Ϊ��", i);
		QueueTraverse_CSq(Q, PrintElem);
		printf("\n");
	}
	printf("\n");
	
	printf("���� 5 ���������Ӳ���...\n");
	for(i=1; i<=5; i++)
	{
		DeQueue_3_33(&Q, &e);
		printf("Ԫ�� \"%d\" ���Ӻ󣬶����е�Ԫ��Ϊ��", e);	
		QueueTraverse_CSq(Q, PrintElem);
		printf("\n");	
	}
	printf("\n");	
	
	return 0;
}

/*��������������
����3.33����ө�
��������������*/
Status EnQueue_3_33(CSqQueue *Q, QElemType_CSq e)
{
	int a, b;
	
	a = (*Q).base[(*Q).front];						//��ͷԪ��ֵ
 	b = (*Q).base[((*Q).rear-1+MAXQSIZE)%MAXQSIZE];	//��βԪ��ֵ 
	
	if(((*Q).rear+1)%MAXQSIZE==(*Q).front)			//������
		return ERROR;

	if(QueueEmpty_CSq(*Q) || e>=(a+b)/2)				//����Ϊ�ջ���e��С��ƽ��ֵ�����ڶ�β
	{					
		(*Q).base[(*Q).rear] = e;
		(*Q).rear = ((*Q).rear+1)%MAXQSIZE;
	}
	else											//���в�Ϊ����eС��ƽ��ֵ�����ڶ�ͷ 
	{						
		(*Q).front = ((*Q).front-1+MAXQSIZE)%MAXQSIZE; 
		(*Q).base[(*Q).front] = e;
	}
	
	return OK;
}

/*��������������
����3.33�����ө�
��������������*/
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
