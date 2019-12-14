#include <stdio.h>
#include <limits.h>    // 提供宏INT_MAX
#include "Status.h"    //**▲01 绪论**//

/* 宏定义 */
#define arrsize 20      //数组长度
#define maxint INT_MAX  //最大的整数

/*
 * 题1.17
 *
 * 计算i!*2^i的值，并存入a[i-1]，i∈[1, arrsize]
 *
 * i!*2^i = (i-1)!*2^(i-1) * i * 2
 */
Status Algo_1_19(int i, int a[]);


int main(int argc, char* argv[]) {
    int i, a[arrsize];
    
    i = 5;
    
    printf("计算i!*2^i...\n");
    
    if(Algo_1_19(i, a) == OK) {
        printf("作为示例，计算当i = %d 时，a[i-1] = %d\n", i, a[i - 1]);
    }
    
    return 0;
}


// 计算i!*2^i的值
Status Algo_1_19(int i, int a[]) {
    int j;
    
    if(i < 1 || i > arrsize) {
        return ERROR;
    }
    
    // 计算i==1时的情形
    a[0] = 2;
    
    // 计算i>1时的情形
    for(j = 2; j <= i; j++) {
        if(maxint / (2 * j) < a[j - 2]) {
            return OVERFLOW;
        }
        
        a[j - 1] = a[j - 2] * j * 2;
    }
    
    return OK;
}
