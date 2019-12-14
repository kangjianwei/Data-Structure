/*===================
 * ʮ������ϡ�����
 *
 * �����㷨: 5.4
 ====================*/

#ifndef CROSSLIST_H
#define CROSSLIST_H

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <string.h>     // �ṩ strstr ԭ��
#include "Status.h"     //**��01 ����**//

/* ʮ������Ԫ������ */
typedef int ElemType;

/* ����Ԫ���Ͷ��� */
typedef struct OLNode {
    int i, j;               // �÷���Ԫ�����±�����±�
    ElemType e;
    struct OLNode* right;   // �÷���Ԫ���ڵ��б�ĺ������
    struct OLNode* down;    // �÷���Ԫ���ڵ��б�ĺ������
} OLNode, * OLink;

/* ʮ���������Ͷ��� */
typedef struct {
    OLink* rhead;       // ������ͷָ��
    OLink* chead;       // ������ͷָ��
    int mu, nu, tu;     // ����������������ͷ���Ԫ����
} CrossList;


/*
 * ���������������� �㷨5.4 ����������������
 *
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
Status CreateSMatrix(CrossList* M, char* path);

/*
 * ����ϡ�����
 */
Status DestroySMatrix(CrossList* M);

/*
 * ������
 *
 * ����һ���¾���T���þ�������˴Ӿ���M�а��������ݡ�
 */
Status CopySMatrix(CrossList M, CrossList* T);

/*
 * ����ӷ�
 *
 * Q = M + N��
 */
Status AddSMatrix(CrossList M, CrossList N, CrossList* Q);

/*
 * �������
 *
 * Q = M - N��
 */
Status SubSMatrix(CrossList M, CrossList N, CrossList* Q);

/*
 * ����˷�
 *
 * Q = M * N��
 */
Status MultSMatrix(CrossList M, CrossList N, CrossList* Q);

/*
 * ����ת��
 */
Status TransposeSMatrix(CrossList M, CrossList* T);

/*
 * �������
 */
void PrintSMatrix(CrossList M);

#endif
