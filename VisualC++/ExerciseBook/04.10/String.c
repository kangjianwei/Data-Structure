/*===========================
 * ϰ��4.10~4.14��ʹ�õ��ַ���
 ============================*/

#include "String.h"

// ��ʼ��������һ��ֵΪs�Ĵ�t
void StrAssign(StringType* t, const char* s) {
    if(s == NULL) {
        *t = "";
    }
    
    *t = (char*) malloc((strlen(s) + 1) * sizeof(char));
    
    strcpy(*t, s);
}

// �Ƚϣ�����s��t�Ĵ�С�������Сһ�£�����0
int StrCompare(StringType s, StringType t) {
    return strcmp(s, t);
}

// �����������ַ���s�ĳ���
int StrLength(StringType s) {
    return (int) strlen(s);
}

// ���ӣ�������s��t���Ӻ�Ĵ�
StringType Concat(StringType s, StringType t) {
    StringType r;
    
    if(s == NULL) {
        s = "";
    }
    
    if(t == NULL) {
        t = "";
    }
    
    r = (char*) malloc((strlen(s) + strlen(t) + 1) * sizeof(char));
    r[0] = '\0';
    
    strcat(r, s);
    strcat(r, t);
    
    return r;
}

// ���Ӵ�����s��startλ���𣬽�ȡlen���ַ��󷵻�
StringType SubString(StringType s, int start, int len) {
    int n;
    char* sub;
    
    n = (int) strlen(s);
    
    if(start < 1 || start > n || start + len - 1 > n || len < 0) {
        return "";
    }
    
    sub = (char*) malloc((len + 1) * sizeof(char));
    strncpy(sub, s + start - 1, len);
    sub[len] = '\0';
    
    return sub;
}

// ���ң���s��posλ�������t������ҵ���������λ��
int Index(StringType s, StringType t, int pos) {
    int m, n, i;
    StringType sub;
    
    // ʧ��������ǰ����
    if(pos < 1 || pos > StrLength(s) || StrLength(t) == 0) {
        return 0;
    }
    
    n = StrLength(s);
    m = StrLength(t);
    i = pos;
    
    // ��֤���Ȳ�Խ��
    while(i <= n - m + 1) {
        // ��ȡS[i, i+m-1]
        sub = SubString(s, i, m);
        
        // ����Ӵ���ģʽ����ƥ�䣬����Ҫ�����ƽ�
        if(StrCompare(sub, t) != 0) {
            ++i;
        } else {
            return i;
        }
    }
    
    return 0;
}

// ���룺��s��pos������t
Status StrInsert(StringType* s, int pos, StringType t) {
    StringType r;
    StringType s1, s2;
    
    if(pos < 1 || pos > StrLength(*s) + 1) {
        return ERROR;
    }
    
    r = (StringType) malloc((strlen(*s) + strlen(t) + 1) * sizeof(char));
    r[0] = '\0';
    
    // ���������Ĵ�Ϊ�գ�����ǰ����
    if(StrLength(t) == 0) {
        return OK;
    }
    
    s1 = SubString(*s, 1, pos - 1);
    s2 = SubString(*s, pos, (int) strlen(*s) - pos + 1);
    
    strcat(r, s1);
    strcat(r, t);
    strcat(r, s2);
    
    *s = r;
    
    return OK;
}

// ɾ������s��posλ����ɾ��len���ַ�
Status StrDelete(StringType* s, int pos, int len) {
    StringType r;
    
    if(pos < 1 || pos + len - 1 > StrLength(*s) || len < 0) {
        return ERROR;
    }
    
    // �����ɾ���ĳ���Ϊ0������ǰ����
    if(len == 0) {
        return OK;
    }
    
    r = (StringType) malloc((StrLength(*s) - len + 1) * sizeof(char));
    strncpy(r, *s, pos - 1);
    strcpy(r + pos - 1, *s + pos + len - 1);
    
    *s = r;
    
    return OK;
}

// ����ַ���
void StrPrint(StringType s) {
    printf("%s\n", s);
}
