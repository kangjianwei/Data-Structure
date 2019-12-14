/***********************************
 *						           *
 * �ļ���: ��07 ͼ\01 MGraph       *
 * 						           *
 * �ļ���: MGraph.c                *
 *    	    			           *
 * ��  ��: 7.1��7.2��7.4��7.5��7.6 * 
 *    	    					   *
 ***********************************/

#ifndef MGRAPH_C
#define MGRAPH_C

#include "MGraph.h" 								//**��07 ͼ**//

/*�T�T�T�T�[
�U �㷨7.1�U 
�^�T�T�T�T*/
Status CreateGraph_M(FILE *fp, MGraph *G)
{	
	Scanf(fp, "%d", &((*G).kind));

	switch((*G).kind)								//�����������ͼ����������ͼ����һ�֡� 
	{
		case DG:
			return CreateDG_M(fp, G);
		case DN:
			return CreateDN_M(fp, G);
		case UDG:
			return CreateUDG_M(fp, G);
		case UDN:
			return CreateUDN_M(fp, G);
		default:
			return ERROR;
	}
}

Status CreateDG_M(FILE *fp, MGraph *G)
{
	int i, j, k;
	VertexType_M v1, v2;
	char tmp;
	
	Scanf(fp, "%d%d%d", &((*G).vexnum), &((*G).arcnum), &((*G).IncInfo));
	Scanf(fp, "%c", &tmp);						//�������з� 
	
	for(i=1; i<=(*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));
	Scanf(fp, "%c", &tmp);						//�������з�
	
	for(i=1; i<=(*G).vexnum; i++)				//��ʼ���ڽӾ��� 
	{
		for(j=1; j<=(*G).vexnum; j++)
			(*G).arcs[i][j].adj = 0;		
	}
	
	for(k=1; k<=(*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &v1, &v2);
		
		i = LocateVex_M(*G, v1);
		j = LocateVex_M(*G, v2);
		
		if(!i || !j)
			return ERROR;
		
		(*G).arcs[i][j].adj = 1;
		if((*G).IncInfo==1)						//���л���������Ϣ����¼�� 
			Input(fp, &((*G).arcs[i][j].info));
	}
	
	return OK;	
}

Status CreateDN_M(FILE *fp, MGraph *G)
{
	int i, j, k;
	VertexType_M v1, v2;
	VRType w;
	char tmp;
	
	Scanf(fp, "%d%d%d", &((*G).vexnum), &((*G).arcnum), &((*G).IncInfo));
	Scanf(fp, "%c", &tmp);						//�������з� 
	
	for(i=1; i<=(*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));
	Scanf(fp, "%c", &tmp);						//�������з�
	
	for(i=1; i<=(*G).vexnum; i++)					//��ʼ���ڽӾ��� 
	{
		for(j=1; j<=(*G).vexnum; j++)
			(*G).arcs[i][j].adj = INFINITY;		
	}
	
	for(k=1; k<=(*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &v1, &v2, &w);
		
		i = LocateVex_M(*G, v1);
		j = LocateVex_M(*G, v2);
		
		if(!i || !j)
			return ERROR;
		
		(*G).arcs[i][j].adj = w;
		if((*G).IncInfo==1)							//���л���������Ϣ����¼�� 
			Input(fp, &((*G).arcs[i][j].info));
	}
	
	return OK;
}

Status CreateUDG_M(FILE *fp, MGraph *G)
{
	int i, j, k;
	VertexType_M v1, v2;
	char tmp;
	
	Scanf(fp, "%d%d%d", &((*G).vexnum), &((*G).arcnum), &((*G).IncInfo));
	Scanf(fp, "%c", &tmp);							//�������з� 
	
	for(i=1; i<=(*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));
	Scanf(fp, "%c", &tmp);							//�������з�
	
	for(i=1; i<=(*G).vexnum; i++)					//��ʼ���ڽӾ��� 
	{
		for(j=1; j<=(*G).vexnum; j++)
			(*G).arcs[i][j].adj = 0;		
	}
	
	for(k=1; k<=(*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &v1, &v2);
		
		i = LocateVex_M(*G, v1);
		j = LocateVex_M(*G, v2);
		
		if(!i || !j)
			return ERROR;
		
		(*G).arcs[i][j].adj = 1;
		if((*G).IncInfo==1)							//���л���������Ϣ����¼�� 
			Input(fp, &((*G).arcs[i][j].info));
		
		(*G).arcs[j][i] = (*G).arcs[i][j];			//���ԳƵ� 
	}
	
	return OK;
}

