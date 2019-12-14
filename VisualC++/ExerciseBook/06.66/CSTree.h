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
Status InitTree_CS(CSTree* T);

/*
 * �п�
 *
 * �ж����Ƿ�Ϊ������
 */
Status TreeEmpty_CS(CSTree T);

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph_CS(CSTree T);

// ͼ�λ������ǰ�ṹ�ڲ�ʵ��
static void Print_CS(CSTree T, int row);

#endif
