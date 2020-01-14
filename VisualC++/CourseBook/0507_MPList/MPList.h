/*==========
 * m元多项式
 ===========*/

#ifndef MPLIST_H
#define MPLIST_H

#include <stdio.h>
#include <stdlib.h>       // 提供 malloc、realloc、free、exit 原型
#include <string.h>       // 提供 strlen 原型
#include "Status.h"       //**▲01 绪论**//
#include "StringUtil.h"   //**字符串工具类**//

/*
 * ████ 提示 ████
 *
 * 1.对于多元函数，约定第一元位于最外层。
 * 2.未知数标记默认为a~z或A~Z这26个字母
 * 3.约定多项式的每个元其指数是【递减】的，如3、2、1
 */


/*
 * 储存当前多项式的遍历信息，如x、y、z等
 * 约定var中的字符顺序即位各元的次序，如：
 * "zyx"指示z为第一元，y为第二元，x为第三元
 */
extern char Var[27];

/*
 * m元多项式结点标记
 *
 * Atom-0：原子结点
 * List-1：表结点
 */
typedef enum { Atom, List } ElemTag;

/* m元多项式元素结点 */
typedef struct MPNode {
    ElemTag tag;            // 区分原子结点和表结点
    int exp;                // 指数域，对于头结点，存储未知数标记，如x、y、z等
    union {
        float coef;         // 系数域
        struct MPNode* hp;  // 表结点的表头指针
    } Node;
    struct MPNode* tp;      // 相当于线性链表的next，指向下一个元素结点
} MPNode;

/* m元多项式广义表类型 */
typedef MPNode* MPList;


/*
 * 创建
 *
 * 由字符串S创建m元多项P。
 * 不会校验S是否书写正确。
 *
 * P   : 待建的多项式
 * S   : 多项式字符串
 * vars: 变量列表，从第一元开始排列，比如xyz代表三元多项式中的未知数标记
 */
Status CreateMPList(MPList* P, char* S, char* vars);

/*
 * m元多项式创建函数
 */
static Status Create(MPList* P, char* S);

/*
 * 图形化输出
 *
 * 带括号输出m元多项P。
 */
void PrintMPList(MPList P);

/*
 * 图形化输出的内部实现
 */
static void Print(MPList P);

/*
 * 将非空串str分割成两部分：hsub为第一个','之前的子串，str为第一个','之后的子串。
 *
 *【注】
 * 1.这里假设字符串str输入正确，其中无空白符号，且str【已经脱去最外层括号】。
 * 2.分离完成后，str也会发生变化
 */
static void sever(char** hstr, char** str);

#endif
