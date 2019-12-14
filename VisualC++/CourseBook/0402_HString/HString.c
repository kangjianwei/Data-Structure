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
 * ����
 *
 * ����S���١�
 *
 *��ע��
 * �Ѵ��Ľṹ�������٣������������ٲ�����
 */
Status DestroyString(HString* S) {
    return OK;
}

/*
 * ���
 *
 * ����S��ա�
 */
Status ClearString(HString* S) {
    // û����ЧԪ��ʱ�����ٶѴ��ṹ
    if((*S).ch != 0) {
        free((*S).ch);
        (*S).ch = NULL;
    }
    
    (*S).length = 0;
    
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
Status StrEmpty(HString S) {
    return S.length == 0 ? TRUE : FALSE;
}

/*
 * ����
 *
 * ���ش�S��Ԫ�صĸ�����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
int StrLength(HString S) {
    return S.length;
}

/*
 * ���Ӵ�
 *
 * ��Sub����S[pos, pos+len-1]��
 * ����ֵָʾ�Ƿ��ȡ�ɹ���
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status SubString(HString* Sub, HString S, int pos, int len) {
    int i;
    
    if(pos < 1 || pos > S.length || len < 0 || pos + len - 1 > S.length) {
        return ERROR;
    }
    
    // ����ǽ�ȡ0���ַ�������Ҫ����ռ�
    if(len == 0) {
        (*Sub).ch = NULL;
        (*Sub).length = 0;
    
        return OK;
    }
    
    (*Sub).ch = (char*) malloc(len * sizeof(char));
    if(!(*Sub).ch) {
        exit(OVERFLOW);
    }
    
    // ����Ԫ��
    for(i = 0; i < len; i++) {
        (*Sub).ch[i] = S.ch[i + pos - 1];
    }
    
    // ȷ���³���
    (*Sub).length = len;
    
    return OK;
}

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
int Index(HString S, HString T, int pos) {
    int i, s, t;
    HString sub;
    
    if(pos < 1 || pos > S.length || StrEmpty(T)) {
        return 0;
    }
    
    s = S.length;
    t = T.length;
    i = pos;
    
    // ��֤���Ȳ�Խ��
    while(i + t - 1 <= s) {
        // ��ȡS[i, i+t-1]
        SubString(&sub, S, i, t);
        
        // ����Ӵ���ģʽ����ƥ�䣬����Ҫ�����ƽ�
        if(StrCompare(sub, T) != 0) {
            ++i;
        } else {
            return i;
        }
    }
    
    return 0;
}

/*
 * ���������������� �㷨4.4 ����������������
 *
 * ����
 *
 * ����T���뵽����S��posλ�ô���
 */
Status StrInsert(HString* S, int pos, HString T) {
    int i;
    
    if(pos < 1 || pos > (*S).length + 1) {
        return ERROR;
    }
    
    // ���������Ĵ�Ϊ�գ�����ǰ����
    if(StrEmpty(T)) {
        return OK;
    }
    
    // �����¿ռ䣬�Ὣ��Ԫ��һ���ƹ�ȥ
    (*S).ch = (char*) realloc((*S).ch, ((*S).length + T.length) * sizeof(char));
    if(!(*S).ch) {
        exit(OVERFLOW);
    }
    
    // ��S���ڳ�λ�ã�Ϊ����T��׼��
    for(i = (*S).length - 1; i >= pos - 1; i--) {
        // �Ӻ���ǰ��������ǰ���Ԫ��Ų������
        (*S).ch[i + T.length] = (*S).ch[i];
    }
    
    // ����T������S���ڳ���λ����
    for(i = pos - 1; i <= pos + T.length - 2; i++) {
        (*S).ch[i] = T.ch[i - pos + 1];
    }
    
    // ��������
    (*S).length += T.length;
    
    return OK;
}

/*
 * ɾ��
 *
 * ɾ��S[pos, pos+len-1]��
 */
Status StrDelete(HString* S, int pos, int len) {
    int i;
    
    if(pos < 1 || pos + len - 1 > (*S).length || len < 0) {
        return ERROR;
    }
    
    // �����ɾ���ĳ���Ϊ0������ǰ����
    if(len == 0) {
        return OK;
    }
    
    // �Ѻ����Ԫ��Ų��ǰ�棬���ǵ���ɾ����Ԫ��
    for(i = pos + len - 1; i <= (*S).length - 1; i++) {
        (*S).ch[i - len] = (*S).ch[i];
    }
    
    // ���ȼ���
    (*S).length -= len;
    
    // ��������Ŀռ䣨������ȼ���Ϊ0������᷵�ؿ�ָ�룩
    (*S).ch = (char*) realloc((*S).ch, (*S).length * sizeof(char));
    
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
    
    if(StrEmpty(S)) {
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

/*
 * �滻
 *
 * ��V�滻����S�г��ֵ�������T��ȵ��Ҳ��ص����Ӵ���
 *
 *��ע��
 * 1.�ò���������С�����Ӽ�
 * 2.��ʵ�ֱȽϵ�Ч
 */
Status Replace(HString* S, HString T, HString V) {
    int i;
    
    if(StrEmpty(*S) || StrEmpty(T)) {
        return ERROR;
    }
    
    // ������S��Ѱ��ģʽ��T��һ�γ��ֵ�λ��
    i = Index(*S, T, 1);
    
    // �������ƥ����ַ���
    while(i != 0) {
        StrDelete(S, i, StrLength(T));  // ��S��ɾ��T
        StrInsert(S, i, V);             // ��S�в���V
        
        i += StrLength(V);          // i�л�����һ��λ��
        
        i = Index(*S, T, i);        // ������һ��ƥ����ַ���
    }
    
    return OK;
}

/*
 * ������
 *
 * ����S1��S2�����洢��T�з��ء�������Ӻ�ĳ����������ֻ����δ����Ĳ��֡�
 * ����ֵ��ʾ���Ӻ�Ĵ��Ƿ�������
 * �Ѵ��Ŀռ䱻��Ϊ�����޵ģ�����������Ƿ���TRUE��ָʾ�����ᱻ�ü���
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status Concat(HString* T, HString S1, HString S2) {
    int i;
    
    // ȷ���³���
    (*T).length = S1.length + S2.length;
    
    // ����ռ�
    (*T).ch = (char*) malloc((*T).length * sizeof(char));
    if(!(*T).ch) {
        exit(OVERFLOW);
    }
    
    // �Ȱ�S1�����ݿ�������
    for(i = 0; i < S1.length; i++) {
        (*T).ch[i] = S1.ch[i];
    }
    
    // �ٿ���S2������
    for(i = 0; i < S2.length; i++) {
        (*T).ch[S1.length + i] = S2.ch[i];
    }
    
    return TRUE;
}
