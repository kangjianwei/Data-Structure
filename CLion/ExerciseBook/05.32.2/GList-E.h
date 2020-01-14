/*===========================
 * 广义表的扩展线性链表存储表示
 ============================*/

#ifndef GLIST_E_H
#define GLIST_E_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、realloc、free、exit 原型
#include "Status.h"     //**▲01 绪论**//
#include "SString.h"    //**▲04 串**//

/* 原子元素类型 */
typedef char AtomType;                        //原子类型

/*
 * 广义表结点标记
 *
 * Atom-0：原子结点
 * List-1：表结点
 */
typedef enum { Atom, List } ElemTag;

/* 广义表（扩展线性链表存储表示）类型定义 */
typedef struct GLNode {
    ElemTag tag;    // 公共标记，用于区分原子结点和表结点
    
    // 原子结点和表结点的联合部分
    union
    {
        AtomType atom;      // atom是原子结点的值域，AtomType由用户定义
        struct GLNode* hp;  // 指向表头
    } Node;
    struct GLNode* tp;      // 指向表尾
} GLNode;

/* 广义表类型 */
typedef GLNode* GList;


/*
 * 初始化
 *
 * 初始化空的广义表，长度为0，深度为1。
 *
 *【注】
 * 需要对每一层带上括号考察
 */
Status InitGList(GList* L);

/*
 * 创建
 *
 * 由字符串S创建广义表L。
 */
Status CreateGList(GList* L, SString S);

/*
 * 销毁
 *
 * 释放广义表所占内存。
 */
Status DestroyGList(GList* L);

/*
 * 复制
 *
 * 由广义表L复制得到广义表T。
 */
Status CopyGList(GList* T, GList L);

/*
 * 计数
 *
 * 返回广义表的长度。
 */
int GListLength(GList L);

/*
 * 深度
 *
 * 返回广义表的深度
 */
int GListDepth(GList L);

/*
 * 判空
 *
 * 判断广义表是否为空。
 */
Status GListEmpty(GList L);

/*
 * 表头
 */
GList GetHead(GList L);

/*
 * 表尾
 */
GList GetTail(GList L);

/*
 * 插入
 *
 * 将元素e插入为广义表L的第一个元素。
 */
Status InsertFirst(GList* L, GList e);

/*
 * 删除
 *
 * 将广义表L的第一个元素删除，并用e返回。
 */
Status DeleteFirst(GList* L, GList* e);

/*
 * 遍历
 *
 * 用visit函数访问广义表L。
 */
void Traverse(GList L, void(Visit)(AtomType));

/*
 * 图形化输出
 *
 * 带括号输出广义表L。
 */
void PrintGList(GList L);

/*
 * 图形化输出的内部实现。
 */
static void Print(GList L);

/*
 * 将非空串str分割成两部分：hsub为第一个','之前的子串，str为第一个','之后的子串。
 *
 *【注】
 * 1.这里假设字符串str输入正确，其中无空白符号，
 *   但str外层的括号可能脱去，也可能未脱去。
 * 2.分离完成后，str也会发生变化
 */
static void sever(SString hstr, SString str);

#endif
