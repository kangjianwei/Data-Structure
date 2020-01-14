/*===============
 * 归并非降序链表
 *
 * 包含算法: 2.21
 ================*/

#ifndef MERGEELIST_H
#define MERGEELIST_H

#include <stdio.h>
#include "Status.h"         //**▲01 绪论**//
#include "ELinkList.h"      //**▲02 线性表**//

/*
 * ████ 注意 ████
 *
 * 为了与之前的归并算法名称区分，这里将算法名称命名为MergeEList(教材中的名称是MergeList_L)
 */

/*
 * ████████ 算法2.21 ████████
 *
 * 非递减链表归并：C=A+B
 *
 * 将链表A和B归并为C，且保持元素相对位置不变。
 * 归并结束后，会销毁La和Lb。
 */
Status MergeEList(ELinkList* La, ELinkList* Lb, ELinkList* Lc, int(Compare)(ElemType, ElemType));

#endif

