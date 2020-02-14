#include <stdio.h>
#include "MFSet.h"      //**▲06 树和二叉树**//

// 输出二元关系对
void PrintRelation(Relation R){
    int k;
    
    for(k=0; k<R.n; k++) {
        printf("(%d, %d) ", R.pairs[k].i, R.pairs[k].j);
    }
    
    printf("\n");
}


int main(int argc, char* argv[]) {
    MFSet S;
    Relation R1, R2;
    
    printf("████████ initial_mfset、initial_relation \n");
    {
        printf("█ 初始化集合 S ...\n");
        initial_mfset(&S, "TestData_S.txt");
        
        printf("█ 初始化二元关系 R1 ...\n");
        initial_relation(&R1, "TestData_R1.txt");
    
        printf("█ 初始化二元关系 R2 ...\n");
        initial_relation(&R2, "TestData_R2.txt");
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ PrintSet \n");
    {
        printf("█ 输出集合 S ...\n");
        PrintSet(S);
    }
    PressEnterToContinue(debug);
    
    
    // 方案一
    printf("████████ find_mfset、merge_mfset \n");
    {
        printf("█ 对集合应用二元关系 R1： ");
        build_mfset(&S, R1);
        PrintRelation(R1);

        printf("█ 输出集合 S ...\n");
        PrintSet(S);


        printf("█ 对集合应用二元关系 R2： ");
        build_mfset(&S, R2);
        PrintRelation(R2);

        printf("█ 输出集合 S ...\n");
        PrintSet(S);
    }
    PressEnterToContinue(debug);
    
    
    // 方案二
//    printf("████████ fix_mfset、mix_mfset \n");
//    {
//        printf("█ 对集合应用二元关系 R1： ");
//        bix_mfset(&S, R1);
//        PrintRelation(R1);
//
//        printf("█ 输出集合 S ...\n");
//        PrintSet(S);
//
//
//        printf("█ 对集合应用二元关系 R2： ");
//        bix_mfset(&S, R2);
//        PrintRelation(R2);
//
//        printf("█ 输出集合 S ...\n");
//        PrintSet(S);
//    }
//    PressEnterToContinue(debug);
    
    return OK;
}
