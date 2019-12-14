#include <stdio.h>
#include "MergeList.h"                    //**��02 ���Ա�**//

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    LinkList La, Lb, Lc;
    
    int n = 5;
    
    printf("��Ϊʾ����La�����趨Ϊ %d ��Lb�����趨Ϊ %d ������La��Lb...\n", n, n);
    
    CreateList_Head(&La, n, "TestData_Head.txt");
    printf("La = ");
    ListTraverse(La, PrintElem);
    
    CreateList_Tail(&Lb, n, "TestData_Tail.txt");
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    printf("�鲢La��LbΪLc = ");
    MergeList(&La, &Lb, &Lc);
    ListTraverse(Lc, PrintElem);
    
    return 0;
}

