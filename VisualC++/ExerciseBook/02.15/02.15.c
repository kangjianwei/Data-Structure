#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "LinkList.h"   //**��02 ���Ա�**//

/*
 * ��2.15
 *
 * ����ha��hb���洢��hc�С�
 */
Status Algo_2_15(LinkList* ha, LinkList* hb, LinkList* hc);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList ha, hb, hc = NULL;
    int i;
    
    // ��ʼ��
    InitList(&ha);
    InitList(&hb);
    
    // ��ֵ
    for(i = 1; i <= 5; i++) {
        ListInsert(ha, i, 2 * i - 1);
        ListInsert(hb, i, 2 * i);
    }
    
    printf("ha = ");
    ListTraverse(ha, PrintElem);
    
    printf("hb = ");
    ListTraverse(hb, PrintElem);
    
    // ����ha��hb
    Algo_2_15(&ha, &hb, &hc);
    
    printf("hc = ");
    ListTraverse(hc, PrintElem);
    
    return 0;
}


// ����ha��hb���洢��hc��
Status Algo_2_15(LinkList* ha, LinkList* hb, LinkList* hc) {
    LinkList pa, pb;
    
    *hc = NULL;
    
    // ȷ��ha��hb������
    if(ha == NULL || *ha == NULL || hb == NULL || *hb == NULL) {
        return ERROR;
    }
    
    pa = *ha;
    pb = *hb;
    
    // Ϊ�����Ч�ʣ���Ҫ�ȱ�����ͬ�Ĳ���
    while(pa->next != NULL && pb->next != NULL) {
        pa = pa->next;
        pb = pb->next;
    }
    
    // ���ha�Ѿ�������ͷ�ˣ���hb��ʣ��
    if(pa->next == NULL && pb->next != NULL) {
        *hc = *ha;
        pa->next = (*hb)->next;
        free(*hb);
    }
    
    // ���hb�Ѿ�������ͷ�ˣ�ha������ʣ�࣬Ҳ����û��
    if(pb->next == NULL) {
        *hc = *hb;
        pb->next = (*ha)->next;
        free(*ha);
    }
    
    // ������ha/hb��ͷ���
    *ha = NULL;
    *hb = NULL;
    
    return OK;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
