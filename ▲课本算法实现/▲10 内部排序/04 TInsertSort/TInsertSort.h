/**********************************
 *                                *
 * 文件夹: ▲10 内部排序          *
 *                                *
 * 文件名: TInsertSort.h          *
 *                                *
 * 内  容: 表插入排序相关操作列表 *
 *                                *
 **********************************/

#ifndef TINSERTSORT_H
#define TINSERTSORT_H

#include "../00 StaticLinkedListType/StaticLinkedListType.c"	//**▲10 内部排序**//

/* 表插入排序函数列表 */
void TInsertSort(SLinkList_sort *L);
/*━━━━━━━━━━━━━━━┓
┃(01)对静态链表L作表插入排序。 ┃
┗━━━━━━━━━━━━━━━*/

void Arrange(SLinkList_sort *L);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法10.3：根据各记录指针，对L中的记录重新排序。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

#endif 
