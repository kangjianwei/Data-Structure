#include <stdio.h>
#include "Status.h"    //**��01 ����**//
#include "SMatrix.h"    //**ϡ�����**//

/*
 * ��ȡ�����е�i�е�j�е�Ԫ�أ�������洢��e��
 */
Status Algo_5_24(SMatrix M, int i, int j, int* e);


int main(int argc, char* argv[]) {
    SMatrix M;
    int e;
    
    printf("�� ������ϡ����� M ...\n");
    CreateSMatrix(&M, "TestData_M.txt");
    printf("M = \n");
    PrintSMatrix(M);
    
    Algo_5_24(M, 2, 3, &e);
    printf("�� %d �� %d �е�Ԫ��Ϊ %d\n", 2, 3, e);
    
    return 0;
}


/*
 * ��ȡ�����е�i�е�j�е�Ԫ�أ�������洢��e��
 */
Status Algo_5_24(SMatrix M, int i, int j, int* e) {
    int s, p;
    
    if(i < 1 || i > M.mu || j < 1 || j > M.nu) {
        return ERROR;
    }
    
    for(p = 1, s = (i - 1) * M.nu + j; M.data[p].seq < s; p++) {
        // Ѱ��ָ����Ԫ��
    }
    
    *e = 0; // Ĭ��Ϊ0
    
    // �ҵ���Ӧ���±��Ԫ��
    if(M.data[p].seq == s) {
        *e = M.data[p].e;
    }
    
    return OK;
}
