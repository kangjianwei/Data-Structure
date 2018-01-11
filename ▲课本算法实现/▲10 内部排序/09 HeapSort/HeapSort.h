/******************************
 *                            *
 * 文件夹: ▲10 内部排序      *
 *                            *
 * 文件名: HeapSort.h         *
 *                            *
 * 内  容: 堆排序相关操作列表 *
 *                            *
 ******************************/

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "../00 SequenceListType/SequenceListType.c"	//**▲10 内部排序**//

/* 类型定义 */
typedef SqList_sort HeapType;

/* 堆排序函数列表 */
void HeapAdjust(HeapType *H, int s, int m); 
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法10.10：调整H.r[s]的关键字（其他关键字已满足堆的条件），使H.r[s..m]成为一个大顶堆。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void HeapSort(HeapType *H);
/*━━━━━━━━━━━━━━━━━┓
┃(02)算法10.11：对顺序表H作堆排序。┃
┗━━━━━━━━━━━━━━━━━*/

#endif 
