/*================
 * 字符串操作工具类
 =================*/

#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc 原型
#include <string.h>     // 提供 strlen、strncpy 原型
#include <ctype.h>      // 提供 isprint 原型
#include "Status.h"     //**▲01 绪论**//

/*
 * 删除
 *
 * 删除s[pos, pos+len-1]，pos从1开始计数。
 */
Status StrDelete(char** S, int pos, int n);

/*
 * 求子串
 *
 * 用sub返回s[pos, pos+len-1]，pos从1开始计数。
 */
Status SubString(char** sub, char* s, int pos, int len);

/*
 * 判空
 *
 * 判断串s中是否包含有效数据。
 */
Status StrEmpty(char* s);

/*
 * 整理
 *
 * 清理字符串s中的空白，包括清理不可打印字符和清理空格。
 */
Status ClearBlank(char** s);

/*
 * 计数
 *
 * 统计字符串s中的元素个数。
 * 这里的特殊之处在于：对于数字，会将其当成一个元素。
 */
int ElemCount(const char* s);

/*
 * 取值
 *
 * 获取字符串s中第pos个元素(pos从1开始计数)，并用f接收。
 * 这里的特殊之处在于：对于数字，会将其当成一个元素。
 */
Status GetElem(char* s, int pos, float *f);

#endif
