/******************************
 *					          *
 * �ļ���: ��07 ͼ\03 OLGraph *
 * 					          *
 * �ļ���: OLGraph.c          *
 *    	    		          *
 * ��  ��: 7.3                * 
 *    	    		          *
 ******************************/

#ifndef OLGRAPH_C
#define OLGRAPH_C

#include "OLGraph.h" 								//**��07 ͼ**//

/*�T�T�T�T�[
�U �㷨7.3�U 
�^�T�T�T�T*/
Status CreateDG_OL(FILE *fp, OLGraph *G)
{
	int i, j, k;
	VertexType_OL v1, v2;
	char tmp;
	ArcBox *p;
	
	Scanf(fp, "%d%d%d", &((*G).vexnum), &((*G).arcnum), &((*G).IncInfo));
	Scanf(fp, "%c", &tmp);							//�������з� 
	
	for(i=1; i<=(*G).vexnum; i++)					//�����ͷ���� 
	{
		Scanf(fp, "%c", &((*G).xlist[i].data));		//���붥��ֵ	
		(*G).xlist[i].firstin = NULL;				//��ʼ��ָ�� 
		(*G).xlist[i].firstout = NULL;
	}
	Scanf(fp, "%c", &tmp);							//�������з�
		
	for(k=1; k<=(*G).arcnum; k++)					//�������������ʮ������ 
	{
		Scanf(fp, "%c%c", &v1, &v2);				//����һ��������ʼ����յ� 
				
		i = LocateVex_OL(*G, v1);					//ȷ��v1��v2��G��λ�� 
		j = LocateVex_OL(*G, v2);
		
		if(!i || !j)
			return ERROR;

		p = (ArcBox *)malloc(sizeof(ArcBox));		//�ٶ����㹻�ռ� 
		if(!p)
			exit(OVERFLOW);
		
		p->tailvex = i;								//�Ի����Ͷ����㸳ֵ 
		p->headvex = j;
		
		p->hlink = (*G).xlist[j].firstin;
		(*G).xlist[j].firstin = p;
		
		p->tLink = (*G).xlist[i].firstout;
		(*G).xlist[i].firstout = p;
		
		if((*G).IncInfo==1)							//��ʾ�л���������Ϣ��¼�� 
			Input(fp, &(p->info));		
	}
	
	return OK;	
}

void ClearGraph_OL(OLGraph *G)
{
	int i;
	ArcBox *p, *q;
	
	for(i=1; i<=(*G).vexnum; i++)
	{
		p = (*G).xlist[i].firstout;
		while(p)
		{
			q = p;
			p = p->tLink;
			free(q);
		}
	}
	
	(*G).vexnum = 0;
	(*G).arcnum = 0;
}
 
int LocateVex_OL(OLGraph G, VertexType_OL u)
{
	int i;
	
	for(i=1; i<=G.vexnum; i++)
	{
		if(G.xlist[i].data==u)
			return i;
	}
	
	return 0;
}

VertexType_OL GetVex_OL(OLGraph G, int order)
{
	if(order>=1 && order<=G.vexnum)
		return G.xlist[order].data;
	else
		return '\0';
} 

Status PutVex_OL(OLGraph *G, VertexType_OL v, VertexType_OL value)
{
	int k;
	
	k = LocateVex_OL(*G, v);
	
	if(k)
	{
		(*G).xlist[k].data = value;
		return OK;	
	}
	else
		return ERROR;
}

int FirstAdjVex_OL(OLGraph G, VertexType_OL v)
{
	int k;
	
	k = LocateVex_OL(G, v);
	
	if(k)
	{
		if(G.xlist[k].firstout)
			return G.xlist[k].firstout->headvex;
	}
	
	return 0;
} 

int NextAdjVex_OL(OLGraph G, VertexType_OL v, VertexType_OL w)
{
	int k1, k2;
	ArcBox *p, *q;
	
	k1 = LocateVex_OL(G, v);
	k2 = LocateVex_OL(G, w);
	
	if(k1 && k2)
	{
		if(G.xlist[k1].firstout && G.xlist[k1].firstout->tLink)
		{
			p = G.xlist[k1].firstout;
			q = p->tLink;
			
			while(p->headvex!=k2 && q->tLink)
			{
				p = q;
				q = q->tLink;
			}
			
			if(p->headvex==k2)
				return q->headvex;
		}	
	}
	
	return 0;
} 

Status InsertVex_OL(OLGraph *G, VertexType_OL v)
{
	int i, k, t;
	
	if((*G).vexnum==MAX_VERTEX_NUM)
		return ERROR;				//���������� 

	(*G).vexnum++;
	
	(*G).xlist[(*G).vexnum].data = v;
	(*G).xlist[(*G).vexnum].firstin = NULL;
	(*G).xlist[(*G).vexnum].firstout = NULL;
	
	return OK;	
} 

Status DeleteVex_OL(OLGraph *G, VertexType_OL v)
{
	int i, k;
	ArcBox *p;
	
	k = LocateVex_OL(*G, v);
	
	if(!k)
		return ERROR;
	
	while((*G).xlist[k].firstout)						//ɾ���Ӷ���v�����Ļ� 
	{
		p = (*G).xlist[k].firstout;
		DeleteArc_OL(G, (*G).xlist[p->tailvex].data, (*G).xlist[p->headvex].data);
	}
	
	while((*G).xlist[k].firstin)						//ɾ��ָ�򶥵�v�Ļ�������������ͼ����������
	{
		p  = (*G).xlist[k].firstin;
		DeleteArc_OL(G, (*G).xlist[p->tailvex].data, (*G).xlist[p->headvex].data);		
	}
	
	for(i=k+1; i<=(*G).vexnum; i++)						//���°��Ÿ�����λ�� 
	{
		(*G).xlist[i-1].data = (*G).xlist[i].data;
		(*G).xlist[i-1].firstin = (*G).xlist[i].firstin;
		(*G).xlist[i-1].firstout = (*G).xlist[i].firstout;
	}
	
	(*G).vexnum--;
	
	return OK;	
}

