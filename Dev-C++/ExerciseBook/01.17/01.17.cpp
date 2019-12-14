#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/*
 * ��1.17����������1���ݹ��㷨
 *
 * ����k��쳲��������е�m���ֵ
 *
 * ע����������int���ͣ�����������ʱ�����
 */
int Algo_1_17_1(int k, int m);

/*
 * ��1.17����������2������(����)�㷨
 *
 * ����k��쳲��������е�m���ֵ
 *
 * ע����������int���ͣ�����������ʱ�����
 */
int Algo_1_17_2(int k, int m);


int main(int argc, char* argv[]) {
    int k, m;
    
    k = 3;
    m = 20;
    
    printf("��Ϊʾ������� %d ��쳲��������е� %d ���ֵΪ��%d \n", k, m, Algo_1_17_1(k, m));
    
    printf("��Ϊʾ������� %d ��쳲��������е� %d ���ֵΪ��%d \n", k, m, Algo_1_17_2(k, m));
    
    return 0;
}


// ����k��쳲��������е�m���ֵ
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

// ����k��쳲��������е�m���ֵ
int Algo_1_17_2(int k, int m) {
    int i, j;
    int* fib;
    
    if(k < 1 || m < 0) {
        exit(OVERFLOW);
    }
    
    // ����fib����
    fib = (int*) malloc((m + 1) * sizeof(int));
    
    // ��ʼ��ǰk-1��Ϊ0
    for(i = 0;  i < k - 1 ;i++) {
        fib[i] = 0;
    }
    
    fib[k-1] = 1;
    
    for(i = k; i <= m; ++i) {
        // �ۼ�ǰk��
        for(j = i - 1, fib[i] = 0; j >= i - k; j--) {
            fib[i] += fib[j];
        }
    }
    
    return fib[m];
}
