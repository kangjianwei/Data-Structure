/***************************************
 *				                       *
 * 文件夹: ▲07 图\07 MiniSpanningTree *
 * 				                       *
 * 文件名: MST-main.c                  *
 *				                       *
 * 内  容: 最小生成树相关函数测试      *
 *				                       *
 ***************************************/

#include <stdio.h>
#include "MST.c" 												//**▲07 图**//													

int main(int argc, char *argv[])
{
	MGraph G;

	printf("初始化并输出无向网...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_UDN_M.txt", "r");	
		CreateGraph_M(fp, &G); 
		fclose(fp);
		OutputMGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("▼1、2\n▲函数 MinSpanTree_PRIM_1等 测试...\n");		//1、2.函数MinSpanTree_PRIM_1等测试
	{
		printf("普里姆算法...\n");	
		printf("先后加入最小生成树的各结点及其对应的最小边的权值分别为：\n");
		MinSpanTree_PRIM_1(G, 'A');
		printf("\n");
	} 
	PressEnter;

	printf("▼3、4\n▲函数 MinSpanTree_PRIM_2等 测试...\n");		//3、4.函数MinSpanTree_PRIM_2等测试
	{
		printf("普里姆算法...\n");			
		printf("最小生成树的各边及其对应的权值分别为：\n");	
		MinSpanTree_PRIM_2(G, 'A');
		printf("\n");
	} 
	PressEnter;

	printf("▼5、6、7、8\n▲函数 MinSpanTree_KRUSKAL等 测试...\n");//5、6、7、8.函数MinSpanTree_KRUSKAL等测试	
	{
		printf("克鲁斯卡尔算法...\n");	
		printf("最小生成树的各边及其对应的权值分别为：\n");		
		MinSpanTree_KRUSKAL(G);
		printf("\n");
	}
	PressEnter;
}
