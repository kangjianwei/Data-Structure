/****************************************
 *                                      *
 * 文件夹: ▲03 栈和队列\08 CylSeqQueue *
 *                                      *
 * 内  容: 循环队列相关函数测试         *
 *                                      *
 ****************************************/

#include <stdio.h>
#include "CylSeqQueue.c"	//**▲03 栈和队列**//
	
void PrintElem(QElemType_CSq e);						//测试函数，打印整型 
	
int main(int argc, char **argv)
{
	CSqQueue Q;
	int i;
	QElemType_CSq e;
	
	printf("▼1\n▲函数 InitQueue_CSq 测试...\n");		//1.函数InitQueue_CSq测试
	{
		printf("初始化循环顺序队列 Q ...\n");					 
		InitQueue_CSq(&Q);
		printf("\n");
	}
	PressEnter;
	
	printf("▼4\n▲函数 QueueEmpty_CSq 测试...\n");		//4.函数QueueEmpty_CSq测试
	{
		QueueEmpty_CSq(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼7\n▲函数 EnQueue_CSq 测试...\n");		//7.函数EnQueue_CSq测试
	{
		for(i=1; i<=6; i++)									
		{
			printf("元素 \"%2d\" 入队Q，", 2*i);
			EnQueue_CSq(&Q, 2*i);
			printf("（累计第 %d 个元素）...\n", QueueLength_CSq(Q));
		}
		printf("\n");
	}
	PressEnter;
	
	printf("▼9\n▲函数 QueueTraverse_CSq 测试...\n");	//9.函数QueueTraverse_CSq测试
	{
		printf(" Q 中的元素为：Q = ");						 
		QueueTraverse_CSq(Q, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼8\n▲函数 DeQueue_CSq 测试...\n");		//8.函数DeQueue_CSq测试
	{
		DeQueue_CSq(&Q, &e);
		printf("队头元素 \"%d\" 出队...\n", e);
		printf(" Q 中的元素为：Q = ");						 
		QueueTraverse_CSq(Q, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼5\n▲函数 QueueLength_CSq 测试...\n");	//5.函数QueueLength_CSq测试
	{
		i = QueueLength_CSq(Q);
		printf(" Q 的长度为 %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("▼6\n▲函数 GetHead_CSq 测试...\n");		//6.函数GetHead_CSq测试
	{
		GetHead_CSq(Q, &e);
		printf("队头元素的值为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("▼3\n▲函数 ClearQueue_CSq 测试...\n");		//3.函数ClearQueue_CSq测试
	{
		printf("清空 Q 前：");
		QueueEmpty_CSq(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		ClearQueue_CSq(&Q);
		printf("清空 Q 后：");
		QueueEmpty_CSq(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼2\n▲函数 DestroyQueue_CSq 测试...\n");	//2.函数DestroyQueue_CSq测试
	{
		printf("销毁 Q 前：");
		Q.base!=NULL ? printf(" Q 存在！\n") : printf(" Q 不存在！！\n");
		DestroyQueue_CSq(&Q);
		printf("销毁 Q 后：");
		Q.base!=NULL ? printf(" Q 存在！\n") : printf(" Q 不存在！！\n");
		printf("\n");
	}
	PressEnter;
		
	return 0;
}

void PrintElem(QElemType_CSq e)
{
	printf("%d ", e);
}
