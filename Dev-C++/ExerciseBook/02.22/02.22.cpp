#include <stdio.h>
#include "Status.h"         //**��01 ����**//
#include "LinkList.h"       //**��02 ���Ա�**//

/*
 * ��2.22
 *
 * �������á�
 */
Status Algo_2_22(LinkList L);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);

int main(int argc, char* argv[]) {
    LinkList L;
    int i;
    
    // ׼����������
    InitList(&L);
    for(i = 1; i <= 10; i++) {
        ListInsert(L, i, i);
    }
    
    printf("˳��L = ");
    ListTraverse(L, PrintElem);
    
    Algo_2_22(L);
    
    printf("���ã�L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}

// ��������
Status Algo_2_22(LinkList L) {
    LinkList p, q;
    
    // ȷ���������
    if(L==NULL) {
        return ERROR;
    }
    
    p = L->next;
    L->next = NULL;
    
    // ͷ�巨
    while(p!=NULL){
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    
    return OK;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%2d ", e);
}
