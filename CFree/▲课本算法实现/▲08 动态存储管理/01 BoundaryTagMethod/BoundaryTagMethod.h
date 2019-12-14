/*******************************
 *                             *
 * 文件夹: ▲08 动态存储管理   *
 *                             *
 * 文件名: BoundaryTagMethod.h *
 *                             *
 * 内  容: 边界标识法          *
 *                             *
 *******************************/

#ifndef BOUNDARYTAGMETHOD_H
#define BOUNDARYTAGMETHOD_H

#include <stdio.h>
#include "../../▲01 绪论/Status.h"							//**▲01 绪论**//

/* 宏定义 */
#define MAX 1000
#define E 10						//分配空间时的正误差（即分配空间最多比所需空间多E个字） 
#define FootLoc(p) p+(p)->size-1	//指向p所指结点的底部 

/* 类型定义 */
typedef struct WORD_a				//WORD_a：内存字类型 
{
	union
	{
		struct WORD_a *llink;		//头部域，指向前驱结点 
		struct WORD_a *uplink;		//底部域，指向本结点头部 
	}Ptr;
	
	int tag;						//块标志，0空闲，1占用，头部和尾部均有 
	int size;						//头部域，块大小 
	struct WORD_a *rlink;			//头部域，指向后继结点 
}WORD_a;
typedef WORD_a* Space;				//Space：可利用空间指针类型 

/* 全局变量 */
Space av;							//整个内存块的起始地址 

/* 边界标识法函数列表 */
void InitSpace_a(WORD_a memory[MAX+2]);
/*━━━━━━━━━━━━━┓
┃(01)初始化一块空闲内存块。┃
┗━━━━━━━━━━━━━*/

Space AllocBoundTag(Space *pav, int n);
/*━━━━━━━━━━━━━━━━━━━┓
┃(02)算法8.1：分配算法（首次拟合法）。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

void Reclaim_a(Space *pav, Space *p);
/*━━━━━━━┓
┃(03)回收算法。┃
┗━━━━━━━*/

void PrintLayout_a(Space av, Space pav);
/*━━━━━━━━━━━━━━━━┓
┃(04)输出当前空闲内存块起止地址。┃
┗━━━━━━━━━━━━━━━━*/

#endif 
