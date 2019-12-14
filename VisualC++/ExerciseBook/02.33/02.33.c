#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <ctype.h>      // �ṩisalpha��isdigitԭ��
#include "Status.h"     //**��01 ����**//

/* ����Ԫ�����Ͷ��� */
typedef char ElemType;

// ��ѭ������ṹ��
typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode;

// ָ���������ָ��
typedef LNode* LinkList;


/*
 * ��2.33
 *
 * �����������ַ������֡���������
 */
Status Algo_2_33(LinkList L, LinkList* L_char, LinkList* L_num, LinkList* L_other);

// ��ʼ��һ������ѭ������
Status InitList(LinkList* L);

// ��ָ�������ݴ������С�ͷ���ĵ���ѭ������
Status CreatList(LinkList* L, ElemType elems[], int n);

// �����������
void Output(LinkList L);


int main(int argc, char* argv[]) {
    LinkList L, L_char, L_num, L_other;
    
    ElemType a[20+1] = "2a3@A5e$T*1%s&7pl(o)";
    
    // ׼���������ݣ����������
    CreatList(&L, a, 20);
    printf("L = ");
    Output(L);
    
    // �������
    Algo_2_33(L, &L_char, &L_num, &L_other);
    
    // �����ֺ������
    printf("L_char  = ");
    Output(L_char);
    printf("L_num   = ");
    Output(L_num);
    printf("L_other = ");
    Output(L_other);
    
    return 0;
}


// �����������ַ������֡���������
Status Algo_2_33(LinkList L, LinkList* L_char, LinkList* L_num, LinkList* L_other) {
    LinkList r, rc, rn, ro, s;
    
    if(L_char == NULL || L_num == NULL || L_other == NULL) {
        return ERROR;
    }
    
    if(L == NULL || L->next == L) {
        return ERROR;
    }
    
    InitList(L_char);
    InitList(L_num);
    InitList(L_other);
    
    r = L->next;
    rc = *L_char;
    rn = *L_num;
    ro = *L_other;
    
    while(r != L) {
        s = (LinkList) malloc(sizeof(LNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->data = r->data;
        
        // Ԫ��Ϊ�ַ�
        if(isalpha(r->data)) {
            s->next = rc->next;
            rc->next = s;
            rc = rc->next;
            
            // Ԫ��Ϊ����
        } else if(isdigit(r->data)) {
            s->next = rn->next;
            rn->next = s;
            rn = rn->next;
            
            // ����
        } else {
            s->next = ro->next;
            ro->next = s;
            ro = ro->next;
        }
        
        r = r->next;
    }
    
    return OK;
}


// ��ʼ��һ������ѭ������
Status InitList(LinkList* L) {
    if(L == NULL) {
        return ERROR;
    }
    
    (*L) = (LinkList) malloc(sizeof(LNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    (*L)->next = *L;
    
    return OK;
}

// ��ָ�������ݴ������С�ͷ���ĵ���ѭ������
Status CreatList(LinkList* L, ElemType elems[], int n) {
    LinkList s, r;
    int i;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // ��ʼ��ͷ���
    (*L) = (LinkList) malloc(sizeof(LNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    (*L)->next = *L;
    
    for(i = 0, r = *L; i < n; i++) {
        s = (LinkList) malloc(sizeof(LNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->data = elems[i];
        
        s->next = r->next;
        r->next = s;
        r = r->next;
    }
    
    return OK;
}

// �����������
void Output(LinkList L) {
    LinkList p;
    
    if(L == NULL || L->next == L) {
        return;
    }
    
    for(p = L->next; p != L; p = p->next) {
        printf("%c ", p->data);
    }
    
    printf("\n");
}
