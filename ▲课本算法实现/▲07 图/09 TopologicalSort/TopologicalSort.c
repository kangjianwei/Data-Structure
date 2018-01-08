/**************************************
 *					                  *
 * 文件夹: ▲07 图\09 TopologicalSort *
 * 					                  *
 * 文件名: TopologicalSort.c          *
 *    	    		                  *
 * 算  法：7.12   	                  *
 *    	    		                  *
 **************************************/

#ifndef TOPOLOGICALSORT_C
#define TOPOLOGICALSORT_C

#include "TopologicalSort.h" 							//**▲07 图**//

/*════╗
║算法7.12║ 
╚════*/
Status TopologicalSort(ALGraph G, int Topo[])			//数组Topo存储拓扑序列
{
	SqStack S;
	ArcNode *p;
	int i, k, count, indegree[MAX_VERTEX_NUM+1];				 
		
	FindInDegree(G, indegree);							//对各顶点求入度
	InitStack_Sq(&S);									//初始化栈 
	
	for(i=1; i<=G.vexnum; i++)							//建立入度为0的顶点栈 
	{
		if(!indegree[i])
			Push_Sq(&S, i);								//入度为0者进栈 
	}
	
	count = 0;											//对输出顶点计数
	
	while(!StackEmpty_Sq(S))
	{		
		Pop_Sq(&S, &i);		 
		count++;										//与教材写法略有出入 
		Topo[count] = i;								//不直接输出，而是暂存于数组中 

		for(p=G.vertices[i].firstarc; p; p=p->nextarc)
		{
			k = p->adjvex;								//对i号顶点的每个邻接点的入度减一
			if(!(--indegree[k]))
				Push_Sq(&S, k); 
		}
	} 
	
	if(count<G.vexnum)
		return ERROR;	
	else
		return OK;
}

void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM+1])
{
	int i;
	ArcNode *p;
	
	for(i=1; i<=G.vexnum; i++)
		indegree[i] = 0;								//初始化入度数组
		
	for(i=1; i<=G.vexnum; i++)
	{		
		p = G.vertices[i].firstarc;
		while(p)
		{
			indegree[p->adjvex]++;
			p = p->nextarc; 
		}
	}	 
}

#endif
