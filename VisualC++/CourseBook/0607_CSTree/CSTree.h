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
 * �ͷ�����ռ�ڴ档
 *
 *��ע��
 * ���ÿղ�����һ�µ�
 */
Status DestroyTree(CSTree* T);

/*
 * �ÿ�
 *
 * �������е����ݣ�ʹ���Ϊ������
 */
Status ClearTree(CSTree* T);

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

/*
 * ȡֵ
 *
 * ��������ָ������ֵ��
 */
TElemType Value(CSTree T, TElemType e);

/*
 * ��ֵ
 *
 * Ϊ��ָ���Ľ�㸳ֵ��
 */
Status Assign(CSTree T, TElemType e, TElemType value);

/*
 * ��
 *
 * �������ĸ���㡣
 */
TElemType Root(CSTree T);

/*
 * ˫��
 *
 * �������н��e��˫�׽�㡣
 */
TElemType Parent(CSTree T, TElemType e);

/*
 * ��������
 *
 * ������T�н��e�ĺ���������
 */
int ChildCount(CSTree T, TElemType e);

/*
 * ����
 *
 * �������н��e�ĵ�i�����ӡ�
 */
TElemType Child(CSTree T, TElemType e, int i);

/*
 * ���ֵ�
 *
 * �������н��e�����ֵܽ�㡣
 */
TElemType LeftSibling(CSTree T, TElemType e);

/*
 * ���ֵ�
 *
 * �������н��e�����ֵܽ�㡣
 */
TElemType RightSibling(CSTree T, TElemType e);

/*
 * ����
 *
 * ����c����Ϊ��T��p���ĵ�i�����ӡ�
 */
Status InsertChild(CSTree* T, TElemType p, int i, CSTree c);

/*
 * ɾ��
 *
 * ɾ����T��p���ĵ�i�����ӡ�
 */
Status DeleteChild(CSTree* T, TElemType p, int i);

/*
 * �������
 */
Status PreOrderTraverse(CSTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status PostOrderTraverse(CSTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status LevelOrderTraverse(CSTree T, Status(Visit)(TElemType));


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// ���������ڲ�����
static void Create(CSTree* T, FILE* fp);

// ����������ȵ��ڲ�ʵ��
static void Depth(CSTree T, int d, int *max);

// ���������e��ָ�룬��������ڣ�����NULL
static CSTree EPtr(CSTree T, TElemType e);

// ���������e��˫�׽���ָ�룬��������ڣ�����NULL
static CSTree PPtr(CSTree T, TElemType e);

// ���������e�ĵ�i�����ӵ�ָ�룬��������ڣ�����NULL
static CSTree CPtr(CSTree T, TElemType e, int i);

// ����������ڲ�ʵ��
static Status PreTraverse(CSTree T, Status(Visit)(TElemType));

// ����������ڲ�ʵ��
static Status PostTraverse(CSTree T, Status(Visit)(TElemType));


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph(CSTree T);

// ͼ�λ������ǰ�ṹ�ڲ�ʵ��
static void Print(CSTree T, int row);

#endif
