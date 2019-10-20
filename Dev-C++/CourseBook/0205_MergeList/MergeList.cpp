/*===============
 * 归并非降序链表
 *
 * 包含算法: 2.12
 ================*/

#include "MergeList.h"                    //**▲02 线性表**//

/*
 * ████████ 算法2.12 ████████
 *
 * 非递减链表归并：C=A+B
 *
 * 将链表A和B归并为C，且保持元素相对位置不变。
 * Lc利用La的头结点，Lb中结点均插入新链表Lc中。
 */
void MergeList(LinkList* La, LinkList* Lb, LinkList* Lc) {
    LinkList pa, pb, pc;
    
    pa = (*La)->next;
    pb = (*Lb)->next;
    pc = *Lc = *La;                        // 用La的头结点作为Lc的头结点
    
    // 遍历La和Lb
    while(pa && pb) {
        if(pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    
    // 插入剩余段
    pc->next = pa ? pa : pb;
    
    // 释放Lb的头结点所占内存
    free(*Lb);
    
    *La = NULL;
    *Lb = NULL;
}
