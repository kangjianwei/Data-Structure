#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/*
 * 方法1：递归法
 *
 * 递归计算平方根
 */
float Algo_3_26_1(float A, float p, float e);

/*
 * 方法2：迭代法
 *
 * 迭代计算平方根
 */
float Algo_3_26_2(float A, float p, float e);


int main(int argc, char* argv[]) {
    
    printf("√50 = %f\n", Algo_3_26_1(50, 1, 0.000001f));
    
    printf("√50 = %f\n", Algo_3_26_2(50, 1, 0.000001f));
    
    return 0;
}


/*
 * 方法1：递归法
 *
 * 递归计算平方根
 */
float Algo_3_26_1(float A, float p, float e) {
    if(A < 0.0) {
        exit(ERROR);
    }
    
    if((p * p - A) > -e && (p * p - A) < e) {
        return p;
    } else {
        return Algo_3_26_1(A, (p + A / p) / 2, e);
    }
}

/*
 * 方法2：迭代法
 *
 * 迭代计算平方根
 */
float Algo_3_26_2(float A, float p, float e) {
    if(A < 0.0) {
        exit(ERROR);
    }
    
    while((p * p - A) >= e || (p * p - A) <= -e) {
        p = (p + A / p) / 2;
    }
    
    return p;
}
