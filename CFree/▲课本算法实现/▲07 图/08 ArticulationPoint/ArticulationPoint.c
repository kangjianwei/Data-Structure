/****************************************
 *    	    		                    *
 * �ļ���: ��07 ͼ\08 ArticulationPoint *
 * 					                    *
 * �ļ���: ArticulationPoint.c          *
 *    	    		                    *
 * ��  ����7.10��7.11   	            *
 *    	    		                    *
 ****************************************/

#ifndef ARTICULATIONPOINT_C
#define ARTICULATIONPOINT_C

#include "ArticulationPoint.h" 							//**��07 ͼ**//

/*�T�T�T�T�[
�U�㷨7.10�U 
�^�T�T�T�T*/
void FindArticul(ALGraph G)
{
	int i, v;
	ArcNode *p;
		
	count = 1;
	visited[1] = 1;										//�趨�ڽӱ���1�Ŷ���Ϊ�������ĸ���0�ŵ�Ԫ���ã�
	
	for(i=2; i<=G.vexnum; i++) 
		visited[i] = 0;									//���ඥ����δ����
	
	p = G.vertices[1].firstarc;
	v = p->adjvex;
	
	DFSArticul(G, v); 									//�ȱ������������ߵ����� 
	
	if(count<G.vexnum)									//�������ĸ���������������
	{
		StorageAPoint(1);
		
		while(p->nextarc)								//���α����������� 
		{
			p = p->nextarc;
			v = p->adjvex;
			
			if(visited[v]==0)
				DFSArticul(G, v);
		}
	}
} 

/*�T�T�T�T�[
�U�㷨7.11�U 
�^�T�T�T�T*/
void DFSArticul(ALGraph G, int v0)
{
	int min, w;											//min�ݴ�low[]��ֵ 
	ArcNode *p;	
	
	visited[v0] = min = ++count;						//v0�ǵ�count�����ʵĶ��� 

	for(p=G.vertices[v0].firstarc; p; p=p->nextarc)
	{
		w = p->adjvex;									//wΪv0���ڽӶ��� 

		if(visited[w]==0)								//wδ�����ʣ���v0�ĺ��� 
		{
			DFSArticul(G, w);							//����ǰ���low[w] 
			
			if(low[w]<min)
				min = low[w];
			
			if(low[w]>=visited[v0])						//v0������ֱ��׷�ݵ��������Ȳ���������
				StorageAPoint(v0);
		}
		else											//w�ѷ��ʣ���v0���������ϵ����� 
		{
			if(visited[w]<min)				
				min = visited[w];
		}
		
		low[v0] = min;
	}
} 

Status StorageAPoint(int n)
{
	int i;
	
	for(i=1; i<=node[0]; i++)
	{
		if(node[i]==n)									//�ùؽڵ��Ѵ洢�� 
			return ERROR;
	}
	
	node[0]++;
	node[node[0]] = n;
	
	return OK;
}

void OutputAPoint(ALGraph G)
{
	int i;
	
	for(i=1; i<=node[0]; i++)
		printf("�� %2d ���ҵ��Ĺؽڵ� %c��������Ϊ %2d\n", i, G.vertices[node[i]].data, node[i]);
}

#endif
