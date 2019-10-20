#include <stdio.h>
#include "Status.h"      //**▲01 绪论**//
#include "LinkList.h"    //**▲02 线性表**//

/*
 * 题2.30
 *
 * A=A-B∩C。
 */
Status Algo_2_30(LinkList La, LinkList Lb, LinkList Lc);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;
    
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {1, 2, 2, 3, 4, 4, 9, 9, 10, 12};
    int c[10] = {1, 1, 2, 2, 3, 3, 4, 5, 12, 13};
    
    // 准备测试数据
    InitList(&La);
    InitList(&Lb);
    InitList(&Lc);
    for(i = 1; i <= 10; i++) {
        ListInsert(La, i, a[i - 1]);
        ListInsert(Lb, i, b[i - 1]);
        ListInsert(Lc, i, c[i - 1]);
    }
    
    printf("La = ");
    ListTraverse(La, PrintElem);
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    // 处理后
    Algo_2_30(La, Lb, Lc);
    
    printf("La = La-Lb∩Lc = ");
    ListTraverse(La, PrintElem);
    
    return 0;
}

// A=A-B∩C
Status Algo_2_30(LinkList La, LinkList Lb, LinkList Lc) {
    LinkList pa, pb, pc, p;
    
    if(La == NULL || Lb == NULL || Lc == NULL) {
        return ERROR;
    }
    
    pa = La->next;
    pb = Lb->next;
    pc = Lc->next;
    p = La;
    
    // 获取B和C的交集，然后将其从A中删除
    while(pa != NULL && pb != NULL && pc != NULL) {
        if(pb->data < pc->data) {
            pb = pb->next;
        } else if(pb->data > pc->data) {
            pc = pc->next;
        } else {
            // 在A中查找交集元素
            while(pa != NULL && pa->data < pb->data) {
                p = pa;
                pa = pa->next;
            }
    
            // 跳过交集元素
            while(pa != NULL && pa->data == pb->data) {
                p->next = pa->next;
                free(pa);
                pa = p->next;
            }
    
            // A还没有遍历完
            if(pa != NULL ) {
                pb = pb->next;
                pc = pc->next;
            }
        }
    }
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%2d ", e);
}
