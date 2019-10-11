/**************************************
 *					                  *
 * 文件夹: ▲07 图\10 CriticalPath    *
 * 					                  *
 * 文件名: CriticalPath.h             *
 *                                    *
 * 内  容: AOE-网关键路径相关操作列表 *
 *                                    *
 **************************************/

#ifndef CRITICALPATH_H
#define CRITICALPATH_H

#include <stdio.h>
#include "../../▲01 绪论/Status.h"								//**▲01 绪论**//
#include "../../▲03 栈和队列/01 SequenceStack/SequenceStack.c"	//**▲03 栈和队列**//
#include "../02 ALGraph/ALGraph.c" 								//**▲07 图**//

/* 全局变量 */
SqStack T;														//拓扑序列顶点栈 
int ve[MAX_VERTEX_NUM+1];										//各事件（顶点）的最早发生时间 
int vl[MAX_VERTEX_NUM+1];										//各事件（顶点）的最迟发生时间
	
/* AOE-网关键路径函数列表 */
Status TopologicalOrder(ALGraph G, SqStack *T);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法7.13：求有向网拓扑排序，并求各事件最早发生时间。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status CriticalPath(ALGraph G);
/*━━━━━━━━━━━━━━━━┓
┃(02)算法7.14：求有向网关键活动。┃
┗━━━━━━━━━━━━━━━━*/

void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM+1]);
/*━━━━━━━━━━━━━┓
┃(03)对有向图各顶点求入度。┃
┗━━━━━━━━━━━━━*/

#endif
