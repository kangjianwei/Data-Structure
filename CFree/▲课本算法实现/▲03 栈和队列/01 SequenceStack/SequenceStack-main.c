/******************************************
 *						      			  *
 * 文件夹: ▲03 栈和队列\01 SequenceStack *
 * 						      			  *
 * 内  容: 顺序栈相关函数测试 			  *
 *                            			  *
 ******************************************/

#include <stdio.h>
#include "SequenceStack.c" 								//**▲03 栈和队列**//
	
void PrintElem(SElemType_Sq e);
	//测试函数，打印整型 

int main(int argc, char **argv)
{
	SqStack S;
	int i;
	SElemType_Sq e;
	
	printf("▼1\n▲函数 InitStack 测试...\n");			//1.函数InitStack测试
	{
		printf("初始化顺序栈 S ...\n");					 
		InitStack_Sq(&S);
		printf("\n");
	}
	PressEnter;
	
	printf("▼4\n▲函数 StackEmpty 测试...\n");			//4.函数StackEmpty测试
	{
		StackEmpty_Sq(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼7\n▲函数 Push 测试...\n");					//7.函数Push测试
	{
		for(i=1; i<=6; i++)									
		{
			printf("将 \"%2d\" 压入栈 S ", 2*i);
			Push_Sq(&S, 2*i);
			printf("（累计第 %d 个元素）...\n", S.top-S.base);
		}
		printf("\n");
	}
	PressEnter;
	
	printf("▼9\n▲函数 StackTraverse 测试...\n");		//9.函数StackTraverse测试
	{
		printf(" S 中的元素为：S = ");						 
		StackTraverse_Sq(S, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼8\n▲函数 Pop 测试...\n");					//8.函数Pop测试
	{
		Pop_Sq(&S, &e);
		printf("栈顶元素 \"%d\" 出栈...\n", e);
		printf(" S 中的元素为：S = ");						 
		StackTraverse_Sq(S, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼5\n▲函数 StackLength 测试...\n");			//5.函数StackLength测试
	{
		i = StackLength_Sq(S);
		printf(" S 的长度为 %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("▼6\n▲函数 GetTop 测试...\n");				//6.函数GetTop测试
	{
		GetTop_Sq(S, &e);
		printf("栈顶元素的值为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("▼3\n▲函数 ClearStack 测试...\n");			//3.函数ClearStack测试
	{
		printf("清空 S 前：");
		StackEmpty_Sq(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		ClearStack_Sq(&S);
		printf("清空 S 后：");
		StackEmpty_Sq(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼2\n▲函数 DestroyStack 测试...\n");			//2.函数DestroyStack测试
	{
		printf("销毁 S 前：");
		S.base!=NULL && S.top!=NULL ? printf(" S 存在！\n") : printf(" S 不存在！！\n");
		DestroyStack_Sq(&S);
		printf("销毁 S 后：");
		S.base!=NULL && S.top!=NULL ? printf(" S 存在！\n") : printf(" S 不存在！！\n");
		printf("\n");
	}
	PressEnter;
		
	return 0;
}

void PrintElem(SElemType_Sq e)
{
	printf("%d ", e);
}
