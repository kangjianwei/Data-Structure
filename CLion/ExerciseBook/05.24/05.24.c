#include <stdio.h>
#include "Status.h"    //**▲01 绪论**//
#include "SMatrix.h"    //**稀疏矩阵**//

/*
 * 获取矩阵中第i行第j列的元素，并将其存储到e中
 */
Status Algo_5_24(SMatrix M, int i, int j, int* e);


int main(int argc, char* argv[]) {
    SMatrix M;
    int e;
    
    printf("█ 创建个稀疏矩阵 M ...\n");
    CreateSMatrix(&M, "TestData_M.txt");
    printf("M = \n");
    PrintSMatrix(M);
    
    Algo_5_24(M, 2, 3, &e);
    printf("第 %d 行 %d 列的元素为 %d\n", 2, 3, e);
    
    return 0;
}


/*
 * 获取矩阵中第i行第j列的元素，并将其存储到e中
 */
Status Algo_5_24(SMatrix M, int i, int j, int* e) {
    int s, p;
    
    if(i < 1 || i > M.mu || j < 1 || j > M.nu) {
        return ERROR;
    }
    
    for(p = 1, s = (i - 1) * M.nu + j; M.data[p].seq < s; p++) {
        // 寻找指定的元素
    }
    
    *e = 0; // 默认为0
    
    // 找到对应列下标的元素
    if(M.data[p].seq == s) {
        *e = M.data[p].e;
    }
    
    return OK;
}
