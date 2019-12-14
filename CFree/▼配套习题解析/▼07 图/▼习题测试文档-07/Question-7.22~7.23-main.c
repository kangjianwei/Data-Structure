#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/02 ALGraph/ALGraph.c"		//**��07 ͼ**//

/* ȫ�ֱ��� */
Status tag;

/* ����ԭ�� */
Status Algo_7_22(ALGraph G, int i, int j);
Status Algo_7_23(ALGraph G, int i, int j);
void DFS_7_22(ALGraph G, int i, int j);	//ͨ��������ȱ����ж�vi��vj֮���Ƿ���ͨ· 
void BFS_7_23(ALGraph G, int i, int j);	//ͨ��������ȱ����ж�vi��vj֮���Ƿ���ͨ·

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//��Ϊ����Դ

	printf("�������������ͼ...\n");
	G.kind = DG;								//������ͼΪ��
	fp = fopen("Data/Algo_7_22-7_23.txt", "r");
	CreateDG_AL(fp, &G);						 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	printf("������ �� 7.22 ��֤... ������\n");
	Algo_7_22(G, 1, 3); 
	printf("\n");

	printf("������ �� 7.23 ��֤... ������\n");
	Algo_7_22(G, 4, 3); 
	printf("\n");
				
	return 0;
}

/*����������������������������������������������������
����7.22��ͨ��������ȱ����ж϶���vi��vj�Ƿ����·����
����������������������������������������������������*/
Status Algo_7_22(ALGraph G, int i, int j)
{
	int v, w;
	ArcNode *p;
	
	if(i==j)
	{
		printf("��������\n");
		return ERROR;
	}
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;			//��ʼ��Ϊδ����	
	
	tag = FALSE;					//ȫ�ֱ��������vi��vj���Ƿ���ͨ·	
	visited[i] = TRUE;
	
	DFS_7_22(G, i, j);				//������ȱ�������
	
	if(tag)
	{
		printf("%c �� %c ֮����ͨ·��\n", G.vertices[i].data, G.vertices[j].data);
		return TRUE;
	}
	else
	{
		printf("%c �� %c ֮����ͨ·����\n", G.vertices[i].data, G.vertices[j].data);
		return ERROR;
	}
} 

/*����������������������������������������������������
����7.23��ͨ��������ȱ����ж϶���vi��vj�Ƿ����·����
����������������������������������������������������*/
Status Algo_7_23(ALGraph G, int i, int j)
{
	int v, w;
	ArcNode *p;
	
	if(i==j)
	{
		printf("��������\n");
		return ERROR;
	}
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;			//��ʼ��Ϊδ����	
	
	tag = FALSE;					//ȫ�ֱ��������vi��vj���Ƿ���ͨ·	
	visited[i] = TRUE;
	
	BFS_7_23(G, i, j);				//������ȱ������� 
	
	if(tag)
	{
		printf("%c �� %c ֮����ͨ·��\n", G.vertices[i].data, G.vertices[j].data);
		return TRUE;
	}
	else
	{
		printf("%c �� %c ֮����ͨ·����\n", G.vertices[i].data, G.vertices[j].data);
		return ERROR;
	}
}

void DFS_7_22(ALGraph G, int i, int j)	//������ȱ���
{
	int w;
	
	for(w=FirstAdjVex_AL(G, G.vertices[i].data); w; w=NextAdjVex_AL(G, G.vertices[i].data, G.vertices[w].data))
	{
		if(tag)
			return;
			
		if(!visited[w])
		{
			visited[w] = TRUE;
						
			if(w==j)
				tag = TRUE;			
			else
				DFS_7_22(G, w, j);				
		}
	}
}

void BFS_7_23(ALGraph G, int i, int j)	//������ȱ���
{
	int v, w;
	LinkQueue Q;
	QElemType_L e;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;					//��ʼ��Ϊδ����

	visited[i] = TRUE;	

	InitQueue_L(&Q);		
	EnQueue_L(&Q, i);
	while(!QueueEmpty_L(Q))
	{
		DeQueue_L(&Q, &e);
		for(w=FirstAdjVex_AL(G, G.vertices[e].data); w; w=NextAdjVex_AL(G, G.vertices[e].data, G.vertices[w].data))
		{
			if(!visited[w])
			{
				visited[w] = TRUE;
						
				if(w==j)
				{
					tag = TRUE;
					return;				
				}
							
				EnQueue_L(&Q, w);
			}
		}
	}
}
