#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <string.h>
#include "Status.h"     //**��01 ����**//

// ���ָ������Ԫ��
typedef char XElemType;

// ���ָ��������ṹ
typedef struct XorNode {
    XElemType data;
    struct XorNode* LRPtr;
} XorNode;
typedef XorNode* XorPointer;

// ��ͷ�������ָ��˫�������ͷβָ��
typedef struct {
    XorPointer Left;    // �ֱ�ָ�����������ˣ�ͷָ�룩�����Ҷˣ�βָ�룩
    XorPointer Right;
} XorLinkedList;


/*
 * ��2.34��������һ������PriorOrNext������������
 *
 * ���L��mark��ʾ�������0���������������1�������������
 */
void Algo_2_34_1(XorLinkedList L, int mark);

/*
 * ��2.34����������������������PriorOrNext������������
 *
 * ���L��mark��ʾ�������0���������������1�������������
 */
void Algo_2_34_2(XorLinkedList L, int mark);

/*
 * ��2.35
 *
 * ��Ԫ��e���뵽��i�����֮ǰ
 */
Status Algo_2_35(XorLinkedList* L, int i, XElemType e);

/*
 * ��2.36
 *
 * ɾ����i(>0)����㣬����e���ܽ����Ԫ��ֵ
 */
Status Algo_2_36(XorLinkedList* L, int i, char* e);

// ָ�������������ָ��p��q�����ֵ��������㣺p^q��
XorPointer XorP(XorPointer p, XorPointer q);

// �������ָ������L
Status Create(XorLinkedList* L, XElemType elems[], int n);

// ��ȡ��ǰ���(cur)��ǰ��(mark=0)����(mark=1)
XorPointer PriorOrNext(XorLinkedList L, XorPointer cur, int mark);


int main(int argc, char** argv) {
    XorLinkedList L;
    XElemType e;
    XElemType* data = "123456789";
    
    Create(&L, data, strlen(data));
    printf("���������������� �� 2.34 ��֤...\n");
    printf("�� ������� L = ");
    Algo_2_34_1(L, 0);
    printf("�� ������� L = ");
    Algo_2_34_1(L, 1);
    
    printf("���������������� �� 2.35 ��֤...\n");
    Algo_2_35(&L, 5, '*');
    printf("�� ���� '*' ΪL�ĵ�5������˳�����...\n");
    printf("�� ������� L = ");
    Algo_2_34_2(L, 0);
    
    printf("���������������� �� 2.36 ��֤...\n");
    Algo_2_36(&L, 5, &e);
    printf("�� ɾ��L�ĵ�5����� '%c' ���������...\n", e);
    printf("�� ������� L = ");
    Algo_2_34_2(L, 1);
    
    return 0;
}


// ������㣺p^q
XorPointer XorP(XorPointer p, XorPointer q) {
    unsigned long x, y, z;
    
    x = (unsigned long) p;
    y = (unsigned long) q;
    
    // �����
    z = x ^ y;
    
    return (XorPointer) z;
}

// �������ָ������L
Status Create(XorLinkedList* L, XElemType elems[], int n) {
    int i;
    XorPointer pre_l, pre_m, pre_r; // ׼������ָ�룬ָ�������н��ڵ��������
    
    (*L).Left = NULL;
    (*L).Right = NULL;
    
    pre_l = pre_m = NULL;
    
    for(i = 0; i < n; i++) {
        pre_r = (XorPointer) malloc(sizeof(XorNode));
        if(pre_r == NULL) {
            exit(OVERFLOW);
        }
        pre_r->data = elems[i];
        
        // ��ָ�루�����׽��ʱ������
        if(i == 0) {
            L->Left = pre_r;
        }
        
        // ��ָ�룬ָ�����һ�����
        L->Right = pre_r;
        
        // ���½�����ʱ����һ������ָ������Ҫ�����޸�
        if(pre_m != NULL) {
            pre_m->LRPtr = XorP(pre_l, pre_r);
        }
        
        pre_r->LRPtr = XorP(pre_m, NULL);
        pre_l = pre_m;
        pre_m = pre_r;
    }
    
    return OK;
}

