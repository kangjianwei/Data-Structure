/*=============================
 * 线性表的顺序存储结构（顺序表）
 *
 * 包含算法: 2.3、2.4、2.5、2.6
 =============================*/

#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"      //**▲01 绪论**//

/* 宏定义 */
#define LIST_INIT_SIZE 100  // 顺序表存储空间的初始分配量
#define LISTINCREMENT  10   // 顺序表存储空间的分配增量

/* 顺序表元素类型定义 */
typedef int ElemType;

/*
 * 顺序表结构
 *
 * 注：elem在使用前需要先为其分配内存，且元素从elem[0]处开始存储
 */
typedef struct {
    ElemType* elem;     // 顺序表存储空间的基址（指向顺序表所占内存的起始位置）
    int length;         // 当前顺序表长度（包含多少元素）
    int listsize;       // 当前分配的存储容量（可以存储多少元素）
} SqList;


/*
 * ████████ 算法2.3 ████████
 *
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(SqList* L);

/*
 * ████████ 算法2.4 ████████
 *
 * 插入
 *
 * 向顺序表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListInsert(SqList* L, int i, ElemType e);

/*
 * 遍历
 *
 * 用visit函数访问顺序表L
 */
void ListTraverse(SqList L, void (Visit)(ElemType));

#endif
