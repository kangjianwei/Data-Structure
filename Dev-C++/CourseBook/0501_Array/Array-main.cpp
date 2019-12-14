#include <stdio.h>
#include "Array.h"//**��05 ����͹����**//

// ��������������ڲ�ʵ��
static void Print(Array A, int dim, int index[]) {
    int i;
    int start;
    
    if(dim == A.dim) {
        start = 0;
        
        // ���㱾�α�������ʼԪ��λ��
        for(i = 0; i < dim - 1; i++) {
            start += index[i] * A.constants[i];
        }
        
        // �������һ��ά���ڵ�Ԫ��
        for(i = 0; i < A.bounds[dim - 1]; i++) {
            printf("%d ", A.base[start + i]);
        }
    } else {
        
        for(i = 0; i < A.bounds[dim - 1]; i++) {
            printf("<");
            
            // ������ת
            index[dim - 1] = (index[dim - 1] + 1 + A.bounds[dim - 1]) % A.bounds[dim - 1];
            
            Print(A, dim + 1, index);
            
            printf(">");
        }
    }
}

// ���������������������
static void ArrayPrint(Array A) {
    int i;
    int* index;
    
    // �ڱ�������Ԫ��ʱ����¼ÿ��Ԫ�ص�������ֻ��¼ǰdim-1ά��
    index = (int*) malloc((A.dim - 1) * sizeof(int));
    for(i = 0; i < A.dim - 1; i++) {
        index[i] = -1;
    }
    
    Print(A, 1, index);
    
    printf("\n");
}


/* ����ά����Ϊ������ */
int main(int argc, char** argv) {
    Array A;
    
    printf("���������������� ���� InitArray ������ά����Ϊ����\n");
    {
        printf("�� ��ʼ��һ��ά��Ϊ<2,3,4>����ά���� A ...\n");
        InitArray(&A, 3, 2, 3, 4);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ���� Assign \n");
    {
        int i, j, k;
        ElemType e = 0;
        
        for(i = 0; i < A.bounds[0]; i++) {
            for(j = 0; j < A.bounds[1]; j++) {
                for(k = 0; k < A.bounds[2]; k++) {
                    printf("�� ��ֵ��A[%d][%d][%d] = %d\n", i, j, k, ++e);
                    Assign(&A, e, i, j, k);
                }
            }
        }
        printf("�� A = ");
        ArrayPrint(A);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ���� Value \n");
    {
        ElemType x;
        
        printf("�� ��ȡ A ���±�Ϊ (1,1,1) ��Ԫ�ص�ֵ��Locate ������� A[1][1][1] �����λ��...\n");
        Value(A, &x, 1, 1, 1);
        printf("�� A[1][1][1] = %d\n", x);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ���� DestroyArray \n");
    {
        printf("�� ���� A ǰ��");
        A.dim != 0 ? printf(" A ���ڣ�\n") : printf(" A �����ڣ���\n");
        
        DestroyArray(&A);
        
        printf("�� ���� A ��");
        A.dim != 0 ? printf(" A ���ڣ�\n") : printf(" A �����ڣ���\n");
    }
    PressEnterToContinue();
    
    
    return 0;
}
