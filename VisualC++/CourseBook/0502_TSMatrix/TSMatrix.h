/*=======================
 * ��Ԫ��˳���ϡ�����
 *
 * �����㷨: 5.1��5.2
 ========================*/

#ifndef TSMATRIX_H
#define TSMATRIX_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc ԭ��
#include <string.h>     // �ṩ strstr ԭ��
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define MAXSIZE 12500   // ����Ԫ���������ֵ

/* ��Ԫ��ϡ�����Ԫ������ */
typedef int ElemType;

/* ��Ԫ�����Ͷ��壬��Ҫ�����洢����Ԫ */
typedef struct {
    int i, j;       // ����Ԫ�����Ԫ�����±�����±�
    ElemType e;
} Triple;

/* ��Ԫ��ϡ��������Ͷ��� */
typedef struct {
    Triple data[MAXSIZE + 1];   // ����Ԫ��Ԫ���data[0]δ��
    int mu, nu, tu;             // ����������������ͷ���Ԫ����
} TSMatrix;


/*
 * ����ϡ�����M
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status CreateSMatrix(TSMatrix* M, char* path);

/*
 * ����ϡ�����
 *
 *��ע��
 * ��Ԫ��˳���Ľṹ�޷����١�
 */
Status DestroySMatrix(TSMatrix* M);

/*
 * ������
 *
 * ����һ���¾���T���þ�������˴Ӿ���M�а��������ݡ�
 */
Status CopySMatrix(TSMatrix M, TSMatrix* T);

/*
 * ����ӷ�
 *
 * Q = M + N��
 */
Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);

/*
 * �������
 *
 * Q = M - N��
 */
Status SubSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);

/*
 * ����˷�
 *
 * Q = M * N������ʵ�ֵ��Ǵ�ͳ����˷���
 */
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);

/*
 * ���������������� �㷨5.1 ����������������
 *
 * ����ת��
 */
Status TransposeSMatrix(TSMatrix M, TSMatrix* T);

/*
 * ���������������� �㷨5.2 ����������������
 *
 * �������ת��
 */
Status FastTransposeSMatrix(TSMatrix M, TSMatrix* T);

/*
 * �������
 */
void PrintSMatrix(TSMatrix M);

#endif
