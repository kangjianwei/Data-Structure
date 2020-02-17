/*=======================
 * AOV-网(有向图)的拓扑排序
 *
 * 包含算法: 7.12
 ========================*/

#ifndef TOPOLOGICALSORTING_H
#define TOPOLOGICALSORTING_H

#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SqStack.h"    //**▲03 栈和队列**//
#include "ALGraph.h"    //**▲07 图**//

/*
 * ████████ 算法7.12 ████████
 *
 * 如果有向图G无回路，则输出它的一个拓扑序列并返回OK；否则，返回FALSE。
 * 拓扑序列通常不唯一，但是必须保证某些关键节点的先后次序。
 */
Status TopologicalSort(ALGraph G, int topo[MAX_VERTEX_NUM]);

/*
 * 计算各顶点的入度
 */
static void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM]);

#endif
