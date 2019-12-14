#include <stdio.h>
#include "Status.h"         //**▲01 绪论**//
#include "DuLinkList.h"     //**▲02 线性表**//

/*
 * 题2.37
 *
 * 按奇偶次序重排链表各元素位序：奇数位序元素靠前正序，偶数位序元素靠后逆序
 */
Status Algo_2_37(DuLinkList L);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    DuLinkList L;
    int i;
    
    // 准备测试数据
    InitList(&L);
    for(i = 1; i <= 10; i++) {
        ListInsert(L, i, i);
    }
    printf("重排前 L = ");
    ListTraverse(L, PrintElem);
    
    Algo_2_37(L);
    
    printf("重排后 L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}


// 按奇偶次序重排链表各元素位序：奇数位序元素靠前正序，偶数位序元素靠后逆序
Status Algo_2_37(DuLinkList L) {
    DuLinkList head, tail, p;
    
    if(L == NULL || L->prior == NULL || L->next == NULL) {
        return ERROR;
    }
    
    head = L->next;                // 指向表首，向右推进
    tail = L->prior;               // 指向表尾，固定不动
    
    // 如果head跟tail中间至少隔了一个元素
    while(head != tail && head->next != tail) {
        // 指向原偶数位序的元素
        p = head->next;
        
        // 摘下此偶数位序的元素
        p->next->prior = head;
        head->next = p->next;
        
        // 将此元素添加到原tail后面
        p->next = tail->next;
        p->prior = tail;
        tail->next->prior = p;
        tail->next = p;
        
        // 前进到下一个奇数位序的元素上
        head = head->next;
    }
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}
