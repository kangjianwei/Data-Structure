/***********************************
 *						           *
 * 文件夹: ▲07 图\11 ShortestPath *
 * 						           *
 * 文件名: ShortestPath-main.c     *
 * 							       *
 * 内  容: 最短路径相关函数测试    *
 *                                 *
 ***********************************/

#include <stdio.h>
#include "ShortestPath.c" 						//**▲07 图**//

int main(int argc, char *argv[])
{
	MGraph G1, G2;	
	int v0 = 2;													//设置起点 
		
	printf("创建并输出有向网G1...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_DN_M_DIJ.txt", "r");
		CreateGraph_M(fp, &G1); 
		fclose(fp);
		OutputMGraph(G1);
		printf("\n");
	}
	PressEnter;	

	printf("▼1、2\n▲函数 ShortestPath_DIJ等 测试...\n");		//1、2.函数ShortestPath_DIJ等测试	
	{
		PathMatrix P1[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
		ShortPathTable D1[MAX_VERTEX_NUM+1];
		
		printf("计算并输出 %c 到其余各点的最短路径：\n", G1.vexs[v0]);
		ShortestPath_DIJ(G1, v0, P1, D1);
		OutputPath_DIJ(G1, v0, P1, D1);
		printf("\n");
	}
	PressEnter;		

	printf("▼3\n▲函数 Dijkstra 测试...\n");					//3.函数Dijkstra测试
	{
		PathMatrix path1[MAX_VERTEX_NUM+1];
		ShortPathTable dist1[MAX_VERTEX_NUM+1];
		
		printf("计算并输出 %c 到其余各点的最短路径：\n", G1.vexs[v0]);	
		Dijkstra(G1, v0, path1, dist1);
		printf("\n");
	}
	PressEnter;
	
	printf("创建并输出有向网G2...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_DN_M_Floyd.txt", "r");
		CreateGraph_M(fp, &G2); 
		fclose(fp);
		OutputMGraph(G2);
		printf("\n");
	}
	PressEnter;

	printf("▼4、5\n▲函数 ShortestPath_FLOYD等 测试...\n");	//4、5.函数ShortestPath_FLOYD等测试
	{
		PathMatrix P2[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
		ShortPathTable D2[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
		
		printf("计算并输出各对顶点之间的最短路径：\n");
		ShortestPath_FLOYD(G2, P2, D2);
		OutputPath_FLOYD(G2, P2, D2);
		printf("\n");
	}
	PressEnter;	

	printf("▼6\n▲函数 Floyd 测试...\n");						//6.函数Floyd测试
	{
		PathMatrix path2[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
		ShortPathTable dist2[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
		
		printf("计算并输出各对顶点之间的最短路径：\n");
		Floyd(G2, path2, dist2);
		printf("\n");
	}
	PressEnter;
		
	return 0;
}
