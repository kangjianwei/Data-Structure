#include <stdio.h>
#include <stdlib.h>     //提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "LinkList.h"   //**▲02 线性表**//

/*
 * 题2.19———方法一
 *
 * 删除递增线性表中元素值介于(mink, maxk)之间的结点。
 */
Status Algo_2_19_1(LinkList L, int mink, int maxk);

/*
 * 题2.19———方法二
 *
 * 删除递增线性表中元素值介于(mink, maxk)之间的结点。
 */
Status Algo_2_19_2(LinkList L, int mink, int maxk);

/*
 * 题2.20
 *
 * 对非递减线性表去重：对于重复元素，仅保留一个。
 */
Status Algo_2_20(LinkList L);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList L;
    int mink1, mink2, maxk1, maxk2, i;
    int a[] = {1, 2, 2, 3, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 12, 12};
    
    mink1 = 2;
    maxk1 = 4;
    
    mink2 = 5;
    maxk2 = 8;
    
    InitList(&L);
    
    for(i = 1; i <= 20; i++) {
        ListInsert(L, i, a[i - 1]);
    }
    
    printf("█ L = ");
    ListTraverse(L, PrintElem);
    
    printf("████████ 题 2.19 验证...\n");
    printf("█ 删除 (%d, %d) 范围内的元素之后：", mink1, maxk1);
    Algo_2_19_1(L, mink1, maxk1);
    printf("L = ");
    ListTraverse(L, PrintElem);
    
    printf("█ 删除 (%d, %d) 范围内的元素之后：", mink2, maxk2);
    Algo_2_19_2(L, mink2, maxk2);
    printf("L = ");
    ListTraverse(L, PrintElem);
    
    printf("████████ 题 2.20 验证...\n");
    printf("█ 对非递减链表去重之后：");
    Algo_2_20(L);
    printf("L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}


// 删除递增线性表中元素值介于(mink, maxk)之间的结点
Status Algo_2_19_1(LinkList L, int mink, int maxk) {
    LinkList p, q;
    int flag;   // 用来提高效率
    
    // 确保链表存在
    if(L == NULL) {
        return ERROR;
    }
    
    // 范围设定错误
    if(mink >= maxk) {
        return ERROR;
    }
    
    // 链表为空，直接返回
    if(L->next == NULL) {
        return OK;
    }
    
    p = L;      // 指向头结点
    flag = 0;   // 标记未遇到(mink, maxk)范围内的元素
    
    while(p->next != NULL) {
        q = p->next;
        
        // 遇到需要删除的结点
        if(q->data > mink && q->data < maxk) {
            // 标记遇到了(mink, maxk)范围内的元素
            flag = 1;
            p->next = q->next;
            free(q);
        } else {
            // 说明剩余元素均>=maxk，无需再遍历
            if(flag == 1) {
                break;
            }
            p = q;
        }
    }
    
    return OK;
}

// 删除递增线性表中元素值介于(mink, maxk)之间的结点
Status Algo_2_19_2(LinkList L, int mink, int maxk) {
    LinkList p, q;
    
    // 确保链表存在
    if(L == NULL) {
        return ERROR;
    }
    
    // 范围设定错误
    if(mink >= maxk) {
        return ERROR;
    }
    
    // 链表为空，直接返回
    if(L->next == NULL) {
        return OK;
    }
    
    p = L;      // 指向头结点
    
    // 查找下限
    while(p->next != NULL && p->next->data <= mink) {
        p = p->next;
    }
    
    // 遍历完成
    if(p->next == NULL) {
        return OK;
    }
    
    // 查找上限，删除(mink, maxk)之间的部分
    while(p->next != NULL && p->next->data < maxk) {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    
    return OK;
}

// 对非递减线性表去重：对于重复元素，仅保留一个
Status Algo_2_20(LinkList L) {
    LinkList p, q;
    
    // 确保链表存在
    if(L == NULL) {
        return ERROR;
    }
    
    // 链表为空，直接返回
    if(L->next == NULL) {
        return OK;
    }
    
    // 指向第1个元素
    p = L->next;
    
    while(p->next != NULL) {
        q = p->next;
        
        // 遇到了重复元素，则需要删除一个
        if(p->data == q->data) {
            p->next = q->next;
            free(q);
            
            // 如果是不同的元素，则p前进一步
        } else {
            p = q;
        }
    }
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}
