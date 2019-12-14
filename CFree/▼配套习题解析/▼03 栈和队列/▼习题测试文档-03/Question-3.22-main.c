#include <stdio.h>		
#include <ctype.h>										//提供isdigit原型 
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"  //**▲03 栈和队列**//

/* 函数原型 */
Status Algo_3_22(char c[], SElemType_Sq *Value);
char Operate(char a, char oper, char b);

int main(int argc, char *argv[])
{
	char c[] = "134*+62/-";
	SElemType_Sq value;
	
	printf("已知逆波兰式为：");
	printf("%s\n", c);
	Algo_3_22(c, &value);
	printf("逆波兰式的计算结果为：%d\n", value-48);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━┓
┃题3.22：对逆波兰表达式求值┃
┗━━━━━━━━━━━━━*/
/* 预设操作符为'+','-','*','/'，变量为单数字 */
Status Algo_3_22(char c[], SElemType_Sq *Value)
{
	int i;
	SqStack S;
	SElemType_Sq a, b;
	
	InitStack_Sq(&S);	
	i = 0;
	
	while(c[i])
	{		
		if(isdigit(c[i]))				//遇到数字
			Push_Sq(&S, c[i]);
		else
		{
			Pop_Sq(&S, &b);				//先弹出来的在操作数后边 
			Pop_Sq(&S, &a);
			Push_Sq(&S, Operate(a, c[i], b));
		}
		
		i++;		 
	} 
	
	Pop_Sq(&S, Value);

	if(!StackEmpty_Sq(S))
		return ERROR;
	else
		return OK;
}

/* 计算a<oper>b */
char Operate(char a, char oper, char b)
{
	char c;
	
	switch(oper)
	{
		case '+': c = (a-48)+(b-48)+48;
			break;
		case '-': c = (a-48)-(b-48)+48;
			break;
		case '*': c = (a-48)*(b-48)+48;
			break;
		case '/': c = (a-48)/(b-48)+48;
			break;
	}
	
	return c;
}
