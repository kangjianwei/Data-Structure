/***********************************
 *					               *
 * �ļ���: ��07 ͼ\10 CriticalPath *
 * 					               *
 * �ļ���: CriticalPath.c          *
 *    	    		               *
 * ��  ����7.13��7.14              *
 *    	    		               *
 ***********************************/

#ifndef CRITICALPATH_C
#define CRITICALPATH_C

#include "CriticalPath.h" 								//**��07 ͼ**//

/*�T�T�T�T�[
�U�㷨7.13�U 
�^�T�T�T�T*/
Status TopologicalOrder(ALGraph G, SqStack *T)
{
	SqStack S;
	ArcNode *p;
	int i, j, k;
	int count, indegree[MAX_VERTEX_NUM+1];
		
	FindInDegree(G, indegree);							//�Ը����������
	InitStack_Sq(&S);									//��ʼ������ȶ���ջ 
	InitStack_Sq(T); 									//��ʼ���������ж���ջ 
	
	for(i=1; i<=G.vexnum; i++)							//�������Ϊ0�Ķ���ջ����ʼ������ve 
	{
		if(!indegree[i])
			Push_Sq(&S, i);								//���Ϊ0�߽�ջ
		
		ve[i] = 0;
	}
	
	count = 0;											//������������
	
	while(!StackEmpty_Sq(S))
	{		
		Pop_Sq(&S, &j);	
		Push_Sq(T, j);									//j��0��ȶ�������������ջ������ 
		count++;

		for(p=G.vertices[j].firstarc; p; p=p->nextarc)
		{
			k = p->adjvex;								//��j�Ŷ����ÿ���ڽӵ����ȼ�һ
			if(!(--indegree[k]))
				Push_Sq(&S, k); 						//����ȼ�Ϊ0�����������ȶ���ջ
			if(ve[j] + 	p->info.in > ve[k])
				ve[k] = ve[j] + p->info.in;
		}
	} 
	
	if(count<G.vexnum)
	{
		printf("������ͼ�л�·����\n");
		return ERROR;	
	}
	else
		return OK;
}

/*�T�T�T�T�[
�U�㷨7.14�U 
�^�T�T�T�T*/
Status CriticalPath(ALGraph G)
{
	int i, j, k;
	ArcNode *p;
	int dut;											//�����ʱ��
	int ee, el;
	int count;
	char tag;
	
	if(!TopologicalOrder(G, &T))
		return ERROR;
	
	for(i=1; i<=G.vexnum; i++)
		vl[i] = ve[G.vexnum];							//��ʼ���¼������㣩����ٷ����¼� 
	
	while(!StackEmpty_Sq(T))							//������������ø������vlֵ 
	{
		for(Pop_Sq(&T,&j),p=G.vertices[j].firstarc; p; p=p->nextarc)
		{
			k = p->adjvex;
			dut = p->info.in;							//dut<j,k>
			
			if(vl[k] - dut < vl[j])
				vl[j] = vl[k] - dut;			
		}
	} 
	
	for(j=1,count=1; j<=G.vexnum; j++)							//��ee��el�͹ؼ�� 
	{
		for(p=G.vertices[j].firstarc; p; p=p->nextarc)
		{
			k = p->adjvex;
			dut  = p->info.in;
			ee = ve[j];
			el = vl[k] - dut;
			tag = (ee==el) ? '*' : ' ';							//��*��ǹؼ�� 
			
			printf("%c-%c  a%-2d=%2d  (%2d, %2d)  %c\n", G.vertices[j].data, G.vertices[k].data, count++, dut, ee, el, tag);
		}
	}
	
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
