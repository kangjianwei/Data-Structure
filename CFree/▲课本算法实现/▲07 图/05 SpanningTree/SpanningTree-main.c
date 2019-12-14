/************************************
 *                                  *
 * 文件夹: ▲07 图\05 SpanningTree  *
 *                                  *
 * 文件名: SpanningTree-main.c      *
 * 							        *
 * 内  容: 无向图生成树相关函数测试 *
 *                                  *
 ************************************/

#include <stdio.h>
#include "SpanningTree.c"											

int main(int argc, char *argv[])
{
	MGraph G;
			
	printf("创建并输出无向图（数组表示法）...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_UDG_M.txt", "r");	
		CreateGraph_M(fp, &G); 
		fclose(fp);
		OutputMGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("▼1、2\n▲函数 DFSForest等 测试...\n");		//1、2.函数DFSForest等测试
	{
		CSTree T;
		
		printf("创建并输出无向图的生成树（森林）...\n");		
		DFSForest(G, &T);
		Print_CS(T);
		printf("\n");
	}
	PressEnter;

	return 0;
}
