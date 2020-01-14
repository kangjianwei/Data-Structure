/*===================================
 * 树的二叉链表（孩子-兄弟）结构存储表示
 ====================================*/

#include "CSTree.h"

/*
 * 初始化
 *
 * 构造空树。
 */
Status InitTree(CSTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    *T = NULL;
    
    return OK;
}

/*
 * 判空
 *
 * 判断树是否为空树。
 */
Status TreeEmpty(CSTree T) {
    return T == NULL ? TRUE : FALSE;
}

// 以图形化形式输出当前结构
void PrintTree(CSTree T) {
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        printf("\n");
        return;
    }
    
    Print(T, 0);
    
    printf("\n");
}

// 图形化输出当前结构内部实现
static void Print(CSTree T, int row) {
    int k;
    
    if(T == NULL) {
        return;
    }
    
    // 访问当前结点
    printf("%c ", T->data);
    
    Print(T->firstchild, row + 1);
    
    if(T->nextsibling != NULL) {
        printf("\n");
        
        for(k = 0; k < row; k++) {
            printf(". ");
        }
        
        Print(T->nextsibling, row);
    }
}
