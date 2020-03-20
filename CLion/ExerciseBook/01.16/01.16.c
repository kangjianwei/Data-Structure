#include <stdio.h>

/*
 * 题1.16（直接比较）
 *
 * 将3个整数从大到小排序，约定排序结果为x>y>z
 */
void Algo_1_16_1(int* x, int* y, int* z);

/*
 * 题1.16（冒泡排序）
 *
 * 将3个整数从大到小排序，约定排序结果为x>y>z
 */
void Algo_1_16_2(int* x, int* y, int* z);


int main(int argc, char* argv[]) {
    int x, y, z;
    
    x = 1;
    y = 2;
    z = 3;
    
    printf("作为示范，设定输入为：%d %d %d...\n", x, y, z);
    
    // 进行排序
    Algo_1_16_1(&x, &y, &z);
//    Algo_1_16_2(&x, &y, &z);
    
    printf("将其从大到小排序后为：%d %d %d...\n", x, y, z);
    
    return 0;
}


// 将3个整数从大到小排序，约定排序结果为x>y>z（直接比较）
void Algo_1_16_1(int* x, int* y, int* z) {
    int tmp;
    
    // 1.确保x>=y
    if(*x < *y) {
        tmp = *x;
        *x = *y;
        *y = tmp;
    }
    
    // 2.确保z>=y，这里如果y是小于z的，那么会对y和z的值进行交换
    if(*y < *z) {
        tmp = *y;
        *y = *z;
        *z = tmp;
    }
    
    // 3.如果第2步中发现y<z，则会对y和z的值进行交换，这会导致y的值被更新。
    //   如果y的值发生了更新，这可能会破坏第1步中x>=y的保证，所以此处需要再次验证x与y的关系。
    if(*x < *y) {
        tmp = *x;
        *x = *y;
        *y = tmp;
    }
}

// 将3个整数从大到小排序，约定排序结果为x>y>z（冒泡排序）
void Algo_1_16_2(int* x, int* y, int* z) {
    int tmp;
    int i, j;
    int a[3];
    
    a[0] = *x;
    a[1] = *y;
    a[2] = *z;
    
    // 需要进行2轮比较
    for(i = 1; i <= 2; i++) {
        for(j = 0; j < 3 - i; j++) {
            // 把小的往后挪
            if(a[j] < a[j + 1]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    
    *x = a[0];
    *y = a[1];
    *z = a[2];
}
