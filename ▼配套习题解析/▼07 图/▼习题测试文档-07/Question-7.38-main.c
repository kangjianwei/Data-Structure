#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"					//**▲07 图**//

/* 全局变量 */
int ReversePolish[MAX_VERTEX_NUM+1];	//0号单元用作计数，存放逆波兰序列 
char c[MAX_VERTEX_NUM+1];		//存放每个顶点对应的实际值 

/* 函数原型 */
void Algo_7_38(ALGraph G, int w);
void AssignSign_7_38(ALGraph G, FILE *fp);		//为每一顶点赋予实际意义 

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;										//作为输入源	
	int i;
		
	printf("创建并输出有向图...\n");
	fp = fopen("Data/Algo_7_38.txt", "r");	
	CreateGraph_AL(fp, &G); 
	AssignSign_7_38(G, fp);
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	Algo_7_38(G, 1);
	printf("此表达式的逆波兰式为：");
	for(i=1; i<=ReversePolish[0]; i++)
		printf("%c ", c[ReversePolish[i]]);
	printf("\n\n");	
		
	return 0;
}

/*━━━━━━━━━━━━━━━┓
┃题7.38：表达式的有向图存储结构┃
┗━━━━━━━━━━━━━━━*/
//表达式结构仿造自教材 
void Algo_7_38(ALGraph G, int w)					//有向图G的顶点序列从源点开始先序编号 
{	
	ArcNode *r;
	
	for(r=G.vertices[w].firstarc; r; r=r->nextarc)
		Algo_7_38(G, r->adjvex);

	if(!r)
	{
		ReversePolish[0]++;
		ReversePolish[ReversePolish[0]] = w;						//按后序序列存储	
	}
}

void AssignSign_7_38(ALGraph G, FILE *fp)
{
	char tmp;
	int k;
	
	Scanf(fp, "%c", &tmp);				//跳过换行符	
	for(k=1; k<=G.vexnum; k++) 
		Scanf(fp, "%c", &c[k]);
}
