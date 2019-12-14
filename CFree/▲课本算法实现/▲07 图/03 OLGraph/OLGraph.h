/******************************************
 *                                        *
 * 文件夹: ▲07 图\03 OLGraph             *
 *                                        *
 * 文件名: OLGraph.h                      *
 *                                        *
 * 内  容: 有向图（十字链表）相关操作列表 *
 *                                        *
 ******************************************/

#ifndef OLGRAPH_H
#define OLGRAPH_H

#include <stdio.h>
#include <stdlib.h> 										//提供malloc、realloc、free、exit原型
#include <stdarg.h>											//提供宏va_list、va_start、va_arg、va_end
#include "../../▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"							//**▲01 绪论**//
#include "../../▲03 栈和队列/07 LinkQueue/LinkQueue.c" 	//**▲03 栈和队列**//

/* 宏定义 */
#define MAX_VERTEX_NUM 20						//最大顶点个数 

/* 有向图（十字链表）类型定义 */
typedef struct									//弧相关信息
{
	//本文档不设弧信息 
}InfoType;
typedef struct ArcBox							//弧结点
{
	int tailvex, headvex;						//该弧的尾和头顶点的位置
	struct ArcBox *hlink, *tLink;				//分别为弧头相同和弧尾相同的弧的链域 
	InfoType info;								//该弧相关信息
}ArcBox;
typedef char VertexType_OL;						//有向图顶点类型
typedef struct VexNode
{
	VertexType_OL data;
	ArcBox *firstin, *firstout;					//分别指向该顶点第一条入弧和出弧 
}VexNode;
typedef struct									//有向图（十字链表）存储结构 
{
	VexNode xlist[MAX_VERTEX_NUM+1];			//表头向量
	int vexnum, arcnum;							//有向图当前顶点数和弧数 
	int IncInfo;								//IncInfo为0则各弧不含其它信息  
}OLGraph;

/* 全局变量 */
Status visited[MAX_VERTEX_NUM+1];		//标志数组
void (*VisitFunc)(VertexType_OL e);		//函数指针变量 

/* 有向图（十字链表）函数列表 */
Status CreateDG_OL(FILE *fp, OLGraph *G);
/*━━━━━━━━━━━━━┓
┃(01)算法7.3：构造有向图。 ┃
┗━━━━━━━━━━━━━*/

void ClearGraph_OL(OLGraph *G);
/*━━━━━━┓
┃(02)清空图。┃
┗━━━━━━*/

int LocateVex_OL(OLGraph G, VertexType_OL u);
/*━━━━━━━━━━━┓
┃(03)寻找顶点u的位置。 ┃
┗━━━━━━━━━━━*/

VertexType_OL GetVex_M(OLGraph G, int order);
/*━━━━━━━━━━━━┓
┃(04)返回第v个结点的值。 ┃
┗━━━━━━━━━━━━*/

Status PutVex_OL(OLGraph *G, VertexType_OL v, VertexType_OL value);
/*━━━━━━━━━━━┓
┃(05)对顶点v赋值value。┃
┗━━━━━━━━━━━*/

int FirstAdjVex_OL(OLGraph G, VertexType_OL v);
/*━━━━━━━━━━━━━━━━┓
┃(06)返回v的第一个邻接顶点序号。 ┃
┗━━━━━━━━━━━━━━━━*/

int NextAdjVex_OL(OLGraph G, VertexType_OL v, VertexType_OL w);
/*━━━━━━━━━━━━━━━━━━━┓
┃(07)返回v相对于w的下一个邻接顶点序号。┃
┗━━━━━━━━━━━━━━━━━━━*/

Status InsertVex_OL(OLGraph *G, VertexType_OL v);
/*━━━━━━━━━━┓
┃(08)插入顶点v到图。 ┃
┗━━━━━━━━━━*/

Status DeleteVex_OL(OLGraph *G, VertexType_OL v);
/*━━━━━━━━━━━┓
┃(09)从图中删除顶点v。 ┃
┗━━━━━━━━━━━*/

Status InsertArc_OL(OLGraph *G, VertexType_OL v, VertexType_OL w, ...);
/*━━━━━━━━━━━┓
┃(10)插入弧<v,w>到图。 ┃
┗━━━━━━━━━━━*/

Status DeleteArc_OL(OLGraph *G, VertexType_OL v, VertexType_OL w);
/*━━━━━━━━━┓
┃(11)删除弧<v,w>。 ┃
┗━━━━━━━━━*/

void DFSTraverse_OL(OLGraph G, void (Visit)(VertexType_OL));
/*━━━━━━━━━┓
┃(12)深度优先遍历。┃
┗━━━━━━━━━*/

void DFS_OL(OLGraph G, int v);
/*━━━━━━━━━━━━━┓
┃(13)深度优先遍历核心函数。┃
┗━━━━━━━━━━━━━*/

void BFSTraverse_OL(OLGraph G, void (Visit)(VertexType_OL));
/*━━━━━━━━━┓
┃(14)广度优先遍历。┃
┗━━━━━━━━━*/

void OutputOLGraph(OLGraph G);
/*━━━━━━┓
┃(15)输出图。┃
┗━━━━━━*/

void Input(FILE *fp, InfoType *info);
/*━━━━━━━━━━━┓
┃(16)录入弧的相关信息。┃
┗━━━━━━━━━━━*/

#endif
