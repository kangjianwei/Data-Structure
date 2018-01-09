/************************************
 *						            *
 * 文件夹: ▲08 动态存储管理        *
 * 						            *
 * 文件名: BoundaryTagMethod-main.c *
 * 							        *
 * 内  容: 边界标识法相关函数测试   *
 *                                  *
 ************************************/

#include <stdio.h>
#include "BoundaryTagMethod.c" 									//**▲08 动态存储管理**//													

int main(int argc, char *argv[])
{	
	WORD_a memory[MAX];
	Space pav;						 
	Space p1, p2, p3, p4;

	printf("▼1、4\n▲函数 InitSpace_a等 测试...\n");				//1、4.函数InitSpace_a、PrintLayout_a测试	
	{
		printf("初始化一个内存块 ：");
		InitSpace_a(memory);
		pav = av;
		PrintLayout_a(av, pav);
		printf("\n");
	}	
	PressEnter; 

	printf("▼2\n▲函数 AllocBoundTag 测试...\n");				//2.函数AllocBoundTag测试		
	{
		printf("申请大小为 100 的内存块 p1 后...\n");
		p1 = AllocBoundTag(&pav, 100);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 

	printf("申请大小为 600 的内存块 p2 后...\n");	
	{
		p2 = AllocBoundTag(&pav, 600);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 

	printf("申请大小为 200 的内存块 p3 后...\n");
	{
		p3 = AllocBoundTag(&pav, 200);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 

	printf("▼3\n▲函数 Reclaim_a 测试...\n");					//3.函数Reclaim_a测试	
	{
		printf("回收大小为 600 的内存块 p2 后...\n");
		Reclaim_a(&pav, &p2);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 

	printf("申请大小为 400 的内存块 p4 后...\n");	
	{
		p4 = AllocBoundTag(&pav, 400);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 

	printf("回收大小为 100 的内存块 p1 后...\n");
	{
		Reclaim_a(&pav, &p1);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 
	
	printf("回收大小为 400 的内存块 p4 后...\n");
	{
		Reclaim_a(&pav, &p4);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 
			
	return 0;
}