/*�T�T�T�T�[
�U �㷨7.2�U 
�^�T�T�T�T*/
Status CreateUDN_M(FILE *fp, MGraph *G)
{
	int i, j, k;
	VertexType_M v1, v2;
	VRType w;
	char tmp;
	
	Scanf(fp, "%d%d%d", &((*G).vexnum), &((*G).arcnum), &((*G).IncInfo));
	Scanf(fp, "%c", &tmp);							//�������з� 
	
	for(i=1; i<=(*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));
	Scanf(fp, "%c", &tmp);							//�������з�
	
	for(i=1; i<=(*G).vexnum; i++)					//��ʼ���ڽӾ��� 
	{
		for(j=1; j<=(*G).vexnum; j++)
			(*G).arcs[i][j].adj = INFINITY;		
	}
	
	for(k=1; k<=(*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &v1, &v2, &w);
		
		i = LocateVex_M(*G, v1);
		j = LocateVex_M(*G, v2);
		
		if(!i || !j)
			return ERROR;
		
		(*G).arcs[i][j].adj = w;
		if((*G).IncInfo==1)							//���л���������Ϣ����¼�� 
			Input(fp, &((*G).arcs[i][j].info));
		
		(*G).arcs[j][i] = (*G).arcs[i][j];			//���ԳƵ� 
	}
	
	return OK;
}

void ClearGraph_M(MGraph *G)
{
	(*G).vexnum = 0;
	(*G).arcnum = 0;
	(*G).IncInfo = 0;
}
 
int LocateVex_M(MGraph G, VertexType_M u)
{
	int i;
	
	for(i=1; i<=G.vexnum; i++)
	{
		if(G.vexs[i]==u)
			return i;
	}
	
	return 0;
}

VertexType_M GetVex_M(MGraph G, int order)
{
	if(order>=1 && order<=G.vexnum)
		return G.vexs[order];
	else
		return '\0';
} 

Status PutVex_M(MGraph *G, VertexType_M v, VertexType_M value)
{
	int k;
	
	k = LocateVex_M(*G, v);
	
	if(k)
	{
		(*G).vexs[k] = value;
		return OK;	
	}
	else
		return ERROR;
} 

int FirstAdjVex_M(MGraph G, VertexType_M v)
{
	int k, j, t;
	
	k = LocateVex_M(G, v);
	
	if(k)
	{	
		if(G.kind%2)				//��
			t = INFINITY;
		else						//ͼ 
			t = 0;

		for(j=1; j<=G.vexnum; j++)
		{
			if(G.arcs[k][j].adj!=t)
				return j;
		}
	}
	
	return 0;
} 

int NextAdjVex_M(MGraph G, VertexType_M v, VertexType_M w)
{
	int k1, k2, j, t;
	
	k1 = LocateVex_M(G, v);
	k2 = LocateVex_M(G, w);
	
	if(k1 && k2)
	{
		if(G.kind%2)				//��
			t = INFINITY;
		else						//ͼ 
			t = 0;

		for(j=k2+1; j<=G.vexnum; j++)
		{
			if(G.arcs[k1][j].adj!=t)
				return j;
		}
	}
	
	return 0;
} 

Status InsertVex_M(MGraph *G, VertexType_M v)
{
	int i, k, t;
	
	if((*G).vexnum==MAX_VERTEX_NUM)
		return ERROR;				//���������� 
	
	if((*G).kind%2)					//��
		t = INFINITY;
	else							//ͼ 
		t = 0;
	
	k = (*G).vexnum + 1;
	(*G).vexs[k] = v;
	
	for(i=1; i<=k; i++)
	{
		(*G).arcs[i][k].adj = t;	
		(*G).arcs[k][i].adj = t;
	}
	
	(*G).vexnum++;
	
	return OK;	
} 

Status DeleteVex_M(MGraph *G, VertexType_M v)
{
	int i, j, k, t;
	
	// ��ɾ��������� 
	k = LocateVex_M(*G, v);
	
	if(!k)
		return ERROR;

	if((*G).kind%2)							//��
		t = INFINITY;
	else									//ͼ 
		t = 0;	
		
	for(i=1; i<=k; i++)
	{
		if((*G).arcs[k][i].adj!=t)			//�����µĻ��� 
			(*G).arcnum--;
		
		if((*G).kind==DG || (*G).kind==DN)	//����
		{
			if((*G).arcs[i][k].adj!=t)
				(*G).arcnum--;			
		} 
	}
	
	/* ���ڽӾ�����ɾ���ö������ڵ������� */ 
	
	// ����ǰ���� 
	for(i=1; i<=(*G).vexnum; i++)
	{
		for(j=k+1; j<=(*G).vexnum; j++)
			(*G).arcs[i][j-1] = (*G).arcs[i][j];
	}
	
	// �����ϸ��� 
	for(i=k+1; i<=(*G).vexnum; i++)
	{
		for(j=1; j<=(*G).vexnum-1; j++)
			(*G).arcs[i-1][j] = (*G).arcs[i][j];
	}
	
	// �Ӷ���������ɾ���ö������Ϣ 
	for(i=k; i<(*G).vexnum; i++) 
	{
		(*G).vexs[i] = (*G).vexs[i+1];
	}
	
	// ��������һ 
	(*G).vexnum--;
	
	return OK;	
} 

