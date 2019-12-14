#include <stdio.h>
#include <limits.h>    // �ṩ��INT_MAX
#include "Status.h"    //**��01 ����**//

/* �궨�� */
#define arrsize 20      //���鳤��
#define maxint INT_MAX  //��������

/*
 * ��1.17
 *
 * ����i!*2^i��ֵ��������a[i-1]��i��[1, arrsize]
 *
 * i!*2^i = (i-1)!*2^(i-1) * i * 2
 */
Status Algo_1_19(int i, int a[]);


int main(int argc, char* argv[]) {
    int i, a[arrsize];
    
    i = 5;
    
    printf("����i!*2^i...\n");
    
    if(Algo_1_19(i, a) == OK) {
        printf("��Ϊʾ�������㵱i = %d ʱ��a[i-1] = %d\n", i, a[i - 1]);
    }
    
    return 0;
}


// ����i!*2^i��ֵ
Status Algo_1_19(int i, int a[]) {
    int j;
    
    if(i < 1 || i > arrsize) {
        return ERROR;
    }
    
    // ����i==1ʱ������
    a[0] = 2;
    
    // ����i>1ʱ������
    for(j = 2; j <= i; j++) {
        if(maxint / (2 * j) < a[j - 2]) {
            return OVERFLOW;
        }
        
        a[j - 1] = a[j - 2] * j * 2;
    }
    
    return OK;
}
