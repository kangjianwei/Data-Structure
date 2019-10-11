#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"		//**▲07 图**//

/* 函数原型 */
Status Algo_7_14(FILE *fp, ALGraph *G);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//作为输入源

	printf("创建并输出有向图...\n");
	fp = fopen("Data/Algo_7_14.txt", "r");
	Algo_7_14(fp, &G);
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━┓
┃题7.14：创建有向图邻接表┃
┗━━━━━━━━━━━━*/
Status Algo_7_14(FILE *fp, ALGraph *G)	
{
	return CreateGraph_AL(fp, G);				 
}
