#include <stdio.h>
#include <stdlib.h>     // 提供 system、rand、srand 原型
#include <time.h>       // 提供 time 原型
#include "SqList.h"     //**▲02 线性表**//

// 递归求最大值
int Algo_5_17_1(SqList L, int len);

// 递归求最小值
int Algo_5_17_2(SqList L, int len);

// 递归求和
int Algo_5_17_3(SqList L, int len);

// 递归求积
double Algo_5_17_4(SqList L, int len);

// 递归求平均数
double Algo_5_17_5(SqList L, int len);


int main(int argc, char* argv[]) {
    SqList L;
    int i;
    
    InitList(&L);
    
    srand((unsigned) time(NULL));   // 用系统时间做随机数种子
    
    for(i = 1; i <= 10; i++) {
        ListInsert(&L, i, rand() % 100);
    }
    
    printf("顺序表中的数字序列为：");
    for(i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
    
    printf("顺序表中的最大值为： %d \n", Algo_5_17_1(L, L.length));
    printf("顺序表中的最小值为： %d \n", Algo_5_17_2(L, L.length));
    printf("顺序表中的和为： %d \n", Algo_5_17_3(L, L.length));
    printf("顺序表中的积为： %.2f \n", Algo_5_17_4(L, L.length));
    printf("顺序表中的平均值为： %.2f \n", Algo_5_17_5(L, L.length));
    
    return 0;
}


// 递归求最大值
int Algo_5_17_1(SqList L, int len) {
    int value, max;
    
    // 获取当前位置的值
    GetElem(L, len, &value);
    
    if(len == 1) {
        return value;
    }
    
    // 获取先前序列的最大值
    max = Algo_5_17_1(L, --len);
    
    return max > value ? max : value;
}

// 递归求最小值
int Algo_5_17_2(SqList L, int len) {
    int value, min;
    
    // 获取当前位置的值
    GetElem(L, len, &value);
    
    if(len == 1) {
        return value;
    }
    
    // 获取先前序列的最小值
    min = Algo_5_17_2(L, --len);
    
    return min < value ? min : value;
}

// 递归求和
int Algo_5_17_3(SqList L, int len) {
    int sum;
    
    // 获取当前位置的值
    GetElem(L, len, &sum);
    
    if(len == 1) {
        return sum;
    }
    
    // 获取先前序列的和
    sum += Algo_5_17_3(L, --len);
    
    return sum;
}

// 递归求积
double Algo_5_17_4(SqList L, int len) {
    int value;
    double mul;
    
    // 获取当前位置的值
    GetElem(L, len, &value);
    mul = value;
    
    if(len == 1) {
        return mul;
    }
    
    // 获取先前序列的积
    mul *= Algo_5_17_4(L, --len);
    
    return mul;
}

// 递归求平均数
double Algo_5_17_5(SqList L, int len) {
    int value;
    double avg;
    
    // 获取当前位置的值
    GetElem(L, len, &value);
    avg = value;
    
    if(len == 1) {
        return avg;
    }
    
    // 获取先前序列的平均数
    avg = (Algo_5_17_5(L, len - 1) * (len - 1) + value) / len;
    
    return avg;
}
