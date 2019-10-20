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
 * 销毁(结构)
 *
 * 释放链表所占内存。
 */
Status DestroyList(ELinkList* L) {
    
    // 链表不存在时没必要销毁
    if(L == NULL || (*L).head == NULL) {
        return ERROR;
    }
    
    ClearList(L);
    
    free((*L).head);
    
    (*L).head = (*L).tail = NULL;
    
    return OK;
}

/*
 * 置空(内容)
 *
 * 这里需要释放链表中非头结点处的空间。
 */
Status ClearList(ELinkList* L) {
    Link p, q;
    
    // 没有有效元素时不需要清理
    if(L == NULL || (*L).head == NULL || (*L).len <= 0) {
        return ERROR;
    }
    
    // 指向第1个元素
    p = (*L).head->next;
    
    // 释放所有元素所占内存
    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    
    (*L).head->next = NULL;
    (*L).tail = (*L).head;
    (*L).len = 0;
    
    return OK;
}

/*
 * 计数
 *
 * 返回链表包含的有效元素的数量。
 */
int ListLength(ELinkList L) {
    return L.len;
}

/*
 * 查找
 *
 * 这个查找函数与传统的版本不一样。
 * 这里首先会查找与元素e满足Compare()==0的元素，如果找到，使用q存储其引用，并返回True。
 * 如果不存在上述引用，则查找首个与元素e满足Compare()>0的元素的前驱，并返回FALSE。
 * 如果链表中的元素均大于e，q存储头结点引用。
 * 如果链表中的元素均小于e，q存储尾结点引用。
 * 其它情形下，会将q置空。
 *
 *【备注】
 * 1.元素e是Compare函数第二个形参
 */
Status LocateElem(ELinkList L, ElemType e, Position* q, Status(Compare)(ElemType, ElemType)) {
    Position pre, p;
    
    *q = NULL;
    
    // 链表不存在，返回错误信息
    if(L.head == NULL) {
        return FALSE;
    }
    
    pre = L.head;
    p = pre->next;
    
    while(p != NULL && Compare(p->data, e) < 0) {
        pre = p;
        p = p->next;
    }
    
    // 找到了与e满足"相等"条件的元素
    if(p != NULL && Compare(p->data, e) == 0) {
        *q = p;
        return TRUE;
    }
    
    // 所有元素均小于e，或者p元素大于e，又或者为空表
    *q = pre;
    
    return FALSE;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 链表扩展操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 取值
 *
 * 获取结点p的元素值。
 */
ElemType GetCurElem(Link p) {
    ElemType e;
    
    if(p == NULL) {
        e.coef = 0.0f;
        e.expn = -1;
        return e;
    }
    
    return p->data;
}

/*
 * 设值
 *
 * 为结点p设置元素值。
 */
Status SetCurElem(Link p, ElemType e) {
    if(p == NULL) {
        return ERROR;
    }
    
    p->data = e;
    
    return OK;
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
    
    // 将被删除结点变成孤立的结点
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
