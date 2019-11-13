/*=======================
 * 三元组顺序表（稀疏矩阵）
 *
 * 包含算法: 5.1、5.2
 ========================*/

#ifndef TSMATRIX_H
#define TSMATRIX_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc 原型
#include <string.h>     // 提供 strstr 原型
#include "Status.h"     //**▲01 绪论**//

/* 宏定义 */
#define MAXSIZE 12500   // 非零元数量的最大值

/* 三元组稀疏矩阵元素类型 */
typedef int ElemType;

/* 三元组类型定义，主要用来存储非零元 */
typedef struct {
    int i, j;       // 该三元组非零元的行下标和列下标
    ElemType e;
} Triple;

/* 三元组稀疏矩阵类型定义 */
typedef struct {
    Triple data[MAXSIZE + 1];   // 非零元三元组表，data[0]未用
    int mu, nu, tu;             // 矩阵的行数、列数和非零元个数
} TSMatrix;


/*
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
Status CreateSMatrix(TSMatrix* M, char* path);

/*
 * 销毁稀疏矩阵
 *
 *【注】
 * 三元组顺序表的结构无法销毁。
 */
Status DestroySMatrix(TSMatrix* M);

/*
 * 矩阵复制
 *
 * 创建一个新矩阵T，该矩阵包含了从矩阵M中包含的数据。
 */
Status CopySMatrix(TSMatrix M, TSMatrix* T);

/*
 * 矩阵加法
 *
 * Q = M + N。
 */
Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);

/*
 * 矩阵减法
 *
 * Q = M - N。
 */
Status SubSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);

/*
 * 矩阵乘法
 *
 * Q = M * N，这里实现的是传统矩阵乘法。
 */
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);

/*
 * ████████ 算法5.1 ████████
 *
 * 矩阵转置
 */
Status TransposeSMatrix(TSMatrix M, TSMatrix* T);

/*
 * ████████ 算法5.2 ████████
 *
 * 矩阵快速转置
 */
Status FastTransposeSMatrix(TSMatrix M, TSMatrix* T);

/*
 * 输出矩阵
 */
void PrintSMatrix(TSMatrix M);

#endif
