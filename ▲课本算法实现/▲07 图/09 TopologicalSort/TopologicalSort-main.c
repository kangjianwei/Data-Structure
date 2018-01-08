/**************************************
 *					                  *
 * 文件夹: ▲07 图\09 TopologicalSort *
 * 					                  *
 * 文件名: TopologicalSort-main.c     *
 * 							          *
 * 内  容: 有向图拓扑排序相关函数测试 *
 *                                    *
 **************************************/

#include <stdio.h> 
#include "TopologicalSort.c" 	//**▲07 图**//

int main(int argc, char *argv[])
{
	ALGraph G;
	
	printf("创建并输出有向图...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_DG_AL.txt", "r");	
		CreateGraph_AL(fp, &G); 
		fclose(fp);
		OutputALGraph(G);
		printf("\n");
	}
	PressEnter;	

	printf("▼1、2\n▲函数 TopologicalSort等 测试...\n");		//1、2.函数TopologicalSort等测试	
	{
		int k;
		int Topo[MAX_VERTEX_NUM+1];								//存储拓扑序列 
	
		printf("对有向图进行拓扑排序...\n");
		if(!TopologicalSort(G, Topo))
			printf("该有向图有回路！！\n");	
		else
		{
			printf("该有向图的拓扑序列为：");
			for(k=1; k<=G.vexnum; k++)
				printf("%c ", G.vertices[Topo[k]].data);
		}
		printf("\n\n");
	}
	PressEnter;
		
	return 0;
}
