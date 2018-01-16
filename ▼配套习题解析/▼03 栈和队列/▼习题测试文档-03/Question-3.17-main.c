#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"  //**▲03 栈和队列**//

/* 函数原型 */
Status Algo_3_17(char *s);

int main(int argc, char *argv[])
{
	char *s = "a+b-c&c-b+a@"; 
	
	printf("判断序列 %s 是否合规...\n\n", s);
	if(Algo_3_17(s))
		printf("序列满足题意！\n");
	else
		printf("序列不满足题意！！\n");

	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题3.17：判定输入序列是否为'序列1&序列2'的模式，且序列2为序列1的逆置 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
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
	
	if(StackEmpty_Sq(S) && s[i]=='@')			//栈为空，且序列访问完 
		return OK;
	else
		return ERROR;
}
