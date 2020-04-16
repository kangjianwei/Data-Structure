/*==============
 * 伙伴系统
 *
 * 包含算法: 8.2
 ===============*/

#ifndef BUDDYSYSTEM_H
#define BUDDYSYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Status.h"    //**▲01 绪论**//

/* 宏定义 */
#define M 6            // 假设总空间大小为2^M个字，子表个数为M+1


/*
 * 内存"字"的类型定义
 *
 * 所谓"字"是指空间分配的最小单位，它不是字节。
 * 一个"字"有多大，取决于对"字"结构是如何定义的。
 */
typedef struct WORD {
    struct WORD* llink; // 头部域的前驱指针
    struct WORD* rlink; // 头部域的后继指针
    int tag;            // 头部域的块标志，0:空闲，1:占用
    int kval;           // 指示块的大小，比如其值为K时，表示该块的大小为2^K
} WORD;

// 表头向量类型
typedef struct HeadNode {
    int nodesize;   // 该链表的空闲块的大小
    WORD* first;    // 该链表的表头指针
} FreeList[M + 1];


/*
 * 初始化一块大小为2^M个字的内存，并返回指向该内存的起点的指针
 * 注：返回的初始内存已经包含了head。
 */
void InitSpace(FreeList avail);

/*
 * ████████ 算法8.2 ████████
 *
 * 伙伴系统的内存分配算法
 *
 * 从空间avail中申请一块大小至少为n(原始值)的空间，并返回指向申请到的空间的指针。如果分配失败，则返回NULL。
 *
 * 注：
 * 1.这里采用首次拟合法，即一遇到满足条件的内存块就进行分配操作。
 * 2.这里申请分配n个字的空间，指的是用户申请的原始空间。
 *   实际在申请时，还要考虑到每个块前面有1个字的head信息，即经过换算后，实际需要申请(n+1)个字。
 *   这里的n与算法8.1里面的n含义正好相反，需要注意。
 */
WORD* AllocBuddy(FreeList avail, int n);

/*
 * 伙伴系统的内存回收算法
 *
 * 对指针p处的内存进行释放(这类似于free()，只是对内存进行释放操作，至于置空指针p的操作，应交给调用方完成)
 *
 * 注：这里没有验证p的取值，调用方应当确保p在合规的范围
 */
void FreeBuddy(FreeList avail, WORD* p);

/*
 * 打印内存布局，查看当前内存的使用情况
 * 注：仅限内部测试使用
 */
void PrintMemoryLayout();

/*
 * 查找块p的伙伴
 *
 * 将一个空闲块对半分裂后，会生成的两个小空闲块，这两个小空闲块互为伙伴。
 *
 * 计算伙伴的算法为：
 * 对于起始地址为p，大小为2^k的内存块：
 * 1.若 p MOD 2^(k+1) == 0   ,则p的伙伴块的起始地址为p+2^k，
 * 2.若 p MOD 2^(k+1) == 2^k ,则p的伙伴块的起始地址为p-2^k。
 *
 * 注：仅限内部使用，用在回收算法中
 */
static WORD* Buddy(WORD* p);

#endif
