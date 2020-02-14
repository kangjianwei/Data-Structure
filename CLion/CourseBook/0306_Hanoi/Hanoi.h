/*==============
 * 汉诺塔
 *
 * 包含算法: 3.5
 ===============*/

#ifndef HANOI_H
#define HANOI_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define N 5         // 汉诺塔中盘子总数

// 汉诺塔图形信息
typedef struct {
    int** plates;   // 汉诺塔中的圆盘信息
    int high[3];    // 三座塔的高度（持有的盘子数量）
} Tower;


/*
 * ████████ 算法3.5 ████████
 *
 * 汉诺塔求解：以y塔为辅助，将x塔上前n个圆盘移动到z塔
 */
void hanoi(int n, char x, char y, char z);

/*
 * 移动汉诺塔圆盘：将第n个圆盘从x塔移到z塔。
 */
void move(char x, int n, char z);

/*
 * 汉诺塔图形信息初始化
 *
 *【注】
 * 教材中无此操作。
 * 增加此操作的目的是为了便于观察汉诺塔圆盘的移动过程
 */
void init(int n);

/*
 * 汉诺塔移动的图形表示，参数含义参见move()函数
 *
 *【注】
 * 教材中无此操作。
 * 增加此操作的目的是为了便于观察汉诺塔圆盘的移动过程
 */
void PrintGraph(char x, int n, char z);

#endif
