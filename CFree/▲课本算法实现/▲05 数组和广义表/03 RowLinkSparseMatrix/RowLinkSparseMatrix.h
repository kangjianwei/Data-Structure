/******************************************************
 *							                          *
 * �ļ���: ��05 ����͹����\03 RowLinkSparseMatrix   *
 *							                          *
 * �ļ���: RowLinkSparseMatrix.h                      *
 *							                          *
 * ��  ��: ���߼����ӵ�˳���ϡ�������ز����б� *
 *                                                    *
 ******************************************************/

#ifndef ROWLINKSPARSEMATRIX_H
#define ROWLINKSPARSEMATRIX_H

#include <stdio.h>
#include <stdarg.h>						//�ṩ��va_list��va_start��va_arg��va_end
#include "../../��01 ����/Status.h"		//**��01 ����**//
#include "../../��01 ����/Scanf.c"		//**��01 ����**//

/* �궨�� */
#define MAXSIZE 400						//�������Ԫ���������ֵΪ400
#define MAXRC	20						//����Ԫ�ظ��������ֵ

/* ���߼����ӵ�ϡ��������Ͷ��� */
typedef int MElemType_RLSq;
typedef struct
{
	int i, j;							//�÷���Ԫ�����±�����±� 
	MElemType_RLSq e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE+1];				//����Ԫ��Ԫ���data[0]δ��
	int rpos[MAXRC+1]; 					//���е�һ������Ԫ����Ԫ����е�λ�ñ� 
	int mu, nu, tu;						//����������������ͷ���Ԫ���� 
}RLSMatrix;

/* ���߼����ӵ�˳���ϡ����󣩻������� */
Status CreateSMatrix_RL(FILE *fp, int n, ...);
/*������������������
��(01)��������M�� ��
������������������*/

void DestroySMatrix_RL(RLSMatrix *M);
/*����������������
��(02)���پ��󡣩�
����������������*/

void PrintSMatrix_RL(RLSMatrix M);
/*����������������
��(03)������󡣩�
����������������*/

void CopySMatrix_RL(RLSMatrix M, RLSMatrix *T);
/*������������������
��(04)����ĸ��ơ���
������������������*/

Status AddSMatri_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);
/*������������������
��(05)Q = M + N�� ��
������������������*/

Status SubSMatrix_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);
/*������������������
��(06)Q = M - N�� ��
������������������*/

Status MultSMatrix_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);
/*��������������������������
��(07)�㷨5.3��Q = M * N����
��������������������������*/

void TransposeSMatrix_RL(RLSMatrix M, RLSMatrix *T);
/*����������������
��(08)����ת�á���
����������������*/

void FastTransposeSMatrix_RL(RLSMatrix M, RLSMatrix *T);
/*��������������������
��(09)�������ת�á���
��������������������*/

#endif
