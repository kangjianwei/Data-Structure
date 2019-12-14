/*======================
 * 稀疏矩阵，用于习题5.24
 =======================*/

#ifndef SMATRIX_H
#define SMATRIX_H

#include <stdio.h>
#include "Status.h"    //**▲01 绪论**//

#define MAXSIZE 100 // 假设非零元个数的最大值为400

/* 非零元类型 */
typedef struct {
    int seq;    // 该非零元在矩阵中的序号（以行序为主序）
    int e;
} SElem;

/* 稀疏矩阵 */
typedef struct {
    SElem data[MAXSIZE + 1]; // 存储各非零元素，data[0]未用
    int mu, nu, tu;          // 矩阵的行数、列数和非零元个数
} SMatrix;


// 创建稀疏矩阵M
Status CreateSMatrix(SMatrix* M, char* path);

// 输出稀疏矩阵M
void PrintSMatrix(SMatrix M);

#endif
