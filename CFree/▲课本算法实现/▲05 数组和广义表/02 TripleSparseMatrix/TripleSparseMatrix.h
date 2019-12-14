/***************************************************
 *                                                 *
 * 文件夹: ▲05 数组和广义表\02 TripleSparseMatrix *
 *                                                 *
 * 文件名: TripleSparseMatrix.h                    *
 *                                                 *
 * 内  容: 三元组顺序表（稀疏矩阵）相关操作列表    *
 *                                                 *
 ***************************************************/

#ifndef TRIPLESPARSEMATRIX_H
#define TRIPLESPARSEMATRIX_H

#include <stdio.h>
#include <stdarg.h>							//提供宏va_list、va_start、va_arg、va_end
#include "../../▲01 绪论/Status.h"			//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"			//**▲01 绪论**//

/* 宏定义 */
#define MAXSIZE 400							//假设非零元个数的最大值为400

/* 三元组稀疏矩阵类型定义 */
typedef int MElemType_TSq;
typedef struct
{
	int i, j;								//该非零元的行下标和列下标 
	MElemType_TSq e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE+1];					//非零元三元组表，data[0]未用
	int mu, nu, tu;							//矩阵的行数、列数和非零元个数
}TSMatrix;

/* 三元组顺序表（稀疏矩阵）函数列表 */
Status CreateSMatrix_T(FILE *fp, int n, ...);
/*━━━━━━━━━┓
┃(01)创建n个矩阵。 ┃
┗━━━━━━━━━*/

void DestroySMatrix_T(TSMatrix *M);
/*━━━━━━━┓
┃(02)销毁矩阵。┃
┗━━━━━━━*/

void PrintSMatrix_T(TSMatrix M);
/*━━━━━━━┓
┃(03)输出矩阵。┃
┗━━━━━━━*/

void CopySMatrix_T(TSMatrix M, TSMatrix *T);
/*━━━━━━━━┓
┃(04)矩阵的复制。┃
┗━━━━━━━━*/

Status AddSMatri_T(TSMatrix M, TSMatrix N, TSMatrix *Q);
/*━━━━━━━━┓
┃(05)Q = M + N。 ┃
┗━━━━━━━━*/

Status SubSMatrix_T(TSMatrix M, TSMatrix N, TSMatrix *Q);
/*━━━━━━━━┓
┃(06)Q = M - N。 ┃
┗━━━━━━━━*/

Status MultSMatrix_T(TSMatrix M, TSMatrix N, TSMatrix *Q);
/*━━━━━━━━┓
┃(07)Q = M * N。 ┃
┗━━━━━━━━*/

void TransposeSMatrix_T(TSMatrix M, TSMatrix *T);
/*━━━━━━━━━━━━┓
┃(08)算法5.1：矩阵转置。 ┃
┗━━━━━━━━━━━━*/

void FastTransposeSMatrix_T(TSMatrix M, TSMatrix *T);
/*━━━━━━━━━━━━━━┓
┃(09)算法5.2：矩阵快速转置。 ┃
┗━━━━━━━━━━━━━━*/

#endif
