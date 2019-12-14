/*======================
 * ϡ���������ϰ��5.24
 =======================*/

#ifndef SMATRIX_H
#define SMATRIX_H

#include <stdio.h>
#include "Status.h"    //**��01 ����**//

#define MAXSIZE 100 // �������Ԫ���������ֵΪ400

/* ����Ԫ���� */
typedef struct {
    int seq;    // �÷���Ԫ�ھ����е���ţ�������Ϊ����
    int e;
} SElem;

/* ϡ����� */
typedef struct {
    SElem data[MAXSIZE + 1]; // �洢������Ԫ�أ�data[0]δ��
    int mu, nu, tu;          // ����������������ͷ���Ԫ����
} SMatrix;


// ����ϡ�����M
Status CreateSMatrix(SMatrix* M, char* path);

// ���ϡ�����M
void PrintSMatrix(SMatrix M);

#endif
