/******************************************************
 *						                              *
 * �ļ���: ��07 ͼ\01 MGraph                          *
 * 						                              *
 * �ļ���: MGraph-main.c                              *
 * 							                          *
 * ��  ��: ͼ��������飨�ڽӾ��󣩱�ʾ����غ������� *
 *                                                    *
 ******************************************************/

#include <stdio.h>
#include "MGraph.c" 											//**��07 ͼ**//

void PrintElem(char c);

int main(int argc, char *argv[])
{
	MGraph G;

	printf("��1��2��3��4��5\n������ CreateGraph_M�� ����...\n");//1��2��3��4��5.����CreateGraph_M�Ȳ���
	{
		FILE *fp;
		int r;
		
		srand((unsigned)time(NULL));							//��ϵͳʱ������������� 
		r = rand()%4;											//���������
		
		switch(r)
		{
			case DG:
				printf("��ʼ������ͼ G ...\n");
				fp = fopen("TestData_DG_M.txt", "r");
				break;
			case DN:
				printf("��ʼ�������� G ...\n");
				fp = fopen("TestData_DN_M.txt", "r");
				break;
			case UDG:
				printf("��ʼ������ͼ G ...\n");
				fp = fopen("TestData_UDG_M.txt", "r");
				break;	
			case UDN:
				printf("��ʼ�������� G ...\n");
				fp = fopen("TestData_UDN_M.txt", "r");
				break;				
		}
		CreateGraph_M(fp, &G); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("��19\n������ OutputMGraph ����...\n");				//19.����OutputMGraph����
	{
		printf("���ͼ���������ڽӾ��� G = \n");		
		OutputMGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("��7\n������ LocateVex_M ����...\n");					//7.����LocateVex_M����
	{
		printf("���� '%c' ��λ��Ϊ %d\n", 'C', LocateVex_M(G, 'C'));
		printf("\n");
	}
	PressEnter;	

	printf("��8\n������ GetVex_M ����...\n");						//8.����GetVex_M����
	{
		printf("�� %d �������ֵΪ '%c'\n", 3, GetVex_M(G, 3));
		printf("\n");
	}
	PressEnter;	

	printf("��10\n������ FirstAdjVex_M ����...\n");				//10.����FirstAdjVex_M����
	{
		printf(" '%c' �ĵ�һ���ڽӶ�������Ϊ %d\n", 'B', FirstAdjVex_M(G, 'B'));
		printf("\n");
	}
	PressEnter;	

	printf("��11\n������ NextAdjVex_M ����...\n");				//11.����NextAdjVex_M����
	{
		printf(" '%c' ����� '%c' ����һ���ڽӶ������Ϊ %d\n", 'A', 'B', NextAdjVex_M(G, 'A', 'B'));
		printf("\n");
	}
	PressEnter;	

	printf("��9\n������ PutVex_M ����...\n");						//9.����PutVex_M����
	{
		printf("�Զ��� '%c' ��ֵ '%c' ��G = \n", 'A', 'X');
		PutVex_M(&G, 'A', 'X');
		OutputMGraph(G);	
		printf("\n");
	}
	PressEnter;
	
	printf("��12\n������ InsertVex_M ����...\n");					//12.����InsertVex_M����
	{
		printf("���붥�� '%c' ��G = \n", 'H');
		InsertVex_M(&G, 'H');
		OutputMGraph(G);	
		printf("\n");
	}
	PressEnter;	

	printf("��14\n������ InsertArc_M ����...\n");					//14.����InsertArc_M����
	{
		printf("˳�β��뻡 <%c, %c, 1>��", 'H', 'X');
		printf("<%c, %c, 1>��", 'H', 'C');
		printf("<%c, %c, 1> ��G = \n", 'D', 'H');
		InsertArc_M(&G, 'H', 'X', 1);
		InsertArc_M(&G, 'H', 'C', 1);
		InsertArc_M(&G, 'D', 'H', 1);
		OutputMGraph(G);	
		printf("\n");
	}
	PressEnter;

	printf("��15\n������ DeleteArc_M ����...\n");					//15.����DeleteArc_M����
	{
		printf("ɾ���� <%c, %c> ��G = \n", 'H', 'X');
		DeleteArc_M(&G, 'H', 'X');
		OutputMGraph(G);	
		printf("\n");
	}
	PressEnter;
		
	printf("��13\n������ DeleteVex_M ����...\n");					//13.����DeleteVex_M����
	{
		printf("ɾ������ '%c' ��G = \n", 'B');
		DeleteVex_M(&G, 'B');
		OutputMGraph(G);	
		printf("\n");
	}
	PressEnter;

	printf("��16��17\n������ DFSTraverse_M�� ����...\n");			//16��17.����DFSTraverse_M�Ȳ���
	{
		printf("������ȱ���ͼ����G = ");
		DFSTraverse_M(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;
	
	printf("��18\n������ BFSTraverse_M ����...\n");				//18.����BFSTraverse_M����
	{
		printf("������ȱ���ͼ����G = ");
		BFSTraverse_M(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;		
	
	printf("��6\n������ ClearGraph_M ����...\n");					//6.����ClearGraph_M����
	{
		printf("��ձ�ͼ��G ...\n");
		ClearGraph_M(&G);
		OutputMGraph(G);	
		printf("\n");
	}
	PressEnter;					
}

void PrintElem(char c)
{
	printf("%c ", c);
}
