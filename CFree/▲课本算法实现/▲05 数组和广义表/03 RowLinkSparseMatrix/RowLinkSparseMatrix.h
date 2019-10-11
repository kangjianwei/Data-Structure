/******************************************************
 *							                          *
 * 文件夹: ▲05 数组和广义表\03 RowLinkSparseMatrix   *
 *							                          *
 * 文件名: RowLinkSparseMatrix.h                      *
 *							                          *
 * 内  容: 行逻辑链接的顺序表（稀疏矩阵）相关操作列表 *
 *                                                    *
 ******************************************************/

#ifndef ROWLINKSPARSEMATRIX_H
#define ROWLINKSPARSEMATRIX_H

#include <stdio.h>
#include <stdarg.h>						//提供宏va_list、va_start、va_arg、va_end
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"		//**▲01 绪论**//

/* 宏定义 */
#define MAXSIZE 400						//假设非零元个数的最大值为400
#define MAXRC	20						//各行元素个数的最大值

/* 行逻辑链接的稀疏矩阵类型定义 */
typedef int MElemType_RLSq;
typedef struct
{
	int i, j;							//该非零元的行下标和列下标 
	MElemType_RLSq e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE+1];				//非零元三元组表data[0]未用
	int rpos[MAXRC+1]; 					//各行第一个非零元在三元组表中的位置表 
	int mu, nu, tu;						//矩阵的行数、列数和非零元个数 
}RLSMatrix;

/* 行逻辑链接的顺序表（稀疏矩阵）基础操作 */
Status CreateSMatrix_RL(FILE *fp, int n, ...);
/*━━━━━━━━┓
┃(01)创建矩阵M。 ┃
┗━━━━━━━━*/

void DestroySMatrix_RL(RLSMatrix *M);
/*━━━━━━━┓
┃(02)销毁矩阵。┃
┗━━━━━━━*/

void PrintSMatrix_RL(RLSMatrix M);
/*━━━━━━━┓
┃(03)输出矩阵。┃
┗━━━━━━━*/

void CopySMatrix_RL(RLSMatrix M, RLSMatrix *T);
/*━━━━━━━━┓
┃(04)矩阵的复制。┃
┗━━━━━━━━*/

Status AddSMatri_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);
/*━━━━━━━━┓
┃(05)Q = M + N。 ┃
┗━━━━━━━━*/

Status SubSMatrix_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);
/*━━━━━━━━┓
┃(06)Q = M - N。 ┃
┗━━━━━━━━*/

Status MultSMatrix_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);
/*━━━━━━━━━━━━┓
┃(07)算法5.3：Q = M * N。┃
┗━━━━━━━━━━━━*/

void TransposeSMatrix_RL(RLSMatrix M, RLSMatrix *T);
/*━━━━━━━┓
┃(08)矩阵转置。┃
┗━━━━━━━*/

void FastTransposeSMatrix_RL(RLSMatrix M, RLSMatrix *T);
/*━━━━━━━━━┓
┃(09)矩阵快速转置。┃
┗━━━━━━━━━*/

#endif
