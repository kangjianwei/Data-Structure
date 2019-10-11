#include <stdio.h>
#include <stdlib.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"

/* 宏定义 */
#define MAX 1000

/* 类型定义 */
typedef struct Block
{
	int tag;					//0代表空闲，1代表占用 
	int cellsize;				//分配的块大小
	struct Block *next;			//指向下一个空闲块
}Block;
typedef struct
{
	Block *lowbound;
	Block *highbound;
}Memory;

/* 全局变量 */
Memory Space;
Block *Heap;

/* 函数原型 */
void Algo_8_15();
void InitSpace();				//初始化内存空间
Block* MallocSpace(int n);		//分配大小为n的内存块 
void FreeSpace(Block *p);		//回收p指向的内存块 
void PrintLayout();				//输出内存占用情况 

int main(int argc, char *argv[])
{
	Block *p1, *p2, *p3, *p4, *p5, *p6;

	printf("初始化内存空间...\n");	
	InitSpace();
	PrintLayout();
	printf("\n");
	
	printf("分配 %d 个内存块 p1\n", 200); 
	p1 = MallocSpace(200);
	PrintLayout();	
	printf("\n");

	printf("分配 %d 个内存块 p2\n", 200); 		
	p2 = MallocSpace(200);
	PrintLayout();
	printf("\n");

	printf("分配 %d 个内存块 p3\n", 200); 			
	p3 = MallocSpace(200);
	PrintLayout();
	printf("\n");

	printf("分配 %d 个内存块 p4\n", 300); 				
	p4 = MallocSpace(300);
	PrintLayout();
	printf("\n");

	printf("回收大小为 %d 的内存块 p1\n", 200);		
	FreeSpace(p1);
	PrintLayout();	
	printf("\n");

	printf("回收大小为 %d 的内存块 p3\n", 200);			
	FreeSpace(p3);
	PrintLayout();	
	printf("\n");
	
	printf("整理内存，回收碎片...\n");		
	Algo_8_15();
	PrintLayout();
	printf("\n");

	printf("回收大小为 %d 的内存块 p5\n", 300);			
	p5 = MallocSpace(300);
	PrintLayout();	
	printf("\n");

	printf("回收大小为 %d 的内存块 p2\n", 200);			
	FreeSpace(p2);
	PrintLayout();
	printf("\n");
		
	printf("回收大小为 %d 的内存块 p6\n", 200);	
	p6 = MallocSpace(200);
	PrintLayout();
	printf("\n");

	printf("回收大小为 %d 的内存块 p4\n", 300);			
	FreeSpace(p4);
	PrintLayout();
	printf("\n");

	printf("整理内存，回收碎片...\n");			
	Algo_8_15();
	PrintLayout();
	printf("\n");
										
	return 0;
}

/*━━━━━━━━━┓
┃题8.15：堆内存回收┃
┗━━━━━━━━━*/
void Algo_8_15()
{
	Block *p, *q;
	int count, k;
	
	for(p=Space.lowbound,count=0,Heap=NULL; p<=Space.highbound; p++)
	{
		if(p->tag==0)				//遇到碎片或者未使用的空间则回收到一起 
		{
			count++;
			if(!Heap)
				Heap = q = p;
			else
			{
				q->next = p;
				q = q->next;			
			}
		}
	}
	
	q->next = NULL;
	Heap->cellsize = count;
}

void InitSpace()				//初始化内存空间
{
	Block *pre, *p;
	
	Space.lowbound = (Block *)malloc(MAX*sizeof(Block));
	Space.highbound = Space.lowbound + MAX - 1;
	
	Heap = Space.lowbound;
	Heap->cellsize = MAX;
	
	pre=Space.lowbound;
	pre->tag = 0;
	if(MAX>1)
	{
		for(p=pre+1; p<=Space.highbound; p++,pre++)
		{
			p->tag = 0;
			pre->next = p;
		}
	}
	pre->next = NULL;
}

Block* MallocSpace(int n)
{
	Block *p, *q;
	int count;
	
	if(!Heap || Heap->cellsize<n)		//内存已不足 
		return NULL;
	
	p = q = Heap;
	
	for(count=1; count<n; count++)
	{
		q->tag = 1;
		q = q->next;
	}
	
	Heap = q->next;
	if(Heap)
		Heap->cellsize = p->cellsize - n;
	
	q->tag = 1;
	q->next = NULL;
	p->cellsize = n;
	
	return p;
}

void FreeSpace(Block *p)
{
	Block *r = p;
		
	while(r)
	{
		r->tag = 0;
		r = r->next; 
	}
}

void PrintLayout()
{
	int x, y, z, k;
	Block *p, *q;
	
	if(Heap)
		x = Heap->cellsize;				//空闲内存块数 					
	else
		x = 0;
		
	for(p=Space.lowbound,y=0; p<=Space.highbound; p++)
	{
		if(p->tag==1)				//统计被占用的内存块 
			y++;
	}
	
	z = MAX - x - y;				//统计碎片数
	
	printf("已用空间 %4d，未用空间 %4d，碎片数 %4d，内存总空间 %4d。\n", y, x, z, MAX);
}
