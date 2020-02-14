/*==============
 * 汉诺塔
 *
 * 包含算法: 3.5
 ===============*/

#include "Hanoi.h"                        //**03 栈和队列**//

/* 全局变量 */
Tower T;   // 汉诺塔
int gStep; // 统计移动步数


/*
 * ████████ 算法3.5 ████████
 *
 * 汉诺塔求解：以y为辅助，将x上前n个圆盘移动到z
 */
void hanoi(int n, char x, char y, char z) {
    if(n == 1) {                          // 欲移动n个圆盘，需先移动其上的n-1个圆盘
        move(x, 1, z);                    // 将编号为1的圆盘从x移到z
    } else {
        hanoi(n - 1, x, z, y);            // 将x上编号为1至n-1的圆盘移到y，z作辅助塔
        move(x, n, z);                    // 将编号为n的圆盘从x移到z
        hanoi(n - 1, y, x, z);            // 将y上编号为1至n-1的圆盘移动到z，x作辅助塔
    }
}

void move(char x, int n, char z) {
    // step为全局变量，在main函数之外定义
    gStep++;
    printf("第%2d步：将第 %d 个圆盘从 %c 移到 %c \n", gStep, n, x, z);
    
    // 汉诺塔移动的图形表示
    PrintGraph(x, n, z);
}

/*
 * 汉诺塔图形信息初始化
 *
 *【注】
 * 教材中无此操作。
 * 增加此操作的目的是为了便于观察汉诺塔圆盘的移动过程
 */
void init(int n) {
    int i;
    int* towerX, * towerY, * towerZ;

    T.plates = (int**) malloc(3 * sizeof(int*));
    
    towerX = (int*) malloc(n * sizeof(int));
    towerY = (int*) malloc(n * sizeof(int));
    towerZ = (int*) malloc(n * sizeof(int));
    
    for(i = 0; i < n; ++i) {
        towerX[i] = n-i;
        towerY[i] = 0;
        towerZ[i] = 0;
    }
    
    T.plates[0] = towerX;
    T.plates[1] = towerY;
    T.plates[2] = towerZ;
    
    T.high[0] = n;
    T.high[1] = 0;
    T.high[2] = 0;
    
    // 汉诺塔移动的图形表示
    PrintGraph('\0', 0, '\0');
}

/*
 * 汉诺塔移动的图形表示
 *
 *【注】
 * 教材中无此操作。
 * 增加此操作的目的是为了便于观察汉诺塔圆盘的移动过程
 */
void PrintGraph(char t1, int n, char t2){
    int i, j;
    char** s;
    
    // 将n号盘子从t1中移除
    if(t1=='x') {
        T.plates[0][T.high[0]-1] = 0;
        T.high[0]--;
    } else if(t1=='y') {
        T.plates[1][T.high[1]-1] = 0;
        T.high[1]--;
    } else if(t1=='z') {
        T.plates[2][T.high[2]-1] = 0;
        T.high[2]--;
    } else {
        // t1上的圆盘不需要移动
    }
    
    // 将n号盘子添加到t2中
    if(t2=='x') {
        T.plates[0][T.high[0]] = n;
        T.high[0]++;
    } else if(t2=='y') {
        T.plates[1][T.high[1]] = n;
        T.high[1]++;
    } else if(t2=='z') {
        T.plates[2][T.high[2]] = n;
        T.high[2]++;
    } else {
        // t2上的圆盘不需要移动
    }
    
    s = (char**)malloc((N+2)*sizeof(char*));
    for(i = 0; i<N+2; i++) {
        s[i] = (char*)malloc(N* sizeof(char));
        
        for(j = 0; j < i; j++) {
            if(i==N+1) {
                s[i][j] = '-';  // 将最后一行初始化为托盘
            } else {
                s[i][j] = '*';
            }
        }
        
        if(i==N+1) {
            s[i][j-1] = '\0';
        } else {
            s[i][j] = '\0';
        }
    }
    
    for(i = N-1; i >= 0; i--) {
        printf("%-*s | %-*s | %-*s\n", N, s[T.plates[0][i]], N, s[T.plates[1][i]], N, s[T.plates[2][i]]);
    }
    printf("%-*s + %-*s + %-*s\n", N, s[N+1], N, s[N+1], N, s[N+1]);
    printf("%-*s %-*s %-*s\n", N+2, "x", N+2, "y", N+2, "z");
    
    printf("\n");
}
