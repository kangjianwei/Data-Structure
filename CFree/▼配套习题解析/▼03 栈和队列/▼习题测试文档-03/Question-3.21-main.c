#include <stdio.h>		
#include <ctype.h>										//提供isalpha原型 
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"  //**▲03 栈和队列**//

/* 函数原型 */
void Algo_3_21(char *s, char c[]);
Status Priority(char a, char b);

int main(int argc, char *argv[])
{
	char *s = "a+b*c-d/e";
	char c[100];
	
	printf("中缀表达式为：");
	printf("%s\n",s);
	printf("\n");
		
	Algo_3_21(s, c);
	printf("生成的后缀表达式：");
	printf("%s\n",c);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━┓
┃题3.21：中缀式变后缀式┃
┗━━━━━━━━━━━*/
/* 逆波兰式：即后缀表达式，将运算符写在操作数之后 */
/* 如"a+b*c-d/e"将转化为："abc*+de/-" */
/* 假设表达式变量为单字母，操作符只有'+'、'-'、'*'、'/' */
void Algo_3_21(char *s, char c[])	//用一个足够大的数组暂存逆波兰式
{						
	int i, j; 
	SqStack S;						//栈中临时存储操作符 
	SElemType_Sq e;					//SElemType被定义char类型，char和int类型可直接比较 
	
	InitStack_Sq(&S);
	i = j = 0;
	
	while(s[i]!='\0')
	{
		if(isalpha(s[i]))			//读到单字母
			c[j++] = s[i];			//字母直接送入数组 
		else						//读到的是运算符 
		{
			while(!StackEmpty_Sq(S))
			{
				GetTop_Sq(S, &e);	//获取栈顶元素
				
				if(Priority(e, s[i]))//栈中运算符优先级高 
				{
					Pop_Sq(&S, &e);	//将栈中优先级高的运算符送入数组 
					c[j++] = e;
				}
				else				//遇到栈中运算符优先级低时，结束循环 
					break;	
			}	
	
			Push_Sq(&S, s[i]);	  	//将读取到的优先级小的字符压入栈
		}
		
		i++;						//继续读取 
	}
	
	while(!StackEmpty_Sq(S))
	{
		Pop_Sq(&S, &e);
		c[j++] = e;		
	}
	
	c[j] = '\0';					//数组中转换后的逆波兰式以"\0"标记结束 
}

/* 比较运算符a、b的优先级 */ 
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