Status InsertArc_OL(OLGraph *G, VertexType_OL v, VertexType_OL w, ...)
{
	int k1, k2;
	ArcBox *p, *q, *r;
	
	k1 = LocateVex_OL(*G, v);
	k2 = LocateVex_OL(*G, w);
	
	if(!k1 || !k2)
		return ERROR;
		
	p = (ArcBox *)malloc(sizeof(ArcBox));
	if(!p)
		exit(OVERFLOW);
	p->tailvex = k1;
	p->headvex = k2;
	
	va_list ap;											//���ڻ���Ϣ����¼�� 
	va_start(ap, w);
	p->info = va_arg(ap, InfoType);						//�ṹ��ֱ�Ӹ���	
	va_end(ap);	
	
	q = (*G).xlist[k1].firstout;
	if(!q || q->headvex>p->headvex)
	{
		p->tLink = q;
		(*G).xlist[k1].firstout = p;	
	}
	else
	{
		while(q->tLink && q->tLink->headvex<p->headvex)
			q = q->tLink;
		
		p->tLink = q->tLink;
		q->tLink = p;
	}

	
	r = (*G).xlist[k2].firstin;
	if(!r || r->tailvex>p->tailvex)
	{
		p->hlink = r;
		(*G).xlist[k2].firstin = p;	
	}
	else
	{
		while(r->hlink && r->hlink->tailvex<p->tailvex)
			r = r->hlink;
		
		p->hlink = r->hlink;
		r->hlink = p;	
	}
		
	(*G).arcnum++;									//������һ 
		
	return OK;	
}

Status DeleteArc_OL(OLGraph *G, VertexType_OL v, VertexType_OL w)
{
	int k1, k2;
	ArcBox *p, *q, *r;
	
	k1 = LocateVex_OL(*G, v);
	k2 = LocateVex_OL(*G, w);
	
	if(!k1 || !k2)
		return ERROR;

	p = (*G).xlist[k1].firstout;
	if(p && p->headvex==k2)
		(*G).xlist[k1].firstout = p->tLink;
	else
	{
		q = p;
		p = p->tLink;
		while(p && p->headvex!=k2)
		{
			q = p;
			p = p->tLink;
		}
		
		if(p)
			q->tLink = p->tLink;
		else										//��ɾ���Ļ������� 
			return ERROR;
	}
	
	p = (*G).xlist[k2].firstin;
	if(p->tailvex==k1)
		(*G).xlist[k2].firstin = p->hlink;
	else
	{
		r = p;
		p = p->hlink;
		while(p->tailvex!=k1)
		{
			r = p;
			p = p->hlink;
		}
		
		r->hlink = p->hlink;
	}
		
	free(p);
	
	(*G).arcnum--;							//������һ
		
	return OK;
}

void DFSTraverse_OL(OLGraph G, void (Visit)(VertexType_OL))
{
	int v;
	
	VisitFunc = Visit;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;					//��ʼ��Ϊδ����
	
	for(v=1; v<=G.vexnum; v++)
	{
		if(!visited[v])						//δ����
			DFS_OL(G, v); 
	} 
}

void DFS_OL(OLGraph G, int v)
{
	int w;

	visited[v] = TRUE;

	VisitFunc(G.xlist[v].data);

	for(w=FirstAdjVex_OL(G, G.xlist[v].data); w; w=NextAdjVex_OL(G, G.xlist[v].data, G.xlist[w].data))
	{
		if(!visited[w])
			DFS_OL(G, w);
	}
}

void BFSTraverse_OL(OLGraph G, void (Visit)(VertexType_OL))
{
	int v, w;
	LinkQueue Q;
	QElemType_L e;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;					//��ʼ��Ϊδ����
	
	InitQueue_L(&Q);		
	
	for(v=1; v<=G.vexnum; v++)
	{
		if(!visited[v])
		{
			visited[v] = TRUE;
			Visit(G.xlist[v].data);
			EnQueue_L(&Q, v);
			while(!QueueEmpty_L(Q))
			{
				DeQueue_L(&Q, &e);
				for(w=FirstAdjVex_OL(G, G.xlist[e].data); w; w=NextAdjVex_OL(G, G.xlist[e].data, G.xlist[w].data))
				{
					if(!visited[w])
					{
						visited[w] = TRUE;
						Visit(G.xlist[w].data);
						EnQueue_L(&Q, w);
					}
				}
			}
		}
	}
}

void OutputOLGraph(OLGraph G)
{
	int i, j;
	ArcBox *p;
	
	if(!G.vexnum && !G.arcnum)
		printf("��ͼ������\n");
	else
	{
		for(i=1; i<=G.vexnum; i++)
		{
			printf("%c�� ", G.xlist[i].data);
			p = G.xlist[i].firstout;
			j = 1;
			while(p)
			{
				while(p->headvex!=j)
				{
					printf("      ");
					j++;
				}
				printf("(%-c %c) ", G.xlist[p->tailvex].data, G.xlist[p->headvex].data);
				p = p->tLink;
				j++;
			}
			printf("\n");	
		}
	}
}

void Input(FILE *fp, InfoType *info)
{
	//¼�뻡����Ϣ�����ĵ��漰���Ļ�Ĭ����������Ϣ 
}

#endif
