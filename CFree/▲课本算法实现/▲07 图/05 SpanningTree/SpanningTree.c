/***********************************
 *						           *
 * 文件夹: ▲07 图\05 SpanningTree *
 * 						           *
 * 文件名: SpanningTree.c          *
 *    	    			           *
 * 算  法: 7.7、7.8                * 
 *    	    			           *
 ***********************************/

#ifndef SPANNINGTREE_C
#define SPANNINGTREE_C

#include "SpanningTree.h"

/*════╗
║ 算法7.7║ 
╚════*/
void DFSForest(MGraph G, CSTree *T)
{
	int v;
	CSTree p, q;
	
	InitTree_CS(T);
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;
	
	for(v=1; v<=G.vexnum; v++)
	{
		if(!visited[v])							//第v顶点为新的生成树的根结点 
		{
			p = (CSTree)malloc(sizeof(CSNode));	//分配根结点
			if(!p)
				exit(OVERFLOW);
			p->data = GetVex_M(G, v);
			p->firstchild = p->nextsibling = NULL;
			
			if(!(*T))							//是第一棵生成树的根 
				*T = p;
			else								//是其他生成树的根（前一棵树根的兄弟） 
				q->nextsibling = p;
			
			q = p;								//q指示当前生成树的根 
			DFSTree(G, v, &p);					//建立以p为根的生成树 
		}
	}
}

/*════╗
║ 算法7.8║ 
╚════*/
void DFSTree(MGraph G, int v, CSTree *T)
{
	Status first;
	int w;
	CSTree p, q;
		
	visited[v] = TRUE;
	first = TRUE;
	
	for(w=FirstAdjVex_M(G, G.vexs[v]); w; w=NextAdjVex_M(G, G.vexs[v], G.vexs[w]))
	{
		if(!visited[w])
		{
			p = (CSTree)malloc(sizeof(CSNode));		//分配孩子结点 
			if(!p)
				exit(OVERFLOW);
			p->data = GetVex_M(G, w);
			p->firstchild = p->nextsibling = NULL;
			
			if(first)
			{
				(*T)->firstchild = p;
				first = FALSE;
			}
			else
				q->nextsibling = p;	
		
			q = p;
			DFSTree(G, w, &q);
		}
	}
}

#endif
