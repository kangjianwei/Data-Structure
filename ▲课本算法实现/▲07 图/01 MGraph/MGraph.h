/******************************************************
 *                                                    *
 * 文件夹: ▲07 图\01 MGraph                          *
 *                                                    *
 * 文件名: MGraph.h                                   *
 *                                                    *
 * 内  容: 图、表的数组（邻接矩阵）表示法相关操作列表 *
 *                                                    *
 ******************************************************/

#ifndef MGRAPH_H
#define MGRAPH_H

#include <stdio.h>
#include <limits.h>											//提供宏INT_MAX
#include <stdlib.h> 										//提供rand、srand原型 
#include <stdarg.h>											//提供宏va_list、va_start、va_arg、va_end
#include "../../▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"							//**▲01 绪论**//
#include "../../▲03 栈和队列/07 LinkQueue/LinkQueue.c" 	//**▲03 栈和队列**//

/* 宏定义 */
#define INFINITY INT_MAX						//最大值∞
#define MAX_VERTEX_NUM 20						//最大顶点个数 

/* 图、表的数组（邻接矩阵）表示法类型定义 */
typedef enum{ DG, DN, UDG, UDN }GraphKind;		//0-有向图，1-有向网（带权值），2-无向图，3-无向网（带权值）
typedef struct{ }InfoType;						//弧相关信息
typedef int VRType;								//图、表顶点关系类型 
typedef struct ArcCell
{
	VRType adj;									//带权图中表示权值，无权图中用0、1表示是否相邻
	InfoType info;								//该弧相关信息，可以忽略 
}ArcCell;
typedef ArcCell AdjMatrix[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1]; //邻接矩阵 

/* 图、表（数组表示法）的存储表示 */
typedef char VertexType_M;				//图、表顶点类型 
typedef struct
{
	VertexType_M vexs[MAX_VERTEX_NUM+1];//顶点向量
	AdjMatrix arcs;						//邻接矩阵
	int vexnum,	arcnum;					//图、表的当前顶点数和弧数
	int IncInfo;						//IncInfo为0则各弧不含其它信息 
	GraphKind kind;						//图、表的种类标志 
}MGraph;

/* 全局变量 */
Status visited[MAX_VERTEX_NUM+1];		//标志数组
void (*VisitFunc)(VertexType_M e);		//函数指针变量 

/* 图、表（数组表示法）函数列表 */
Status CreateGraph_M(FILE *fp, MGraph *G);
/*━━━━━━━━━━━━━┓
┃(01)算法7.1：创建图、表。 ┃
┗━━━━━━━━━━━━━*/

Status CreateDG_M(FILE *fp, MGraph *G);
/*━━━━━━━━┓
┃(02)构造有向图。┃
┗━━━━━━━━*/

Status CreateDN_M(FILE *fp, MGraph *G);
/*━━━━━━━━┓
┃(03)构造有向网。┃
┗━━━━━━━━*/ 

Status CreateUDG_M(FILE *fp, MGraph *G);
/*━━━━━━━━┓
┃(04)构造无向图。┃
┗━━━━━━━━*/

Status CreateUDN_M(FILE *fp, MGraph *G);
/*━━━━━━━━━━━━━┓
┃(05)算法7.2：构造无向网。 ┃
┗━━━━━━━━━━━━━*/

void ClearGraph_M(MGraph *G);
/*━━━━━━━━━┓
┃(06)清空图（网）。┃
┗━━━━━━━━━*/

int LocateVex_M(MGraph G, VertexType_M u);
/*━━━━━━━━━━━┓
┃(07)寻找顶点u的位置。 ┃
┗━━━━━━━━━━━*/

VertexType_M GetVex_M(MGraph G, int order);
/*━━━━━━━━━━━━┓
┃(08)返回第v个结点的值。 ┃
┗━━━━━━━━━━━━*/

Status PutVex_M(MGraph *G, VertexType_M v, VertexType_M value);
/*━━━━━━━━━━━┓
┃(09)对顶点v赋值value。┃
┗━━━━━━━━━━━*/

int FirstAdjVex_M(MGraph G, VertexType_M v);
/*━━━━━━━━━━━━━━━━┓
┃(10)返回v的第一个邻接顶点序号。 ┃
┗━━━━━━━━━━━━━━━━*/

int NextAdjVex_M(MGraph G, VertexType_M v, VertexType_M w);
/*━━━━━━━━━━━━━━━━━━━┓
┃(11)返回v相对于w的下一个邻接顶点序号。┃
┗━━━━━━━━━━━━━━━━━━━*/

Status InsertVex_M(MGraph *G, VertexType_M v);
/*━━━━━━━━━━┓
┃(12)插入顶点v到图。 ┃
┗━━━━━━━━━━*/

Status DeleteVex_M(MGraph *G, VertexType_M v);
/*━━━━━━━━━━━┓
┃(13)从图中删除顶点v。 ┃
┗━━━━━━━━━━━*/

Status InsertArc_M(MGraph *G, VertexType_M v, VertexType_M w, VRType adj, ...);
/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃(14)插入弧<v,w>到图,弧的相关信息InfoType可选。┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/

Status DeleteArc_M(MGraph *G, VertexType_M v, VertexType_M w);
/*━━━━━━━━━┓
┃(15)删除弧<v,w>。 ┃
┗━━━━━━━━━*/

void DFSTraverse_M(MGraph G, void(Visit)(VertexType_M));
/*━━━━━━━━━━━━━━┓
┃(16)算法7.4：深度优先遍历。 ┃
┗━━━━━━━━━━━━━━*/

void DFS_M(MGraph G, int v);
/*━━━━━━━━━━━━━━━━━━┓
┃(17)算法7.5：深度优先遍历核心函数。 ┃
┗━━━━━━━━━━━━━━━━━━*/

void BFSTraverse_M(MGraph G, void(Visit)(VertexType_M));
/*━━━━━━━━━━━━━━┓
┃(18)算法7.6：广度优先遍历。 ┃
┗━━━━━━━━━━━━━━*/

void OutputMGraph(MGraph G);
/*━━━━━━━━━┓
┃(19)输出图（表）。┃
┗━━━━━━━━━*/

void Input(FILE *fp, InfoType *info);
/*━━━━━━━━━━━┓
┃(20)录入弧的相关信息。┃
┗━━━━━━━━━━━*/

#endif
