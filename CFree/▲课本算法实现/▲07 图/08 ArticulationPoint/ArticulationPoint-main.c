/****************************************
 *    	    		                    *
 * �ļ���: ��07 ͼ\08 ArticulationPoint *
 * 					                    *
 * �ļ���: ArticulationPoint-main.c     *
 * 							            *
 * ��  ��: ����ͼ�ؽڵ���غ�������     *
 *                                      *
 ****************************************/

#include <stdio.h>
#include "ArticulationPoint.c" 									//**��07 ͼ**//													

int main(int argc, char *argv[])
{
	ALGraph G;	
	
	printf("�������������ͼ...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_UDG_AL.txt", "r");	
		CreateGraph_AL(fp, &G); 
		fclose(fp);
		OutputALGraph(G);
		printf("\n");
	}
	PressEnter;	

	printf("��1��2��3��4\n������ FindArticul�� ����...\n");		//1��2��3��4.����FindArticul��OutputAPoint�Ȳ���	
	{
		printf("Ѱ�Ҳ�����ؽڵ�...\n");
		FindArticul(G);
		OutputAPoint(G);
		printf("\n");
	}
	PressEnter;
		
	return 0;
}
