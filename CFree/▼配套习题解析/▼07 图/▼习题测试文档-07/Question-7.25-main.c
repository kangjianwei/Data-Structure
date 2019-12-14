#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"			//**▲01 绪论**//
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"			//**▲01 绪论**//
#include "../../../▲课本算法实现/▲03 栈和队列/01 SequenceStack/SequenceStack.c"	//**▲03 栈和队列**//

/* 宏定义 */
#define MAX_VERTEX_NUM 20				//最大顶点个数 
#define MAX 1000						//最大容量 

/* 全局变量 */
Status visited[MAX_VERTEX_NUM+1];		//访问标记 
Status mark;							//回路标记 
SqStack path;							//路径 

/* 图的存储结构类型定义 */
typedef struct
{
	char vexs[MAX_VERTEX_NUM+1];				//顶点向量
	int s[MAX];									//存储每个顶点的后继顶点 
	int fst[MAX_VERTEX_NUM+1], lst[MAX_VERTEX_NUM+1];	//某个顶点后继顶点在s中的起止范围 
	int vexnum,	arcnum;							//有向图的当前顶点数和弧数	
}Graph;

/* 函数原型 */
Status Algo_7_25(Graph G);
Status CreateGraph_7_25(FILE *fp, Graph *G);		//创建有向图
void OutputGraph_7_25(Graph G);						//输出有向图
int LocateVex_7_25(Graph G, char u);				//返回元素u在图中的位序 
int FirstAdjVex_7_25(Graph G, int v);				//返回v的第一个邻接顶点 
int NextAdjVex_7_25(Graph G, int v, int w);			//返回以v基于w的下一个邻接顶点 
void DFS_7_25(Graph G, int v);						//深度优先遍历有向图 
Status IsExistPath_7_25(int e);						//判断元素e是否存在于栈中

int main(int argc, char *argv[])
{
	Graph G;
	FILE *fp;									//作为输入源

	printf("创建并输出有向图...\n");
	fp = fopen("Data/Algo_7_25.txt", "r");
	CreateGraph_7_25(fp, &G);
	fclose(fp);
	OutputGraph_7_25(G);
	printf("\n");
	
	InitStack_Sq(&path);
	Algo_7_25(G) ? printf("图中有回路！") : printf("图中无回路！！");
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━┓
┃题7.25：判断有向图中是否存在回路┃
┗━━━━━━━━━━━━━━━━*/
Status Algo_7_25(Graph G)	
{
	int v;
	
	for(v=1; v<=G.vexnum; v++)
		visited[v] = FALSE;

	for(v=1; v<=G.vexnum && !mark; v++)
	{
		if(!visited[v])
			DFS_7_25(G, v);						//利用深度优先搜索判断有向图是否有回路 
	}
	
	return mark;								//全局变量，标记是否找到回路 
}

Status CreateGraph_7_25(FILE *fp, Graph *G)		//创建有向图 
{
	int i, j, k, total;
	int count[MAX_VERTEX_NUM+1];
	char tmp, v1, v2;
	
	Scanf(fp, "%d%d", &((*G).vexnum), &((*G).arcnum));
	Scanf(fp, "%c", &tmp);						//跳过换行符
	
	for(k=1; k<=(*G).vexnum; k++)
	{
		Scanf(fp, "%c", &((*G).vexs[k]));	
		count[k] = 0;
	}
	Scanf(fp, "%c", &tmp);						//跳过换行符
	
	for(k=1; k<=(*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &v1, &v2);
		
		i = LocateVex_7_25(*G, v1);
		j = LocateVex_7_25(*G, v2);
		
		(*G).s[k] = j;
		count[i]++;
	}
	
	for(k=1,total=0; k<=(*G).arcnum; k++)
	{
		(*G).fst[k] = total + 1;

		total += count[k];
		
		if(count[k])
			(*G).lst[k] = total;
		else
			(*G).lst[k] = 0;
	}
}

void OutputGraph_7_25(Graph G)					//输出有向图 
{
	int i, j;
	
	if(!G.vexnum && !G.arcnum)
		printf("有向图为空！\n");
	else
	{
		for(i=1; i<=G.vexnum; i++)
		{
			printf("%c→", G.vexs[i]);
			
			for(j=G.fst[i]; j<=G.lst[i]; j++)
				printf(" %c", G.vexs[G.s[j]]);
			
			printf("\n");	
		}
	}
}

int LocateVex_7_25(Graph G, char u)				//返回元素u在图中的位序 
{
	int i;
	
	for(i=1; i<=G.vexnum; i++)
	{
		if(G.vexs[i]==u)
			return i;
	}
	
	return 0;
}

int FirstAdjVex_7_25(Graph G, int v)			//返回v的第一个邻接顶点 
{	
	if(G.fst[v]<=G.lst[v])
		return G.s[G.fst[v]];
	
	return 0;
} 

int NextAdjVex_7_25(Graph G, int v, int w)	//返回以v基于w的下一个邻接顶点 
{
	int i;
	
	if(G.fst[v]<=G.lst[v])
	{
		for(i=G.fst[v]; i<=G.lst[v] && i!=w; i++)
			;
		
		if(i<G.lst[v])
			return G.s[i+1];
	}
	 
	return 0; 
}

void DFS_7_25(Graph G, int v)				//深度优先遍历有向图 
{
	int w, e;

	visited[v] = TRUE;
	Push_Sq(&path, v);
	
	for(w=FirstAdjVex_7_25(G, v); w && !mark; w=NextAdjVex_7_25(G, v, w))
	{
		if(!visited[w])
			DFS_7_25(G, w);
		else
		{
			if(IsExistPath_7_25(w))
				mark = TRUE;
		}
	}
	
	if(!w && !mark)
		Pop_Sq(&path, &e);	
}

Status IsExistPath_7_25(int e)				//判断元素e是否存在于栈中
{
	int *p;
	
	for(p=path.base; p<path.top; p++)
	{
		if(*p==e)
			return TRUE;
	}
	
	return ERROR;
}
