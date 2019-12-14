#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "CrossList.h"  //**��05 ����͹����**//

/*
 * ϡ�����ӷ���AddSMatrix
 *
 *��ע��
 * �ú�������CrossList����ļ��ж���
 */
Status Algo_5_27(CrossList M, CrossList N, CrossList* Q);


int main(int argc, char* argv[]) {
    CrossList M, N, Q;
    
    printf("�� ��������ϡ����� M��N ...\n");
    CreateSMatrix(&M, "TestData_M.txt");
    CreateSMatrix(&N, "TestData_N.txt");
    printf("�� M = \n");
    PrintSMatrix(M);
    printf("�� N = \n");
    PrintSMatrix(N);
    
    Algo_5_27(M, N, &Q);
    printf("�� Q = M + N = \n");
    PrintSMatrix(Q);
    
    return 0;
}


/*
 * ϡ�����ӷ���AddSMatrix
 *
 *��ע��
 * �ú�������CrossList����ļ��ж���
 */
Status Algo_5_27(CrossList M, CrossList N, CrossList* Q) {
    return AddSMatrix(M, N, Q);
}
