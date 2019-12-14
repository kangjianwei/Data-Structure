#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"             //**��01 ����**//

/*
 * ������Ԫ�����Ͷ���
 *
 *��ע��
 * �����������Ȼ�����ַ���������Ԫ��������Ȼ��int��ԭ���ǣ�
 * 1.��Ҫ����ͷ���洢����������������int��ֱ����char����
 * 2.char������int���ݣ����Խ����Ȼ��int����Ҳ���������洢char
 */
typedef int ElemType;

/* �ַ������ */
typedef struct SNode {
    ElemType chdata;        // ���ݽ��
    struct SNode* succ;  // ָ���̽��
    struct SNode* next;  // next�������У�ָ��ǰ����㣬��ģʽ���У�ָ��ý�㴦ʧ��ʱӦ������Ƚϵ���һ�����
} SNode;

// �ַ���
typedef SNode* String;


// ��ʼ��
Status StrAssign_4_28(String* S, char* chars);

// �󴮳�
int StrLength_4_28(String S);

// �ַ������
void StrPrint_4_28(String S);

/*
 * ����ģʽ����nextֵ���Ľ�����㷨��
 *
 * �����൱��KMP�㷨���µ�get_nextval����
 */
Status Algo_4_28(String T);

/*
 * KMP�㷨
 *
 * �����൱��KMP�㷨���µ�Index_KMP����
 */
int Algo_4_29(String S, String T, int pos);


int main(int argc, char* argv[]) {
    char* s = "abaaabaababaabcaabaabcacabaabcaabaabcac";
    char* t = "abaabcac";
    String S, T;
    int pos, i;
    
    StrAssign_4_28(&S, s);  //����
    StrAssign_4_28(&T, t);  //ģʽ��
    
    printf("��������S = ");
    StrPrint_4_28(S);
    printf("ģʽ����T = ");
    StrPrint_4_28(T);
    
    printf("�������� 4.28 ��֤...������\n");
    Algo_4_28(T);
    printf("����next��...\n");
    
    printf("�������� 4.29 ��֤...������\n");
    pos = 18;
    i = Algo_4_29(S, T, pos);
    printf("ģʽ�� T ������ S �ĵ� %d ���ַ����һ��ƥ��ɹ���λ��Ϊ %d\n", pos, i);
    
    return 0;
}


// ��ʼ��
Status StrAssign_4_28(String* S, char* chars) {
    int i, len;
    String p;
    
    if(S == NULL || chars == NULL) {
        return ERROR;
    }
    
    len = (int) strlen(chars);
    
    // ����ͷ���
    *S = (String) malloc(sizeof(SNode));
    (*S)->chdata = len; // ��¼���ĳ���
    (*S)->next = NULL;  // ͷ����ǰ��
    
    p = *S;
    
    for(i = 0; i < len; i++) {
        p->succ = (String) malloc(sizeof(SNode));
        p->succ->chdata = chars[i];
        p->succ->next = p;          // nextĬ��ָ��ǰһ�����
        p = p->succ;
    }
    
    // ���һ�����ĺ��ΪNULL
    p->succ = NULL;
    
    return OK;
}

// �󴮳�
int StrLength_4_28(String S) {
    return S == NULL ? 0 : S->chdata;
}

// �ַ������
void StrPrint_4_28(String S) {
    String p;
    
    if(S == NULL) {
        printf("\n");
        return;
    }
    
    for(p = S->succ; p != NULL; p = p->succ) {
        printf("%c", p->chdata);
    }
    
    printf("\n");
}

/*
 * ����ģʽ����nextֵ���Ľ�����㷨��
 *
 * �����൱��KMP�㷨���µ�get_nextval����
 */
Status Algo_4_28(String T) {
    SNode* i, * j;
    
    if(StrLength_4_28(T) == 0) {
        return ERROR;
    }
    
    i = T->succ;    // �൱��֮ǰ��i=1
    j = T;          // �൱��֮ǰ��j=0
    
    // ģʽ����һ���ַ���ʧ��ʱ��ģʽ����Ҫ��ͷ�Ƚϣ�������Ҫǰ������һ��λ�ñȽ�
    i->next = T;
    
    // ����ģʽ���ϵ��ַ�
    while(i->succ != NULL) {
        if(j == T || i->chdata == j->chdata) {
            i = i->succ;
            j = j->succ;
            
            if(i->chdata != j->chdata) {
                i->next = j;
            } else {
                i->next = j->next;
            }
        } else {
            j = j->next;
        }
    }
    
    return OK;
}

/*
 * KMP�㷨
 *
 * �����൱��KMP�㷨���µ�Index_KMP����
 */
int Algo_4_29(String S, String T, int pos) {
    int count;        // ��¼i��λ��
    SNode* i, * j;    // i����S��j����T
    
    if(pos < 1 || StrLength_4_28(S) == 0 || StrLength_4_28(T) == 0) {
        return 0;
    }
    
    for(count = 1, i = S->succ; count < pos; count++, i = i->succ) {
        // ��iָ���pos�����
    }
    
    j = T->succ;
    
    // �Ƚ��ַ���
    while(i != NULL && j != NULL) {
        /*
         * �������Σ�
         * 1.��ģʽ���ĵ�һ���ַ�����ʧ��
         * 2.������ģʽ�������ַ����
         */
        if(j == T || i->chdata == j->chdata) {
            i = i->succ;
            j = j->succ;
            
            count++;        // ��¼i��λ��
        } else {
            // ʧ��ʱ�ص�ǰһ���ʵ���λ��
            j = j->next;
        }
    }
    
    // ƥ��ɹ�������ƥ��λ��
    if(j == NULL) {
        return count-StrLength_4_28(T);
    } else {
        // ƥ��ʧ��
        return 0;
    }
}
