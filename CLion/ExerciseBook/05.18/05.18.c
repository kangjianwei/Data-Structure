#include <stdio.h>
#include <stdlib.h>     // 提供 system、rand、srand 原型
#include <time.h>       // 提供 time 原型
#include "Status.h"     //**▲01 绪论**//
#include "Array.h"      //**▲05 数组和广义表**//

/*
 * 将数组A中的元素循环右移k个位置
 */
Status Algo_5_18(Array A, int k);

// 逆置[begin, end]范围内的元素
static Status Reversal_5_18(Array A, int begin, int end);


int main(int argc, char* argv[]) {
    Array A;
    ElemType e;
    int i;
    int k = 7;      // 右移位数
    
    // 初始化长度为10的一维数组
    InitArray(&A, 1, 10);
    
    srand((unsigned) time(NULL));   // 用系统时间做随机数种子
    
    for(i = 0; i < Length(A); i++) {
        e = rand() % 100;
        Assign(&A, e, i);
    }
    
    printf("数组A包含的元素为：\n");
    for(i = 0; i < Length(A); i++) {
        Value(A, &e, i);
        printf("%2d ", e);
    }
    printf("\n");
    
    printf("将数组A循环右移 %d 位后：\n", k);
    Algo_5_18(A, k);
    for(i = 0; i < Length(A); i++) {
        Value(A, &e, i);
        printf("%2d ", e);
    }
    printf("\n");
    
    return 0;
}


/*
 * 将数组A中的元素循环右移k个位置
 */
Status Algo_5_18(Array A, int k) {
    int n, p;
    
    n = Length(A);
    
    p = k % n;      // 计算实际需要循环右移的位数
    if(p <= 0) {
        return ERROR;
    }
    
    Reversal_5_18(A, 0, n-1);   // 逆置[0, n-1]范围内的元素
    Reversal_5_18(A, 0, p-1);   // 逆置[0, p-1]范围内的元素
    Reversal_5_18(A, p, n-1);   // 逆置[p, n-1]范围内的元素
    
    return OK;
}

// 逆置[begin, end]范围内的元素
static Status Reversal_5_18(Array A, int begin, int end) {
    int i;
    ElemType e1, e2;
    
    if(begin < 0 || end > Length(A)-1 || begin >= end) {
        return ERROR;
    }
    
    // 用"交换法"逆置
    for(i = 0; i < (end - begin + 1) / 2; i++) {
        Value(A, &e1, begin + i);     // 获取中点前的元素
        Value(A, &e2, end - i);       // 获取中点后的元素
        
        // 两元素完成交换
        Assign(&A, e2, begin + i);
        Assign(&A, e1, end - i);
    }
    
    return OK;
}
