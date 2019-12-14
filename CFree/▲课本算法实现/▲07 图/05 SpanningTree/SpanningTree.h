/************************************
 *                                  *
 * 文件夹: ▲07 图\05 SpanningTree  *
 *                                  *
 * 文件名: SpanningTree.h           *
 *                                  *
 * 内  容: 无向图生成树相关操作列表 *
 *                                  *
 ************************************/
 
#ifndef SPANNINGTREE_H
#define SPANNINGTREE_H

#include <stdlib.h>											//提供malloc、realloc、free、exit原型
#include "../01 MGraph/MGraph.c"										//**▲07 图**//
#include "../../▲06 树和二叉树/07 ChildSiblingTree/ChildSiblingTree.c"	//**▲06 树和二叉树**//

/* 无向图生成树函数列表 */
void DFSForest(MGraph G, CSTree *T);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法7.7：创建无向图的生成树（森林） ┃
┗━━━━━━━━━━━━━━━━━━━━*/

void DFSTree(MGraph G, int v, CSTree *T);
/*━━━━━━━━━━━━━━━━━━━┓
┃(02)算法7.8：生成结点v起始的树（森林）┃
┗━━━━━━━━━━━━━━━━━━━*/

#endif
