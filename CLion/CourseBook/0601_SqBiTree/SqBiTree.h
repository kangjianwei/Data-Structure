/*==================
 * 二叉树顺序存储结构
 ===================*/

#ifndef SQBITREE_H
#define SQBITREE_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、free 原型
#include <string.h>     // 提供 memset、strcmp 原型
#include <math.h>       // 提供 pow 原型
#include "Status.h"     //**▲01 绪论**//

/* 宏定义 */
#define MAX_TREE_SIZE 1024       // 二叉树的最大结点数

/* 二叉树元素类型定义，这里假设其元素类型为char */
typedef char TElemType;

/*
 * 二叉树类型定义，0号单元存储根结点。
 *
 *【注】
 * 在二叉树的顺序结构中，其元素是按照完全顺序二叉树的层序序列排列的。
 */
typedef TElemType SqBiTree[MAX_TREE_SIZE];


/*
 * 初始化
 *
 * 构造空二叉树。
 */
Status InitBiTree(SqBiTree T);

/*
 * 销毁
 *
 * 释放二叉树所占内存。
 *
 *【注】
 * 二叉树的顺序存储结构无法销毁。
 */
Status DestroyBiTree(SqBiTree T);

/*
 * 置空
 *
 * 清理二叉树中的数据，使其成为空树。
 */
Status ClearBiTree(SqBiTree T);

/*
 * 创建
 *
 * 按照预设的定义来创建二叉树。
 * 这里约定使用【先序序列】来创建二叉树。
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
Status CreateBiTree(SqBiTree T, char* path);

/*
 * 判空
 *
 * 判断二叉树是否为空树。
 */
Status BiTreeEmpty(SqBiTree T);

/*
 * 树深
 *
 * 返回二叉树的深度（层数）。
 */
int BiTreeDepth(SqBiTree T);

/*
 * 取值
 *
 * 返回二叉树中指定结点的值。
 */
TElemType Value(SqBiTree T, TElemType e);

/*
 * 赋值
 *
 * 为二叉树指定的结点赋值。
 */
Status Assign(SqBiTree T, TElemType e, TElemType value);

/*
 * 根
 *
 * 返回二叉树的根结点。
 */
TElemType Root(SqBiTree T);

/*
 * 双亲
 *
 * 返回二叉树中结点e的双亲结点。
 */
TElemType Parent(SqBiTree T, TElemType e);

/*
 * 左孩子
 *
 * 返回二叉树中结点e的左孩子结点。
 */
TElemType LeftChild(SqBiTree T, TElemType e);

/*
 * 右孩子
 *
 * 返回二叉树中结点e的右孩子结点。
 */
TElemType RightChild(SqBiTree T, TElemType e);

/*
 * 左兄弟
 *
 * 返回二叉树中结点e的左兄弟结点。
 */
TElemType LeftSibling(SqBiTree T, TElemType e);

/*
 * 右兄弟
 *
 * 返回二叉树中结点e的右兄弟结点。
 */
TElemType RightSibling(SqBiTree T, TElemType e);

/*
 * 插入
 *
 * 已知c为与T不相交的非空二叉树，且c的右子树为空，
 * 根据LR的取值(0或1)，将c插入为T中结点p的左子树/右子树，
 * 并且，将p结点原有的左子树/右子树嫁接为二叉树c的右子树。
 */
Status InsertChild(SqBiTree T, TElemType p, int LR, SqBiTree c);

/*
 * 删除
 *
 * 根据LR的取值(0或1)，删除结点p的左子树/右子树。
 */
Status DeleteChild(SqBiTree T, TElemType p, int LR);

/*
 * 先序遍历
 */
Status PreOrderTraverse(SqBiTree T, Status(Visit)(TElemType));

/*
 * 中序遍历
 */
Status InOrderTraverse(SqBiTree T, Status(Visit)(TElemType));

/*
 * 后序遍历
 */
Status PostOrderTraverse(SqBiTree T, Status(Visit)(TElemType));

/*
 * 层序遍历
 */
Status LevelOrderTraverse(SqBiTree T, Status(Visit)(TElemType));


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建二叉树的内部函数
static void CreateTree(SqBiTree T, int i, FILE* fp);

// 求二叉树深度的内部函数
static int TreeDepth(SqBiTree T, int i);

// 返回二叉树结点e的索引号，i是结点p的索引号
static int EIndex(SqBiTree T, TElemType e, int i);

// 摘下二叉树T中的子树i，将其插入为二叉树R的子树j
static void Transfer(SqBiTree T, int i, SqBiTree R, int j);

// 删除二叉树T中的子树i
static void Delete(SqBiTree T, int i);

// 先序遍历的内部实现
static Status PreTraverse(SqBiTree T, Status(Visit)(TElemType), int i);

// 中序遍历的内部实现
static Status InTraverse(SqBiTree T, Status(Visit)(TElemType), int i);

// 后序遍历的内部实现
static Status PostTraverse(SqBiTree T, Status(Visit)(TElemType), int i);


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构，仅限内部测试使用
void PrintTree(SqBiTree T);

#endif
