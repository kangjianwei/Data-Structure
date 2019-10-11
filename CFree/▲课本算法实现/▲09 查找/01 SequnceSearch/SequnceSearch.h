/******************************************
 *                                        *
 * 文件夹: ▲09 查找                      *
 *                                        *
 * 文件名: SequnceSearch.h                *
 *                                        *
 * 内  容: 顺序查找（无序表）相关操作列表 *
 *                                        *
 ******************************************/

#ifndef SEQUNCESEARCH_H
#define SEQUNCESEARCH_H

#include "../00 Base/Base.c" 					//**▲09 查找**//

/* 宏函数 */
#define EQ(a,b) ((a)==(b))
 
/* 顺序查找函数列表 */
int Search_Seq(Table T, KeyType key);
/*━━━━━━━━━━━━━━━━━━━┓
┃(01)算法9.1：顺序查找关键字key的位置。┃
┗━━━━━━━━━━━━━━━━━━━*/

#endif 
