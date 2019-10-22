/*===============================
 * 线性表的链式存储结构（链表）
 *
 * 包含算法: 2.8、2.9、2.10、2.11
 ================================*/

#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

// 事件类型枚举常量，0代表到达事件，1至4表示四个窗口的离开事件
typedef enum {
    Arrive, Leave_1, Leave_2, Leave_3, Leave_4
} EventType;

/* 事件链表元素类型定义 */
typedef struct
{
    int OccurTime;      // 事件发生时刻
    EventType NType;    // 事件类型
} Event, ElemType;      // 事件链表元素

/*
 * 单链表结构
 *
 * 注：这里的单链表存在头结点
 */
typedef struct LNode {
    ElemType data;      // 数据结点
    struct LNode* next; // 指向下一个结点的指针
} LNode;

// 指向单链表结点的指针
typedef LNode* LinkList;


/*
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(LinkList* L);

/*
 * 判空
 *
 * 判断链表中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 链表为空
 * FALSE: 链表不为空
 */
Status ListEmpty(LinkList L);

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
Status ListInsert(LinkList L, int i, ElemType e);

/*
 * ████████ 算法2.10 ████████
 *
 * 删除
 *
 * 删除链表第i个位置上的元素，并将被删除元素存储到e中。
 * 删除成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListDelete(LinkList L, int i, ElemType* e);

#endif
