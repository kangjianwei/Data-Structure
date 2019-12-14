/*=============================
 * ���Ķ���˳��洢��ʾ��˳�򴮣�
 *
 * �����㷨: 4.1��4.2��4.3��4.5
 ==============================*/

#ifndef SSTRING_H
#define SSTRING_H

#include <stdio.h>
#include <string.h>     // �ṩstrlenԭ��
#include "Status.h"     //**��01 ����**//

/* �궨�� */
#define MAXSTRLEN 255       // ˳�򴮵���󴮳�

/*
 * ����˳��洢���Ͷ���
 *
 * ע����ЧԪ�ش�SString��1�ŵ�Ԫ��ʼ�洢
 *     SString��0�ŵ�Ԫ�����洢�䳤��
 */
typedef unsigned char SString[MAXSTRLEN + 1];       // 0�ŵ�Ԫ��Ŵ��ĳ���


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
Status StrAssign(SString T, const char* chars);

/*
 * ����
 *
 * ����S���١�
 *
 *��ע��
 * ˳�򴮵Ľṹ�޷�����
 */
Status DestroyString(SString S);

/*
 * ���
 *
 * ����S��ա�
 */
Status ClearString(SString S);

/*
 * �п�
 *
 * �жϴ�S���Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ��SΪ��
 * FALSE: ��S��Ϊ��
 */
Status StrEmpty(SString S);

/*
 * ����
 *
 * ���ش�S��Ԫ�صĸ�����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
int StrLength(SString S);

/*
 * ���������������� �㷨4.3 ����������������
 *
 * ���Ӵ�
 *
 * ��Sub����S[pos, pos+len-1]��
 * ����ֵָʾ�Ƿ��ȡ�ɹ���
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status SubString(SString Sub, SString S, int pos, int len);

/*
 * ���������������� �㷨4.1 ����������������
 *
 * ����
 *
 * ��pos����ʼ����ģʽ��T������S���״γ��ֵ�λ�ã���������ڣ��򷵻�0��
 * ������ҳɹ�������ƥ���λ�á�
 *
 *��ע��
 * 1.��ʵ����Ҫ����������С�����Ӽ�
 * 2.��ʵ�ֱȽϵ�Ч
 */
int Index_1(SString S, SString T, int pos);

/*
 * ���������������� �㷨4.5 ����������������
 *
 * ����
 *
 * ��pos����ʼ����ģʽ��T������S���״γ��ֵ�λ�ã���������ڣ��򷵻�0��
 * ������ҳɹ�������ƥ���λ�á�
 *
 *��ע��
 * 1.��ʵ�ֲ�����������С�����Ӽ�
 * 2.��ʵ�ֱȽϵ�Ч
 */
int Index_2(SString S, SString T, int pos);

/*
 * ����
 *
 * ����T���뵽����S��posλ�ô���
 */
Status StrInsert(SString S, int pos, SString T);

/*
 * ɾ��
 *
 * ɾ��S[pos, pos+len-1]��
 */
Status StrDelete(SString S, int pos, int len);

/*
 * �Ƚ�
 *
 * �Ƚϴ�S�ʹ�T�����رȽϽ����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
int StrCompare(SString S, SString T);

/*
 * ����
 *
 * ����S���Ƶ���T��
 */
Status StrCopy(SString T, SString S);

/*
 * �滻
 *
 * ��V�滻����S�г��ֵ�������T��ȵ��Ҳ��ص����Ӵ���
 *
 *��ע��
 * �ò���������С�����Ӽ���Ч�ʽϵ͡�
 */
Status Replace(SString S, SString T, SString V);

/*
 * ���������������� �㷨4.2 ����������������
 *
 * ������
 *
 * ����S1��S2�����洢��T�з��ء�������Ӻ�ĳ����������ֻ����δ����Ĳ��֡�
 * ����ֵ��ʾ���Ӻ�Ĵ��Ƿ�������
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status Concat(SString T, SString S1, SString S2);

// �������ӡ�ַ���
void StrPrint(SString S);

#endif
