#include <stdio.h>
#include <stdlib.h>     // �ṩ system��rand��srand ԭ��
#include <time.h>       // �ṩ time ԭ��
#include "SqList.h"     //**��02 ���Ա�**//

// �ݹ������ֵ
int Algo_5_17_1(SqList L, int len);

// �ݹ�����Сֵ
int Algo_5_17_2(SqList L, int len);

// �ݹ����
int Algo_5_17_3(SqList L, int len);

// �ݹ����
double Algo_5_17_4(SqList L, int len);

// �ݹ���ƽ����
double Algo_5_17_5(SqList L, int len);


int main(int argc, char* argv[]) {
    SqList L;
    int i;
    
    InitList(&L);
    
    srand((unsigned) time(NULL));   // ��ϵͳʱ�������������
    
    for(i = 1; i <= 10; i++) {
        ListInsert(&L, i, rand() % 100);
    }
    
    printf("˳����е���������Ϊ��");
    for(i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
    
    printf("˳����е����ֵΪ�� %d \n", Algo_5_17_1(L, L.length));
    printf("˳����е���СֵΪ�� %d \n", Algo_5_17_2(L, L.length));
    printf("˳����еĺ�Ϊ�� %d \n", Algo_5_17_3(L, L.length));
    printf("˳����еĻ�Ϊ�� %.2f \n", Algo_5_17_4(L, L.length));
    printf("˳����е�ƽ��ֵΪ�� %.2f \n", Algo_5_17_5(L, L.length));
    
    return 0;
}


// �ݹ������ֵ
int Algo_5_17_1(SqList L, int len) {
    int value, max;
    
    // ��ȡ��ǰλ�õ�ֵ
    GetElem(L, len, &value);
    
    if(len == 1) {
        return value;
    }
    
    // ��ȡ��ǰ���е����ֵ
    max = Algo_5_17_1(L, --len);
    
    return max > value ? max : value;
}

// �ݹ�����Сֵ
int Algo_5_17_2(SqList L, int len) {
    int value, min;
    
    // ��ȡ��ǰλ�õ�ֵ
    GetElem(L, len, &value);
    
    if(len == 1) {
        return value;
    }
    
    // ��ȡ��ǰ���е���Сֵ
    min = Algo_5_17_2(L, --len);
    
    return min < value ? min : value;
}

// �ݹ����
int Algo_5_17_3(SqList L, int len) {
    int sum;
    
    // ��ȡ��ǰλ�õ�ֵ
    GetElem(L, len, &sum);
    
    if(len == 1) {
        return sum;
    }
    
    // ��ȡ��ǰ���еĺ�
    sum += Algo_5_17_3(L, --len);
    
    return sum;
}

// �ݹ����
double Algo_5_17_4(SqList L, int len) {
    int value;
    double mul;
    
    // ��ȡ��ǰλ�õ�ֵ
    GetElem(L, len, &value);
    mul = value;
    
    if(len == 1) {
        return mul;
    }
    
    // ��ȡ��ǰ���еĻ�
    mul *= Algo_5_17_4(L, --len);
    
    return mul;
}

// �ݹ���ƽ����
double Algo_5_17_5(SqList L, int len) {
    int value;
    double avg;
    
    // ��ȡ��ǰλ�õ�ֵ
    GetElem(L, len, &value);
    avg = value;
    
    if(len == 1) {
        return avg;
    }
    
    // ��ȡ��ǰ���е�ƽ����
    avg = (Algo_5_17_5(L, len - 1) * (len - 1) + value) / len;
    
    return avg;
}
