/******************************
 *					          *
 * 文件夹: ▲07 图\02 ALGraph *
 * 					          *
 * 文件名: ALGraph.c          *
 *    	    		          *
 ******************************/

#ifndef ALGRAPH_C
#define ALGRAPH_C

#include "ALGraph.h" 								//**▲07 图**//

Status CreateGraph_AL(FILE *fp, ALGraph *G)
{	
	Scanf(fp, "%d", &((*G).kind));

	switch((*G).kind)
	{
		case DG:
			return CreateDG_AL(fp, G);
		case UDG:
			return CreateUDG_AL(fp, G);
		default:
			return ERROR;
	}
}

Status CreateDG_AL(FILE *fp, ALGraph *G)
{
	int i, j, k;
	VertexType_AL v1, v2;
	char tmp;
	ArcNode *p;
	ArcNode *r[MAX_VERTEX_NUM+1];					//作为访问标记，用作定位 
	
	Scanf(fp, "%d%d%d", &((*G).vexnum), &((*G).arcnum), &((*G).IncInfo));
	Scanf(fp, "%c", &tmp);							//跳过换行符 
	
	for(i=1; i<=(*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).vertices[i].data));
		(*G).vertices[i].firstarc = NULL;
		r[i] = NULL;	
	}
	Scanf(fp, "%c", &tmp);							//跳过换行符
	
	for(k=1; k<=(*G).arcnum; k++)					//读取各边，制作邻接表 
	{
		Scanf(fp, "%c%c", &v1, &v2);
		
		i = LocateVex_AL(*G, v1);
		j = LocateVex_AL(*G, v2);
		
		if(!i || !j)								//保证获取的顶点存在 
			return ERROR;
		
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if(!p)
			exit(OVERFLOW);
		p->adjvex = j;
		p->nextarc = NULL;
		if((*G).IncInfo==1)							//表示有弧的其他信息，录入 
			Input(fp, &(p->info));
		
		if(r[i]==NULL)								//邻接表中第一个结点 
			(*G).vertices[i].firstarc = p;			//加入到邻接表 
		else
			r[i]->nextarc = p;
			
		r[i] = p;
	}
	
	return OK;	
}

Status CreateUDG_AL(FILE *fp, ALGraph *G)
{
	int i, j, k;
	VertexType_AL v1, v2;
	char tmp;
	ArcNode *p, *q;
	ArcNode *r[MAX_VERTEX_NUM+1];					//作为访问标记 
	
	Scanf(fp, "%d%d%d", &((*G).vexnum), &((*G).arcnum), &((*G).IncInfo));
	Scanf(fp, "%c", &tmp);							//跳过换行符 
	
	for(i=1; i<=(*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).vertices[i].data));
		(*G).vertices[i].firstarc = NULL;	
		r[i] = NULL;
	}
	Scanf(fp, "%c", &tmp);							//跳过换行符
	
	for(k=1; k<=(*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &v1, &v2);
		
		i = LocateVex_AL(*G, v1);
		j = LocateVex_AL(*G, v2);
		
		if(!i || !j)								//保证获取的顶点存在
			return ERROR;
		
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if(!p)
			exit(OVERFLOW);
		p->adjvex = j;
		p->nextarc = NULL;
		if((*G).IncInfo==1)							//表示有弧的其他信息，录入 
			Input(fp, &(p->info));
			
		if(r[i]==NULL)								//邻接表中第一个结点 
			(*G).vertices[i].firstarc = p;			//加入到邻接表 
		else
			r[i]->nextarc = p;			
		r[i] = p;		

		q = (ArcNode *)malloc(sizeof(ArcNode));
		if(!q)
			exit(OVERFLOW);
		q->adjvex = i;
		q->nextarc = NULL;
		if((*G).IncInfo==1)							//表示有弧的其他信息，录入 
			q->info = p->info;		

		if(r[j]==NULL)								//邻接表中第一个结点 
			(*G).vertices[j].firstarc = q;			//加入到邻接表 
		else
			r[j]->nextarc = q;			
		r[j] = q;
	}
	
	return OK;
}

void ClearGraph_AL(ALGraph *G)
{
	int i;
	ArcNode *p, *q;
	
	for(i=1; i<=(*G).vexnum; i++)
	{
		p = (*G).vertices[i].firstarc;
		while(p)
		{
			q = p;
			p = p->nextarc;
			free(q);
		}
	}

	(*G).vexnum = 0;
	(*G).arcnum = 0;
}
 
