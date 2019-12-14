#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SMatrix.h"    //**稀疏矩阵**//

/*
 * 稀疏矩阵加法：AddSMatrix
 */
Status Algo_5_25(SMatrix P, SMatrix Q, SMatrix* R);


int main(int argc, char* argv[]) {
    SMatrix M, N, Q;
    
    printf("█ 创建两个稀疏矩阵 M、N ...\n");
    CreateSMatrix(&M, "TestData_M.txt");
    CreateSMatrix(&N, "TestData_N.txt");
    printf("█ M = \n");
    PrintSMatrix(M);
    printf("█ N = \n");
    PrintSMatrix(N);
    
    Algo_5_25(M, N, &Q);
    printf("Q = M + N = \n");
    PrintSMatrix(Q);
    
    return 0;
}


/*
 * 稀疏矩阵加法：AddSMatrix
 */
Status Algo_5_25(SMatrix P, SMatrix Q, SMatrix* R) {
    int i, j;
    int p, q, r;
    
    if(P.mu != Q.mu || P.nu != Q.nu) {
        printf("两矩阵的行数、列数不满足相加条件！！\n");
        return ERROR;
    }
    
    // 初始化R的信息
    (*R).mu = P.mu;
    (*R).nu = P.nu;
    (*R).tu = 0;
    memset((*R).V, 0, sizeof((*R).V));
    memset((*R).B, 0, sizeof((*R).B));
    
    // 指向P、Q、R中的数组V
    p = q = r = 0;
    
    for(i = 0; i < P.mu; ++i) {
        for(j = 0; j < P.nu; ++j) {
            if(P.B[i][j] == 0 && Q.B[i][j] == 0) {
                continue;
            } else if(P.B[i][j] == 0 && Q.B[i][j] == 1) {
                (*R).V[r++] = Q.V[q++];
                (*R).B[i][j] = 1;
            } else if(P.B[i][j] == 1 && Q.B[i][j] == 0) {
                (*R).V[r++] = P.V[p++];
                (*R).B[i][j] = 1;
                
                // 如果P、Q两处均有非零元，则尝试相加
            } else {
                if((P.V[p] + Q.V[q])!=0) {
                    (*R).V[r++] = P.V[p] + Q.V[q];
                    (*R).B[i][j] = 1;
                }
                
                p++;
                q++;
            }
        }
    }
    
    (*R).tu = r;
    
    return OK;
}
