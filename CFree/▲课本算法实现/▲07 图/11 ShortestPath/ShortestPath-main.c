/***********************************
 *						           *
 * �ļ���: ��07 ͼ\11 ShortestPath *
 * 						           *
 * �ļ���: ShortestPath-main.c     *
 * 							       *
 * ��  ��: ���·����غ�������    *
 *                                 *
 ***********************************/

#include <stdio.h>
#include "ShortestPath.c" 						//**��07 ͼ**//

int main(int argc, char *argv[])
{
	MGraph G1, G2;	
	int v0 = 2;													//������� 
		
	printf("���������������G1...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_DN_M_DIJ.txt", "r");
		CreateGraph_M(fp, &G1); 
		fclose(fp);
		OutputMGraph(G1);
		printf("\n");
	}
	PressEnter;	

	printf("��1��2\n������ ShortestPath_DIJ�� ����...\n");		//1��2.����ShortestPath_DIJ�Ȳ���	
	{
		PathMatrix P1[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
		ShortPathTable D1[MAX_VERTEX_NUM+1];
		
		printf("���㲢��� %c �������������·����\n", G1.vexs[v0]);
		ShortestPath_DIJ(G1, v0, P1, D1);
		OutputPath_DIJ(G1, v0, P1, D1);
		printf("\n");
	}
	PressEnter;		

	printf("��3\n������ Dijkstra ����...\n");					//3.����Dijkstra����
	{
		PathMatrix path1[MAX_VERTEX_NUM+1];
		ShortPathTable dist1[MAX_VERTEX_NUM+1];
		
		printf("���㲢��� %c �������������·����\n", G1.vexs[v0]);	
		Dijkstra(G1, v0, path1, dist1);
		printf("\n");
	}
	PressEnter;
	
	printf("���������������G2...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_DN_M_Floyd.txt", "r");
		CreateGraph_M(fp, &G2); 
		fclose(fp);
		OutputMGraph(G2);
		printf("\n");
	}
	PressEnter;

	printf("��4��5\n������ ShortestPath_FLOYD�� ����...\n");	//4��5.����ShortestPath_FLOYD�Ȳ���
	{
		PathMatrix P2[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
		ShortPathTable D2[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
		
		printf("���㲢������Զ���֮������·����\n");
		ShortestPath_FLOYD(G2, P2, D2);
		OutputPath_FLOYD(G2, P2, D2);
		printf("\n");
	}
	PressEnter;	

	printf("��6\n������ Floyd ����...\n");						//6.����Floyd����
	{
		PathMatrix path2[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
		ShortPathTable dist2[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
		
		printf("���㲢������Զ���֮������·����\n");
		Floyd(G2, path2, dist2);
		printf("\n");
	}
	PressEnter;
		
	return 0;
}
