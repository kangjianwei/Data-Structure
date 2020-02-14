#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 单链表元素类型定义 */
typedef int ElemType;

/*
 * 单链表结构
 *
 * 注：这里的单链表【没有】头结点
 */
typedef struct LNode {
    ElemType data;      // 数据结点
    struct LNode* next; // 指向下一个结点的指针
} LNode;

// 指向单链表结点的指针
typedef LNode* LinkList;


/*
 * 题2.16
 *
 * 删除la中第i个位置起的len个元素，并将其添加到lb第j个位置之前。
 */
Status Algo_2_16(LinkList* la, LinkList* lb, int i, int j, int len);

/*
 * 题2.17
 *
 * 将元素b插入到链表L第i个位置上，i是元素的位序，从1开始计数。。
 */
Status Algo_2_17(LinkList* L, int i, ElemType b);

/*
 * 题2.18
 *
 * 删除链表L的第i个结点，i是元素的位序，从1开始计数。
 */
Status Algo_2_18(LinkList* L, int i);

// 初始化无头结点的链表L
void InitList(LinkList* L);

// 输出无头结点的链表中的元素
void Output(LinkList L);


int main(int argc, char* argv[]) {
    int i;
    LinkList la, lb;
    
    InitList(&la);
    InitList(&lb);
    
    printf("████████ 题 2.17 验证...\n");
    for(i = 1; i <= 10; i++) {
        Algo_2_17(&la, i, 2 * i - 1);
        Algo_2_17(&lb, i, 2 * i);
    }
    printf("█ 创建无头结点链表：\n");
    printf("█ la = ");
    Output(la);
    printf("█ lb = ");
    Output(lb);
    PressEnterToContinue(debug);
    
    printf("████████ 题 2.16 验证...\n");
    printf("█ 将la中从第2个结点起的5个结点插入到lb的第6个结点之前...\n");
    Algo_2_16(&la, &lb, 2, 6, 5);
    printf("█ la = ");
    Output(la);
    printf("█ lb = ");
    Output(lb);
    PressEnterToContinue(debug);
    
    printf("████████ 题 2.18 验证...\n");
    printf("█ 删除lb第6个结点起的5个结点...\n");
    for(i = 1; i <= 5; i++) {
        Algo_2_18(&lb, 6);
    }
    printf("█ 删除完成后：lb = ");
    Output(lb);
    
    return 0;
}


// 删除la中第i个位置起的len个元素，并将其添加到lb第j个位置之前
Status Algo_2_16(LinkList* la, LinkList* lb, int i, int j, int len) {
    LinkList p;     // 指向la中第i-1个结点
    LinkList q;     // 指向la中第i+len-1个结点
    LinkList r;     // 指向q后面的结点
    LinkList s;     // 指向lb中第j-1个结点
    int k;
    
    if(i <= 0 || j <= 0 || len <= 0) {
        return ERROR;
    }
    
    // 确保la中有结点可摘
    if(la == NULL || *la == NULL) {
        return ERROR;
    }
    
    
    // 确定p的位置
    k = 1;
    p = *la;
    
    if(i == 1) {
        p = NULL;
    } else {
        // 查找la中第i-1个结点，且保证它后继存在
        while(p->next != NULL && k < i - 1) {
            ++k;
            p = p->next;
        }
        
        // 未找到合适的位置
        if(p->next == NULL) {
            return ERROR;
        }
    }
    
    
    // 确定q的位置
    if(p == NULL) {
        q = *la;
    } else {
        q = p->next;
    }
    k = i;
    
    while(q != NULL && k < i + len - 1) {
        ++k;
        q = q->next;
    }
    
    if(q == NULL) {
        return ERROR;
    }
    
    // 确定r的位置
    r = q->next;
    
    
    if(lb == NULL) {
        return ERROR;
    }
    
    // 确定s的位置
    k = 1;
    s = *lb;
    
    // 插入到lb第一个位置之前
    if(j == 1) {
        q->next = *lb;
        
        if(p == NULL) {
            *lb = *la;
            *la = r;
        } else {
            *lb = p->next;
            p->next = r;
        }
    } else {
        // 查找lb中第j-1个结点，且保证它后继存在
        while(s->next != NULL && k < j - 1) {
            ++k;
            s = s->next;
        }
        
        // 未找到合适的位置
        if(s->next == NULL) {
            return ERROR;
        }
    
        q->next = s->next;
    
        if(p == NULL) {
            *lb = *la;
            *la = r;
        } else {
            s->next = p->next;
            p->next = r;
        }
    }
    
    return OK;
}

// 将元素b插入到链表L第i个位置上
Status Algo_2_17(LinkList* L, int i, ElemType b) {
    LinkList p, s;
    int j;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // i从1开始计数
    if(i <= 0) {
        return ERROR;
    }
    
    // 创建新结点
    s = (LinkList) malloc(sizeof(LNode));
    if(s == NULL) {
        exit(OVERFLOW);
    }
    s->data = b;
    
    j = 1;
    p = *L;
    
    // 特殊情形
    if(i == 1) {
        s->next = p;
        *L = s;
    } else {
        // 查找第i-1个结点，且保证它自身存在
        while(p != NULL && j < i - 1) {
            ++j;
            p = p->next;
        }
        
        // 未找到合适的位置
        if(p == NULL) {
            return ERROR;
        }
        
        s->next = p->next;
        p->next = s;
    }
    
    return OK;
}

// 删除链表L的第i个结点
Status Algo_2_18(LinkList* L, int i) {
    LinkList p, q;
    int j;
    
    // 确保有结点可删除
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    // i从1开始计数
    if(i <= 0) {
        return ERROR;
    }
    
    j = 1;
    p = *L;
    
    // 特殊情形
    if(i == 1) {
        *L = p->next;
        free(p);
    } else {
        // 查找第i-1个结点，且保证它后继存在
        while(p->next != NULL && j < i - 1) {
            ++j;
            p = p->next;
        }
        
        // 未找到合适的位置
        if(p->next == NULL) {
            return ERROR;
        }
        
        q = p->next;
        p->next = q->next;
        free(q);
    }
    
    return OK;
}

// 初始化无头结点的链表L
void InitList(LinkList* L) {
    *L = NULL;
}

// 输出无头结点的链表中的元素
void Output(LinkList L) {
    while(L != NULL) {
        printf("%2d ", L->data);
        L = L->next;
    }
    
    printf("\n");
}
