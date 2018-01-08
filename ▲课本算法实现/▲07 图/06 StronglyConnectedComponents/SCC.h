/**************************************************
 *                                                *
 * 文件夹: ▲07 图\06 StronglyConnectedComponents *
 *                                                *
 * 文件名: SCC.h                                  *
 *                                                *
 * 内  容: 强连通分量相关操作列表                 *
 *                                                *
 **************************************************/

#ifndef SCC_H
#define SCC_H

#include <stdio.h>
#include "../03 OLGraph/OLGraph.c"			//**▲07 图**//

/* 全局变量 */
int count;
int finished[MAX_VERTEX_NUM+1];
 
/* 强连通分量函数列表 */
void InverseGraph(OLGraph *G);
/*━━━━━━━━━━━━━━━━━━┓
┃(01)逆置有向图（十字链表存储结构）。┃
┗━━━━━━━━━━━━━━━━━━*/

void DFSTraverse_SCC(OLGraph G);
/*━━━━━━━━━━━━━━┓
┃(02)深度优先遍历（有改动）。┃
┗━━━━━━━━━━━━━━*/

void DFS_SCC_1(OLGraph G, int v);
/*━━━━━━━━━━━━━━━━━━┓
┃(03)深度优先遍历核心函数（有改动）。┃
┗━━━━━━━━━━━━━━━━━━*/

void DFS_SCC_2(OLGraph G, int v);
/*━━━━━━━━━━━━━━━━━━┓
┃(04)深度优先遍历核心函数（有改动）。┃
┗━━━━━━━━━━━━━━━━━━*/

void Kosaraju(OLGraph G);
/*━━━━━━━━━━━━━━━━━━━┓
┃(05)求有向图强连通分量的Kosaraju算法。┃
┗━━━━━━━━━━━━━━━━━━━*/

#endif 
