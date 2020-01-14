/*===================================
 * 树的二叉链表（孩子-兄弟）结构存储表示
 ====================================*/

#ifndef CSTREE_H
#define CSTREE_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、free 原型
#include <string.h>     // 提供 memset、strcmp 原型
#include "Status.h"     //**▲01 绪论**//

/* 单个结点最大的孩子数量 */
#define MAX_CHILD_COUNT 8

/* 树的元素类型定义，这里假设其元素类型为char */
typedef char TElemType;

/* (孩子-兄弟)树的结点定义 */
typedef struct CSNode {
    TElemType data;
    struct CSNode* firstchild;  // 指向长子
    struct CSNode* nextsibling; // 指向右兄弟
} CSNode;

/* (孩子-兄弟)树类型定义 */
typedef CSNode* CSTree;


/*
 * 初始化
 *
 * 构造空树。
 */
Status InitTree(CSTree* T);

/*
 * 销毁
 *
 * 释放树所占内存。
 *
 *【注】
 * 与置空操作是一致的
 */
Status DestroyTree(CSTree* T);

/*
 * 置空
 *
 * 清理树中的数据，使其成为空树。
 */
Status ClearTree(CSTree* T);

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
Status CreateTree(CSTree* T, char* path);

/*
 * 判空
 *
 * 判断树是否为空树。
 */
Status TreeEmpty(CSTree T);

/*
 * 树深
 *
 * 返回树的深度（层数）。
 */
int TreeDepth(CSTree T);

/*
 * 取值
 *
 * 返回树中指定结点的值。
 */
TElemType Value(CSTree T, TElemType e);

/*
 * 赋值
 *
 * 为树指定的结点赋值。
 */
Status Assign(CSTree T, TElemType e, TElemType value);

/*
 * 根
 *
 * 返回树的根结点。
 */
TElemType Root(CSTree T);

/*
 * 双亲
 *
 * 返回树中结点e的双亲结点。
 */
TElemType Parent(CSTree T, TElemType e);

/*
 * 孩子数量
 *
 * 返回树T中结点e的孩子数量。
 */
int ChildCount(CSTree T, TElemType e);

/*
 * 孩子
 *
 * 返回树中结点e的第i个孩子。
 */
TElemType Child(CSTree T, TElemType e, int i);

/*
 * 左兄弟
 *
 * 返回树中结点e的左兄弟结点。
 */
TElemType LeftSibling(CSTree T, TElemType e);

/*
 * 右兄弟
 *
 * 返回树中结点e的右兄弟结点。
 */
TElemType RightSibling(CSTree T, TElemType e);

/*
 * 插入
 *
 * 将树c插入为树T中p结点的第i个孩子。
 */
Status InsertChild(CSTree* T, TElemType p, int i, CSTree c);

/*
 * 删除
 *
 * 删除树T中p结点的第i个孩子。
 */
Status DeleteChild(CSTree* T, TElemType p, int i);

/*
 * 先序遍历
 */
Status PreOrderTraverse(CSTree T, Status(Visit)(TElemType));

/*
 * 后序遍历
 */
Status PostOrderTraverse(CSTree T, Status(Visit)(TElemType));

/*
 * 层序遍历
 */
Status LevelOrderTraverse(CSTree T, Status(Visit)(TElemType));


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建树的内部函数
static void Create(CSTree* T, FILE* fp);

// 计算树的深度的内部实现
static void Depth(CSTree T, int d, int *max);

// 返回树结点e的指针，如果不存在，返回NULL
static CSTree EPtr(CSTree T, TElemType e);

// 返回树结点e的双亲结点的指针，如果不存在，返回NULL
static CSTree PPtr(CSTree T, TElemType e);

// 返回树结点e的第i个孩子的指针，如果不存在，返回NULL
static CSTree CPtr(CSTree T, TElemType e, int i);

// 先序遍历的内部实现
static Status PreTraverse(CSTree T, Status(Visit)(TElemType));

// 后序遍历的内部实现
static Status PostTraverse(CSTree T, Status(Visit)(TElemType));


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构
void PrintTree(CSTree T);

// 图形化输出当前结构内部实现
static void Print(CSTree T, int row);

#endif
