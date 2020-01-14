#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "BiTree.h"     //**▲06 树和二叉树**//

/*
 * 判断两棵二叉树是否相似
 */
Status Algo_6_36(BiTree B1, BiTree B2);


int main(int argc, char* argv[]) {
    BiTree B1, B2, B3;
    
    printf("创建二叉树 B1 ：...\n");
    CreateBiTree(&B1, "TestData_B1.txt");
    PrintTree(B1);
    printf("\n");
    
    printf("创建二叉树 B2 ：...\n");
    CreateBiTree(&B2, "TestData_B2.txt");
    PrintTree(B2);
    printf("\n");
    
    printf("创建二叉树 B3 ：...\n");
    CreateBiTree(&B3, "TestData_B3.txt");
    PrintTree(B3);
    printf("\n");
    
    if(Algo_6_36(B1, B2) == TRUE) {
        printf("B1与B2相似！\n");
    } else {
        printf("B1与B2不相似！！\n");
    }
    
    if(Algo_6_36(B2, B3) == TRUE) {
        printf("B2与B3相似！\n");
    } else {
        printf("B2与B3不相似！！\n");
    }
    
    return 0;
}


/*
 * 判断两棵二叉树是否相似
 */
Status Algo_6_36(BiTree B1, BiTree B2) {
    // 都为空树
    if(BiTreeEmpty(B1) && BiTreeEmpty(B2)) {
        return TRUE;
    } else {
        // 都不为空树
        if(!BiTreeEmpty(B1) && !BiTreeEmpty(B2)) {
            // 判断左右子树
            if(Algo_6_36(B1->lchild, B2->lchild) && Algo_6_36(B1->rchild, B2->rchild)) {
                return TRUE;
            }
        }
    }
    
    return FALSE;
}
