/************************************
 *					                *
 * 文件夹: ▲07 图\02 ALGraph       *
 * 					                *
 * 文件名: ALGraph.h                *
 *    	    		                *
 * 内  容: 图（邻接表）相关操作列表 *
 *                                  *
 ************************************/

#ifndef ALGRAPH_H
#define ALGRAPH_H

#include <stdio.h>
#include <stdlib.h> 										//提供malloc、realloc、free、exit、rand、srand原型 
#include <stdarg.h>											//提供宏va_list、va_start、va_arg、va_end
#include "../../▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"							//**▲01 绪论**//
#include "../../▲03 栈和队列/07 LinkQueue/LinkQueue.c" 	//**▲03 栈和队列**//

/* 宏定义 */
#define MAX_VERTEX_NUM 20						//最大顶点个数 

/* 图的类型定义 */
typedef enum{ DG, UDG }GraphKind;				//0-有向图，1-无向图
typedef struct
{
	int in;
}InfoType;

/* 表结点 */
typedef struct ArcNode
{
	int adjvex;							//顶点序号 
	struct ArcNode *nextarc;			//指向下一条弧的指针 
	InfoType info;						//该弧相关信息
}ArcNode;

/* 头结点 */
typedef char VertexType_AL;				//图顶点类型 
typedef struct VNode
{
	VertexType_AL data;					//顶点信息
	ArcNode *firstarc;
}VNode;
typedef VNode AdjList[MAX_VERTEX_NUM+1];

/* 图（邻接表）的存储表示 */
typedef struct
{
	AdjList vertices;					//邻接表
	int vexnum,	arcnum;					//图的当前顶点数和弧数
	int IncInfo;						//IncInfo为0则各弧不含其它信息 
	GraphKind kind;						//图的种类标志 
}ALGraph;

/* 全局变量 */
Status visited[MAX_VERTEX_NUM+1];		//标志数组
void (*VisitFunc)(VertexType_AL e);		//函数指针变量 

/* 图（邻接表）函数列表 */
Status CreateGraph_AL(FILE *fp, ALGraph *G);
/*━━━━━━┓ 
┃(01)创建图。┃
┗━━━━━━*/

Status CreateDG_AL(FILE *fp, ALGraph *G);
/*━━━━━━━━┓
┃(02)构造有向图。┃
┗━━━━━━━━*/

Status CreateUDG_AL(FILE *fp, ALGraph *G);
/*━━━━━━━━┓
┃(03)构造无向图。┃
┗━━━━━━━━*/

void ClearGraph_AL(ALGraph *G);
/*━━━━━━┓
┃(04)清空图。┃
┗━━━━━━*/

int LocateVex_AL(ALGraph G, VertexType_AL u);
/*━━━━━━━━━━━┓
┃(05)寻找顶点u的位置。 ┃
┗━━━━━━━━━━━*/

VertexType_AL GetVex_M(ALGraph G, int order);
/*━━━━━━━━━━━━┓
┃(06)返回第v个结点的值。 ┃
┗━━━━━━━━━━━━*/

Status PutVex_AL(ALGraph *G, VertexType_AL v, VertexType_AL value);
/*━━━━━━━━━━━┓
┃(07)对顶点v赋值value。┃
┗━━━━━━━━━━━*/

int FirstAdjVex_AL(ALGraph G, VertexType_AL v);
/*━━━━━━━━━━━━━━━━┓
┃(08)返回v的第一个邻接顶点序号。 ┃
┗━━━━━━━━━━━━━━━━*/

int NextAdjVex_AL(ALGraph G, VertexType_AL v, VertexType_AL w);
/*━━━━━━━━━━━━━━━━━━━┓
┃(09)返回v相对于w的下一个邻接顶点序号。┃
┗━━━━━━━━━━━━━━━━━━━*/

Status InsertVex_AL(ALGraph *G, VertexType_AL v);
/*━━━━━━━━━━┓
┃(10)插入顶点v到图。 ┃
┗━━━━━━━━━━*/

Status DeleteVex_AL(ALGraph *G, VertexType_AL v);
/*━━━━━━━━━━━┓
┃(11)从图中删除顶点v。 ┃
┗━━━━━━━━━━━*/

Status InsertArc_AL(ALGraph *G, VertexType_AL v, VertexType_AL w, ...);
/*━━━━━━━━━━━┓
┃(12)插入弧<v,w>到图。 ┃
┗━━━━━━━━━━━*/

Status DeleteArc_AL(ALGraph *G, VertexType_AL v, VertexType_AL w);
/*━━━━━━━━━┓
┃(13)删除弧<v,w>。 ┃
┗━━━━━━━━━*/

void DFSTraverse_AL(ALGraph G, void (Visit)(VertexType_AL));
/*━━━━━━━━━┓
┃(14)深度优先遍历。┃
┗━━━━━━━━━*/

void DFS_AL(ALGraph G, int v);
/*━━━━━━━━━━━━━┓
┃(15)深度优先遍历核心函数。┃
┗━━━━━━━━━━━━━*/

void BFSTraverse_AL(ALGraph G, void (Visit)(VertexType_AL));
/*━━━━━━━━━┓
┃(16)广度优先遍历。┃
┗━━━━━━━━━*/

void OutputALGraph(ALGraph G);
/*━━━━━━┓
┃(17)输出图。┃
┗━━━━━━*/

void Input(FILE *fp, InfoType *info);
/*━━━━━━━━━━━┓
┃(18)录入弧的相关信息。┃
┗━━━━━━━━━━━*/

#endif
