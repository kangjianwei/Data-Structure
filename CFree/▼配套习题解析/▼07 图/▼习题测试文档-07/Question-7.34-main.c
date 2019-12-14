#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/09 TopologicalSort/TopologicalSort.c"	//**▲07 图**//

/* 函数原型 */
Status Algo_7_34(ALGraph G, int Topo[]);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;													//作为输入源	
	int Topo[MAX_VERTEX_NUM+1];									//存储拓扑序列
	int k;
		
	printf("创建并输出有向图...\n");
	fp = fopen("Data/Algo_7_34.txt", "r");	
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	if(Algo_7_34(G, Topo))
	{
		printf("此有向无环图的拓扑序列为：\n");
		for(k=1; k<=G.vexnum; k++)
			printf("%d-%c ", k, G.vertices[Topo[k]].data); 
	}
	printf("\n\n");
	
	return 0;
}

/*━━━━━━━━┓
┃题7.34：拓扑排序┃
┗━━━━━━━━*/
Status Algo_7_34(ALGraph G, int Topo[])
{	
	return TopologicalSort(G, Topo);							//已定义 
}
