/*=====================
 * 双向循环链表
 *
 * 包含算法: 2.18、2.19
 ======================*/

#include "DuLinkList.h"        //**▲02 线性表**//

/*
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(DuLinkList* L) {
    *L = (DuLinkList) malloc(sizeof(DuLNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    
    // 前驱和后继均指向自身
    (*L)->next = (*L)->prior = *L;
    
    return OK;
}

/*
 * ████████ 算法2.18 ████████
 *
 * 插入
 *
 * 向双向循环链表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListInsert(DuLinkList L, int i, ElemType e) {
    DuLinkList p, s;
    
    // 确保双向循环链表存在（但可能为空表）
    if(L == NULL) {
        return ERROR;
    }
    
    // 查找第i个结点位置（引用）
    if((p = GetElemP(L, i)) == NULL) {
        return ERROR;
    }
    
    // 创建新结点
    s = (DuLinkList) malloc(sizeof(DuLNode));
    if(s == NULL) {
        exit(OVERFLOW);
    }
    s->data = e;
    
    // 将s插入到p的前面，称为第i个结点
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    
    return OK;
}

/*
 * 遍历
 *
 * 用visit函数访问双向循环链表L
 */
void ListTraverse(DuLinkList L, void(Visit)(ElemType)) {
    DuLinkList p;
    
    // 确保双向循环链表存在
    if(L == NULL || L->next == L || L->prior == L) {
        return;
    }
    
    p = L->next;
    
    while(p != L) {
        Visit(p->data);
        p = p->next;
    }
    
    printf("\n");
}

/*
 * 获取循环链表L上第i个元素的引用
 *
 * ▓▓▓▓ 注 ▓▓▓▓
 * 1.加static的含义是当前函数只在DuLinkList中使用，不会被别的文件引用
 * 2.假设链表长度为len，且需要获取第len+1个元素的引用时，由于这里是循环链表，所以返回的是头结点
 */
static DuLinkList GetElemP(DuLinkList L, int i) {
    DuLinkList p;
    int count;
    
    // 确保双向循环链表存在（但可能为空表）
    if(L == NULL) {
        return NULL;
    }
    
    // 位置不合规
    if(i < 1) {
        return NULL;
    }
    
    p = L;
    count = 0;
    
    // 尝试查找第i个元素
    while(p->next != L && count < i) {
        p = p->next;
        ++count;
    }
    
    // 恰好找到第i个元素
    if(count == i) {
        return p;
    }
    
    // 至此，说明p->next==L，此时需要判断i是否过大
    if(count + 1 < i) {
        return NULL;
    }
    
    // 至此，说明需要在len+1的位置上插入元素
    return L;
}
