/************************************
 *                                  *
 * 文件夹: ▲10 内部排序            *
 *                                  *
 * 文件名: SelectSort.h             *
 *                                  *
 * 内  容: 简单选择排序相关操作列表 *
 *                                  *
 ************************************/

#ifndef SELECTSORT_H
#define SELECTSORT_H

#include "../00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 简单选择排序函数列表 */
void SelectSort(SqList_sort *L);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法10.9：对顺序表L作简单选择排序。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

int SelectMinKey(SqList_sort L, int i);
/*━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)在L.r[i..L.length]中选择key最小的记录。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━*/

#endif 
