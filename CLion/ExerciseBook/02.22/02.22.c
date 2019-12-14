#include <stdio.h>
#include "Status.h"         //**▲01 绪论**//
#include "LinkList.h"       //**▲02 线性表**//

/*
 * 题2.22
 *
 * 链表逆置。
 */
Status Algo_2_22(LinkList L);

// 测试函数，打印元素
void PrintElem(ElemType e);

int main(int argc, char* argv[]) {
    LinkList L;
    int i;
    
    // 准备测试数据
    InitList(&L);
    for(i = 1; i <= 10; i++) {
        ListInsert(L, i, i);
    }
    
    printf("顺序：L = ");
    ListTraverse(L, PrintElem);
    
    Algo_2_22(L);
    
    printf("逆置：L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}

// 链表逆置
Status Algo_2_22(LinkList L) {
    LinkList p, q;
    
    // 确保链表存在
    if(L==NULL) {
        return ERROR;
    }
    
    p = L->next;
    L->next = NULL;
    
    // 头插法
    while(p!=NULL){
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%2d ", e);
}
