/*======================
 * ϡ���������ϰ��5.25
 =======================*/

#include "SMatrix.h"    //**ϡ�����**//

// ����ϡ�����M
Status CreateSMatrix(SMatrix* M, char* path) {
    FILE* fp;
    int v, i, j;
    
    fp = fopen(path, "r");
    
    ReadData(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));
    
    memset((*M).V, 0, sizeof((*M).V));
    memset((*M).B, 0, sizeof((*M).B));
    
    for(v=0; v < (*M).tu; v++) {
        // ��ȡ����Ԫ��Ϣ����Ԫ�ش�������V��
        ReadData(fp, "%d%d%d", &i, &j, &((*M).V[v]));
        
        (*M).B[i-1][j-1] = 1;
    }
    
    fclose(fp);
    
    return OK;
}

// ���ϡ�����M
void PrintSMatrix(SMatrix M) {
    int v, i, j;
    
    v = 0;  // ����V���α�
    
    for(i = 1; i <= M.mu; i++) {
        for(j = 1; j <= M.nu; j++) {
            if(M.B[i-1][j-1] == 1) {
                printf("%3d ", M.V[v++]);
            } else {
                printf("%3d ", M.B[i-1][j-1]);
            }
        }
        
        printf("\n");
    }
}
