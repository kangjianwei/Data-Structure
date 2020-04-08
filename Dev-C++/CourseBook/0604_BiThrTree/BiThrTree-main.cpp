#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "BiThrTree.h"  //**▲06 树和二叉树**//

// 测试函数，打印元素
Status PrintElem(TElemType c) {
    printf("%c", c);
    return OK;
}


int main(int argc, char* argv[]) {
    BiThrTree T;    // 二叉树
    BiThrTree Thr;  // 中序全线索二叉树
    
    printf("████████ 中序全线索化二叉树 \n");
    {
        printf("█ 按先序序列创建二叉树...\n");
        CreateBiTree(&T, "TestData_Pre.txt");

        printf("█ 对二叉树进行中序全线索化...\n");
        InOrderThreading(&Thr, T);

        printf("█ 中序遍历中序全线索二叉树...\n");
        InOrderTraverse_Thr(Thr, PrintElem);

        // 逆中序遍历，用来验证前驱线索是否正确
        InOrderTraverse_Thr_Inverse(Thr, PrintElem);
    }
    PressEnterToContinue(debug);
}
