/*============================
 * 广义表的头尾链表存储表示
 =============================*/

#ifndef GLIST_H
#define GLIST_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、realloc、free、exit 原型
#include "Status.h"     //**▲01 绪论**//
#include "SString.h"    //**▲04 串**//

/* 原子元素类型 */
typedef char AtomType;

/*
 * 广义表结点标记
 *
 * Atom-0：原子结点
 * List-1：表结点
 */
typedef enum { Atom, List } ElemTag;

/* 广义表（头尾链表存储表示）类型定义 */
typedef struct GLNode {
    ElemTag tag;    // 公共标记，用于区分原子结点和表结点
    
    // 原子结点和表结点的联合部分
    union {
        AtomType atom;          // atom是原子结点的值域，AtomType由用户定义
        struct {
            struct GLNode* hp;  // 指向表头
            struct GLNode* tp;  // 指向表尾
        } ptr;                  // 表结点的指针域
    } Node;
} GLNode;

/* 广义表类型 */
typedef GLNode* GList;

/*
 * 图形化输出标记
 *
 * Head代表广义表指针来自表头
 * Tail代表广义表指针来自表尾
 */
typedef enum { Head, Tail } Mark;


/*
 * ████████ 算法5.7 ████████
 *
 * 创建
 *
 * 由字符串S创建广义表L。
 */
Status CreateGList(GList* L, SString S);

/*
 * 图形化输出
 *
 * 带括号输出广义表L。
 */
void PrintGList(GList L);

/*
 * 图形化输出的内部实现，mark是图形化输出标记。
 */
static void Print(GList L, Mark mark);

/*
 * ████████ 算法5.8 ████████
 *
 * 将非空串str分割成两部分：hsub为第一个','之前的子串，str为第一个','之后的子串。
 *
 *【注】
 * 1.这里假设字符串str输入正确，其中无空白符号，且str【已经脱去最外层括号】。
 * 2.分离完成后，str也会发生变化
 */
static void sever(SString hstr, SString str);

#endif
