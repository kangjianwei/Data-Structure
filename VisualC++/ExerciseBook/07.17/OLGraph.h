/*====================
 * 图的十字链表存储表示
 *
 * 包含算法: 7.3
 ====================*/

#ifndef OLGRAPH_H
#define OLGRAPH_H

#include <stdio.h>
#include <string.h>     // 提供memset、strcmp 原型
#include <stdarg.h>     // 提供宏va_list、va_start、va_arg、va_end
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/*
 * 注：
 *
 * 通常来讲，无权图被简称为【图】，有权图被简称为【网】。
 * 无向图/网中的顶点关系被称为【边】，有向图/网中的顶点关系被称为【弧】，并区分弧头与弧尾。
 * 实际表述中，未必会严格遵守以上命名。
 *
 * 当前结构适合存储有向图。
 *
 * ★ 插入边/弧的信息时，这里的实现是按"升序"插入的，这使得插入的弧是按"升序"排列的。
 */


/* 宏定义 */
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

// 边/弧的相关附加信息
typedef struct {
    /*
     * 注：
     * 教材中给出的结构只考虑了无权图，而没考虑有权图(网)。
     * 这里为了把“网”的情形也考虑进去，特在附加信息中增加了"权重"属性。
     */
    int weight;
} InfoType;

/* 边/弧结点 */
typedef struct ArcBox {
    int tailvex;    // 弧头顶点位置
    int headvex;    // 弧尾顶点位置
    struct ArcBox* hlink;  // 指向下一个拥有相同弧头的弧
    struct ArcBox* tlink;  // 指向下一个拥有相同弧尾的弧
    InfoType* info;  // 该弧的相关附加信息
} ArcBox;

// 每个横向链表的头结点
typedef struct VexNode {
    VertexType data;    // 顶点
    ArcBox* firstin;    // 指向该顶点的第一条入弧
    ArcBox* firstout;   // 指向该顶点的第一条出弧
} VexNode;

/* 图的十字链表存储表示类型定义 */
typedef struct {
    VexNode xlist[MAX_VERTEX_NUM];  // 表头向量
    int vexnum, arcnum;             // 顶点数和弧数
    GraphKind kind;                 // 图的类型标志
} OLGraph;


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
Status CreateGraph(OLGraph* G, char* path[]);

/*
 * ████████ 算法7.3 ████████
 *
 * 构造有向图
 *
 * 注：
 * 教材中使用了头插法来插入弧，这种做法的唯一优点是插入方便，
 * 但是在涉及到删除或查找时，效率较低；
 * 而且，"头插法"依赖输入的顺序，如果输入的边/弧是乱序的，
 * 则最终构造出的图/网中的边/弧也是无序的。
 *
 * 为了克服以上缺点，这里改用"升序"插入法，保证插入的弧是"升序"的。
 * 但同时，这样做会使"插入"算法变得较为复杂。
 */
static Status CreateDG(OLGraph* G);

/*
 * 构造有向网
 */
static Status CreateDN(OLGraph* G);

/*
 * 构造无向图
 */
static Status CreateUDG(OLGraph* G);

/*
 * 构造无向网
 */
static Status CreateUDN(OLGraph* G);

/*
 * 录入弧的相关附加信息
 */
static void Input(OLGraph G, InfoType** info);

/*
 * 查找
 *
 * 返回顶点u在图/网中的位置
 */
int LocateVex(OLGraph G, VertexType u);

/*
 * 插入顶点
 *
 * 将指定的顶点v追加到顶点集中，未建立该顶点与其他顶点的关系
 */
Status InsertVex(OLGraph* G, VertexType v);

/*
 * 删除顶点
 *
 * 从顶点集中删除指定的顶点v，注意需要更新相关的顶点关系
 */
Status DeleteVex(OLGraph* G, VertexType v);

/*
 * 构造一个边/弧结点(仅限内部使用)
 */
static ArcBox* newArcBoxPtr(int tailvex, int headvex, ArcBox* hlink, ArcBox* tlink, InfoType* info);

/*
 * 插入边/弧<v, w>
 *
 * 如果当前图/网是无向的，则插入一条弧需要增加两个顶点关系，但弧的数量只增一。
 * 对于图/网来说，可以在可变参数中列出边/弧的附加信息。
 *
 * 注：此处接收的参数与MGraph有些不一样：网的附加信息中包含了各条边/弧的权值。
 */
Status InsertArc(OLGraph* G, VertexType v, VertexType w, ...);

/*
 * 删除边/弧<v, w>
 */
Status DeleteArc(OLGraph* G, VertexType v, VertexType w);

/*
 * 以图形化形式输出当前结构
 */
void PrintGraph(OLGraph G);

#endif
