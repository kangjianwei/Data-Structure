/************************************
 *							        *
 * 文件夹: ▲02 线性表\05 MergeList *
 * 							        *
 * 文件名: MergeList.h              *
 * 							        *
 * 内  容: 单链表归并相关操作列表   *
 *                                  *
 ************************************/

#ifndef MERGELIST_H
#define MERGELIST_H

#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 单链表归并函数列表 */
void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc);
/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法2.12：C=A+B，且保持元素相对位置不变。   ┃
┃    Lc利用La的头结点，Lb中结点均插入新链表Lc中。┃    
┗━━━━━━━━━━━━━━━━━━━━━━━━*/

#endif
