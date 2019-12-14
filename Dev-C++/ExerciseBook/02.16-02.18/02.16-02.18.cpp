#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* ������Ԫ�����Ͷ��� */
typedef int ElemType;

/*
 * ������ṹ
 *
 * ע������ĵ�����û�С�ͷ���
 */
typedef struct LNode {
    ElemType data;      // ���ݽ��
    struct LNode* next; // ָ����һ������ָ��
} LNode;

// ָ���������ָ��
typedef LNode* LinkList;


/*
 * ��2.16
 *
 * ɾ��la�е�i��λ�����len��Ԫ�أ���������ӵ�lb��j��λ��֮ǰ��
 */
Status Algo_2_16(LinkList* la, LinkList* lb, int i, int j, int len);

/*
 * ��2.17
 *
 * ��Ԫ��b���뵽����L��i��λ���ϣ�i��Ԫ�ص�λ�򣬴�1��ʼ��������
 */
Status Algo_2_17(LinkList* L, int i, ElemType b);

/*
 * ��2.18
 *
 * ɾ������L�ĵ�i����㣬i��Ԫ�ص�λ�򣬴�1��ʼ������
 */
Status Algo_2_18(LinkList* L, int i);

// ��ʼ����ͷ��������L
void InitList(LinkList* L);

// �����ͷ���������е�Ԫ��
void Output(LinkList L);


int main(int argc, char* argv[]) {
    int i;
    LinkList la, lb;
    
    InitList(&la);
    InitList(&lb);
    
    printf("���������������� �� 2.17 ��֤...\n");
    for(i = 1; i <= 10; i++) {
        Algo_2_17(&la, i, 2 * i - 1);
        Algo_2_17(&lb, i, 2 * i);
    }
    printf("�� ������ͷ�������\n");
    printf("�� la = ");
    Output(la);
    printf("�� lb = ");
    Output(lb);
    PressEnterToContinue();
    
    printf("���������������� �� 2.16 ��֤...\n");
    printf("�� ��la�дӵ�2��������5�������뵽lb�ĵ�6�����֮ǰ...\n");
    Algo_2_16(&la, &lb, 2, 6, 5);
    printf("�� la = ");
    Output(la);
    printf("�� lb = ");
    Output(lb);
    PressEnterToContinue();
    
    printf("���������������� �� 2.18 ��֤...\n");
    printf("�� ɾ��lb��6��������5�����...\n");
    for(i = 1; i <= 5; i++) {
        Algo_2_18(&lb, 6);
    }
    printf("�� ɾ����ɺ�lb = ");
    Output(lb);
    
    return 0;
}


// ɾ��la�е�i��λ�����len��Ԫ�أ���������ӵ�lb��j��λ��֮ǰ
Status Algo_2_16(LinkList* la, LinkList* lb, int i, int j, int len) {
    LinkList p;     // ָ��la�е�i-1�����
    LinkList q;     // ָ��la�е�i+len-1�����
    LinkList r;     // ָ��q����Ľ��
    LinkList s;     // ָ��lb�е�j-1�����
    int k;
    
    if(i <= 0 || j <= 0 || len <= 0) {
        return ERROR;
    }
    
    // ȷ��la���н���ժ
    if(la == NULL || *la == NULL) {
        return ERROR;
    }
    
    
    // ȷ��p��λ��
    k = 1;
    p = *la;
    
    if(i == 1) {
        p = NULL;
    } else {
        // ����la�е�i-1����㣬�ұ�֤����̴���
        while(p->next != NULL && k < i - 1) {
            ++k;
            p = p->next;
        }
        
        // δ�ҵ����ʵ�λ��
        if(p->next == NULL) {
            return ERROR;
        }
    }
    
    
    // ȷ��q��λ��
    if(p == NULL) {
        q = *la;
    } else {
        q = p->next;
    }
    k = i;
    
    while(q != NULL && k < i + len - 1) {
        ++k;
        q = q->next;
    }
    
    if(q == NULL) {
        return ERROR;
    }
    
    // ȷ��r��λ��
    r = q->next;
    
    
    if(lb == NULL) {
        return ERROR;
    }
    
    // ȷ��s��λ��
    k = 1;
    s = *lb;
    
    // ���뵽lb��һ��λ��֮ǰ
    if(j == 1) {
        q->next = *lb;
        
        if(p == NULL) {
            *lb = *la;
            *la = r;
        } else {
            *lb = p->next;
            p->next = r;
        }
    } else {
        // ����lb�е�j-1����㣬�ұ�֤����̴���
        while(s->next != NULL && k < j - 1) {
            ++k;
            s = s->next;
        }
        
        // δ�ҵ����ʵ�λ��
        if(s->next == NULL) {
            return ERROR;
        }
    
        q->next = s->next;
    
        if(p == NULL) {
            *lb = *la;
            *la = r;
        } else {
            s->next = p->next;
            p->next = r;
        }
    }
    
    return OK;
}

// ��Ԫ��b���뵽����L��i��λ����
Status Algo_2_17(LinkList* L, int i, ElemType b) {
    LinkList p, s;
    int j;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // i��1��ʼ����
    if(i <= 0) {
        return ERROR;
    }
    
    // �����½��
    s = (LinkList) malloc(sizeof(LNode));
    if(s == NULL) {
        exit(OVERFLOW);
    }
    s->data = b;
    
    j = 1;
    p = *L;
    
    // ��������
    if(i == 1) {
        s->next = p;
        *L = s;
    } else {
        // ���ҵ�i-1����㣬�ұ�֤���������
        while(p != NULL && j < i - 1) {
            ++j;
            p = p->next;
        }
        
        // δ�ҵ����ʵ�λ��
        if(p == NULL) {
            return ERROR;
        }
        
        s->next = p->next;
        p->next = s;
    }
    
    return OK;
}

// ɾ������L�ĵ�i�����
Status Algo_2_18(LinkList* L, int i) {
    LinkList p, q;
    int j;
    
    // ȷ���н���ɾ��
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    // i��1��ʼ����
    if(i <= 0) {
        return ERROR;
    }
    
    j = 1;
    p = *L;
    
    // ��������
    if(i == 1) {
        *L = p->next;
        free(p);
    } else {
        // ���ҵ�i-1����㣬�ұ�֤����̴���
        while(p->next != NULL && j < i - 1) {
            ++j;
            p = p->next;
        }
        
        // δ�ҵ����ʵ�λ��
        if(p->next == NULL) {
            return ERROR;
        }
        
        q = p->next;
        p->next = q->next;
        free(q);
    }
    
    return OK;
}

// ��ʼ����ͷ��������L
void InitList(LinkList* L) {
    *L = NULL;
}

// �����ͷ���������е�Ԫ��
void Output(LinkList L) {
    while(L != NULL) {
        printf("%2d ", L->data);
        L = L->next;
    }
    
    printf("\n");
}
