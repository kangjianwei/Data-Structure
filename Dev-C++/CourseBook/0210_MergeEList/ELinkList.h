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

/*
 * 内存回收
 *
 * 释放线性链表中指定的结点。
 *
 *【备注】
 * static修饰的含义是该函数仅限当前文件内使用
 */
void FreeNode(Link* p);


/*━━━━━━━━━━━━━━━━━━━━━━ 链表常规操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(ELinkList* L);

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
Status ListInsert(ELinkList* L, int i, ElemType e);

/*
 * 遍历
 *
 * 用visit函数访问链表L
 */
void ListTraverse(ELinkList L, void(Visit)(ElemType));


/*━━━━━━━━━━━━━━━━━━━━━━ 链表扩展操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 取值
 *
 * 获取结点p的元素值。
 */
ElemType GetCurElem(Link p);

/*
 * 头结点
 *
 * 获取头结点引用。
 */
Position GetHead(ELinkList L);

/*
 * 后继
 *
 * 获取结点p的后继，如果不存在，则返NULL。
 */
Position NextPos(ELinkList L, Link p);

/*
 * 查找
 *
 * 查找链表L中第i(允许为0)个结点，并将其引用存入p，且返回OK
 * 如果i值不合规，则返回ERROR
 * 特别注意，当i为0时，p存储的是头结点的引用
 */
Status LocatePos(ELinkList L, int i, Link* p);

/*
 * 插入
 *
 * 将s结点插入到h结点后面，成为h后面的第一个结点
 *
 *【备注】
 * 教材中对于该方法的描述有些问题，这里是修正过的版本
 */
Status InsFirst(ELinkList* L, Link h, Link s);

/*
 * 删除
 *
 * 删除h结点后的第一个结点，并用q存储被删除结点的引用
 *
 *【备注】
 * 教材中对于该方法的定义略显粗糙，这里是修正过的版本
 */
Status DelFirst(ELinkList* L, Link h, Link* q);

/*
 * 向尾部添加
 *
 * 将s所指的一串结点链接在链表L后面
 */
Status Append(ELinkList* L, Link s);

#endif
