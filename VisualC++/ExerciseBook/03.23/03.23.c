#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <string.h>     // �ṩstrlenԭ��
#include <ctype.h>      // �ṩisalphaԭ��
#include "SqStack.h"    //**��03 ջ�Ͷ���**//

/*
 * ����׺���ʽ���沨��ʽ��ת��Ϊǰ׺���ʽ������ʽ��
 *
 *��ע��
 * ���ʽ�ı���Ϊ����ĸ��������ֻ��'+'��'-'��'*'��'/'��������
 */
char* Algo_3_23(char* c);

// ���ַ�ת��Ϊ�ַ���
char* CharToStr(char c);

// ƴ���ַ���a��b������ƴ�Ӻ���ַ���
char* StrCat(char* a, char* b);


int main(int argc, char* argv[]) {
    char* s = "abc+*de/-";
    
    printf("��׺���ʽ��%s\n", "a*(b+c)-d/e");
    
    printf("��׺���ʽ��");
    printf("%s\n", s);
    
    printf("ǰ׺���ʽ��");
    printf("%s\n", Algo_3_23(s));
    
    return 0;
}


/*
 * ����׺���ʽ���沨��ʽ��ת��Ϊǰ׺���ʽ������ʽ��
 *
 *��ע��
 * ���ʽ�ı���Ϊ����ĸ��������ֻ��'+'��'-'��'*'��'/'��������
 */
char* Algo_3_23(char* c) {
    int i;
    char* s, * e1, * e2;
    SqStack S;
    
    InitStack(&S);
    
    for(i = 0; c[i] != '\0'; i++) {
        s = CharToStr(c[i]);
        
        // ��c[i]Ϊ������(���ǲ�����)����ջ������Ӧ��������Ԫ��
        if(!isalpha(c[i])) {
            if(Pop(&S, &e2) && Pop(&S, &e1)) {
                s = StrCat(s, StrCat(e1, e2));
            } else {
                return NULL;
            }
        }
        
        Push(&S, s);
    }
    
    Pop(&S, &s);
    
    if(StackEmpty(S)) {
        return s;
    }
    
    return NULL;
}

// ���ַ�ת��Ϊ�ַ���
char* CharToStr(char c) {
    char* s;
    
    s = (char*) malloc(2 * sizeof(char));
    
    s[0] = c;
    s[1] = '\0';
    
    return s;
}

// ƴ���ַ���a��b������ƴ�Ӻ���ַ���
char* StrCat(char* a, char* b) {
    char* s;
    int i, j, alen, blen;
    
    alen = (int) strlen(a);
    blen = (int) strlen(b);
    
    s = (char*) malloc((alen + blen + 1) * sizeof(char));
    
    j = 0;
    
    for(i = 0; i < alen; i++) {
        s[j++] = a[i];
    }
    
    for(i = 0; i < blen; i++) {
        s[j++] = b[i];
    }
    
    s[j] = '\0';
    
    return s;
}
