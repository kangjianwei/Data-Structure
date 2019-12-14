#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 双向循环链表元素类型定义 */
typedef int ElemType;

/*
 * 双向循环链表结构，增加了一个访问拼读域
 *
 * 注：这里的双向循环链表存在头结点
 */
typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior;  // 前驱
    struct DuLNode* next;   // 后继
    int freq;               // 访问频度域
} DuLNode;

// 指向双循环链表结构的指针
typedef DuLNode* DuLinkList;

/*
 * 题2.38
 *
 * 查找元素e在首次在L中出现的位序，并按访问频度重排链表。
 */
DuLinkList Algo_2_38(DuLinkList* L, ElemType e);

// 创建双循环链表
Status CreatList(DuLinkList* L, ElemType elems[], int n);

// 正向输出链表
void Output(DuLinkList L);


int main(int argc, char* argv[]) {
    DuLinkList L;
    int i;
    ElemType data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ElemType visit[10] = {1, 2, 2, 2, 3, 4, 4, 5, 5, 9};
    
    CreatList(&L, data, 10);
    printf("访问前： L = \n");
    Output(L);
    
    // 依次访问tmp中预设的数字
    for(i = 0; i < 10; i++) {
        Algo_2_38(&L, visit[i]);
    }
    
    printf("访问后：L = \n");
    Output(L);
    
    return 0;
}

// 查找元素e在首次在L中出现的位序，并按访问频度重排链表
DuLinkList Algo_2_38(DuLinkList* L, ElemType e) {
    DuLinkList pre, r;
    
    // 确保链表存在
    if(L == NULL || *L == NULL) {
        return NULL;
    }
    
    for(pre = *L; pre->next != *L && pre->next->data != e; pre = pre->next) {
        // 查找元素e的前驱
    }
    
    // 没找到满足条件的元素
    if(pre->next == *L) {
        return NULL;
    }
    
    // 摘下元素e
    r = pre->next;
    pre->next = r->next;
    r->next->prior = pre;
    
    // 频度增一
    r->freq++;
    
    for(pre = *L; pre->next != *L && pre->next->freq > r->freq; pre = pre->next) {
        // 根据访问频度，寻找元素e应该插入的位置的前驱
    }
    
    // 将元素e插入到合适的位置
    r->next = pre->next;
    r->prior = pre;
    pre->next->prior = r;
    pre->next = r;
    
    // 返回指向元素e的引用
    return r;
}

// 创建双循环链表
Status CreatList(DuLinkList* L, ElemType elems[], int n) {
    DuLinkList s, p;
    int i;
    
    *L = (DuLinkList) malloc(sizeof(DuLNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    (*L)->data = -1;
    (*L)->prior = *L;
    (*L)->next = *L;
    (*L)->freq = 0;
    
    p = *L;
    
    for(i = 0; i < n; i++) {
        s = (DuLinkList) malloc(sizeof(DuLNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->data = elems[i];
        s->freq = 0;
        
        // 尾插
        s->next = *L;
        (*L)->prior = s;
        s->prior = p;
        p->next = s;
        
        p = p->next;
    }
    
    return OK;
}

// 正向输出链表
void Output(DuLinkList L) {
    DuLinkList p;
    
    if(L == NULL || L->next == L || L->prior == NULL) {
        return;
    }
    
    printf("数据：");
    for(p = L->next; p != L; p = p->next) {
        printf("%2d ", p->data);
    }
    printf("\n");
    
    printf("频度：");
    for(p = L->next; p != L; p = p->next) {
        printf("%2d ", p->freq);
    }
    printf("\n");
}
