/*****************************
 *                           *
 * 文件夹: ▲08 动态存储管理 *
 *                           *
 * 文件名: BuddySystem.h     *
 *                           *
 * 内  容: 伙伴系统          *
 *                           *
 *****************************/

#ifndef BUDDYSYSTEM_H
#define BUDDYSYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../▲01 绪论/Status.h"							//**▲01 绪论**//

/* 宏定义 */
#define M 3						//可利用空间总容量64k字的2的幂次，子表的个数为M+1 

/* 类型定义 */
typedef struct WORD_b
{ 
	struct WORD_b *llink;		//指向前驱结点 
	int tag;					//块标志，0空闲，1占用 
	int kval;					//块大小，值为2的幂次k 
	struct WORD_b *rlink;		//头部域，指向后继结点 
}WORD_b;						//WORD_b：内存字类型，结点的第一个字也称为head 
typedef struct HeadNode
{
	int nodesize;				//该链表的空闲块的大小 
	WORD_b *first;				//该链表的表头指针 
}FreeList[M+1];					//表头向量类型 

/* 全局变量 */
WORD_b *start, *end;			//内存起点和终点 
 
/* 伙伴系统函数列表 */
void InitSpace_b(FreeList avail);
/*━━━━━━━━━━━━━┓
┃(01)初始化一块空闲内存块。┃
┗━━━━━━━━━━━━━*/

WORD_b* AllocBuddy(FreeList avail, int n);
/*━━━━━━━━━━━━┓
┃(02)算法8.2：分配算法。 ┃
┗━━━━━━━━━━━━*/

WORD_b* Buddy(WORD_b* p); 
/*━━━━━━━━━━━━━━━━━━┓
┃(03)返回p处内存块的伙伴内存块地址。 ┃
┗━━━━━━━━━━━━━━━━━━*/

void Reclaim_b(FreeList avail, WORD_b** p);
/*━━━━━━━┓
┃(04)回收算法。┃
┗━━━━━━━*/

void PrintLayout_b(FreeList avail);
/*━━━━━━━━━━━━━━━━┓
┃(05)输出当前空闲内存块起止地址。┃
┗━━━━━━━━━━━━━━━━*/

#endif 
