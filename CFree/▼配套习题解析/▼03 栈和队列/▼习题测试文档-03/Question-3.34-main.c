#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/07 LinkQueue/LinkQueue.c"  //**��03 ջ�Ͷ���**//

/* ����ԭ�� */
void Algo_3_34(char *En, char Con[]);
Status EnQueue_3_34(LinkQueue *Q, QElemType_L e, int di);
Status Dispatch_3_34(char *En, char Ex[], char Con[]);

int main(int argc, char *argv[])
{
	char *En = "HPSHHSHPPHHSPSHSPSSHSP"; 
	char Ex[100], Con[100];

	printf("�����������ߡ����������ұߡ�..\n");
	printf("����ǰ��ڴ��ĳ�������Ϊ��P����Ӳ��ϯ��S�������ԣ�H����Ӳ�ԣ���\nEn�����ҵ��� = ");
	printf("%s\n", En);
	printf("\n");
	
	printf("���ɵ�������...\n");
	Algo_3_34(En, Con);
	printf("��������Ϊ��E�����ͷ��ӣ�A�����β��ӣ�D�����ͷ���ӣ���\nCon = ");
	printf("%s\n", Con);
	printf("\n");	

	printf("���ݵ������н��г������...\n");
	Dispatch_3_34(En, Ex, Con);
	printf("������ɺ���ڳ��ĳ�������Ϊ��\nEx�����ҵ��� = ");
	printf("%s\n", Ex);
	printf("\n");

	return 0;
}

/*��������������������������
����3.34�����ɳ���������Щ�
��������������������������*/
/* �����������ߣ��������ұߣ������ȡ˳����ҵ��� */
void Algo_3_34(char *En, char Con[])
{
	int i, j; 
	LinkQueue Q; 
	QElemType_L e;
		
	InitQueue_L(&Q);						//��ʼ��һ���ַ����� 
	i = j = 0;
	
	while(En[i])
	{
		if(En[i]=='P')						//Ӳ��ֱ�ӿ������ʵ�λ�� 
		{
			Con[j++] = 'L';					//L��������ֱ�ӿ������� 
		}
		
		if(En[i]=='S')						//���ԴӶ�ͷ��� 
		{
			EnQueue_3_34(&Q, En[i], 0);
			Con[j++] = 'E';
		}	
		
		if(En[i]=='H')						//Ӳ�ԴӶ�β���
		{
			EnQueue_3_34(&Q, En[i], 1);
			Con[j++] = 'A';
		}
				
		i++;
	}
	
	while(!QueueEmpty_L(Q))					//�������������Ժ�Ӳ�Գ��� 
	{
		DeQueue_L(&Q, &e);;
		Con[j++] = 'D';
	}
	
	Con[j] = '\0';
}

/* ������޵Ķ�������㷨*/ 
Status EnQueue_3_34(LinkQueue *Q, QElemType_L e, int di)	//di������ӷ��� 
{
	QueuePtr p;
	
	p = (QueuePtr)malloc(sizeof(QNode));					//���������޷���� 
	if(!p)
		exit(OVERFLOW);
	
	p->data = e;
	
	if(di==0)												//di=0�Ӷ�ͷ���
	{
		p->next = (*Q).front->next;
		(*Q).front->next = p;
	}
	
	if(di==1) 												//di=1�Ӷ�β���
	{
		p->next = (*Q).rear->next;
		(*Q).rear->next = p;
		(*Q).rear = p;
	}
	
	return OK;	 
} 

/* ����ڵĳ�����ȵ����� */ 
Status Dispatch_3_34(char *En, char Ex[], char Con[])
{
	int i, j, k;
	LinkQueue Q; 
	QElemType_L e;
		
	InitQueue_L(&Q);						//��ʼ��һ���ַ����� 	
	i = j = k = 0;

	while(Con[k])
	{
		if(Con[k]=='L')						//Ӳ�������ֱ�ӿ������� 
			Ex[j++] = En[i++];
		
		if(Con[k]=='E')						//���ԴӶ�ͷ��� 
			EnQueue_3_34(&Q, En[i++], 0);
		
		if(Con[k]=='A')
			EnQueue_3_34(&Q, En[i++], 1);
			
		if(Con[k]=='D')
		{
			DeQueue_L(&Q, &e);
			Ex[j++] = e;		
		}
		
		k++;
	}
	
	if(!Con[k] && (En[i] || QueueEmpty_L(Q)))
		return ERROR;
	
	Ex[j] = '\0';
	
	return OK;
}
