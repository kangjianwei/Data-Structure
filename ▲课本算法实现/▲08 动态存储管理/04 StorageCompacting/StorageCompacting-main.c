/************************************
 *						            *
 * 文件夹: ▲08 动态存储管理        *
 * 						            *
 * 文件名: StorageCompacting-main.c *
 * 							        *
 * 内  容: 存储紧缩相关函数测试     *
 *                                  *
 ************************************/

#include <stdio.h> 
#include "StorageCompacting.c" 									//**▲08 动态存储管理**//

int main(int argc, char *argv[])
{
	int *p1, *p4;
	char *p2, *p5;
	float *p3;

	printf("▼1\n▲函数 InitMemory 测试...\n");					//1.函数InitMemory测试	
	{
		printf("初始化一块大小为 %d 的内存...\n", MAX);
		InitMemory(MAX);
		printf("\n");
	}
	PressEnter;

	printf("▼5\n▲函数 PrintLayout 测试...\n");					//5.函数PrintLayout测试	
	{
		printf("输出当前内存分配情况...\n");
		PrintLayout();
		printf("\n");
	} 
	PressEnter;

	printf("▼2、3\n▲函数 MallocMemory、CompressMemory 测试...\n");//2、3.函数MallocMemory、CompressMemory测试		
	{
		printf("申请大小为 %d 的内存块 p1...\n", 100*sizeof(int));		
		p1 = (int*)MallocMemory(100*sizeof(int));
		PrintLayout();	
		printf("\n");
		PressEnter;

		printf("申请大小为 %d 的内存块 p2...\n", 100*sizeof(char));		
		p2 = (char*)MallocMemory(100*sizeof(char));
		PrintLayout();
		printf("\n");
		PressEnter;

		printf("申请大小为 %d 的内存块 p3...\n", 100*sizeof(float));	
		p3 = (float*)MallocMemory(100*sizeof(float));
		PrintLayout();
		printf("\n");
	} 
	PressEnter;

	printf("▼4\n▲函数 FreeMemory 测试...\n");					//4.函数FreeMemory测试
	{
		printf("释放 p2 指向的内存块...\n");	
		FreeMemory(p2);
		PrintLayout();
		printf("\n"); 
		PressEnter;

		printf("申请大小为 %d 的内存块 p5...\n", 200*sizeof(char));	
		p5 = (char*)MallocMemory(200*sizeof(char));
		PrintLayout();			
		printf("\n");
		PressEnter;

		printf("申请大小为 %d 的内存块 p4...\n", sizeof(int));	
		p4 = (int*)MallocMemory(100*sizeof(int));
		PrintLayout();
		printf("\n");
	} 
	PressEnter;
		
	return 0;
}

