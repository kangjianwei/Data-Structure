/*===============================
 * 线性表的链式存储结构（链表）
 *
 * 包含算法: 2.8、2.9、2.10、2.11
 ================================*/

#include "LinkList.h" //**▲02 线性表**//

/*
 * 初始化
 *
 * 只是初始化一个头结点。
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(LinkList* L) {
    (*L) = (LinkList) malloc(sizeof(LNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    
    (*L)->next = NULL;
    
    return OK;
}

/*
 * 销毁(结构)
 *
 * 释放链表所占内存，头结点也会被清理。
 */
Status DestroyList(LinkList* L) {
    LinkList p;
    
    // 确保链表结构存在
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    p = *L;
    
    while(p != NULL) {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
    
    *L = NULL;
    
    return OK;
}

/*
 * 置空(内容)
 *
 * 这里需要释放链表中非头结点处的空间。
 */
Status ClearList(LinkList L) {
    LinkList pre, p;
    
    // 确保链表存在
    if(L == NULL) {
        return ERROR;
    }
    
    p = L->next;
    
    // 释放链表上所有结点所占内存
    while(p != NULL) {
        pre = p;
        p = p->next;
        free(pre);
    }
    
    L->next = NULL;
    
    return OK;
}

/*
 * 查找
 *
 * 返回链表中首个与e满足Compare关系的元素位序。
 * 如果不存在这样的元素，则返回0。
 *
 *【备注】
 * 元素e是Compare函数第二个形参
 */
int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    LinkList p;
    
    // 确保链表存在且不为空表
    if(L == NULL || L->next == NULL) {
        return 0;
    }
    
    i = 1;          // i的初值为第1个元素的位序
    p = L->next;    // p的初值为第1个元素的指针
    
    while(p != NULL && !Compare(p->data, e)) {
        i++;
        p = p->next;
    }
    
    if(p != NULL) {
        return i;
    } else {
        return 0;
    }
}

/*
 * ████████ 算法2.9 ████████
 *
 * 插入
 *
 * 向链表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListInsert(LinkList L, int i, ElemType e) {
    LinkList p, s;
    int j;
    
    // 确保链表存
    if(L == NULL) {
        return ERROR;
    }
    
    p = L;
    j = 0;
    
    // 寻找第i-1个结点，且保证该结点本身不为NULL
    while(p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    
    // 如果遍历到头了，或者i的值不合规(比如i<=0)，说明没找到合乎目标的结点
    if(p == NULL || j > i - 1) {
        return ERROR;
    }
    
    // 生成新结点
    s = (LinkList) malloc(sizeof(LNode));
    if(s == NULL) {
        exit(OVERFLOW);
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return OK;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 新增函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 判断线性表中两个元素是否相等
Status Equal(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE : FALSE;
}
