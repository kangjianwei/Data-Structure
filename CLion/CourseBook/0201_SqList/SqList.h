/*=============================
 * 线性表的顺序存储结构（顺序表）
 *
 * 包含算法: 2.3、2.4、2.5、2.6
 =============================*/

#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

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
    int length;   // 当前顺序表长度（包含多少元素）
    int listsize; // 当前分配的存储容量（可以存储多少元素）
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
 * 销毁(结构)
 *
 * 释放顺序表所占内存。
 */
Status DestroyList(SqList* L);

/*
 * 置空(内容)
 *
 * 只是清理顺序表中存储的数据，不释放顺序表所占内存。
 */
Status ClearList(SqList* L);

/*
 * 判空
 *
 * 判断顺序表中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 顺序表为空
 * FALSE: 顺序表不为空
 */
Status ListEmpty(SqList L);

/*
 * 计数
 *
 * 返回顺序表包含的有效元素的数量。
 */
int ListLength(SqList L);

/*
 * 取值
 *
 * 获取顺序表中第i个元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数，但这不符合编码的通用约定。
 * 通常，i的含义应该指索引，即从0开始计数。
 */
Status GetElem(SqList L, int i, ElemType* e);

/*
 * ████████ 算法2.6 ████████
 *
 * 查找
 *
 * 返回顺序表中首个与e满足Compare关系的元素位序。
 * 如果不存在这样的元素，则返回0。
 *
 *【备注】
 * 元素e是Compare函数第二个形参
 */
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 * 前驱
 *
 * 获取元素cur_e的前驱，
 * 如果存在，将其存储到pre_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e);

/*
 * 后继
 *
 * 获取元素cur_e的后继，
 * 如果存在，将其存储到next_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e);

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
 * ████████ 算法2.5 ████████
 *
 * 删除
 *
 * 删除顺序表第i个位置上的元素，并将被删除元素存储到e中。
 * 删除成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListDelete(SqList* L, int i, ElemType* e);

/*
 * 遍历
 *
 * 用visit函数访问顺序表L
 */
void ListTraverse(SqList L, void (Visit)(ElemType));

#endif
