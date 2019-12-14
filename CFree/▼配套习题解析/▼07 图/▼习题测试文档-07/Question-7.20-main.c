#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**��01 ����**//
#include "../../../���α��㷨ʵ��/��07 ͼ/01 MGraph/MGraph.c"		//**��07 ͼ**//

/* ����ԭ�� */
Status Algo_7_20(MGraph G);

int main(int argc, char *argv[])
{
	MGraph G;
	FILE *fp;									//��Ϊ����Դ

	printf("�������������ͼ...\n");
	G.kind = UDG;								//������ͼΪ��
	fp = fopen("Data/Algo_7_20.txt", "r");
	CreateUDG_M(fp, &G);						 
	fclose(fp);
	OutputMGraph(G);
	printf("\n");
	
	Algo_7_20(G) ? printf("ͼG�ɴ��ݣ�\n") : printf("ͼG���ɴ��ݣ�\n"); 
	printf("\n");
			
	return 0;
}

/*����������������������������
����7.20���ж�ͼG�Ƿ�ɴ��� ��
����������������������������*/
Status Algo_7_20(MGraph G)
{
	Status trans;
	int x, y, z;
	
	trans = TRUE;
	
	for(x=1; x<=G.vexnum; x++)						//V��ÿ��x 
	{
		for(y=1; y<=G.vexnum; y++)					//N(x)��ÿ��y 
		{
			if(G.arcs[x][y].adj)					//y��x���ڽӶ���
			{
				for(z=1; z<=G.vexnum; z++)			 
				{
					if(G.arcs[y][z].adj && z!=x)	//N(y)�в�����x��ÿ��z
					{						
						if(!G.arcs[x][z].adj)		//z����N(x)��
						{
							trans = FALSE;
							
							return trans;
						} 
					}
				}
			} 
		}
	}
	
	return trans;	
} 
