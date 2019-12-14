/*=========================
 * ���Ķѷ���洢��ʾ���Ѵ���
 *
 * �����㷨: 4.4
 ==========================*/

#include "HString.h"    //**��04 ��**//

/*
 * ��ʼ��
 *
 * ����һ��ֵΪchars�Ĵ�T��
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrAssign(HString* T, const char* chars) {
    int i, j;
    
    // ��chars�ĳ���
    i = (int) strlen(chars);
    
    // û����ЧԪ��
    if(i == 0) {
        (*T).ch = NULL;
        (*T).length = 0;
    
        return OK;
    }
    
    // ������ЧԪ��ʱ����Ҫ����洢�ռ�
    (*T).ch = (char*) malloc(i * sizeof(char));
    if(!((*T).ch)) {
        exit(OVERFLOW);
    }
    
    for(j = 0; j < i; j++) {
        (*T).ch[j] = chars[j];
    }
    
    (*T).length = i;
    
    return OK;
}

/*
 * �Ƚ�
 *
 * �Ƚϴ�S�ʹ�T�����رȽϽ����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrCompare(HString S, HString T) {
    int i;
    
    for(i = 0; i < S.length && i < T.length; i++) {
        // ������ͬ���ַ�ʱ���Ƚ����С
        if(S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    
    return S.length - T.length;
}

/*
 * ����
 *
 * ����S���Ƶ���T��
 */
Status StrCopy(HString* T, HString S) {
    int i;
    
    if(S.length == 0) {
        (*T).ch = NULL;
        (*T).length = 0;
    } else {
        // ����ռ�
        (*T).ch = (char*) malloc(S.length * sizeof(char));
        if(!(*T).ch) {
            exit(OVERFLOW);
        }
        
        // ����Ԫ��
        for(i = 0; i < S.length; i++) {
            (*T).ch[i] = S.ch[i];
        }
        
        // ���Ƴ�����Ϣ
        (*T).length = S.length;
    }
    
    return OK;
}
