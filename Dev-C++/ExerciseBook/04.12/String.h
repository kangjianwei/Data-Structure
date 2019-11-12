/*===========================
 * 习题4.10~4.14中使用的字符串
 ============================*/

#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <string.h>     // 提供 strlen 原型
#include "Status.h"     //**▲01 绪论**//

/* 字符串类型 */
typedef char* StringType;


// 初始化：构造一个值为s的串t
void StrAssign(StringType* t, const char*  s);

// 比较：返回s与t的大小，如果大小一致，返回0
int StrCompare(StringType s, StringType t);

// 计数：返回字符串s的长度
int StrLength(StringType s);

// 联接：返回由s与t联接后的串
StringType Concat(StringType s, StringType t);

// 求子串：从s的start位置起，截取len个字符后返回
StringType SubString(StringType s, int start, int len);

// 查找：从s的pos位置起查找t，如果找到，返回其位置
int Index(StringType s, StringType t, int pos);

// 插入：在s的pos处插入t
Status StrInsert(StringType* s, int pos, StringType t);

// 删除：从s的pos位置起，删除len个字符
Status StrDelete(StringType* s, int pos, int len);

// 输出字符串
void StrPrint(StringType s);

#endif
