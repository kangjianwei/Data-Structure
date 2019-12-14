/**************************************
 *					                  *
 * �ļ���: ��07 ͼ\09 TopologicalSort *
 * 					                  *
 * �ļ���: TopologicalSort.c          *
 *    	    		                  *
 * ��  ����7.12   	                  *
 *    	    		                  *
 **************************************/

#ifndef TOPOLOGICALSORT_C
#define TOPOLOGICALSORT_C

#include "TopologicalSort.h" 							//**��07 ͼ**//

/*�T�T�T�T�[
�U�㷨7.12�U 
�^�T�T�T�T*/
Status TopologicalSort(ALGraph G, int Topo[])			//����Topo�洢��������
{
	SqStack S;
	ArcNode *p;
	int i, k, count, indegree[MAX_VERTEX_NUM+1];				 
		
	FindInDegree(G, indegree);							//�Ը����������
	InitStack_Sq(&S);									//��ʼ��ջ 
	
	for(i=1; i<=G.vexnum; i++)							//�������Ϊ0�Ķ���ջ 
	{
		if(!indegree[i])
			Push_Sq(&S, i);								//���Ϊ0�߽�ջ 
	}
	
	count = 0;											//������������
	
	while(!StackEmpty_Sq(S))
	{		
		Pop_Sq(&S, &i);		 
		count++;										//��̲�д�����г��� 
		Topo[count] = i;								//��ֱ������������ݴ��������� 

		for(p=G.vertices[i].firstarc; p; p=p->nextarc)
		{
			k = p->adjvex;								//��i�Ŷ����ÿ���ڽӵ����ȼ�һ
			if(!(--indegree[k]))
				Push_Sq(&S, k); 
		}
	} 
	
	if(count<G.vexnum)
		return ERROR;	
	else
		return OK;
}

void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM+1])
{
	int i;
	ArcNode *p;
	
	for(i=1; i<=G.vexnum; i++)
		indegree[i] = 0;								//��ʼ���������
		
	for(i=1; i<=G.vexnum; i++)
	{		
		p = G.vertices[i].firstarc;
		while(p)
		{
			indegree[p->adjvex]++;
			p = p->nextarc; 
		}
	}	 
}

#endif
