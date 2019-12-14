#include <stdio.h>

/*
 * 题1.16
 *
 * 将3个整数按从大到小顺序输出
 */
void Algo_1_16(int *x, int *y, int *z);


int main(int argc, char* argv[]) {
    int x, y, z;
    
    x = 3;
    y = 7;
    z = 1;
    
    printf("作为示范，设定输入为：%d %d %d...\n", x, y, z);
    
    // 进行排序
    Algo_1_16(&x, &y, &z);
    
    printf("将其从大到小排序后为：%d %d %d...\n", x, y, z);
    
    return 0;
}


// 将3个整数按从大到小顺序输出
void Algo_1_16(int *x, int *y, int *z) {
    int tmp;
    
    // 确保x>=y
    if(*x < *y) {
        tmp = *x;
        *x = *y;
        *y = tmp;
    }
    
    // 确保z>=y
    if(*y < *z) {
        tmp = *y;
        *y = *z;
        *z = tmp;
    }
    
    // 确保x>=z
    if(*x < *z) {
        tmp = *x;
        *x = *z;
        *z = tmp;
    }
}
