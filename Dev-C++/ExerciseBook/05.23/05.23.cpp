#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "RLSMatrix.h"  //**��05 ����͹����**//

/*
 * ��ȡ�����е�i�е�j�е�Ԫ�أ�������洢��e��
 */
Status Algo_5_23(RLSMatrix M, int i, int j, int* e);


int main(int argc, char* argv[]) {
    RLSMatrix M;
    int e;
    
    printf("�� ������ϡ����� M ...\n");
    CreateSMatrix(&M, "TestData_M.txt");
    printf("M = \n");
    PrintSMatrix(M);
    
    Algo_5_23(M, 2, 3, &e);
    printf("�� �� %d �� %d �е�Ԫ��Ϊ %d\n", 2, 3, e);
    
    return 0;
}


/*
 * ��ȡ�����е�i�е�j�е�Ԫ�أ�������洢��e��
 */
Status Algo_5_23(RLSMatrix M, int i, int j, int* e) {
    int begin, end, k;
    
    if(i < 1 || i > M.mu || j < 1 || j > M.nu) {
        return ERROR;
    }
    
    // ��ȡ��i�����׸�����Ԫ����Ԫ����е�λ��
    begin = M.rpos[i];
    end = (i == M.mu ? M.tu : M.rpos[i + 1] - 1);
    
    *e = 0; // Ĭ��Ϊ0
    
    for(k = begin; k <= end; k++) {
        // �ҵ���Ӧ���±��Ԫ��
        if(M.data[k].j == j) {
            *e = M.data[k].e;
            break;
        }
    }
    
    return OK;
}
