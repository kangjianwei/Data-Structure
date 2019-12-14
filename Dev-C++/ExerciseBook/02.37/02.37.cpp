#include <stdio.h>
#include "Status.h"         //**��01 ����**//
#include "DuLinkList.h"     //**��02 ���Ա�**//

/*
 * ��2.37
 *
 * ����ż�������������Ԫ��λ������λ��Ԫ�ؿ�ǰ����ż��λ��Ԫ�ؿ�������
 */
Status Algo_2_37(DuLinkList L);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    DuLinkList L;
    int i;
    
    // ׼����������
    InitList(&L);
    for(i = 1; i <= 10; i++) {
        ListInsert(L, i, i);
    }
    printf("����ǰ L = ");
    ListTraverse(L, PrintElem);
    
    Algo_2_37(L);
    
    printf("���ź� L = ");
    ListTraverse(L, PrintElem);
    
    return 0;
}


// ����ż�������������Ԫ��λ������λ��Ԫ�ؿ�ǰ����ż��λ��Ԫ�ؿ�������
Status Algo_2_37(DuLinkList L) {
    DuLinkList head, tail, p;
    
    if(L == NULL || L->prior == NULL || L->next == NULL) {
        return ERROR;
    }
    
    head = L->next;                // ָ����ף������ƽ�
    tail = L->prior;               // ָ���β���̶�����
    
    // ���head��tail�м����ٸ���һ��Ԫ��
    while(head != tail && head->next != tail) {
        // ָ��ԭż��λ���Ԫ��
        p = head->next;
        
        // ժ�´�ż��λ���Ԫ��
        p->next->prior = head;
        head->next = p->next;
        
        // ����Ԫ����ӵ�ԭtail����
        p->next = tail->next;
        p->prior = tail;
        tail->next->prior = p;
        tail->next = p;
        
        // ǰ������һ������λ���Ԫ����
        head = head->next;
    }
    
    return OK;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
