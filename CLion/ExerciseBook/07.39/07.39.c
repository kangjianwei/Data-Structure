#include <stdio.h>
#include "SqList.h"
#include "BiTree.h"

/*
 * 获取存储在二叉树中的表达式的逆波兰式
 *
 * 注：表达式结构参考教材插图7.22
 */
void Algo_7_39(BiTree T);

/*
 * 从二叉树的根结点出发获取树中存储的表达式的逆波兰式。
 * 求取的逆波兰式会存储在RPN中。
 *
 * 注：使用了后续遍历
 */
static void AntiPolandFormula_7_39(BiTree T, SqList* RPN);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("████████ 创建并打印二叉树... \n");
    {
        InitBiTree(&T);
        CreateBiTree(&T, "TestData_Pre.txt");
        PrintTree(T);
        printf("\n");
    }
    
    printf("████████ 求取二叉树中存储的表达式的逆波兰式... \n");
    {
        Algo_7_39(T);
        printf("\n");
    }
    
    return 0;
}


/*
 * 获取存储在二叉树中的表达式的逆波兰式
 *
 * 注：表达式结构参考教材插图7.23
 */
void Algo_7_39(BiTree T) {
    int i;
    SqList RPN;  // 存储逆波兰表达式
    ElemType e;
    
    // 初始化长度为0的线性表
    InitList(&RPN);
    
    // 从有向无环图的根结点出发，通过尾递归获取到其中存储的表达式的逆波兰式
    AntiPolandFormula_7_39(T, &RPN);
    
    for(i = 1; i <= ListLength(RPN); i++) {
        GetElem(RPN, i, &e);
        printf("%c", e);
    }
    printf("\n");
}

/*
 * 从二叉树的根结点出发获取树中存储的表达式的逆波兰式。
 * 求取的逆波兰式会存储在RPN中。
 *
 * 注：使用了后续遍历
 */
void AntiPolandFormula_7_39(BiTree T, SqList* RPN) {
    if(T == NULL) {
        return;
    }
    
    AntiPolandFormula_7_39(T->lchild, RPN);
    AntiPolandFormula_7_39(T->rchild, RPN);
    // 当没有孩子结点可遍历时，存储当前结点
    ListInsert(RPN, ListLength(*RPN) + 1, T->data);
}
