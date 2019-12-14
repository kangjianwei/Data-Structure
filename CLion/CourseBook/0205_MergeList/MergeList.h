/*===============
 * 归并非降序链表
 *
 * 包含算法: 2.12
 ================*/

#ifndef MERGELIST_H
#define MERGELIST_H

#include <stdio.h>
#include <stdlib.h>      //提供malloc、realloc、free、exit原型
#include "LinkList.h"    //**▲02 线性表**//

/*
 * ████████ 算法2.12 ████████
 *
 * 非递减链表归并：C=A+B
 *
 * 将链表A和B归并为C，且保持元素相对位置不变。
 * Lc利用La的头结点，Lb中结点均插入新链表Lc中。
 */
void MergeList(LinkList* La, LinkList* Lb, LinkList* Lc);

#endif
