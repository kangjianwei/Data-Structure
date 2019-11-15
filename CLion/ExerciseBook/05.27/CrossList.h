/*===================
 * 十字链表（稀疏矩阵）
 *
 * 包含算法: 5.4
 ====================*/

#ifndef CROSSLIST_H
#define CROSSLIST_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <string.h>     // 提供 strstr 原型
#include "Status.h"     //**▲01 绪论**//

/* 十字链表元素类型 */
typedef int ElemType;

/* 非零元类型定义 */
typedef struct OLNode {
    int i, j;               // 该非零元的行下标和列下标
    ElemType e;
    struct OLNode* right;   // 该非零元所在的行表的后继链域
    struct OLNode* down;    // 该非零元所在的列表的后继链域
} OLNode, * OLink;

/* 十字链表类型定义 */
typedef struct {
    OLink* rhead;       // 行链表头指针
    OLink* chead;       // 列链表头指针
    int mu, nu, tu;     // 矩阵的行数、列数和非零元个数
} CrossList;


/*
 * ████████ 算法5.4 ████████
 *
 * 创建稀疏矩阵M
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
Status CreateSMatrix(CrossList* M, char* path);

/*
 * 销毁稀疏矩阵
 */
Status DestroySMatrix(CrossList* M);

/*
 * 矩阵复制
 *
 * 创建一个新矩阵T，该矩阵包含了从矩阵M中包含的数据。
 */
Status CopySMatrix(CrossList M, CrossList* T);

/*
 * 矩阵加法
 *
 * Q = M + N。
 */
Status AddSMatrix(CrossList M, CrossList N, CrossList* Q);

/*
 * 矩阵减法
 *
 * Q = M - N。
 */
Status SubSMatrix(CrossList M, CrossList N, CrossList* Q);

/*
 * 矩阵乘法
 *
 * Q = M * N。
 */
Status MultSMatrix(CrossList M, CrossList N, CrossList* Q);

/*
 * 矩阵转置
 */
Status TransposeSMatrix(CrossList M, CrossList* T);

/*
 * 输出矩阵
 */
void PrintSMatrix(CrossList M);

#endif
