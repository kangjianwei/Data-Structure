/*===========================
 * ϰ��4.10~4.14��ʹ�õ��ַ���
 ============================*/

#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <string.h>     // �ṩ strlen ԭ��
#include "Status.h"     //**��01 ����**//

/* �ַ������� */
typedef char* StringType;


// ��ʼ��������һ��ֵΪs�Ĵ�t
void StrAssign(StringType* t, const char*  s);

// �Ƚϣ�����s��t�Ĵ�С�������Сһ�£�����0
int StrCompare(StringType s, StringType t);

// �����������ַ���s�ĳ���
int StrLength(StringType s);

// ���ӣ�������s��t���Ӻ�Ĵ�
StringType Concat(StringType s, StringType t);

// ���Ӵ�����s��startλ���𣬽�ȡlen���ַ��󷵻�
StringType SubString(StringType s, int start, int len);

// ���ң���s��posλ�������t������ҵ���������λ��
int Index(StringType s, StringType t, int pos);

// ���룺��s��pos������t
Status StrInsert(StringType* s, int pos, StringType t);

// ɾ������s��posλ����ɾ��len���ַ�
Status StrDelete(StringType* s, int pos, int len);

// ����ַ���
void StrPrint(StringType s);

#endif
