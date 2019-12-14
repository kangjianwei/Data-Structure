/*=============================
 * ���Ķ���˳��洢��ʾ��˳�򴮣�
 *
 * �����㷨: 4.1��4.2��4.3��4.5
 ==============================*/

#ifndef SSTRING_H
#define SSTRING_H

#include <stdio.h>
#include <string.h>     // �ṩ strlen ԭ��
#include <ctype.h>      // �ṩ isprint ԭ��
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
 * �����ַ���S�еĿհף����������ɴ�ӡ�ַ�������ո�
 *
 *��ע��
 * �ú������ڱ����������ġ�
 */
Status ClearBlank(SString S);

#endif
