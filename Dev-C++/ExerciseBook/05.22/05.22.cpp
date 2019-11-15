#include <stdio.h>
#include "Status.h"    //**▲01 绪论**//
#include "TSMatrix.h"  //**▲05 数组和广义表**//

/*
 * 稀疏矩阵加法：AddSMatrix
 *
 *【注】
 * 计算结果需要保存到原矩阵A中
 */
Status Algo_5_22(TSMatrix* A, TSMatrix B);


int main(int argc, char* argv[]) {
    TSMatrix A, B;
    
    printf("█ 创建两个稀疏矩阵 A、B ...\n");
    CreateSMatrix(&A, "TestData_A.txt");
    CreateSMatrix(&B, "TestData_B.txt");
    printf("█ A = \n");
    PrintSMatrix(A);
    printf("█ B = \n");
    PrintSMatrix(B);
    
    // 矩阵相加
    Algo_5_22(&A, B);
    
    printf("█ A = A + B = \n");
    PrintSMatrix(A);
    
    return 0;
}


/*
 * 稀疏矩阵加法：AddSMatrix
 *
 *【注】
 * 计算结果需要保存到原矩阵A中
 */
Status Algo_5_22(TSMatrix* A, TSMatrix B) {
    int m, n, k;
    
    if((*A).mu != B.mu || (*A).nu != B.nu) {
        printf("两矩阵的行数、列数不满足相加条件！！\n");
        return ERROR;
    }
    
    // A中元素向后移动，移动长度为B的元素个数
    for(k = (*A).tu; k > 0; k--) {
        (*A).data[k + B.tu] = (*A).data[k];
    }
    
    m = B.tu + 1;   // 遍历A的起点
    n = 1;          // 遍历B的起点
    k = 0;          // 指向计算结果的游标
    
    // 依次遍历A与B的三元组
    while(m <= (*A).tu + B.tu && n <= B.tu) {
        // A中的三元组行下标较小
        if((*A).data[m].i < B.data[n].i) {
            (*A).data[++k] = (*A).data[m++];
            
            // B中的三元组行下标较小
        } else if((*A).data[m].i > B.data[n].i) {
            (*A).data[++k] = B.data[n++];
            
            // A与B中的三元组行下标一致，需要进一步比较列坐标
        } else {
            // A中的三元组列下标较小
            if((*A).data[m].j < B.data[n].j) {
                (*A).data[++k] = (*A).data[m++];
                
                // B中的三元组列下标较小
            } else if((*A).data[m].j > B.data[n].j) {
                (*A).data[++k] = B.data[n++];
                
                // A与B中的三元组列下标一致，需要进行加法运算
            } else {
                // 值不为0时，需要存储该元素
                if(((*A).data[m].e + B.data[n].e) != 0) {
                    k++;
                    (*A).data[k].i = (*A).data[m].i;
                    (*A).data[k].j = (*A).data[m].j;
                    (*A).data[k].e = (*A).data[m].e + B.data[n].e;
                }
                m++;
                n++;
            }
        }
    }
    
    // 遍历A中剩余的三元组
    while(m <= (*A).tu + B.tu) {
        (*A).data[++k] = (*A).data[m++];
    }
    
    // 遍历B中剩余的三元组
    while(n <= B.tu) {
        (*A).data[++k] = B.data[n++];
    }
    
    (*A).tu = k;
    
    return OK;
}
