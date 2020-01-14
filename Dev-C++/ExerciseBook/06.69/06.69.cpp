#include <stdio.h>
#include "BiTree.h" //**▲06 树和二叉树**//

/*
 * 逆中序遍历且按层序打印树
 * i代表相对根结点走了几步，隐含了层序信息
 */
void Algo_6_69(BiTree T, int i);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("创建二叉树（先序序列）T...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("逆中序序列且按层序打印树：\n");
    Algo_6_69(T, 0);
    printf("\n");
    
    return 0;
}


/*
 * 逆中序遍历且按层序打印树
 * i代表相对根结点走了几步，隐含了层序信息
 */
void Algo_6_69(BiTree T, int i) {
    int j;
    
    if(T) {
        Algo_6_69(T->rchild, i + 1);    // 先访问右子树
        
        for(j = 1; j <= 2 * i; j++) {   // i乘以2是为了输出效果美观，实际空格数减半
            printf(" ");
        }
        printf("%c\n", T->data);
        
        Algo_6_69(T->lchild, i + 1);    // 最后访问左子树
    }
}
