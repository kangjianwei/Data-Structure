#include <stdio.h>
#include "LinkList.h"    //**▲02 线性表**//

/*
 * 题2.28
 *
 * 求交集：C=A∩B。
 * 不允许C中的元素重复，且C会利用A原有的空间，A被销毁。
 */
LinkList Algo_2_28(LinkList* La, LinkList Lb);

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
    Lc = Algo_2_28(&La, Lb);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}


LinkList Algo_2_28(LinkList* La, LinkList Lb) {
    LinkList Lc;
    LinkList pa, pb, pc, s;
    
    // 确保La和Lb存在
    if(La == NULL || *La == NULL || Lb == NULL) {
        return NULL;
    }
    
    pa = (*La)->next;
    pb = Lb->next;
    
    Lc = *La;
    Lc->next = NULL;
    pc = Lc;
    
    // 只遍历La和Lb的共同部分就行
    while(pa != NULL && pb != NULL) {
        if(pa->data < pb->data) {
            s = pa;
            pa = pa->next;
            free(s);
        } else if(pa->data > pb->data) {
            pb = pb->next;
        } else {
            // 确保Lc中的元素不重复
            if(pc == Lc || pc->data != pa->data) {
                pc->next = pa;
                pc = pc->next;
            }
            
            pa = pa->next;
            pb = pb->next;
        }
    }
    
    pc->next = NULL;
    
    
    *La = NULL;
    
    return Lc;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}
