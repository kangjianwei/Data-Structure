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


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建树的内部函数
static void Create(CSTree* T, FILE* fp);

// 计算树的深度的内部实现
static void Depth(CSTree T, int d, int *max);


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构
void PrintTree(CSTree T);

// 图形化输出当前结构内部实现
static void Print(CSTree T, int row);

#endif
