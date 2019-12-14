#ifndef Question_7
#define Question_7

#include <stdio.h>
#include <limits.h>
#include "../../../���α��㷨ʵ��/��07 ͼ/02 ALGraph/ALGraph.c"		//**��07 ͼ**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/07 ChildSiblingTree/ChildSiblingTree.c"

/* ����ԭ�� */
CSTree MinSpanTree_PRIM_7_32(ALGraph G, VertexType_AL u);
int GetInfo_7_32(ALGraph G, int i, int j);							//��ȡ��<i,j>����Ϣ��Ȩֵ�� 
int Minimum_7_32(ALGraph G, int strat[], int mark[], int n);		//�ҳ�����С���롱 
void AddEdgeToTree_7_32(CSTree *T, char v, char w);					//��ӱ�<v,w>�����У�vΪ���ӵ� 

int main(int argc, char *argv[])
{
    ALGraph G;
    FILE *fp;										//��Ϊ����Դ
	CSTree T;

	printf("�������������ͼ����Ȩ��...\n");	
	fp = fopen("Data/Algo_7_32.txt", "r");
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");	

	T = MinSpanTree_PRIM_7_32(G, 'A');
	printf("��������ͨ������С������Ϊ��\n");
	Print_CS(T);
	printf("\n");
}

/*������������������������������������������
����7.32����С������������ķ�㷨���ڽӱ���
������������������������������������������*/
CSTree MinSpanTree_PRIM_7_32(ALGraph G, VertexType_AL u)//����ͼ��Ȩֵ������0 
{
	int i, j, k; 
	int start[G.vexnum+1];			//��ǵ�ǰ�����������ıߵ���ʼ���� 
	int mark[G.vexnum+1];			//��ǵ�i�������Ƿ��Ѽ�����С������ 
	CSTree T;
	
	InitTree_CS(&T);
	k = LocateVex_AL(G, u);
	
	for(j=1; j<=G.vexnum; j++)						//���������ʼ�� 
	{
		start[j] = k;
		if(j!=k)
			mark[j] = 0;
		else
			mark[j] = 1;
	}
	
	for(i=1; i<=G.vexnum-1; i++)		//�ܹ���ҪG.vexnum-1��Ѱ����С��
	{
		k = Minimum_7_32(G, start, mark, G.vexnum);
		
		AddEdgeToTree_7_32(&T, G.vertices[start[k]].data, G.vertices[k].data);//��ӱߵ��� 
		
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
	
	return INT_MAX;							//����ߵ�Ȩֵ������0	
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
