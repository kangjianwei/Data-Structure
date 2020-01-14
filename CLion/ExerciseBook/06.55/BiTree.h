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
    
    int DescNum;                // 该结点的子孙数量
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
 * 置空
 *
 * 清理二叉树中的数据，使其成为空树。
 */
Status ClearBiTree(BiTree* T);

/*
 * ████████ 算法6.4 ████████
 *
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
Status CreateBiTree(BiTree* T, char* path);

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


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建二叉树的内部函数
static void CreateTree(BiTree* T, FILE* fp);


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构，仅限内部测试使用
void PrintTree(BiTree T);

#endif
