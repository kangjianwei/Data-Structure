/*===================
 * 无向网的最小生成森林
 ===================*/

#ifndef MINIMUMSPANNINGTREE_H
#define MINIMUMSPANNINGTREE_H

#include <stdio.h>
#include <limits.h>   /* 提供INT_MAX宏 */
#include "MFSet.h"    //**▲06 树和二叉树**//
#include "ALGraph.h"  //**▲07 图**//
#include "CSTree.h"   //**▲06 树和二叉树**//

/*
 * 使用普里姆算法构造无向网G的最小生成森林
 */
CSTree MinSpanTree_PRIM(ALGraph G);

/*
 * 从顶点子集V-U中选出下一个候选顶点以便后续加入到最小生成树
 *
 * 选择顶点子集U到顶点子集V-U的权值最小的边，
 * 并返回该边在顶点子集V-U中那头的端点，
 * 该端点后续会加入到顶点子集U中，成为最小生成树的新结点。
 *
 * 注：形参与教材中给出的模板有所不同
 */
static int minimum(ALGraph G);

#endif
