/*******************************
 *						       *
 * 文件夹: ▲07 图\04 AMLGraph *
 * 						       *
 * 文件名: AMLGraph.c          *
 *    	    		           *
 *******************************/

#ifndef AMLGRAPH_C
#define AMLGRAPH_C

#include "AMLGraph.h" 								//**▲07 图**//

/*════╗
║ 算法7.3║ 
╚════*/
Status CreateUDG_AML(FILE *fp, AMLGraph *G)
{
	int i, j, k;
	VertexType_AML v1, v2;
	char tmp;
	EBox *p;
	
	Scanf(fp, "%d%d%d", &((*G).vexnum), &((*G).edgenum), &((*G).IncInfo));
	Scanf(fp, "%c", &tmp);							//跳过换行符 
	
	for(i=1; i<=(*G).vexnum; i++)					//构造表头向量 
	{
		Scanf(fp, "%c", &((*G).adjmulist[i].data));	//输入顶点值	
		(*G).adjmulist[i].firstedge = NULL;
	}
	Scanf(fp, "%c", &tmp);							//跳过换行符
		
	for(k=1; k<=(*G).edgenum; k++)					//输入各弧并构造邻接多重表 
	{
		Scanf(fp, "%c%c", &v1, &v2);				//输入一条弧的起始点和终点 
				
		i = LocateVex_AML(*G, v1);					//确定v1和v2在G中位置 
		j = LocateVex_AML(*G, v2);
		
		if(!i || !j)
			return ERROR;

		p = (EBox *)malloc(sizeof(EBox));			//假定有足够空间 
		if(!p)
			exit(OVERFLOW);
		
		p->mark = unvisit;
		p->ivex = i;								//对弧结点和顶点结点赋值 
		p->jvex = j;
		
		p->ilink = (*G).adjmulist[i].firstedge;
		(*G).adjmulist[i].firstedge = p;
		
		p->jlink = (*G).adjmulist[j].firstedge;
		(*G).adjmulist[j].firstedge = p;
		
		if((*G).IncInfo==1)							//表示有弧的其他信息，录入 
			Input(fp, &(p->info));			
		
		edgePtr[k] = p;
	}
	
	return OK;	
}

void ClearGraph_AML(AMLGraph *G)
{
	int i;
	EBox *p, *q;
	
	for(i=1; i<=(*G).vexnum; i++)
	{
		p = (*G).adjmulist[i].firstedge;
		while(p)
		{
			q = p;
			p = p->ilink;
			free(q);
		}
	}
		
	(*G).vexnum = 0;
	(*G).edgenum = 0;
}
 
int LocateVex_AML(AMLGraph G, VertexType_AML u)
{
	int i;
	
	for(i=1; i<=G.vexnum; i++)
	{
		if(G.adjmulist[i].data==u)
			return i;
	}
	
	return 0;
}
 
VertexType_AML GetVex_AML(AMLGraph G, int order)
{
	if(order>=1 && order<=G.vexnum)
		return G.adjmulist[order].data;
	else
		return '\0';
} 

Status PutVex_AML(AMLGraph *G, VertexType_AML v, VertexType_AML value)
{
	int k;
	
	k = LocateVex_AML(*G, v);
	
	if(k)
	{
		(*G).adjmulist[k].data = value;
		return OK;	
	}
	else
		return ERROR;
}

int FirstAdjVex_AML(AMLGraph G, VertexType_AML v)
{
	int k;
	EBox *p;
		
	k = LocateVex_AML(G, v);
	p = G.adjmulist[k].firstedge;
		
	if(k && p)
	{
		if(p->ivex==k)
			return p->jvex;

		if(p->jvex==k)
			return p->ivex;
	}
	
	return 0;
} 

int NextAdjVex_AML(AMLGraph G, VertexType_AML v, VertexType_AML w)
{
	int k1, k2;
	EBox *p;
	
	k1 = LocateVex_AML(G, v);
	k2 = LocateVex_AML(G, w);
	p = G.adjmulist[k1].firstedge;
	
	if(k1 && k2)
	{
		while(p && ((p->ivex==k1 && p->jvex!=k2) || (p->jvex==k1 && p->ivex!=k2)))
		{
			if(p->ivex==k1)
				p = p->ilink;
			else
				p = p->jlink;
		}
		
		if(p && ((p->ivex==k1 && p->jvex==k2) || (p->jvex==k1 && p->ivex==k2)))
		{
			if(p->ivex==k1)
				p = p->ilink;
			else
				p = p->jlink;			
		}
		
		if(p)
		{
			if(p->ivex==k1)
				return p->jvex;
	
			if(p->jvex==k1)
				return p->ivex;			
		}
	}
	
	return 0;
} 

