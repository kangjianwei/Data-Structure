/*=========================
 * ���Ķѷ���洢��ʾ���Ѵ���
 *
 * �����㷨: 4.4
 ==========================*/

#ifndef HSTRING
#define HSTRING

#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <string.h>     // �ṩstrlenԭ��
#include "Status.h"     //**��01 ����**//

/*
 * ���ĶѴ洢��ʾ
 *
 * ע����ЧԪ�ش�ch��0�ŵ�Ԫ��ʼ�洢
 */
typedef struct {
    char* ch;           // ���Ƿǿմ����򰴴�������洢��������chΪNULL
    int length;
} HString;


/*
 * �������� ��ʾ ��������
 *
 * ��ѭ�̲ĵ���дϰ�ߣ�posָʾ�ַ���λ��(��������)����1��ʼ����
 */


/*
 * ��ʼ��
 *
 * ����һ��ֵΪchars�Ĵ�T��
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrAssign(HString* T, const char* chars);

/*
 * ����
 *
 * ����S���١�
 */
Status DestroyString(HString* S);

/*
 * ���
 *
 * ����S��ա�
 */
Status ClearString(HString* S);

/*
 * �п�
 *
 * �жϴ�S���Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ��SΪ��
 * FALSE: ��S��Ϊ��
 */
Status StrEmpty(HString S);

/*
 * ����
 *
 * ���ش�S��Ԫ�صĸ�����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
int StrLength(HString S);

/*
 * ���Ӵ�
 *
 * ��Sub����S[pos, pos+len-1]��
 * ����ֵָʾ�Ƿ��ȡ�ɹ���
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status SubString(HString* Sub, HString S, int pos, int len);

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
int Index(HString S, HString T, int pos);

/*
 * ���������������� �㷨4.4 ����������������
 *
 * ����
 *
 * ����T���뵽����S��posλ�ô���
 */
Status StrInsert(HString* S, int pos, HString T);

/*
 * ɾ��
 *
 * ɾ��S[pos, pos+len-1]��
 */
Status StrDelete(HString* S, int pos, int len);

/*
 * �Ƚ�
 *
 * �Ƚϴ�S�ʹ�T�����رȽϽ����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrCompare(HString S, HString T);

/*
 * ����
 *
 * ����S���Ƶ���T��
 */
Status StrCopy(HString* T, HString S);

/*
 * �滻
 *
 * ��V�滻����S�г��ֵ�������T��ȵ��Ҳ��ص����Ӵ���
 *
 *��ע��
 * 1.�ò���������С�����Ӽ�
 * 2.��ʵ�ֱȽϵ�Ч
 */
Status Replace(HString* S, HString T, HString V);

/*
 * ������
 *
 * ����S1��S2�����洢��T�з��ء�������Ӻ�ĳ����������ֻ����δ����Ĳ��֡�
 * ����ֵ��ʾ���Ӻ�Ĵ��Ƿ�������
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status Concat(HString* T, HString S1, HString S2);

// �������ӡ�ַ���
void StrPrint(HString S);

#endif
