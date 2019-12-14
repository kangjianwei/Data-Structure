#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��03 ջ�Ͷ���/01 SequenceStack/SequenceStack.c"	//**��03 ջ�Ͷ���**//
#include "../../../���α��㷨ʵ��/��07 ͼ/01 MGraph/MGraph.c"		//**��07 ͼ**//

/* ����ԭ�� */
Status Algo_7_24(MGraph G, int start);

int main(int argc, char *argv[])
{
	MGraph G;
	FILE *fp;									//��Ϊ����Դ

	printf("�������������ͼ...\n");
	fp = fopen("Data/Algo_7_24.txt", "r");
	G.kind = DG;								//����ͼ
	CreateDG_M(fp, &G);	
	fclose(fp);
	OutputMGraph(G);
	printf("\n");
	
	printf("����ͼ...\n");
	Algo_7_24(G, 1);
	printf("\n\n");
		
	return 0;
}

/*����������������������������������������
����7.24����������ͼ��������ȱ������ԣ���
����������������������������������������*/
Status Algo_7_24(MGraph G, int start)				//������ͼ�ڽӾ���洢�ṹΪ�� 
{
	SqStack S;
	SElemType_Sq e;
	int i;
	
	for(i=1; i<=G.vexnum; i++)
		visited[i] = FALSE;
	
	InitStack_Sq(&S);
	Push_Sq(&S, start);
	visited[start] = TRUE;
	printf("%d ", start);

	while(!StackEmpty_Sq(S))
	{
		GetTop_Sq(S, &e);
		
		for(i=1; i<=G.vexnum; i++)
		{
			if(G.arcs[e][i].adj && !visited[i])
			{
				Push_Sq(&S, i);
				visited[i] = TRUE;
				printf("%d ", i);
				break;
			}
		}
		
		if(i>G.vexnum)
			Pop_Sq(&S, &e);
	}	
}
