/******************************************
 *                                        *
 * 文件夹: ▲10 内部排序                  *
 *                                        *
 * 文件名: SequenceListType.h             *
 *                                        *
 * 内  容: 顺序表存储结构，供本章算法调用 *
 *                                        *
 ******************************************/

#ifndef SEQUENCELISTTYPE_H
#define SEQUENCELISTTYPE_H

#include <stdio.h>
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"		//**▲01 绪论**//

/* 宏定义 */
#ifndef MAXSIZE
#define MAXSIZE 20						//一个用作示例的小顺序表的最大长度
#endif 
#define LT(a,b) ((a)<(b))					
#define LQ(a,b) ((a)<=(b))

/* 类型定义 */
typedef int KeyType;					//定义关键字类型为整数类型
typedef struct							//顺序表结构 
{
	KeyType key;						//关键字项 
	//使用结构体便于使用中扩展 
}RcdType;								//记录类型
typedef struct
{
	RcdType r[MAXSIZE+1];				//r[0]闲置或用作哨兵单元
	int length;							//顺序表长度 
}SqList_sort;							//顺序表类型 

/* 顺序表存储结构函数列表 */
Status CreateSortList(FILE *fp, SqList_sort *L);
/*━━━━━━━━━━━━━━┓
┃(01)创建一个任意顺序的序列。┃
┗━━━━━━━━━━━━━━*/

void Traverse(SqList_sort L, void(Visit)(KeyType));
/*━━━━━━━━┓
┃(02)输出序列L。 ┃
┗━━━━━━━━*/

#endif 
