/*====================
 * 最短路径算法
 *
 * 包含算法: 7.15、7.16
 =====================*/

#ifndef SHORTESTPATHS_H
#define SHORTESTPATHS_H

#include <stdio.h>
#include <limits.h>
#include "Status.h"    //**▲01 绪论**//
#include "ALGraph.h"   //**▲07 图**//

// 权值的最大值，用在网中，表示两顶点不直接连通
#define INFINITE INT_MAX


// Dijkstra算法中的最短路径矩阵，是一个二维数组
typedef Boolean PathMatrix_DIJ[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
// Dijkstra算法中的最短路径代价，该代价可能是步长和，也可能是权值和
typedef int ShortPathTable_DIJ[MAX_VERTEX_NUM];


/*
 * 应当在执行迪杰斯特拉算法之前被调用，用来计算各顶点之间的关系。
 */
void GetAdjs(ALGraph G);

/*
 * ████████ 算法7.15 ████████
 *
 * 迪杰斯特拉(Dijkstra)算法求单源最短路径
 *
 * @param G  待遍历的图。
 * @param v0 单源最短路径的起点。
 * @param P  存储从v0到其余各顶点的最短路径信息。
 *           P[j][k]==TRUE代表从v0->j的最短路径会经过顶点k；否则，代表不经过。
 *           注：该数组只反映了顶点的存在性，而未反映顶点在路径上的次序。
 * @param D  存储从v0到其余各顶点的最短路径代价，在图中，该代价是步长和，在网中，该代价是权值和。
 */
void ShortestPath_DIJ(ALGraph G, int v0, PathMatrix_DIJ P, ShortPathTable_DIJ D);

/*
 * 打印使用迪杰斯特拉(Dijkstra)算法求取的单源最短路径
 */
void PrintPath_DIJ(ALGraph G, int v0, PathMatrix_DIJ P, ShortPathTable_DIJ D);

/*
 * 打印从a到b的路径，该路径的顶点信息位于P中
 */
static void PrintPath(ALGraph G, int a, int b, Boolean P[MAX_VERTEX_NUM]) ;

/*
 * 利用广度预先搜索找到一条从pre到b的路径，该路径上路过的所有顶点位于vexs中，找出的路径存储到path中
 */
static Status Find(ALGraph G, int pre, int b, int vexs[MAX_VERTEX_NUM], int path[MAX_VERTEX_NUM]);

#endif
