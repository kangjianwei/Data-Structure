#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/01 SequenceStack/SequenceStack.c"	//**��03 ջ�Ͷ���**//
#include "../../../���α��㷨ʵ��/��07 ͼ/02 ALGraph/ALGraph.c"		//**��07 ͼ**//

/* �궨�� */
#define MAX 100									//�ҳ������·���� 

/* ȫ�ֱ��� */
Status mark;
SqStack S;										//�ݴ�·��
int path[MAX+1][MAX_VERTEX_NUM+1];				//�洢�ҵĵ�·�� 

/* ����ԭ�� */
Status Algo_7_27(ALGraph G, int i, int j, int k);
Status Algo_7_28(ALGraph G, int i, int j);
void DFS_7_27(ALGraph G, int i, int j, int k);	//ͨ�����޵�������ȱ����ж�·���Ƿ����
void DFS_7_28(ALGraph G, int i, int j);			//ͨ��������ȱ����ҳ�����·��

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//��Ϊ����Դ
	char v1, v2;
	int i, j, k, m, n;
	int *p;
	
	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_27-7_28.txt", "r");
	CreateGraph_AL(fp, &G);
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	v1 = 'a';
	v2 = 'c';
	i = LocateVex_AL(G, v1);
	j = LocateVex_AL(G, v2);
	k = 4;
	
	printf("������ �� 7.27 ��֤... ������\n");
	Algo_7_27(G, i, j, k);
	printf("%c �� %c ֮��", v1, v2);
	mark ? printf("����") : printf("������");
	printf("����Ϊ %d ��·����\n", k);
	printf("\n");

	printf("������ �� 7.28 ��֤... ������\n");
	Algo_7_28(G, i, j);
	if(!path[0][0])
		printf("%c �� %c ֮�䲻����·����", G.vertices[i].data, G.vertices[j].data);
	else
	{
		printf("%c �� %c ֮����� %d ��·����\n", G.vertices[i].data, G.vertices[j].data, path[0][0]);
		printf("·����    ·��\n");
		for(m=1; m<=path[0][0]; m++)
		{
			printf("  %2d  ", path[m][0]-1);
			printf("    ");
			for(n=1; n<=path[m][0]; n++)
				printf("%c ", G.vertices[path[m][n]].data);
			printf("\n");
		}
	}
	printf("\n");
	
	return 0;
}

/*������������������������������������������������
����7.27���ж�i��j֮���Ƿ���ڳ���Ϊk�ļ�·�� ��
������������������������������������������������*/
Status Algo_7_27(ALGraph G, int i, int j, int k)	
{
	int v;
		 
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;						//�����ʱ�ǳ�ʼ��Ϊδ����		
	
	mark = FALSE;
	
	DFS_7_27(G, i, j, k); 						//ͨ�����޵�������ȱ����ж�·���Ƿ���� 
	
	return mark ?  TRUE : FALSE;
}

/*����������������������������������
����7.28���ҳ�i��j֮�����м�·����
����������������������������������*/
Status Algo_7_28(ALGraph G, int i, int j)	
{
	int m, n;
		 
	for(m=1; m<=G.vexnum; m++)
		visited[m] = FALSE;						//�����ʱ�ǳ�ʼ��Ϊδ����

	InitStack_Sq(&S);							//��ʼ��·��ջ���ݴ�·���� 
		
	for(m=0; m<=MAX; m++)						//��ʼ��·������ 
	{
		for(n=0; n<=MAX_VERTEX_NUM; n++)
			path[m][n] = 0;
	}
	
	DFS_7_28(G, i, j); 							//ͨ��������ȱ����ҳ�����·�� 
	
	if(!path[0][0])
		return FALSE;
	else	
		return TRUE;
}

void DFS_7_27(ALGraph G, int i, int j, int k)
{
	int w, e;
	int count;
	int *p;
	
	visited[i] = TRUE;
	Push_Sq(&S, i);
	
	if(i==j)
	{
		for(p=S.base,count=-1; p<S.top; p++,count++)
			;
		
		if(count==k)
			mark = TRUE;
		else
		{
			Pop_Sq(&S, &e);
			visited[i] = FALSE;		
		}
				
		return;
	}
	
	for(w=FirstAdjVex_AL(G, G.vertices[i].data); w && !mark; w=NextAdjVex_AL(G, G.vertices[i].data, G.vertices[w].data))
	{
		if(!visited[w])
			DFS_7_27(G, w, j, k);
	}
	
	if(!w && !mark){
		visited[i] = FALSE;
		Pop_Sq(&S, &e);
	}
}

void DFS_7_28(ALGraph G, int i, int j)
{
	int w, e;
	int *p;
	
	visited[i] = TRUE;
	Push_Sq(&S, i);
	
	if(i==j)
	{
		path[0][0]++;
		
		for(p=S.base; p<S.top; p++)
			path[path[0][0]][++path[path[0][0]][0]] = *p; 
		
		Pop_Sq(&S, &e);
		visited[i] = FALSE;
		
		return;
	}
	
	for(w=FirstAdjVex_AL(G, G.vertices[i].data); w; w=NextAdjVex_AL(G, G.vertices[i].data, G.vertices[w].data))
	{
		if(!visited[w])
			DFS_7_28(G, w, j);
	}
	
	if(!w)
	{
		Pop_Sq(&S, &e);
		visited[i] = FALSE;
	}
}
