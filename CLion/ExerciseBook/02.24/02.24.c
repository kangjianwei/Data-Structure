#include <stdio.h>
#include "Status.h"      //**▲01 绪论**//
#include "LinkList.h"    //**▲02 线性表**//

/*
 * 题2.24
 *
 * 归并两个递增单链表为一个递减单链表。
 * 归并策略是：逐个摘下La和Lb中的元素，并使用头插法插入到Lc中
 * 归并完成后，将原表置空，但不销毁。
 */
Status Algo_2_24(LinkList La, LinkList Lb, LinkList* Lc);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;
    
    // 0号单元存储的是数组长度
    int a[] = {10, 1, 3, 5, 7,  9, 11, 13, 15, 17, 19};
    int b[] = {8,  2, 3, 6, 7, 10, 15, 17, 20};
    
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
    Algo_2_24(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}


// 归并两个递增单链表为一个递减单链表
Status Algo_2_24(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList pa, pb;
    
    // 初始化Lc
    InitList(Lc);
    
    // 确保La和Lb存在
    if(La == NULL || Lb == NULL) {
        return ERROR;
    }
    
    // 遍历La和Lb
    while(La->next!=NULL && Lb->next!=NULL){
        pa = La->next;
        pb = Lb->next;
    
        // 摘下La中较小的元素
        if(pa->data<=pb->data) {
            La->next = pa->next;
            
            // 将摘下的元素通过头插法插入到Lc
            pa->next = (*Lc)->next;
            (*Lc)->next = pa;
    
            // 摘下Lb中较小的元素
        } else {
            Lb->next = pb->next;
    
            // 将摘下的元素通过头插法插入到Lc
            pb->next = (*Lc)->next;
            (*Lc)->next = pb;
        }
    }
    
    // 如果La还有剩余，将La中剩余元素插入到Lc中
    while(La->next!=NULL){
        pa = La->next;
        La->next = pa->next;
        
        pa->next = (*Lc)->next;
        (*Lc)->next = pa;
    }
    
    // 如果Lb还有剩余，将Lb中剩余元素插入到Lc中
    while(Lb->next!=NULL){
        pb = Lb->next;
        Lb->next = pb->next;
        
        pb->next = (*Lc)->next;
        (*Lc)->next = pb;
    }

    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%2d ", e);
}
