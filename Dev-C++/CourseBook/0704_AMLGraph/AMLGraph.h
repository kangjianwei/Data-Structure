/*=====================
 * 图的邻接多重表存储表示
 ======================*/

#ifndef AMLGRAPH_H
#define AMLGRAPH_H

#include <stdio.h>
#include <string.h>     // 提供memset、strcmp 原型
#include <stdarg.h>     // 提供宏va_list、va_start、va_arg、va_end
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "LinkQueue.h"  //**▲03 栈和队列**//

/*
 * 注：
 *
 * 通常来讲，无权图被简称为【图】，有权图被简称为【网】。
 * 无向图/网中的顶点关系被称为【边】，有向图/网中的顶点关系被称为【弧】，并区分弧头与弧尾。
 * 实际表述中，未必会严格遵守以上命名。
 *
 * 当前结构适合存储无向图/网。
 *
 * ★ 插入边/弧的信息时，这里的实现是按"升序"插入的，这使得插入的弧是按"升序"排列的。
 */


/* 宏定义 */
#define MAX_VERTEX_NUM 26                       // 最大顶点个数


// 图的类型
// 图的类型
typedef enum {
    DG,     // 0-有向图；此处不支持
    DN,     // 1-有向网(带权值)；此处不支持
    UDG,    // 2-无向图
    UDN     // 3-无向网(带权值)
} GraphKind;


/* 无向图（邻接多重表）类型定义 */
typedef enum {
    unvisit, visit
} VisitIf;

// 顶点类型
typedef char VertexType;

// 边的相关附加信息
typedef struct {
    /*
     * 注：
     * 教材中给出的结构只考虑了无权图，而没考虑有权图(网)。
     * 这里为了把“网”的情形也考虑进去，特在附加信息中增加了"权重"属性。
     */
    int weight;
} InfoType;

/* 边结点 */
typedef struct EBox {
    VisitIf mark;       // 访问标记
    int ivex;           // 该边依附的两个顶点的位置
    int jvex;           // 该边依附的两个顶点的位置
    struct EBox* ilink; // 分别指向依附这两个顶点的下一条边
    struct EBox* jlink; // 分别指向依附这两个顶点的下一条边
    InfoType* info;
} EBox;

// 每个链表的头结点
typedef struct VexBox {
    VertexType data;    // 顶点信息
    EBox* firstedge;    // 指向第一条依附该顶点的边的指针
} VexBox;

/* 图的邻接多重表存储表示类型定义 */
typedef struct {
    VexBox adjmulist[MAX_VERTEX_NUM];   // 表头向量
    int vexnum, edgenum;                // 图/网的顶点数和边数
    GraphKind kind;                     // 图的类型标志
} AMLGraph;


// 边/弧上是否存在附加信息
extern Boolean IncInfo;


/*
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
Status CreateGraph(AMLGraph* G, char* path[]);

/*
 * 构造无向图
 */
static Status CreateUDG(AMLGraph* G);

/*
 * 构造无向网
 */
static Status CreateUDN(AMLGraph* G);

/*
 * 录入边的相关附加信息
 */
static void Input(AMLGraph G, InfoType** info);

/*
 * 销毁
 *
 * 邻接表存储的图需要释放内存。
 */
Status DestroyGraph(AMLGraph* G);

/*
 * 查找
 *
 * 返回顶点u在图/网中的位置
 */
int LocateVex(AMLGraph G, VertexType u);

/*
 * 取值
 *
 * 返回索引v处的顶点值
 */
VertexType GetVex(AMLGraph G, int v);

/*
 * 赋值
 *
 * 将顶点v赋值为value
 */
Status PutVex(AMLGraph* G, VertexType v, VertexType value);

/*
 * 首个邻接点
 *
 * 返回顶点v的首个邻接点
 */
int FirstAdjVex(AMLGraph G, VertexType v);

/*
 * 下一个邻接点
 *
 * 返回顶点v的(相对于w的)下一个邻接点
 */
int NextAdjVex(AMLGraph G, VertexType v, VertexType w);

/*
 * 插入顶点
 *
 * 将指定的顶点v追加到顶点集中，未建立该顶点与其他顶点的关系
 */
Status InsertVex(AMLGraph* G, VertexType v);

/*
 * 删除顶点
 *
 * 从顶点集中删除指定的顶点v，注意需要更新相关的顶点关系
 */
Status DeleteVex(AMLGraph* G, VertexType v);

/*
 * 构造一个边结点(仅限内部使用)
 */
static EBox* newEBoxPtr(VisitIf mark, int ivex, int jvex, EBox* ilink, EBox* jlink, InfoType* info);

/*
 * 插入边<v, w>
 *
 * 当前图/网是无向的，且由于特殊的结构，使得插入一条边时只需要增加一对顶点关系，边的数量依然增一。
 * 对于图/网来说，可以在可变参数中列出边的附加信息。
 *
 * 注：此处接收的参数与MGraph有些不一样：网的附加信息中包含了各条边的权值。
 */
Status InsertArc(AMLGraph* G, VertexType v, VertexType w, ...);

/*
 * 删除边<v, w>
 */
Status DeleteArc(AMLGraph* G, VertexType v, VertexType w);

/*
 * 深度优先遍历(此处借助递归实现)
 */
void DFSTraverse(AMLGraph G, Status(Visit)(VertexType));

/*
 * 深度优先遍历核心函数
 */
static void DFS(AMLGraph G, int v);

/*
 * 广度优先遍历(此处借助队列实现)
 */
void BFSTraverse(AMLGraph G, Status(Visit)(VertexType));

/*
 * 以图形化形式输出当前结构
 */
void PrintGraph(AMLGraph G);

#endif
