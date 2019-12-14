/*========
 * ��ά����
 =========*/

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <stdarg.h>     // �ṩ��va_start��va_arg��va_end
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define MAX_ARRAY_DIM 8 // ���������������ά��Ϊ8

/* ����Ԫ������ */
typedef int ElemType;

/* �����˳��洢��ʾ */
typedef struct {
    ElemType* base;     // ����Ԫ�ػ�ַ���������Ԫ�أ�
    int dim;            // ����ά��
    int* bounds;        // ����ά���ַ����������С�����Ϣ��
    int* constants;     // ����ӳ����������ַ���洢����ĳ��ά��ʱ��ÿ����ҪԽ����Ԫ�ظ�����
} Array;


/*
 * ��ʼ����
 *
 * ��ʼ��ά��Ϊdim�����飬�ɱ����ָʾ��ά�ȵĴ�С��
 */
Status InitArray(Array* A, int dim, ...);

/*
 * ����(�ṹ)��
 *
 * ��������ռ�õĿռ䡣
 */
Status DestroyArray(Array* A);

/*
 * ȡֵ��
 *
 * ��ȡָ���±괦��Ԫ��ֵ���ɱ����Ϊdim���±�ֵ��ָʾ����ȡԪ�������±ꡣ
 */
Status Value(Array A, ElemType* e, ...);

/*
 * ��ֵ��
 *
 * Ϊָ���±괦��Ԫ�ظ�ֵ���ɱ����Ϊdim���±�ֵ��ָʾ����ֵԪ�������±ꡣ
 */
Status Assign(Array* A, ElemType e, ...);

/*
 * ���apָʾ��ֵ������A�е����λ�ã�
 * ����������Ԫ�ص�Ŀ��Ԫ����Ҫ��Խ��Ԫ��������
 */
static Status Locate(Array A, va_list ap, int *off);

/*
 * ����������Ԫ�صĸ���
 *
 *��ע��
 * ��Ϊ�����ĺ���
 */
int Length(Array A);

#endif
