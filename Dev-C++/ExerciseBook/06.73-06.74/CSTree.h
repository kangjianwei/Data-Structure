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
 * 判空
 *
 * 判断树是否为空树。
 */
Status TreeEmpty(CSTree T);

// 以图形化形式输出当前结构
void PrintTree(CSTree T);

// 图形化输出当前结构内部实现
static void Print(CSTree T, int row);

#endif
