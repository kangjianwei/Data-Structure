/*=======================
 * 扩展的单链表（线性链表）
 *
 * 包含算法: 2.20
 ========================*/

#include "ELinkList.h"  //**▲02 线性表**//


/*━━━━━━━━━━━━━━━━━━━━━━ 内存操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 内存分配
 *
 * 为线性链表申请一个结点，并存入指定的数据e。
 *
 *【备注】
 * static修饰的含义是该函数仅限当前文件内使用
 */
Status MakeNode(Link* p, ElemType e) {
    if(p == NULL) {
        return ERROR;
    }
    
    // 申请空间
    *p = (Link) malloc(sizeof(LNode));
    if(*p == NULL) {
        // 这里没有退出程序，而是返回错误提示
        return ERROR;
    }
    
    (*p)->data = e;
    (*p)->next = NULL;
    
    return OK;
}

/*
 * 内存回收
 *
 * 释放线性链表中指定的结点。
 *
 *【备注】
 * static修饰的含义是该函数仅限当前文件内使用
 */
void FreeNode(Link* p) {
    if(p == NULL || *p == NULL) {
        return;
    }
    
    free(*p);
    
    *p = NULL;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 链表常规操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(ELinkList* L) {
    Link p;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // 创建头结点
    p = (Link) malloc(sizeof(LNode));
    if(p == NULL) {
        exit(OVERFLOW);
    }
    p->next = NULL;
    
    // 只有头结点时，首位游标指向自身
    (*L).head = (*L).tail = p;
    (*L).len = 0;
    
    return OK;
}

/*
 * ████████ 算法2.20 ████████
 *
 * 插入
 *
 * 向链表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 * 可以看做是算法2.9的改写
 */
Status ListInsert(ELinkList* L, int i, ElemType e) {
    Link h, s;
    
    if(L == NULL || (*L).head == NULL) {
        return ERROR;
    }
    
    // 确保i值合规[1, len+1]
    if(i < 1 || i > (*L).len + 1) {
        return ERROR;
    }
    
    // 查找第i-1个元素的引用，存储在h中
    if(LocatePos(*L, i - 1, &h) == ERROR) {
        return ERROR;
    }
    
    // 分配新结点s
    if(MakeNode(&s, e) == ERROR) {
        return ERROR;
    }
    
    // 将s结点插入到h结点后面，成为h后面的第一个结点
    if(InsFirst(L, h, s) == ERROR) {
        return ERROR;
    }
    
    return OK;
}

/*
 * 遍历
 *
 * 用visit函数访问链表L
 */
void ListTraverse(ELinkList L, void(Visit)(ElemType)) {
    Link p;
    
    if(L.len <= 0) {
        return;
    }
    
    // 指向第1个元素
    p = L.head->next;
    
    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }
    
    printf("\n");
}


/*━━━━━━━━━━━━━━━━━━━━━━ 链表扩展操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 取值
 *
 * 获取结点p的元素值。
 */
ElemType GetCurElem(Link p) {
    if(p == NULL) {
        return INT_MIN;
    }
    
    return p->data;
}

/*
 * 头结点
 *
 * 获取头结点引用。
 */
Position GetHead(ELinkList L) {
    return L.head;
}

/*
 * 后继
 *
 * 获取结点p的后继，如果不存在，则返NULL。
 */
Position NextPos(ELinkList L, Link p) {
    
    // 确保链表(头结点)存在
    if(L.head == NULL) {
        return NULL;
    }
    
    if(p == NULL) {
        return NULL;
    }
    
    return p->next;
}

/*
 * 查找
 *
 * 查找链表L中第i(允许为0)个结点，并将其引用存入p，且返回OK
 * 如果i值不合规，则返回ERROR
 * 特别注意，当i为0时，p存储的是头结点的引用
 */
Status LocatePos(ELinkList L, int i, Link* p) {
    int j;
    Link r;
    
    // 注：i允许为0
    if(i < 0 || i > L.len) {
        return ERROR;
    }
    
    // 保证链表(头结点)存在
    if(L.head == NULL) {
        return ERROR;
    }
    
    // i为0时，取头结点
    if(i == 0) {
        *p = L.head;
        return OK;
    }
    
    j = 0;         // 计数
    r = L.head;    // 指向头结点
    
    while(r != NULL && j < i) {
        j++;
        r = r->next;
    }
    
    if(r == NULL) {
        return ERROR;
    }
    
    *p = r;
    
    return OK;
}

/*
 * 插入
 *
 * 将s结点插入到h结点后面，成为h后面的第一个结点
 *
 *【备注】
 * 教材中对于该方法的描述有些问题，这里是修正过的版本
 */
Status InsFirst(ELinkList* L, Link h, Link s) {
    if(L == NULL || (*L).head == NULL || h == NULL || s == NULL) {
        return ERROR;
    }
    
    s->next = h->next;
    h->next = s;
    
    // 若h为尾结点，则需要更新尾结点
    if(h == (*L).tail) {
        (*L).tail = h->next;
    }
    
    (*L).len++;
    
    return OK;
}

/*
 * 删除
 *
 * 删除h结点后的第一个结点，并用q存储被删除结点的引用
 *
 *【备注】
 * 教材中对于该方法的定义略显粗糙，这里是修正过的版本
 */
Status DelFirst(ELinkList* L, Link h, Link* q) {
    if(L == NULL || (*L).head == NULL || h == NULL || q == NULL) {
        return ERROR;
    }
    
    // 如果没有结点可删除，返回错误信息
    if(h->next == NULL) {
        return ERROR;
    }
    
    *q = h->next;
    
    h->next = (*q)->next;
    
    // ★将被删除结点变成孤立的结点
    (*q)->next = NULL;
    
    // 如果h后只有一个结点，更改尾结点指针
    if(h->next == NULL) {
        (*L).tail = h;
    }
    
    // 并不释放被删结点所占空间
    (*L).len--;
    
    return OK;
}

/*
 * 向尾部添加
 *
 * 将s所指的一串结点链接在链表L后面
 */
Status Append(ELinkList* L, Link s) {
    int count;
    
    if(L == NULL || (*L).head == NULL || s == NULL) {
        return ERROR;
    }
    
    count = 0;
    (*L).tail->next = s;
    
    // 确定新的尾结点位置
    while(s != NULL) {
        (*L).tail = s;
        s = s->next;
        count++;
    }
    
    (*L).len += count;
    
    return OK;
}
