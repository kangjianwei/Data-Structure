/***********************************
 *					               *
 * 文件夹: ▲07 图\10 CriticalPath *
 * 					               *
 * 文件名: CriticalPath.c          *
 *    	    		               *
 * 算  法：7.13、7.14              *
 *    	    		               *
 ***********************************/

#ifndef CRITICALPATH_C
#define CRITICALPATH_C

#include "CriticalPath.h" 								//**▲07 图**//

/*════╗
║算法7.13║ 
╚════*/
Status TopologicalOrder(ALGraph G, SqStack *T)
{
	SqStack S;
	ArcNode *p;
	int i, j, k;
	int count, indegree[MAX_VERTEX_NUM+1];
		
	FindInDegree(G, indegree);							//对各顶点求入度
	InitStack_Sq(&S);									//初始化零入度顶点栈 
	InitStack_Sq(T); 									//初始化拓扑序列顶点栈 
	
	for(i=1; i<=G.vexnum; i++)							//建立入度为0的顶点栈，初始化数组ve 
	{
		if(!indegree[i])
			Push_Sq(&S, i);								//入度为0者进栈
		
		ve[i] = 0;
	}
	
	count = 0;											//对输出顶点计数
	
	while(!StackEmpty_Sq(S))
	{		
		Pop_Sq(&S, &j);	
		Push_Sq(T, j);									//j号0入度顶点入拓扑序列栈并计数 
		count++;

		for(p=G.vertices[j].firstarc; p; p=p->nextarc)
		{
			k = p->adjvex;								//对j号顶点的每个邻接点的入度减一
			if(!(--indegree[k]))
				Push_Sq(&S, k); 						//若入度减为0，则放入零入度顶点栈
			if(ve[j] + 	p->info.in > ve[k])
				ve[k] = ve[j] + p->info.in;
		}
	} 
	
	if(count<G.vexnum)
	{
		printf("该有向图有回路！！\n");
		return ERROR;	
	}
	else
		return OK;
}

/*════╗
║算法7.14║ 
╚════*/
Status CriticalPath(ALGraph G)
{
	int i, j, k;
	ArcNode *p;
	int dut;											//活动持续时间
	int ee, el;
	int count;
	char tag;
	
	if(!TopologicalOrder(G, &T))
		return ERROR;
	
	for(i=1; i<=G.vexnum; i++)
		vl[i] = ve[G.vexnum];							//初始化事件（顶点）的最迟发生事件 
	
	while(!StackEmpty_Sq(T))							//按拓扑逆序求得各顶点的vl值 
	{
		for(Pop_Sq(&T,&j),p=G.vertices[j].firstarc; p; p=p->nextarc)
		{
			k = p->adjvex;
			dut = p->info.in;							//dut<j,k>
			
			if(vl[k] - dut < vl[j])
				vl[j] = vl[k] - dut;			
		}
	} 
	
	for(j=1,count=1; j<=G.vexnum; j++)							//求ee，el和关键活动 
	{
		for(p=G.vertices[j].firstarc; p; p=p->nextarc)
		{
			k = p->adjvex;
			dut  = p->info.in;
			ee = ve[j];
			el = vl[k] - dut;
			tag = (ee==el) ? '*' : ' ';							//用*标记关键活动 
			
			printf("%c-%c  a%-2d=%2d  (%2d, %2d)  %c\n", G.vertices[j].data, G.vertices[k].data, count++, dut, ee, el, tag);
		}
	}
	
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
