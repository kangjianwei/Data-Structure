#include <stdio.h>
#include "Status.h"    //**��01 ����**//
#include "TSMatrix.h"  //**��05 ����͹����**//

/*
 * ϡ�����ӷ���AddSMatrix
 *
 *��ע��
 * ��������Ҫ���浽ԭ����A��
 */
Status Algo_5_22(TSMatrix* A, TSMatrix B);


int main(int argc, char* argv[]) {
    TSMatrix A, B;
    
    printf("�� ��������ϡ����� A��B ...\n");
    CreateSMatrix(&A, "TestData_A.txt");
    CreateSMatrix(&B, "TestData_B.txt");
    printf("�� A = \n");
    PrintSMatrix(A);
    printf("�� B = \n");
    PrintSMatrix(B);
    
    // �������
    Algo_5_22(&A, B);
    
    printf("�� A = A + B = \n");
    PrintSMatrix(A);
    
    return 0;
}


/*
 * ϡ�����ӷ���AddSMatrix
 *
 *��ע��
 * ��������Ҫ���浽ԭ����A��
 */
Status Algo_5_22(TSMatrix* A, TSMatrix B) {
    int m, n, k;
    
    if((*A).mu != B.mu || (*A).nu != B.nu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // A��Ԫ������ƶ����ƶ�����ΪB��Ԫ�ظ���
    for(k = (*A).tu; k > 0; k--) {
        (*A).data[k + B.tu] = (*A).data[k];
    }
    
    m = B.tu + 1;   // ����A�����
    n = 1;          // ����B�����
    k = 0;          // ָ����������α�
    
    // ���α���A��B����Ԫ��
    while(m <= (*A).tu + B.tu && n <= B.tu) {
        // A�е���Ԫ�����±��С
        if((*A).data[m].i < B.data[n].i) {
            (*A).data[++k] = (*A).data[m++];
            
            // B�е���Ԫ�����±��С
        } else if((*A).data[m].i > B.data[n].i) {
            (*A).data[++k] = B.data[n++];
            
            // A��B�е���Ԫ�����±�һ�£���Ҫ��һ���Ƚ�������
        } else {
            // A�е���Ԫ�����±��С
            if((*A).data[m].j < B.data[n].j) {
                (*A).data[++k] = (*A).data[m++];
                
                // B�е���Ԫ�����±��С
            } else if((*A).data[m].j > B.data[n].j) {
                (*A).data[++k] = B.data[n++];
                
                // A��B�е���Ԫ�����±�һ�£���Ҫ���мӷ�����
            } else {
                // ֵ��Ϊ0ʱ����Ҫ�洢��Ԫ��
                if(((*A).data[m].e + B.data[n].e) != 0) {
                    k++;
                    (*A).data[k].i = (*A).data[m].i;
                    (*A).data[k].j = (*A).data[m].j;
                    (*A).data[k].e = (*A).data[m].e + B.data[n].e;
                }
                m++;
                n++;
            }
        }
    }
    
    // ����A��ʣ�����Ԫ��
    while(m <= (*A).tu + B.tu) {
        (*A).data[++k] = (*A).data[m++];
    }
    
    // ����B��ʣ�����Ԫ��
    while(n <= B.tu) {
        (*A).data[++k] = B.data[n++];
    }
    
    (*A).tu = k;
    
    return OK;
}
