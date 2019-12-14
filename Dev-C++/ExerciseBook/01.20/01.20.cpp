#include <stdio.h>
#include <math.h>                        //提供pow原型

/*
 * 题1.20
 *
 * 计算多项式Pn(Xo)的值
 */
double Algo_1_20(int a[], int x, int n);


int main(int argc, char* argv[]) {
    int a[5] = {-2, 3, 6, -8, 7};
    int n = 5;
    int Xo = 3;
    
    printf("作为示范，设定项数n = 5，变量Xo = 3，计算Pn(Xo)...\n");
    printf("P%d(%d) = %f\n", n, Xo, Algo_1_20(a, Xo, n));
    
    return 0;
}


// 计算多项式Pn(Xo)的值
double Algo_1_20(int a[], int x, int n) {
    int i;
    double tmp;
    
    for(i = 1, tmp = 0; i <= n; i++) {
        tmp += a[i - 1] * pow(x, i - 1);
    }
    
    return tmp;
}