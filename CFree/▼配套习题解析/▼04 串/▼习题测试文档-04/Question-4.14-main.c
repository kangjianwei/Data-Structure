#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/01 SequenceList/SequenceList.c"	//**▲02 线性表**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"	//**▲04 串**//

/* 宏定义 */
#define STACK_INIT_SIZE	100				//顺序栈存储空间的初始分配量
#define STACKINCREMENT	10 				//顺序栈存储空间的分配增量	

/* 类型定义 */
typedef SString SElemType;				//栈元素类型为字符串数组
typedef struct							//栈结构类型
{
	SElemType	*base;					//在栈构造之前和销毁之后，base的值为NULL 
	SElemType	*top;					//栈顶指针 
	int			stacksize;				//当前已分配的存储空间，以元素为单位 
}SqStack;

/* 函数原型 */
Status InitStack_4_14(SqStack *S);					//字符串栈的初始化
Status Push_4_14(SqStack *S, SElemType e); 			//入栈
Status Pop_4_14(SqStack *S, SElemType *e);			//出栈 
Status Algo_4_14(SqList P, SString Str);

int main(int argc, char *argv[])
{
	char *p = "-+a*bc/de";			//后缀：abc*+de/-
	int i;
	SqList P;
	SString Str;
	
	InitList_Sq(&P);
	for(i=1; i<=strlen(p); i++)
		ListInsert_Sq(&P, i, p[i-1]);
	printf("前缀表达式：P   = ");
	for(i=0; i<P.length; i++)
		printf("%c", P.elem[i]);
	printf("\n\n");
	
	Algo_4_14(P, Str);	
	printf("后缀表达式：Str = ");	
	StrPrint_Sq(Str);
	printf("\n\n");	
	
	return 0;
}

/*━━━━━━━━━━━┓
┃题4.14：前缀式变后缀式┃
┗━━━━━━━━━━━*/
/* 假设表达式变量均为单字符 */
Status Algo_4_14(SqList P, SString Str)
{
	int i;
	SElemType e1, e2, tmp;
	SqStack S;
	
	InitStack_4_14(&S);
	
	for(i=P.length-1; i>=0; i--)		//从后往前读取 
	{
		tmp[0] = 1;
		tmp[1] = P.elem[i];
		
		if(isalpha(P.elem[i]))			//遇到变量入栈 
			Push_4_14(&S, tmp);
		else
		{
			Pop_4_14(&S, &e1);			//遇到操作符连续出栈 
			Pop_4_14(&S, &e2);

			Concat_Sq(e1, e1, e2);		//将出栈的两个变量与操作符正确连接	
			Concat_Sq(e1, e1, tmp);

			Push_4_14(&S, e1);			//连接好的字符串入栈 
		}	
	}
	
	Pop_4_14(&S, &tmp);					//弹出转换完成后的字符串 
	StrCopy_Sq(Str, tmp);	
	
	if(S.base==S.top)					//最后栈应该为空 
		return OK;
	else
		return ERROR;
}

Status InitStack_4_14(SqStack *S)
{
 	(*S).base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!(*S).base)
		exit(OVERFLOW);
		
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	
	return OK;
}

Status Push_4_14(SqStack *S, SElemType e)
{
	int i;
	
	if((*S).top-(*S).base>=(*S).stacksize)		//栈满，追加存储空间
	{
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!(*S).base)
			exit(OVERFLOW);						//存储分配失败
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	
	for(i=0; i<=e[0]; i++)
		(*(S->top))[i] = e[i];					//进栈先赋值，栈顶指针再自增 

	(S->top)++;

	return OK;
} 

Status Pop_4_14(SqStack *S, SElemType *e)
{
	int i;
	
	if((*S).top==(*S).base)
		return ERROR;
	
	(*S).top--;									//出栈栈顶指针先递减，再赋值
	
	for(i=0; i<=(*((*S).top))[0]; i++)
		(*e)[i] = (*((*S).top))[i];
	
	return OK;
}
