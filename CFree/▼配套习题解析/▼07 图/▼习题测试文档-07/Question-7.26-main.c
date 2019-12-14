#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"	//**▲03 栈和队列**//
#include "../../../▲课本算法实现/▲07 图/01 MGraph/MGraph.c"		//**▲07 图**//

/* 函数原型 */
Status Algo_7_26(MGraph G);
void FindInDegree_7_26(MGraph G, int indegree[]);//对各顶点求入度

int main(int argc, char *argv[])
{
	MGraph G;
	FILE *fp;									//作为输入源

	printf("创建并输出无向图...\n");
	G.kind = DG;								//以无向图为例
	fp = fopen("Data/Algo_7_26.txt", "r");
	CreateDG_M(fp, &G);						 
	fclose(fp);
	OutputMGraph(G);
	printf("\n");
	
	Algo_7_26(G);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━┓
┃题7.26：将有向图邻接矩阵变为下三角形式┃
┗━━━━━━━━━━━━━━━━━━━*/
Status Algo_7_26(MGraph G)			//本质是将原图拓扑序列变为逆拓扑序列 
{
	SqStack S;
	int i, j;
	int count, indegree[MAX_VERTEX_NUM+1];
	int tmp[MAX_VERTEX_NUM+1];							//存储拓扑序列
	
	FindInDegree_7_26(G, indegree);						//对各顶点求入度
	InitStack_Sq(&S);									//初始化栈 
	
	for(i=1; i<=G.vexnum; i++)							//建立入度为0的顶点栈 
	{
		if(!indegree[i])
			Push_Sq(&S, i);								//入度为0者进栈 
	}
	
	count = 0;											//对原序列计数
	
	while(!StackEmpty_Sq(S))
	{		
		Pop_Sq(&S, &i);		 
		count++; 
		tmp[count] = i;									//暂存于数组中 

		for(j=1; j<=G.vexnum; j++)
		{
			if(G.arcs[i][j].adj)				
			{
				if(!(--indegree[j]))					//对i号顶点的每个邻接点的入度减一
					Push_Sq(&S, j); 			
			}
		}
	} 
	
	if(count<G.vexnum)
	{
		printf("该有向图有回路！！\n");
		return ERROR;	
	}
	else
	{
		printf("该有向图的拓扑序列为：\n旧编号序列 →");
		for(i=1; i<=G.vexnum; i++)
			printf(" %c", G.vexs[tmp[i]]);
		printf("\n\n");

		printf("该有向图的逆拓扑序列为：\n新编号序列 →");
		for(i=G.vexnum; i>=1; i--)
			printf(" %c", G.vexs[tmp[i]]);
		printf("\n");
		
		return OK;
	}	
		
}

void FindInDegree_7_26(MGraph G, int indegree[])
{
	int i, j;
	
	for(i=1; i<=G.vexnum; i++)
		indegree[i] = 0;								//初始化入度数组
		
	for(i=1; i<=G.vexnum; i++)
	{		
		for(j=1; j<=G.vexnum; j++)
		{
			if(G.arcs[i][j].adj)
				indegree[j]++;
		}
	}
	 
}
