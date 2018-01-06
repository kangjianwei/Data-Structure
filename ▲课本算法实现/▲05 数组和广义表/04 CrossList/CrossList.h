/********************************************
 * 							                *
 * 文件夹: ▲05 数组和广义表\04 CrossList   *
 * 							                *
 * 文件名: CrossList.h                      *
 * 							                *
 * 内  容: 十字链表（稀疏矩阵）相关操作列表 *
 *                                          *
 ********************************************/

#ifndef CROSSLIST_H
#define CROSSLIST_H

#include <stdio.h>
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include <stdarg.h>						//提供宏va_list、va_start、va_arg、va_end
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"		//**▲01 绪论**//

/* 十字链表类型定义 */
typedef int CElemType;
typedef struct OLNode 
{
	int i, j;				//该非零元的行下标和列下标 
	CElemType e;
	struct OLNode *right;	//该非零元所在的行表的后继链域 
	struct OLNode *down;	//该非零元所在的列表的后继链域
}OLNode;
typedef OLNode *OLink;		//指向某一结点的指针 
typedef struct
{
	OLink *rhead;			//行链表头指针 
	OLink *chead;			//列链表头指针 
	int mu, nu, tu;			//矩阵的行数、列数和非零元个数 
}CrossList;

/* 十字链表（稀疏矩阵）函数列表 */
Status CreateSMatrix_OL(FILE *fp, int n, ...);
/*━━━━━━━━━━━━┓
┃(01)算法5.4：创建矩阵M。┃
┗━━━━━━━━━━━━*/

void DestroySMatrix_OL(CrossList *M);
/*━━━━━━━┓
┃(02)销毁矩阵。┃
┗━━━━━━━*/

void PrintSMatrix_OL(CrossList M);
/*━━━━━━━┓
┃(03)输出矩阵。┃
┗━━━━━━━*/

void CopySMatrix_OL(CrossList M, CrossList *T);
/*━━━━━━━━┓
┃(04)矩阵的复制。┃
┗━━━━━━━━*/

Status AddSMatri_OL(CrossList M, CrossList N, CrossList *Q);
/*━━━━━━━━┓
┃(05)Q = M + N。 ┃
┗━━━━━━━━*/

Status SubSMatrix_OL(CrossList M, CrossList N, CrossList *Q);
/*━━━━━━━━┓
┃(06)Q = M - N。 ┃
┗━━━━━━━━*/

Status MultSMatrix_OL(CrossList M, CrossList N, CrossList *Q);
/*━━━━━━━━┓
┃(07)Q = M * N。 ┃
┗━━━━━━━━*/

void TransposeSMatrix_OL(CrossList M, CrossList *T);
/*━━━━━━━┓
┃(08)矩阵转置。┃
┗━━━━━━━*/

#endif
