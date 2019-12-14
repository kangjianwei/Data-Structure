#include <stdio.h>
#include <stdlib.h> // 提供malloc、realloc、free、exit原型
#include "Status.h" //**▲01 绪论**//

/*
 * 方法1：递归法求解，优点是算法简单
 *
 * 递归计算F(n)
 */
int Algo_3_25_1(int n);

/*
 * 方法2：消除递归的迭代法，优点是存储了上一层计算数值
 *
 * 迭代计算F(n)
 */
int Algo_3_25_2(int n);


int main(int argc, char* argv[]) {
    
    printf("F(10) = %d\n", Algo_3_25_1(10));
    
    printf("F(10) = %d\n", Algo_3_25_2(10));
    
    return 0;
}


/*
 * 方法1：递归法求解，优点是算法简单
 *
 * 递归计算F(n)
 */
int Algo_3_25_1(int n) {
    if(n < 0) {
        exit(ERROR);
    }
    
    if(n == 0) {
        return n + 1;
    } else {
        return n * Algo_3_25_1(n / 2);
    }
}

/*
 * 方法2：消除递归的迭代法，优点是存储了上一层计算数值
 *
 * 迭代计算F(n)
 */
int Algo_3_25_2(int n) {
    int* a;
    int i;
    
    if(n < 0) {
        exit(ERROR);
    }
    
    a = (int*) malloc((n + 1) * sizeof(int));
    
    for(i = 1, a[0] = 1; i <= n; i++) {
        a[i] = i * a[i / 2];
    }
    
    return a[n];
}
