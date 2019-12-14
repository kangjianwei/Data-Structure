#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* ˫��ѭ������Ԫ�����Ͷ��� */
typedef int ElemType;

/*
 * ˫��ѭ������ṹ��������һ������ƴ����
 *
 * ע�������˫��ѭ���������ͷ���
 */
typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior;  // ǰ��
    struct DuLNode* next;   // ���
    int freq;               // ����Ƶ����
} DuLNode;

// ָ��˫ѭ������ṹ��ָ��
typedef DuLNode* DuLinkList;

/*
 * ��2.38
 *
 * ����Ԫ��e���״���L�г��ֵ�λ�򣬲�������Ƶ����������
 */
DuLinkList Algo_2_38(DuLinkList* L, ElemType e);

// ����˫ѭ������
Status CreatList(DuLinkList* L, ElemType elems[], int n);

// �����������
void Output(DuLinkList L);


int main(int argc, char* argv[]) {
    DuLinkList L;
    int i;
    ElemType data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ElemType visit[10] = {1, 2, 2, 2, 3, 4, 4, 5, 5, 9};
    
    CreatList(&L, data, 10);
    printf("����ǰ�� L = \n");
    Output(L);
    
    // ���η���tmp��Ԥ�������
    for(i = 0; i < 10; i++) {
        Algo_2_38(&L, visit[i]);
    }
    
    printf("���ʺ�L = \n");
    Output(L);
    
    return 0;
}

// ����Ԫ��e���״���L�г��ֵ�λ�򣬲�������Ƶ����������
DuLinkList Algo_2_38(DuLinkList* L, ElemType e) {
    DuLinkList pre, r;
    
    // ȷ���������
    if(L == NULL || *L == NULL) {
        return NULL;
    }
    
    for(pre = *L; pre->next != *L && pre->next->data != e; pre = pre->next) {
        // ����Ԫ��e��ǰ��
    }
    
    // û�ҵ�����������Ԫ��
    if(pre->next == *L) {
        return NULL;
    }
    
    // ժ��Ԫ��e
    r = pre->next;
    pre->next = r->next;
    r->next->prior = pre;
    
    // Ƶ����һ
    r->freq++;
    
    for(pre = *L; pre->next != *L && pre->next->freq > r->freq; pre = pre->next) {
        // ���ݷ���Ƶ�ȣ�Ѱ��Ԫ��eӦ�ò����λ�õ�ǰ��
    }
    
    // ��Ԫ��e���뵽���ʵ�λ��
    r->next = pre->next;
    r->prior = pre;
    pre->next->prior = r;
    pre->next = r;
    
    // ����ָ��Ԫ��e������
    return r;
}

// ����˫ѭ������
Status CreatList(DuLinkList* L, ElemType elems[], int n) {
    DuLinkList s, p;
    int i;
    
    *L = (DuLinkList) malloc(sizeof(DuLNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    (*L)->data = -1;
    (*L)->prior = *L;
    (*L)->next = *L;
    (*L)->freq = 0;
    
    p = *L;
    
    for(i = 0; i < n; i++) {
        s = (DuLinkList) malloc(sizeof(DuLNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->data = elems[i];
        s->freq = 0;
        
        // β��
        s->next = *L;
        (*L)->prior = s;
        s->prior = p;
        p->next = s;
        
        p = p->next;
    }
    
    return OK;
}

// �����������
void Output(DuLinkList L) {
    DuLinkList p;
    
    if(L == NULL || L->next == L || L->prior == NULL) {
        return;
    }
    
    printf("���ݣ�");
    for(p = L->next; p != L; p = p->next) {
        printf("%2d ", p->data);
    }
    printf("\n");
    
    printf("Ƶ�ȣ�");
    for(p = L->next; p != L; p = p->next) {
        printf("%2d ", p->freq);
    }
    printf("\n");
}
