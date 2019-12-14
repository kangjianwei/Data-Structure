/**************************************
 *					                  *
 * �ļ���: ��07 ͼ\09 TopologicalSort *
 * 					                  *
 * �ļ���: TopologicalSort-main.c     *
 * 							          *
 * ��  ��: ����ͼ����������غ������� *
 *                                    *
 **************************************/

#include <stdio.h> 
#include "TopologicalSort.c" 	//**��07 ͼ**//

int main(int argc, char *argv[])
{
	ALGraph G;
	
	printf("�������������ͼ...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_DG_AL.txt", "r");	
		CreateGraph_AL(fp, &G); 
		fclose(fp);
		OutputALGraph(G);
		printf("\n");
	}
	PressEnter;	

	printf("��1��2\n������ TopologicalSort�� ����...\n");		//1��2.����TopologicalSort�Ȳ���	
	{
		int k;
		int Topo[MAX_VERTEX_NUM+1];								//�洢�������� 
	
		printf("������ͼ������������...\n");
		if(!TopologicalSort(G, Topo))
			printf("������ͼ�л�·����\n");	
		else
		{
			printf("������ͼ����������Ϊ��");
			for(k=1; k<=G.vexnum; k++)
				printf("%c ", G.vertices[Topo[k]].data);
		}
		printf("\n\n");
	}
	PressEnter;
		
	return 0;
}
