/******************************************
 *                                        *
 * �ļ���: ��07 ͼ\03 OLGraph             *
 *                                        *
 * �ļ���: OLGraph-main.c                 *
 * 							              *
 * ��  ��: ����ͼ��ʮ��������غ������� *
 *                                        *
 ******************************************/

#include <stdio.h>
#include "OLGraph.c" 											//**��07 ͼ**//

void PrintElem(char c);

int main(int argc, char *argv[])
{
	OLGraph G;
	
	printf("��1\n������ CreateDG_OL�� ����...\n");				//1.����CreateDG_OL�Ȳ���
	{
		FILE *fp;
		
		printf("��ʼ������ͼ G ...\n");
		fp = fopen("TestData_DG_OL.txt", "r");					//�ĵ��л���¼��Ϊ���� 
		CreateDG_OL(fp, &G); 
		fclose(fp);
		printf("\n");
	} 
	PressEnter;
	
	printf("��15\n������ OutputOLGraph ����...\n");				//15.����OutputOLGraph����
	{
		printf("�������ͼ��ʮ������ G = \n");		
		OutputOLGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("��3\n������ LocateVex_OL ����...\n");				//3.����LocateVex_OL����
	{
		printf("���� '%c' ��λ��Ϊ %d \n", 'C', LocateVex_OL(G, 'C'));
		printf("\n");
	}
	PressEnter;	

	printf("��4\n������ GetVex_OL ����...\n");					//4.����GetVex_OL����
	{
		printf("�� %d �������ֵΪ '%c' \n", 3, GetVex_OL(G, 3));
		printf("\n");
	}
	PressEnter;	

	printf("��6\n������ FirstAdjVex_OL ����...\n");				//6.����FirstAdjVex_OL����
	{
		printf("' %c' �ĵ�һ���ڽӶ�������Ϊ %d \n", 'D', FirstAdjVex_OL(G, 'D'));
		printf("\n");
	}
	PressEnter;	

	printf("��7\n������ NextAdjVex_OL ����...\n");				//7.����NextAdjVex_OL����
	{
		printf(" '%c' ����� '%c' ����һ���ڽӶ������Ϊ %d\n", 'D', 'A', NextAdjVex_OL(G, 'D', 'A'));
		printf("\n");
	}
	PressEnter;	

	printf("��5\n������ PutVex_OL ����...\n");					//5.����PutVex_OL����
	{
		printf("�Զ��� '%c' ��ֵ '%c'��G = \n", 'A', 'X');
		PutVex_OL(&G, 'A', 'X');
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;
	
	printf("��8\n������ InsertVex_OL ����...\n");					//8.����InsertVex_OL����
	{
		printf("���붥�� '%c'��G = \n", 'H');
		InsertVex_OL(&G, 'H');
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;	

	printf("��10\n������ InsertArc_OL ����...\n");				//10.����InsertArc_OL����
	{
		printf("˳�β��뻡 <%c, %c>��", 'H', 'X');
		printf("<%c, %c>��", 'H', 'C');
		printf("<%c, %c>��G = \n", 'D', 'H');
		InsertArc_OL(&G, 'H', 'X');
		InsertArc_OL(&G, 'H', 'C');
		InsertArc_OL(&G, 'D', 'H');
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;

	printf("��11\n������ DeleteArc_OL ����...\n");				//11.����DeleteArc_OL����
	{
		printf("ɾ���� <%c, %c>��G = \n", 'H', 'X');
		DeleteArc_OL(&G, 'H', 'X');
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;
		
	printf("��09\n������ DeleteVex_OL ����...\n");				//09.����DeleteVex_OL����
	{
		printf("ɾ������ '%c'��G = \n", 'H');
		DeleteVex_OL(&G, 'H');
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;

	printf("��12��13\n������ DFSTraverse_OL�� ����...\n");		//12��13.����DFSTraverse_OL�Ȳ���
	{
		printf("������ȱ�������ͼ G = ");
		DFSTraverse_OL(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;

	printf("��14\n������ BFSTraverse_OL ����...\n");				//14.����BFSTraverse_OL����
	{
		printf("������ȱ�������ͼ G = ");
		BFSTraverse_OL(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;
	
	printf("��2\n������ ClearGraph_OL ����...\n");				//2.����ClearGraph_OL����
	{
		printf("�������ͼ...\n");
		ClearGraph_OL(&G);
		OutputOLGraph(G);	
		printf("\n");
	}
	PressEnter;					
}

void PrintElem(char c)
{
	printf("%c ", c);
}
