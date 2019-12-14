#include <stdio.h>
#include "Status.h"    //**��01 ����**//
#include "SqList.h"    //**��02 ���Ա�**//

/*
 * ��2.25
 *
 * �󽻼���C=A��B��
 */
Status Algo_2_25(SqList La, SqList Lb, SqList* Lc);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    SqList La, Lb, Lc;
    int i;
    
    int a[10] = {1, 2, 2, 3, 4, 4, 9, 9, 10, 12};
    int b[10] = {1, 1, 2, 2, 3, 3, 4, 5, 12, 13};
    
    // ׼����������
    InitList(&La);
    InitList(&Lb);
    for(i = 1; i <= 10; i++) {
        ListInsert(&La, i, a[i - 1]);
        ListInsert(&Lb, i, b[i - 1]);
    }
    
    printf("La = ");
    ListTraverse(La, PrintElem);
    
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    // �󽻼�
    Algo_2_25(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}

// �󽻼���C=A��B
Status Algo_2_25(SqList La, SqList Lb, SqList* Lc) {
    int i, j, k;
    
    // ȷ��La��Lb����
    if(La.elem == NULL || Lb.elem == NULL) {
        return ERROR;
    }
    
    InitList(Lc);
    
    i = j = 0;  // ����La��Lb
    k = 0;      // ����Lc
    
    // ֻ����La��Lb�Ĺ�ͬ���־���
    while(i < La.length && j < Lb.length) {
        if(La.elem[i] < Lb.elem[j]) {
            i++;
        } else if(La.elem[i] > Lb.elem[j]) {
            j++;
            // ���La��Lb�е�Ԫ�����
        } else {
            // Lc��Ԫ�ؿ����ظ�
            ListInsert(Lc, k+1, La.elem[i]);
            k++;
            i++;
            j++;
        }
    }
    
    return OK;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}
