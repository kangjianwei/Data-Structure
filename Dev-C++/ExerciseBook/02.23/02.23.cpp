#include <stdio.h>
#include "Status.h"      //**▲01 绪论**//
#include "LinkList.h"    //**▲02 线性表**//

/*
 * 题2.23
 *
 * 方法一：将La中的元素插入到Lb中，然后让Lc指向Lb
 *
 * 交错归并两个单链表，新链表使用原链表的存储空间。
 */
Status Algo_2_23_1(LinkList La, LinkList Lb, LinkList* Lc);

/*
 * 题2.23
 *
 * 方法二：将La和Lb中的元素交替摘下，并将其插入到Lc中
 *
 * 交错归并两个单链表，新链表使用原链表的存储空间。
 */
Status Algo_2_23_2(LinkList La, LinkList Lb, LinkList* Lc);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;

    // 0号单元存储的是数组长度
    int a[] = {10, 1, 3, 5, 7,  9, 11, 13, 15, 17, 19};
    int b[] = { 8, 2, 4, 6, 8, 10, 12, 14, 16};

    // 准备测试数据
    InitList(&La);
    InitList(&Lb);
    for(i = 1; i <= a[0]; i++) {
        ListInsert(La, i, a[i]);
    }
    for(i = 1; i <= b[0]; i++) {
        ListInsert(Lb, i, b[i]);
    }
    printf("La = ");
    ListTraverse(La, PrintElem);
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);

    // 归并方法测试
//    Algo_2_23_1(La, Lb, &Lc);
    Algo_2_23_2(La, Lb, &Lc);

    printf("Lc = ");
    ListTraverse(Lc, PrintElem);

    return 0;
}


/*
 * 题2.23
 *
 * 方法一：将La中的元素插入到Lb中，然后让Lc指向Lb
 *
 * 交错归并两个单链表，新链表使用原链表的存储空间。
 */
Status Algo_2_23_1(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList p, pb;

    // 初始化Lc
    InitList(Lc);
    
    // 确保La和Lb存在
    if(La == NULL || Lb == NULL) {
        return ERROR;
    }
    
    pb = Lb;

    // 先遍历La和Lb的共同部分
    while(La->next != NULL && pb->next != NULL) {
        // 从La中摘下结点
        p = La->next;
        La->next = p->next;

        // 将La中摘下的结点插入到Lb中
        p->next = pb->next;
        pb->next = p;

        // 前进到原Lb中下一个结点的位置
        pb = pb->next->next;
    }

    // 如果La有剩余，但Lb已遍历到尽头，则需要将La中剩余元素整体链接到Lb的尾部
    if(pb->next == NULL && La->next != NULL) {
        pb->next = La->next;
        La->next = NULL;
    }

    // 让Lc指向Lb的链表
    (*Lc)->next = Lb->next;
    Lb->next = NULL;

    return OK;
}

/*
 * 题2.23
 *
 * 方法二：将La和Lb中的元素交替摘下，并将其插入到Lc中
 *
 * 交错归并两个单链表，新链表使用原链表的存储空间。
 */
Status Algo_2_23_2(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList p, pc;
    int flag;   // 指挥当前应当摘下La中的元素还是摘下Lb中的元素

    // 初始化Lc
    InitList(Lc);

    // 确保La和Lb存在
    if(La == NULL || Lb == NULL) {
        return ERROR;
    }

    flag = 0;
    pc = *Lc;

    // 先遍历La和Lb的共同部分
    while(La->next!=NULL && Lb->next!=NULL){
        // 摘下La中的元素
        if(flag==0) {
            // 摘下La中的元素
            p = La->next;
            La->next = p->next;

            flag = 1;

            // 摘下La中的元素
        } else {
            p = Lb->next;
            Lb->next = p->next;

            flag = 0;
        }

        // 将摘下的元素插入到Lc
        pc->next = p;
        pc = pc->next;
    }

    // 如果La已经遍历到尽头(Lb可能有剩余)
    if(La->next==NULL) {
        // 摘下Lb中可能剩余的所有元素
        p = Lb->next;
        Lb->next = NULL;
        pc->next = p;

        // 如果La有剩余(Lb一定遍历到尽头了，否则上面的while循环会继续执行)
    } else {
        // 摘下La中剩余的元素
        p = La->next;
        La->next = NULL;
        pc->next = p;
    }

    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%2d ", e);
}

