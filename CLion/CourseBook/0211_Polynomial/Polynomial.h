/*========================
 * 一元多项式(基于线性链表)
 *
 * 包含算法: 2.22、2.23
 =========================*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>         // 提供malloc、realloc、free、exit原型
#include <string.h>         // 提供 strstr 原型
#include <stdarg.h>         // 提供宏va_list、va_start、va_arg、va_end
#include "ELinkList.h"      //**▲02 线性表**//

/* 一元多项式类型定义 */
typedef ELinkList Polynomial;


/*━━━━━━━━━━━━━━━━━━━━━━ 一元多项式操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * ████████ 算法2.22 ████████
 *
 * 创建
 *
 * 根据输入的系数和指数，创建项数为m的一元多项式
 *
 *
 *【备注】
 *
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 *
 * 如果需要从控制台读取数据，则不需要填写可变参数，
 * 如果需要从文件中读取数据，则需要在可变参数中填写文件名信息(文件名中需要包含子串"TestData")。
 */
void CreatPolyn(Polynomial* P, int m, ...);

/*
 * 销毁
 *
 * 销毁一元多项式。
 */
void DestroyPolyn(Polynomial *P);

/*
 * 计数
 *
 * 返回一元多项式的项数。
 */
int PolynLength(Polynomial P);

/*
 * ████████ 算法2.23 ████████
 *
 * 加法
 *
 * 一元多项式加法Pa=Pa+Pb，
 * 计算完成后，计算结果存到Pa中，并将Pb销毁。
 */
void AddPolyn(Polynomial *Pa, Polynomial *Pb);

/*
 * 减法
 *
 * 一元多项式减法Pa=Pa-Pb，
 * 计算完成后，计算结果存到Pa中，并将Pb销毁。
 */
void SubtractPolyn(Polynomial *Pa, Polynomial *Pb);

/*
 * 乘法
 *
 * 一元多项式乘法Pa=Pa*Pb，
 * 计算完成后，计算结果存到Pa中，并将Pb销毁。
 */
void MultiplyPolyn(Polynomial *Pa, Polynomial *Pb);


/*━━━━━━━━━━━━━━━━━━━━━━ 基础操作 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 输出
 *
 * 打印输出一元多项式。
 */
void PrintPolyn(Polynomial P);

/*
 * 比较
 *
 * 比较c1项和c2项指数大小。
 */
int Cmp(ElemType c1, ElemType c2);

#endif
