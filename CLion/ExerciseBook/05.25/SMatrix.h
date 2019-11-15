/*======================
 * 稀疏矩阵，用于习题5.25
 =======================*/

#ifndef SMATRIX_H
#define SMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"    //**▲01 绪论**//

/* 宏定义 */
#define Mu      20      // 假设矩阵行数最大值为20
#define Nu      20      // 假设矩阵列数最大值为20
#define MAXSIZE 400     // 假设非零元个数的最大值为400

/* 稀疏矩阵类型定义 */
typedef struct {
    int V[MAXSIZE];     // 存储矩阵的元素
    int B[Mu][Nu];      // 标记矩阵中各位置元素是否为非零元
    int mu, nu, tu;     // 矩阵行数，列数，非零元个数
} SMatrix;


// 创建稀疏矩阵M
Status CreateSMatrix(SMatrix* M, char* path);

// 输出稀疏矩阵M
void PrintSMatrix(SMatrix M);

#endif
