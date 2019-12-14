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
 * 销毁
 *
 * 将串S销毁。
 *
 *【注】
 * 顺序串的结构无法销毁
 */
Status DestroyString(SString S);

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
 * ████████ 算法4.1 ████████
 *
 * 查找
 *
 * 从pos处开始搜索模式串T在主串S中首次出现的位置，如果不存在，则返回0。
 * 如果查找成功，返回匹配的位置。
 *
 *【注】
 * 1.此实现需要依赖串的最小操作子集
 * 2.该实现比较低效
 */
int Index_1(SString S, SString T, int pos);

/*
 * ████████ 算法4.5 ████████
 *
 * 查找
 *
 * 从pos处开始搜索模式串T在主串S中首次出现的位置，如果不存在，则返回0。
 * 如果查找成功，返回匹配的位置。
 *
 *【注】
 * 1.此实现不依赖串的最小操作子集
 * 2.该实现比较低效
 */
int Index_2(SString S, SString T, int pos);

/*
 * 插入
 *
 * 将串T插入到主串S的pos位置处。
 */
Status StrInsert(SString S, int pos, SString T);

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
 * 替换
 *
 * 用V替换主串S中出现的所有与T相等的且不重叠的子串。
 *
 *【注】
 * 该操作依赖最小操作子集，效率较低。
 */
Status Replace(SString S, SString T, SString V);

/*
 * ████████ 算法4.2 ████████
 *
 * 串联接
 *
 * 联接S1和S2，并存储到T中返回。如果联接后的长度溢出，则只保留未溢出的部分。
 * 返回值表示联接后的串是否完整。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status Concat(SString T, SString S1, SString S2);

// 输出：打印字符串
void StrPrint(SString S);

#endif
