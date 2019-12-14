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
 * ����
 *
 * �ͷŶ�������ռ�ڴ档
 *
 *��ע��
 * �������Ķ�������洢�ṹ�������٣�����û��Ҫ���١�
 * ��Ϊ�����������ٺ��״̬���ÿպ��״̬��һ�µġ�
 */
Status DestroyBiTree(BiTree* T);

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

/*
 * ȡֵ
 *
 * ���ض�������ָ������ֵ��
 */
TElemType Value(BiTree T, TElemType e);

/*
 * ��ֵ
 *
 * Ϊ������ָ���Ľ�㸳ֵ��
 */
Status Assign(BiTree T, TElemType e, TElemType value);

/*
 * ��
 *
 * ���ض������ĸ���㡣
 */
TElemType Root(BiTree T);

/*
 * ˫��
 *
 * ���ض������н��e��˫�׽�㡣
 */
TElemType Parent(BiTree T, TElemType e);

/*
 * ����
 *
 * ���ض������н��e�����ӽ�㡣
 */
TElemType LeftChild(BiTree T, TElemType e);

/*
 * �Һ���
 *
 * ���ض������н��e���Һ��ӽ�㡣
 */
TElemType RightChild(BiTree T, TElemType e);

/*
 * ���ֵ�
 *
 * ���ض������н��e�����ֵܽ�㡣
 */
TElemType LeftSibling(BiTree T, TElemType e);

/*
 * ���ֵ�
 *
 * ���ض������н��e�����ֵܽ�㡣
 */
TElemType RightSibling(BiTree T, TElemType e);

/*
 * ����
 *
 * ��֪cΪ��T���ཻ�ķǿն���������c��������Ϊ�գ�
 * ����LR��ȡֵ(0��1)����c����ΪT�н��p��������/��������
 * ���ң���p���ԭ�е�������/�������޽�Ϊ������c����������
 */
Status InsertChild(BiTree T, TElemType p, int LR, BiTree c);

/*
 * ɾ��
 *
 * ����LR��ȡֵ(0��1)��ɾ�����p��������/��������
 */
Status DeleteChild(BiTree T, TElemType p, int LR);

/*
 * ���������������� �㷨6.1 ����������������
 *
 * �������
 */
Status PreOrderTraverse(BiTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status InOrderTraverse(BiTree T, Status(Visit)(TElemType));

/*
 * ���������������� �㷨6.2 ����������������
 *
 * �������
 *
 *��ע��
 * �ǵݹ��㷨
 */
Status InOrderTraverse_2(BiTree T, Status(Visit)(TElemType));

/*
 * ���������������� �㷨6.3 ����������������
 *
 * �������
 *
 *��ע��
 * �ǵݹ��㷨
 */
Status InOrderTraverse_3(BiTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status PostOrderTraverse(BiTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status LevelOrderTraverse(BiTree T, Status(Visit)(TElemType));


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������������ڲ�����
static void CreateTree(BiTree* T, FILE* fp);

// ����ָ����������e��ָ��
static BiTree EPtr(BiTree T, TElemType e);

// ����ָ����������e��˫�׽���ָ��
static BiTree PPtr(BiTree T, TElemType e);

// ����������ڲ�ʵ��
static Status PreTraverse(BiTree T, Status(Visit)(TElemType));

// ����������ڲ�ʵ��
static Status InTraverse(BiTree T, Status(Visit)(TElemType));

// ����������ڲ�ʵ��
static Status PostTraverse(BiTree T, Status(Visit)(TElemType));


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ�������ڲ�����ʹ��
void PrintGraph(BiTree T);

#endif
