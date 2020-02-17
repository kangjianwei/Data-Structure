/*==================
 * 无向网的最小生成树
 *
 * 包含算法: 7.9
 ==================*/

#ifndef MINIMUMSPANNINGTREE_H
#define MINIMUMSPANNINGTREE_H

#include <stdio.h>
#include <limits.h>  // 提供INT_MAX宏
#include "SqQueue.h" //**▲03 栈和队列**//
#include "MFSet.h"   //**▲06 树和二叉树**//
#include "CSTree.h"  //**▲06 树和二叉树**//
#include "Graph.h"

/*
 * 使用克鲁斯卡尔算法求取最小生成树
 */
CSTree MinSpanTree_KRUSKAL(Graph G);

#endif
