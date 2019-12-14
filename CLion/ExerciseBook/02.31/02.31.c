#include <stdio.h>
#include <stdlib.h>     //提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 链表元素类型定义 */
typedef int ElemType;

// 单向循环链表结构（无头结点）
typedef struct LNode {
    ElemType data;      // 数据结点
    struct LNode* next; // 指向下一个结点的指针
} LNode;

// 指向链表结点的指针
typedef LNode* LinkList;


/*
 * 题2.31
 *
 * 删除s结点的前驱
 */
Status Algo_2_31(LinkList* L, LinkList s);

// 用指定的数据创建【无】头结点的单向循环链表
Status CreatList(LinkList* L, ElemType elems[], int n);

// 输出链表L
void Output(LinkList L);


int main(int argc, char* argv[]) {
    LinkList L, s;
    
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // 准备测试数据
    CreatList(&L, a, 10);
    printf("L = ");
    Output(L);
    
    s = L->next->next->next->next;
    
    printf("删除 %d 的前驱后...\n", s->data);
    Algo_2_31(&L, s);
    
    printf("L = ");
    Output(L);
    
    return 0;
}

// 删除s结点的前驱
Status Algo_2_31(LinkList* L, LinkList s) {
    LinkList p, pre;
    
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    // 无前驱
    if(s == NULL || s->next == s) {
        return ERROR;
    }
    
    p = s;
    
    // 使用p->next指向s的前驱
    while(p->next->next != s) {
        p = p->next;
    }
    
    // s的前驱
    pre = p->next;
    
    // 删掉前驱
    p->next = pre->next;
    free(pre);
    
    // 如果前驱正好是
    if(pre == *L) {
        *L = s;
    }
    
    return OK;
}

// 用指定的数据创建无头结点的单向循环链表
Status CreatList(LinkList* L, ElemType elems[], int n) {
    LinkList s, r;
    int i;
    
    if(L == NULL) {
        return ERROR;
    }
    
    *L = NULL;
    
    for(i = 0; i < n; i++) {
        s = (LinkList) malloc(sizeof(LNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        
        s->data = elems[i];
        
        if(i == 0) {
            *L = s;
            s->next = *L;   // 循环
            r = *L;
        } else {
            s->next = r->next;
            r->next = s;
            r = r->next;
        }
    }
    
    return OK;
}

// 输出链表L
void Output(LinkList L) {
    LinkList p;
    
    if(L == NULL) {
        return;
    }
    
    printf("%2d ", L->data);
    
    for(p = L->next; p != L; p = p->next) {
        printf("%2d ", p->data);
    }
    
    printf("\n");
}
