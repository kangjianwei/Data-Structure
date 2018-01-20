#ifndef Question_7
#define Question_7

#include <stdio.h>
#include <limits.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"				//**▲07 图**//
#include "../../../▲课本算法实现/▲06 树和二叉树/07 ChildSiblingTree/ChildSiblingTree.c"//**▲06 树和二叉树**//

/* 类型定义 */
typedef int MFSet; 						//并查集 
typedef	struct							//边的集合 
{
	int u, v;							//端点 
	int Weight;							//权值 
}EdgeSetType;
typedef	struct							//不带权值的边的集合 
{
	char u;
	char v;								//端点 
}Edge;

/* 函数原型 */
CSTree MinSpanTree_KRUSKAL_7_33(ALGraph G);
void InitEdgeSet_7_33(EdgeSetType EdgeSet[], ALGraph G);		//初始化边集 
Status GetMinEdge_7_33(EdgeSetType EdgeSet[], int *u, int *v);	//获取最小边<u, v>
void DelMinEdge_7_33(EdgeSetType EdgeSet[], int u, int v);		//删除边<u, v> 
void InitMFSet_7_33(MFSet S[], ALGraph G);						//初始化并查集 
int FindSeat_7_33(MFSet S[], int u);							//返回顶点u所在集合 
void Merge_7_33(MFSet S[], int u, int v);						//将集合u并入集合v 
CSTree CreateCSTree_7_33(Edge E[]);								//根据边集创建树 
void AddEdgeToTree_7_33(CSTree *T, char v, char w);				//添加边<v,w>到树中，v为连接点

int main(int argc, char *argv[])
{
    ALGraph G;
    FILE *fp;										//作为输入源
	CSTree T;

	printf("创建并输出无向图（带权）...\n");	
	fp = fopen("Data/Algo_7_33.txt", "r");
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");	
	
	T= MinSpanTree_KRUSKAL_7_33(G);
	printf("此无向连通网的最小生成树为：\n");
	Print_CS(T);
	printf("\n");
}

/*━━━━━━━━━━━━━━━━━━━━━━┓
┃题7.33：最小生成树的克鲁斯卡尔算法（邻接表）┃
┗━━━━━━━━━━━━━━━━━━━━━━*/
CSTree MinSpanTree_KRUSKAL_7_33(ALGraph G)			//假设图的权值均大于0 
{
	MFSet S[G.vexnum+1];							//并查集 
	EdgeSetType EdgeSet[G.arcnum+1];				//原始边集 
	Edge E[G.vexnum];								//筛选后的最小边集								
	int u, v;
	int k;
	
	InitEdgeSet_7_33(EdgeSet, G);
	InitMFSet_7_33(S, G);
	
	k = 1;
	E[0].u = E[0].v = G.vexnum-1;
	
	while(k<=G.vexnum-1)
	{
		if(GetMinEdge_7_33(EdgeSet, &u, &v))				//找到最小边 
		{
			if(FindSeat_7_33(S, u)!=FindSeat_7_33(S, v))	//判断是否构成回路 
			{
				E[k].u = G.vertices[u].data;
				E[k].v = G.vertices[v].data;
				Merge_7_33(S, u, v);						
				k++;
			}
		
			DelMinEdge_7_33(EdgeSet, u, v); 
		}
	}
	
	return CreateCSTree_7_33(E);
}

void InitEdgeSet_7_33(EdgeSetType EdgeSet[], ALGraph G)
{
	int k, count;
	ArcNode *r;
	
	EdgeSet[0].Weight = G.arcnum;
	
	for(k=1,count=0; k<=G.vexnum; k++)
	{
		r = G.vertices[k].firstarc;
		while(r && r->adjvex<k)
			r = r->nextarc;
		while(r)
		{
			count++;
			EdgeSet[count].u = k;
			EdgeSet[count].v = r->adjvex;
			EdgeSet[count].Weight = r->info.in;
			r = r->nextarc;
		}
	}
}

Status GetMinEdge_7_33(EdgeSetType EdgeSet[], int *u, int *v)
{
	int k;
	int min = INT_MAX;
	
	for(k=1; k<=EdgeSet[0].Weight; k++)
	{
		if(EdgeSet[k].Weight<min)
		{
			min = EdgeSet[k].Weight;
			*u = EdgeSet[k].u;
			*v = EdgeSet[k].v;
		}
	}
	
	if(min==INT_MAX)
		return ERROR;
	else
		return OK;
}

void DelMinEdge_7_33(EdgeSetType EdgeSet[], int u, int v)
{
	int k;
	
	for(k=1; k<=EdgeSet[0].Weight; k++)
	{
		if((EdgeSet[k].u==u&&EdgeSet[k].v==v) || (EdgeSet[k].u==v&&EdgeSet[k].v==u))
		{
			while(k+1<=EdgeSet[0].Weight)
			{
				EdgeSet[k] = EdgeSet[k+1];
				k++;
			}
			
			break;
		}	
	}
	
	EdgeSet[0].Weight--;
}

void InitMFSet_7_33(MFSet S[], ALGraph G)
{
	int k;
	
	S[0] = G.vexnum;
	
	for(k=1; k<=G.vexnum; k++)
		S[k] = -1;
}

int FindSeat_7_33(MFSet S[], int u)
{
	int k;
	
	for(k=u; S[k]>0; k=S[k])
		;
	
	return k;
}

void Merge_7_33(MFSet S[], int u, int v) //集合u合并到集合v 
{
	int k;
	
	S[u] = v;
	
	for(k=v; S[k]>0; k=S[k])
		;
			
	S[k]--;
}

CSTree CreateCSTree_7_33(Edge E[])
{
	CSTree T;
	char Stack[E[0].u+1];					//模拟栈 
	int i, j, k;
	char tmp;
	
	InitTree_CS(&T);						//初始化孩子-兄弟树 
	k = -1;
	
	if(E[0].u)								//边集不为空
	{
		Stack[++k] = E[1].v;
		Stack[++k] = E[1].u;
		AddEdgeToTree_7_33(&T, E[1].u, E[1].v);
		
		while(k>=0)
		{
			tmp = Stack[k--];
			for(i=2; i<=E[0].u; i++)
			{
				if(E[i].u==tmp || E[i].v==tmp)
				{
					if(E[i].u==tmp)
					{
						AddEdgeToTree_7_33(&T, E[i].u, E[i].v);
						Stack[++k] = E[i].v;		
					}
					else
					{
						Stack[++k] = E[i].u;
						AddEdgeToTree_7_33(&T, E[i].v, E[i].u);				
					}
						
					E[i].u = E[i].v = '\0';		//相当于删掉此条已访问过的边 
				}
			}
		}		
	} 
	
	return T;	
}

void AddEdgeToTree_7_33(CSTree *T, char v, char w)
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
