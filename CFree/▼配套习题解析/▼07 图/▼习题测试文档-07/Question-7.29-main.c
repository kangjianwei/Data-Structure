#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/01 SequenceStack/SequenceStack.c"	//**��03 ջ�Ͷ���**//
#include "../../../���α��㷨ʵ��/��07 ͼ/01 MGraph/MGraph.c"		//**��07 ͼ**//

/* ȫ�ֱ��� */
int sum;
SqStack S;										//�ݴ�·��

/* ����ԭ�� */
int Algo_7_29(MGraph G, int i, int j, int k);
void DFS_7_29(MGraph G, int i, int j, int k);	//ͨ�����޵�������ȱ���ͳ�ƺϷ�·��

int main(int argc, char *argv[])
{
	MGraph G;
	FILE *fp;									//��Ϊ����Դ
	char v1, v2;
	int i, j, k;
	
	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_29.txt", "r");
	G.kind = DG;
	CreateDG_M(fp, &G);
	fclose(fp);
	OutputMGraph(G);
	printf("\n");
	
	v1 = 'u';
	v2 = 'v';
	i = LocateVex_M(G, v1);
	j = LocateVex_M(G, v2);
	k = 3;
	
	Algo_7_29(G, i, j, k);
	printf("%c �� %c ֮��", v1, v2);
	sum ? printf("���� %d ��", sum) : printf("������");
	printf("����Ϊ %d ��·����\n", k);
	printf("\n");
	
	return 0;
}

/*����������������������������������������������
����7.29������i��j֮��·������Ϊk�ļ�·���� ��
����������������������������������������������*/
int Algo_7_29(MGraph G, int i, int j, int k)	
{
	int v;
		 
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;						//�����ʱ�ǳ�ʼ��Ϊδ����
		
	sum = 0;									//ͳ�Ʒ���������·���� 
	
	DFS_7_29(G, i, j, k); 						//ͨ�����޵�������ȱ���ͳ�ƺϷ�·�� 
	
	return sum;
}

void DFS_7_29(MGraph G, int i, int j, int k)
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
			sum++;

		Pop_Sq(&S, &e);
		visited[i] = FALSE;		
				
		return;
	}
	
	for(w=FirstAdjVex_M(G, G.vexs[i]); w; w=NextAdjVex_M(G, G.vexs[i], G.vexs[w]))
	{
		if(!visited[w])
			DFS_7_29(G, w, j, k);
	}
	
	if(!w)
	{
		Pop_Sq(&S, &e);
		visited[i] = FALSE;
	}
}
