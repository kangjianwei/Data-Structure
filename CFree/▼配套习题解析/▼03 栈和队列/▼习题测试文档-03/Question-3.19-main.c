#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"  //**▲03 栈和队列**//

/* 函数原型 */
Status Algo_3_19(char *s);
Status Matching(char a, char b)	;

int main(int argc, char *argv[])
{
	char *s = "(1+2)*3/{2/[(4-5)*3]-5*(8-7)}"; 
	
	printf("判断表达式 %s 括号是否匹配...\n", s);
	if(Algo_3_19(s))
		printf("表达式括号匹配！\n");
	else
		printf("表达式括号不匹配！！\n");

	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━┓
┃题3.19：判断表达式括号是否匹配┃
┗━━━━━━━━━━━━━━━*/
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

Status Matching(char a, char b)			//判断操作符a的优先级是否大于b 
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
