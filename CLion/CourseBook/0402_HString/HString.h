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
Status StrAssign(HString* T, const char* chars);

/*
 * 销毁
 *
 * 将串S销毁。
 */
Status DestroyString(HString* S);

/*
 * 清空
 *
 * 将串S清空。
 */
Status ClearString(HString* S);

/*
 * 判空
 *
 * 判断串S中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 串S为空
 * FALSE: 串S不为空
 */
Status StrEmpty(HString S);

/*
 * 计数
 *
 * 返回串S中元素的个数。
 *
 *【注】
 * 该操作属于最小操作子集
 */
int StrLength(HString S);

/*
 * 求子串
 *
 * 用Sub返回S[pos, pos+len-1]。
 * 返回值指示是否截取成功。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status SubString(HString* Sub, HString S, int pos, int len);

/*
 * 查找
 *
 * 从pos处开始搜索模式串T在主串S中首次出现的位置，如果不存在，则返回0。
 * 如果查找成功，返回匹配的位置。
 *
 *【注】
 * 1.此实现需要依赖串的最小操作子集
 * 2.该实现比较低效
 */
int Index(HString S, HString T, int pos);

/*
 * ████████ 算法4.4 ████████
 *
 * 插入
 *
 * 将串T插入到主串S的pos位置处。
 */
Status StrInsert(HString* S, int pos, HString T);

/*
 * 删除
 *
 * 删除S[pos, pos+len-1]。
 */
Status StrDelete(HString* S, int pos, int len);

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

/*
 * 替换
 *
 * 用V替换主串S中出现的所有与T相等的且不重叠的子串。
 *
 *【注】
 * 1.该操作依赖最小操作子集
 * 2.该实现比较低效
 */
Status Replace(HString* S, HString T, HString V);

/*
 * 串联接
 *
 * 联接S1和S2，并存储到T中返回。如果联接后的长度溢出，则只保留未溢出的部分。
 * 返回值表示联接后的串是否完整。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status Concat(HString* T, HString S1, HString S2);

#endif
