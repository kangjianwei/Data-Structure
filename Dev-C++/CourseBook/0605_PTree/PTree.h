/*==================
 * ����˫�ױ�洢��ʾ
 ===================*/

#ifndef PTREE_H
#define PTREE_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��free ԭ��
#include <string.h>     // �ṩ memset��strcmp ԭ��
#include "Status.h"     //**��01 ����**//
#include "LinkList.h"   //**��02 ���Ա�**//
#include "LinkQueue.h"  //**��03 ջ�Ͷ���**//

/* ����������� */
#define MAX_TREE_SIZE 1024

/* ����������ĺ������� */
#define MAX_CHILD_COUNT 8

/* ����Ԫ�����Ͷ��壬���������Ԫ������Ϊchar */
typedef char TElemType;

/* (˫��)���Ľ�㶨�� */
typedef struct PTNode {
    TElemType data;
    int parent;         // ˫��λ����
} PTNode;

/*
 * (˫��)�����Ͷ���
 *
 *��ע��
 * 1.���н����nodes��"����"�洢��û�п�϶
 * 2.����r���ܳ�����nodes������λ��
 * 3.��������⣬����������ΰ�����˳�Ÿ�����������У���һ����̲�ͼʾ���ܻ�������
 * 4.nodes������ѭ��ʹ�õģ���һ��̲�δ�ᵽ��
 * 5.�������nodes�ռ����㹻��ģ��������������Ϊ��̬����洢
 */
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];    // �洢���н��
    int r;  // ����λ��(����)
    int n;  // ���Ľ����
} PTree;


/* ����ĳ��������Ϣ */
typedef struct{
    int row;            // ��ǰ�����������
    int col;            // ��ǰ�����������
    int childIndex;     // ��ǰ����ǵڼ�������
    int firstChild;     // ��ǰ���ĵ�һ�����������е�����
    int lastChild;      // ��ǰ�������һ�����������е�����
} Pos;


/*
 * ��ʼ��
 *
 * ���������
 */
Status InitTree(PTree* T);

/*
 * ����
 *
 * �ͷ�����ռ�ڴ档
 *
 *��ע��
 * ����˫�ױ�ṹ�޷�������
 */
Status DestroyTree(PTree* T);

/*
 * �ÿ�
 *
 * �������е����ݣ�ʹ���Ϊ������
 */
Status ClearTree(PTree* T);

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
Status CreateTree(PTree* T, char* path);

/*
 * �п�
 *
 * �ж����Ƿ�Ϊ������
 */
Status TreeEmpty(PTree T);

/*
 * ����
 *
 * ����������ȣ���������
 */
int TreeDepth(PTree T);

/*
 * ȡֵ
 *
 * ��������ָ������ֵ��
 */
TElemType Value(PTree T, TElemType e);

/*
 * ��ֵ
 *
 * Ϊ��ָ���Ľ�㸳ֵ��
 */
Status Assign(PTree* T, TElemType e, TElemType value);

/*
 * ��
 *
 * �������ĸ���㡣
 */
TElemType Root(PTree T);

/*
 * ˫��
 *
 * �������н��e��˫�׽�㡣
 */
TElemType Parent(PTree T, TElemType e);

/*
 * ��������
 *
 * ������T�н��e�ĺ���������
 */
int ChildCount(PTree T, TElemType e);

/*
 * ����
 *
 * �������н��e�ĵ�i�����ӡ�
 */
TElemType Child(PTree T, TElemType e, int i);

/*
 * ���ֵ�
 *
 * �������н��e�����ֵܽ�㡣
 *
 *��ע��
 * �������Ľ����ܻ����������ӣ�
 * �����������ֵ���ָ��߽��ڸý����ֵܡ�
 */
TElemType LeftSibling(PTree T, TElemType e);

/*
 * ���ֵ�
 *
 * �������н��e�����ֵܽ�㡣
 *
 *��ע��
 * �������Ľ����ܻ����������ӣ�
 * �����������ֵ���ָ�ұ߽��ڸý����ֵܡ�
 */
TElemType RightSibling(PTree T, TElemType e);

/*
 * ����
 *
 * ����c����Ϊ��T��p���ĵ�i�����ӡ�
 */
Status InsertChild(PTree* T, TElemType p, int i, PTree c);

/*
 * ɾ��
 *
 * ɾ����T��p���ĵ�i�����ӡ�
 */
Status DeleteChild(PTree* T, TElemType p, int i);

/*
 * �������
 */
Status PreOrderTraverse(PTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status PostOrderTraverse(PTree T, Status(Visit)(TElemType));

/*
 * �������
 */
Status LevelOrderTraverse(PTree T, Status(Visit)(TElemType));


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// ���������ڲ�����
static void Create(PTree* T, FILE* fp);

// ���������e����������������ڣ�����-1
static int EIndex(PTree T, TElemType e);

// ���������e�ĵ�i��������������������ڣ�����-1
static int CIndex(PTree T, TElemType e, int i);

// ��ȡ��T�Ľ����Ϣ�����������Щ��Ϣ�������Pos���͵Ķ���
static void getPos(PTree T, Pos pt[]);

// ����������ڲ�ʵ��
static Status PreTraverse(PTree T, Pos pt[], int i, Status(Visit)(TElemType));

// ����������ڲ�ʵ��
static Status PostTraverse(PTree T, Pos pt[], int i, Status(Visit)(TElemType));

// ���pos��Ϣ�������ڲ�����ʹ��
static void printPos(PTree T, Pos pt[]);


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph(PTree T);

// ͼ�λ������ǰ�ṹ�ڲ�ʵ��
static void Print(PTree T, Pos pt[], int i);

// ͼ�λ�����������нṹ�������ڲ�����ʹ��
static void PrintFramework(PTree T);

#endif
