#include <stdio.h>
#include <stdlib.h>     // �ṩ malloc��realloc��free��exit ԭ��
#include <string.h>
#include "Status.h"     //**��01 ����**//

/*
 * ������Ԫ�����Ͷ���
 *
 *��ע��
 * �����������Ȼ�����ַ���������Ԫ��������Ȼ��int��ԭ���ǣ�
 * 1.��Ҫ����ͷ���洢����������������int��ֱ����char����
 * 2.char������int���ݣ����Խ����Ȼ��int����Ҳ���������洢char
 */
typedef int ElemType;

/*
 * ������ṹ
 *
 * ע������ĵ��������ͷ���
 */
typedef struct SNode {
    ElemType data;      // ���ݽ��
    struct SNode* next; // ָ����һ������ָ��
} SNode;

// ָ���������ָ�룬�����ַ�������
typedef SNode* String;


/*
 * ��ʼ��
 *
 * ����һ��ֵΪchars�Ĵ�T��
 */
Status StrAssign_4_21(String* S, char* chars);

/*
 * ����
 *
 * ����S���Ƶ���T��
 */
Status StrCopy_4_21(String* S, String T);

/*
 * �Ƚ�
 *
 * �Ƚϴ�S�ʹ�T�����رȽϽ����
 */
int StrCompare_4_21(String S, String T);

/*
 * ����
 *
 * ���ش�S��Ԫ�صĸ�����
 */
int StrLength_4_21(String S);

/*
 * ������
 *
 * ����S1��S2�����洢��T�з��ء�������Ӻ�ĳ����������ֻ����δ����Ĳ��֡�
 * ����ֵ��ʾ���Ӻ�Ĵ��Ƿ�������
 */
Status Concat_4_21(String* R, String S1, String S2);

/*
 * ���Ӵ�
 *
 * ��Sub����S[pos, pos+len-1]��
 * ����ֵָʾ�Ƿ��ȡ�ɹ���
 */
Status SubString_4_21(String* Sub, String S, int pos, int len);

// �ַ������
void StrPrint_4_21(String S);


int main(int argc, char* argv[]) {
    char* chars = "0123456789";
    String S, T;
    int i;
    
    printf("���������������� StrAssign \n");
    {
        printf("�� Ϊ˳�� S ��ֵ...\n");
        StrAssign_4_21(&S, chars);
        printf("�� S = ");
        StrPrint_4_21(S);
    }
    PressEnterToContinue();
    
    printf("���������������� StrLength \n");
    {
        i = StrLength_4_21(S);
        printf("�� S �ĳ���Ϊ %d \n", i);
    }
    PressEnterToContinue();
    
    printf("���������������� StrCopy \n");
    {
        printf("�� ���� S �� T ...\n");
        StrCopy_4_21(&T, S);
        printf("�� T = ");
        StrPrint_4_21(T);
    }
    PressEnterToContinue();
    
    printf("���������������� StrCompare \n");
    {
        printf("�� �Ƚ��ַ��� S �� T ...\n");
        i = StrCompare_4_21(S, T);
        i == 0 ? printf("�� S==T\n") : (i < 0 ? printf("�� S<T\n") : printf("�� S>T\n"));
    }
    PressEnterToContinue();
    
    printf("���������������� SubString \n");
    {
        String Sub;
        
        printf("�� �� Sub ���� S �е� 6 ���ַ���� 5 ���ַ�...\n");
        SubString_4_21(&Sub, S, 6, 5);
        printf("�� Sub = ");
        StrPrint_4_21(Sub);
    }
    PressEnterToContinue();
    
    
    printf("���������������� Concat \n");
    {
        String Tmp, S1, S2;
        
        StrAssign_4_21(&S1, "+++++");
        StrAssign_4_21(&S2, "-----");
        
        printf("�� ���� \"+++++\" �� \"-----\" �γ� Tmp ...\n");
        Concat_4_21(&Tmp, S1, S2);
        printf("�� Tmp = ");
        StrPrint_4_21(Tmp);
    }
    PressEnterToContinue();
    
    return 0;
}


/*
 * ��ʼ��
 *
 * ����һ��ֵΪchars�Ĵ�T��
 */
