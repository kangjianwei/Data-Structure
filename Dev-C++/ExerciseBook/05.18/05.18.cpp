#include <stdio.h>
#include <stdlib.h>     // �ṩ system��rand��srand ԭ��
#include <time.h>       // �ṩ time ԭ��
#include "Status.h"     //**��01 ����**//
#include "Array.h"      //**��05 ����͹����**//

/*
 * ������A�е�Ԫ��ѭ������k��λ��
 */
Status Algo_5_18(Array A, int k);

// ����[begin, end]��Χ�ڵ�Ԫ��
static Status Reversal_5_18(Array A, int begin, int end);


int main(int argc, char* argv[]) {
    Array A;
    ElemType e;
    int i;
    int k = 7;      // ����λ��
    
    // ��ʼ������Ϊ10��һά����
    InitArray(&A, 1, 10);
    
    srand((unsigned) time(NULL));   // ��ϵͳʱ�������������
    
    for(i = 0; i < Length(A); i++) {
        e = rand() % 100;
        Assign(&A, e, i);
    }
    
    printf("����A������Ԫ��Ϊ��\n");
    for(i = 0; i < Length(A); i++) {
        Value(A, &e, i);
        printf("%2d ", e);
    }
    printf("\n");
    
    printf("������Aѭ������ %d λ��\n", k);
    Algo_5_18(A, k);
    for(i = 0; i < Length(A); i++) {
        Value(A, &e, i);
        printf("%2d ", e);
    }
    printf("\n");
    
    return 0;
}


/*
 * ������A�е�Ԫ��ѭ������k��λ��
 */
Status Algo_5_18(Array A, int k) {
    int n, p;
    
    n = Length(A);
    
    p = k % n;      // ����ʵ����Ҫѭ�����Ƶ�λ��
    if(p <= 0) {
        return ERROR;
    }
    
    Reversal_5_18(A, 0, n-1);   // ����[0, n-1]��Χ�ڵ�Ԫ��
    Reversal_5_18(A, 0, p-1);   // ����[0, p-1]��Χ�ڵ�Ԫ��
    Reversal_5_18(A, p, n-1);   // ����[p, n-1]��Χ�ڵ�Ԫ��
    
    return OK;
}

// ����[begin, end]��Χ�ڵ�Ԫ��
static Status Reversal_5_18(Array A, int begin, int end) {
    int i;
    ElemType e1, e2;
    
    if(begin < 0 || end > Length(A)-1 || begin >= end) {
        return ERROR;
    }
    
    // ��"������"����
    for(i = 0; i < (end - begin + 1) / 2; i++) {
        Value(A, &e1, begin + i);     // ��ȡ�е�ǰ��Ԫ��
        Value(A, &e2, end - i);       // ��ȡ�е���Ԫ��
        
        // ��Ԫ����ɽ���
        Assign(&A, e2, begin + i);
        Assign(&A, e1, end - i);
    }
    
    return OK;
}
