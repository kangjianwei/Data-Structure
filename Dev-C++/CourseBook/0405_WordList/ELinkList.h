/*=======================
 * 扩展的单链表（线性链表）
 *
 * 包含算法: 2.20
 ========================*/

#ifndef ELINKLIST_H
#define ELINKLIST_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <limits.h>     // 提供一些极限常量
#include "Status.h"     //**▲01 绪论**//

/*
 * ████ 注意 ████
 *
 * 教材中的线性链表命名为LinkList，
 * 这里为了与单链表区分，故将其命名为ELinkList。
 * 线性链表可以理解成对普通链表的一种扩展。
 */

/* 线性链表元素类型定义 */
typedef int ElemType;

/*
 * 线性链表结构
 *
 * 注：这里的线性链表存在头结点
 */
typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, * Link, * Position;

/* 维护线性链表头尾指针及长度信息 */
typedef struct {
    Link head, tail;    // 分别指向线性链表中的头结点和尾结点
    int len;            // 指示线性链表中数据元素的个数
} ELinkList;


/*━━━━━━━━━━━━━━━━━━━━━━ 内存操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 内存分配
 *
 * 为线性链表申请一个结点，并存入指定的数据e。
 *
 *【备注】
 * static修饰的含义是该函数仅限当前文件内使用
 */
Status MakeNode(Link* p, ElemType e);


/*━━━━━━━━━━━━━━━━━━━━━━ 链表常规操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(ELinkList* L);


/*━━━━━━━━━━━━━━━━━━━━━━ 链表扩展操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 向尾部添加
 *
 * 将s所指的一串结点链接在链表L后面
 */
Status Append(ELinkList* L, Link s);

#endif
