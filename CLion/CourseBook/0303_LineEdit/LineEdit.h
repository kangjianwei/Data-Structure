/*==============
 * 行编辑程序
 *
 * 包含算法: 3.2
 ===============*/

#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <stdio.h>
#include "SqStack.h"    //**▲03 栈和队列**//
#include "LineEdit.h"

// 模拟文件中的文本结束标记，需要覆盖已有的定义
#ifdef  EOF
#undef  EOF
#define EOF '\0'
#endif

/*
 * ████████ 算法3.2 ████████
 *
 * 行编辑程序，模拟编辑文本时的退格与清空行的操作。
 *
 *【注】
 * 教材使用的是控制台输入，这里为了便于测试，直接改为从形参接收参数
 */
void LineEdit(const char buffer[]);

// 测试函数，打印元素
void Print(SElemType e);

#endif
