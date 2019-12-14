#include <stdio.h>	
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//

/* �궨�� */
#define N 100								//ջ������

/* ���Ͷ��� */
typedef int SElemType;
typedef enum{ Left, Right } StackName;
typedef struct
{
	SElemType s[N];							//��һ�������㹻���������ջ 
	int t[2];								//���ջ��ָ�� 
}TWStack;

/* ����ԭ�� */
void Inistack_TWS_3_15(TWStack *S);
Status Push_TWS_3_15(TWStack *S, StackName name, SElemType x);
Status Pop_TWS_3_15(TWStack *S, StackName name, SElemType *x);
void OutputStack_3_15(TWStack S, StackName name);

int main(int argc, char *argv[])
{
	TWStack S;
	int i, x;
	
	printf("��ʼ��ջ...\n");
	Inistack_TWS_3_15(&S);
	printf("\n");
	
	printf("������ջ��ѹ��Ԫ��...\n");
	for(i=1; i<=5; i++)
	{
		Push_TWS_3_15(&S, Left, i);
		Push_TWS_3_15(&S, Right, 2*i);
	}	
	printf("��ջ�е�Ԫ�أ���ջ�׵�ջ������");
	OutputStack_3_15(S, Left);
	printf("\n");
	printf("��ջ�е�Ԫ�أ���ջ�׵�ջ������");	
	OutputStack_3_15(S, Right);
	printf("\n\n");
	
	printf("�ֱ𵯳�����ջ��ջ��Ԫ��...\n");
	Pop_TWS_3_15(&S, Left, &x);
	printf("��ջ��ջ��Ԫ��Ϊ��%d\n", x);
	Pop_TWS_3_15(&S, Right, &x);
	printf("��ջ��ջ��Ԫ��Ϊ��%d\n", x);
	printf("��ջ�е�Ԫ�أ���ջ�׵�ջ������");
	OutputStack_3_15(S, Left);
	printf("\n");
	printf("��ջ�е�Ԫ�أ���ջ�׵�ջ������");	
	OutputStack_3_15(S, Right);
	printf("\n\n");
		
	return 0;
}

/*��������������������������
����3.15-(1)����ʼ��˫��ջ��
��������������������������*/
void Inistack_TWS_3_15(TWStack *S) 
{									
	(*S).t[Left] = -1;						//ջ0��ջ��ָ�� 
	(*S).t[Right] = N;						//ջ1��ջ��ָ��
}

/*����������������������
����3.15-(2)����ջ������
����������������������*/
Status Push_TWS_3_15(TWStack *S, StackName name, SElemType x)//��Ԫ��x��iջ 
{
	if((*S).t[Left]+1==(*S).t[Right])		//ע��ջ������������ȫ����������ջ�������˷ѿռ� 
		return ERROR;

	switch(name)
	{
		case Left: 
			(*S).t[name]++;		
			break;

		case Right: 
			(*S).t[name]--;
			break;
	}
	
	(*S).s[(*S).t[name]] = x;

	return OK;
}

/*����������������������
����3.15-(3)����ջ������
����������������������*/
Status Pop_TWS_3_15(TWStack *S, StackName name, SElemType *x)	//��iջ��ջ��Ԫ�س�ջ 
{	
	switch(name)
	{
		case Left:
			if((*S).t[name]==-1)					//�ж�ջ�� 
				return ERROR;
			*x = (*S).s[(*S).t[name]];
			(*S).t[name]--;
			break;

		case Right:
			if((*S).t[name]==N)
				return ERROR;
			*x = (*S).s[(*S).t[name]];
			(*S).t[name]++;
			break;
	} 
}

/* ���ջ */ 
void OutputStack_3_15(TWStack S, StackName name)
{
	int i;
	
	switch(name)
	{
		case Left:
			for(i=0; i<=S.t[name]; i++)
				printf("%d ", S.s[i]);
			break;

		case Right:
			for(i=N-1; i>=S.t[name]; i--)
				printf("%d ", S.s[i]);
			break;
	}
}
