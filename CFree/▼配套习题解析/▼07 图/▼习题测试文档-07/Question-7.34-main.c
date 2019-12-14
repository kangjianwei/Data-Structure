#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/09 TopologicalSort/TopologicalSort.c"	//**��07 ͼ**//

/* ����ԭ�� */
Status Algo_7_34(ALGraph G, int Topo[]);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;													//��Ϊ����Դ	
	int Topo[MAX_VERTEX_NUM+1];									//�洢��������
	int k;
		
	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_34.txt", "r");	
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	if(Algo_7_34(G, Topo))
	{
		printf("�������޻�ͼ����������Ϊ��\n");
		for(k=1; k<=G.vexnum; k++)
			printf("%d-%c ", k, G.vertices[Topo[k]].data); 
	}
	printf("\n\n");
	
	return 0;
}

/*������������������
����7.34����������
������������������*/
Status Algo_7_34(ALGraph G, int Topo[])
{	
	return TopologicalSort(G, Topo);							//�Ѷ��� 
}
