/***************************************
 *				                       *
 * �ļ���: ��07 ͼ\07 MiniSpanningTree *
 * 				                       *
 * �ļ���: MST.c                       *
 * 				                       *
 * ��  ����7.9                         *
 * 				                       *
 ***************************************/

#ifndef MST_C
#define MST_C

#include "MST.h"									//**��07 ͼ**//

void MinSpanTree_PRIM_1(MGraph G, VertexType_M u)	//����ͼ��Ȩֵ������0 
{
	int i, j, k; 
	Edge closedge[G.vexnum+1];						//0�ŵ�Ԫ����

	k = LocateVex_M(G, u);
	
	for(j=1; j<=G.vexnum; j++)						//���������ʼ�� 
	{
		if(j!=k)
		{
			
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j].adj; 
		}
	}
	
	closedge[k].lowcost = 0;
	
	printf("    %c\n", u);
	for(i=1; i<=G.vexnum-1; i++)					//�ܹ���ҪG.vexnum-1��Ѱ����С��
	{
		k = Minimum_1(closedge, G.vexnum);		
		printf("%2d, %c\n", closedge[k].lowcost, G.vexs[k]);

		closedge[k].lowcost = 0;
		
		for(j=1; j<=G.vexnum; j++)
		{											//��ǰ����ĳһ�������СȨֵС����һ������ĳһ�������СȨֵ 
			if(G.arcs[k][j].adj < closedge[j].lowcost)
			{	
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j].adj;
			}
		}
	}
}

int Minimum_1(Edge closedge[], int n)
{
	int i, j;
	int min = INT_MAX; 
	 
	for(i=1,j=0; i<=n; i++)
	{
		if(closedge[i].lowcost)						//��Ȩֵ��Ϊ0�ı���ѡ��ӵ����СȨֵ�ı� 
		{
			if(closedge[i].lowcost<=min)
			{
				min = closedge[i].lowcost;
				j = i;
			}
		}
	}
	
	return j;
}

void MinSpanTree_PRIM_2(MGraph G, VertexType_M u)
{
	int i, j, k;
	int start[G.vexnum+1], mark[G.vexnum+1];

	if(G.vexnum==1)
	{
		printf("��������ֻ��һ�����㣬����С������Ϊ��%c\n", G.vexs[1]);
		return;
	}

	k = LocateVex_M(G, u);
		
	for(j=1; j<=G.vexnum; j++)
	{
		start[j] = k;
		if(j!=k)
			mark[j] = 0;
		else
			mark[j] = 1;
	}
	
	for(i=1; i<=G.vexnum-1; i++)
	{
		k = Minimum_2(G, start, mark, G.vexnum);
		printf("%c��%c, %2d\n", G.vexs[start[k]], G.vexs[k], G.arcs[start[k]][k].adj);
		
		mark[k] = 1;
		
		for(j=1; j<=G.vexnum; j++)
		{
			if(mark[j]!=1)
			{
				if(G.arcs[k][j].adj<G.arcs[start[j]][j].adj)
					start[j] = k;
			}
		}
	}
}

int Minimum_2(MGraph G, int start[], int mark[], int n)
{
	int i, j;
	int min = INT_MAX; 
	
	for(i=1,j=0; i<=n; i++)
	{
		if(mark[i]!=1 && G.arcs[start[i]][i].adj<min)
		{
			min = G.arcs[start[i]][i].adj;
			j = i;
		}
	}
	
	return j;
}

void MinSpanTree_KRUSKAL(MGraph G)
{
	int i, j, count;
	int x, y;
	EdgeSetType r[100];
	MFSet S;								//ͼ�и����㼯�� 
	Relation R;
	
	if(G.vexnum==1)
	{
		printf("��������ֻ��һ�����㣬����С������Ϊ��%c\n", G.vexs[1]);
		return;
	}
	
	Initial(G, &S);

	count = 0;
	for(i=1; i<=G.vexnum; i++)				//�ҳ��������еĸ����� 
	{
		for(j=i; j<=G.vexnum; j++)
		{
			if(G.arcs[i][j].adj!=INFINITY)
			{
				++count;
				r[count].a = i;
				r[count].b = j;
				r[count].w = G.arcs[i][j].adj;
			}
		}
	}
	
	sort(r, 1, G.arcnum);					//�Ը����߸���Ȩ�ش�С�������� 
	
	count = 0;								//ͳ�Ƽ������ı��� 
	for(i=1; i<=G.arcnum; i++)
	{
		x = find_mfset(S, r[i].a);
		y = find_mfset(S, r[i].b);
		
		if(x!=y)							//ͨ�����鼯�жϼ���ı��Ƿ���γɻ�· 
		{
			BuildRelation(&R, r[i].a, r[i].b);		
			EquivalenceClass_mfset_1(&S, R);

			printf("%c��%c  %2d\n", G.vexs[r[i].a], G.vexs[r[i].b], r[i].w);
			
			if(++count==G.vexnum-1)
				break;
		}	
	}
}

void sort(EdgeSetType EdgeSet[], int left, int right)//�������� 
{
	int i, j;
	EdgeSetType tmp;
	
	i = left;
	j = right;
	
	if(i<j)
	{
		tmp = EdgeSet[left];
		
		while(i!=j)
		{
			while(i<j && EdgeSet[j].w>tmp.w)		//��������ɨ��
				j--;
			
			if(i<j)
			{
				EdgeSet[i] = EdgeSet[j];
				i++;
			}
			
			while(i<j && EdgeSet[i].w<tmp.w)		//��������ɨ��
				i++;
			
			if(i<j)
			{
				EdgeSet[j] = EdgeSet[i];
				j--;
			}
		}
		
		EdgeSet[i] = tmp;							//����i==j����ɵ�һ�ֿ��� 
		
		sort(EdgeSet, left, i-1);
		sort(EdgeSet, j+1, right);
	}
}

void Initial(MGraph G, MFSet *S)
{
	int i;
	FILE *fp;
	
	fp = tmpfile();									//��������һ����ʱ�ļ��� 
	
	fprintf(fp, "%d\n", G.vexnum);		
	for(i=1; i<=G.vexnum; i++)
		fprintf(fp, "%d ", i);
	fseek(fp, 0, SEEK_SET);
	
	Initial_mfset(fp, S);
}

void BuildRelation(Relation *R, int a, int b)
{	
	R->n = 1;
	R->nodes[0].i = a;
	R->nodes[0].j = b;
}

#endif 
