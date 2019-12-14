/***************************************
 *				                       *
 * �ļ���: ��07 ͼ\07 MiniSpanningTree *
 * 				                       *
 * �ļ���: MST-main.c                  *
 *				                       *
 * ��  ��: ��С��������غ�������      *
 *				                       *
 ***************************************/

#include <stdio.h>
#include "MST.c" 												//**��07 ͼ**//													

int main(int argc, char *argv[])
{
	MGraph G;

	printf("��ʼ�������������...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_UDN_M.txt", "r");	
		CreateGraph_M(fp, &G); 
		fclose(fp);
		OutputMGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("��1��2\n������ MinSpanTree_PRIM_1�� ����...\n");		//1��2.����MinSpanTree_PRIM_1�Ȳ���
	{
		printf("����ķ�㷨...\n");	
		printf("�Ⱥ������С�������ĸ���㼰���Ӧ����С�ߵ�Ȩֵ�ֱ�Ϊ��\n");
		MinSpanTree_PRIM_1(G, 'A');
		printf("\n");
	} 
	PressEnter;

	printf("��3��4\n������ MinSpanTree_PRIM_2�� ����...\n");		//3��4.����MinSpanTree_PRIM_2�Ȳ���
	{
		printf("����ķ�㷨...\n");			
		printf("��С�������ĸ��߼����Ӧ��Ȩֵ�ֱ�Ϊ��\n");	
		MinSpanTree_PRIM_2(G, 'A');
		printf("\n");
	} 
	PressEnter;

	printf("��5��6��7��8\n������ MinSpanTree_KRUSKAL�� ����...\n");//5��6��7��8.����MinSpanTree_KRUSKAL�Ȳ���	
	{
		printf("��³˹�����㷨...\n");	
		printf("��С�������ĸ��߼����Ӧ��Ȩֵ�ֱ�Ϊ��\n");		
		MinSpanTree_KRUSKAL(G);
		printf("\n");
	}
	PressEnter;
}
