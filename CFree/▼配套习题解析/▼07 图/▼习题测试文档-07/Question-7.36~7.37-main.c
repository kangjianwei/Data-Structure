#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/09 TopologicalSort/TopologicalSort.c" //**��07 ͼ**//

/* ����ԭ�� */
Status Algo_7_36(ALGraph G, int MPL[][MAX_VERTEX_NUM+1]);
Status Algo_7_37(ALGraph G, int MPL[][MAX_VERTEX_NUM+1], int Path[]);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;										//��Ϊ����Դ	
	int MPL[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];	//��¼������������·�� 		
	int i, j;
	int Path[MAX_VERTEX_NUM+1];
	
	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_36-7_37.txt", "r");	
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");	

	printf("������ �� 7.36 ��֤... ������\n");	
	if(Algo_7_36(G, MPL))
	{
		printf("�Ӹ�����������·���ֱ�Ϊ��\n");
		for(i=1; i<=G.vexnum; i++)
		{
			for(j=1; j<=MPL[i][0]; j++)
				printf("%c ", G.vertices[MPL[i][j]].data);
			printf("\n");
		}	
	}
	printf("\n");

	printf("������ �� 7.37 ��֤.. ������\n");	
	if(Algo_7_37(G, MPL, Path))
	{
		printf("��DAGͼ���·��Ϊ��");
		for(i=1; i<=Path[0]; i++)
			printf("%c ", G.vertices[Path[i]].data);
		printf("\n");
	}
	printf("\n");
		
	return 0;
}

/*������������������������������������������
����7.36����DAGͼ��ÿ������������·�� ��
������������������������������������������*/
Status Algo_7_36(ALGraph G, int MPL[][MAX_VERTEX_NUM+1])
{	
	int Topo[MAX_VERTEX_NUM+1];									//�洢��������
	int i, j, k, max, tmp;
	ArcNode *r;
	
	if(TopologicalSort(G, Topo))
	{
		for(i=0; i<=MAX_VERTEX_NUM; i++)						//��ʼ���·������ 
		{
			for(j=0; j<=MAX_VERTEX_NUM; j++)
				MPL[i][j] = 0;
		}
		
		MPL[0][0] = G.vexnum;									//��·���� 
		
		for(k=G.vexnum; k>=1; k--)								//������������������·�� 
		{
			r = G.vertices[Topo[k]].firstarc;
			
			MPL[Topo[k]][1] = Topo[k];
			
			if(!r)
				MPL[Topo[k]][0]	= 1;
			else
			{
				max = tmp = 0;
				while(r)
				{
					if(MPL[r->adjvex][0]>max)					//��ĳ�����ж����·������ֻȡ����������һ�� 
					{
						max = MPL[r->adjvex][0];
						tmp = r->adjvex;
					}
					
					r = r->nextarc;
				}
				
				MPL[Topo[k]][0] = max+1;							//��ǰ����������·���ж������ 
				
				for(i=1; i<=max; i++)
					MPL[Topo[k]][i+1] = MPL[tmp][i];
			}
		}
		
		return OK;
	}
	
	return ERROR;
}

/*��������������������������
����7.37����DAGͼ�·�� ��
��������������������������*/
Status Algo_7_37(ALGraph G, int MPL[][MAX_VERTEX_NUM+1], int Path[])
{
	int k, tmp;
	
	if(Algo_7_36(G, MPL))
	{
		for(k=1,Path[0]=tmp=0; k<=G.vexnum; k++)
		{
			if(MPL[k][0]>Path[0])					//��DAGͼ�ж����·������ֻȡ����������һ��
			{
				Path[0] = MPL[k][0];
				tmp = k;
			}
		}
		
		for(k=1; k<=Path[0]; k++)
			Path[k] = MPL[tmp][k];
		
		return OK;
	}
	
	return ERROR;
}
