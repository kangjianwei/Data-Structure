#include <stdio.h>
#include "Status.h"    //**▲01 绪论**//
#include "TSMatrix.h"  //**▲05 数组和广义表**//

/*
 * 稀疏矩阵加法：AddSMatrix
 *
 *【注】
 * 该函数已在TSMatrix相关文件中定义
 */
Status Algo_5_21(TSMatrix A, TSMatrix B, TSMatrix* C);


int main(int argc, char* argv[]) {
    TSMatrix A, B, C;
    
    printf("█ 创建两个稀疏矩阵 A、B ...\n");
    CreateSMatrix(&A, "TestData_A.txt");
    CreateSMatrix(&B, "TestData_B.txt");
    printf("█ A = \n");
    PrintSMatrix(A);
    printf("█ B = \n");
    PrintSMatrix(B);
    
    // 矩阵相加
    Algo_5_21(A, B, &C);
    
    printf("█ C = A + B = \n");
    PrintSMatrix(C);
    
    return 0;
}


/*
 * 稀疏矩阵加法：AddSMatrix
 *
 *【注】
 * 该函数已在TSMatrix相关文件中定义
 */
Status Algo_5_21(TSMatrix A, TSMatrix B, TSMatrix* C) {
    return AddSMatrix(A, B, C);
}
