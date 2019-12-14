/********************************
 *                              *
 * 文件夹: ▲10 内部排序        *
 *                              *
 * 文件名: MergingSort.h        *
 *                              *
 * 内  容: 归并排序相关操作列表 *
 *                              *
 ********************************/

#ifndef MERGINGSORT_H
#define MERGINGSORT_H

#include "../00 SequenceListType/SequenceListType.c"	//**▲10 内部排序**//

/* 归并排序函数列表 */
void Merge(RcdType SR[], RcdType TR[], int i, int m, int n);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法10.12：将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void MSort(RcdType SR[], RcdType TR[], int s, int t);
/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法10.13：将SR[s..t]归并排序为TR[s..t]。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/

void MergeSort(SqList_sort *L);
/*━━━━━━━━━━━━━━━━━━┓
┃(03)算法10.14：对顺序表L作归并排序。┃
┗━━━━━━━━━━━━━━━━━━*/

#endif 
