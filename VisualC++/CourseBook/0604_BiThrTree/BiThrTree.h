/*=======================
 * ����������
 *
 * �����㷨: 6.5��6.6��6.7
 ========================*/

#ifndef BITHRTREE_H
#define BITHRTREE_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��free ԭ��
#include <string.h>     // �ṩ memset��strcmp ԭ��
#include <math.h>       // �ṩ pow ԭ��
#include "Status.h"     //**��01 ����**//

/* ����������������ͱ�� */
typedef enum {
    Link, Thread    // Link==0��ָ��(����)��Thread==1������
} PointerTag;

/* ����������Ԫ�����Ͷ��壬���������Ԫ������Ϊchar */
typedef char TElemType;

/* ������������㶨�� */
typedef struct BiThrNode {
    TElemType data;             // ���Ԫ��
    struct BiThrNode* lchild;   // ����ָ��
    struct BiThrNode* rchild;   // �Һ���ָ��
    PointerTag LTag;            // ��ָ����
    PointerTag RTag;            // ��ָ����
} BiThrNode;

/* ָ����������������ָ�� */
typedef BiThrNode* BiThrTree;


/* ȫ�ֱ��� */
static BiThrTree pre;   // ָ��ǰ���ʽ�����һ����㣨ǰ����


/*
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
Status CreateBiTree(BiThrTree* T, char* path);

/*
 * ���������������� �㷨6.6 ����������������
 *
 * �������������T��������ȫ������Ϊ����������Thrt��
 * ע���������������ǰ����������������
 */
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T);

/*
 * ���������������� �㷨6.5 ����������������
 *
 * �����������ȫ����������T���ǵݹ��㷨����
 */
Status InOrderTraverse_Thr(BiThrTree T, Status(Visit)(TElemType));


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������������ڲ�����
static void CreateTree(BiThrTree* T, FILE* fp);

/*
 * ���������������� �㷨6.7 ����������������
 *
 * ����ȫ���������ڲ�ʵ��
 */
static void InTheading(BiThrTree p);

#endif
