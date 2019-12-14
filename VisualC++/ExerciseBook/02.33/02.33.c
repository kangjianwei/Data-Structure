#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <ctype.h>      // 提供isalpha、isdigit原型
#include "Status.h"     //**▲01 绪论**//

/* 链表元素类型定义 */
typedef char ElemType;

// 单循环链表结构体
typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode;

// 指向链表结点的指针
typedef LNode* LinkList;


/*
 * 题2.33
 *
 * 拆分链表，拆成字符、数字、其他三类
 */
Status Algo_2_33(LinkList L, LinkList* L_char, LinkList* L_num, LinkList* L_other);

// 初始化一个单向循环链表
Status InitList(LinkList* L);

// 用指定的数据创建【有】头结点的单向循环链表
Status CreatList(LinkList* L, ElemType elems[], int n);

// 正向输出链表
void Output(LinkList L);


int main(int argc, char* argv[]) {
    LinkList L, L_char, L_num, L_other;
    
    ElemType a[20+1] = "2a3@A5e$T*1%s&7pl(o)";
    
    // 准备测试数据，并正序输出
    CreatList(&L, a, 20);
    printf("L = ");
    Output(L);
    
    // 拆分链表
    Algo_2_33(L, &L_char, &L_num, &L_other);
    
    // 输出拆分后的链表
    printf("L_char  = ");
    Output(L_char);
    printf("L_num   = ");
    Output(L_num);
    printf("L_other = ");
    Output(L_other);
    
    return 0;
}


// 拆分链表，拆成字符、数字、其他三类
Status Algo_2_33(LinkList L, LinkList* L_char, LinkList* L_num, LinkList* L_other) {
    LinkList r, rc, rn, ro, s;
    
    if(L_char == NULL || L_num == NULL || L_other == NULL) {
        return ERROR;
    }
    
    if(L == NULL || L->next == L) {
        return ERROR;
    }
    
    InitList(L_char);
    InitList(L_num);
    InitList(L_other);
    
    r = L->next;
    rc = *L_char;
    rn = *L_num;
    ro = *L_other;
    
    while(r != L) {
        s = (LinkList) malloc(sizeof(LNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->data = r->data;
        
        // 元素为字符
        if(isalpha(r->data)) {
            s->next = rc->next;
            rc->next = s;
            rc = rc->next;
            
            // 元素为数字
        } else if(isdigit(r->data)) {
            s->next = rn->next;
            rn->next = s;
            rn = rn->next;
            
            // 其它
        } else {
            s->next = ro->next;
            ro->next = s;
            ro = ro->next;
        }
        
        r = r->next;
    }
    
    return OK;
}


// 初始化一个单向循环链表
Status InitList(LinkList* L) {
    if(L == NULL) {
        return ERROR;
    }
    
    (*L) = (LinkList) malloc(sizeof(LNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    (*L)->next = *L;
    
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
    (*L)->next = *L;
    
    for(i = 0, r = *L; i < n; i++) {
        s = (LinkList) malloc(sizeof(LNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->data = elems[i];
        
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
        printf("%c ", p->data);
    }
    
    printf("\n");
}
