#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/01 SequenceStack/SequenceStack.c"  //**��03 ջ�Ͷ���**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/07 LinkQueue/LinkQueue.c"  //**��03 ջ�Ͷ���**//

/* ����ԭ�� */
Status Algo_3_31(char c[]);

int main(int argc, char *argv[])
{
	char *a = "abcdedcba@";
	char *b = "ababab@";
	
	if(Algo_3_31(a))
		printf("%s��������@���ǻ������У�\n", a);
	else
		printf("%s��������@�����ǻ������У���\n", a);
	printf("\n");
	
	if(Algo_3_31(b))
		printf("%s��������@���ǻ������У�\n", b);
	else
		printf("%s��������@�����ǻ������У���\n", b);
	printf("\n");

	return 0;
}

/*����������������������������������
����3.31���ж�����c�Ƿ�Ϊ�������� ��
����������������������������������*/
Status Algo_3_31(char c[])
{
	SqStack S;
	LinkQueue Q;
	SElemType_Sq e1;
	QElemType_L e2;
	int i;
	
	InitStack_Sq(&S);
	InitQueue_L(&Q);
	
	for(i=0; c[i]!='@'; i++)		//���ַ�����ջ�Ͷ���
	{
		Push_Sq(&S, c[i]);
		EnQueue_L(&Q, c[i]);
	}
	
	while(!StackEmpty_Sq(S) && !QueueEmpty_L(Q))
	{
		Pop_Sq(&S, &e1);
		DeQueue_L(&Q, &e2);
		if(e1!=e2)
			return ERROR;
	}
	
	if(StackEmpty_Sq(S) && QueueEmpty_L(Q))
		return OK;
}
