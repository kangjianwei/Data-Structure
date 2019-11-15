#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "RLSMatrix.h"  //**▲05 数组和广义表**//

/*
 * 获取矩阵中第i行第j列的元素，并将其存储到e中
 */
Status Algo_5_23(RLSMatrix M, int i, int j, int* e);


int main(int argc, char* argv[]) {
    RLSMatrix M;
    int e;
    
    printf("█ 创建个稀疏矩阵 M ...\n");
    CreateSMatrix(&M, "TestData_M.txt");
    printf("M = \n");
    PrintSMatrix(M);
    
    Algo_5_23(M, 2, 3, &e);
    printf("█ 第 %d 行 %d 列的元素为 %d\n", 2, 3, e);
    
    return 0;
}


/*
 * 获取矩阵中第i行第j列的元素，并将其存储到e中
 */
Status Algo_5_23(RLSMatrix M, int i, int j, int* e) {
    int begin, end, k;
    
    if(i < 1 || i > M.mu || j < 1 || j > M.nu) {
        return ERROR;
    }
    
    // 获取第i行中首个非零元在三元组表中的位置
    begin = M.rpos[i];
    end = (i == M.mu ? M.tu : M.rpos[i + 1] - 1);
    
    *e = 0; // 默认为0
    
    for(k = begin; k <= end; k++) {
        // 找到对应列下标的元素
        if(M.data[k].j == j) {
            *e = M.data[k].e;
            break;
        }
    }
    
    return OK;
}
