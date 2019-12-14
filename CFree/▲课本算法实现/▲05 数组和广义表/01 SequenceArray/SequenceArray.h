/**********************************************
 *                                            *
 * 文件夹: ▲05 数组和广义表\01 SequenceArray *
 *                                            *
 * 文件名: SequenceArray.h                    *
 *                                            *
 * 内  容: 数组相关操作列表                   *
 *                                            *
 **********************************************/

#ifndef SEQUENCEARRAY_H
#define SEQUENCEARRAY_H

#include <stdio.h>
#include <stdlib.h>								//提供malloc、realloc、free、exit原型
#include <stdarg.h>								//提供宏va_start、va_arg、va_end 
#include "../../▲01 绪论/Status.h"				//**▲01 绪论**//

/* 宏定义 */
#define MAX_ARRAY_DIM 8							//数组的最大维度为8 

/* 数组类型定义 */
typedef int AElemType_Sq;
typedef struct									//数组的顺序存储表示
{
	AElemType_Sq *base;							//数组元素基址（存放数组元素） 
	int dim;									//数组维数 
	int *bounds;								//数组维界基址（存放数组行、列信息）
	int *constants;								//数组映像函数常量基址（存储跨越某个维度时需要越过的元素个数） 
}Array;							

/* 数组函数列表 */
Status InitArray(Array *A, int dim, ...);
/*━━━━━━━━━━━━━━┓
┃(01)初始化维数为dim的数组。 ┃
┗━━━━━━━━━━━━━━*/

Status DestroyArray(Array *A);
/*━━━━━━━┓
┃(02)销毁数组。┃
┗━━━━━━━*/ 

Status LocateArray(Array A, va_list ap, int *off);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(03)求出ap指示的值在数组A中的相对位置。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

Status ValueArray(Array A, AElemType_Sq *e, ...);
/*━━━━━━━━━━━━━━━━━┓
┃(04)取值，可变参数是dim个下标值。 ┃
┗━━━━━━━━━━━━━━━━━*/

Status AssignArray(Array *A, AElemType_Sq e, ...);
/*━━━━━━━━━━━━━━━━━┓
┃(05)赋值，可变参数是dim个下标值。 ┃
┗━━━━━━━━━━━━━━━━━*/

void ArrayPrint(Array A);
/*━━━━━━━━━━━━━━┓
┃(06)按行依次输出数组中内容。┃
┗━━━━━━━━━━━━━━*/

#endif
