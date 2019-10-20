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

/*
 * 线性链表元素类型定义
 * 这里用在多项式中，用到了结构体类型的元素
 */
typedef struct {
    float coef;     // 多项式系数
    int expn;       // 多项式指数
} ElemType;         // 重新定义扩展的线性表中元素类型

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
 * 销毁(结构)
 *
 * 释放链表所占内存。
 */
Status DestroyList(ELinkList* L);

/*
 * 置空(内容)
 *
 * 这里需要释放链表中非头结点处的空间。
 */
Status ClearList(ELinkList* L);

/*
 * 计数
 *
 * 返回链表包含的有效元素的数量。
 */
int ListLength(ELinkList L);

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
Status LocateElem(ELinkList L, ElemType e, Position* q, Status(Compare)(ElemType, ElemType));


/*━━━━━━━━━━━━━━━━━━━━━━ 链表扩展操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 取值
 *
 * 获取结点p的元素值。
 */
ElemType GetCurElem(Link p);

/*
 * 设值
 *
 * 为结点p设置元素值。
 */
Status SetCurElem(Link p, ElemType e);

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
