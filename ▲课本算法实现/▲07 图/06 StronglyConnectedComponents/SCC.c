/**************************************************
 *				                                  *
 * 文件夹: ▲07 图\06 StronglyConnectedComponents *
 * 				                                  *
 * 文件名: SCC.c                                  *
 *    	    	                                  *
 **************************************************/

#ifndef SCC_C
#define SCC_C

#include "SCC.h"							//**▲07 图**//

void InverseGraph(OLGraph *G)
{
	int i, k;
	ArcBox *tmp, *p, *q;
	VexNode *h;
	
	for(i=1; i<=(*G).vexnum; i++)
	{
		h = &((*G).xlist[i]);

		if(h->firstout)
			p = h->firstout;

		tmp = h->firstout;
		h->firstout = h->firstin;
		h->firstin = tmp;
		
		while(p)
		{
			q = p;
			p = p->tLink;
			
			k = q->tailvex;
			q->tailvex = q->headvex;
			q->headvex = k;
			
			tmp = q->tLink;
			q->tLink = q->hlink;
			q->hlink = tmp;
		}
	}
}

void DFSTraverse_SCC(OLGraph G)
{
	int v;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;					//初始化为未访问
	
	count = 0;
	
	for(v=1; v<=G.vexnum; v++)
	{
		if(!visited[v])						//未访问
			DFS_SCC_1(G, v); 
	} 
}

void DFS_SCC_1(OLGraph G, int v)
{
	int w;

	visited[v] = TRUE;

	for(w=FirstAdjVex_OL(G, G.xlist[v].data); w; w=NextAdjVex_OL(G, G.xlist[v].data, G.xlist[w].data))
	{
		if(!visited[w])
			DFS_SCC_1(G, w);
	}
	
	finished[++count] = v;
}

void DFS_SCC_2(OLGraph G, int v)
{
	int w;

	visited[v] = TRUE;
	printf("%c ", G.xlist[v].data);

	for(w=FirstAdjVex_OL(G, G.xlist[v].data); w; w=NextAdjVex_OL(G, G.xlist[v].data, G.xlist[w].data))
	{
		if(!visited[w])
			DFS_SCC_2(G, w);		
	}
}

void Kosaraju(OLGraph G)
{
	int v;
	
	DFSTraverse_SCC(G);						//生成下一次的遍历次序 
	
	InverseGraph(&G);						//逆置有向图 
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;					//初始化为未访问
	
	printf("此有向图的强连通分量为：\n");	
	for(v=G.vexnum; v>=1; v--)
	{
		if(!visited[finished[v]])			//未访问
		{
			DFS_SCC_2(G, finished[v]);
				printf("\n");
		}
	} 
}

#endif