// ��ȡ��ǰ���(cur)��ǰ��(mark=0)����(mark=1)
XorPointer PriorOrNext(XorLinkedList L, XorPointer cur, int mark) {
    XorPointer p_l, p_m, p_r;
    
    if(mark != 1 && mark != 0) {
        return NULL;
    }
    
    // ȷ���������
    if(L.Left == NULL || L.Right == NULL || cur == NULL) {
        return NULL;
    }
    
    // ���̣���������
    if(mark == 1) {
        p_l = NULL;
        p_m = L.Left;
        
        // ָ�벻�������ƽ�
        while(p_m != cur) {
            p_r = XorP(p_l, p_m->LRPtr);    //�����Ҳ��һ������ַ
            p_l = p_m;
            p_m = p_r;
        }
        
        // p_mָ��cur��ǰ��
        p_r = XorP(p_l, p_m->LRPtr);
        
        return p_r;
        
        // ��ǰ������������
    } else {
        p_m = L.Right;
        p_r = NULL;
        
        // ָ�벻�������ƽ�
        while(p_m != cur) {
            p_l = XorP(p_m->LRPtr, p_r);    //��������һ������ַ
            p_r = p_m;
            p_m = p_l;
        }
        
        // p_mָ��cur�ĺ��
        p_l = XorP(p_m->LRPtr, p_r);
        
        return p_l;
    }
}

// ���L��mark��ʾ�������0���������������1�������������
void Algo_2_34_1(XorLinkedList L, int mark) {
    XorPointer cur;
    
    if(mark != 1 && mark != 0) {
        return;
    }
    
    // ȷ���������
    if(L.Left == NULL || L.Right == NULL) {
        return;
    }
    
    // �����������
    if(mark == 0) {
        cur = L.Left;
        do {
            printf("%c ", cur->data);
            // ��ȡcur�ĺ��
            cur = PriorOrNext(L, cur, 1);
        } while(cur != NULL);
        
        // �����������
    } else {
        cur = L.Right;
        do {
            printf("%c ", cur->data);
            // ��ȡcur��ǰ��
            cur = PriorOrNext(L, cur, 0);
        } while(cur != NULL);
    }
    
    printf("\n");
}

// ���L��mark��ʾ�������0���������������1�������������
void Algo_2_34_2(XorLinkedList L, int mark) {
    XorPointer p_l, p_m, p_r;
    
    if(mark != 1 && mark != 0) {
        return;
    }
    
    // ȷ���������
    if(L.Left == NULL || L.Right == NULL) {
        return;
    }
    
    // �����������
    if(mark == 0) {
        p_l = NULL;
        p_m = L.Left;
        
        // p_mΪ��ʱ˵����������
        while(p_m != NULL) {
            printf("%c ", p_m->data);
            p_r = XorP(p_l, p_m->LRPtr);    // �����Ҳ��һ������ַ
            p_l = p_m;                      // ָ�벻������ƽ�
            p_m = p_r;
        }
        
        // �����������
    } else {
        p_m = L.Right;
        p_r = NULL;
        
        // p_mΪ��ʱ˵����������
        while(p_m != NULL) {
            printf("%c ", p_m->data);
            p_l = XorP(p_m->LRPtr, p_r);    // ��������һ������ַ
            p_r = p_m;                      // ָ�벻����ǰ�ƽ�
            p_m = p_l;
        }
    }
    
    printf("\n");
}

