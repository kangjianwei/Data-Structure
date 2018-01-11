/********************************************
 *                                          *
 * 文件夹: ▲10 内部排序                    *
 *                                          *
 * 文件名: StaticLinkedListType.h           *
 *                                          *
 * 内  容: 静态链表存储结构，供本章算法调用 *
 *                                          *
 ********************************************/

#ifndef STATICLINKEDLISTTYPE_H
#define STATICLINKEDLISTTYPE_H

#include <stdio.h>
#include <limits.h>
#include "../../▲01 绪论/Status.h"			//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"			//**▲01 绪论**//

/* 宏定义 */
#define MAXSIZE 100							//静态链表容量  
#define MAXINT INT_MAX
#define LT(a,b) ((a)<(b))					

/* 类型定义 */
typedef int KeyType;						//定义关键字类型为整数类型
typedef struct								//静态链表
{
	KeyType key;							//关键字项
	//使用结构体便于使用中扩展
}RcdType;									//记录类型
typedef struct
{
	RcdType rc;								//记录项 
	int next;								//指针项 
}SLNode;									//表结点类型 
typedef struct
{
	SLNode r[MAXSIZE];						//0号单元为表头结点 
	int length;								//链表当前长度 
}SLinkList_sort;							//静态链表类型 

/* 静态链表存储结构函数列表 */
Status CreateSortList(FILE *fp, SLinkList_sort *L);
/*━━━━━━━━━━━━━━┓
┃(01)创建一个任意顺序的序列。┃
┗━━━━━━━━━━━━━━*/

void Traverse(SLinkList_sort L, void(Visit)(KeyType));
/*━━━━━━━━┓
┃(02)输出序列L。 ┃
┗━━━━━━━━*/

#endif 
