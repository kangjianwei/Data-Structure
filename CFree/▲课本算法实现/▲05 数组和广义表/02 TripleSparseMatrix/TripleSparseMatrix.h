/***************************************************
 *                                                 *
 * �ļ���: ��05 ����͹����\02 TripleSparseMatrix *
 *                                                 *
 * �ļ���: TripleSparseMatrix.h                    *
 *                                                 *
 * ��  ��: ��Ԫ��˳���ϡ�������ز����б�    *
 *                                                 *
 ***************************************************/

#ifndef TRIPLESPARSEMATRIX_H
#define TRIPLESPARSEMATRIX_H

#include <stdio.h>
#include <stdarg.h>							//�ṩ��va_list��va_start��va_arg��va_end
#include "../../��01 ����/Status.h"			//**��01 ����**//
#include "../../��01 ����/Scanf.c"			//**��01 ����**//

/* �궨�� */
#define MAXSIZE 400							//�������Ԫ���������ֵΪ400

/* ��Ԫ��ϡ��������Ͷ��� */
typedef int MElemType_TSq;
typedef struct
{
	int i, j;								//�÷���Ԫ�����±�����±� 
	MElemType_TSq e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE+1];					//����Ԫ��Ԫ���data[0]δ��
	int mu, nu, tu;							//����������������ͷ���Ԫ����
}TSMatrix;

/* ��Ԫ��˳���ϡ����󣩺����б� */
Status CreateSMatrix_T(FILE *fp, int n, ...);
/*��������������������
��(01)����n������ ��
��������������������*/

void DestroySMatrix_T(TSMatrix *M);
/*����������������
��(02)���پ��󡣩�
����������������*/

void PrintSMatrix_T(TSMatrix M);
/*����������������
��(03)������󡣩�
����������������*/

void CopySMatrix_T(TSMatrix M, TSMatrix *T);
/*������������������
��(04)����ĸ��ơ���
������������������*/

Status AddSMatri_T(TSMatrix M, TSMatrix N, TSMatrix *Q);
/*������������������
��(05)Q = M + N�� ��
������������������*/

Status SubSMatrix_T(TSMatrix M, TSMatrix N, TSMatrix *Q);
/*������������������
��(06)Q = M - N�� ��
������������������*/

Status MultSMatrix_T(TSMatrix M, TSMatrix N, TSMatrix *Q);
/*������������������
��(07)Q = M * N�� ��
������������������*/

void TransposeSMatrix_T(TSMatrix M, TSMatrix *T);
/*��������������������������
��(08)�㷨5.1������ת�á� ��
��������������������������*/

void FastTransposeSMatrix_T(TSMatrix M, TSMatrix *T);
/*������������������������������
��(09)�㷨5.2���������ת�á� ��
������������������������������*/

#endif
