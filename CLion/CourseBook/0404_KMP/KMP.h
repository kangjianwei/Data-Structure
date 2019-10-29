/*=======================
 * KMP算法
 *
 * 包含算法: 4.6、4.7、4.8
 ========================*/

#ifndef KMP_H
#define KMP_H

#include <stdio.h>
#include <stdlib.h>
#include "SString.h"            //**▲04 串**//

/*
 * ████████ 算法4.6 ████████
 *
 * 查找
 *
 * 从pos处开始搜索模式串T在主串S中首次出现的位置，如果不存在，则返回0。
 * 如果查找成功，返回匹配的位置。
 *
 *【注】
 * 1.该实现用到了KMP算法，是一种比较高效的字符串匹配方式
 * 2.教材中没有next参数
 */
int Index_KMP(SString S, SString T, int pos, int next[]);

/*
 * ████████ 算法4.7 ████████
 *
 * 计算模式串的“失配数组”，用于KMP算法。
 */
void get_next(SString T, int next[]);

/*
 * ████████ 算法4.8 ████████
 *
 * 计算模式串的“失配数组”，用于KMP算法。
 * 这是一个优化后的版本，效率较算法4.7有所提高。
 */
void get_nextval(SString T, int nextval[]);

#endif
