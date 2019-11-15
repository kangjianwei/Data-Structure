#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Array.h"      //**▲05 数组和广义表**//

/* 数组元素坐标 */
typedef struct {
    int x;
    int y;
    ElemType value;
} Elem;

/*
 * 寻找二维数组A中的马鞍点
 *
 *【注】
 * 数组每行每列的元素不唯一
 */
void Algo_5_19(Array A);


int main(int argc, char* argv[]) {
    int a[3][4] = {
        {10, 16, 13, 14},
        {15, 18, 15, 20},
        { 5,  8, 12, 32}
    };
    int i, j;
    Array A;
    
    // 准备测试数据
    InitArray(&A, 2, 3, 4);
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            Assign(&A, a[i][j], i, j);
        }
    }
    
    // 寻找马鞍点
    Algo_5_19(A);
    
    return 0;
}


/*
 * 寻找二维数组A中的马鞍点
 *
 *【注】
 * 数组每行每列的元素不唯一
 */
void Algo_5_19(Array A) {
    int row, col;   // 行数与列数
    Elem* Min;      // 存储数组A中每行的最小值信息
    ElemType* Max;  // 存储数组A中每列的最大值（只存储值）
    int total, k;   // total记录Min中存储的元素数量
    int i, j;
    ElemType e;
    int count;
    int min;
    
    row = A.bounds[0];
    col = A.bounds[1];
    
    Min = (Elem*) malloc(row * col * sizeof(Elem));
    
    Max = (ElemType*) malloc(col * sizeof(ElemType));
    // 初始化最大值数组
    for(j = 0; j < col; j++) {
        Max[j] = INT_MIN;
    }
    
    total = 0;
    
    for(i = 0; i < row; i++) {
        min = INT_MAX;  // 当前行最小值
        
        for(j = 0; j < col; j++) {
            // 获取元素A[i][j]
            Value(A, &e, i, j);
            
            // 记录最大值
            if(e > Max[j]) {
                Max[j] = e;
            }
            
            // 记录最小值信息
            if(e <= min) {
                // 每次发现更小的，k都需要重置
                if(e < min) {
                    k = total;  // 重新统计当前行的最小值元素数量
                    min = e;
                }
                
                Min[k].x = i;
                Min[k].y = j;
                Min[k].value = e;
                
                k++;
            }
        }
        
        // 累加本次新增的元素数量
        total += (k - total);
    }
    
    count = 0;
    for(k = 0; k < total; k++) {
        // 如果当前最小值所在列的最大值与当前最小值一致，则遇到了马鞍点
        if(Max[Min[k].y] == Min[k].value) {
            printf("第 %2d 个马鞍点是位于 (%2d, %2d) 处的 %d\n", ++count, Min[k].x, Min[k].y, Min[k].value);
        }
    }
}
