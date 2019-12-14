#include <stdio.h>
#include "Status.h"      //**��01 ����**//
#include "LinkList.h"    //**��02 ���Ա�**//

/*
 * ��2.26
 *
 * �󽻼���C=A��B��
 */
Status Algo_2_26(LinkList La, LinkList Lb, LinkList* Lc);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    LinkList La, Lb, Lc;
    int i;
    
    int a[10] = {1, 2, 2, 3, 4, 4, 9, 9, 10, 12};
    int b[10] = {1, 1, 2, 2, 3, 3, 4, 5, 12, 13};
    
    // ׼����������
    InitList(&La);
    InitList(&Lb);
    for(i = 1; i <= 10; i++) {
        ListInsert(La, i, a[i - 1]);
        ListInsert(Lb, i, b[i - 1]);
    }
    printf("La = ");
    ListTraverse(La, PrintElem);
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    // �󽻼�
    Algo_2_26(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}

// �󽻼���C=A��B
Status Algo_2_26(LinkList La, LinkList Lb, LinkList* Lc) {
    LinkList pa, pb, pc, s;
    
    // ȷ��La��Lb����
    if(La == NULL || Lb == NULL) {
        return ERROR;
    }
    
    InitList(Lc);
    
    pa = La->next;
    pb = Lb->next;
    pc = *Lc;
    
    // ֻ����La��Lb�Ĺ�ͬ���־���
    while(pa != NULL && pb != NULL) {
        if(pa->data < pb->data) {
            pa = pa->next;
        } else if(pa->data > pb->data) {
            pb = pb->next;
        } else {
            // Lc��Ԫ�ؿ����ظ�
            s = (LinkList) malloc(sizeof(LNode));
            if(s == NULL) {
                exit(OVERFLOW);
            }
            s->data = pa->data;
            s->next = NULL;
            
            pc->next = s;
            
            pc = pc->next;
            
            pa = pa->next;
            pb = pb->next;
        }
    }
    
    return OK;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
