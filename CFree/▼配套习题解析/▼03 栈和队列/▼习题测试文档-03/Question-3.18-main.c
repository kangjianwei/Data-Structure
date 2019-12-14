#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"  //**▲03 栈和队列**//

/* 函数原型 */
Status Algo_3_18(char *s);

int main(int argc, char *argv[])
{
	char *s = "(1+2)*3/{2/[(4-5)*3]-5*(8-7)}"; 
		
	printf("判断表达式 %s 开闭括号数量是否匹配...\n", s);
	if(Algo_3_18(s))
		printf("表达式开闭括号数量匹配！\n");
	else
		printf("表达式开闭括号数量不匹配！！\n");

	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━┓
┃题3.18：判定表达式开闭括号是否配对出现┃
┗━━━━━━━━━━━━━━━━━━━*/ 
/* 不考虑括号是否正确配对 */
Status Algo_3_18(char *s)
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
				break;
		}
		
		i++;
	}
	
	if(StackEmpty_Sq(S))
		return OK;
	else
		return ERROR;
}
