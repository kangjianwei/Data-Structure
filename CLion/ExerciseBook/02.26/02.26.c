#include <stdio.h>
#include "Status.h"      //**▲01 绪论**//
#include "LinkList.h"    //**▲02 线性表**//

/*
 * 题2.26
 *
 * 求交集：C=A∩B。
 */
Status Algo_2_26(LinkList La, LinkList Lb, LinkList* Lc);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;
    
    int a[10] = {1, 2, 2, 3, 4, 4, 9, 9, 10, 12};
    int b[10] = {1, 1, 2, 2, 3, 3, 4, 5, 12, 13};
    
    // 准备测试数据
    InitList(&La);
    InitList(&Lb);
    for(i = 1; i <= 10; i++) {
        ListInsert(La, i, a[i - 1]);
        ListInsert(Lb, i, b[i - 1]);
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

// 求交集：C=A∩B
Status Algo_2_26(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList pa, pb, pc, s;
    
    // 确保La和Lb存在
    if(La == NULL || Lb == NULL) {
        return ERROR;
    }
    
    InitList(Lc);
    
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
            // Lc中元素可能重复
            s = (LinkList) malloc(sizeof(LNode));
            if(s == NULL) {
                exit(OVERFLOW);
            }
            s->data = pa->data;
            s->next = NULL;
            
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
    printf("%d ", e);
}
