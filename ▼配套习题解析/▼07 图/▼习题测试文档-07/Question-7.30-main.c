#include <stdio.h>
#include "../../../▲课本算法实现/▲07 图/01 MGraph/MGraph.c"		//**▲07 图**//

/* 全局变量 */
enum
{
	WHITE,
	GRAY,
	BLACK
}color[MAX_VERTEX_NUM+1];						//用不同颜色做访问标记 
int p[MAX_VERTEX_NUM];							//暂存路径 
int k;
int path[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];	//存储找的的路径 

/* 函数原型 */
void Algo_7_30(MGraph G);
void DFS_7_30(MGraph G, int i);					//通过深度优先遍历找出所有回路

int main(int argc, char *argv[])
{
	MGraph G;
	FILE *fp;									//作为输入源
	int  m, n;
	
	printf("创建并输出有向图...\n");
	fp = fopen("Data/Algo_7_30.txt", "r");
	G.kind = DG;
	CreateDG_M(fp, &G);
	fclose(fp);
	OutputMGraph(G);
	printf("\n");

	Algo_7_30(G);
	printf("此有向图中共存在 %d 条回路...\n", path[0][0]);
	for(m=1; m<=path[0][0]; m++)
	{
		printf("  %2d  ", path[m][0]);
		printf("    ");
		for(n=1; n<=path[m][0]; n++)
			printf("%c ", G.vexs[path[m][n]]);
		printf("%c", G.vexs[path[m][1]]);
		printf("\n");
	}
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━┓
┃题7.30：找出有向图中所有简单回路┃
┗━━━━━━━━━━━━━━━━*/
void Algo_7_30(MGraph G)	
{
	int i, j;
	
	for(i=0; i<=MAX_VERTEX_NUM; i++)
	{
		for(j=0; j<=MAX_VERTEX_NUM; j++)
			path[i][j] = 0;
	}
	
	for(i=1; i<=G.vexnum; i++)
		color[i] = WHITE;	
	
	for(i=1; i<=G.vexnum; i++)
	{
		k = 1;
		p[k] = i;
		DFS_7_30(G, i);
	}
}

void DFS_7_30(MGraph G, int i)
{
	int u, j;
	
	color[i] = GRAY;
	
	for(u=FirstAdjVex_M(G, G.vexs[i]); u; u=NextAdjVex_M(G, G.vexs[i], G.vexs[u]))
	{
		if(u>p[1] && color[u]==WHITE)
		{
			p[++k] = u;
			DFS_7_30(G, u);
		}
		
		if(u==p[1])
		{
			path[0][0]++;
			path[path[0][0]][0] = k;			//路径长度 
			for(j=1; j<=k; j++)					//将求得的路径存入路径数组 
				path[path[0][0]][j] = p[j];		//回路的终点即起点，不存入数组 			
		}
	}
	
	color[p[k]] = WHITE;						//退回到上一个顶点 
	k--;
}