Status InsertVex_AML(AMLGraph *G, VertexType_AML v)
{
	int i, k, t;
	
	if((*G).vexnum==MAX_VERTEX_NUM)
		return ERROR;				//顶点数已满 

	(*G).vexnum++;
	
	(*G).adjmulist[(*G).vexnum].data = v;
	(*G).adjmulist[(*G).vexnum].firstedge = NULL;
	
	return OK;	
} 

Status DeleteVex_AML(AMLGraph *G, VertexType_AML v)
{
	int i, k;
	EBox *p, *q, *r;
	
	k = LocateVex_AML(*G, v);
	
	if(!k)
		return ERROR;
	
	while((*G).adjmulist[k].firstedge)
	{
		p = (*G).adjmulist[k].firstedge;
		DeleteArc_AML(G, (*G).adjmulist[p->ivex].data, (*G).adjmulist[p->jvex].data);
	}
	
	for(i=k+1; i<=(*G).vexnum; i++)
	{
		(*G).adjmulist[i-1].data = (*G).adjmulist[i].data;
		(*G).adjmulist[i-1].firstedge = (*G).adjmulist[i].firstedge;
	}
	
	(*G).vexnum--;
	
	return OK;	
}

Status InsertArc_AML(AMLGraph *G, VertexType_AML v, VertexType_AML w, ...)
{
	int k1, k2;
	EBox *p, *q, *r;
	
	k1 = LocateVex_AML(*G, v);
	k2 = LocateVex_AML(*G, w);
	
	if(!k1 || !k2)
		return ERROR;
		
	p = (EBox *)malloc(sizeof(EBox));
	if(!p)
		exit(OVERFLOW);
	if(k1<k2)							//维持整个邻接表的有序性 
	{
		p->ivex = k1;
		p->jvex = k2;
	}
	else
	{
		p->ivex = k2;
		p->jvex = k1;	
	}
	
	va_list ap;											//存在弧信息，则录入 
	va_start(ap, w);
	p->info = va_arg(ap, InfoType);						//结构可直接复制	
	va_end(ap);		
	
	q = (*G).adjmulist[p->ivex].firstedge;
	if(!q || (q->ivex>p->jvex || q->jvex>p->jvex))
	{
		p->ilink = q;
		(*G).adjmulist[p->ivex].firstedge = p;
	}
	else
	{	
		while(q && (p->jvex>q->ivex && p->jvex>q->jvex))
		{
			r = q;
			if(q->ivex==p->ivex)
				q = q->ilink;
			else
				q = q->jlink;
		}
		
		if(r->ivex==p->ivex)
		{
			p->ilink = r->ilink;
			r->ilink = p;	
		}
		else
		{
			p->ilink = r->jlink;
			r->jlink = p;
		}
	}
	
	q = (*G).adjmulist[p->jvex].firstedge;
	if(!q || (q->ivex>p->ivex && q->jvex>p->ivex))
	{
		p->jlink = q;
		(*G).adjmulist[p->jvex].firstedge = p;
	}
	else
	{	
		while(q && (p->ivex>q->ivex || p->ivex>q->jvex))
		{
			r = q;
			if(q->ivex==p->jvex)
				q = q->ilink;
			else
				q = q->jlink;
		}
		
		if(r->ivex==p->jvex)
		{
			p->jlink = r->ilink;
			r->ilink = p;	
		}
		else
		{
			p->jlink = r->jlink;
			r->jlink = p;
		}
	}	
	
	(*G).edgenum++;									//弧数增一 
	
	edgePtr[(*G).edgenum] = p;
		
	return OK;	
}

