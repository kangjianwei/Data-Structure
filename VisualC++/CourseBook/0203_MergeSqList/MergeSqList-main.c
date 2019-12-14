#include <stdio.h>
#include "SqList.h"
#include "MergeSqList.h"                //**��02 ���Ա�**//

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    ElemType a[4] = {3, 5, 8, 11};
    ElemType b[7] = {2, 6, 8, 9, 11, 15, 20};
    
    SqList La, Lb, Lc1, Lc2;
    int i;
    
    // ��ʼ��La
    InitList(&La);
    for(i = 1; i <= 4; i++) {
        ListInsert(&La, i, a[i - 1]);
    }
    
    // ��ʼ��Lb
    InitList(&Lb);
    for(i = 1; i <= 7; i++) {
        ListInsert(&Lb, i, b[i - 1]);
    }
    
    // ���La
    printf("La = ");
    ListTraverse(La, PrintElem);
    
    // ���Lb
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    // �鲢˳���La��Lb���㷨2.2
    MergeSqList_1(La, Lb, &Lc1);
    printf("�鲢La��LbΪLc1 = ");
    ListTraverse(Lc1, PrintElem);
    
    // �鲢˳���La��Lb���㷨2.7
    MergeSqList_2(La, Lb, &Lc2);
    printf("�鲢La��LbΪLc2 = ");
    ListTraverse(Lc2, PrintElem);
    
    return 0;
}
