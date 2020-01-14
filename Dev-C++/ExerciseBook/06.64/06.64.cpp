#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "PTree.h"      //**▲06 树和二叉树**//

/*
 * 计算双亲表表示的树的深度
 */
int Algo_6_64(PTree T);


int main(int argc, char* argv[]) {
    PTree T;
    
    printf("创建树T...\n");
    InitTree(&T);
    CreateTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("此树的深度为： %d\n", Algo_6_64(T));
    printf("\n");
    
    return 0;
}


/*
 * 计算双亲表表示的树的深度
 */
int Algo_6_64(PTree T) {
    return TreeDepth(T);    // 已定义
}
