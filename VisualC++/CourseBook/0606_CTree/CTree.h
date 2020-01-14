/*=============================
 * 树的孩子链表(带双亲)的存储表示
 =============================*/

#ifndef CTREE_H
#define CTREE_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、free 原型
#include <string.h>     // 提供 memset、strcmp 原型
#include "Status.h"     //**▲01 绪论**//
#include "LinkQueue.h"  //**▲03 栈和队列**//

/* 树的最大结点数 */
#define MAX_TREE_SIZE 1024

/* 单个结点最大的孩子数量 */
#define MAX_CHILD_COUNT 8

/* 树的元素类型定义，这里假设其元素类型为char */
typedef char TElemType;

/* 孩子结点定义 */
typedef struct CTNode {
    int child;              // 该孩子在树中的索引
    struct CTNode* next;    // 指向下一个孩子
} CTNode;

/* 指向孩子结点的指针 */
typedef CTNode* ChildPtr;

/* (双亲)树的结点定义 */
typedef struct {
    int parent;             // 双亲位置域
    TElemType data;         // 当前结点
    ChildPtr firstchild;    // 孩子链表头指针
} CTBox;

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
    CTBox nodes[MAX_TREE_SIZE]; // 存储树中结点
    int r;  // 树根位置(索引)
    int n;  // 树的结点数
} CTree;


/*
 * 树中某个结点的信息
 *
 * 注：相比双亲表存储结构，不需要再寄来当前结点的第一个孩子在树中的索引
 * */
typedef struct{
    int row;            // 当前结点所处的行
    int col;            // 当前结点所处的列
    int childIndex;     // 当前结点是第几个孩子
    int lastChild;      // 当前结点的最后一个孩子在树中的索引
} Pos;


/*
 * 初始化
 *
 * 构造空树。
 */
Status InitTree(CTree* T);

/*
 * 销毁
 *
 * 释放树所占内存。
 *
 *【注】
 * 与置空操作是一致的
 */
Status DestroyTree(CTree* T);

/*
 * 置空
 *
 * 清理树中的数据，使其成为空树。
 */
Status ClearTree(CTree* T);

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
Status CreateTree(CTree* T, char* path);

/*
 * 判空
 *
 * 判断树是否为空树。
 */
Status TreeEmpty(CTree T);

/*
 * 树深
 *
 * 返回树的深度（层数）。
 */
int TreeDepth(CTree T);

/*
 * 取值
 *
 * 返回树中指定结点的值。
 */
TElemType Value(CTree T, TElemType e);

/*
 * 赋值
 *
 * 为树指定的结点赋值。
 */
Status Assign(CTree* T, TElemType e, TElemType value);

/*
 * 根
 *
 * 返回树的根结点。
 */
TElemType Root(CTree T);

/*
 * 双亲
 *
 * 返回树中结点e的双亲结点。
 */
TElemType Parent(CTree T, TElemType e);

/*
 * 孩子数量
 *
 * 返回树T中结点e的孩子数量。
 */
int ChildCount(CTree T, TElemType e);

/*
 * 孩子
 *
 * 返回树中结点e的第i个孩子。
 */
TElemType Child(CTree T, TElemType e, int i);

/*
 * 左兄弟
 *
 * 返回树中结点e的左兄弟结点。
 *
 *【注】
 * 由于树的结点可能会包含多个孩子，
 * 因此这里的左兄弟特指左边紧邻该结点的兄弟。
 */
TElemType LeftSibling(CTree T, TElemType e);

/*
 * 右兄弟
 *
 * 返回树中结点e的右兄弟结点。
 *
 *【注】
 * 由于树的结点可能会包含多个孩子，
 * 因此这里的右兄弟特指右边紧邻该结点的兄弟。
 */
TElemType RightSibling(CTree T, TElemType e);

/*
 * 插入
 *
 * 将树c插入为树T中p结点的第i个孩子。
 */
Status InsertChild(CTree* T, TElemType p, int i, CTree c);

/*
 * 删除
 *
 * 删除树T中p结点的第i个孩子。
 */
Status DeleteChild(CTree* T, TElemType p, int i);

/*
 * 先序遍历
 */
Status PreOrderTraverse(CTree T, Status(Visit)(TElemType));

/*
 * 后序遍历
 */
Status PostOrderTraverse(CTree T, Status(Visit)(TElemType));

/*
 * 层序遍历
 */
Status LevelOrderTraverse(CTree T, Status(Visit)(TElemType));


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建树的内部函数
static void Create(CTree* T, FILE* fp);

// 返回树结点e的索引，如果不存在，返回-1
static int EIndex(CTree T, TElemType e);

// 返回树结点e的第i个孩子索引，如果不存在，返回-1
static int CIndex(CTree T, TElemType e, int i);

// 获取树T的结点信息，具体包含哪些信息，请参照Pos类型的定义
static void getPos(CTree T, Pos pt[]);

// 先序遍历的内部实现
static Status PreTraverse(CTree T, int i, Status(Visit)(TElemType));

// 后序遍历的内部实现
static Status PostTraverse(CTree T, int i, Status(Visit)(TElemType));

// 输出pos信息，仅限内部测试使用
static void printPos(CTree T, Pos pt[]);


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构
void PrintTree(CTree T);

// 图形化输出当前结构内部实现
static void Print(CTree T, Pos pt[], int i);

// 图形化输出树的排列结构，仅限内部测试使用
static void PrintFramework(CTree T);

#endif
