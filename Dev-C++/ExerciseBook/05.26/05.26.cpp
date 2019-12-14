#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "CrossList.h"  //**��05 ����͹����**//

/*
 * ����Ԫ����ʽ���ʮ������
 */
Status Algo_5_26(CrossList M);


int main(int argc, char* argv[]) {
    CrossList M;
    
    printf("����ʮ������ M...\n");
    CreateSMatrix(&M, "TestData_M.txt");
    printf("M = \n");
    PrintSMatrix(M);
    
    printf("����Ԫ����ʽ��� M...\n");
    printf(" �� ��  ֵ\n");
    Algo_5_26(M);
    
    return 0;
}


/*
 * ����Ԫ����ʽ���ʮ������
 */
Status Algo_5_26(CrossList M) {
    int i, j;
    OLNode* p;
    
    if(M.tu==0) {
        return ERROR;
    }
    
    for(i = 1; i <= M.mu; ++i) {
        p = M.rhead[i];
        for(j = 1; j <= M.nu; ++j) {
            if(p && p->j == j) {
                printf("(%2d %2d %3d)\n", i, j, p->e);
                p = p->right;
            }
        }
    }
    
    return OK;
}
