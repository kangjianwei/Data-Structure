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
 * ����
 *
 * ����S���١�
 *
 *��ע��
 * ˳�򴮵Ľṹ�޷�����
 */
Status DestroyString(SString S) {
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
int Index_1(SString S, SString T, int pos) {
    int i, n, m;       // ��¼S��T�ĳ���
    SString sub;
    
    /*
     * ʧ��������ǰ����
     * ������̲�д����΢��ͬ
     */
    if(pos < 1 || pos > S[0] || StrEmpty(T)) {
        return 0;
    }
    
    n = StrLength(S);
    m = StrLength(T);
    i = pos;
    
    // ��֤���Ȳ�Խ��
    while(i <= n - m + 1) {
        // ��ȡS[i, i+m-1]
        SubString(sub, S, i, m);
        
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
int Index_2(SString S, SString T, int pos) {
    int i = pos;
    int j = 1;
    
    if(pos < 1 || pos > S[0] || StrEmpty(T)) {
        return 0;
    }
    
    while(i <= S[0] && j <= T[0]) {
        // ������ͬ�ַ���������ȽϺ���ַ�
        if(S[i] == T[j]) {
            i++;
            j++;
            
            // ������ͬ���ַ������α���Ҫ���ˣ����±Ƚ�
        } else {
            i = i - (j - 1) + 1;    // j-1����ͽ�͵�ǰ����j-1��Ԫ�أ��ڵ�j��Ԫ���Ϲ���һ��
            j = 1;                  // �α�j�ص���T�ĵ�һ��λ��
        }
    }
    
    // ������һ��T[0]>0���ж�
    if(j > T[0] && T[0] > 0) {      // T��Ϊ�մ�
        return i - T[0];            // ƥ��ɹ�
    } else {
        return 0;
    }
}

/*
 * ����
 *
 * ����T���뵽����S��posλ�ô���
 */
Status StrInsert(SString S, int pos, SString T) {
    int i;
    
    if(pos < 1 || pos > S[0] + 1 || S[0] + T[0] > MAXSTRLEN) {
        return ERROR;
    }
    
    // ���������Ĵ�Ϊ�գ�����ǰ����
    if(StrEmpty(T)) {
        return OK;
    }
    
    // ��S���ڳ�λ�ã�Ϊ����T��׼��
    for(i = S[0]; i >= pos; i--) {
        // �Ӻ���ǰ��������ǰ���Ԫ��Ų������
        S[i + T[0]] = S[i];
    }
    
    // ����T������S���ڳ���λ����
    for(i = pos; i <= pos + T[0] - 1; i++) {
        S[i] = T[i - pos + 1];
    }
    
    // ��������
    S[0] += T[0];
    
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
 * �滻
 *
 * ��V�滻����S�г��ֵ�������T��ȵ��Ҳ��ص����Ӵ���
 *
 *��ע��
 * 1.�ò���������С�����Ӽ�
 * 2.��ʵ�ֱȽϵ�Ч
 */
Status Replace(SString S, SString T, SString V) {
    int i;
    
    if(StrEmpty(S) || StrEmpty(T)) {
        return ERROR;
    }
    
    // ������S��Ѱ��ģʽ��T��һ�γ��ֵ�λ��
    i = Index_2(S, T, 1);
    
    // �������ƥ����ַ������ҿ��Ա���ȫ�滻���滻�������
    while(i != 0 && S[0] - T[0] + V[0] <= MAXSTRLEN) {
        StrDelete(S, i, StrLength(T));  // ��S��ɾ��T
        StrInsert(S, i, V);             // ��S�в���V
        
        i += StrLength(V);      // i�л�����һ��λ��
        
        i = Index_2(S, T, i);   // ������һ��ƥ����ַ���
    }
    
    if(i == 0) {                // S�е�T��ȫ�����滻
        return OK;
    } else {                    // S������T������V�Ѿ��岻��ȥ��
        return ERROR;
    }
}

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
Status Concat(SString T, SString S1, SString S2) {
    int i;
    int uncut;  // �´��Ƿ�����
    
    // ��ȫ����Ҫ�ü�
    if(S1[0] + S2[0] <= MAXSTRLEN) {
        // ����S1��T��
        for(i = 1; i <= S1[0]; i++) {
            T[i] = S1[i];
        }
        
        // ����S2��T��
        for(i = S1[0] + 1; i <= S1[0] + S2[0]; i++) {
            T[i] = S2[i - S1[0]];
        }
        
        // �����³���
        T[0] = S1[0] + S2[0];
        
        // δ�ü�������
        uncut = TRUE;
        
        // ��Ҫ�ü�S2
    } else if(S1[0] <= MAXSTRLEN) {
        // ����S1��T��
        for(i = 1; i <= S1[0]; i++) {
            T[i] = S1[i];
        }
        
        // ��S2��һ���ָ��Ƶ�T��
        for(i = S1[0] + 1; i <= MAXSTRLEN; i++) {
            T[i] = S2[i - S1[0]];
        }
        
        // �����³���
        T[0] = MAXSTRLEN;
        
        uncut = FALSE;
        
        // ֻ��Ҫ����S1��һ����
    } else {
        // ��ͬ������Ϣһ����
        for(i = 0; i <= MAXSTRLEN; i++) {
            T[i] = S1[i];
        }
        
        uncut = FALSE;
    }
    
    return uncut;
}

// �������ӡ�ַ���
void StrPrint(SString S) {
    int i;
    
    for(i = 1;  i<=S[0] ; i++) {
        printf("%c", S[i]);
    }
    
    printf("\n");
}
