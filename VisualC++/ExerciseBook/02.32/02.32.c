#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 链表元素类型定义 */
typedef int ElemType;

// 双循环链表结构体
typedef struct LNode {
    ElemType data;
    struct LNode* next;
    struct LNode* pre;
} LNode;

// 指向链表结点的指针
typedef LNode* LinkList;


/*
 * 题2.32
 *
 * 将单向循环链表修改为双向循环链表
 */
Status Algo_2_32(LinkList L);

// 用指定的数据创建【有】头结点的单向循环链表
Status CreatList(LinkList* L, ElemType elems[], int n);

// 正向输出链表
void Output(LinkList L);

// 反向输出链表
void OutputReverse(LinkList L);


int main(int argc, char* argv[]) {
    LinkList L;
    ElemType a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // 准备测试数据，并正序输出
    CreatList(&L, a, 10);
    printf("L = ");
    Output(L);
    
    // 变为双向链表
    Algo_2_32(L);
    
    // 逆序输出链表
    printf("L = ");
    OutputReverse(L);
    
    return 0;
}


// 将单向循环链表修改为双向循环链表
Status Algo_2_32(LinkList L) {
    LinkList r;
    
    if(L==NULL || L->next==L) {
        return ERROR;
    }
    
    for(r = L; r->next != L; r = r->next) {
        r->next->pre = r;
    }
    
    L->pre = r;
    
    return OK;
}

// 用指定的数据创建【有】头结点的单向循环链表
Status CreatList(LinkList* L, ElemType elems[], int n) {
    LinkList s, r;
    int i;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // 初始化头结点
    (*L) = (LinkList) malloc(sizeof(LNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    (*L)->pre = NULL;
    (*L)->next = *L;
    
    for(i = 0, r = *L; i < n; i++) {
        s = (LinkList) malloc(sizeof(LNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->data = elems[i];
        s->pre = NULL;
        
        s->next = r->next;
        r->next = s;
        r = r->next;
    }
    
    return OK;
}

// 正向输出链表
void Output(LinkList L) {
    LinkList p;
    
    if(L == NULL || L->next == L) {
        return;
    }
    
    for(p = L->next; p != L; p = p->next) {
        printf("%2d ", p->data);
    }
    
    printf("\n");
}

// 反向输出链表
void OutputReverse(LinkList L) {
    LinkList p;
    
    if(L == NULL || L->pre == L) {
        return;
    }
    
    for(p = L->pre; p != L; p = p->pre) {
        printf("%2d ", p->data);
    }
    
    printf("\n");
}
