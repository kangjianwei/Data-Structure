#include <stdio.h>
#include <stdlib.h>     //�ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* ����Ԫ�����Ͷ��� */
typedef int ElemType;

// ����ѭ������ṹ����ͷ��㣩
typedef struct LNode {
    ElemType data;      // ���ݽ��
    struct LNode* next; // ָ����һ������ָ��
} LNode;

// ָ���������ָ��
typedef LNode* LinkList;


/*
 * ��2.31
 *
 * ɾ��s����ǰ��
 */
Status Algo_2_31(LinkList* L, LinkList s);

// ��ָ�������ݴ������ޡ�ͷ���ĵ���ѭ������
Status CreatList(LinkList* L, ElemType elems[], int n);

// �������L
void Output(LinkList L);


int main(int argc, char* argv[]) {
    LinkList L, s;
    
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // ׼����������
    CreatList(&L, a, 10);
    printf("L = ");
    Output(L);
    
    s = L->next->next->next->next;
    
    printf("ɾ�� %d ��ǰ����...\n", s->data);
    Algo_2_31(&L, s);
    
    printf("L = ");
    Output(L);
    
    return 0;
}

// ɾ��s����ǰ��
Status Algo_2_31(LinkList* L, LinkList s) {
    LinkList p, pre;
    
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    // ��ǰ��
    if(s == NULL || s->next == s) {
        return ERROR;
    }
    
    p = s;
    
    // ʹ��p->nextָ��s��ǰ��
    while(p->next->next != s) {
        p = p->next;
    }
    
    // s��ǰ��
    pre = p->next;
    
    // ɾ��ǰ��
    p->next = pre->next;
    free(pre);
    
    // ���ǰ��������
    if(pre == *L) {
        *L = s;
    }
    
    return OK;
}

// ��ָ�������ݴ�����ͷ���ĵ���ѭ������
Status CreatList(LinkList* L, ElemType elems[], int n) {
    LinkList s, r;
    int i;
    
    if(L == NULL) {
        return ERROR;
    }
    
    *L = NULL;
    
    for(i = 0; i < n; i++) {
        s = (LinkList) malloc(sizeof(LNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        
        s->data = elems[i];
        
        if(i == 0) {
            *L = s;
            s->next = *L;   // ѭ��
            r = *L;
        } else {
            s->next = r->next;
            r->next = s;
            r = r->next;
        }
    }
    
    return OK;
}

// �������L
void Output(LinkList L) {
    LinkList p;
    
    if(L == NULL) {
        return;
    }
    
    printf("%2d ", L->data);
    
    for(p = L->next; p != L; p = p->next) {
        printf("%2d ", p->data);
    }
    
    printf("\n");
}
