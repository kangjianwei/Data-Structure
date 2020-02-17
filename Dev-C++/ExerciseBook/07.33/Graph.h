/*=================================
 * 由题7.33的描述创建的一种无向网结构
 ==================================*/

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <limits.h>     // 提供宏INT_MAX
#include <stdlib.h>     // 提供 malloc、free 原型
#include <string.h>     // 提供 memset、strcmp 原型
#include "Status.h"     //**▲01 绪论**//

#define INFINITE INT_MAX    // 最大值，用来表示网中的两个顶点不直接连接
#define MAX_VERTEX_NUM 26   // 顶点个数最大值

// 顶点类型
typedef char VertexType;

// 边集类型
typedef struct {
    int u, v;    // 顶点
    int weight;  // 权值
} EdgeSetType;

// 有向图类型定义
typedef struct Graph {
    VertexType vexs[MAX_VERTEX_NUM];  // 顶点向量
    EdgeSetType* EdgeSet;             // 边集
    int vexnum, arcnum;               // 有向图的顶点数和弧数
} Graph;


/*
 * 创建有向图
 *
 * path为NULL或为""时，从控制台读取图的初始化信息。
 * 否则，从预设的文件中读取图的初始化信息。
 */
Status CreateGraph(Graph* G, char* path);

/*
 * 创建有向图的核心算法
 */
static void Create(Graph* G);

/*
 * 查找
 *
 * 返回顶点u在有向图中的位置
 */
int LocateVex(Graph G, VertexType u);

/*
 * 从边集EdgeSet中获取最小边的顶点u和v，并返回TRUE。
 * 若边集为空，则返回FASLE。
 */
Boolean GetMinEdge(EdgeSetType* EdgeSet, int* u, int* v);

/*
 * 从边集中删除依附于顶点u和v的最小边。
 * 删除成功返回TRUE，否则，返回FALSE。
 */
Boolean DelMinEdge(EdgeSetType* EdgeSet, int u, int v);

/*
 * 打印有向图结构
 */
void PrintGraph(Graph G);

#endif
