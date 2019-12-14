#ifndef Question_8
#define Question_8

#include <stdio.h>

/* �궨�� */
#define MAX 1000

/* ���Ͷ��� */
typedef struct
{
	int origin;						//������ڴ����ʼ��ַ 
	int size;						//������ڴ���С 
}FreeBlock;							//�ڴ����Ϣ 
typedef FreeBlock SElemType_Sq;
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/01 SequenceStack/SequenceStack.c"	//**��03 ջ�Ͷ���**//

/* ȫ�ֱ��� */
SqStack S;			//����ڴ���Ϣ 
struct
{
	int start;		//�ڴ�ռ���� 
	int end;		//�ڴ�ռ��յ� 
	int cur;		//��ǰ�����ڴ����� 
}Space;				//�ڴ�ռ� 

/* ����ԭ�� */ 
int Algo_8_11(int n);			//�����СΪn���ڴ�飬�������뵽���ڴ���ַ 
Status Algo_8_12();				//�ͷ��ڴ�ռ� 
void InitSpace();				//��ʼ���ڴ�ռ估�ڴ���Ϣ��
void PrintLayout();				//����ڴ�ʹ����� 

int main(int argc, char *argv[])
{
	printf("��ʼ�� %d ���ڴ����Ϊ�洢�ռ�...\n", MAX);
	InitSpace();
	PrintLayout();
	printf("\n");
	
	printf("���� %d ���ڴ��...\n", 300);
	Algo_8_11(300);
	PrintLayout();
	printf("\n");

	printf("���� %d ���ڴ��...\n", 400);	
	Algo_8_11(400);
	PrintLayout();	
	printf("\n");

	printf("���� %d ���ڴ��...\n", 500);	
	Algo_8_11(500);
	PrintLayout();	
	printf("\n");
				
	return 0;
}
void InitSpace()
{
	void *p = malloc(MAX);
	
	Space.start = Space.cur = (int)p;
	Space.end = Space.start+MAX-1;
	
	InitStack_Sq(&S);
}

/*������������������������������������������������������
����8.11�������СΪn���ڴ�飬�������뵽���ڴ���ַ ��
������������������������������������������������������*/
int Algo_8_11(int n)
{
	FreeBlock e;
	
	if(n>MAX)
		return 0;
	else
	{
		while(Space.end-Space.cur+1<n && Algo_8_12())	//���ڴ治���ã����ͷ�һ���ֿռ� 
			;
		
		e.origin = Space.cur;
		e.size = n;
		
		Push_Sq(&S, e);
		
		Space.cur += n;
		
		return e.origin;
	}
}

/*����������������������
����8.12���ͷ��ڴ�ռ䩧
����������������������*/
Status Algo_8_12()
{
	SElemType_Sq e;
	
	if(!StackEmpty_Sq(S))
	{
		Pop_Sq(&S, &e);									//���ڴ���Ϣ����ɾ�����ڴ����Ϣ 
		Space.cur -= e.size;
		
		return OK;	
	}
	else
		return ERROR;
}

void PrintLayout()
{
	SElemType_Sq *k;
	int count;
	
	printf("��ռ�õ��ڴ�鷶Χ����");
	for(k=S.base,count=0; k<S.top; k++)
	{
		printf("%3d����%3d��", k->origin-Space.start, k->origin+k->size-Space.start-1);
		count += k->size;	
	}	
	printf("\n");
	
	printf("�ڴ���ռ�ÿ�����%4d�����п�����%4d��\n", count, MAX-count);		
}

#endif
