#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "BiTree.h"     //**▲06 树和二叉树**//

/*
 * 计算二叉树中每个结点的子孙数目
 */
int Algo_6_55(BiTree T);

// 先序输出二叉树及各结点其子孙数目
void PreOrderPrint(BiTree T);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("创建二叉树（先序序列）T...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("先序输出二叉树结点值及其相应的子孙数目：\n");
    Algo_6_55(T);
    PreOrderPrint(T);
    
    return 0;
}


/*
 * 计算二叉树中每个结点的子孙数目
 */
int Algo_6_55(BiTree T) {
    int l, r;
    
    if(T == NULL) {
        return 0;
    } else {
        T->DescNum = 0;
        
        if(T->lchild != NULL) {
            l = Algo_6_55(T->lchild);
            T->DescNum += l + 1;
        }
        
        if(T->rchild != NULL) {
            r = Algo_6_55(T->rchild);
            T->DescNum += r + 1;
        }
    }
    
    return T->DescNum;
}

// 先序输出二叉树及各结点其子孙数目
void PreOrderPrint(BiTree T) {
    if(T != NULL) {
        printf("结点 %c 的子孙数目 %d\n", T->data, T->DescNum);
        PreOrderPrint(T->lchild);
        PreOrderPrint(T->rchild);
    }
}
