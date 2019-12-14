#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/01 SequenceStack/SequenceStack.c"  //**��03 ջ�Ͷ���**//

/* ����ԭ�� */
Status Algo_3_19(char *s);
Status Matching(char a, char b)	;

int main(int argc, char *argv[])
{
	char *s = "(1+2)*3/{2/[(4-5)*3]-5*(8-7)}"; 
	
	printf("�жϱ��ʽ %s �����Ƿ�ƥ��...\n", s);
	if(Algo_3_19(s))
		printf("���ʽ����ƥ�䣡\n");
	else
		printf("���ʽ���Ų�ƥ�䣡��\n");

	printf("\n");
	
	return 0;
}

/*��������������������������������
����3.19���жϱ��ʽ�����Ƿ�ƥ�䩧
��������������������������������*/
Status Algo_3_19(char *s)
{
	SqStack S;
	SElemType_Sq e;
	int i;

	i = 0;
	InitStack_Sq(&S);	
	
	while(s[i])
	{
		switch(s[i])
		{
			case '(':
			case '[':
			case '{':
				Push_Sq(&S, s[i]);
				break;
				
			case ')':
			case ']':
			case '}':
				if(StackEmpty_Sq(S))
					return ERROR;
				
				Pop_Sq(&S, &e);
				
				if(!Matching(e, s[i]))
					return ERROR;				
				break;
		}
		
		i++;
	}
	
	if(StackEmpty_Sq(S))
		return OK;
	else
		return ERROR;
}

Status Matching(char a, char b)			//�жϲ�����a�����ȼ��Ƿ����b 
{
	switch(a)
	{
		case '(':
			if(b!=')')
				return ERROR;
			break;
			
		case '[':
			if(b!=']')
				return ERROR;
			break;
			
		case '{':
			if(b!='}')
				return ERROR;
			break;
			
		default:
			return ERROR;	
	}
	
	return OK;
}
