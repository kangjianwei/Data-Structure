/*======================
 * ϡ���������ϰ��5.25
 =======================*/

#ifndef SMATRIX_H
#define SMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"    //**��01 ����**//

/* �궨�� */
#define Mu      20      // ��������������ֵΪ20
#define Nu      20      // ��������������ֵΪ20
#define MAXSIZE 400     // �������Ԫ���������ֵΪ400

/* ϡ��������Ͷ��� */
typedef struct {
    int V[MAXSIZE];     // �洢�����Ԫ��
    int B[Mu][Nu];      // ��Ǿ����и�λ��Ԫ���Ƿ�Ϊ����Ԫ
    int mu, nu, tu;     // ��������������������Ԫ����
} SMatrix;


// ����ϡ�����M
Status CreateSMatrix(SMatrix* M, char* path);

// ���ϡ�����M
void PrintSMatrix(SMatrix M);

#endif
