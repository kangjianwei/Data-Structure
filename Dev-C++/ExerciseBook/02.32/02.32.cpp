#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* ����Ԫ�����Ͷ��� */
typedef int ElemType;

// ˫ѭ������ṹ��
typedef struct LNode {
    ElemType data;
    struct LNode* next;
    struct LNode* pre;
} LNode;

// ָ���������ָ��
typedef LNode* LinkList;


/*
 * ��2.32
 *
 * ������ѭ�������޸�Ϊ˫��ѭ������
 */
Status Algo_2_32(LinkList L);

// ��ָ�������ݴ������С�ͷ���ĵ���ѭ������
Status CreatList(LinkList* L, ElemType elems[], int n);

// �����������
void Output(LinkList L);

// �����������
void OutputReverse(LinkList L);


int main(int argc, char* argv[]) {
    LinkList L;
    ElemType a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // ׼���������ݣ����������
    CreatList(&L, a, 10);
    printf("L = ");
    Output(L);
    
    // ��Ϊ˫������
    Algo_2_32(L);
    
    // �����������
    printf("L = ");
    OutputReverse(L);
    
    return 0;
}


// ������ѭ�������޸�Ϊ˫��ѭ������
Status Algo_2_32(LinkList L) {
    LinkList r;
    
    if(L==NULL || L->next==L) {
        return ERROR;
    }
    
    for(r = L; r->next != L; r = r->next) {
        r->next->pre = r;
    }
    
    L->pre = r;
    
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
    (*L)->pre = NULL;
    (*L)->next = *L;
    
    for(i = 0, r = *L; i < n; i++) {
        s = (LinkList) malloc(sizeof(LNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->data = elems[i];
        s->pre = NULL;
        
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
        printf("%2d ", p->data);
    }
    
    printf("\n");
}

// �����������
void OutputReverse(LinkList L) {
    LinkList p;
    
    if(L == NULL || L->pre == L) {
        return;
    }
    
    for(p = L->pre; p != L; p = p->pre) {
        printf("%2d ", p->data);
    }
    
    printf("\n");
}
