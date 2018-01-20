#ifndef Question_7
#define Question_7

#include <stdio.h>
#include <limits.h>
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"		//**▲07 图**//
#include "../../../▲课本算法实现/▲06 树和二叉树/07 ChildSiblingTree/ChildSiblingTree.c"

/* 函数原型 */
CSTree MinSpanTree_PRIM_7_32(ALGraph G, VertexType_AL u);
int GetInfo_7_32(ALGraph G, int i, int j);							//获取边<i,j>的信息（权值） 
int Minimum_7_32(ALGraph G, int strat[], int mark[], int n);		//找出“最小距离” 
void AddEdgeToTree_7_32(CSTree *T, char v, char w);					//添加边<v,w>到树中，v为连接点 

int main(int argc, char *argv[])
{
    ALGraph G;
    FILE *fp;										//作为输入源
	CSTree T;

	printf("创建并输出无向图（带权）...\n");	
	fp = fopen("Data/Algo_7_32.txt", "r");
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");	

	T = MinSpanTree_PRIM_7_32(G, 'A');
	printf("此无向连通网的最小生成树为：\n");
	Print_CS(T);
	printf("\n");
}

/*━━━━━━━━━━━━━━━━━━━━┓
┃题7.32：最小生成树的普里姆算法（邻接表）┃
┗━━━━━━━━━━━━━━━━━━━━*/
CSTree MinSpanTree_PRIM_7_32(ALGraph G, VertexType_AL u)//假设图的权值均大于0 
{
	int i, j, k; 
	int start[G.vexnum+1];			//标记当前加入生成树的边的起始顶点 
	int mark[G.vexnum+1];			//标记第i个顶点是否已加入最小生成树 
	CSTree T;
	
	InitTree_CS(&T);
	k = LocateVex_AL(G, u);
	
	for(j=1; j<=G.vexnum; j++)						//辅助数组初始化 
	{
		start[j] = k;
		if(j!=k)
			mark[j] = 0;
		else
			mark[j] = 1;
	}
	
	for(i=1; i<=G.vexnum-1; i++)		//总共需要G.vexnum-1次寻找最小边
	{
		k = Minimum_7_32(G, start, mark, G.vexnum);
		
		AddEdgeToTree_7_32(&T, G.vertices[start[k]].data, G.vertices[k].data);//添加边到树 
		
		mark[k] = 1;
		
		for(j=1; j<=G.vexnum; j++)
		{
			if(mark[j]!=1)
			{
				if(GetInfo_7_32(G, k, j) < GetInfo_7_32(G, start[j], j))
					start[j] = k;
			}
		}
	}
	
	return T;
}

int GetInfo_7_32(ALGraph G, int i, int j)
{
	ArcNode *r;
	
	r = G.vertices[i].firstarc;
	
	while(r && r->adjvex!=j)
		r = r->nextarc;
	
	if(r && r->adjvex==j)
		return r->info.in;
	
	return INT_MAX;							//假设边的权值均大于0	
} 

int Minimum_7_32(ALGraph G, int start[], int mark[], int n)
{
	int i, j;
	int min = INT_MAX; 
	 
	for(i=1,j=0; i<=n; i++)
	{
		if(mark[i]!=1 && GetInfo_7_32(G, start[i], i)<min)
		{
			min = GetInfo_7_32(G, start[i], i);
			j = i;
		}
	}
	
	return j;
}

void AddEdgeToTree_7_32(CSTree *T, char v, char w)
{
	CSTree p, q, r;
	
	r = (CSTree)malloc(sizeof(CSNode));
	r->data = w;
	r->firstchild = r->nextsibling = NULL;
	
	if(!(*T))
	{
		*T = (CSTree)malloc(sizeof(CSNode));
		(*T)->data = v;
		(*T)->firstchild = r;
		(*T)->nextsibling = NULL;		
	}
	else
	{
		p = Order_CS(*T, v);
		q = p->firstchild;
		
		if(!q)
			p->firstchild = r;
		else
		{
			while(q && q->nextsibling)
				q = q->nextsibling;
			q->nextsibling = r;	
		}
	}
}

#endif
