#include <stdio.h>
#include "CrossList.h"            //**▲05 数组和广义表**//

int main(int argc, char** argv) {
    CrossList M, N;
    
    printf("████████ 函数 CreateSMatrix \n");
    {
        printf("█ 创建两个稀疏矩阵 M、N ...\n");
        CreateSMatrix(&M, "TestData_M.txt");
        CreateSMatrix(&N, "TestData_N.txt");
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ 函数 PrintSMatrix \n");
    {
        printf("█ M = \n");
        PrintSMatrix(M);
        
        printf("█ N = \n");
        PrintSMatrix(N);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ 函数 CopySMatrix \n");
    {
        CrossList Tmp;
        
        printf("█ 复制 M 到 Tmp...\n");
        CopySMatrix(M, &Tmp);
        
        printf("█ Tmp = \n");
        PrintSMatrix(Tmp);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ 函数 AddSMatrix \n");
    {
        CrossList Q1;
        
        AddSMatrix(M, N, &Q1);
        
        printf("█ Q1 = M + N = \n");
        PrintSMatrix(Q1);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ 函数 SubtSMatrix \n");
    {
        CrossList Q2;
        
        SubSMatrix(M, N, &Q2);
        
        printf("█ Q2 = M - N = \n");
        PrintSMatrix(Q2);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ 函数 MultSMatrix \n");
    {
        CrossList Q3;
        
        MultSMatrix(M, N, &Q3);
        
        printf("█ Q3 = M * N = \n");
        PrintSMatrix(Q3);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ 函数 TransposeSMatrix \n");
    {
        CrossList T;
        
        TransposeSMatrix(M, &T);
        
        printf("█ T = M(T) = \n");
        PrintSMatrix(T);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ 函数 DestroySMatrix \n");
    {
        printf("█ 销毁 M 前：");
        !M.mu && !M.nu && !M.tu ? printf(" M 不存在！！\n") : printf(" M 存在！\n");
        
        DestroySMatrix(&M);
        
        printf("█ 销毁 M 后：");
        !M.mu && !M.nu && !M.tu ? printf(" M 不存在！！\n") : printf(" M 存在！\n");
    }
    PressEnterToContinue(debug);
    
    return 0;
}
