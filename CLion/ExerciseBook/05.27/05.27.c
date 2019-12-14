#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "CrossList.h"  //**▲05 数组和广义表**//

/*
 * 稀疏矩阵加法：AddSMatrix
 *
 *【注】
 * 该函数已在CrossList相关文件中定义
 */
Status Algo_5_27(CrossList M, CrossList N, CrossList* Q);


int main(int argc, char* argv[]) {
    CrossList M, N, Q;
    
    printf("█ 创建两个稀疏矩阵 M、N ...\n");
    CreateSMatrix(&M, "TestData_M.txt");
    CreateSMatrix(&N, "TestData_N.txt");
    printf("█ M = \n");
    PrintSMatrix(M);
    printf("█ N = \n");
    PrintSMatrix(N);
    
    Algo_5_27(M, N, &Q);
    printf("█ Q = M + N = \n");
    PrintSMatrix(Q);
    
    return 0;
}


/*
 * 稀疏矩阵加法：AddSMatrix
 *
 *【注】
 * 该函数已在CrossList相关文件中定义
 */
Status Algo_5_27(CrossList M, CrossList N, CrossList* Q) {
    return AddSMatrix(M, N, Q);
}
