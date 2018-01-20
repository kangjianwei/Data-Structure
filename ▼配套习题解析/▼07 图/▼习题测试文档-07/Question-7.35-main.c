#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/09 TopologicalSort/TopologicalSort.c" //**▲07 图**//

/* 函数原型 */
Status Algo_7_35(ALGraph G, char *root);

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;										//作为输入源	
	char root;
		
	printf("创建并输出有向图...\n");
	fp = fopen("Data/Algo_7_35.txt", "r");	
	CreateGraph_AL(fp, &G); 
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	if(Algo_7_35(G, &root)) 
		printf("此有向无环图的根为：%c\n", root);
	else
		printf("找不到此有向图的根！\n");
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━┓
┃题7.35：求DAG图的根（求拓扑序列起点） ┃
┗━━━━━━━━━━━━━━━━━━━*/
Status Algo_7_35(ALGraph G, char *root)
{	
	int indegree[MAX_VERTEX_NUM+1];	
	int k, count;

	FindInDegree(G, indegree);						//对各顶点求入度已定义 
	
	for(k=1,count=0; k<=G.vexnum; k++)
	{
		if(!indegree[k])
		{
			count++;
			*root = G.vertices[k].data;		
		}
	}
	
	if(count==1)									//有向无环弱连通图的根若存在则唯一
		return OK;
	else
		return ERROR;
}
