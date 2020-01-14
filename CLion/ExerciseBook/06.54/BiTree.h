/*=============================
 * 二叉树的二叉链表存储结构
 *
 * 包含算法: 6.1、6.2、6.3、6.4
 =============================*/

#ifndef BITREE_H
#define BITREE_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、free 原型
#include <string.h>     // 提供 memset、strcmp 原型
#include <math.h>       // 提供 pow 原型
#include "Status.h"     //**▲01 绪论**//

/* 二叉树元素类型定义，这里假设其元素类型为char */
typedef char TElemType;

/* 二叉树结点定义 */
typedef struct BiTNode {
    TElemType data;             // 结点元素
    struct BiTNode* lchild;     // 左孩子指针
    struct BiTNode* rchild;     // 右孩子指针
} BiTNode;

/* 指向二叉树结点的指针 */
typedef BiTNode* BiTree;


/*
 * 初始化
 *
 * 构造空二叉树。
 */
Status InitBiTree(BiTree* T);

/*
 * 判空
 *
 * 判断二叉树是否为空树。
 */
Status BiTreeEmpty(BiTree T);

/*
 * 树深
 *
 * 返回二叉树的深度（层数）。
 */
int BiTreeDepth(BiTree T);

// 以图形化形式输出当前结构，仅限内部测试使用
void PrintTree(BiTree T);

#endif
