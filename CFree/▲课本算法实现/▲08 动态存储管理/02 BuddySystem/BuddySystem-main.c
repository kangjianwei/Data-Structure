/********************************
 *						        *
 * 文件夹: ▲08 动态存储管理    *
 * 						        *
 * 文件名: BuddySystem-main.c   *
 * 							    *
 * 内  容: 伙伴系统相关函数测试 *
 *                              *
 ********************************/

#include <stdio.h>
#include "BuddySystem.c" 									//**▲08 动态存储管理**//

int main(int argc, char *argv[])
{	
	FreeList avail;
	WORD_b *p1, *p2, *p3, *p4;

	printf("▼1、5\n▲函数 InitSpace_b等 测试...\n");			//1、5.函数InitSpace_b、PrintLayout_b测试
	{
		printf("初始化一个内存块 ：");	
		InitSpace_b(avail);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;

	printf("▼2\n▲函数 AllocBuddy 测试...\n");				//2.函数AllocBuddy测试	
	{
		printf("申请大小为 1 的内存块 p1 后...\n");	
		p1 = AllocBuddy(avail, 1);
		PrintLayout_b(avail);
		printf("\n");
	}
	PressEnter;
	
	printf("申请大小为 2 的内存块 p2 后...\n");
	{
		p2 = AllocBuddy(avail, 2);
		PrintLayout_b(avail);
		printf("\n");
	}
	PressEnter;
	
	printf("申请大小为 3 的内存块 p3 后...\n");
	{
		p3 = AllocBuddy(avail, 3);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;
	
	printf("申请大小为 1 的内存块 p4 后...\n");
	{
		p4 = AllocBuddy(avail, 1);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;

	printf("▼3、4\n▲函数 Reclaim_b等 测试...\n");			//3、4.函数Buddy、Reclaim_b测试	
	{
		printf("回收内存块 p1 后...\n");	
		Reclaim_b(avail, &p1);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;
	
	printf("回收内存块 p2 后...\n");
	{
		Reclaim_b(avail, &p2);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;
	
	printf("回收内存块 p3 后...\n");
	{
		Reclaim_b(avail, &p3);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;
	
	printf("回收内存块 p4 后...\n");
	{
		Reclaim_b(avail, &p4);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;
			
	return 0;
}

