#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../../▲课本算法实现/▲07 图/02 ALGraph/ALGraph.c"					//**▲07 图**//

/* 宏定义 */
int ReversePolish[MAX_VERTEX_NUM+1];	//0号单元用作计数，存放逆波兰序列 

/* 类型定义 */
struct
{
	int sign;							//0标记字符，1标记数字
	union
	{
		char c;							//存放每个顶点对应的实际值 
		int i;
	}data;
}Elem[MAX_VERTEX_NUM+1];

/* 函数原型 */
int Calculate_7_40(ALGraph G, int w); 
void AssignSign_7_40(ALGraph G, FILE *fp);	//为每一顶点赋予实际意义 
void Algo_7_40(ALGraph G, int w);			//有向图G的顶点序列从源点开始先序编号

int main(int argc, char *argv[])
{
	ALGraph G;
	FILE *fp;										//作为输入源	
	int i;
		
	printf("创建并输出有向图...\n");
	fp = fopen("Data/Algo_7_40.txt", "r");	
	CreateGraph_AL(fp, &G); 
	AssignSign_7_40(G, fp);
	fclose(fp);
	OutputALGraph(G);
	printf("\n");
	
	Algo_7_40(G, 1);
	printf("此表达式的逆波兰式为：");
	for(i=1; i<=ReversePolish[0]; i++)
	{
		if(Elem[ReversePolish[i]].sign==0)
			printf("%c ", Elem[ReversePolish[i]].data.c);
		else
			printf("%d ", Elem[ReversePolish[i]].data.i);
	}
	printf("\n\n");	
	
	printf("此表达式的值为：");
	printf("%d\n", Calculate_7_40(G, 1));
	printf("\n");		
	
	return 0;
}

/*━━━━━━━━━┓
┃题7.40：计算表达式┃
┗━━━━━━━━━*/
int Calculate_7_40(ALGraph G, int w)		//从源点开始遍历 
{
	ArcNode *p, *q;
	int x, y;
	char oper;
		
	p = G.vertices[w].firstarc;				//p、q同时出现或同时为空 

	if(p)
	{
		q = p->nextarc;
		
		x = Calculate_7_40(G, p->adjvex);	//类似于二叉树的遍历 
		y = Calculate_7_40(G, q->adjvex);
		oper = Elem[w].data.c;
		
		if(oper=='+')
			return x + y;
		if(oper=='-')
			return x - y;
		if(oper=='*')
			return x * y;		
		if(oper=='/')
			return x / y;
	}
	else
		return Elem[w].data.i;	
}

void AssignSign_7_40(ALGraph G, FILE *fp)
{
	char tmp;
	int k;
	
	Scanf(fp, "%c", &tmp);				//跳过换行符	
	for(k=1; k<=G.vexnum; k++) 
		Scanf(fp, "%d", &Elem[k].sign);

	Scanf(fp, "%c", &tmp);				//跳过换行符
	for(k=1; k<=G.vexnum; k++)
	{
		if(Elem[k].sign==0)				//读字符 
			Scanf(fp, "%c", &Elem[k].data.c);
		else
			Scanf(fp, "%d", &Elem[k].data.i);	
	}
}

//表达式结构仿造自教材 
void Algo_7_40(ALGraph G, int w)			//有向图G的顶点序列从源点开始先序编号 
{	
	ArcNode *r;
	
	for(r=G.vertices[w].firstarc; r; r=r->nextarc)
		Algo_7_40(G, r->adjvex);

	if(!r)
	{
		ReversePolish[0]++;
		ReversePolish[ReversePolish[0]] = w;						//按后序序列存储	
	}
}
