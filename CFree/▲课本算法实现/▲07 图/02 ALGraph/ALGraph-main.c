/************************************
 *					                *
 * �ļ���: ��07 ͼ\02 ALGraph       *
 * 					                *
 * �ļ���: ALGraph-main.c           *
 * 							        *
 * ��  ��: ͼ���ڽӱ���غ������� *
 *                                  *
 ************************************/

#include <stdio.h> 
#include "ALGraph.c" 										//**��07 ͼ**//

void PrintElem(char c);

int main(int argc, char *argv[])
{
	ALGraph G;

	printf("��1��2��3\n������ CreateGraph_AL�� ����...\n");	//1��2��3.����CreateGraph_AL�Ȳ���
	{
		FILE *fp;
		int r;
		
		srand((unsigned)time(NULL));						//��ϵͳʱ������������� 
		r = rand()%2;										//���������
	
		switch(r)
		{
			case DG:
				printf("��ʼ������ͼ...\n");
				fp = fopen("TestData_DG_AL.txt", "r");
				break;
			case UDG:
				printf("��ʼ������ͼ...\n");
				fp = fopen("TestData_UDG_AL.txt", "r");
				break;			
		}
		CreateGraph_AL(fp, &G); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("��17\n������ OutputALGraph ����...\n");			//17.����OutputALGraph����
	{
		printf("���ͼ���ڽӱ� G = \n");		
		OutputALGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("��5\n������ LocateVex_AL ����...\n");			//5.����LocateVex_AL����
	{
		printf("���� '%c' ��λ��Ϊ %d \n", 'C', LocateVex_AL(G, 'C'));
		printf("\n");
	}
	PressEnter;	

	printf("��6\n������ GetVex_AL ����...\n");				//6.����GetVex_AL����
	{
		printf("�� %d �������ֵΪ '%c'\n", 3, GetVex_AL(G, 3));
		printf("\n");
	}
	PressEnter;	

	printf("��8\n������ FirstAdjVex_AL ����...\n");			//8.����FirstAdjVex_AL����
	{
		printf(" '%c' �ĵ�һ���ڽӶ�������Ϊ %d \n", 'B', FirstAdjVex_AL(G, 'B'));
		printf("\n");
	} 
	PressEnter;	

	printf("��9\n������ NextAdjVex_AL ����...\n");			//9.����NextAdjVex_AL����
	{
		printf(" '%c' ����� '%c' ����һ���ڽӶ������Ϊ %d \n", 'A', 'B', NextAdjVex_AL(G, 'A', 'B'));
		printf("\n");
	} 
	PressEnter;	

	printf("��7\n������ PutVex_AL ����...\n");				//7.����PutVex_AL����
	{
		printf("�Զ��� '%c' ��ֵ '%c' ��G = \n", 'A', 'X');
		PutVex_AL(&G, 'A', 'X');
		OutputALGraph(G);	
		printf("\n");
	} 
	PressEnter;
	
	printf("��10\n������ InsertVex_AL ����...\n");			//10.����InsertVex_AL����
	{
		printf("���붥�� '%c' ��G = \n", 'H');
		InsertVex_AL(&G, 'H');
		OutputALGraph(G);	
		printf("\n");
	} 
	PressEnter;	

	printf("��12\n������ InsertArc_AL ����...\n");			//12.����InsertArc_AL����
	{
		printf("˳�β��뻡 <%c, %c>��", 'H', 'X');
		printf("<%c, %c>��", 'H', 'C');
		printf("<%c, %c> ��G = \n", 'D', 'H');
		InsertArc_AL(&G, 'H', 'X');
		InsertArc_AL(&G, 'H', 'C');
		InsertArc_AL(&G, 'D', 'H');
		OutputALGraph(G);	
		printf("\n");
	} 
	PressEnter;

	printf("��13\n������ DeleteArc_AL ����...\n");			//13.����DeleteArc_AL����
	{
		printf("ɾ���� <%c, %c> ��G = \n", 'H', 'X');
		DeleteArc_AL(&G, 'H', 'X');
		OutputALGraph(G);	
		printf("\n");
	}
	PressEnter;
		
	printf("��11\n������ DeleteVex_AL ����...\n");			//11.����DeleteVex_AL����
	{
		printf("ɾ������ '%c' ��G = \n", 'H');
		DeleteVex_AL(&G, 'H');
		OutputALGraph(G);	
		printf("\n");
	}
	PressEnter;

	printf("��14��15\n������ DFSTraverse_AL�� ����...\n");	//14��15.����DFSTraverse_AL�Ȳ���
	{
		printf("������ȱ���ͼ G = ");
		DFSTraverse_AL(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;

	printf("��16\n������ BFSTraverse_AL ����...\n");		//16.����BFSTraverse_AL����
	{
		printf("������ȱ���ͼ G = ");
		BFSTraverse_AL(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;
	
	printf("��4\n������ ClearGraph_AL ����...\n");			//4.����ClearGraph_AL����
	{
		printf("���ͼ...\n");
		ClearGraph_AL(&G);
		OutputALGraph(G);	
		printf("\n");
	}
	PressEnter;					
}

void PrintElem(char c)
{
	printf("%c ", c);
}
