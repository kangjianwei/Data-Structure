#include <stdio.h>
#include <stdlib.h>     //�ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "LinkList.h"   //**��02 ���Ա�**//

/*
 * ��2.19����������һ
 *
 * ɾ���������Ա���Ԫ��ֵ����(mink, maxk)֮��Ľ�㡣
 */
Status Algo_2_19_1(LinkList L, int mink, int maxk);

/*
 * ��2.19������������
 *
 * ɾ���������Ա���Ԫ��ֵ����(mink, maxk)֮��Ľ�㡣
 */
Status Algo_2_19_2(LinkList L, int mink, int maxk);

/*
 * ��2.20
 *
 * �Էǵݼ����Ա�ȥ�أ������ظ�Ԫ�أ�������һ����
 */
Status Algo_2_20(LinkList L);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList L;
    int mink1, mink2, maxk1, maxk2, i;
    int a[] = {1, 2, 2, 3, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 12, 12};
    
    mink1 = 2;
    maxk1 = 4;
    
    mink2 = 5;
    maxk2 = 8;
    
    InitList(&L);
    
    for(i = 1; i <= 20; i++) {
        ListInsert(L, i, a[i - 1]);
    }
    
    printf("�� L = ");
    ListTraverse(L, PrintElem);
    
    printf("���������������� �� 2.19 ��֤...\n");
    printf("�� ɾ�� (%d, %d) ��Χ�ڵ�Ԫ��֮��", mink1, maxk1);
    Algo_2_19_1(L, mink1, maxk1);
    printf("L = ");
    ListTraverse(L, PrintElem);
    
    printf("�� ɾ�� (%d, %d) ��Χ�ڵ�Ԫ��֮��", mink2, maxk2);
    Algo_2_19_2(L, mink2, maxk2);
    printf("L = ");
    ListTraverse(L, PrintElem);
    
    printf("���������������� �� 2.20 ��֤...\n");
    printf("�� �Էǵݼ�����ȥ��֮��");
    Algo_2_20(L);
    printf("L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}


// ɾ���������Ա���Ԫ��ֵ����(mink, maxk)֮��Ľ��
Status Algo_2_19_1(LinkList L, int mink, int maxk) {
    LinkList p, q;
    int flag;   // �������Ч��
    
    // ȷ���������
    if(L == NULL) {
        return ERROR;
    }
    
    // ��Χ�趨����
    if(mink >= maxk) {
        return ERROR;
    }
    
    // ����Ϊ�գ�ֱ�ӷ���
    if(L->next == NULL) {
        return OK;
    }
    
    p = L;      // ָ��ͷ���
    flag = 0;   // ���δ����(mink, maxk)��Χ�ڵ�Ԫ��
    
    while(p->next != NULL) {
        q = p->next;
        
        // ������Ҫɾ���Ľ��
        if(q->data > mink && q->data < maxk) {
            // ���������(mink, maxk)��Χ�ڵ�Ԫ��
            flag = 1;
            p->next = q->next;
            free(q);
        } else {
            // ˵��ʣ��Ԫ�ؾ�>=maxk�������ٱ���
            if(flag == 1) {
                break;
            }
            p = q;
        }
    }
    
    return OK;
}

// ɾ���������Ա���Ԫ��ֵ����(mink, maxk)֮��Ľ��
Status Algo_2_19_2(LinkList L, int mink, int maxk) {
    LinkList p, q;
    
    // ȷ���������
    if(L == NULL) {
        return ERROR;
    }
    
    // ��Χ�趨����
    if(mink >= maxk) {
        return ERROR;
    }
    
    // ����Ϊ�գ�ֱ�ӷ���
    if(L->next == NULL) {
        return OK;
    }
    
    p = L;      // ָ��ͷ���
    
    // ��������
    while(p->next != NULL && p->next->data <= mink) {
        p = p->next;
    }
    
    // �������
    if(p->next == NULL) {
        return OK;
    }
    
    // �������ޣ�ɾ��(mink, maxk)֮��Ĳ���
    while(p->next != NULL && p->next->data < maxk) {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    
    return OK;
}

// �Էǵݼ����Ա�ȥ�أ������ظ�Ԫ�أ�������һ��
Status Algo_2_20(LinkList L) {
    LinkList p, q;
    
    // ȷ���������
    if(L == NULL) {
        return ERROR;
    }
    
    // ����Ϊ�գ�ֱ�ӷ���
    if(L->next == NULL) {
        return OK;
    }
    
    // ָ���1��Ԫ��
    p = L->next;
    
    while(p->next != NULL) {
        q = p->next;
        
        // �������ظ�Ԫ�أ�����Ҫɾ��һ��
        if(p->data == q->data) {
            p->next = q->next;
            free(q);
            
            // ����ǲ�ͬ��Ԫ�أ���pǰ��һ��
        } else {
            p = q;
        }
    }
    
    return OK;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
