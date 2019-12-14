#include <stdio.h>
#include "Status.h"      //**��01 ����**//
#include "LinkList.h"    //**��02 ���Ա�**//

/*
 * ��2.24
 *
 * �鲢��������������Ϊһ���ݼ�������
 * �鲢�����ǣ����ժ��La��Lb�е�Ԫ�أ���ʹ��ͷ�巨���뵽Lc��
 * �鲢��ɺ󣬽�ԭ���ÿգ��������١�
 */
Status Algo_2_24(LinkList La, LinkList Lb, LinkList* Lc);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;
    
    // ׼����������
    InitList(&La);
    InitList(&Lb);
    for(i = 1; i <= 5; i++) {
        ListInsert(La, i, 2 * i - 1);
        ListInsert(Lb, i, 2 * i);
    }
    printf("La = ");
    ListTraverse(La, PrintElem);
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    // �鲢��������
    Algo_2_24(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}


// �鲢��������������Ϊһ���ݼ�������
Status Algo_2_24(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList pa, pb;
    
    // ȷ��La��Lb����
    if(La == NULL || Lb == NULL || Lc == NULL) {
        return ERROR;
    }
    
    InitList(Lc);
    
    // ����La��Lb
    while(La->next!=NULL && Lb->next!=NULL){
        pa = La->next;
        pb = Lb->next;
    
        // ժ��La��Lb�н�С��Ԫ��
        if(pa->data<=pb->data) {
            La->next = pa->next;
            pa->next = (*Lc)->next;
            (*Lc)->next = pa;
        } else {
            Lb->next = pb->next;
            pb->next = (*Lc)->next;
            (*Lc)->next = pb;
        }
    }
    
    // ���La����ʣ�࣬��La��ʣ��Ԫ�ز��뵽Lc��
    while(La->next!=NULL){
        pa = La->next;
        La->next = pa->next;
        pa->next = (*Lc)->next;
        (*Lc)->next = pa;
    }
    
    // ���Lb����ʣ�࣬��Lb��ʣ��Ԫ�ز��뵽Lc��
    while(Lb->next!=NULL){
        pb = Lb->next;
        Lb->next = pb->next;
        pb->next = (*Lc)->next;
        (*Lc)->next = pb;
    }

    return OK;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
