/**************************************
 *					                  *
 * �ļ���: ��07 ͼ\10 CriticalPath    *
 * 					                  *
 * �ļ���: CriticalPath-main.c        *
 * 							          *
 * ��  ��: AOE-���ؼ�·����غ������� *
 *                                    *
 **************************************/

#include <stdio.h>
#include "CriticalPath.c" 									    //**��07 ͼ**//

int main(int argc, char *argv[])
{
	ALGraph G; 
	
	printf("�������������ͼ(��Ȩ)...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_DG_AL.txt", "r");	
		CreateGraph_AL(fp, &G); 
		fclose(fp);
		OutputALGraph(G);
		printf("\n");
	}
	PressEnter;	

	printf("��1��2��3\n������ CriticalPath�� ����...\n");			//1��2��3.����CriticalPath�Ȳ���	
	{
		printf("��������AOV-���еĹؼ�·��...\n");
		CriticalPath(G);
		printf("\n");
	}
	PressEnter;
		
	return 0;
}
