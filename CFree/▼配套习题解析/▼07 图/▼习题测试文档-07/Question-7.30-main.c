#include <stdio.h>
#include "../../../���α��㷨ʵ��/��07 ͼ/01 MGraph/MGraph.c"		//**��07 ͼ**//

/* ȫ�ֱ��� */
enum
{
	WHITE,
	GRAY,
	BLACK
}color[MAX_VERTEX_NUM+1];						//�ò�ͬ��ɫ�����ʱ�� 
int p[MAX_VERTEX_NUM];							//�ݴ�·�� 
int k;
int path[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];	//�洢�ҵĵ�·�� 

/* ����ԭ�� */
void Algo_7_30(MGraph G);
void DFS_7_30(MGraph G, int i);					//ͨ��������ȱ����ҳ����л�·

int main(int argc, char *argv[])
{
	MGraph G;
	FILE *fp;									//��Ϊ����Դ
	int  m, n;
	
	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_30.txt", "r");
	G.kind = DG;
	CreateDG_M(fp, &G);
	fclose(fp);
	OutputMGraph(G);
	printf("\n");

	Algo_7_30(G);
	printf("������ͼ�й����� %d ����·...\n", path[0][0]);
	for(m=1; m<=path[0][0]; m++)
	{
		printf("  %2d  ", path[m][0]);
		printf("    ");
		for(n=1; n<=path[m][0]; n++)
			printf("%c ", G.vexs[path[m][n]]);
		printf("%c", G.vexs[path[m][1]]);
		printf("\n");
	}
	printf("\n");
	
	return 0;
}

/*����������������������������������
����7.30���ҳ�����ͼ�����м򵥻�·��
����������������������������������*/
void Algo_7_30(MGraph G)	
{
	int i, j;
	
	for(i=0; i<=MAX_VERTEX_NUM; i++)
	{
		for(j=0; j<=MAX_VERTEX_NUM; j++)
			path[i][j] = 0;
	}
	
	for(i=1; i<=G.vexnum; i++)
		color[i] = WHITE;	
	
	for(i=1; i<=G.vexnum; i++)
	{
		k = 1;
		p[k] = i;
		DFS_7_30(G, i);
	}
}

void DFS_7_30(MGraph G, int i)
{
	int u, j;
	
	color[i] = GRAY;
	
	for(u=FirstAdjVex_M(G, G.vexs[i]); u; u=NextAdjVex_M(G, G.vexs[i], G.vexs[u]))
	{
		if(u>p[1] && color[u]==WHITE)
		{
			p[++k] = u;
			DFS_7_30(G, u);
		}
		
		if(u==p[1])
		{
			path[0][0]++;
			path[path[0][0]][0] = k;			//·������ 
			for(j=1; j<=k; j++)					//����õ�·������·������ 
				path[path[0][0]][j] = p[j];		//��·���յ㼴��㣬���������� 			
		}
	}
	
	color[p[k]] = WHITE;						//�˻ص���һ������ 
	k--;
}
