/*======================
 * 稀疏矩阵，用于习题5.25
 =======================*/

#include "SMatrix.h"    //**稀疏矩阵**//

// 创建稀疏矩阵M
Status CreateSMatrix(SMatrix* M, char* path) {
    FILE* fp;
    int v, i, j;
    
    fp = fopen(path, "r");
    
    ReadData(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));
    
    memset((*M).V, 0, sizeof((*M).V));
    memset((*M).B, 0, sizeof((*M).B));
    
    for(v=0; v < (*M).tu; v++) {
        // 读取非零元信息，将元素存入数组V中
        ReadData(fp, "%d%d%d", &i, &j, &((*M).V[v]));
        
        (*M).B[i-1][j-1] = 1;
    }
    
    fclose(fp);
    
    return OK;
}

// 输出稀疏矩阵M
void PrintSMatrix(SMatrix M) {
    int v, i, j;
    
    v = 0;  // 遍历V的游标
    
    for(i = 1; i <= M.mu; i++) {
        for(j = 1; j <= M.nu; j++) {
            if(M.B[i-1][j-1] == 1) {
                printf("%3d ", M.V[v++]);
            } else {
                printf("%3d ", M.B[i-1][j-1]);
            }
        }
        
        printf("\n");
    }
}
