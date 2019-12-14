/***********************************
 *						           *
 * �ļ���: ��07 ͼ\05 SpanningTree *
 * 						           *
 * �ļ���: SpanningTree.c          *
 *    	    			           *
 * ��  ��: 7.7��7.8                * 
 *    	    			           *
 ***********************************/

#ifndef SPANNINGTREE_C
#define SPANNINGTREE_C

#include "SpanningTree.h"

/*�T�T�T�T�[
�U �㷨7.7�U 
�^�T�T�T�T*/
void DFSForest(MGraph G, CSTree *T)
{
	int v;
	CSTree p, q;
	
	InitTree_CS(T);
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;
	
	for(v=1; v<=G.vexnum; v++)
	{
		if(!visited[v])							//��v����Ϊ�µ��������ĸ���� 
		{
			p = (CSTree)malloc(sizeof(CSNode));	//��������
			if(!p)
				exit(OVERFLOW);
			p->data = GetVex_M(G, v);
			p->firstchild = p->nextsibling = NULL;
			
			if(!(*T))							//�ǵ�һ���������ĸ� 
				*T = p;
			else								//�������������ĸ���ǰһ���������ֵܣ� 
				q->nextsibling = p;
			
			q = p;								//qָʾ��ǰ�������ĸ� 
			DFSTree(G, v, &p);					//������pΪ���������� 
		}
	}
}

/*�T�T�T�T�[
�U �㷨7.8�U 
�^�T�T�T�T*/
void DFSTree(MGraph G, int v, CSTree *T)
{
	Status first;
	int w;
	CSTree p, q;
		
	visited[v] = TRUE;
	first = TRUE;
	
	for(w=FirstAdjVex_M(G, G.vexs[v]); w; w=NextAdjVex_M(G, G.vexs[v], G.vexs[w]))
	{
		if(!visited[w])
		{
			p = (CSTree)malloc(sizeof(CSNode));		//���亢�ӽ�� 
			if(!p)
				exit(OVERFLOW);
			p->data = GetVex_M(G, w);
			p->firstchild = p->nextsibling = NULL;
			
			if(first)
			{
				(*T)->firstchild = p;
				first = FALSE;
			}
			else
				q->nextsibling = p;	
		
			q = p;
			DFSTree(G, w, &q);
		}
	}
}

#endif
