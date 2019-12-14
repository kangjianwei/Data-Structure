#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Array.h"      //**��05 ����͹����**//

/* ����Ԫ������ */
typedef struct {
    int x;
    int y;
    ElemType value;
} Elem;

/*
 * Ѱ�Ҷ�ά����A�е�����
 *
 *��ע��
 * ����ÿ��ÿ�е�Ԫ�ز�Ψһ
 */
void Algo_5_19(Array A);


int main(int argc, char* argv[]) {
    int a[3][4] = {
        {10, 16, 13, 14},
        {15, 18, 15, 20},
        { 5,  8, 12, 32}
    };
    int i, j;
    Array A;
    
    // ׼����������
    InitArray(&A, 2, 3, 4);
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            Assign(&A, a[i][j], i, j);
        }
    }
    
    // Ѱ������
    Algo_5_19(A);
    
    return 0;
}


/*
 * Ѱ�Ҷ�ά����A�е�����
 *
 *��ע��
 * ����ÿ��ÿ�е�Ԫ�ز�Ψһ
 */
void Algo_5_19(Array A) {
    int row, col;   // ����������
    Elem* Min;      // �洢����A��ÿ�е���Сֵ��Ϣ
    ElemType* Max;  // �洢����A��ÿ�е����ֵ��ֻ�洢ֵ��
    int total, k;   // total��¼Min�д洢��Ԫ������
    int i, j;
    ElemType e;
    int count;
    int min;
    
    row = A.bounds[0];
    col = A.bounds[1];
    
    Min = (Elem*) malloc(row * col * sizeof(Elem));
    
    Max = (ElemType*) malloc(col * sizeof(ElemType));
    // ��ʼ�����ֵ����
    for(j = 0; j < col; j++) {
        Max[j] = INT_MIN;
    }
    
    total = 0;
    
    for(i = 0; i < row; i++) {
        min = INT_MAX;  // ��ǰ����Сֵ
        
        for(j = 0; j < col; j++) {
            // ��ȡԪ��A[i][j]
            Value(A, &e, i, j);
            
            // ��¼���ֵ
            if(e > Max[j]) {
                Max[j] = e;
            }
            
            // ��¼��Сֵ��Ϣ
            if(e <= min) {
                // ÿ�η��ָ�С�ģ�k����Ҫ����
                if(e < min) {
                    k = total;  // ����ͳ�Ƶ�ǰ�е���СֵԪ������
                    min = e;
                }
                
                Min[k].x = i;
                Min[k].y = j;
                Min[k].value = e;
                
                k++;
            }
        }
        
        // �ۼӱ���������Ԫ������
        total += (k - total);
    }
    
    count = 0;
    for(k = 0; k < total; k++) {
        // �����ǰ��Сֵ�����е����ֵ�뵱ǰ��Сֵһ�£�������������
        if(Max[Min[k].y] == Min[k].value) {
            printf("�� %2d ��������λ�� (%2d, %2d) ���� %d\n", ++count, Min[k].x, Min[k].y, Min[k].value);
        }
    }
}
