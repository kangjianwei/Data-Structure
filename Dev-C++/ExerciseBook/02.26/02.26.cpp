#include <stdio.h>
#include "Status.h"      //**▲01 绪论**//
#include "LinkList.h"    //**▲02 线性表**//

/*
 * 题2.26
 *
 * 求交集：C=A∩B，要求新链表另辟空间。
 */
Status Algo_2_26(LinkList La, LinkList Lb, LinkList* Lc);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;

    // 0号单元存储的是数组长度
    int a[] = {10, 1, 3, 5, 7,  9, 11, 13, 15, 17, 19};
    int b[] = {8,  1, 5, 7, 8, 10, 15, 17, 20};

    // 准备测试数据，同一表中的元素值各不相同
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

    // 求交集
    Algo_2_26(La, Lb, &Lc);

    printf("Lc = ");
    ListTraverse(Lc, PrintElem);

    return 0;
}


// 求交集：C=A∩B，要求新链表另辟空间。
Status Algo_2_26(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList pa, pb, pc, s;

    // 初始化Lc
    InitList(Lc);

    // 确保La和Lb存在
    if(La == NULL || Lb == NULL) {
        return ERROR;
    }

    pa = La->next;
    pb = Lb->next;
    pc = *Lc;

    // 只遍历La和Lb的共同部分就行
    while(pa != NULL && pb != NULL) {
        if(pa->data < pb->data) {
            pa = pa->next;
        } else if(pa->data > pb->data) {
            pb = pb->next;
        } else {
            // 创建新结点存放交集元素
            s = (LinkList) malloc(sizeof(LNode));
            if(s == NULL) {
                exit(OVERFLOW);
            }
            s->data = pa->data;
            s->next = NULL;

            // 将交集元素插入到Lc
            pc->next = s;
            pc = pc->next;

            pa = pa->next;
            pb = pb->next;
        }
    }

    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%2d ", e);
}

