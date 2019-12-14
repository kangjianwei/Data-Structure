/************************************
 *                                  *
 * 文件夹: ▲10 内部排序            *
 *                                  *
 * 文件名: ShellSort.h              *
 *                                  *
 * 内  容: 希尔插入排序相关操作列表 *
 *                                  *
 ************************************/

#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "../00 SequenceListType/SequenceListType.c"	//**▲10 内部排序**//

/* 全局变量 */
int t = 3;												//增量序列容量 
int dlta[] = {5, 3, 1};									//增量序列 

/* 希尔插入排序函数列表 */
void ShellInsert(SqList_sort *L, int dk);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法10.4：对顺序表做一趟希尔插入排序。┃
┗━━━━━━━━━━━━━━━━━━━━━*/

void ShellSort(SqList_sort *L, int dlta[], int t);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法10.5：按增量序列dlta[0..t-1]对顺序表L作希尔插入排序。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

#endif 
