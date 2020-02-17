/*==================
 * 有向图的强连通分量
 ===================*/

#ifndef STRONGLYCONNECTEDCOMPONENTS_H
#define STRONGLYCONNECTEDCOMPONENTS_H

#include <stdio.h>
#include "OLGraph.h"    //**▲07 图**//

/*
 * (1) Tarjan算法
 *
 * 求取有向图的强连通分量
 */
void Tarjan(OLGraph G);

/*
 * 深度优先遍历顶点v可达的所有元素，并尝试找出其中的强连通分量
 */
static void DFS_Tarjan(OLGraph G, int v);


/*
 * (2) Kosaraju算法
 *
 * 求取有向图的强连通分量，这是教材中提到的算法
 *
 * 核心思想是：
 * 1.从某顶点出发，深度遍历有向图，得到一个访问序列；
 * 2.逆置有向图；
 * 3.遍历上面得出的访问序列，对其中的每个顶点进行深度优先遍历。
 */
void Kosaraju(OLGraph G);

/*
 * 逆置有向图（十字链表存储结构），即将所有弧的方向逆置
 *
 * 核心思想是：
 * 1.创建一个不包含任何弧的空图；
 * 2.依次遍历每个顶点的每条入弧；
 * 3.摘下遇到的入弧，将其插入到空图中变成出弧。
 */
static void InverseGraph(OLGraph *G);

/*
 * 存储深度优先遍历中访问到的元素
 */
static Status StoreElem(VertexType c);

/*
 * 深度遍历已经逆置后的图，仅限内部使用
 */
static void DFS_Inverse(OLGraph G, int v);

#endif
