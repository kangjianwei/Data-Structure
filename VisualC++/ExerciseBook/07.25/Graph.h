/*=================================
 * 由题7.25的描述创建的一种有向图结构
 ==================================*/

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <string.h>     // 提供memset、strcmp 原型
#include "Status.h"     //**▲01 绪论**//

#define MAX_VERTEX_NUM 26   // 顶点个数最大值
#define MAX_ADJ_NUM    650  // 所有顶点的邻接点数量和最大值

// 顶点类型
typedef char VertexType;

// 有向图类型定义
typedef struct Graph {
    VertexType vexs[MAX_VERTEX_NUM];  // 顶点向量
    int s[MAX_ADJ_NUM];               // 各顶点的邻接点
    int fst[MAX_VERTEX_NUM];          // fst[v] -> 顶点v的邻接点在s中的起始下标
    int lst[MAX_VERTEX_NUM];          // lst[v] -> 顶点v的邻接点在s中的终止下标
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
 * 打印有向图结构
 */
void PrintGraph(Graph G);

#endif
