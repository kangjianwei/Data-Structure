#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/01 SequenceStack/SequenceStack.c"  //**��03 ջ�Ͷ���**//

/* ����ԭ�� */
Status Algo_3_17(char *s);

int main(int argc, char *argv[])
{
	char *s = "a+b-c&c-b+a@"; 
	
	printf("�ж����� %s �Ƿ�Ϲ�...\n\n", s);
	if(Algo_3_17(s))
		printf("�����������⣡\n");
	else
		printf("���в��������⣡��\n");

	printf("\n");
	
	return 0;
}

/*����������������������������������������������������������������������
����3.17���ж����������Ƿ�Ϊ'����1&����2'��ģʽ��������2Ϊ����1������ ��
����������������������������������������������������������������������*/
Status Algo_3_17(char *s)
{
	SqStack S;
	SElemType_Sq e;
	int i;
	
	InitStack_Sq(&S);
	i = 0;
		
	while(s[i]!='@' && s[i]!='&')
	{
		Push_Sq(&S, s[i]);
		i++;
	}
	
	if(s[i]!='@')
	{
		i++;
		while(!StackEmpty_Sq(S) && s[i]!='@')
		{
			Pop_Sq(&S, &e);
			if(s[i]!=e)
				return ERROR;
			i++;	
		}
	}
	
	if(StackEmpty_Sq(S) && s[i]=='@')			//ջΪ�գ������з����� 
		return OK;
	else
		return ERROR;
}
