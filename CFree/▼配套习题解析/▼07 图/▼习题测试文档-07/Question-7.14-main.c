#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/02 ALGraph/ALGraph.c"		//**��07 ͼ**//

/* ����ԭ�� */
Status Algo_7_14(FILE *fp, ALGraph *G);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//��Ϊ����Դ

	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_14.txt", "r");
	Algo_7_14(fp, &G);
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	return 0;
}

/*��������������������������
����7.14����������ͼ�ڽӱ�
��������������������������*/
Status Algo_7_14(FILE *fp, ALGraph *G)	
{
	return CreateGraph_AL(fp, G);				 
}
