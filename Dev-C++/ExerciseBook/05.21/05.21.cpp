#include <stdio.h>
#include "Status.h"    //**��01 ����**//
#include "TSMatrix.h"  //**��05 ����͹����**//

/*
 * ϡ�����ӷ���AddSMatrix
 *
 *��ע��
 * �ú�������TSMatrix����ļ��ж���
 */
Status Algo_5_21(TSMatrix A, TSMatrix B, TSMatrix* C);


int main(int argc, char* argv[]) {
    TSMatrix A, B, C;
    
    printf("�� ��������ϡ����� A��B ...\n");
    CreateSMatrix(&A, "TestData_A.txt");
    CreateSMatrix(&B, "TestData_B.txt");
    printf("�� A = \n");
    PrintSMatrix(A);
    printf("�� B = \n");
    PrintSMatrix(B);
    
    // �������
    Algo_5_21(A, B, &C);
    
    printf("�� C = A + B = \n");
    PrintSMatrix(C);
    
    return 0;
}


/*
 * ϡ�����ӷ���AddSMatrix
 *
 *��ע��
 * �ú�������TSMatrix����ļ��ж���
 */
Status Algo_5_21(TSMatrix A, TSMatrix B, TSMatrix* C) {
    return AddSMatrix(A, B, C);
}