int LocateVex_AL(ALGraph G, VertexType_AL u)
{
	int i;
	
	for(i=1; i<=G.vexnum; i++)
	{
		if(G.vertices[i].data==u)
			return i;
	}
	
	return 0;
}

VertexType_AL GetVex_AL(ALGraph G, int order)
{
	if(order>=1 && order<=G.vexnum)
		return G.vertices[order].data;
	else
		return '\0';
} 

Status PutVex_AL(ALGraph *G, VertexType_AL v, VertexType_AL value)
{
	int k;
	
	k = LocateVex_AL(*G, v);
	
	if(k)
	{
		(*G).vertices[k].data = value;
		return OK;	
	}
	else
		return ERROR;
} 

int FirstAdjVex_AL(ALGraph G, VertexType_AL v)
{
	int k;
	ArcNode *p;
	
	k = LocateVex_AL(G, v);
	
	if(k && G.vertices[k].firstarc)
		return G.vertices[k].firstarc->adjvex;
	
	return 0;
} 

int NextAdjVex_AL(ALGraph G, VertexType_AL v, VertexType_AL w)
{
	int k1, k2;
	ArcNode *p, *q;
	
	k1 = LocateVex_AL(G, v);
	k2 = LocateVex_AL(G, w);
	
	if(k1 && k2)
	{
		for(p=G.vertices[k1].firstarc; p; p=p->nextarc)
		{
			if(p->adjvex==k2)
			{
				if(p->nextarc)
					return p->nextarc->adjvex;
				else
					return 0;	
			}
		}	
	}
 
	return 0;									//结点v和结点w并不连通 
} 

Status InsertVex_AL(ALGraph *G, VertexType_AL v)
{
	int i, k, t;
	
	if((*G).vexnum==MAX_VERTEX_NUM)
		return ERROR;							//顶点数已满 

	(*G).vexnum++;
	
	(*G).vertices[(*G).vexnum].data = v;
	(*G).vertices[(*G).vexnum].firstarc = NULL;
	
	return OK;	
} 

Status DeleteVex_AL(ALGraph *G, VertexType_AL v)
{
	int i, k;
	ArcNode *p, *q;
	
	k = LocateVex_AL(*G, v);	
	if(!k)								//删除的顶点需存在 
		return ERROR;
	
	p = (*G).vertices[k].firstarc;		//释放v的邻接表
	while(p)
	{
		q = p;
		p = p->nextarc;
		DeleteArc_AL(G, v, (*G).vertices[q->adjvex].data); 
	}
	
	for(i=k+1; i<=(*G).vexnum; i++)		//移动顶点 
	{
		(*G).vertices[i-1].data = (*G).vertices[i].data;
		(*G).vertices[i-1].firstarc = (*G).vertices[i].firstarc;
	}
	
	(*G).vexnum--;						//顶点数减一 

	if((*G).kind==DG)					//有向图
	{
		for(i=1; i<=(*G).vexnum; i++)
		{
			p = (*G).vertices[i].firstarc;

			while(p && p->adjvex<k)
			{
				q = p;
				p = p->nextarc;
			}
				
			if(p)
			{
				if(p->adjvex==k)
				{
					if(p==(*G).vertices[i].firstarc)	//删除首结点 
						(*G).vertices[i].firstarc = p->nextarc;
					else
						q->nextarc = p->nextarc;				
					
					free(p);
					
					(*G).arcnum--;		//弧数减一		
				}
			}
		}
	} 
	
	return OK;	
}

Status InsertArc_AL(ALGraph *G, VertexType_AL v, VertexType_AL w, ...)
{
	int k1, k2;
	ArcNode *p, *q;
	va_list ap;											
	
	k1 = LocateVex_AL(*G, v);
	k2 = LocateVex_AL(*G, w);
	
	if(!k1 || !k2)
		return ERROR;
		
	p = (ArcNode *)malloc(sizeof(ArcNode));
	if(!p)
		exit(OVERFLOW);
	p->adjvex = k2;
	 
	va_start(ap, w);									//若存在弧信息，则录入
	p->info = va_arg(ap, InfoType);						//结构可直接复制	
	va_end(ap);	
	
	q = (*G).vertices[k1].firstarc;
	if(!q || q->adjvex>k2)
	{
		p->nextarc = (*G).vertices[k1].firstarc;		//加入到邻接表 
		(*G).vertices[k1].firstarc = p;
	}
	else												//q->adjvex<k2
	{
		while(q->nextarc && q->nextarc->adjvex<k2)
			q = q->nextarc;
		p->nextarc = q->nextarc;
		q->nextarc = p;
	}
	
	if((*G).kind==UDG)									//无向图
	{
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if(!p)
			exit(OVERFLOW);
		p->adjvex = k1;
		
		va_start(ap, w);								//存在弧信息，则录入
		p->info = va_arg(ap, InfoType);					//结构可直接复制		
		va_end(ap);
			
		q = (*G).vertices[k2].firstarc;
		if(!q || q->adjvex>k1)
		{
			p->nextarc = (*G).vertices[k2].firstarc;	//加入到邻接表 
			(*G).vertices[k2].firstarc = p;
		}
		else											//q->adjvex<k1
		{
			while(q->nextarc && q->nextarc->adjvex<k1)
				q = q->nextarc;
			p->nextarc = q->nextarc;
			q->nextarc = p;
		}		
	}

	(*G).arcnum++;									//弧数增一 
		
	return OK;	
}

