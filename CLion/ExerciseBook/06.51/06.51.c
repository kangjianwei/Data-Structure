#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "BiTree.h"     //**▲06 树和二叉树**//

/*
 * 输出算术表达式构成的二叉树（中序遍历）
 */
void Algo_6_51(BiTree T);

// 判断字符c是否为操作符
Status IsOperator(char c);

// 判断两个操作符的优先级
Status Priority(char a, char b);


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
        // 当前结点的左孩子是操作符且优先级低于当前结点
        if(IsOperator(T->lchild->data) && Priority(T->lchild->data, T->data) < 0) {
            printf("(");
            Algo_6_51(T->lchild);
            printf(")");
        } else {
            Algo_6_51(T->lchild);
        }
    }
    
    printf("%c", T->data);
    
    if(T->rchild != NULL) {
        // 当前结点的右孩子是操作符且优先级低于当前结点
        if(IsOperator(T->rchild->data) && Priority(T->rchild->data, T->data) < 0) {
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

// 判断两个操作符的优先级
Status Priority(char a, char b) {
    // a的优先级低
    if((a == '+' || a == '-') && (b == '*' || b == '/')) {
        return -1;
        
        // a的优先级高
    } else if((a == '*' || a == '/') && (b == '+' || b == '-')) {
        return 1;
        
        // 优先级相同
    } else {
        return 0;
    }
}
