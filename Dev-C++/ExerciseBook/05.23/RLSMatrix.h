/*=============================
 * ���߼����ӵ�˳���ϡ�����
 *
 * �����㷨: 5.3
 ==============================*/

#ifndef RLSMATRIX_H
#define RLSMATRIX_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc ԭ��
#include <string.h>     // �ṩ strstr ԭ��
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define MAXSIZE 12500   // ����Ԫ���������ֵ
#define MAXRC      20   // ����Ԫ�ظ��������ֵ

/* ���߼����ӵ�ϡ�����Ԫ������ */
typedef int ElemType;

/* ��Ԫ�����Ͷ��壬��Ҫ�����洢����Ԫ */
typedef struct {
    int i, j;       // �÷���Ԫ�����±�����±�
    ElemType e;
} Triple;

/* ���߼����ӵ�ϡ��������Ͷ��� */
typedef struct {
    Triple data[MAXSIZE + 1];   // ����Ԫ��Ԫ���data[0]δ��
    int rpos[MAXRC + 1];        // ���е�һ������Ԫ����Ԫ����е�λ�ñ�rpos[0]δ��
    int mu, nu, tu;             // ����������������ͷ���Ԫ����
} RLSMatrix;


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
Status CreateSMatrix(RLSMatrix* M, char* path);

/*
 * ����ϡ�����
 *
 *��ע��
 * ���߼����ӵ�˳���ṹ�޷����١�
 */
Status DestroySMatrix(RLSMatrix* M);

/*
 * ������
 *
 * ����һ���¾���T���þ�������˴Ӿ���M�а��������ݡ�
 */
Status CopySMatrix(RLSMatrix M, RLSMatrix* T);

/*
 * ����ӷ�
 *
 * Q = M + N��
 */
Status AddSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix* Q);

/*
 * �������
 *
 * Q = M - N��
 */
Status SubSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix* Q);

/*
 * ���������������� �㷨5.3 ����������������
 *
 * ����˷�
 *
 * Q = M * N��
 */
Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix* Q);

/*
 * ����ת��
 */
Status TransposeSMatrix(RLSMatrix M, RLSMatrix* T);

/*
 * �������ת��
 */
Status FastTransposeSMatrix(RLSMatrix M, RLSMatrix* T);

/*
 * �������
 */
void PrintSMatrix(RLSMatrix M);

// Ϊrpos���鸳ֵ
static void AssignRpos(RLSMatrix* M);

#endif
