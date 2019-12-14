/*=============================
 * ���Ķ���˳��洢��ʾ��˳�򴮣�
 *
 * �����㷨: 4.1��4.2��4.3��4.5
 ==============================*/

#include "SString.h"    //**��04 ��**//

/*
 * ��ʼ��
 *
 * ����һ��ֵΪchars�Ĵ�T��
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrAssign(SString T, const char* chars) {
    int i, len;
    
    len = (int) strlen(chars);
    
    // chars����
    if(len > MAXSTRLEN) {
        return ERROR;
    }
    
    T[0] = len;
    for(i = 1; i <= len; i++) {
        T[i] = chars[i - 1];
    }
    
    return OK;
}

/*
 * ���
 *
 * ����S��ա�
 */
Status ClearString(SString S) {
    // ֻ��Ҫ��������Ϊ0�Ϳ���
    S[0] = 0;
    return OK;
}

/*
 * �п�
 *
 * �жϴ�S���Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ��SΪ��
 * FALSE: ��S��Ϊ��
 */
Status StrEmpty(SString S) {
    return S[0] == 0 ? TRUE : FALSE;
}

/*
 * ����
 *
 * ���ش�S��Ԫ�صĸ�����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
int StrLength(SString S) {
    return S[0];
}

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
Status SubString(SString Sub, SString S, int pos, int len) {
    int i;
    
    if(pos < 1 || pos > S[0] || len < 0 || pos + len - 1 > S[0]) {
        return ERROR;
    }
    
    // ����Ԫ��
    for(i = 1; i <= len; i++) {
        Sub[i] = S[pos + i - 1];
    }
    
    // ȷ���³���
    Sub[0] = len;
    
    return OK;
}

/*
 * ɾ��
 *
 * ɾ��S[pos, pos+len-1]��
 */
Status StrDelete(SString S, int pos, int len) {
    int i;
    
    if(pos < 1 || pos + len - 1 > S[0] || len < 0) {
        return ERROR;
    }
    
    // �����ɾ���ĳ���Ϊ0������ǰ����
    if(len == 0) {
        return OK;
    }
    
    // �Ѻ����Ԫ��Ų��ǰ�棬���ǵ���ɾ����Ԫ��
    for(i = pos + len; i <= S[0]; i++) {
        S[i - len] = S[i];
    }
    
    // ���ȼ���
    S[0] -= len;
    
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
int StrCompare(SString S, SString T) {
    int i = 1;
    
    while(i <= S[0] && i <= T[0]) {
        // ������ͬ���ַ�ʱ���Ƚ����С
        if(S[i] != T[i]) {
            return S[i] - T[i];
        }
        
        i++;
    }
    
    return S[0] - T[0];
}

/*
 * ����
 *
 * ����S���Ƶ���T��
 */
Status StrCopy(SString T, SString S) {
    int i;
    
    // ��ͬ������Ϣһ����
    for(i = 0; i <= S[0]; i++) {
        T[i] = S[i];
    }
    
    return OK;
}

/*
 * �����ַ���S�еĿհף����������ɴ�ӡ�ַ�������ո�
 *
 *��ע��
 * �ú������ڱ����������ġ�
 */
Status ClearBlank(SString S) {
    int i, j;
    
    // ����ǿմ�
    if(S[0] == 0) {
        return ERROR;
    }
    
    for(i = 1, j = 0; i <= S[0]; i++) {
        // ��������հף����Թ�
        if(S[i] == ' ' || !isprint(S[i])) {
            continue;
        }
        
        j++;
        
        S[j] = S[i];
    }
    
    S[0] = j;
    
    return OK;
}
