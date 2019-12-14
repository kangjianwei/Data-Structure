/********************************
 *                              *
 * 文件夹: ▲10 内部排序        *
 *                              *
 * 文件名: QuickSort.h          *
 *                              *
 * 内  容: 快速排序相关操作列表 *
 *                              *
 ********************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "../00 SequenceListType/SequenceListType.c"	//**▲10 内部排序**//

/* 快速排序函数列表 */
int Partition_1(SqList_sort *L, int low, int high);
/*━━━━━━━━━━━━━━━━━━┓
┃(01)算法10.6(a)：完成一趟快速排序。 ┃
┗━━━━━━━━━━━━━━━━━━*/

int Partition_2(SqList_sort *L, int low, int high);
/*━━━━━━━━━━━━━━━━━━┓
┃(02)算法10.6(b)：完成一趟快速排序。 ┃
┗━━━━━━━━━━━━━━━━━━*/

void QSort(SqList_sort *L, int low, int high);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(03)算法10.8：对顺序表L中的子序列L.r[low..high]作快速排序。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void QuickSort(SqList_sort *L);
/*━━━━━━━━━━━━━━━━━━┓
┃(04)算法10.7：对顺序表L作快速排序。 ┃
┗━━━━━━━━━━━━━━━━━━*/

#endif 
