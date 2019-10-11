#ifndef Question_8
#define Question_8

#include <stdio.h>

/* 宏定义 */
#define MAX 1000

/* 类型定义 */
typedef struct
{
	int origin;						//申请的内存块起始地址 
	int size;						//申请的内存块大小 
}FreeBlock;							//内存块信息 
typedef FreeBlock SElemType_Sq;
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"	//**▲03 栈和队列**//

/* 全局变量 */
SqStack S;			//存放内存信息 
struct
{
	int start;		//内存空间起点 
	int end;		//内存空间终点 
	int cur;		//当前空闲内存块起点 
}Space;				//内存空间 

/* 函数原型 */ 
int Algo_8_11(int n);			//申请大小为n的内存块，返回申请到的内存块地址 
Status Algo_8_12();				//释放内存空间 
void InitSpace();				//初始化内存空间及内存信息表
void PrintLayout();				//输出内存使用情况 

int main(int argc, char *argv[])
{
	printf("初始化 %d 个内存块作为存储空间...\n", MAX);
	InitSpace();
	PrintLayout();
	printf("\n");
	
	printf("申请 %d 个内存块...\n", 300);
	Algo_8_11(300);
	PrintLayout();
	printf("\n");

	printf("申请 %d 个内存块...\n", 400);	
	Algo_8_11(400);
	PrintLayout();	
	printf("\n");

	printf("申请 %d 个内存块...\n", 500);	
	Algo_8_11(500);
	PrintLayout();	
	printf("\n");
				
	return 0;
}
void InitSpace()
{
	void *p = malloc(MAX);
	
	Space.start = Space.cur = (int)p;
	Space.end = Space.start+MAX-1;
	
	InitStack_Sq(&S);
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题8.11：申请大小为n的内存块，返回申请到的内存块地址 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/
int Algo_8_11(int n)
{
	FreeBlock e;
	
	if(n>MAX)
		return 0;
	else
	{
		while(Space.end-Space.cur+1<n && Algo_8_12())	//若内存不够用，则释放一部分空间 
			;
		
		e.origin = Space.cur;
		e.size = n;
		
		Push_Sq(&S, e);
		
		Space.cur += n;
		
		return e.origin;
	}
}

/*━━━━━━━━━━┓
┃题8.12：释放内存空间┃
┗━━━━━━━━━━*/
Status Algo_8_12()
{
	SElemType_Sq e;
	
	if(!StackEmpty_Sq(S))
	{
		Pop_Sq(&S, &e);									//从内存信息表中删掉此内存块信息 
		Space.cur -= e.size;
		
		return OK;	
	}
	else
		return ERROR;
}

void PrintLayout()
{
	SElemType_Sq *k;
	int count;
	
	printf("已占用的内存块范围：┃");
	for(k=S.base,count=0; k<S.top; k++)
	{
		printf("%3d←→%3d┃", k->origin-Space.start, k->origin+k->size-Space.start-1);
		count += k->size;	
	}	
	printf("\n");
	
	printf("内存已占用块数：%4d，空闲块数：%4d。\n", count, MAX-count);		
}

#endif
