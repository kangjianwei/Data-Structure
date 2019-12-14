/*=============================
 * 串的定长顺序存储表示（顺序串）
 *
 * 包含算法: 4.1、4.2、4.3、4.5
 ==============================*/

#ifndef SSTRING_H
#define SSTRING_H

#include <stdio.h>
#include <string.h>     // 提供 strlen 原型
#include <ctype.h>      // 提供 isprint 原型
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
 * ████ 提示 ████
 *
 * 遵循教材的书写习惯，pos指示字符的位序(不是索引)，从1开始计数
 */


/*
 * 初始化
 *
 * 构造一个值为chars的串T。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status StrAssign(SString T, const char* chars);

/*
 * 清空
 *
 * 将串S清空。
 */
Status ClearString(SString S);

/*
 * 判空
 *
 * 判断串S中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 串S为空
 * FALSE: 串S不为空
 */
Status StrEmpty(SString S);

/*
 * 计数
 *
 * 返回串S中元素的个数。
 *
 *【注】
 * 该操作属于最小操作子集
 */
int StrLength(SString S);

/*
 * ████████ 算法4.3 ████████
 *
 * 求子串
 *
 * 用Sub返回S[pos, pos+len-1]。
 * 返回值指示是否截取成功。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status SubString(SString Sub, SString S, int pos, int len);

/*
 * 删除
 *
 * 删除S[pos, pos+len-1]。
 */
Status StrDelete(SString S, int pos, int len);

/*
 * 比较
 *
 * 比较串S和串T，返回比较结果。
 *
 *【注】
 * 该操作属于最小操作子集
 */
int StrCompare(SString S, SString T);

/*
 * 复制
 *
 * 将串S复制到串T。
 */
Status StrCopy(SString T, SString S);

/*
 * 清理字符串S中的空白，包括清理不可打印字符和清理空格。
 *
 *【注】
 * 该函数是在本章中新增的。
 */
Status ClearBlank(SString S);

#endif
