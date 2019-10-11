/********************************
 *                              *
 * 文件夹: ▲10 内部排序        *
 *                              *
 * 文件名: RadixSort.h          *
 *                              *
 * 内  容: 基数排序相关操作列表 *
 *                              *
 ********************************/

#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <stdio.h>
#include "../../▲01 绪论/Status.h"			//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"			//**▲01 绪论**//

#define MAX_NUM_OF_KEY 8					//关键字项数的最大值 
#define RADIX 10							//关键字基数，此时是十进制整数的基数 
#define MAX_SPACE 10000

#define ord(ch) ((ch)-'0') 
#define succ(x) ((x)+1)

/* 静态链表的结点类型 */
typedef char KeysType;
typedef struct
{
	KeysType keys[MAX_NUM_OF_KEY];			//关键字 
	int next;
}SLCell;

/* 静态链表类型 */
typedef struct
{
	SLCell r[MAX_SPACE];					//静态链表的可利用空间，r[0]为头结点 
	int keynum;								//记录的当前关键字个数 
	int recnum;								//静态链表当前长度 
}SLList;

/* 指针数组类型 */
typedef int ArrType[RADIX];					//指针数组类型 

/* 基数排序函数列表 */
void CreateSLList(FILE *fp, SLList *L);
/*━━━━━━━━━━┓
┃(01)创建静态链表L。 ┃
┗━━━━━━━━━━*/

void Traverse(SLList L);
/*━━━━━━━━━━━━━━━━━┓
┃(02)输出静态链表L中的关键字记录。 ┃
┗━━━━━━━━━━━━━━━━━*/

void RadixSort(SLList *L);
/*━━━━━━━━━━━━━━━━━━━┓
┃(03)算法10.17：对静态链表L作基数排序。┃
┗━━━━━━━━━━━━━━━━━━━*/

void Distribute(SLCell *r, int i, ArrType f, ArrType e);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(04)算法10.15：分配算法，按第i个关键字keys[i]建立RADIX个子表，使同一子表中记录的keys[i]相同。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void Collect(SLCell *r, int i, ArrType f, ArrType e); 
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(05)算法10.16：收集算法，按keys[i]从小到大地将f[0..RADIX-1]所指各子表依次链接成一个链表。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

#endif 
