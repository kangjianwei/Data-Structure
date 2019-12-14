#include <stdio.h>
#include <stdlib.h> // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h" //**��01 ����**//

/*
 * ����1���ݹ鷨��⣬�ŵ����㷨��
 *
 * �ݹ����F(n)
 */
int Algo_3_25_1(int n);

/*
 * ����2�������ݹ�ĵ��������ŵ��Ǵ洢����һ�������ֵ
 *
 * ��������F(n)
 */
int Algo_3_25_2(int n);


int main(int argc, char* argv[]) {
    
    printf("F(10) = %d\n", Algo_3_25_1(10));
    
    printf("F(10) = %d\n", Algo_3_25_2(10));
    
    return 0;
}


/*
 * ����1���ݹ鷨��⣬�ŵ����㷨��
 *
 * �ݹ����F(n)
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
 * ����2�������ݹ�ĵ��������ŵ��Ǵ洢����һ�������ֵ
 *
 * ��������F(n)
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
