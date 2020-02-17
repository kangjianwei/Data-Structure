/*==================
 * 无向图的生成树
 *
 * 包含算法: 7.7、7.8
 ===================*/

#ifndef SPANNINGTREE_H
#define SPANNINGTREE_H

#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "CSTree.h"     //**▲06 树和二叉树**//
#include "MGraph.h"     //**▲07 图**//

/*
 * ████████ 算法7.7 ████████
 *
 * 构造无向图的生成树(森林)
 */
void DFSForest(MGraph G, CSTree* T);

/*
 * ████████ 算法7.8 ████████
 *
 * 通过深度优先遍历各结点，构造结点v起始的树
 */
void DFSTree(MGraph G, int v, CSTree* T);

#endif
