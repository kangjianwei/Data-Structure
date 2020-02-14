/*==================
 * 归并非降序顺序表
 *
 * 包含算法: 2.2、2.7
 ===================*/

#ifndef MERGESQLIST_H
#define MERGESQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"        //**▲02 线性表**//

/*
 * ████████ 算法2.2 ████████
 *
 * 非递减链表归并：C=A+B
 *
 * 归并顺序表La和Lb，生成新的顺序表Lc。
 * 其中，La、Lb、Lc均为非递减序列。
 */
void MergeSqList_1(SqList La, SqList Lb, SqList* Lc);

/*
 * ████████ 算法2.7 ████████
 *
 * 非递减链表归并：C=A+B
 *
 * 归并顺序表La和Lb，生成新的顺序表Lc。
 * 其中，La、Lb、Lc均为非递减序列。
 */
void MergeSqList_2(SqList La, SqList Lb, SqList* Lc);

#endif
