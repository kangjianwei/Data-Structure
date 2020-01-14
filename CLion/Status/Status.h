/*
 * 注：
 * 本次修订的目的包括降低耦合，争取每个模块都可以单独运行
 * 但是Status这个模块会被所有其他模块引用，引用次数很多。
 * 如果直接将Status模块复制到其它模块中，则会导致太多重复代码，
 * 因此这里生成一个公共静态库让其它模块共享比较划算
 */

#ifndef STATUS_H
#define STATUS_H

#include <stdio.h>

/* 状态码 */
#define TRUE        1   // 真/是
#define FALSE       0   // 假/否
#define OK          1   // 通过/成功
#define ERROR       0   // 错误/失败

//系统中已有此状态码定义，要防止冲突
#ifndef OVERFLOW
#define OVERFLOW    -2  //堆栈上溢
#endif

//系统中已有此状态码定义，要防止冲突
#ifndef NULL
#define NULL ((void*)0)
#endif

/* 状态码类型 */
typedef int Status;

/* 布尔类型 */
typedef int Boolean;


// 读取数据
int ReadData(FILE* fp, char* format, ...);

// 摁下回车键以继续运行
void PressEnterToContinue();

// 函数暂停一段时间，time不代表具体的时间
void Wait(long time);

// 跳过输入端的行分割符，如'\r'、'\n'、'\r\n'
void skipLineSeparator(FILE* fp);

#endif


