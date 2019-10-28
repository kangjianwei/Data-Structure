/*=============================
 * 串的块链分配存储表示（块链串）
 ==============================*/

#ifndef LSTRING_H
#define LSTRING_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <string.h>     // 提供strlen原型
#include "Status.h"     //**▲01 绪论**//

/* 宏定义 */
#define CHUNKSIZE 3     // 块大小（自定义）

/* 串的块链存储结构 */
typedef struct Chunk {
    char ch[CHUNKSIZE];  // 当前块中的内容
    struct Chunk* next;  // 指向下一个块
} Chunk;

/* 串的块链存储类型定义 */
typedef struct {
    Chunk* head;    //串的头指针
    Chunk* tail;    //串的尾指针
    int curlen;     //串的当前长度
} LString;


/*
 * ████ 提示 ████
 *
 * 遵循教材的书写习惯，pos指示字符的位序(不是索引)，从1开始计数
 */

/*
 * ████ 注意 ████
 *
 * 1.教材示例中使用#作为非串值字符，而这里使用C语言中的\0作为非串值字符
 * 2.教材中指出，块链的最后一个块中，末尾可能是用非串值字符填充的。
 *   例如块大小为4，长度为14的块可能为：ＡＢＣＤ -> ＥＦＧＨ -> ＩＪＫＬ -> ＭＮ\0\0
 */


/*
 * 初始化
 *
 * 构造一个值为chars的串T。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status StrAssign(LString* T, const char* chars);

/*
 * 销毁
 *
 * 将串S销毁。
 */
Status DestroyString(LString* S);

/*
 * 清空
 *
 * 将串S清空。
 */
Status ClearString(LString* S);

/*
 * 判空
 *
 * 判断串S中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 串S为空
 * FALSE: 串S不为空
 */
Status StrEmpty(LString S);

/*
 * 计数
 *
 * 返回串S中元素的个数。
 *
 *【注】
 * 该操作属于最小操作子集
 */
int StrLength(LString S);

/*
 * 求子串
 *
 * 用Sub返回S[pos, pos+len-1]。
 * 返回值指示是否截取成功。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status SubString(LString* Sub, LString S, int pos, int len);

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
int Index(LString S, LString T, int pos);

/*
 * 插入
 *
 * 将串T插入到主串S的pos位置处。
 */
Status StrInsert(LString* S, int pos, LString T);

/*
 * 删除
 *
 * 删除S[pos, pos+len-1]。
 */
Status StrDelete(LString* S, int pos, int len);

/*
 * 比较
 *
 * 比较串S和串T，返回比较结果。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status StrCompare(LString S, LString T);

/*
 * 复制
 *
 * 将串S复制到串T。
 */
Status StrCopy(LString* T, LString S);

/*
 * 替换
 *
 * 用V替换主串S中出现的所有与T相等的且不重叠的子串。
 *
 *【注】
 * 1.该操作依赖最小操作子集
 * 2.该实现比较低效
 */
Status Replace(LString* S, LString T, LString V);

/*
 * 串联接
 *
 * 联接S1和S2，并存储到T中返回。如果联接后的长度溢出，则只保留未溢出的部分。
 * 返回值表示联接后的串是否完整。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status Concat(LString* T, LString S1, LString S2);

#endif