Status DeleteArc_AL(ALGraph *G, VertexType_AL v, VertexType_AL w)
{
	int k1, k2;
	ArcNode *p, *q;
	
	k1 = LocateVex_AL(*G, v);
	k2 = LocateVex_AL(*G, w);
	
	if(!k1 || !k2)
		return ERROR;

	p = (*G).vertices[k1].firstarc;
	if(p && p->adjvex==k2)
	{
		(*G).vertices[k1].firstarc = p->nextarc;
		free(p);
	}
	else
	{
		while(p && p->adjvex!=k2)
		{
			q = p;
			p = p->nextarc;
		}
		
		if(!p)
			return ERROR;								//欲删除的边不存在
		else
		{
			q->nextarc = p->nextarc;
			free(p);
		}	 
	}
	
	if((*G).kind==UDG)									//无向图
	{
		p = (*G).vertices[k2].firstarc;
		if(p && p->adjvex==k1)
		{
			(*G).vertices[k2].firstarc = p->nextarc;
			free(p);
		}
		else
		{
			while(p && p->adjvex!=k1)
			{
				q = p;
				p = p->nextarc;
			}
			
			if(!p)
				return ERROR;							//欲删除的边不存在
			else
			{
				q->nextarc = p->nextarc;
				free(p);
			}	 
		}	
	}	

	(*G).arcnum--;										//弧数减一
		
	return OK;
}

void DFSTraverse_AL(ALGraph G, void (Visit)(VertexType_AL))
{
	int v;
	
	VisitFunc = Visit;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;					//初始化为未访问
	
	for(v=1; v<=G.vexnum; v++)
	{
		if(!visited[v])						//未访问
			DFS_AL(G, v); 
	} 
}

void DFS_AL(ALGraph G, int v)
{
	int w;

	visited[v] = TRUE;

	VisitFunc(G.vertices[v].data);

	for(w=FirstAdjVex_AL(G, G.vertices[v].data); w; w=NextAdjVex_AL(G, G.vertices[v].data, G.vertices[w].data))
	{
		if(!visited[w])
			DFS_AL(G, w);
	}
}

void BFSTraverse_AL(ALGraph G, void (Visit)(VertexType_AL))
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
			Visit(G.vertices[v].data);
			EnQueue_L(&Q, v);
			while(!QueueEmpty_L(Q))
			{
				DeQueue_L(&Q, &e);
				for(w=FirstAdjVex_AL(G, G.vertices[e].data); w; w=NextAdjVex_AL(G, G.vertices[e].data, G.vertices[w].data))
				{
					if(!visited[w])
					{
						visited[w] = TRUE;
						Visit(G.vertices[w].data);
						EnQueue_L(&Q, w);
					}
				}
			}
		}
	}
}

void OutputALGraph(ALGraph G)
{
	int i, j;
	ArcNode *p;
	
	if(!G.vexnum && !G.arcnum)
		printf("空图（表）！\n");
	else
	{
		for(i=1; i<=G.vexnum; i++)
		{
			printf("%c→", G.vertices[i].data);
			p = G.vertices[i].firstarc;
			while(p)
			{
				printf(" %c", G.vertices[p->adjvex].data);
				p = p->nextarc;
			}
			printf("\n");	
		}
	}
}

void Input(FILE *fp, InfoType *info)
{
	//录入弧的信息，本文档涉及到的弧默认无其他信息
#if defined CRITICALPATH_H || \
    defined Question_7
	Scanf(fp, "%d", &(info->in));
#endif
}

#endif
