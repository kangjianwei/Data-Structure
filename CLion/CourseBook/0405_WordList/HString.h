/*=========================
 * 串的堆分配存储表示（堆串）
 *
 * 包含算法: 4.4
 ==========================*/

#ifndef HSTRING
#define HSTRING

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <string.h>     // 提供strlen原型
#include "Status.h"     //**▲01 绪论**//

/*
 * 串的堆存储表示
 *
 * 注：有效元素从ch的0号单元开始存储
 */
typedef struct {
    char* ch;           // 若是非空串，则按串长分配存储区，否则ch为NULL
    int length;
} HString;


/*
 * 初始化
 *
 * 构造一个值为chars的串T。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status StrAssign(HString* T, const char* chars);

/*
 * 比较
 *
 * 比较串S和串T，返回比较结果。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status StrCompare(HString S, HString T);

/*
 * 复制
 *
 * 将串S复制到串T。
 */
Status StrCopy(HString* T, HString S);

#endif
