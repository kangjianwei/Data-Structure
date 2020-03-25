#include <stdio.h>
#include "LinkList.h"    //**▲02 线性表**//

/*
 * 题2.28
 *
 * 求交集：C=A∩B。
 *
 * A和B中元素可能重复，但C中元素不重复。
 * 而且，要求C利用A原有的空间，但是A中的无效结点会被释放。
 */
Status Algo_2_28(LinkList La, LinkList Lb, LinkList* Lc);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;
    
    // 0号单元存储的是数组长度
    int a[] = {10, 1, 1, 1, 7, 7,  9, 10, 18, 18, 19};
    int b[] = {8,  1, 1, 7, 7, 7, 15, 18, 18};
    
    // 准备测试数据，同一表中的元素值可能相同
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
    Algo_2_28(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}


/*
 * 题2.28
 *
 * 求交集：C=A∩B。
 *
 * A和B中元素可能重复，但C中元素不重复。
 * 而且，要求C利用A原有的空间，但是A中的无效结点会被释放。
 */
Status Algo_2_28(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList pa, pb, pc, s;
    
    // 确保La和Lb存在
    if(La == NULL || Lb == NULL) {
        return ERROR;
    }
    
    // Lc利用La的空间
    *Lc = La;
    
    pa = La->next;
    pb = Lb->next;
    pc = *Lc;
    
    // 遍历La和Lb的共同部分
    while(pa != NULL && pb != NULL) {
        if(pa->data < pb->data) {
            pc->next = pa->next;
            free(pa);   // 释放La中的无效结点
            pa = pc->next;
        } else if(pa->data > pb->data) {
            pb = pb->next;
            
            // 遇到交集元素
        } else {
            // 如果Lc不为空，则需要确保Lc中的元素不重复
            if(pc == (*Lc) || pc->data != pa->data) {
                pc = pc->next;  // pc游标直接前进，相当于保留了pa指向的元素
                
                pa = pa->next;
            } else {
                // 如果该交集元素已经存在了，则释放这个结点
                pc->next = pa->next;
                free(pa);   // 释放La中的无效结点
                
                pa = pc->next;
            }
    
            // pb总是照常前进
            pb = pb->next;
        }
    }
    
    // Lc已生成，Lc和La共享一段内存
    pc->next = NULL;

    // 释放La中多余的无效结点
    while(pa!=NULL){
        s = pa;
        pa = pa->next;
        free(s);
    }
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%2d ", e);
}
