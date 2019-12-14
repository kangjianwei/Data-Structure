/*=============================
 * ���Ŀ�������洢��ʾ����������
 ==============================*/

#ifndef LSTRING_H
#define LSTRING_H

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <string.h>     // �ṩstrlenԭ��
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define CHUNKSIZE 3     // ���С���Զ��壩

/* ���Ŀ����洢�ṹ */
typedef struct Chunk {
    char ch[CHUNKSIZE];  // ��ǰ���е�����
    struct Chunk* next;  // ָ����һ����
} Chunk;

/* ���Ŀ����洢���Ͷ��� */
typedef struct {
    Chunk* head;    //����ͷָ��
    Chunk* tail;    //����βָ��
    int curlen;     //���ĵ�ǰ����
} LString;


/*
 * �������� ��ʾ ��������
 *
 * ��ѭ�̲ĵ���дϰ�ߣ�posָʾ�ַ���λ��(��������)����1��ʼ����
 */

/*
 * �������� ע�� ��������
 *
 * 1.�̲�ʾ����ʹ��#��Ϊ�Ǵ�ֵ�ַ���������ʹ��C�����е�\0��Ϊ�Ǵ�ֵ�ַ�
 * 2.�̲���ָ�������������һ�����У�ĩβ�������÷Ǵ�ֵ�ַ����ġ�
 *   ������СΪ4������Ϊ14�Ŀ����Ϊ�����£ã� -> �ţƣǣ� -> �ɣʣˣ� -> �ͣ�\0\0
 */


/*
 * ��ʼ��
 *
 * ����һ��ֵΪchars�Ĵ�T��
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrAssign(LString* T, const char* chars);

/*
 * ����
 *
 * ����S���١�
 */
Status DestroyString(LString* S);

/*
 * ���
 *
 * ����S��ա�
 */
Status ClearString(LString* S);

/*
 * �п�
 *
 * �жϴ�S���Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ��SΪ��
 * FALSE: ��S��Ϊ��
 */
Status StrEmpty(LString S);

/*
 * ����
 *
 * ���ش�S��Ԫ�صĸ�����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
int StrLength(LString S);

/*
 * ���Ӵ�
 *
 * ��Sub����S[pos, pos+len-1]��
 * ����ֵָʾ�Ƿ��ȡ�ɹ���
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status SubString(LString* Sub, LString S, int pos, int len);

/*
 * ����
 *
 * ��pos����ʼ����ģʽ��T������S���״γ��ֵ�λ�ã���������ڣ��򷵻�0��
 * ������ҳɹ�������ƥ���λ�á�
 *
 *��ע��
 * 1.��ʵ����Ҫ����������С�����Ӽ�
 * 2.��ʵ�ֱȽϵ�Ч
 */
int Index(LString S, LString T, int pos);

/*
 * ����
 *
 * ����T���뵽����S��posλ�ô���
 */
Status StrInsert(LString* S, int pos, LString T);

/*
 * ɾ��
 *
 * ɾ��S[pos, pos+len-1]��
 */
Status StrDelete(LString* S, int pos, int len);

/*
 * �Ƚ�
 *
 * �Ƚϴ�S�ʹ�T�����رȽϽ����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrCompare(LString S, LString T);

/*
 * ����
 *
 * ����S���Ƶ���T��
 */
Status StrCopy(LString* T, LString S);

/*
 * �滻
 *
 * ��V�滻����S�г��ֵ�������T��ȵ��Ҳ��ص����Ӵ���
 *
 *��ע��
 * 1.�ò���������С�����Ӽ�
 * 2.��ʵ�ֱȽϵ�Ч
 */
Status Replace(LString* S, LString T, LString V);

/*
 * ������
 *
 * ����S1��S2�����洢��T�з��ء�������Ӻ�ĳ����������ֻ����δ����Ĳ��֡�
 * ����ֵ��ʾ���Ӻ�Ĵ��Ƿ�������
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status Concat(LString* T, LString S1, LString S2);

// ���Ժ�������ӡ�ַ���
void StrPrint(LString S);

#endif
