/*==================
 * 树的双亲表存储表示
 ===================*/

#ifndef PTREE_H
#define PTREE_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、free 原型
#include <string.h>     // 提供 memset、strcmp 原型
#include "Status.h"     //**▲01 绪论**//
#include "LinkList.h"   //**▲02 线性表**//
#include "LinkQueue.h"  //**▲03 栈和队列**//

/* 树的最大结点数 */
#define MAX_TREE_SIZE 1024

/* 单个结点最大的孩子数量 */
#define MAX_CHILD_COUNT 8

/* 树的元素类型定义，这里假设其元素类型为char */
typedef char TElemType;

/* (双亲)树的结点定义 */
typedef struct PTNode {
    TElemType data;
    int parent;         // 双亲位置域
} PTNode;

/*
 * (双亲)树类型定义
 *
 *【注】
 * 1.树中结点在nodes中"紧邻"存储，没有空隙
 * 2.树根r可能出现在nodes的任意位置
 * 3.除根结点外，其他结点依次按层序顺着根结点往下排列（这一点与教材图示可能会有区别）
 * 4.nodes数组是循环使用的（这一点教材未提到）
 * 5.这里假设nodes空间是足够大的，可以视需求将其改为动态分配存储
 */
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];    // 存储树中结点
    int r;  // 树根位置(索引)
    int n;  // 树的结点数
} PTree;


/* 树中某个结点的信息 */
typedef struct{
    int row;            // 当前结点所处的行
    int col;            // 当前结点所处的列
    int childIndex;     // 当前结点是第几个孩子
    int firstChild;     // 当前结点的第一个孩子在树中的索引
    int lastChild;      // 当前结点的最后一个孩子在树中的索引
} Pos;


/*
 * 初始化
 *
 * 构造空树。
 */
Status InitTree(PTree* T);

/*
 * 创建
 *
 * 按照预设的定义来创建树。
 * 这里约定使用【层序序列】来创建树。
 *
 *
 *【备注】
 *
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 *
 * 如果需要从控制台读取数据，则path为NULL或者为空串，
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
Status CreateTree(PTree* T, char* path);

/*
 * 判空
 *
 * 判断树是否为空树。
 */
Status TreeEmpty(PTree T);

/*
 * 树深
 *
 * 返回树的深度（层数）。
 */
int TreeDepth(PTree T);


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建树的内部函数
static void Create(PTree* T, FILE* fp);

// 获取树T的结点信息，具体包含哪些信息，请参照Pos类型的定义
static void getPos(PTree T, Pos pt[]);


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构
void PrintGraph(PTree T);

// 图形化输出当前结构内部实现
static void Print(PTree T, Pos pt[], int i);

// 图形化输出树的排列结构，仅限内部测试使用
static void PrintFramework(PTree T);

#endif
