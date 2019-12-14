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


/*━━━━━━━━━━━━━━━━━━━━━━ 链表扩展操作 ━━━━━━━━━━━━━━━━━━━━━━*/

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
