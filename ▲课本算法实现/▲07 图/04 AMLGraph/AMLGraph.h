/********************************************
 *						                    *
 * 文件夹: ▲07 图\04 AMLGraph              *
 * 						                    *
 * 文件名: AMLGraph.h                       *
 *                                          *
 * 内  容: 无向图（邻接多重表）相关操作列表 *
 *                                          *
 ********************************************/

#ifndef AMLGRAPH_H
#define AMLGRAPH_H

#include <stdio.h>
#include <stdlib.h> 										//提供malloc、realloc、free、exit原型
#include <stdarg.h>											//提供宏va_list、va_start、va_arg、va_end
#include "../../▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"							//**▲01 绪论**//
#include "../../▲03 栈和队列/07 LinkQueue/LinkQueue.c" 	//**▲03 栈和队列**//

/* 宏定义 */
#define MAX_VERTEX_NUM 20						//最大顶点个数 
#define MAX_EDGE_NUM 190						//无向图最大弧数量 

/* 无向图（邻接多重表）类型定义 */
typedef enum{ unvisit, visit }VisitIf;
typedef struct
{
	//本文档不设弧信息
}InfoType;
typedef struct EBox								//表结点 
{
	VisitIf mark;								//访问标记 
	int ivex, jvex;								//该边依附的两个顶点的位置
	struct EBox *ilink, *jlink;					//分别指向依附这两个顶点的下一条边
	InfoType info;								//该弧相关信息
}EBox;
typedef char VertexType_AML;					//无向图顶点类型 
typedef struct VexBox
{
	VertexType_AML data;						//顶点信息 
	EBox *firstedge;
}VexBox;
typedef struct									//无向图（邻接多重表）存储结构
{
	VexBox adjmulist[MAX_VERTEX_NUM+1];			//表头向量
	int vexnum, edgenum;						//无向图当前顶点数和弧数 
	int IncInfo;								//IncInfo为0则各弧不含其它信息  
}AMLGraph;

/* 全局变量 */
Status visited[MAX_VERTEX_NUM+1];				//顶点标志数组
EBox *edgePtr[MAX_EDGE_NUM+1];					//弧指针数组
void (*VisitFunc)(VertexType_AML e);			//函数指针变量 

/* 无向图（邻接多重表）函数列表 */
Status CreateUDG_AML(FILE *fp, AMLGraph *G);
/*━━━━━━━━━━━━━┓
┃(01)算法7.3：构造无向图。 ┃
┗━━━━━━━━━━━━━*/

void ClearGraph_AML(AMLGraph *G);
/*━━━━━━┓
┃(02)清空图。┃
┗━━━━━━*/

int LocateVex_AML(AMLGraph G, VertexType_AML u);
/*━━━━━━━━━━━┓
┃(03)寻找顶点u的位置。 ┃
┗━━━━━━━━━━━*/

VertexType_AML GetVex_M(AMLGraph G, int order);
/*━━━━━━━━━━━━┓
┃(04)返回第v个结点的值。 ┃
┗━━━━━━━━━━━━*/

Status PutVex_AML(AMLGraph *G, VertexType_AML v, VertexType_AML value);
/*━━━━━━━━━━━┓
┃(05)对顶点v赋值value。┃
┗━━━━━━━━━━━*/

int FirstAdjVex_AML(AMLGraph G, VertexType_AML v);
/*━━━━━━━━━━━━━━━━┓
┃(06)返回v的第一个邻接顶点序号。 ┃
┗━━━━━━━━━━━━━━━━*/

int NextAdjVex_AML(AMLGraph G, VertexType_AML v, VertexType_AML w);
/*━━━━━━━━━━━━━━━━━━━┓
┃(07)返回v相对于w的下一个邻接顶点序号。┃
┗━━━━━━━━━━━━━━━━━━━*/

Status InsertVex_AML(AMLGraph *G, VertexType_AML v);
/*━━━━━━━━━━┓
┃(08)插入顶点v到图。 ┃
┗━━━━━━━━━━*/

Status DeleteVex_AML(AMLGraph *G, VertexType_AML v);
/*━━━━━━━━━━━┓
┃(09)从图中删除顶点v。 ┃
┗━━━━━━━━━━━*/

Status InsertArc_AML(AMLGraph *G, VertexType_AML v, VertexType_AML w, ...);
/*━━━━━━━━━━━┓
┃(10)插入弧<v,w>到图。 ┃
┗━━━━━━━━━━━*/

Status DeleteArc_AML(AMLGraph *G, VertexType_AML v, VertexType_AML w);
/*━━━━━━━━━┓
┃(11)删除弧<v,w> 。┃
┗━━━━━━━━━*/

void DFSTraverse_AML(AMLGraph G, void(Visit)(VertexType_AML));
/*━━━━━━━━━┓
┃(12)深度优先遍历。┃
┗━━━━━━━━━*/

void DFS_AML(AMLGraph G, int v);
/*━━━━━━━━━━━━━┓
┃(13)深度优先遍历核心函数。┃
┗━━━━━━━━━━━━━*/

void BFSTraverse_AML(AMLGraph G, void(Visit)(VertexType_AML));
/*━━━━━━━━━┓
┃(14)广度优先遍历。┃
┗━━━━━━━━━*/

void OutputAMLGraph(AMLGraph G);
/*━━━━━━┓
┃(15)输出图。┃
┗━━━━━━*/

void ClearMark(AMLGraph G);
/*━━━━━━━┓
┃(16)清空标志。┃
┗━━━━━━━*/

void Input(FILE *fp, InfoType *info);
/*━━━━━━━━━━━┓
┃(17)录入弧的相关信息。┃
┗━━━━━━━━━━━*/

#endif
