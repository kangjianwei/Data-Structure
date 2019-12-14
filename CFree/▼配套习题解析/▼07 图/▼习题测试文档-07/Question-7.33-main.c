#ifndef Question_7
#define Question_7

#include <stdio.h>
#include <limits.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/02 ALGraph/ALGraph.c"				//**��07 ͼ**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/07 ChildSiblingTree/ChildSiblingTree.c"//**��06 ���Ͷ�����**//

/* ���Ͷ��� */
typedef int MFSet; 						//���鼯 
typedef	struct							//�ߵļ��� 
{
	int u, v;							//�˵� 
	int Weight;							//Ȩֵ 
}EdgeSetType;
typedef	struct							//����Ȩֵ�ıߵļ��� 
{
	char u;
	char v;								//�˵� 
}Edge;

/* ����ԭ�� */
CSTree MinSpanTree_KRUSKAL_7_33(ALGraph G);
void InitEdgeSet_7_33(EdgeSetType EdgeSet[], ALGraph G);		//��ʼ���߼� 
Status GetMinEdge_7_33(EdgeSetType EdgeSet[], int *u, int *v);	//��ȡ��С��<u, v>
void DelMinEdge_7_33(EdgeSetType EdgeSet[], int u, int v);		//ɾ����<u, v> 
void InitMFSet_7_33(MFSet S[], ALGraph G);						//��ʼ�����鼯 
int FindSeat_7_33(MFSet S[], int u);							//���ض���u���ڼ��� 
void Merge_7_33(MFSet S[], int u, int v);						//������u���뼯��v 
CSTree CreateCSTree_7_33(Edge E[]);								//���ݱ߼������� 
void AddEdgeToTree_7_33(CSTree *T, char v, char w);				//��ӱ�<v,w>�����У�vΪ���ӵ�

int main(int argc, char *argv[])
{
    ALGraph G;
    FILE *fp;										//��Ϊ����Դ
	CSTree T;

	printf("�������������ͼ����Ȩ��...\n");	
	fp = fopen("Data/Algo_7_33.txt", "r");
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");	
	
	T= MinSpanTree_KRUSKAL_7_33(G);
	printf("��������ͨ������С������Ϊ��\n");
	Print_CS(T);
	printf("\n");
}

/*����������������������������������������������
����7.33����С�������Ŀ�³˹�����㷨���ڽӱ���
����������������������������������������������*/
CSTree MinSpanTree_KRUSKAL_7_33(ALGraph G)			//����ͼ��Ȩֵ������0 
{
	MFSet S[G.vexnum+1];							//���鼯 
	EdgeSetType EdgeSet[G.arcnum+1];				//ԭʼ�߼� 
	Edge E[G.vexnum];								//ɸѡ�����С�߼�								
	int u, v;
	int k;
	
	InitEdgeSet_7_33(EdgeSet, G);
	InitMFSet_7_33(S, G);
	
	k = 1;
	E[0].u = E[0].v = G.vexnum-1;
	
	while(k<=G.vexnum-1)
	{
		if(GetMinEdge_7_33(EdgeSet, &u, &v))				//�ҵ���С�� 
		{
			if(FindSeat_7_33(S, u)!=FindSeat_7_33(S, v))	//�ж��Ƿ񹹳ɻ�· 
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

void Merge_7_33(MFSet S[], int u, int v) //����u�ϲ�������v 
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
	char Stack[E[0].u+1];					//ģ��ջ 
	int i, j, k;
	char tmp;
	
	InitTree_CS(&T);						//��ʼ������-�ֵ��� 
	k = -1;
	
	if(E[0].u)								//�߼���Ϊ��
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
						
					E[i].u = E[i].v = '\0';		//�൱��ɾ�������ѷ��ʹ��ı� 
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
