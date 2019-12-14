#ifndef Question_7
#define Question_7

#include <stdio.h>
#include <limits.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"			//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/02 ALGraph/ALGraph.c"	//**��07 ͼ**//

/* ����ԭ�� */
void Dijkstra_7_42(ALGraph G, int v0, int path[], int dist[]);
int GetInfo_7_42(ALGraph G, int i, int j);			//��ȡ��<i,j>����Ϣ��Ȩֵ�� 

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;										//��Ϊ����Դ	
	int path[MAX_VERTEX_NUM+1];
	int dist[MAX_VERTEX_NUM+1];
	int v0 = 1;
		
	printf("�������������ͼ����Ȩ��...\n");
	fp = fopen("Data/Algo_7_42.txt", "r");	
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");

	printf("���㲢��� %c �������������·����\n", G.vertices[v0].data);
	Dijkstra_7_42(G, v0, path, dist);
	printf("\n");
}

void Dijkstra_7_42(ALGraph G, int v0, int path[], int dist[])
{
	int set[MAX_VERTEX_NUM+1];
	int min, i, j, v;
	int tmp[MAX_VERTEX_NUM+1], k;
	
	for(i=1; i<=G.vexnum; i++)					//�����ʼ��
	{
		dist[i] = GetInfo_7_42(G, v0, i);		//dist[i]��v0��i�����·������ 
		set[i] = 0;								//set[i]��������飬��Ǹ������Ƿ��Ѽ���·�� 
		if(GetInfo_7_42(G, v0, i) < INT_MAX)
			path[i] = v0;						//path[i]�������v0��vi·����vi��ǰһ������ 
		else
			path[i] = -1;						//����v0��vi�м䲻�����κζ��㣨���ܲ�ͨ��Ҳ���������� 
	}
	
	set[v0] = 1;
	path[v0] = -1;
	
	for(i=1; i<=G.vexnum; i++)					//��ʼ���������ؼ�������ʼ���ж�����G.vexnum-1�����㣩 
	{
		min = INT_MAX;
		
		for(j=1; j<=G.vexnum; j++)				//ѡ��v0��ʣ�ඥ������̵�һ��·��
		{
			if(!set[j] && dist[j]<min)
			{
				v = j;
				min = dist[j];					//v0��ʣ�ඥ������·��<v0, v> 
			}
		}
			
		set[v] = 1;								//������v�������·��
		
		for(j=1; j<=G.vexnum; j++)				//�ж�v�ļ����Ƿ�����v0��ʣ�ඥ��ĸ���·�� 
		{
			if(!set[j] && min<INT_MAX &&  GetInfo_7_42(G, v, j)<INT_MAX && (min + GetInfo_7_42(G, v, j)) < dist[j])
			{
				dist[j] = min + GetInfo_7_42(G, v, j);
				path[j] = v;
			}
		}
	}
	
	//���·�� 
	for(i=1; i<=G.vexnum; i++)
	{
		if(v0!=i)
		{
			printf("%c �� %c ��·��Ϊ��", G.vertices[v0].data, G.vertices[i].data);
			
			if(path[i]==-1)
				printf("��");
			else
			{
				tmp[0] = 0;								//����·���ϵĶ������ 
	
				if(v0!=i)
				{
					k = i;
					do
					{
						tmp[0]++;
						tmp[tmp[0]] = k;
						k = path[k];			
					}while(path[k]!=-1);			
				}
				
				printf("%c ", G.vertices[v0].data);
				
				if(tmp[0])
				{
					for(j=tmp[0]; j>=1; j--)
						printf("%c ", G.vertices[tmp[j]].data);
				}
			}
				
			printf("��Ȩ��Ϊ��");
			if(dist[i]==INT_MAX)
				printf("��\n");
			else
				printf("%2d\n", dist[i]);
		}
	}	
} 

int GetInfo_7_42(ALGraph G, int i, int j)
{
	ArcNode *r;
	
	r = G.vertices[i].firstarc;
	
	while(r && r->adjvex!=j)
		r = r->nextarc;
	
	if(r && r->adjvex==j)
		return r->info.in;
	
	return INT_MAX;							//����ߵ�Ȩֵ������0	
}

#endif
