/****************************************
 *    	    		                    *
 * 文件夹: ▲07 图\08 ArticulationPoint *
 * 					                    *
 * 文件名: ArticulationPoint.c          *
 *    	    		                    *
 * 算  法：7.10、7.11   	            *
 *    	    		                    *
 ****************************************/

#ifndef ARTICULATIONPOINT_C
#define ARTICULATIONPOINT_C

#include "ArticulationPoint.h" 							//**▲07 图**//

/*════╗
║算法7.10║ 
╚════*/
void FindArticul(ALGraph G)
{
	int i, v;
	ArcNode *p;
		
	count = 1;
	visited[1] = 1;										//设定邻接表上1号顶点为生成树的根（0号单元弃用）
	
	for(i=2; i<=G.vexnum; i++) 
		visited[i] = 0;									//其余顶点尚未访问
	
	p = G.vertices[1].firstarc;
	v = p->adjvex;
	
	DFSArticul(G, v); 									//先遍历根结点最左边的子树 
	
	if(count<G.vexnum)									//生成树的根有至少两棵子树
	{
		StorageAPoint(1);
		
		while(p->nextarc)								//依次遍历其他子树 
		{
			p = p->nextarc;
			v = p->adjvex;
			
			if(visited[v]==0)
				DFSArticul(G, v);
		}
	}
} 

/*════╗
║算法7.11║ 
╚════*/
void DFSArticul(ALGraph G, int v0)
{
	int min, w;											//min暂存low[]的值 
	ArcNode *p;	
	
	visited[v0] = min = ++count;						//v0是第count个访问的顶点 

	for(p=G.vertices[v0].firstarc; p; p=p->nextarc)
	{
		w = p->adjvex;									//w为v0的邻接顶点 

		if(visited[w]==0)								//w未曾访问，是v0的孩子 
		{
			DFSArticul(G, w);							//返回前求得low[w] 
			
			if(low[w]<min)
				min = low[w];
			
			if(low[w]>=visited[v0])						//v0子树可直接追溯的最早祖先不超过自身
				StorageAPoint(v0);
		}
		else											//w已访问，是v0在生成树上的祖先 
		{
			if(visited[w]<min)				
				min = visited[w];
		}
		
		low[v0] = min;
	}
} 

Status StorageAPoint(int n)
{
	int i;
	
	for(i=1; i<=node[0]; i++)
	{
		if(node[i]==n)									//该关节点已存储过 
			return ERROR;
	}
	
	node[0]++;
	node[node[0]] = n;
	
	return OK;
}

void OutputAPoint(ALGraph G)
{
	int i;
	
	for(i=1; i<=node[0]; i++)
		printf("第 %2d 个找到的关节点 %c，先序编号为 %2d\n", i, G.vertices[node[i]].data, node[i]);
}

#endif
