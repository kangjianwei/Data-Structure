#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/09 TopologicalSort/TopologicalSort.c" //**��07 ͼ**//

/* ����ԭ�� */
Status Algo_7_35(ALGraph G, char *root);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;										//��Ϊ����Դ	
	char root;
		
	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_35.txt", "r");	
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	if(Algo_7_35(G, &root)) 
		printf("�������޻�ͼ�ĸ�Ϊ��%c\n", root);
	else
		printf("�Ҳ���������ͼ�ĸ���\n");
	printf("\n");
	
	return 0;
}

/*����������������������������������������
����7.35����DAGͼ�ĸ���������������㣩 ��
����������������������������������������*/
Status Algo_7_35(ALGraph G, char *root)
{	
	int indegree[MAX_VERTEX_NUM+1];	
	int k, count;

	FindInDegree(G, indegree);						//�Ը�����������Ѷ��� 
	
	for(k=1,count=0; k<=G.vexnum; k++)
	{
		if(!indegree[k])
		{
			count++;
			*root = G.vertices[k].data;		
		}
	}
	
	if(count==1)									//�����޻�����ͨͼ�ĸ���������Ψһ
		return OK;
	else
		return ERROR;
}
