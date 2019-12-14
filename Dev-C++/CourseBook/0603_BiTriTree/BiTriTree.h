/*=======================
 * ����������������洢�ṹ
 ========================*/

#ifndef BITRITREE_H
#define BITRITREE_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��free ԭ��
#include <string.h>     // �ṩ memset��strcmp ԭ��
#include <math.h>       // �ṩ pow ԭ��
#include "Status.h"     //**��01 ����**//

/* ������Ԫ�����Ͷ��壬���������Ԫ������Ϊchar */
typedef char TElemType;

/* ��������㶨�壬������˫�׽��Ķ��� */
typedef struct BiTriTNode {
    TElemType data;             // ���Ԫ��
    struct BiTriTNode* lchild;  // ����ָ��
    struct BiTriTNode* rchild;  // �Һ���ָ��
    struct BiTriTNode* parent;  // ˫�׽��ָ��
} BiTriTNode;

/* ָ�����������ָ�� */
typedef BiTriTNode* BiTriTree;


/*
 * ��ʼ��
 *
 * ����ն�������
 */
Status InitBiTree(BiTriTree* T);

/*
 * ����
 *
 * �ͷŶ�������ռ�ڴ档
 *
 *��ע��
 * ����������������洢�ṹ�������٣�����û��Ҫ���١�
 * ��Ϊ�����������ٺ��״̬���ÿպ��״̬��һ�µġ�
 */
Status DestroyBiTree(BiTriTree* T);

/*
 * �ÿ�
 *
 * ����������е����ݣ�ʹ���Ϊ������
 */
Status ClearBiTree(BiTriTree* T);

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
Status CreateBiTree(BiTriTree* T, char* path);

/*
 * �п�
 *
 * �ж϶������Ƿ�Ϊ������
 */
Status BiTreeEmpty(BiTriTree T);

/*
 * ����
 *
 * ���ض���������ȣ���������
 */
int BiTreeDepth(BiTriTree T);

/*
 * ȡֵ
 *
 * ���ض�������ָ������ֵ��
 */
TElemType Value(BiTriTree T, TElemType e);

/*
 * ��ֵ
 *
 * Ϊ������ָ���Ľ�㸳ֵ��
 */
Status Assign(BiTriTree T, TElemType e, TElemType value);

/*
 * ��
 *
 * ���ض������ĸ���㡣
 */
TElemType Root(BiTriTree T);

/*
 * ˫��
 *
 * ���ض������н��e��˫�׽�㡣
 */
TElemType Parent(BiTriTree T, TElemType e);

/*
 * ����
 *
 * ���ض������н��e�����ӽ�㡣
 */
TElemType LeftChild(BiTriTree T, TElemType e);

/*
 * �Һ���
 *
 * ���ض������н��e���Һ��ӽ�㡣
 */
TElemType RightChild(BiTriTree T, TElemType e);

/*
 * ���ֵ�
 *
 * ���ض������н��e�����ֵܽ�㡣
 */
TElemType LeftSibling(BiTriTree T, TElemType e);

/*
 * ���ֵ�
 *
 * ���ض������н��e�����ֵܽ�㡣
 */
TElemType RightSibling(BiTriTree T, TElemType e);

/*
 * ����
 *
 * ��֪cΪ��T���ཻ�ķǿն���������c��������Ϊ�գ�
 * ����LR��ȡֵ(0��1)����c����ΪT�н��p��������/��������
 * ���ң���p���ԭ�е�������/�������޽�Ϊ������c����������
 */
Status InsertChild(BiTriTree T, TElemType p, int LR, BiTriTree c);

/*
 * ɾ��
 *
 * ����LR��ȡֵ(0��1)��ɾ�����p��������/��������
 */
Status DeleteChild(BiTriTree T, TElemType p, int LR);

/*
 * ���������������� �㷨6.1 ����������������
 *
 * �������
 */
Status PreOrderTraverse(BiTriTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status InOrderTraverse(BiTriTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status PostOrderTraverse(BiTriTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status LevelOrderTraverse(BiTriTree T, Status(Visit)(TElemType));


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������������ڲ�����
static void CreateTree(BiTriTree* T, FILE* fp);

// ����ָ����������e��ָ��
static BiTriTree EPtr(BiTriTree T, TElemType e);

// ����������ڲ�ʵ��
static Status PreTraverse(BiTriTree T, Status(Visit)(TElemType));

// ����������ڲ�ʵ��
static Status InTraverse(BiTriTree T, Status(Visit)(TElemType));

// ����������ڲ�ʵ��
static Status PostTraverse(BiTriTree T, Status(Visit)(TElemType));


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ�������ڲ�����ʹ��
void PrintGraph(BiTriTree T);

#endif
