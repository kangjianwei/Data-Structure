#include <stdio.h>

/*
 * ��1.16
 *
 * ��3���������Ӵ�С˳�����
 */
void Algo_1_16(int *x, int *y, int *z);


int main(int argc, char* argv[]) {
    int x, y, z;
    
    x = 3;
    y = 7;
    z = 1;
    
    printf("��Ϊʾ�����趨����Ϊ��%d %d %d...\n", x, y, z);
    
    // ��������
    Algo_1_16(&x, &y, &z);
    
    printf("����Ӵ�С�����Ϊ��%d %d %d...\n", x, y, z);
    
    return 0;
}


// ��3���������Ӵ�С˳�����
void Algo_1_16(int *x, int *y, int *z) {
    int tmp;
    
    // ȷ��x>=y
    if(*x < *y) {
        tmp = *x;
        *x = *y;
        *y = tmp;
    }
    
    // ȷ��z>=y
    if(*y < *z) {
        tmp = *y;
        *y = *z;
        *z = tmp;
    }
    
    // ȷ��x>=z
    if(*x < *z) {
        tmp = *x;
        *x = *z;
        *z = tmp;
    }
}
