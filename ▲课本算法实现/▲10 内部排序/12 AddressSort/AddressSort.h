/**************************************
 *                                    *
 * 文件夹: ▲10 内部排序              *
 *                                    *
 * 文件名: AddressSort.h              *
 *                                    *
 * 内  容: 顺序表地址排序相关操作列表 *
 *                                    *
 **************************************/

#ifndef ADDRESSSORT_H
#define ADDRESSSORT_H

#include <limits.h>
#include "../00 SequenceListType/SequenceListType.c"	//**▲10 内部排序**//

/* 顺序表地址排序函数列表 */
void AddressSort(SqList_sort *L);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(01)对顺序表L按关键字大小进行地址排序。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

void Rearrange(SqList_sort *L, int adr[]);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法10.18：根据各记录地址，对L中的记录重新排序。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

#endif 
