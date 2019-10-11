#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"		//**▲07 图**//

/* 全局变量 */
Status tag;

/* 函数原型 */
Status Algo_7_22(ALGraph G, int i, int j);
Status Algo_7_23(ALGraph G, int i, int j);
void DFS_7_22(ALGraph G, int i, int j);	//通过深度优先遍历判断vi到vj之间是否有通路 
void BFS_7_23(ALGraph G, int i, int j);	//通过广度优先遍历判断vi到vj之间是否有通路

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//作为输入源

	printf("创建并输出有向图...\n");
	G.kind = DG;								//以无向图为例
	fp = fopen("Data/Algo_7_22-7_23.txt", "r");
	CreateDG_AL(fp, &G);						 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	printf("███ 题 7.22 验证... ███\n");
	Algo_7_22(G, 1, 3); 
	printf("\n");

	printf("███ 题 7.23 验证... ███\n");
	Algo_7_22(G, 4, 3); 
	printf("\n");
				
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题7.22：通过深度优先遍历判断顶点vi到vj是否存在路径┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/
Status Algo_7_22(ALGraph G, int i, int j)
{
	int v, w;
	ArcNode *p;
	
	if(i==j)
	{
		printf("参数错误！\n");
		return ERROR;
	}
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;			//初始化为未访问	
	
	tag = FALSE;					//全局变量，标记vi到vj间是否有通路	
	visited[i] = TRUE;
	
	DFS_7_22(G, i, j);				//深度优先遍历函数
	
	if(tag)
	{
		printf("%c 到 %c 之间有通路！\n", G.vertices[i].data, G.vertices[j].data);
		return TRUE;
	}
	else
	{
		printf("%c 到 %c 之间无通路！！\n", G.vertices[i].data, G.vertices[j].data);
		return ERROR;
	}
} 

/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题7.23：通过广度优先遍历判断顶点vi到vj是否存在路径┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/
Status Algo_7_23(ALGraph G, int i, int j)
{
	int v, w;
	ArcNode *p;
	
	if(i==j)
	{
		printf("参数错误！\n");
		return ERROR;
	}
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;			//初始化为未访问	
	
	tag = FALSE;					//全局变量，标记vi到vj间是否有通路	
	visited[i] = TRUE;
	
	BFS_7_23(G, i, j);				//广度优先遍历函数 
	
	if(tag)
	{
		printf("%c 到 %c 之间有通路！\n", G.vertices[i].data, G.vertices[j].data);
		return TRUE;
	}
	else
	{
		printf("%c 到 %c 之间无通路！！\n", G.vertices[i].data, G.vertices[j].data);
		return ERROR;
	}
}

void DFS_7_22(ALGraph G, int i, int j)	//深度优先遍历
{
	int w;
	
	for(w=FirstAdjVex_AL(G, G.vertices[i].data); w; w=NextAdjVex_AL(G, G.vertices[i].data, G.vertices[w].data))
	{
		if(tag)
			return;
			
		if(!visited[w])
		{
			visited[w] = TRUE;
						
			if(w==j)
				tag = TRUE;			
			else
				DFS_7_22(G, w, j);				
		}
	}
}

void BFS_7_23(ALGraph G, int i, int j)	//广度优先遍历
{
	int v, w;
	LinkQueue Q;
	QElemType_L e;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;					//初始化为未访问

	visited[i] = TRUE;	

	InitQueue_L(&Q);		
	EnQueue_L(&Q, i);
	while(!QueueEmpty_L(Q))
	{
		DeQueue_L(&Q, &e);
		for(w=FirstAdjVex_AL(G, G.vertices[e].data); w; w=NextAdjVex_AL(G, G.vertices[e].data, G.vertices[w].data))
		{
			if(!visited[w])
			{
				visited[w] = TRUE;
						
				if(w==j)
				{
					tag = TRUE;
					return;				
				}
							
				EnQueue_L(&Q, w);
			}
		}
	}
}
