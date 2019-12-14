#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"			//**��01 ����**//
#include "../../../���α��㷨ʵ��/��01 ����/Scanf.c"			//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/01 SequenceStack/SequenceStack.c"	//**��03 ջ�Ͷ���**//

/* �궨�� */
#define MAX_VERTEX_NUM 20				//��󶥵���� 
#define MAX 1000						//������� 

/* ȫ�ֱ��� */
Status visited[MAX_VERTEX_NUM+1];		//���ʱ�� 
Status mark;							//��·��� 
SqStack path;							//·�� 

/* ͼ�Ĵ洢�ṹ���Ͷ��� */
typedef struct
{
	char vexs[MAX_VERTEX_NUM+1];				//��������
	int s[MAX];									//�洢ÿ������ĺ�̶��� 
	int fst[MAX_VERTEX_NUM+1], lst[MAX_VERTEX_NUM+1];	//ĳ�������̶�����s�е���ֹ��Χ 
	int vexnum,	arcnum;							//����ͼ�ĵ�ǰ�������ͻ���	
}Graph;

/* ����ԭ�� */
Status Algo_7_25(Graph G);
Status CreateGraph_7_25(FILE *fp, Graph *G);		//��������ͼ
void OutputGraph_7_25(Graph G);						//�������ͼ
int LocateVex_7_25(Graph G, char u);				//����Ԫ��u��ͼ�е�λ�� 
int FirstAdjVex_7_25(Graph G, int v);				//����v�ĵ�һ���ڽӶ��� 
int NextAdjVex_7_25(Graph G, int v, int w);			//������v����w����һ���ڽӶ��� 
void DFS_7_25(Graph G, int v);						//������ȱ�������ͼ 
Status IsExistPath_7_25(int e);						//�ж�Ԫ��e�Ƿ������ջ��

int main(int argc, char *argv[])
{
	Graph G;
	FILE *fp;									//��Ϊ����Դ

	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_25.txt", "r");
	CreateGraph_7_25(fp, &G);
	fclose(fp);
	OutputGraph_7_25(G);
	printf("\n");
	
	InitStack_Sq(&path);
	Algo_7_25(G) ? printf("ͼ���л�·��") : printf("ͼ���޻�·����");
	printf("\n\n");
		
	return 0;
}

/*����������������������������������
����7.25���ж�����ͼ���Ƿ���ڻ�·��
����������������������������������*/
Status Algo_7_25(Graph G)	
{
	int v;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;

	for(v=1; v<=G.vexnum && !mark; v++)
	{
		if(!visited[v])
			DFS_7_25(G, v);						//����������������ж�����ͼ�Ƿ��л�· 
	}
	
	return mark;								//ȫ�ֱ���������Ƿ��ҵ���· 
}

Status CreateGraph_7_25(FILE *fp, Graph *G)		//��������ͼ 
{
	int i, j, k, total;
	int count[MAX_VERTEX_NUM+1];
	char tmp, v1, v2;
	
	Scanf(fp, "%d%d", &((*G).vexnum), &((*G).arcnum));
	Scanf(fp, "%c", &tmp);						//�������з�
	
	for(k=1; k<=(*G).vexnum; k++)
	{
		Scanf(fp, "%c", &((*G).vexs[k]));	
		count[k] = 0;
	}
	Scanf(fp, "%c", &tmp);						//�������з�
	
	for(k=1; k<=(*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &v1, &v2);
		
		i = LocateVex_7_25(*G, v1);
		j = LocateVex_7_25(*G, v2);
		
		(*G).s[k] = j;
		count[i]++;
	}
	
	for(k=1,total=0; k<=(*G).arcnum; k++)
	{
		(*G).fst[k] = total + 1;

		total += count[k];
		
		if(count[k])
			(*G).lst[k] = total;
		else
			(*G).lst[k] = 0;
	}
}

void OutputGraph_7_25(Graph G)					//�������ͼ 
{
	int i, j;
	
	if(!G.vexnum && !G.arcnum)
		printf("����ͼΪ�գ�\n");
	else
	{
		for(i=1; i<=G.vexnum; i++)
		{
			printf("%c��", G.vexs[i]);
			
			for(j=G.fst[i]; j<=G.lst[i]; j++)
				printf(" %c", G.vexs[G.s[j]]);
			
			printf("\n");	
		}
	}
}

int LocateVex_7_25(Graph G, char u)				//����Ԫ��u��ͼ�е�λ�� 
{
	int i;
	
	for(i=1; i<=G.vexnum; i++)
	{
		if(G.vexs[i]==u)
			return i;
	}
	
	return 0;
}

int FirstAdjVex_7_25(Graph G, int v)			//����v�ĵ�һ���ڽӶ��� 
{	
	if(G.fst[v]<=G.lst[v])
		return G.s[G.fst[v]];
	
	return 0;
} 

int NextAdjVex_7_25(Graph G, int v, int w)	//������v����w����һ���ڽӶ��� 
{
	int i;
	
	if(G.fst[v]<=G.lst[v])
	{
		for(i=G.fst[v]; i<=G.lst[v] && i!=w; i++)
			;
		
		if(i<G.lst[v])
			return G.s[i+1];
	}
	 
	return 0; 
}

void DFS_7_25(Graph G, int v)				//������ȱ�������ͼ 
{
	int w, e;

	visited[v] = TRUE;
	Push_Sq(&path, v);
	
	for(w=FirstAdjVex_7_25(G, v); w && !mark; w=NextAdjVex_7_25(G, v, w))
	{
		if(!visited[w])
			DFS_7_25(G, w);
		else
		{
			if(IsExistPath_7_25(w))
				mark = TRUE;
		}
	}
	
	if(!w && !mark)
		Pop_Sq(&path, &e);	
}

Status IsExistPath_7_25(int e)				//�ж�Ԫ��e�Ƿ������ջ��
{
	int *p;
	
	for(p=path.base; p<path.top; p++)
	{
		if(*p==e)
			return TRUE;
	}
	
	return ERROR;
}
