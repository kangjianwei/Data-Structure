/*=============================
 * �������Ķ�������洢�ṹ
 *
 * �����㷨: 6.1��6.2��6.3��6.4
 =============================*/

#ifndef BITREE_H
#define BITREE_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��free ԭ��
#include <string.h>     // �ṩ memset��strcmp ԭ��
#include <math.h>       // �ṩ pow ԭ��
#include "Status.h"     //**��01 ����**//

/* ������Ԫ�����Ͷ��壬���������Ԫ������Ϊchar */
typedef char TElemType;

/* ��������㶨�� */
typedef struct BiTNode {
    TElemType data;             // ���Ԫ��
    struct BiTNode* lchild;     // ����ָ��
    struct BiTNode* rchild;     // �Һ���ָ��
} BiTNode;

/* ָ�����������ָ�� */
typedef BiTNode* BiTree;


/*
 * ��ʼ��
 *
 * ����ն�������
 */
Status InitBiTree(BiTree* T);

/*
 * �ÿ�
 *
 * ����������е����ݣ�ʹ���Ϊ������
 */
Status ClearBiTree(BiTree* T);

/*
 * ���������������� �㷨6.4 ����������������
 *
 * ����
 *
 * ����Ԥ��Ķ�����������������
 * ����Լ��ʹ�á��������С���������������
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
Status CreateBiTree(BiTree* T, char* path);

/*
 * �п�
 *
 * �ж϶������Ƿ�Ϊ������
 */
Status BiTreeEmpty(BiTree T);

/*
 * ����
 *
 * ���ض���������ȣ���������
 */
int BiTreeDepth(BiTree T);


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������������ڲ�����
static void CreateTree(BiTree* T, FILE* fp);


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ�������ڲ�����ʹ��
void PrintGraph(BiTree T);

#endif
