#ifndef Question_7
#define Question_7

#include <stdio.h>
#include <limits.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"			//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"	//**▲07 图**//

/* 函数原型 */
void Dijkstra_7_42(ALGraph G, int v0, int path[], int dist[]);
int GetInfo_7_42(ALGraph G, int i, int j);			//获取边<i,j>的信息（权值） 

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;										//作为输入源	
	int path[MAX_VERTEX_NUM+1];
	int dist[MAX_VERTEX_NUM+1];
	int v0 = 1;
		
	printf("创建并输出无向图（带权）...\n");
	fp = fopen("Data/Algo_7_42.txt", "r");	
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");

	printf("计算并输出 %c 到其余各点的最短路径：\n", G.vertices[v0].data);
	Dijkstra_7_42(G, v0, path, dist);
	printf("\n");
}

void Dijkstra_7_42(ALGraph G, int v0, int path[], int dist[])
{
	int set[MAX_VERTEX_NUM+1];
	int min, i, j, v;
	int tmp[MAX_VERTEX_NUM+1], k;
	
	for(i=1; i<=G.vexnum; i++)					//数组初始化
	{
		dist[i] = GetInfo_7_42(G, v0, i);		//dist[i]：v0到i的最短路径长度 
		set[i] = 0;								//set[i]：标记数组，标记各顶点是否已加入路径 
		if(GetInfo_7_42(G, v0, i) < INT_MAX)
			path[i] = v0;						//path[i]：保存从v0到vi路径上vi的前一个顶点 
		else
			path[i] = -1;						//代表v0到vi中间不经过任何顶点（可能不通，也可能是自身） 
	}
	
	set[v0] = 1;
	path[v0] = -1;
	
	for(i=1; i<=G.vexnum; i++)					//初始化结束，关键操作开始（判断其余G.vexnum-1个顶点） 
	{
		min = INT_MAX;
		
		for(j=1; j<=G.vexnum; j++)				//选出v0到剩余顶点中最短的一条路径
		{
			if(!set[j] && dist[j]<min)
			{
				v = j;
				min = dist[j];					//v0到剩余顶点的最短路径<v0, v> 
			}
		}
			
		set[v] = 1;								//将顶点v加入最短路径
		
		for(j=1; j<=G.vexnum; j++)				//判断v的加入是否会造就v0到剩余顶点的更短路径 
		{
			if(!set[j] && min<INT_MAX &&  GetInfo_7_42(G, v, j)<INT_MAX && (min + GetInfo_7_42(G, v, j)) < dist[j])
			{
				dist[j] = min + GetInfo_7_42(G, v, j);
				path[j] = v;
			}
		}
	}
	
	//输出路径 
	for(i=1; i<=G.vexnum; i++)
	{
		if(v0!=i)
		{
			printf("%c 到 %c 的路径为：", G.vertices[v0].data, G.vertices[i].data);
			
			if(path[i]==-1)
				printf("×");
			else
			{
				tmp[0] = 0;								//计数路径上的顶点个数 
	
				if(v0!=i)
				{
					k = i;
					do
					{
						tmp[0]++;
						tmp[tmp[0]] = k;
						k = path[k];			
					}while(path[k]!=-1);			
				}
				
				printf("%c ", G.vertices[v0].data);
				
				if(tmp[0])
				{
					for(j=tmp[0]; j>=1; j--)
						printf("%c ", G.vertices[tmp[j]].data);
				}
			}
				
			printf("，权长为：");
			if(dist[i]==INT_MAX)
				printf("∞\n");
			else
				printf("%2d\n", dist[i]);
		}
	}	
} 

int GetInfo_7_42(ALGraph G, int i, int j)
{
	ArcNode *r;
	
	r = G.vertices[i].firstarc;
	
	while(r && r->adjvex!=j)
		r = r->nextarc;
	
	if(r && r->adjvex==j)
		return r->info.in;
	
	return INT_MAX;							//假设边的权值均大于0	
}

#endif
