#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "BiTree.h"     //**▲06 树和二叉树**//

/*
 * 输出算术表达式构成的二叉树（中序遍历）
 */
void Algo_6_51(BiTree T);

// 判断字符c是否为操作符
Status IsOperator(char c);


int main(int argc, char* argv[]) {
    BiTree T;

    printf("创建二叉树（先序序列）T...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");

    printf("输出算术表达式：");
    Algo_6_51(T);
    printf("\n");

    return 0;
}


/*
 * 输出算术表达式构成的二叉树（中序遍历）
 */
void Algo_6_51(BiTree T) {
    if(T == NULL) {
        return;
    }

    if(T->lchild != NULL) {
        // 左子树是表达式，则添加括号
        if(IsOperator(T->lchild->data)) {
            printf("(");
            Algo_6_51(T->lchild);
            printf(")");
        } else {
            Algo_6_51(T->lchild);
        }
    }

    printf("%c", T->data);

    if(T->rchild != NULL) {
        // 右子树是表达式，则添加括号
        if(IsOperator(T->rchild->data)) {
            printf("(");
            Algo_6_51(T->rchild);
            printf(")");
        } else {
            Algo_6_51(T->rchild);
        }
    }
}

// 判断字符c是否为操作符
Status IsOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        return TRUE;
    } else {
        return ERROR;
    }
}

