/*==========
 * mԪ����ʽ
 ===========*/

#ifndef MPLIST_H
#define MPLIST_H

#include <stdio.h>
#include <stdlib.h>       // �ṩ malloc��realloc��free��exit ԭ��
#include <string.h>       // �ṩ strlen ԭ��
#include "Status.h"       //**��01 ����**//
#include "StringUtil.h"   //**�ַ���������**//

/*
 * �������� ��ʾ ��������
 *
 * 1.���ڶ�Ԫ������Լ����һԪλ������㡣
 * 2.δ֪�����Ĭ��Ϊa~z��A~Z��26����ĸ
 * 3.Լ������ʽ��ÿ��Ԫ��ָ���ǡ��ݼ����ģ���3��2��1
 */


/*
 * ���浱ǰ����ʽ�ı�����Ϣ����x��y��z��
 * Լ��var�е��ַ�˳��λ��Ԫ�Ĵ����磺
 * "zyx"ָʾzΪ��һԪ��yΪ�ڶ�Ԫ��xΪ����Ԫ
 */
extern char Var[27];

/*
 * mԪ����ʽ�����
 *
 * Atom-0��ԭ�ӽ��
 * List-1������
 */
typedef enum { Atom, List } ElemTag;

/* mԪ����ʽԪ�ؽ�� */
typedef struct MPNode {
    ElemTag tag;            // ����ԭ�ӽ��ͱ���
    int exp;                // ָ���򣬶���ͷ��㣬�洢δ֪����ǣ���x��y��z��
    union {
        float coef;         // ϵ����
        struct MPNode* hp;  // ����ı�ͷָ��
    } Node;
    struct MPNode* tp;      // �൱�����������next��ָ����һ��Ԫ�ؽ��
} MPNode;

/* mԪ����ʽ��������� */
typedef MPNode* MPList;


/*
 * ����
 *
 * ���ַ���S����mԪ����P��
 * ����У��S�Ƿ���д��ȷ��
 *
 * P   : �����Ķ���ʽ
 * S   : ����ʽ�ַ���
 * vars: �����б��ӵ�һԪ��ʼ���У�����xyz������Ԫ����ʽ�е�δ֪�����
 */
Status CreateMPList(MPList* P, char* S, char* vars);

/*
 * mԪ����ʽ��������
 */
static Status Create(MPList* P, char* S);

/*
 * ͼ�λ����
 *
 * ���������mԪ����P��
 */
void PrintGraph(MPList P);

/*
 * ͼ�λ�������ڲ�ʵ��
 */
static void Print(MPList P);

/*
 * ���ǿմ�str�ָ�������֣�hsubΪ��һ��','֮ǰ���Ӵ���strΪ��һ��','֮����Ӵ���
 *
 *��ע��
 * 1.��������ַ���str������ȷ�������޿հ׷��ţ���str���Ѿ���ȥ��������š���
 * 2.������ɺ�strҲ�ᷢ���仯
 */
static void sever(char** hstr, char** str);

#endif

