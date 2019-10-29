/*=============================
 * 串的定长顺序存储表示（顺序串）
 *
 * 包含算法: 4.1、4.2、4.3、4.5
 ==============================*/

#ifndef SSTRING_H
#define SSTRING_H

#include <stdio.h>
#include <string.h>     // 提供strlen原型
#include "Status.h"     //**▲01 绪论**//

/* 宏定义 */
#define MAXSTRLEN 255       // 顺序串的最大串长

/*
 * 串的顺序存储类型定义
 *
 * 注：有效元素从SString的1号单元开始存储
 *     SString的0号单元用来存储其长度
 */
typedef unsigned char SString[MAXSTRLEN + 1];       // 0号单元存放串的长度


/*
 * 初始化
 *
 * 构造一个值为chars的串T。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status StrAssign(SString T, const char* chars);

#endif
