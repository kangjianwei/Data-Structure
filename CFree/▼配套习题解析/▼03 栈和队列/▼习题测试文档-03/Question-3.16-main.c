#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/01 SequenceStack/SequenceStack.c"  //**��03 ջ�Ͷ���**//

/* ����ԭ�� */
void Algo_3_16(char *En, char Con[]);
Status Dispatch_3_16(char *En, char Ex[], char Con[]);

int main(int argc, char *argv[])
{
	char *En = "HSHHSHHHSSHSSSHS"; 
	char Ex[100], Con[100];
	
	printf("����������ұߡ�����������ߡ�..\n");
	printf("����ǰ��ڴ��ĳ�������Ϊ��H����Ӳϯ��S������ϯ����\nEn�������ң� = ");
	printf("%s\n", En);
	printf("\n");
	
	printf("���ɵ�������...\n");
	Algo_3_16(En, Con);
	printf("��������Ϊ��I������ջ��O�����ջ����\nCon = ");
	printf("%s\n", Con);
	printf("\n");	

	printf("���ݵ������н��г������...\n");
	Dispatch_3_16(En, Ex, Con);
	printf("������ɺ���ڳ��ĳ�������Ϊ��\nEx�������ң� = ");
	printf("%s\n", Ex);
	printf("\n");

	return 0;
}

/*��������������������������
����3.16�����ɳ���������Щ�
��������������������������*/
/* ����������ұߣ���������ߣ������ȡ˳������� */
void Algo_3_16(char *En, char Con[])		//En�洢�������У�Con�洢�������� 
{
	int i, j; 
	SqStack S; 
	SElemType_Sq e;
		
	InitStack_Sq(&S);						//��ʼ��һ���ַ�ջ 
	i = j = 0;
	
	while(En[i])
	{
		if(En[i]=='H')						//Ӳϯ����ջ 
		{
			Push_Sq(&S, En[i]);
			Con[j++] = 'I';
		}
		
		if(En[i]=='S')						//��ϯ��ջ��ջ����ջ����ת 
		{
			Push_Sq(&S, En[i]);
			Pop_Sq(&S, &e);
			Con[j++] = 'I';
			Con[j++] = 'O';
		}	
		
		i++;
	}
	
	while(!StackEmpty_Sq(S))				//��ջ��Ӳϯ��ջ 
	{
		Pop_Sq(&S, &e);
		Con[j++] = 'O';
	}
	
	Con[j] = '\0';
}

/* ����ڵĳ�����ȵ����� */ 
Status Dispatch_3_16(char *En, char Ex[], char Con[])
{
	int i, j, k;
	SqStack S; 
	SElemType_Sq e;
		
	InitStack_Sq(&S);						//��ʼ��һ���ַ�ջ 
	
	i = j = k = 0;

	while(Con[k])
	{
		if(Con[k]=='I')
			Push_Sq(&S, En[i++]);
		
		if(Con[k]=='O')
		{
			Pop_Sq(&S, &e);
			Ex[j++] = e;
		}
		
		k++;
	}
	
	if(!Con[k] && (En[i] || StackEmpty_Sq(S)))
		return ERROR;
	
	Ex[j] = '\0';
	
	return OK;
}