Status StrAssign_4_21(String* S, char* chars) {
    int i, len;
    String p;
    
    if(S == NULL || chars == NULL) {
        return ERROR;
    }
    
    len = (int) strlen(chars);
    
    *S = (SNode*) malloc(sizeof(SNode));
    (*S)->data = len;
    
    p = *S;
    
    for(i = 0; i < len; i++) {
        p->next = (SNode*) malloc(sizeof(SNode));
        p->next->data = chars[i];
        p = p->next;
    }
    
    p->next = NULL;
    
    return OK;
}

/*
 * ����
 *
 * ����S���Ƶ���T��
 */
Status StrCopy_4_21(String* S, String T) {
    String p, r, t;
    
    if(S == NULL || T == NULL) {
        return ERROR;
    }
    
    for(t = T; t != NULL; t = t->next) {
        r = (SNode*) malloc(sizeof(SNode));
        r->data = t->data;
        
        if(t == T) {
            *S = r;
            p = r;
        } else {
            p->next = r;
            p = p->next;
        }
    }
    
    p->next = NULL;
    
    return OK;
}

/*
 * �Ƚ�
 *
 * �Ƚϴ�S�ʹ�T�����رȽϽ����
 */
int StrCompare_4_21(String S, String T) {
    String s, t;
    
    if(S == NULL || T == NULL) {
        return StrLength_4_21(S) - StrLength_4_21(T);
    }
    
    s = S->next;
    t = T->next;
    
    while(s != NULL && t != NULL) {
        if(s->data != t->data) {
            return s->data - t->data;
        }
        
        s = s->next;
        t = t->next;
    }
    
    if(s == NULL && t != NULL) {
        return -1;
    } else if(s != NULL && t == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * ����
 *
 * ���ش�S��Ԫ�صĸ�����
 */
int StrLength_4_21(String S) {
    return S == NULL ? 0 : S->data;
}

/*
 * ������
 *
 * ����S1��S2�����洢��T�з��ء�������Ӻ�ĳ����������ֻ����δ����Ĳ��֡�
 * ����ֵ��ʾ���Ӻ�Ĵ��Ƿ�������
 */
Status Concat_4_21(String* R, String S1, String S2) {
    String r, s, p;
    
    if(R == NULL || S1 == NULL || S2 == NULL) {
        return ERROR;
    }
    
    *R = (SNode*) malloc(sizeof(SNode));
    (*R)->data = S1->data + S2->data;
    
    r = *R;
    
    for(s = S1->next; s != NULL; s = s->next) {
        p = (SNode*) malloc(sizeof(SNode));
        p->data = s->data;
        r->next = p;
        r = r->next;
    }
    
    for(s = S2->next; s != NULL; s = s->next) {
        p = (SNode*) malloc(sizeof(SNode));
        p->data = s->data;
        r->next = p;
        r = r->next;
    }
    
    r->next = NULL;
    
    return OK;
}

/*
 * ���Ӵ�
 *
 * ��Sub����S[pos, pos+len-1]��
 * ����ֵָʾ�Ƿ��ȡ�ɹ���
 */
Status SubString_4_21(String* Sub, String S, int pos, int len) {
    int i, slen;
    String sub, s, p;
    
    slen = StrLength_4_21(S);
    
    if(Sub == NULL || S == NULL || pos < 1 || pos > slen || len < 0 || pos + len - 1 > slen) {
        return ERROR;
    }
    
    *Sub = (SNode*) malloc(sizeof(SNode));
    (*Sub)->data = len;
    
    for(i = 0, s = S; i < pos; i++, s = s->next) {
        // ���ҵ�pos����㣬����sָ����
    }
    
    sub = *Sub;
    
    for(i = 0; i < len; i++) {
        sub->next = (SNode*) malloc(sizeof(SNode));
        sub->next->data = s->data;
        sub = sub->next;
        
        s = s->next;
    }
    
    sub->next = NULL;
    
    return OK;
}

// �ַ������
void StrPrint_4_21(String S) {
    String p;
    
    if(S == NULL) {
        return;
    }
    
    for(p = S->next; p != NULL; p = p->next) {
        printf("%c", p->data);
    }
    printf("\n");
}
