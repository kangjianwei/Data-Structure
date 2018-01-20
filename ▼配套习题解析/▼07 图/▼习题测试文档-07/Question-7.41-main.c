#ifndef Question_7
#define Question_7

#include <stdio.h>
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"	//**▲03 栈和队列**//
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"				//**▲07 图**//

/* 全局变量 */
SqStack S;
int path[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];	//路径数组 
int step;										//路径长 

/* 函数原型 */
void Algo_7_41(ALGraph G);
void DFS_7_41(ALGraph G, int w);				//深搜找出源点到汇点的各条路径 
int FindOrigin(ALGraph G);						//寻找关键路径源点(唯一)

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//作为输入源	
	
	printf("创建并输出 有向图（带权）...\n");
	fp = fopen("Data/Algo_7_41.txt", "r");	
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");

	printf("此AOE网的关键路径是：");
	Algo_7_41(G);
	printf("\n");
}

void Algo_7_41(ALGraph G)
{
	int i, j, start;
	int max = 0;
	
	for(i=0; i<=G.vexnum; i++)					//初始化路径数组 
	{
		for(j=0; j<=G.vexnum; j++)
			path[i][j] = 0;
	}
	
	step = 0;
	start = FindOrigin(G);						//源点
	InitStack_Sq(&S);
	
	DFS_7_41(G, start); 						//从源点开始遍历 
	
	for(i=1; i<=path[0][0]; i++)				//确定最长的路径长度 
	{
		if(path[i][0]>max)
			max = path[i][0];
	}
	
	for(i=1; i<=path[0][0]; i++)
	{
		if(path[i][0]==max)
		{
			for(j=1; path[i][j]&&j<=MAX_VERTEX_NUM; j++)
				printf("%c ", G.vertices[path[i][j]].data);		
			printf("\n");
		}		
	}
} 

void DFS_7_41(ALGraph G, int w)
{
	ArcNode *r;	
	SElemType_Sq e;
	int *p;
	int count;
	
	Push_Sq(&S, w); 
	
	for(r=G.vertices[w].firstarc; r; r=r->nextarc)
	{
		step += r->info.in;
		DFS_7_41(G, r->adjvex);
		step -= r->info.in;
	}
	
	if(!r)
	{
		if(G.vertices[w].firstarc==NULL)			//找到了汇点
		{
			path[0][0]++;
			path[path[0][0]][0] = step;
	
			for(p=S.base,count=1; p<S.top; p++,count++)
				path[path[0][0]][count] = *p;		
		} 
		
		Pop_Sq(&S, &e);
	}
}

int FindOrigin(ALGraph G)
{
	int k;
	ArcNode *r;
	int mark[G.vexnum+1];
	
	for(k=1; k<=G.vexnum; k++)
		mark[k] = 0;
	
	for(k=1; k<=G.vexnum; k++)
	{
		r = G.vertices[k].firstarc;
		
		while(r)
		{
			mark[r->adjvex] = 1;
			r = r->nextarc;
		}
	}
	
	for(k=1; k<=G.vexnum; k++)
	{
		if(!mark[k])
			return k;
	}
	
	return 0;	
}

#endif
