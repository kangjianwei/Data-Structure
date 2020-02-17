/*=======================
 * AOE-网(有向网)的关键路径
 *
 * 包含算法: 7.13、7.14
 ========================*/

#ifndef CRITICALPATHMETHOD_H
#define CRITICALPATHMETHOD_H

#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SqStack.h"    //**▲03 栈和队列**//
#include "ALGraph.h"    //**▲07 图**//

/*
 * ████████ 算法7.14 ████████
 *
 * 计算有向网G的关键路径
 *
 * 注：有向网顶点序列中最后一个顶点必须为事件终点
 */
Status CriticalPath(ALGraph G);

/*
 * ████████ 算法7.13 ████████
 *
 * 如果有向网G无回路，则寻找它的一个拓扑序列存储到拓扑序列栈T中，并返回OK；否则，返回FALSE。
 * 拓扑序列通常不唯一，但是必须保证某些关键节点的先后次序。
 */
static Status TopologicalOrder(ALGraph G, SqStack* T);

/*
 * 计算各顶点的入度
 */
static void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM]);

#endif
