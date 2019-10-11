/******************************************
 *							  			  *
 * 文件夹: ▲03 栈和队列\01 SequenceStack *
 * 							  			  *
 * 文件名: SequenceStack.c    			  *
 *                            			  *
 ******************************************/

#ifndef SEQUENCESTACK_C
#define SEQUENCESTACK_C

#include "SequenceStack.h" 						//**▲03 栈和队列**//

Status InitStack_Sq(SqStack *S)
{
 	(*S).base = (SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));
	if(!(*S).base)
		exit(OVERFLOW);
		
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	
	return OK;
} 

Status DestroyStack_Sq(SqStack *S)
{
	free((*S).base);
	
	(*S).base = NULL;
	(*S).top = NULL;
	(*S).stacksize = 0;
	
	return OK;
} 

Status ClearStack_Sq(SqStack *S)
{
	(*S).top = (*S).base;
	
	return OK;
} 

Status StackEmpty_Sq(SqStack S)
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
} 

int StackLength_Sq(SqStack S)
{
	return S.top - S.base;
} 

Status GetTop_Sq(SqStack S, SElemType_Sq *e)
{
	if(S.top==S.base)
		return ERROR;
		
	*e = *(S.top - 1);							//并不破坏栈 
	
	return OK;

} 

Status Push_Sq(SqStack *S, SElemType_Sq e)
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

Status Pop_Sq(SqStack *S, SElemType_Sq *e)
{
	if((*S).top==(*S).base)
		return ERROR;

	(*S).top--;									//出栈栈顶指针先递减，再赋值 
	*e = *((*S).top);

	return OK;
} 

Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq))
{												//遍历不应该破坏栈 
	SElemType_Sq *p = S.base;
	
	while(p<S.top)
		Visit(*p++);
	
	return OK;
} 

#endif
