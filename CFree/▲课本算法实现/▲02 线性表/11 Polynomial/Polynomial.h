/*************************************
 *						             *
 * 文件夹: ▲02 线性表\11 Polynomial *
 * 							         *
 * 文件名: Polynomial.h              *
 * 							         *
 * 内  容: 一元多项式相关操作列表    *
 *                                   *
 *************************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>						//提供malloc、realloc、free、exit原型

/* 多项式类型定义 */
typedef struct							//用来表示多项式的项 
{
	float	coef;						//系数 
	int		expn;						//指数 
}LElemType_E;							//重新定义扩展的线性表中元素类型 
#include "../09 ExtenLinkedList/ExtenLinkedList.c"//**▲02 线性表**//
typedef LElemType_E  ElemType_P;		//一元多项式项的类型 
typedef ELinkList  Polynomial;			//一元多项式		

/* 一元多项式函数列表 */
void CreatPolyn_P(FILE *fp, Polynomial *P, int m); 
/*━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法2.22：创建项数为m的一元多项式。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

void DestroyPolyn_P(Polynomial *P);
/*━━━━━━━━━━┓
┃(02)销毁一元多项式。┃
┗━━━━━━━━━━*/

int PolynLength_P(Polynomial P);
/*━━━━━━━━━━━━━┓
┃(03)返回一元多项式的项数。┃
┗━━━━━━━━━━━━━*/

void AddPolyn_P(Polynomial *Pa, Polynomial *Pb);
/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃(04)算法2.23：一元多项式加法Pa=Pa+Pb，销毁Pb。┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/

void SubtractPolyn_P(Polynomial *Pa, Polynomial *Pb);
/*━━━━━━━━━━━━━━━━━━┓
┃(05)一元多项式减法Pa=Pa-Pb，销毁Pb。┃
┗━━━━━━━━━━━━━━━━━━*/

void MultiplyPolyn_P(Polynomial *Pa, Polynomial *Pb);
/*━━━━━━━━━━━━━━━━━━┓
┃(06)一元多项式乘法Pa=Pa*Pb，销毁Pb。┃
┗━━━━━━━━━━━━━━━━━━*/

int Cmp_exp(ElemType_P c1, ElemType_P c2);
/*━━━━━━━━━━━━━━┓
┃(07)比较c1项和c2项指数大小。┃
┗━━━━━━━━━━━━━━*/

void PrintPolyn_P(Polynomial P);
/*━━━━━━━━━━━━┓
┃(08)打印输出一元多项式。┃
┗━━━━━━━━━━━━*/

#endif
