#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/09 TopologicalSort/TopologicalSort.c" //**▲07 图**//

/* 函数原型 */
Status Algo_7_36(ALGraph G, int MPL[][MAX_VERTEX_NUM+1]);
Status Algo_7_37(ALGraph G, int MPL[][MAX_VERTEX_NUM+1], int Path[]);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;										//作为输入源	
	int MPL[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];	//记录各顶点出发的最长路径 		
	int i, j;
	int Path[MAX_VERTEX_NUM+1];
	
	printf("创建并输出有向图...\n");
	fp = fopen("Data/Algo_7_36-7_37.txt", "r");	
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");	

	printf("███ 题 7.36 验证... ███\n");	
	if(Algo_7_36(G, MPL))
	{
		printf("从各顶点出发的最长路径分别为：\n");
		for(i=1; i<=G.vexnum; i++)
		{
			for(j=1; j<=MPL[i][0]; j++)
				printf("%c ", G.vertices[MPL[i][j]].data);
			printf("\n");
		}	
	}
	printf("\n");

	printf("███ 题 7.37 验证.. ███\n");	
	if(Algo_7_37(G, MPL, Path))
	{
		printf("此DAG图的最长路径为：");
		for(i=1; i<=Path[0]; i++)
			printf("%c ", G.vertices[Path[i]].data);
		printf("\n");
	}
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━┓
┃题7.36：求DAG图从每个顶点出发的最长路径 ┃
┗━━━━━━━━━━━━━━━━━━━━*/
Status Algo_7_36(ALGraph G, int MPL[][MAX_VERTEX_NUM+1])
{	
	int Topo[MAX_VERTEX_NUM+1];									//存储拓扑序列
	int i, j, k, max, tmp;
	ArcNode *r;
	
	if(TopologicalSort(G, Topo))
	{
		for(i=0; i<=MAX_VERTEX_NUM; i++)						//初始化最长路径数组 
		{
			for(j=0; j<=MAX_VERTEX_NUM; j++)
				MPL[i][j] = 0;
		}
		
		MPL[0][0] = G.vexnum;									//总路径数 
		
		for(k=G.vexnum; k>=1; k--)								//逆拓扑序列求各顶点最长路径 
		{
			r = G.vertices[Topo[k]].firstarc;
			
			MPL[Topo[k]][1] = Topo[k];
			
			if(!r)
				MPL[Topo[k]][0]	= 1;
			else
			{
				max = tmp = 0;
				while(r)
				{
					if(MPL[r->adjvex][0]>max)					//若某顶点有多条最长路径，则只取首先遇见的一条 
					{
						max = MPL[r->adjvex][0];
						tmp = r->adjvex;
					}
					
					r = r->nextarc;
				}
				
				MPL[Topo[k]][0] = max+1;							//当前顶点出发的最长路径中顶点个数 
				
				for(i=1; i<=max; i++)
					MPL[Topo[k]][i+1] = MPL[tmp][i];
			}
		}
		
		return OK;
	}
	
	return ERROR;
}

/*━━━━━━━━━━━━┓
┃题7.37：求DAG图最长路径 ┃
┗━━━━━━━━━━━━*/
Status Algo_7_37(ALGraph G, int MPL[][MAX_VERTEX_NUM+1], int Path[])
{
	int k, tmp;
	
	if(Algo_7_36(G, MPL))
	{
		for(k=1,Path[0]=tmp=0; k<=G.vexnum; k++)
		{
			if(MPL[k][0]>Path[0])					//若DAG图有多条最长路径，则只取首先遇见的一条
			{
				Path[0] = MPL[k][0];
				tmp = k;
			}
		}
		
		for(k=1; k<=Path[0]; k++)
			Path[k] = MPL[tmp][k];
		
		return OK;
	}
	
	return ERROR;
}
