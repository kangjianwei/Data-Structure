/*==================
 * 无向网的最小生成树
 *
 * 包含算法: 7.9
 ==================*/

#ifndef MINIMUMSPANNINGTREE_H
#define MINIMUMSPANNINGTREE_H

#include <stdio.h>
#include <limits.h>     // 提供INT_MAX宏
#include "MFSet.h"      //**▲06 树和二叉树**//
#include "MGraph.h"     //**▲07 图**//

/*
 * ████████ 算法7.9 ████████
 *
 * 普里姆算法
 *
 * 从第u个顶点出发构造无向网G的最小生成树T，输出T的各条边。
 * 该算法的耗时部分是对顶点的遍历，与网中的边数无关，因为适用于边比较稠密的网
 *
 * 注：假设图的权值均大于0
 */
void MinSpanTree_PRIM(MGraph G, VertexType u);

/*
 * 从顶点子集V-U中选出下一个候选顶点以便后续加入到最小生成树
 *
 * 选择顶点子集U到顶点子集V-U的权值最小的边，
 * 并返回该边在顶点子集V-U中那头的端点，
 * 该端点后续会加入到顶点子集U中，成为最小生成树的新结点。
 *
 * 注：形参与教材中给出的模板有所不同
 */
static int minimum(MGraph G);

/*
 * 克鲁斯卡尔算法
 *
 * 从第u个顶点出发构造无向网G的最小生成树T，输出T的各条边
 * 该算法的耗时部分是对边的遍历，与网中的顶点无关，因为适用于边比较稀疏的网
 *
 * 可以改进之处：对已有边排序时可以采用第9章介绍的堆排序
 */
void MinSpanTree_KRUSKAL(MGraph G);

#endif
