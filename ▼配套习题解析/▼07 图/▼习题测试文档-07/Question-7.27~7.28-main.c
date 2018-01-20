#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"	//**▲03 栈和队列**//
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"		//**▲07 图**//

/* 宏定义 */
#define MAX 100									//找出的最大路径数 

/* 全局变量 */
Status mark;
SqStack S;										//暂存路径
int path[MAX+1][MAX_VERTEX_NUM+1];				//存储找的的路径 

/* 函数原型 */
Status Algo_7_27(ALGraph G, int i, int j, int k);
Status Algo_7_28(ALGraph G, int i, int j);
void DFS_7_27(ALGraph G, int i, int j, int k);	//通过有限的深度优先遍历判断路径是否存在
void DFS_7_28(ALGraph G, int i, int j);			//通过深度优先遍历找出所有路径

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;									//作为输入源
	char v1, v2;
	int i, j, k, m, n;
	int *p;
	
	printf("创建并输出无向图...\n");
	fp = fopen("Data/Algo_7_27-7_28.txt", "r");
	CreateGraph_AL(fp, &G);
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	v1 = 'a';
	v2 = 'c';
	i = LocateVex_AL(G, v1);
	j = LocateVex_AL(G, v2);
	k = 4;
	
	printf("███ 题 7.27 验证... ███\n");
	Algo_7_27(G, i, j, k);
	printf("%c 到 %c 之间", v1, v2);
	mark ? printf("存在") : printf("不存在");
	printf("长度为 %d 的路径！\n", k);
	printf("\n");

	printf("███ 题 7.28 验证... ███\n");
	Algo_7_28(G, i, j);
	if(!path[0][0])
		printf("%c 到 %c 之间不存在路径：", G.vertices[i].data, G.vertices[j].data);
	else
	{
		printf("%c 到 %c 之间存在 %d 条路径：\n", G.vertices[i].data, G.vertices[j].data, path[0][0]);
		printf("路径长    路径\n");
		for(m=1; m<=path[0][0]; m++)
		{
			printf("  %2d  ", path[m][0]-1);
			printf("    ");
			for(n=1; n<=path[m][0]; n++)
				printf("%c ", G.vertices[path[m][n]].data);
			printf("\n");
		}
	}
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃题7.27：判断i到j之间是否存在长度为k的简单路径 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/
Status Algo_7_27(ALGraph G, int i, int j, int k)	
{
	int v;
		 
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;						//将访问标记初始化为未访问		
	
	mark = FALSE;
	
	DFS_7_27(G, i, j, k); 						//通过有限的深度优先遍历判断路径是否存在 
	
	return mark ?  TRUE : FALSE;
}

/*━━━━━━━━━━━━━━━━┓
┃题7.28：找出i到j之间所有简单路径┃
┗━━━━━━━━━━━━━━━━*/
Status Algo_7_28(ALGraph G, int i, int j)	
{
	int m, n;
		 
	for(m=1; m<=G.vexnum; m++)
		visited[m] = FALSE;						//将访问标记初始化为未访问

	InitStack_Sq(&S);							//初始化路径栈（暂存路径） 
		
	for(m=0; m<=MAX; m++)						//初始化路径数组 
	{
		for(n=0; n<=MAX_VERTEX_NUM; n++)
			path[m][n] = 0;
	}
	
	DFS_7_28(G, i, j); 							//通过深度优先遍历找出所有路径 
	
	if(!path[0][0])
		return FALSE;
	else	
		return TRUE;
}

void DFS_7_27(ALGraph G, int i, int j, int k)
{
	int w, e;
	int count;
	int *p;
	
	visited[i] = TRUE;
	Push_Sq(&S, i);
	
	if(i==j)
	{
		for(p=S.base,count=-1; p<S.top; p++,count++)
			;
		
		if(count==k)
			mark = TRUE;
		else
		{
			Pop_Sq(&S, &e);
			visited[i] = FALSE;		
		}
				
		return;
	}
	
	for(w=FirstAdjVex_AL(G, G.vertices[i].data); w && !mark; w=NextAdjVex_AL(G, G.vertices[i].data, G.vertices[w].data))
	{
		if(!visited[w])
			DFS_7_27(G, w, j, k);
	}
	
	if(!w && !mark){
		visited[i] = FALSE;
		Pop_Sq(&S, &e);
	}
}

void DFS_7_28(ALGraph G, int i, int j)
{
	int w, e;
	int *p;
	
	visited[i] = TRUE;
	Push_Sq(&S, i);
	
	if(i==j)
	{
		path[0][0]++;
		
		for(p=S.base; p<S.top; p++)
			path[path[0][0]][++path[path[0][0]][0]] = *p; 
		
		Pop_Sq(&S, &e);
		visited[i] = FALSE;
		
		return;
	}
	
	for(w=FirstAdjVex_AL(G, G.vertices[i].data); w; w=NextAdjVex_AL(G, G.vertices[i].data, G.vertices[w].data))
	{
		if(!visited[w])
			DFS_7_28(G, w, j);
	}
	
	if(!w)
	{
		Pop_Sq(&S, &e);
		visited[i] = FALSE;
	}
}
