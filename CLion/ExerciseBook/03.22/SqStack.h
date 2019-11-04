/*=========================
 * 栈的顺序存储结构（顺序栈）
 ==========================*/

#ifndef SQSTACK_H
#define SQSTACK_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 宏定义 */
#define STACK_INIT_SIZE 100     // 顺序栈存储空间的初始分配量
#define STACKINCREMENT  10      // 顺序栈存储空间的分配增量

/* 顺序栈元素类型定义 */
typedef int SElemType;

// 顺序栈元素结构
typedef struct {
    SElemType* base;               // 栈底指针
    SElemType* top;                // 栈顶指针
    int stacksize;                 // 当前已分配的存储空间，以元素为单位
} SqStack;


/*
 * 初始化
 *
 * 构造一个空栈。初始化成功则返回OK，否则返回ERROR。
 */
Status InitStack(SqStack* S);

/*
 * 判空
 *
 * 判断顺序栈中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 顺序栈为空
 * FALSE: 顺序栈不为空
 */
Status StackEmpty(SqStack S);

/*
 * 入栈
 *
 * 将元素e压入到栈顶。
 */
Status Push(SqStack* S, SElemType e);

/*
 * 出栈
 *
 * 将栈顶元素弹出，并用e接收。
 */
Status Pop(SqStack* S, SElemType* e);

#endif
