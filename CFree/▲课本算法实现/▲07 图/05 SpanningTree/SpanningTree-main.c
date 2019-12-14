/************************************
 *                                  *
 * �ļ���: ��07 ͼ\05 SpanningTree  *
 *                                  *
 * �ļ���: SpanningTree-main.c      *
 * 							        *
 * ��  ��: ����ͼ��������غ������� *
 *                                  *
 ************************************/

#include <stdio.h>
#include "SpanningTree.c"											

int main(int argc, char *argv[])
{
	MGraph G;
			
	printf("�������������ͼ�������ʾ����...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_UDG_M.txt", "r");	
		CreateGraph_M(fp, &G); 
		fclose(fp);
		OutputMGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("��1��2\n������ DFSForest�� ����...\n");		//1��2.����DFSForest�Ȳ���
	{
		CSTree T;
		
		printf("�������������ͼ����������ɭ�֣�...\n");		
		DFSForest(G, &T);
		Print_CS(T);
		printf("\n");
	}
	PressEnter;

	return 0;
}
