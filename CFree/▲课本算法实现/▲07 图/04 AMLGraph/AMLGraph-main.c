/********************************************
 *						                    *
 * �ļ���: ��07 ͼ\04 AMLGraph              *
 * 						                    *
 * �ļ���: AMLGraph-main.c                  *
 * 							                *
 * ��  ��: ����ͼ���ڽӶ��ر���غ������� *
 *                                          *
 ********************************************/

#include <stdio.h> 
#include "AMLGraph.c" 							//**��07 ͼ**//

void PrintElem(char c);

int main(int argc, char *argv[])
{
	AMLGraph G;
	
	printf("��1\n������ CreateDG_AML�� ����...\n");			//1.����CreateDG_AML�Ȳ���
	{
		FILE *fp;
		
		printf("��ʼ������ͼ...\n");
		fp = fopen("TestData_UDG_AML.txt", "r");			//�ĵ��л���¼��Ϊ���� 
		CreateUDG_AML(fp, &G); 
		fclose(fp);
		printf("\n");
	} 
	PressEnter;
	
	printf("��15\n������ OutputAMLGraph ����...\n");		//15.����OutputAMLGraph����
	{
		printf("�������ͼ���ڽӶ��ر� G = \n");		
		OutputAMLGraph(G);
		printf("\n");
	}
	PressEnter;

	printf("��3\n������ LocateVex_AML ����...\n");			//3.����LocateVex_AML����
	{
		printf("���� '%c' ��λ��Ϊ %d \n", 'C', LocateVex_AML(G, 'C'));
		printf("\n");
	} 
	PressEnter;	

	printf("��4\n������ GetVex_AML ����...\n");				//4.����GetVex_AML����
	{
		printf("�� %d �������ֵΪ '%c' \n", 3, GetVex_AML(G, 3));
		printf("\n");
	} 
	PressEnter;	

	printf("��6\n������ FirstAdjVex_AML ����...\n");		//6.����FirstAdjVex_AML����
	{
		printf(" '%c' �ĵ�һ���ڽӶ�������Ϊ %d \n", 'D', FirstAdjVex_AML(G, 'D'));
		printf("\n");
	} 
	PressEnter;	

	printf("��7\n������ NextAdjVex_AML ����...\n");			//7.����NextAdjVex_AML����
	{
		printf(" '%c' ����� '%c' ����һ���ڽӶ������Ϊ %d \n", 'D', 'A', NextAdjVex_AML(G, 'D', 'A'));
		printf("\n");
	} 
	PressEnter;	

	printf("��5\n������ PutVex_AML ����...\n");				//5.����PutVex_AML����
	{
		printf("�Զ��� '%c' ��ֵ '%c'��G = \n", 'A', 'X');
		PutVex_AML(&G, 'A', 'X');
		OutputAMLGraph(G);	
		printf("\n");
	}
	PressEnter;
	
	printf("��8\n������ InsertVex_AML ����...\n");			//8.����InsertVex_AML����
	{
		printf("���붥�� '%c' ��G = \n", 'H');
		InsertVex_AML(&G, 'H');
		OutputAMLGraph(G);	
		printf("\n");
	}
	PressEnter;	

	printf("��10\n������ InsertArc_AML ����...\n");			//10.����InsertArc_AML����
	{
		printf("˳�β��뻡 <%c, %c>��", 'H', 'X');
		printf("<%c, %c>��", 'H', 'C');
		printf("<%c, %c> ��G = \n", 'D', 'H');
		InsertArc_AML(&G, 'H', 'X');
		InsertArc_AML(&G, 'H', 'C');
		InsertArc_AML(&G, 'D', 'H');
		OutputAMLGraph(G);
		printf("\n");
	}
	PressEnter;
	
	printf("��11\n������ DeleteArc_AML ����...\n");			//11.����DeleteArc_AML����
	{
		printf("ɾ���� <%c, %c> ��G = \n", 'H', 'X');
		DeleteArc_AML(&G, 'H', 'X');
		OutputAMLGraph(G);	
		printf("\n");
	} 
	PressEnter;
	
	printf("��09\n������ DeleteVex_AML ����...\n");			//09.����DeleteVex_AML����
	{
		printf("ɾ������ '%c' ��G = \n", 'H');
		DeleteVex_AML(&G, 'H');
		OutputAMLGraph(G);	
		printf("\n");
	}
	PressEnter;

	printf("��12��13\n������ DFSTraverse_AML�� ����...\n");	//12��13.����DFSTraverse_AML�Ȳ���
	{
		printf("������ȱ�������ͼ G = ");
		DFSTraverse_AML(G, PrintElem);	
		printf("\n\n");
	} 
	PressEnter;

	printf("��14\n������ BFSTraverse_AML ����...\n");		//14.����BFSTraverse_AML����
	{
		printf("������ȱ�������ͼ G = ");
		BFSTraverse_AML(G, PrintElem);	
		printf("\n\n");
	}
	PressEnter;
	
	printf("��2\n������ ClearGraph_AML ����...\n");			//2.����ClearGraph_AML����
	{
		printf("�������ͼ...\n");
		ClearGraph_AML(&G);
		OutputAMLGraph(G);	
		printf("\n");
	} 
	PressEnter;				
}

void PrintElem(char c)
{
	printf("%c ", c);
}
