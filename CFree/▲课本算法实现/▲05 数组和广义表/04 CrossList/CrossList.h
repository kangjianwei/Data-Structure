/********************************************
 * 							                *
 * �ļ���: ��05 ����͹����\04 CrossList   *
 * 							                *
 * �ļ���: CrossList.h                      *
 * 							                *
 * ��  ��: ʮ������ϡ�������ز����б� *
 *                                          *
 ********************************************/

#ifndef CROSSLIST_H
#define CROSSLIST_H

#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
#include <stdarg.h>						//�ṩ��va_list��va_start��va_arg��va_end
#include "../../��01 ����/Status.h"		//**��01 ����**//
#include "../../��01 ����/Scanf.c"		//**��01 ����**//

/* ʮ���������Ͷ��� */
typedef int CElemType;
typedef struct OLNode 
{
	int i, j;				//�÷���Ԫ�����±�����±� 
	CElemType e;
	struct OLNode *right;	//�÷���Ԫ���ڵ��б�ĺ������ 
	struct OLNode *down;	//�÷���Ԫ���ڵ��б�ĺ������
}OLNode;
typedef OLNode *OLink;		//ָ��ĳһ����ָ�� 
typedef struct
{
	OLink *rhead;			//������ͷָ�� 
	OLink *chead;			//������ͷָ�� 
	int mu, nu, tu;			//����������������ͷ���Ԫ���� 
}CrossList;

/* ʮ������ϡ����󣩺����б� */
Status CreateSMatrix_OL(FILE *fp, int n, ...);
/*��������������������������
��(01)�㷨5.4����������M����
��������������������������*/

void DestroySMatrix_OL(CrossList *M);
/*����������������
��(02)���پ��󡣩�
����������������*/

void PrintSMatrix_OL(CrossList M);
/*����������������
��(03)������󡣩�
����������������*/

void CopySMatrix_OL(CrossList M, CrossList *T);
/*������������������
��(04)����ĸ��ơ���
������������������*/

Status AddSMatri_OL(CrossList M, CrossList N, CrossList *Q);
/*������������������
��(05)Q = M + N�� ��
������������������*/

Status SubSMatrix_OL(CrossList M, CrossList N, CrossList *Q);
/*������������������
��(06)Q = M - N�� ��
������������������*/

Status MultSMatrix_OL(CrossList M, CrossList N, CrossList *Q);
/*������������������
��(07)Q = M * N�� ��
������������������*/

void TransposeSMatrix_OL(CrossList M, CrossList *T);
/*����������������
��(08)����ת�á���
����������������*/

#endif
