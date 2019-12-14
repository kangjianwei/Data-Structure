/*======================
 * ϡ���������ϰ��5.24
 =======================*/

#include "SMatrix.h"    //**ϡ�����**//

// ����ϡ�����M
Status CreateSMatrix(SMatrix* M, char* path) {
    FILE* fp;
    int k, i, j;
    
    fp = fopen(path, "r");
    
    ReadData(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));
    
    // ��ȡԪ��
    for(k = 1; k <= (*M).tu; k++) {
        ReadData(fp, "%d%d%d", &i, &j, &((*M).data[k].e));
        (*M).data[k].seq = (i - 1) * (*M).nu + j;
    }
    
    fclose(fp);
    
    return OK;
}

// ���ϡ�����M
void PrintSMatrix(SMatrix M) {
    int r, c;
    int k = 1;
    
    for(r = 1; r <= M.mu; r++) {
        for(c = 1; c <= M.nu; c++) {
            if(r == (M.data[k].seq - 1) / M.nu + 1 && c == (M.data[k].seq - 1) % M.nu + 1) {
                
                printf("%3d ", M.data[k].e);
                k++;
            } else {
                printf("  0 ");
            }
        }
        printf("\n");
    }
}
