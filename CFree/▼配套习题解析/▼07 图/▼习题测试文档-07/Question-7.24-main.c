#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"	//**▲03 栈和队列**//
#include "../../../▲课本算法实现/▲07 图/01 MGraph/MGraph.c"		//**▲07 图**//

/* 函数原型 */
Status Algo_7_24(MGraph G, int start);

int main(int argc, char *argv[])
{
	MGraph G;
	FILE *fp;									//作为输入源

	printf("创建并输出有向图...\n");
	fp = fopen("Data/Algo_7_24.txt", "r");
	G.kind = DG;								//有向图
	CreateDG_M(fp, &G);	
	fclose(fp);
	OutputMGraph(G);
	printf("\n");
	
	printf("遍历图...\n");
	Algo_7_24(G, 1);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━┓
┃题7.24：遍历有向图（深度优先遍历策略）┃
┗━━━━━━━━━━━━━━━━━━━*/
Status Algo_7_24(MGraph G, int start)				//以有向图邻接矩阵存储结构为例 
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
