#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/*
 * 题1.17———方法1：递归算法
 *
 * 计算k阶斐波那契数列第m项的值
 *
 * 注：计算结果是int类型，当项数过大时会溢出
 */
int Algo_1_17_1(int k, int m);

/*
 * 题1.17———方法2：递推(迭代)算法
 *
 * 计算k阶斐波那契数列第m项的值
 *
 * 注：计算结果是int类型，当项数过大时会溢出
 */
int Algo_1_17_2(int k, int m);


int main(int argc, char* argv[]) {
    int k, m;
    
    k = 3;
    m = 20;
    
    printf("作为示范，求得 %d 阶斐波那契数列第 %d 项的值为：%d \n", k, m, Algo_1_17_1(k, m));
    
    printf("作为示范，求得 %d 阶斐波那契数列第 %d 项的值为：%d \n", k, m, Algo_1_17_2(k, m));
    
    return 0;
}


// 计算k阶斐波那契数列第m项的值
int Algo_1_17_1(int k, int m) {
    int i, value;
    
    if(k < 2 || m < 0) {
        exit(OVERFLOW);
    }
    
    if(m < k - 1) {
        return 0;
    } else if(m == k - 1) {
        return 1;
    } else {
        for(i = 1, value = 0; i <= k; i++) {
            value += Algo_1_17_1(k, m - i);
        }
        
        return value;
    }
}

// 计算k阶斐波那契数列第m项的值
int Algo_1_17_2(int k, int m) {
    int i, j;
    int* fib;
    
    if(k < 1 || m < 0) {
        exit(OVERFLOW);
    }
    
    // 创建fib数组
    fib = (int*) malloc((m + 1) * sizeof(int));
    
    // 初始化前k-1项为0
    for(i = 0;  i < k - 1 ;i++) {
        fib[i] = 0;
    }
    
    fib[k-1] = 1;
    
    for(i = k; i <= m; ++i) {
        // 累加前k项
        for(j = i - 1, fib[i] = 0; j >= i - k; j--) {
            fib[i] += fib[j];
        }
    }
    
    return fib[m];
}
