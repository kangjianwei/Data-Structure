#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* ջԪ�����Ͷ��� */
typedef struct {
    int mval;
    int nval;
} SElemType;

/*
 * (1)�ݹ鷨
 *
 * �ݹ���㰢��������
 */
int Algo_3_27_1(int m, int n);

/*
 * (2)����ջģ��ݹ�
 *
 * ģ��ջ���㰢��������
 */
int Algo_3_27_2(int m, int n);


int main(int argc, char* argv[]) {
    
    printf("akm(3,4) = %d\n", Algo_3_27_1(3, 4));
    
    printf("akm(3,4) = %d\n", Algo_3_27_2(3, 4));
    
    return 0;
}


/*
 * (1)�ݹ鷨
 *
 * �ݹ���㰢��������
 */
int Algo_3_27_1(int m, int n) {
    int akm, tmp;
    
    if(m < 0 || n < 0) {
        exit(ERROR);
    }
    
    if(m == 0) {
        akm = n + 1;
    } else if(n == 0) {
        akm = Algo_3_27_1(m - 1, 1);
    } else {
        akm = Algo_3_27_1(m - 1, Algo_3_27_1(m, n - 1));
    }
    
    return akm;
}

/*
 * (2)����ջģ��ݹ�
 *
 * ģ��ջ���㰢��������
 */
int Algo_3_27_2(int m, int n) {
    SElemType stack[1000];
    int top = -1;   // ��ʼ��Ϊ-1��������0
    
    if(m < 0 || n < 0) {
        exit(ERROR);
    }
    
    // �ȵ������ٴ�ֵ
    top++;
    
    stack[top].mval = m;
    stack[top].nval = n;
    
    while(1) {
        // m==0
        while(top>0 && stack[top].mval == 0) {
            top--;
            stack[top].mval = stack[top].mval - 1;
            stack[top].nval = stack[top + 1].nval + 1;
        }
    
        if(top==0 && stack[0].mval == 0) {
            break;
        }
    
        // m!=0 n!=0
        while(stack[top].nval > 0) {
            top++;
            stack[top].mval = stack[top - 1].mval;
            stack[top].nval = stack[top - 1].nval - 1;
        }
    
        // m!=0 n==0
        if(stack[top].nval == 0) {
            stack[top].mval = stack[top].mval - 1;
            stack[top].nval = 1;
        }
    }
    
    return stack[top].nval + 1;
}
