#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "SMatrix.h"    //**ϡ�����**//

/*
 * ϡ�����ӷ���AddSMatrix
 */
Status Algo_5_25(SMatrix P, SMatrix Q, SMatrix* R);


int main(int argc, char* argv[]) {
    SMatrix M, N, Q;
    
    printf("�� ��������ϡ����� M��N ...\n");
    CreateSMatrix(&M, "TestData_M.txt");
    CreateSMatrix(&N, "TestData_N.txt");
    printf("�� M = \n");
    PrintSMatrix(M);
    printf("�� N = \n");
    PrintSMatrix(N);
    
    Algo_5_25(M, N, &Q);
    printf("Q = M + N = \n");
    PrintSMatrix(Q);
    
    return 0;
}


/*
 * ϡ�����ӷ���AddSMatrix
 */
Status Algo_5_25(SMatrix P, SMatrix Q, SMatrix* R) {
    int i, j;
    int p, q, r;
    
    if(P.mu != Q.mu || P.nu != Q.nu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // ��ʼ��R����Ϣ
    (*R).mu = P.mu;
    (*R).nu = P.nu;
    (*R).tu = 0;
    memset((*R).V, 0, sizeof((*R).V));
    memset((*R).B, 0, sizeof((*R).B));
    
    // ָ��P��Q��R�е�����V
    p = q = r = 0;
    
    for(i = 0; i < P.mu; ++i) {
        for(j = 0; j < P.nu; ++j) {
            if(P.B[i][j] == 0 && Q.B[i][j] == 0) {
                continue;
            } else if(P.B[i][j] == 0 && Q.B[i][j] == 1) {
                (*R).V[r++] = Q.V[q++];
                (*R).B[i][j] = 1;
            } else if(P.B[i][j] == 1 && Q.B[i][j] == 0) {
                (*R).V[r++] = P.V[p++];
                (*R).B[i][j] = 1;
                
                // ���P��Q�������з���Ԫ���������
            } else {
                if((P.V[p] + Q.V[q])!=0) {
                    (*R).V[r++] = P.V[p] + Q.V[q];
                    (*R).B[i][j] = 1;
                }
                
                p++;
                q++;
            }
        }
    }
    
    (*R).tu = r;
    
    return OK;
}
