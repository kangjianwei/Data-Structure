/**************************************
 *                                    *
 * 文件夹: ▲03 栈和队列\07 LinkQueue *
 *                                    *
 * 内  容: 链队相关函数测试           *
 *                                    *
 *************************************/

#include <stdio.h>
#include "LinkQueue.c" 		//**03 栈和队列**//
	
void PrintElem(QElemType_L e);						//测试函数，打印整型 
	
int main(int argc, char **argv)
{
	LinkQueue Q;
	int i;
	QElemType_L e;
	
	printf("▼1\n▲函数 InitQueue_L 测试...\n");	//1.函数InitQueue_L测试
	{
		printf("初始化链队 Q ...\n");					 
		InitQueue_L(&Q);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼4\n▲函数 QueueEmpty_L 测试...\n");	//4.函数QueueEmpty_L测试
	{
		QueueEmpty_L(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("▼7\n▲函数 EnQueue_L 测试...\n");		//7.函数EnQueue_L测试
	{
		for(i=1; i<=6; i++)									
		{
			printf("元素 \"%2d\" 入队，", 2*i);
			EnQueue_L(&Q, 2*i);
			printf("（累计第 %d 个元素）...\n", QueueLength_L(Q));
		}
		printf("\n");
	} 
	PressEnter;
	
	printf("▼9\n▲函数 QueueTraverse_L 测试...\n");//9.函数QueueTraverse_L测试
	{
		printf(" Q 中的元素为：Q = ");						 
		QueueTraverse_L(Q, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼8\n▲函数 DeQueue_L 测试...\n");		//8.函数DeQueue_L测试
	{
		DeQueue_L(&Q, &e);
		printf("队头元素 \"%d\" 出队...\n", e);
		printf(" Q 中的元素为：Q = ");						 
		QueueTraverse_L(Q, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼5\n▲函数 QueueLength_L 测试...\n");	//5.函数QueueLength_L测试
	{
		i = QueueLength_L(Q);
		printf(" Q 的长度为 %d \n", i);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼6\n▲函数 GetHead_L 测试...\n");		//6.函数GetHead_L测试
	{
		GetHead_L(Q, &e);
		printf("队头元素的值为 \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼3\n▲函数 ClearQueue_L 测试...\n");	//3.函数ClearQueue_L测试
	{
		printf("清空 Q 前：");
		QueueEmpty_L(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		ClearQueue_L(&Q);
		printf("清空 Q 后：");
		QueueEmpty_L(Q) ? printf(" Q 为空！！\n") : printf(" Q 不为空！\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("▼2\n▲函数 DestroyQueue_L 测试...\n");	//2.函数DestroyQueue_L测试
	{
		printf("销毁 Q 前：");
		Q.front!=NULL && Q.rear!=NULL ? printf(" Q 存在！\n") : printf(" Q 不存在！！\n");
		DestroyQueue_L(&Q);
		printf("销毁 Q 后：");
		Q.front!=NULL && Q.rear!=NULL ? printf(" Q 存在！\n") : printf(" Q 不存在！！\n");
		printf("\n");
	} 
	PressEnter;
		
	return 0;
}

void PrintElem(QElemType_L e)
{
	printf("%d ", e);
}
