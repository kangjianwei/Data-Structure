#include <stdio.h>
#include "CrossList.h"            //**��05 ����͹����**//

int main(int argc, char** argv) {
    CrossList M, N;
    
    printf("���������������� ���� CreateSMatrix \n");
    {
        printf("�� ��������ϡ����� M��N ...\n");
        CreateSMatrix(&M, "TestData_M.txt");
        CreateSMatrix(&N, "TestData_N.txt");
    }
    PressEnterToContinue();
    
    
    printf("���������������� ���� PrintSMatrix \n");
    {
        printf("�� M = \n");
        PrintSMatrix(M);
        
        printf("�� N = \n");
        PrintSMatrix(N);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ���� CopySMatrix \n");
    {
        CrossList Tmp;
        
        printf("�� ���� M �� Tmp...\n");
        CopySMatrix(M, &Tmp);
        
        printf("�� Tmp = \n");
        PrintSMatrix(Tmp);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ���� AddSMatrix \n");
    {
        CrossList Q1;
        
        AddSMatrix(M, N, &Q1);
        
        printf("�� Q1 = M + N = \n");
        PrintSMatrix(Q1);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ���� SubtSMatrix \n");
    {
        CrossList Q2;
        
        SubSMatrix(M, N, &Q2);
        
        printf("�� Q2 = M - N = \n");
        PrintSMatrix(Q2);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ���� MultSMatrix \n");
    {
        CrossList Q3;
        
        MultSMatrix(M, N, &Q3);
        
        printf("�� Q3 = M * N = \n");
        PrintSMatrix(Q3);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ���� TransposeSMatrix \n");
    {
        CrossList T;
        
        TransposeSMatrix(M, &T);
        
        printf("�� T = M(T) = \n");
        PrintSMatrix(T);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ���� DestroySMatrix \n");
    {
        printf("�� ���� M ǰ��");
        !M.mu && !M.nu && !M.tu ? printf(" M �����ڣ���\n") : printf(" M ���ڣ�\n");
        
        DestroySMatrix(&M);
        
        printf("�� ���� M ��");
        !M.mu && !M.nu && !M.tu ? printf(" M �����ڣ���\n") : printf(" M ���ڣ�\n");
    }
    PressEnterToContinue();
    
    return 0;
}
