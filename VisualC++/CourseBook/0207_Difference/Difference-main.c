#include <stdio.h>
#include "Difference.h"                    //**��02 ���Ա�**//

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SLinkList space;    // ���ÿռ�
    int S;              // ��̬����
    
    // S = (A-B)��(B-A)
    difference(space, &S, "TestData.txt");
    
    printf("S = (A-B)��(B-A) = ");
    ListTraverse(space, S, PrintElem);
    
    return 0;
}
