#include <stdio.h>
#include <math.h>                        //�ṩpowԭ��

/*
 * ��1.20
 *
 * �������ʽPn(Xo)��ֵ
 */
double Algo_1_20(int a[], int x, int n);


int main(int argc, char* argv[]) {
    int a[5] = {-2, 3, 6, -8, 7};
    int n = 5;
    int Xo = 3;
    
    printf("��Ϊʾ�����趨����n = 5������Xo = 3������Pn(Xo)...\n");
    printf("P%d(%d) = %f\n", n, Xo, Algo_1_20(a, Xo, n));
    
    return 0;
}


// �������ʽPn(Xo)��ֵ
double Algo_1_20(int a[], int x, int n) {
    int i;
    double tmp;
    
    for(i = 1, tmp = 0; i <= n; i++) {
        tmp += a[i - 1] * pow(x, i - 1);
    }
    
    return tmp;
}