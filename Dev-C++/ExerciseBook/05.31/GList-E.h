/*===========================
 * ��������չ��������洢��ʾ
 ============================*/

#ifndef GLIST_E_H
#define GLIST_E_H

#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��realloc��free��exit ԭ��
#include "Status.h"     //**��01 ����**//
#include "SString.h"    //**��04 ��**//

/* ԭ��Ԫ������ */
typedef char AtomType;                        //ԭ������

/*
 * ���������
 *
 * Atom-0��ԭ�ӽ��
 * List-1������
 */
typedef enum { Atom, List } ElemTag;

/* �������չ��������洢��ʾ�����Ͷ��� */
typedef struct GLNode {
    ElemTag tag;    // ������ǣ���������ԭ�ӽ��ͱ���
    
    // ԭ�ӽ��ͱ�������ϲ���
    union
    {
        AtomType atom;      // atom��ԭ�ӽ���ֵ��AtomType���û�����
        struct GLNode* hp;  // ָ���ͷ
    } Node;
    struct GLNode* tp;      // ָ���β
} GLNode;

/* ��������� */
typedef GLNode* GList;


/*
 * ��ʼ��
 *
 * ��ʼ���յĹ��������Ϊ0�����Ϊ1��
 *
 *��ע��
 * ��Ҫ��ÿһ��������ſ���
 */
Status InitGList(GList* L);

/*
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
void Traverse(GList L, void(Visit)(AtomType));

/*
 * ͼ�λ����
 *
 * ��������������L��
 */
void PrintGraph(GList L);

/*
 * ͼ�λ�������ڲ�ʵ�֡�
 */
static void Print(GList L);

/*
 * ���ǿմ�str�ָ�������֣�hsubΪ��һ��','֮ǰ���Ӵ���strΪ��һ��','֮����Ӵ���
 *
 *��ע��
 * 1.��������ַ���str������ȷ�������޿հ׷��ţ�
 *   ��str�������ſ�����ȥ��Ҳ����δ��ȥ��
 * 2.������ɺ�strҲ�ᷢ���仯
 */
static void sever(SString hstr, SString str);

#endif
