#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/01 MGraph/MGraph.c"		//**▲07 图**//

/* 函数原型 */
Status Algo_7_20(MGraph G);

int main(int argc, char *argv[])
{
	MGraph G;
	FILE *fp;									//作为输入源

	printf("创建并输出无向图...\n");
	G.kind = UDG;								//以无向图为例
	fp = fopen("Data/Algo_7_20.txt", "r");
	CreateUDG_M(fp, &G);						 
	fclose(fp);
	OutputMGraph(G);
	printf("\n");
	
	Algo_7_20(G) ? printf("图G可传递！\n") : printf("图G不可传递！\n"); 
	printf("\n");
			
	return 0;
}

/*━━━━━━━━━━━━━┓
┃题7.20：判断图G是否可传递 ┃
┗━━━━━━━━━━━━━*/
Status Algo_7_20(MGraph G)
{
	Status trans;
	int x, y, z;
	
	trans = TRUE;
	
	for(x=1; x<=G.vexnum; x++)						//V中每个x 
	{
		for(y=1; y<=G.vexnum; y++)					//N(x)中每个y 
		{
			if(G.arcs[x][y].adj)					//y是x的邻接顶点
			{
				for(z=1; z<=G.vexnum; z++)			 
				{
					if(G.arcs[y][z].adj && z!=x)	//N(y)中不等于x的每个z
					{						
						if(!G.arcs[x][z].adj)		//z不在N(x)中
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
