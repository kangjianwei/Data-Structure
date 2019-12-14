#include <stdio.h>
#include "SqList.h"    //**��02 ���Ա�**//

/*
 * ��2.27
 *
 * �󽻼���C=A��B��
 * ������C�е�Ԫ���ظ�����C������Aԭ�еĿռ䣬A�����١�
 */
SqList Algo_2_27(SqList* La, SqList Lb);

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
    Lc = Algo_2_27(&La, Lb);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}

// �󽻼���C=A��B
SqList Algo_2_27(SqList* La, SqList Lb) {
    int i, j, k;
    SqList Lc;
    
    // ȷ��La��Lb����
    if((*La).elem == NULL || Lb.elem == NULL) {
        Lc.elem = NULL;
        Lc.length = 0;
        Lc.listsize = 0;
        return Lc;
    }
    
    i = j = 0;  // ����La��Lb
    k = 0;      // ����Lc
    
    Lc.elem = (*La).elem;
    Lc.listsize = La->listsize;
    
    // ֻ����La��Lb�Ĺ�ͬ���־���
    while(i < (*La).length && j < Lb.length) {
        if((*La).elem[i] < Lb.elem[j]) {
            i++;
        } else if((*La).elem[i] > Lb.elem[j]) {
            j++;
            // ���La��Lb�е�Ԫ�����
        } else {
            // ȷ��Lc�е�Ԫ�ز��ظ�
            if(k == 0 || Lc.elem[k - 1] != (*La).elem[i]) {
                Lc.elem[k] = (*La).elem[i];
                k++;
            }
            
            i++;
            j++;
        }
    }
    
    // ����A������ռ佻����Cʹ��
    (*La).elem = NULL;
    (*La).length = 0;
    (*La).listsize = 0;
    
    Lc.length = k;
    
    return Lc;
}

void PrintElem(ElemType e) {
    printf("%d ", e);
}
