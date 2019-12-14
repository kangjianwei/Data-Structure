/*================
 * �ַ�������������
 =================*/

#include "StringUtil.h"

/*
 * ɾ��
 *
 * ɾ��s[pos, pos+len-1]��pos��1��ʼ������
 */
Status StrDelete(char** s, int pos, int n) {
    int len;
    char* ss;
    
    len = (int) strlen(*s);
    
    if(pos < 1 || pos + n - 1 > len || n < 0) {
        return ERROR;
    }
    
    // �����ɾ���ĳ���Ϊ0������ǰ����
    if(n == 0) {
        return ERROR;
    }
    
    ss = (char*) malloc((len - n + 1) * sizeof(char));
    
    strncpy(ss, *s, pos - 1);
    strncpy(ss, *s + pos + n - 1, len - pos - n + 1);
    
    ss[len - n] = '\0';
    
    *s = ss;
    
    return OK;
}

/*
 * ���Ӵ�
 *
 * ��sub����s[pos, pos+len-1]��pos��1��ʼ������
 */
Status SubString(char** sub, char* s, int pos, int n) {
    int len, i;
    
    len = (int) strlen(s);
    
    if(pos < 1 || pos > len || n < 0 || pos + n - 1 > len) {
        *sub = NULL;
        return ERROR;
    }
    
    *sub = (char*) malloc((n + 1) * sizeof(char));
    
    for(i = 0; i < n; i++) {
        (*sub)[i] = s[pos + i - 1];
    }
    
    // ȷ���³���
    (*sub)[n] = '\0';
    
    return OK;
}

/*
 * �п�
 *
 * �жϴ�s���Ƿ������Ч���ݡ�
 */
Status StrEmpty(char* s) {
    return strlen(s) == 0 ? TRUE : FALSE;
}

/*
 * ����
 *
 * �����ַ���s�еĿհף����������ɴ�ӡ�ַ�������ո�
 */
Status ClearBlank(char** s) {
    int len;
    int i, j;
    char* ss;
    
    len = (int) strlen(*s);
    if(len == 0) {
        return ERROR;
    }
    
    ss = (char*) malloc((len + 1) * sizeof(char));
    
    for(i = 0, j = 0; i < len; i++) {
        // ��������հף����Թ�
        if((*s)[i] == ' ' || !isprint((*s)[i])) {
            continue;
        }
        
        ss[j++] = (*s)[i];
    }
    
    ss[j] = '\0';
    
    *s = ss;
    
    return OK;
}

/*
 * ����
 *
 * ͳ���ַ���s�е�Ԫ�ظ�����
 * ���������֮�����ڣ��������֣��Ὣ�䵱��һ��Ԫ�ء�
 */
int ElemCount(const char* s) {
    int count;
    float f;
    char c;
    char* sub;
    
    if(s==NULL || strlen(s) == 0) {
        return 0;
    }
    
    sub = (char*) malloc((strlen(s) + 1) * sizeof(char));
    sub[0] = '\0';
    
    // �������������
    if(sscanf(s, "%f", &f) == 1) {
        sscanf(s, "%f%s", &f, sub);
    } else {
        sscanf(s, "%c%s", &c, sub);
    }
    
    count = ElemCount(sub);
    
    return 1 + count;
}

/*
 * ȡֵ
 *
 * ��ȡ�ַ���s�е�pos��Ԫ��(pos��1��ʼ����)������f���ա�
 * ���������֮�����ڣ��������֣��Ὣ�䵱��һ��Ԫ�ء�
 */
Status GetElem(char* s, int pos, float* f) {
    int len;
    
    len = (int) strlen(s);
    
    if(pos < 1 || pos > len) {
        return ERROR;
    }
    
    // �ȳ��Զ����֣���ȡʧ�ܵĻ����ٳ��Զ��ַ�
    if(sscanf(s + pos - 1, "%f", f) < 1) {
        *f = s[pos - 1];
    }
    
    return OK;
}
