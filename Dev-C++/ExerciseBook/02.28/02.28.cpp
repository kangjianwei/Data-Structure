#include <stdio.h>
#include "LinkList.h"    //**��02 ���Ա�**//

/*
 * ��2.28
 *
 * �󽻼���C=A��B��
 * ������C�е�Ԫ���ظ�����C������Aԭ�еĿռ䣬A�����١�
 */
LinkList Algo_2_28(LinkList* La, LinkList Lb);

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
    Lc = Algo_2_28(&La, Lb);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}


LinkList Algo_2_28(LinkList* La, LinkList Lb) {
    LinkList Lc;
    LinkList pa, pb, pc, s;
    
    // ȷ��La��Lb����
    if(La == NULL || *La == NULL || Lb == NULL) {
        return NULL;
    }
    
    pa = (*La)->next;
    pb = Lb->next;
    
    Lc = *La;
    Lc->next = NULL;
    pc = Lc;
    
    // ֻ����La��Lb�Ĺ�ͬ���־���
    while(pa != NULL && pb != NULL) {
        if(pa->data < pb->data) {
            s = pa;
            pa = pa->next;
            free(s);
        } else if(pa->data > pb->data) {
            pb = pb->next;
        } else {
            // ȷ��Lc�е�Ԫ�ز��ظ�
            if(pc == Lc || pc->data != pa->data) {
                pc->next = pa;
                pc = pc->next;
            }
            
            pa = pa->next;
            pb = pb->next;
        }
    }
    
    pc->next = NULL;
    
    
    *La = NULL;
    
    return Lc;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
