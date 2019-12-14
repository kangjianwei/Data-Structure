/**********************************************
 *                                            *
 * �ļ���: ��05 ����͹����\01 SequenceArray *
 *                                            *
 * �ļ���: SequenceArray.h                    *
 *                                            *
 * ��  ��: ������ز����б�                   *
 *                                            *
 **********************************************/

#ifndef SEQUENCEARRAY_H
#define SEQUENCEARRAY_H

#include <stdio.h>
#include <stdlib.h>								//�ṩmalloc��realloc��free��exitԭ��
#include <stdarg.h>								//�ṩ��va_start��va_arg��va_end 
#include "../../��01 ����/Status.h"				//**��01 ����**//

/* �궨�� */
#define MAX_ARRAY_DIM 8							//��������ά��Ϊ8 

/* �������Ͷ��� */
typedef int AElemType_Sq;
typedef struct									//�����˳��洢��ʾ
{
	AElemType_Sq *base;							//����Ԫ�ػ�ַ���������Ԫ�أ� 
	int dim;									//����ά�� 
	int *bounds;								//����ά���ַ����������С�����Ϣ��
	int *constants;								//����ӳ����������ַ���洢��Խĳ��ά��ʱ��ҪԽ����Ԫ�ظ����� 
}Array;							

/* ���麯���б� */
Status InitArray(Array *A, int dim, ...);
/*������������������������������
��(01)��ʼ��ά��Ϊdim�����顣 ��
������������������������������*/

Status DestroyArray(Array *A);
/*����������������
��(02)�������顣��
����������������*/ 

Status LocateArray(Array A, va_list ap, int *off);
/*������������������������������������������
��(03)���apָʾ��ֵ������A�е����λ�á� ��
������������������������������������������*/

Status ValueArray(Array A, AElemType_Sq *e, ...);
/*������������������������������������
��(04)ȡֵ���ɱ������dim���±�ֵ�� ��
������������������������������������*/

Status AssignArray(Array *A, AElemType_Sq e, ...);
/*������������������������������������
��(05)��ֵ���ɱ������dim���±�ֵ�� ��
������������������������������������*/

void ArrayPrint(Array A);
/*������������������������������
��(06)��������������������ݡ���
������������������������������*/

#endif
