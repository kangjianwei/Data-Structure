/*===================
 * 冪集
 *
 * 包含算法: 6.14/6.15
 ====================*/

#ifndef POWERSET_H
#define POWERSET_H

#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "LinkList.h"   //**▲02 线性表**//

/*
 * 冪集中的集合定义，这里使用了线性表。
 * 冪集元素类型也与线性表元素类型一致。
 */
typedef LinkList List;

/*
 * 创建集合A，集合元素类型与线性表元素类型一致。
 */
Status CreatePowerSet(List* A, char* path);

/*
 * ████████ 6.14/6.15 ████████
 *
 * 求取集合A的幂集，集合B用来暂存每一次求出的幂集子集。
 */
void GetPowerSet(int i, List A, List B);

/*
 * 输出当前集合。
 */
void PrintPowerSet(List A);


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建集合的内部函数
static void Create(List* A, FILE* fp);

#endif
