#include <stdio.h>
#include "PowerSet.h"   //**▲06 树和二叉树**//

int main(int argc, char* argv[]) {
    List A;
    
    printf("████████ CreatePowerSet \n");
    {
        printf("█ 创建集合 A ...\n");
        CreatePowerSet(&A, "TestData_A.txt");
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ PrintPowerSet \n");
    {
        printf("█ 输出集合 A = ");
        PrintPowerSet(A);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ GetPowerSet \n");
    {
        LinkList B;
        
        printf("█ 计算集合的幂集...\n");
        
        printf("█ 创建集合 B 临时存储幂集元素...\n");
        InitList(&B);
        
        printf("█ 依次输出求取的幂集中的各子集...\n");
        GetPowerSet(1, A, B);
    }
    PressEnterToContinue(debug);
    
    return OK;
}
