#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"		//**▲07 图**//

/* 函数原型 */
Status Algo_7_21(ALGraph G);
Status is_adj(ALGraph G, int i, int j);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//作为输入源

	printf("创建并输出无向图...\n");
	G.kind = UDG;								//以无向图为例
	fp = fopen("Data/Algo_7_21.txt", "r");
	CreateUDG_AL(fp, &G);						 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	Algo_7_21(G) ? printf("图G可传递！\n") : printf("图G不可传递！\n"); 
	printf("\n");
			
	return 0;
}

/*━━━━━━━━━━━━━┓
┃题7.21：判断图G是否可传递 ┃
┗━━━━━━━━━━━━━*/
Status Algo_7_21(ALGraph G)
{
	Status trans;
	int x, y, z;
	ArcNode *p, *q;
	
	trans = TRUE;
	
	for(x=1; x<=G.vexnum; x++)								//V中每个x 
	{
		for(p=G.vertices[x].firstarc; p; p=p->nextarc)
		{
			y = p->adjvex;									//N(x)中每个y
			
			for(q=G.vertices[y].firstarc; q; q=q->nextarc)	
			{
				z = q->adjvex;								//N(y)中不等于x的每个z
				
				if(z!=x && !is_adj(G, x, z))				//z不在N(x)中
				{
					trans = FALSE;
				
					return trans;				
				}
			}	
		}
	}
	
	return trans;		
}

/*━━━━━━━━━━━━━┓
┃判断j是否在i的邻接顶点中  ┃
┗━━━━━━━━━━━━━*/
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
