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
Status InitTree_P(PTree* T);

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
Status CreateTree_P(PTree* T, char* path);

/*
 * �п�
 *
 * �ж����Ƿ�Ϊ������
 */
Status TreeEmpty_P(PTree T);


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// ���������ڲ�����
static void Create_P(PTree* T, FILE* fp);

// ��ȡ��T�Ľ����Ϣ�����������Щ��Ϣ�������Pos���͵Ķ���
static void getPos_P(PTree T, Pos pt[]);


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph_P(PTree T);

// ͼ�λ������ǰ�ṹ�ڲ�ʵ��
static void Print_P(PTree T, Pos pt[], int i);

// ͼ�λ�����������нṹ�������ڲ�����ʹ��
static void PrintFramework_P(PTree T);

#endif
