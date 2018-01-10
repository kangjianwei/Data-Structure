/************************************
 *                                  *
 * 文件夹: ▲09 查找                *
 *                                  *
 * 文件名: FibonacciSearch.h        *
 *                                  *
 * 内  容: 斐波那契查找相关操作列表 *
 *                                  *
 ************************************/

#ifndef FIBONACCISEARCH_H
#define FIBONACCISEARCH_H

#include "../00 Base/Base.c" 		//**▲09 查找**//

/* 宏定义 */
#define MaxSize 12					//根据Max的值定出来的斐波那契数列项数			
 
/* 斐波那契查找函数列表 */
int Search_Fib(Table T, KeyType key);
/*━━━━━━━━━━━━━━━━━━┓
┃(01)斐波那契法查找关键字key的位置。 ┃
┗━━━━━━━━━━━━━━━━━━*/

#endif 
