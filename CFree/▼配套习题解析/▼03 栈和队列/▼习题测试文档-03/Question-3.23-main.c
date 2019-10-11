#include <stdio.h>
#include <stdlib.h>							//提供malloc、realloc、free、exit原型
#include <string.h>
#include <ctype.h>												//提供isalpha原型 
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  			//**▲01 绪论**//

/* 宏定义 */
#define STACK_INIT_SIZE	100				//顺序栈存储空间的初始分配量
#define STACKINCREMENT	10 				//顺序栈存储空间的分配增量

/* 类型定义 */
typedef char* SElemType_Sq;
typedef struct
{
	SElemType_Sq	*base;				//在栈构造之前和销毁之后，base的值为NULL 
	SElemType_Sq	*top;				//栈顶指针 
	int			stacksize;				//当前已分配的存储空间，以元素为单位 
}SqStack;

/* 函数原型 */
char* Algo_3_23(char *c);
Status InitStack(SqStack *S);			//初始化栈
Status StackEmpty(SqStack S);			//判断栈是否为空 
Status Push(SqStack *S, SElemType_Sq e);//入栈
Status Pop(SqStack *S, SElemType_Sq *e);//出栈 
char* CharToStr(char c);				//字符转换为字符串 
char* StrCohere(char *a, char* b);		//拼接字符串a和b

int main(int argc, char *argv[])
{
	char *s = "abc*+de/-";
	
	printf("后缀表达式为：");
	printf("%s\n", s);
	printf("前缀表达式为：");
	printf("%s\n", Algo_3_23(s));
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━┓
┃题3.23：后缀式变前缀式┃
┗━━━━━━━━━━━*/
char* Algo_3_23(char *c)
{
	int len, i, j;
	char *s, *e1, *e2;
	SqStack S;
	
	InitStack(&S);
	
	for(i=0; c[i]; i++)
	{
		s = CharToStr(c[i]);
		
		if(!isalpha(c[i]))		//若c[i]为操作符，则栈中至少有两个“字符”			
		{
			if(Pop(&S, &e2) && Pop(&S, &e1)) 	
				s = StrCohere(s, StrCohere(e1, e2));
			else
				return NULL;
		}
		
		Push(&S, s);
	}
	
	Pop(&S, &s);
	
	if(StackEmpty(S))	
		return s;
	else
		return NULL;
}

Status InitStack(SqStack *S)
{
 	(*S).base = (SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));
	if(!(*S).base)
		exit(OVERFLOW);
		
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	
	return OK;
}

Status StackEmpty(SqStack S)
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}

Status Push(SqStack *S, SElemType_Sq e)
{
	if((*S).top-(*S).base>=(*S).stacksize)		//栈满，追加存储空间
	{
		(*S).base = (SElemType_Sq *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
		if(!(*S).base)
			exit(OVERFLOW);						//存储分配失败
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	
	*(S->top) = e;								//进栈先赋值，栈顶指针再自增 
	(S->top)++;

	return OK;
} 

Status Pop(SqStack *S, SElemType_Sq *e)
{
	if((*S).top==(*S).base)
		return ERROR;

	(*S).top--;									//出栈栈顶指针先递减，再赋值 
	*e = *((*S).top);

	return OK;
}

char* CharToStr(char c)							//字符转换为字符串 
{
	char *s;
	
	s = (char*)malloc(2*sizeof(char));
	if(!s)
		exit(OVERFLOW);
			
	s[0] = c;
	s[1] = '\0';
	
	return s;
}

char* StrCohere(char *a, char* b)				//拼接字符串a和b 
{
	char *s;
	int i, j, alen, blen;
	
	alen = strlen(a);
	blen = strlen(b);
	
	s = (char*)malloc((alen+blen+1)*sizeof(char));
	if(!s)
		exit(OVERFLOW);
	
	j = 0;
	for(i=0; i<alen; i++)
		s[j++] = a[i];
	
	for(i=0; i<blen; i++)
		s[j++] = b[i];
	
	s[j] = '\0';
	
	return s;	
}