Status InsertArc_M(MGraph *G, VertexType_M v, VertexType_M w, VRType adj, ...)
{
	int k1, k2;
	
	k1 = LocateVex_M(*G, v);
	k2 = LocateVex_M(*G, w);
	
	if(!k1 || !k2)
		return ERROR;
		
	(*G).arcs[k1][k2].adj = adj;					//������Ϣ�����ڣ�Ȩֵ���� 

	va_list ap;										//���ڻ���������Ϣ����¼�� 
	va_start(ap, adj);
	(*G).arcs[k1][k2].info = va_arg(ap, InfoType);	//�ṹ��ֱ�Ӹ���	
	va_end(ap);
	
	if((*G).kind==UDG || (*G).kind==UDN)	//����	
		(*G).arcs[k2][k1] = (*G).arcs[k1][k2];
	
	(*G).arcnum++;							//������һ 
		
	return OK;	
} 

Status DeleteArc_M(MGraph *G, VertexType_M v, VertexType_M w)
{
	int k1, k2;
	
	k1 = LocateVex_M(*G, v);
	k2 = LocateVex_M(*G, w);
	
	if(!k1 || !k2)
		return ERROR;
	
	if((*G).kind%2)							//��
		(*G).arcs[k1][k2].adj = INFINITY;
	else									//ͼ 
		(*G).arcs[k1][k2].adj = 0;
	
	if((*G).kind==UDG || (*G).kind==UDN)	//����	
		(*G).arcs[k2][k1] = (*G).arcs[k1][k2];	

	(*G).arcnum--;							//������һ 
		
	return OK;
}

/*�T�T�T�T�[
�U �㷨7.4�U 
�^�T�T�T�T*/
void DFSTraverse_M(MGraph G, void(Visit)(VertexType_M))
{
	int v;
	
	VisitFunc = Visit;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;					//��ʼ��Ϊδ����
	
	for(v=1; v<=G.vexnum; v++)
	{
		if(!visited[v])						//δ����
			DFS_M(G, v); 
	} 
}

/*�T�T�T�T�[
�U �㷨7.5�U 
�^�T�T�T�T*/
void DFS_M(MGraph G, int v)
{
	int w;

	visited[v] = TRUE;

	VisitFunc(G.vexs[v]);

	for(w=FirstAdjVex_M(G, G.vexs[v]); w; w=NextAdjVex_M(G, G.vexs[v], G.vexs[w]))
	{
		if(!visited[w])
			DFS_M(G, w);
	}
}

/*�T�T�T�T�[
�U �㷨7.6�U 
�^�T�T�T�T*/
void BFSTraverse_M(MGraph G, void(Visit)(VertexType_M))
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
			Visit(G.vexs[v]);
			EnQueue_L(&Q, v);
			while(!QueueEmpty_L(Q))
			{
				DeQueue_L(&Q, &e);
				for(w=FirstAdjVex_M(G, G.vexs[e]); w; w=NextAdjVex_M(G, G.vexs[e], G.vexs[w]))
				{
					if(!visited[w])
					{
						visited[w] = TRUE;
						Visit(G.vexs[w]);
						EnQueue_L(&Q, w);
					}
				}
			}
		}
	}
}

void OutputMGraph(MGraph G)
{
	int i, j;
	
	if(!G.vexnum && !G.arcnum)
		printf("��ͼ������\n");
	else
	{
		printf("  ");
		for(i=1; i<=G.vexnum; i++)
			printf("%2c ", G.vexs[i]);
		printf("\n");
		
		for(i=1; i<=G.vexnum; i++)
		{
			printf("%c ", G.vexs[i]);
			for(j=1; j<=G.vexnum; j++)
			{
				if(G.arcs[i][j].adj==INFINITY)
					printf("�� ");
				else
					printf("%2d ", G.arcs[i][j]);
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
