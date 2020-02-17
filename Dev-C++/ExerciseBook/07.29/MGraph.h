/*=================================
 * 图的数组(邻接矩阵)存储表示
 *
 * 包含算法: 7.1、7.2、7.4、7.5、7.6
 ==================================*/

#ifndef MGRAPH_H
#define MGRAPH_H

#include <stdio.h>
#include <limits.h>     // 提供宏INT_MAX
#include <string.h>     // 提供memset、strcmp 原型
#include <stdarg.h>     // 提供宏va_list、va_start、va_arg、va_end
#include "Status.h"     //**▲01 绪论**//

/*
 * 注：
 *
 * 通常来讲，无权图被简称为【图】，有权图被简称为【网】。
 * 无向图/网中的顶点关系被称为【边】，有向图/网中的顶点关系被称为【弧】，并区分弧头与弧尾。
 * 实际表述中，未必会严格遵守以上命名。
 */

/* 宏定义 */
#define INFINITE INT_MAX    // 最大值，用来表示网中的两个顶点不直接连接
#define MAX_VERTEX_NUM 26   // 最大顶点个数


// 图的类型
typedef enum {
    DG,     // 0-有向图
    DN,     // 1-有向网(带权值)
    UDG,    // 2-无向图
    UDN     // 3-无向网(带权值)
} GraphKind;

// 顶点类型
typedef char VertexType;

/*
 * 顶点关系类型
 *
 * 在无权图中，该值通常为0或1，表示两顶点是否直接连通；
 * 在有权图中，该值通常为权值。
 */
typedef int VRType;

// 边的相关附加信息
typedef struct {
    // 如果有的话，后续会添加相应的属性
} InfoType;

// 边的类型，每条边上可能有附加信息info
typedef struct ArcCell {
    VRType adj;  // 顶点关系，在有权图跟无权图中的含义不同
    InfoType* info; // 边的附加信息，通常忽略
} ArcCell;

/* 图/网的数组(邻接矩阵)存储表示类型定义 */
typedef struct {
    VertexType vexs[MAX_VERTEX_NUM];               // 顶点向量
    ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // 邻接矩阵
    int vexnum, arcnum;                            // 图/网的顶点数和弧数
    GraphKind kind;                                // 图的类型标志
} MGraph;


// 边/弧上是否存在附加信息
extern Boolean IncInfo;


/*
 * ████████ 算法7.1 ████████
 *
 * 创建
 *
 *【备注】
 *
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 *
 * 如果需要从控制台读取数据，则path为NULL，或path[kind]为""。
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
Status CreateGraph(MGraph* G, char* path[]);

/*
 * 构造无向图
 */
static Status CreateDG(MGraph* G);

/*
 * 录入边的相关附加信息
 */
static void Input(MGraph G, InfoType** info);

/*
 * 查找
 *
 * 返回顶点u在图/网中的位置
 */
int LocateVex(MGraph G, VertexType u);

/*
 * 取值
 *
 * 返回索引v处的顶点值
 */
VertexType GetVex(MGraph G, int v);

/*
 * 首个邻接点
 *
 * 返回顶点v的首个邻接点
 */
int FirstAdjVex(MGraph G, VertexType v);

/*
 * 下一个邻接点
 *
 * 返回顶点v的(相对于w的)下一个邻接点
 */
int NextAdjVex(MGraph G, VertexType v, VertexType w);

/*
 * 以图形化形式输出当前结构
 *
 * 注：在网中，使用"-"来表示两顶点不直接连通
 */
void PrintGraph(MGraph G);

#endif
