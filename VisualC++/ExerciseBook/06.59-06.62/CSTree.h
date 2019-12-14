/*===================================
 * ���Ķ�����������-�ֵܣ��ṹ�洢��ʾ
 ====================================*/

#ifndef CSTREE_H
#define CSTREE_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��free ԭ��
#include <string.h>     // �ṩ memset��strcmp ԭ��
#include "Status.h"     //**��01 ����**//

/* ����������ĺ������� */
#define MAX_CHILD_COUNT 8

/* ����Ԫ�����Ͷ��壬���������Ԫ������Ϊchar */
typedef char TElemType;

/* (����-�ֵ�)���Ľ�㶨�� */
typedef struct CSNode {
    TElemType data;
    struct CSNode* firstchild;  // ָ����
    struct CSNode* nextsibling; // ָ�����ֵ�
} CSNode;

/* (����-�ֵ�)�����Ͷ��� */
typedef CSNode* CSTree;


/*
 * ��ʼ��
 *
 * ���������
 */
Status InitTree(CSTree* T);

/*
 * ����
 *
 * ����Ԥ��Ķ�������������
 * ����Լ��ʹ�á��������С�����������
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
Status CreateTree(CSTree* T, char* path);

/*
 * �п�
 *
 * �ж����Ƿ�Ϊ������
 */
Status TreeEmpty(CSTree T);

/*
 * ����
 *
 * ����������ȣ���������
 */
int TreeDepth(CSTree T);


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// ���������ڲ�����
static void Create(CSTree* T, FILE* fp);

// ����������ȵ��ڲ�ʵ��
static void Depth(CSTree T, int d, int *max);


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph(CSTree T);

// ͼ�λ������ǰ�ṹ�ڲ�ʵ��
static void Print(CSTree T, int row);

#endif
