/***************************************
 *							           *
 * 文件夹: ▲06 树和二叉树\10 PowerSet *
 * 						               *
 * 文件名: PowerSet.h                  *
 * 						               *
 * 内  容: 幂集相关操作列表            *
 * 						               *
 ***************************************/

#ifndef POWERSET_H
#define POWERSET_H

#include <stdio.h>
#include "../../▲01 绪论/Status.h"					//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"					//**▲01 绪论**//
#include "../../▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**// 

/* 幂集类型定义 */
typedef LElemType_L PElemType;

/* 幂集函数列表 */
Status CreatePowerSet_PS(FILE *fp, LinkList *A);
/*━━━━━━━━━━━━━━━┓
┃(01)创建集合A，集合元素为int。┃
┗━━━━━━━━━━━━━━━*/

void GetPowerSet_PS(int i, LinkList A, LinkList B);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法6.14 && 6.15：求取集合A的幂集，集合B暂存每一次求出的幂集子集。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void Output_PS(LinkList A);
/*━━━━━━━━━━━━━┓
┃(03)构造空树HT(初始化树)。┃
┗━━━━━━━━━━━━━*/

#endif
