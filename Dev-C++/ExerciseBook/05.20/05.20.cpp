#include <stdio.h>
#include <stdlib.h>     // �ṩ system��rand��srand ԭ��
#include <time.h>       // �ṩ time ԭ��
#include "Array.h"      //**��05 ����͹����**//

// ���ݶ���ʽϵ�����������ʽ
void Algo_5_20(Array A);

// ��������������ڲ�ʵ��
static void Print(Array A, int dim, int index[]);


int main(int argc, char* argv[]) {
    Array A;
    int i, j, k;
    ElemType e = 0;
    
    // ��ʼ��һ��ά��Ϊ<2,3,4>����ά����
    InitArray(&A, 3, 2, 3, 4);
    
    srand((unsigned) time(NULL));   // ��ϵͳʱ�������������
    
    // ׼����������
    for(i = 0; i < A.bounds[0]; i++) {
        for(j = 0; j < A.bounds[1]; j++) {
            for(k = 0; k < A.bounds[2]; k++) {
                e = rand() % 50 - 25;   // ��������������
                Assign(&A, e, i, j, k);
            }
        }
    }
    
    // �������ʽ
    Algo_5_20(A);
    
    return 0;
}


// ���ݶ���ʽϵ�����������ʽ
void Algo_5_20(Array A) {
    int i;
    int* index;
    
    // �ڱ�������Ԫ��ʱ����¼ÿ��Ԫ�ص�������ֻ��¼ǰdim-1ά��
    index = (int*) malloc((A.dim - 1) * sizeof(int));
    for(i = 0; i < A.dim - 1; i++) {
        index[i] = -1;
    }
    
    Print(A, 1, index);
    
    printf("\n");
}

// ��������������ڲ�ʵ��
static void Print(Array A, int dim, int index[]) {
    int i, j;
    int start;
    ElemType coef;
    
    if(dim == A.dim) {
        start = 0;
        
        // ���㱾�α�������ʼԪ��λ��
        for(i = 0; i < dim - 1; i++) {
            start += index[i] * A.constants[i];
        }
        
        // �������һ��ά���ڵ�Ԫ��
        for(i = 0; i < A.bounds[dim - 1]; i++) {
            // ��ȡϵ��
            coef = A.base[start + i];
            
            // ϵ��Ϊ0��������
            if(coef == 0) {
                continue;
            }
            
            if(coef < 0) {
                printf(" - ");
            } else {
                printf(" + ");
            }
            
            // ϵ���ľ���ֵΪ1ʱ���������ϵ��
            if(abs(coef) != 1) {
                // ���ϵ�����������ţ�ǰ���Ѿ���������ţ�����һ��Ҳ����ŷ���
                printf("%d", abs(coef));
            }
            
            /*
             * �������ʽ��ÿһ�δ֪��������a��b��c...����
             *
             *��ע��
             * ����ָ��λ0����ָ��λ1�����Σ�������Ȼ�����ӡ������
             * ����ѡ�񲻴�ӡ��Щ���
             */
            for(j = 0; j < dim - 1; j++) {
                printf("%c^%d", 'a' + j, index[j]);
            }
            printf("%c^%d", 'a' + j, i);
        }
    } else {
        for(i = 0; i < A.bounds[dim - 1]; i++) {
            // ������ת
            index[dim - 1] = (index[dim - 1] + 1 + A.bounds[dim - 1]) % A.bounds[dim - 1];
            
            Print(A, dim + 1, index);
        }
    }
}