Status DeleteArc_AML(AMLGraph *G, VertexType_AML v, VertexType_AML w)
{
	int k1, k2, i;
	EBox *p, *q, *r;
	
	k1 = LocateVex_AML(*G, v);
	k2 = LocateVex_AML(*G, w);
	
	if(!k1 || !k2)
		return ERROR;
	
	p = (*G).adjmulist[k1].firstedge;
	if(p && ((p->ivex==k1 && p->jvex==k2) || (p->ivex==k2 && p->jvex==k1)))
		(*G).adjmulist[k1].firstedge = p->ivex==k1 ? p->ilink : p->jlink;
	else
	{
		while(p && !((p->ivex==k1 && p->jvex==k2) || (p->ivex==k2 && p->jvex==k1)))
		{
			r = p;
			p = p->ivex==k1 ? p->ilink : p->jlink;		
		}
		
		if(r->ivex==k1)
			r->ilink = p->ivex==k1 ? p->ilink : p->jlink;
		else
			r->jlink = p->ivex==k1 ? p->ilink : p->jlink;			
	}

	p = (*G).adjmulist[k2].firstedge;
	if(p && ((p->ivex==k1 && p->jvex==k2) || (p->ivex==k2 && p->jvex==k1)))
		(*G).adjmulist[k2].firstedge = p->jvex==k2 ? p->jlink : p->ilink;
	else
	{
		while(p && !((p->ivex==k1 && p->jvex==k2) || (p->ivex==k2 && p->jvex==k1)))
		{
			r = p;
			p = p->ivex==k2 ? p->ilink : p->jlink;		
		}
		
		if(r->jvex==k2)
			r->jlink = p->jvex==k2 ? p->jlink : p->ilink;
		else
			r->ilink = p->jvex==k2 ? p->jlink : p->ilink;			
	}
	
	for(i=1; i<=(*G).edgenum; i++)
	{
		if(edgePtr[i]==p)
			break;
	}
	
	while(i+1<=(*G).edgenum)
	{
		edgePtr[i] = edgePtr[i+1];
		i++;
	}
		
	free(p);
	
	(*G).edgenum--;							//弧数减一
		
	return OK;
}

void DFSTraverse_AML(AMLGraph G, void (Visit)(VertexType_AML))
{
	int v;
	
	VisitFunc = Visit;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;					//初始化为未访问
	
	for(v=1; v<=G.vexnum; v++)
	{
		if(!visited[v])						//未访问
			DFS_AML(G, v); 
	} 
}

void DFS_AML(AMLGraph G, int v)
{
	int w;

	visited[v] = TRUE;

	VisitFunc(G.adjmulist[v].data);

	for(w=FirstAdjVex_AML(G, G.adjmulist[v].data); w; w=NextAdjVex_AML(G, G.adjmulist[v].data, G.adjmulist[w].data))
	{
		if(!visited[w])
			DFS_AML(G, w);
	}
}

void BFSTraverse_AML(AMLGraph G, void (Visit)(VertexType_AML))
{
	int v, w;
	LinkQueue Q;
	QElemType_L e;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;					//初始化为未访问
	
	InitQueue_L(&Q);		
	
	for(v=1; v<=G.vexnum; v++)
	{
		if(!visited[v])
		{
			visited[v] = TRUE;
			Visit(G.adjmulist[v].data);
			EnQueue_L(&Q, v);
			while(!QueueEmpty_L(Q))
			{
				DeQueue_L(&Q, &e);
				for(w=FirstAdjVex_AML(G, G.adjmulist[e].data); w; w=NextAdjVex_AML(G, G.adjmulist[e].data, G.adjmulist[w].data))
				{
					if(!visited[w])
					{
						visited[w] = TRUE;
						Visit(G.adjmulist[w].data);
						EnQueue_L(&Q, w);
					}
				}
			}
		}
	}
}

void OutputAMLGraph(AMLGraph G)
{
	int k, j;
	EBox *p;
	
	if(!G.vexnum && !G.edgenum)
		printf("空图（表）！\n");
	else
	{
		ClearMark(G);
		
		printf("顶点：");
		for(k=1; k<=G.vexnum; k++)
			printf("%c ", G.adjmulist[k].data);
		printf("\n");
		
		printf("边  ：");
		for(k=1; k<=G.vexnum; k++)
		{
			if(G.adjmulist[k].firstedge)
			{
				p = G.adjmulist[k].firstedge;				
				while(p)
				{
					if(p->mark==unvisit)
					{
						printf("<%c,%c> ", G.adjmulist[p->ivex].data, G.adjmulist[p->jvex].data);
						p->mark = visit;						
					}
					
					if(p->ivex==k)
						p = p->ilink;
					else
						p = p->jlink;
				}
			}
		}
		printf("\n");
	}
}

void ClearMark(AMLGraph G)
{
	int k;
	
	for(k=1; k<=G.edgenum; k++)
		edgePtr[k]->mark = unvisit;
} 

void Input(FILE *fp, InfoType *info)
{
	//录入弧的信息，本文档涉及到的弧默认无其他信息 
}

#endif
