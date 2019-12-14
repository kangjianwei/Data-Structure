#include <stdio.h>		
#include <ctype.h>										//�ṩisalphaԭ�� 
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/01 SequenceStack/SequenceStack.c"  //**��03 ջ�Ͷ���**//

/* ����ԭ�� */
void Algo_3_21(char *s, char c[]);
Status Priority(char a, char b);

int main(int argc, char *argv[])
{
	char *s = "a+b*c-d/e";
	char c[100];
	
	printf("��׺���ʽΪ��");
	printf("%s\n",s);
	printf("\n");
		
	Algo_3_21(s, c);
	printf("���ɵĺ�׺���ʽ��");
	printf("%s\n",c);
	printf("\n");
	
	return 0;
}

/*������������������������
����3.21����׺ʽ���׺ʽ��
������������������������*/
/* �沨��ʽ������׺���ʽ���������д�ڲ�����֮�� */
/* ��"a+b*c-d/e"��ת��Ϊ��"abc*+de/-" */
/* ������ʽ����Ϊ����ĸ��������ֻ��'+'��'-'��'*'��'/' */
void Algo_3_21(char *s, char c[])	//��һ���㹻��������ݴ��沨��ʽ
{						
	int i, j; 
	SqStack S;						//ջ����ʱ�洢������ 
	SElemType_Sq e;					//SElemType������char���ͣ�char��int���Ϳ�ֱ�ӱȽ� 
	
	InitStack_Sq(&S);
	i = j = 0;
	
	while(s[i]!='\0')
	{
		if(isalpha(s[i]))			//��������ĸ
			c[j++] = s[i];			//��ĸֱ���������� 
		else						//������������� 
		{
			while(!StackEmpty_Sq(S))
			{
				GetTop_Sq(S, &e);	//��ȡջ��Ԫ��
				
				if(Priority(e, s[i]))//ջ����������ȼ��� 
				{
					Pop_Sq(&S, &e);	//��ջ�����ȼ��ߵ�������������� 
					c[j++] = e;
				}
				else				//����ջ����������ȼ���ʱ������ѭ�� 
					break;	
			}	
	
			Push_Sq(&S, s[i]);	  	//����ȡ�������ȼ�С���ַ�ѹ��ջ
		}
		
		i++;						//������ȡ 
	}
	
	while(!StackEmpty_Sq(S))
	{
		Pop_Sq(&S, &e);
		c[j++] = e;		
	}
	
	c[j] = '\0';					//������ת������沨��ʽ��"\0"��ǽ��� 
}

/* �Ƚ������a��b�����ȼ� */ 
Status Priority(char a, char b)
{
	switch(a)
	{
		case '*':
		case '/': 
			return OK;				//a>b
			break;

		case '+':
		case '-': 
			if(b=='+' || b=='-')
				return OK;			//a>b
		  	else
		  		return ERROR;		//a<b
	  		break; 
	}
}
