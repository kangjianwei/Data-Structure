#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "CTree.h"      //**▲06 树和二叉树**//

/*
 * 计算孩子链表表示的树的深度
 */
int Algo_6_63(CTree T);


int main(int argc, char* argv[]) {
    CTree T;
    
    printf("创建树T...\n");
    InitTree(&T);
    CreateTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("此树的深度为： %d\n", Algo_6_63(T));
    printf("\n");
    
    return 0;
}


/*
 * 计算孩子链表表示的树的深度
 */
int Algo_6_63(CTree T) {
    return TreeDepth(T);    // 已定义
}
