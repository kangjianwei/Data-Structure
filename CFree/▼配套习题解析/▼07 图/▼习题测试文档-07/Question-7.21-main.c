#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/02 ALGraph/ALGraph.c"		//**��07 ͼ**//

/* ����ԭ�� */
Status Algo_7_21(ALGraph G);
Status is_adj(ALGraph G, int i, int j);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//��Ϊ����Դ

	printf("�������������ͼ...\n");
	G.kind = UDG;								//������ͼΪ��
	fp = fopen("Data/Algo_7_21.txt", "r");
	CreateUDG_AL(fp, &G);						 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	Algo_7_21(G) ? printf("ͼG�ɴ��ݣ�\n") : printf("ͼG���ɴ��ݣ�\n"); 
	printf("\n");
			
	return 0;
}

/*����������������������������
����7.21���ж�ͼG�Ƿ�ɴ��� ��
����������������������������*/
Status Algo_7_21(ALGraph G)
{
	Status trans;
	int x, y, z;
	ArcNode *p, *q;
	
	trans = TRUE;
	
	for(x=1; x<=G.vexnum; x++)								//V��ÿ��x 
	{
		for(p=G.vertices[x].firstarc; p; p=p->nextarc)
		{
			y = p->adjvex;									//N(x)��ÿ��y
			
			for(q=G.vertices[y].firstarc; q; q=q->nextarc)	
			{
				z = q->adjvex;								//N(y)�в�����x��ÿ��z
				
				if(z!=x && !is_adj(G, x, z))				//z����N(x)��
				{
					trans = FALSE;
				
					return trans;				
				}
			}	
		}
	}
	
	return trans;		
}

/*����������������������������
���ж�j�Ƿ���i���ڽӶ�����  ��
����������������������������*/
Status is_adj(ALGraph G, int i, int j)
{
	ArcNode *p;
	
	for(p=G.vertices[i].firstarc; p; p=p->nextarc)
	{
		if(p->adjvex==j)
			return TRUE;
	}
	
	return FALSE;
}
