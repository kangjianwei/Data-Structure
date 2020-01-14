#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "BiTree.h"     //**▲06 树和二叉树**//

#define MAX_TREE_SIZE  1024  // 二叉树元素数量最大值

/*
 * 根据二叉树的层序序列创建链式二叉树
 */
Status Algo_6_54(BiTree* T, TElemType sa[100]);


int main(int argc, char* argv[]) {
    BiTree T;
    TElemType sa[MAX_TREE_SIZE] = "ABCDEF^G^HI^J";  // 层序序列
   
    printf("创建二叉树（层序序列）...\n");
    Algo_6_54(&T, sa);
    PrintTree(T);
    
    return 0;
}


/*
 * 根据二叉树的层序序列创建链式二叉树
 */
Status Algo_6_54(BiTree* T, TElemType sa[]) {
    BiTree tree[MAX_TREE_SIZE];   // 临时存放遍历中各结点指针的复制品
    int p, i;
    
    i = 0;
    
    while(sa[i] != '\0') {
        if(sa[i] == '^') {
            tree[i] = NULL;
        } else {
            tree[i] = (BiTree) malloc(sizeof(BiTNode));
            if(tree[i] == NULL) {
                exit(OVERFLOW);
            }
            tree[i]->data = sa[i];
            tree[i]->lchild = tree[i]->rchild = NULL;
        }
        
        if(i > 0) {
            p = (i - 1) / 2;   // 父结点序号
            
            // 当前结点是左孩子
            if(2 * p + 1 == i) {
                tree[p]->lchild = tree[i];
            } else {
                tree[p]->rchild = tree[i];
            }
        }
        
        i++;
    }
    
    *T = tree[0];
    
    return OK;
}
