/*============================
 * ������ͷβ����洢��ʾ
 *
 * �����㷨: 5.5��5.6��5.7��5.8
 =============================*/

#ifndef GLIST_HT_H
#define GLIST_HT_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��realloc��free��exit ԭ��
#include "Status.h"     //**��01 ����**//
#include "SString.h"    //**��04 ��**//

/* ԭ��Ԫ������ */
typedef char AtomType;

/*
 * ���������
 *
 * Atom-0��ԭ�ӽ��
 * List-1������
 */
typedef enum { Atom, List } ElemTag;

/* �����ͷβ����洢��ʾ�����Ͷ��� */
typedef struct GLNode {
    ElemTag tag;    // ������ǣ���������ԭ�ӽ��ͱ���
    
    // ԭ�ӽ��ͱ�������ϲ���
    union {
        AtomType atom;          // atom��ԭ�ӽ���ֵ��AtomType���û�����
        struct {
            struct GLNode* hp;  // ָ���ͷ
            struct GLNode* tp;  // ָ���β
        } ptr;                  // �����ָ����
    } Node;
} GLNode;

/* ��������� */
typedef GLNode* GList;

/*
 * ͼ�λ�������
 *
 * Head��������ָ�����Ա�ͷ
 * Tail��������ָ�����Ա�β
 */
typedef enum { Head, Tail } Mark;


/*
 * ��ʼ��
 *
 * ��ʼ���յĹ��������Ϊ0�����Ϊ1��
 *
 *��ע��
 * ��Ҫ��ÿһ��ȥ�����ſ���
 */
Status InitGList(GList* L);

/*
 * ���������������� �㷨5.7 ����������������
 *
 * ����
 *
 * ���ַ���S���������L��
 */
Status CreateGList(GList* L, SString S);

/*
 * ����
 *
 * �ͷŹ������ռ�ڴ档
 */
Status DestroyGList(GList* L);

/*
 * ���������������� �㷨5.6 ����������������
 *
 * ����
 *
 * �ɹ����L���Ƶõ������T��
 */
Status CopyGList(GList* T, GList L);

/*
 * ����
 *
 * ���ع����ĳ��ȡ�
 */
int GListLength(GList L);

/*
 * ���������������� �㷨5.5 ����������������
 *
 * ���
 *
 * ���ع��������
 */
int GListDepth(GList L);

/*
 * �п�
 *
 * �жϹ�����Ƿ�Ϊ�ա�
 */
Status GListEmpty(GList L);

/*
 * ��ͷ
 */
GList GetHead(GList L);

/*
 * ��β
 */
GList GetTail(GList L);

/*
 * ����
 *
 * ��Ԫ��e����Ϊ�����L�ĵ�һ��Ԫ�ء�
 */
Status InsertFirst(GList* L, GList e);

/*
 * ɾ��
 *
 * �������L�ĵ�һ��Ԫ��ɾ��������e���ء�
 */
Status DeleteFirst(GList* L, GList* e);

/*
 * ����
 *
 * ��visit�������ʹ����L��
 */
void Traverse(GList L, void (Visit)(AtomType));

/*
 * ͼ�λ����
 *
 * ��������������L��
 */
void PrintGraph(GList L);

/*
 * ͼ�λ�������ڲ�ʵ�֣�mark��ͼ�λ������ǡ�
 */
static void Print(GList L, Mark mark);

/*
 * ���������������� �㷨5.8 ����������������
 *
 * ���ǿմ�str�ָ�������֣�hsubΪ��һ��','֮ǰ���Ӵ���strΪ��һ��','֮����Ӵ���
 *
 *��ע��
 * 1.��������ַ���str������ȷ�������޿հ׷��ţ���str���Ѿ���ȥ��������š���
 * 2.������ɺ�strҲ�ᷢ���仯
 */
static void sever(SString hstr, SString str);

#endif
