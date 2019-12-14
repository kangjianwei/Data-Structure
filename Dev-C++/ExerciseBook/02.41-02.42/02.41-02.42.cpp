#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

// ϡ�����ʽ����
typedef struct {
    int coef;   // ϵ��
    int exp;    // ָ��
} PolyTerm;

// ϡ�����ʽ��ʽ�ṹ���������ѭ������ṹ��
typedef struct PolyNode {
    PolyTerm data;
    struct PolyNode* next;
} PolyNode;

typedef PolyNode* PolyLink;
typedef PolyLink LinkedPoly;


/*
 * ��2.41
 *
 * �����ʽ�ĵ�������
 */
Status Algo_2_41(LinkedPoly P);

/*
 * ��2.42
 *
 * ��ָ����ż�Բ�ֶ���ʽ��
 */
Status Algo_2_42(LinkedPoly* P, LinkedPoly* P_Odd, LinkedPoly* P_Even);

// ����ϡ�����ʽ
Status CreatPoly(LinkedPoly* P, PolyTerm Data[], int n);

// ���ϡ�����ʽ
void OutputPoly(LinkedPoly P);


int main(int argc, char* argv[]) {
    LinkedPoly P1, P2;
    PolyTerm a[7] = {{-2, 1}, {4, 2}, {2, 3}, {11, 5}, {-7, 6}, {8, 9}, {-3, 10}};
    
    // ׼����������
    CreatPoly(&P1, a, 7);
    CreatPoly(&P2, a, 7);
    printf("Pn(x) = ");
    OutputPoly(P1);
    printf("\n");
    
    printf("���������������� �� 2.41 ��֤...\n");
    {
        
        Algo_2_41(P1);
        printf("�� �����ʽ�ĵ�����֮��...\n");
        printf("�� Pn(x) = ");
        OutputPoly(P1);
        printf("\n");
    }
    
    printf("���������������� �� 2.42 ��֤...\n");
    {
        LinkedPoly P_odd, P_even;
        Algo_2_42(&P2, &P_odd, &P_even);
        printf("�� ��ָ����ż�Բ�ֶ���ʽ֮��...\n");
        printf("�� ����� P_odd  = ");
        OutputPoly(P_odd);
        printf("�� ż���� P_even = ");
        OutputPoly(P_even);
    }
    
    return 0;
}


// �����ʽ�ĵ�����
Status Algo_2_41(LinkedPoly P) {
    LinkedPoly r, pre;
    
    if(P == NULL || P->next == P) {
        return ERROR;
    }
    
    pre = P;
    r = P->next;
    
    while(r != P) {
        // ���ڲ�Ϊ0��ָ��
        if(r->data.exp != 0) {
            r->data.coef *= r->data.exp;    // ϵ����ָ�����
            r->data.exp--;                  // ָ����һ
            pre = r;
            
            // ָ��Ϊ0ʱ�������󵼺�Ϊ0����Ҫɾ����ǰ���
        } else {
            pre->next = r->next;
            free(r);
        }
        
        r = pre->next;
    }
    
    return OK;
}

// ��ָ����ż�Բ�ֶ���ʽ
Status Algo_2_42(LinkedPoly* P, LinkedPoly* P_Odd, LinkedPoly* P_Even) {
    LinkedPoly r, s, p, q;
    
    // ����ͷ���
    *P_Odd = (LinkedPoly) malloc(sizeof(PolyNode));
    *P_Even = (LinkedPoly) malloc(sizeof(PolyNode));
    if(*P_Odd == NULL || *P_Even == NULL) {
        exit(OVERFLOW);
    }
    (*P_Odd)->next = *P_Odd;
    (*P_Even)->next = *P_Even;
    
    if(P == NULL || *P == NULL) {
        return ERROR;
    }
    
    p = *P_Odd;
    q = *P_Even;
    r = (*P)->next;
    
    // ��������ʽ����������
    while(r != (*P)) {
        s = r;
        r = r->next;
        
        // ָ��Ϊ����
        if(s->data.exp % 2 != 0) {
            s->next = p->next;
            p->next = s;
            p = p->next;
    
            // ָ��Ϊż��
        } else {
            s->next = q->next;
            q->next = s;
            q = q->next;
        }
    }
    
    // ����ԭ���Ķ���ʽ
    free(*P);
    *P = NULL;
    
    return OK;
}

// ����ϡ�����ʽ
Status CreatPoly(LinkedPoly* P, PolyTerm Data[], int n) {
    int i;
    LinkedPoly s, r;
    
    // ����ͷ���
    *P = (LinkedPoly) malloc(sizeof(PolyNode));
    if(*P == NULL) {
        exit(OVERFLOW);
    }
    (*P)->next = *P;
    
    for(i = 0, r = *P; i < n; i++) {
        s = (LinkedPoly) malloc(sizeof(PolyNode));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->data = Data[i];
        
        // ���ӵ�����ʽ��
        s->next = r->next;
        r->next = s;
        
        r = r->next;
    }
    
    return OK;
}

// ���ϡ�����ʽ
void OutputPoly(LinkedPoly P) {
    LinkedPoly r;
    
    if(P == NULL || P->next == P) {
        return;
    }
    
    for(r = P->next; r != P; r = r->next) {
        if(r == P->next) {
            printf("%d", r->data.coef);
        } else {
            if(r->data.coef < 0) {
                printf(" - ");
                printf("%d", -r->data.coef);
            } else {
                printf(" + ");
                printf("%d", r->data.coef);
            }
        }
        
        if(r->data.exp) {
            printf("x");
            
            if(r->data.exp != 1) {
                printf("^%d", r->data.exp);
            }
        }
    }
    
    printf("\n");
}
