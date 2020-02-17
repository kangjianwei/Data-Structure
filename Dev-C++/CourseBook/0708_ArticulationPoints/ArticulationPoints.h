/*====================
 * 无向图的关节点
 *
 * 包含算法: 7.10、7.11
 =====================*/

#ifndef ARTICULATIONPOINTS_H
#define ARTICULATIONPOINTS_H

#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "ALGraph.h"    //**▲07 图**//

/*
 * ████████ 算法7.10 ████████
 *
 * 查找并输出G上全部关节点
 */
void FindArticul(ALGraph G);

/*
 * ████████ 算法7.11 ████████
 *
 * 从第v0个顶点出发深度优先遍历图G，查找并输出所有关节点
 */
void DFSArticul(ALGraph G, int v0);

#endif
