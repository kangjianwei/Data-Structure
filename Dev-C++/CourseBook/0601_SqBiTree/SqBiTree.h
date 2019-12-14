/*==================
 * ������˳��洢�ṹ
 ===================*/

#ifndef SQBITREE_H
#define SQBITREE_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��free ԭ��
#include <string.h>     // �ṩ memset��strcmp ԭ��
#include <math.h>       // �ṩ pow ԭ��
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define MAX_TREE_SIZE 1024       // ���������������

/* ������Ԫ�����Ͷ��壬���������Ԫ������Ϊchar */
typedef char TElemType;

/*
 * ���������Ͷ��壬0�ŵ�Ԫ�洢����㡣
 *
 *��ע��
 * �ڶ�������˳��ṹ�У���Ԫ���ǰ�����ȫ˳��������Ĳ����������еġ�
 */
typedef TElemType SqBiTree[MAX_TREE_SIZE];


/*
 * ��ʼ��
 *
 * ����ն�������
 */
Status InitBiTree(SqBiTree T);

/*
 * ����
 *
 * �ͷŶ�������ռ�ڴ档
 *
 *��ע��
 * ��������˳��洢�ṹ�޷����١�
 */
Status DestroyBiTree(SqBiTree T);

/*
 * �ÿ�
 *
 * ����������е����ݣ�ʹ���Ϊ������
 */
Status ClearBiTree(SqBiTree T);

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
Status CreateBiTree(SqBiTree T, char* path);

/*
 * �п�
 *
 * �ж϶������Ƿ�Ϊ������
 */
Status BiTreeEmpty(SqBiTree T);

/*
 * ����
 *
 * ���ض���������ȣ���������
 */
int BiTreeDepth(SqBiTree T);

/*
 * ȡֵ
 *
 * ���ض�������ָ������ֵ��
 */
TElemType Value(SqBiTree T, TElemType e);

/*
 * ��ֵ
 *
 * Ϊ������ָ���Ľ�㸳ֵ��
 */
Status Assign(SqBiTree T, TElemType e, TElemType value);

/*
 * ��
 *
 * ���ض������ĸ���㡣
 */
TElemType Root(SqBiTree T);

/*
 * ˫��
 *
 * ���ض������н��e��˫�׽�㡣
 */
TElemType Parent(SqBiTree T, TElemType e);

/*
 * ����
 *
 * ���ض������н��e�����ӽ�㡣
 */
TElemType LeftChild(SqBiTree T, TElemType e);

/*
 * �Һ���
 *
 * ���ض������н��e���Һ��ӽ�㡣
 */
TElemType RightChild(SqBiTree T, TElemType e);

/*
 * ���ֵ�
 *
 * ���ض������н��e�����ֵܽ�㡣
 */
TElemType LeftSibling(SqBiTree T, TElemType e);

/*
 * ���ֵ�
 *
 * ���ض������н��e�����ֵܽ�㡣
 */
TElemType RightSibling(SqBiTree T, TElemType e);

/*
 * ����
 *
 * ��֪cΪ��T���ཻ�ķǿն���������c��������Ϊ�գ�
 * ����LR��ȡֵ(0��1)����c����ΪT�н��p��������/��������
 * ���ң���p���ԭ�е�������/�������޽�Ϊ������c����������
 */
Status InsertChild(SqBiTree T, TElemType p, int LR, SqBiTree c);

/*
 * ɾ��
 *
 * ����LR��ȡֵ(0��1)��ɾ�����p��������/��������
 */
Status DeleteChild(SqBiTree T, TElemType p, int LR);

/*
 * �������
 */
Status PreOrderTraverse(SqBiTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status InOrderTraverse(SqBiTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status PostOrderTraverse(SqBiTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status LevelOrderTraverse(SqBiTree T, Status(Visit)(TElemType));


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������������ڲ�����
static void CreateTree(SqBiTree T, int i, FILE* fp);

// ���������ȵ��ڲ�����
static int TreeDepth(SqBiTree T, int i);

// ���ض��������e�������ţ�i�ǽ��p��������
static int EIndex(SqBiTree T, TElemType e, int i);

// ժ�¶�����T�е�����i���������Ϊ������R������j
static void Transfer(SqBiTree T, int i, SqBiTree R, int j);

// ɾ��������T�е�����i
static void Delete(SqBiTree T, int i);

// ����������ڲ�ʵ��
static Status PreTraverse(SqBiTree T, Status(Visit)(TElemType), int i);

// ����������ڲ�ʵ��
static Status InTraverse(SqBiTree T, Status(Visit)(TElemType), int i);

// ����������ڲ�ʵ��
static Status PostTraverse(SqBiTree T, Status(Visit)(TElemType), int i);


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ�������ڲ�����ʹ��
void PrintGraph(SqBiTree T);

#endif