// ��Ԫ��e���뵽��i�����֮ǰ
Status Algo_2_35(XorLinkedList* L, int i, XElemType e) {
    XorPointer pl;  // ָ���i-2�����
    XorPointer pre; // ָ���i-1�����
    XorPointer p;   // ָ���i�����
    XorPointer pr;  // ָ���i+1�����
    XorPointer s;
    int j;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // i>=1
    if(i < 1) {
        return ERROR;
    }
    
    // �����½��
    s = (XorPointer) malloc(sizeof(XorNode));
    if(s == NULL) {
        exit(OVERFLOW);
    }
    s->data = e;
    
    // �ȴ�������Ϊ�յ�����
    if((*L).Left == NULL && (*L).Right == NULL) {
        if(i != 1) {
            return ERROR;   // ����Ϊ��ʱ��iֻ��Ϊ1
        }
        
        (*L).Left = (*L).Right = s;
        s->LRPtr = NULL;
        
        return OK;
    }
    
    j = 0;
    pre = NULL;
    p = (*L).Left;
    
    // ���ҵ�i-1����㣬����preָ����
    while(j < i - 1 && p != NULL) {
        j++;
        pr = XorP(pre, p->LRPtr);
        pre = p;
        p = pr;
    }
    
    // iֵ���Ϲ棨����
    if(j < i - 1) {
        return ERROR;
    }
    
    // ��Ҫ���뵽����β��
    if(p == NULL) {
        pl = XorP(pre->LRPtr, p);
        pre->LRPtr = XorP(pl, s);
        
        s->LRPtr = XorP(pre, p);
        
        (*L).Right = s;
        
        return OK;
    }
    
    // ��Ҫ���뵽�����ͷ��
    if(pre == NULL) {
        pr = XorP(pre, p->LRPtr);
        p->LRPtr = XorP(s, pr);
        
        s->LRPtr = XorP(pre, p);
        
        (*L).Left = s;
        
        return OK;
    }
    
    // ��������
    pl = XorP(pre->LRPtr, p);
    pr = XorP(pre, p->LRPtr);
    pre->LRPtr = XorP(pl, s);
    p->LRPtr = XorP(s, pr);
    s->LRPtr = XorP(pre, p);
    
    return OK;
}

// ɾ����i(>0)����㣬����e���ܽ����Ԫ��ֵ
Status Algo_2_36(XorLinkedList* L, int i, XElemType* e) {
    XorPointer pl;  // ָ���i-2�����
    XorPointer pre; // ָ���i-1�����
    XorPointer p;   // ָ���i�����
    XorPointer pr;  // ָ���i+1�����
    XorPointer prr; // ָ���i+2�����
    int j;
    
    if(L == NULL || (*L).Left == NULL || (*L).Right == NULL) {
        return ERROR;
    }
    
    // i>=1
    if(i < 1) {
        return ERROR;
    }
    
    // �ȴ���ֻ��һ����������
    if((*L).Left == (*L).Right) {
        if(i != 1) {
            return ERROR;   // ����ֻ��һ�����ʱ��iֻ��Ϊ1
        }
        
        *e = (*L).Left->data;
        (*L).Left = (*L).Right = NULL;
        
        return OK;
    }
    
    j = 0;
    pre = NULL;
    p = (*L).Left;
    
    // ���ҵ�i-1����㣬����preָ����
    while(j < i - 1 && p != NULL) {
        j++;
        pr = XorP(pre, p->LRPtr);
        pre = p;
        p = pr;
    }
    
    // iֵ���Ϲ棨����
    if(j < i - 1 || p == NULL) {
        return ERROR;
    }
    
    // �洢��ɾԪ�ص�ֵ
    *e = p->data;
    
    /* ���ˣ�����������Ԫ�ش��ڣ���pָ��ɾ��Ԫ�� */
    
    pr = XorP(pre, p->LRPtr);
    
    // ɾ��ͷ���
    if(pre == NULL) {
        // ���ڴ�ʱ������������㣬��pr!=NULL
        prr = XorP(p, pr->LRPtr);
        
        pr->LRPtr = XorP(pre, prr);
    
        (*L).Left = pr;
    } else {
        pl = XorP(pre->LRPtr, p);
        pre->LRPtr = XorP(pl, pr);
    
        // ɾ�����һ�����
        if(pr==NULL) {
            (*L).Right = pre;
        } else {
            prr = XorP(p, pr->LRPtr);
            pr->LRPtr = XorP(pre, prr);
        }
    }
    
    free(p);
    
    return OK;
}
