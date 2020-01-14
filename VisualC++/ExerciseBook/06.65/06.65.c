#include <stdio.h>
#include <string.h>     // 提供strlen原型
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "BiTree.h"     //**▲06 树和二叉树**//

/* 全局变量 */
char Pre[] = "ABDGEHICFJ";  // 前序序列
char In[] = "GDBHEIAFJC";  // 中序序列

/*
 * 由前序序列和中序序列构造二叉树
 */
Status Algo_6_65(BiTree* T);

// 构造二叉树的内部实现
BiTree BuildTree(int pre_start, int pre_end, int in_start, int in_end);    //递归创建二叉树


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("二叉树先序序列为：%s\n", Pre);
    printf("二叉树中序序列为：%s\n", In);
    printf("\n");
    
    printf("由此构造的二叉树为 T = \n");
    Algo_6_65(&T);
    PrintTree(T);
    printf("\n");
    
    return 0;
}


/*
 * 由前序序列和中序序列构造二叉树
 */
Status Algo_6_65(BiTree* T) {
    int len_pre, len_in;
    
    len_pre = strlen(Pre);
    len_in = strlen(In);
    
    if(len_pre == 0 || len_in == 0 || len_pre != len_in) {
        return ERROR;
    }
    
    *T = BuildTree(0, len_pre - 1, 0, len_in - 1);
    
    return OK;
}

// 构造二叉树的内部实现
BiTree BuildTree(int pre_start, int pre_end, int in_start, int in_end) {
    BiTree T;
    int i, LTreeLen, RTreeLen;
    
    T = (BiTree) malloc(sizeof(BiTNode));   // 建立根结点
    if(T == NULL) {
        exit(OVERFLOW);
    }
    T->data = Pre[pre_start];       // 遍历前序存储的结点
    T->lchild = T->rchild = NULL;   // 初始化时置空左右孩子指针
    
    i = in_start;
    while(In[i] != T->data) {   // 在中序序列中寻找根结点位置
        i++;
    }
    
    LTreeLen = i - in_start;    // 左子树长度
    RTreeLen = in_end - i;      // 右子树长度
    
    // 左子树存在
    if(LTreeLen) {
        T->lchild = BuildTree(pre_start + 1, pre_start + LTreeLen, in_start, i - 1);
    }
    
    // 右子树存在
    if(RTreeLen) {
        T->rchild = BuildTree(pre_start + LTreeLen + 1, pre_end, i + 1, in_end);
    }
    
    return T;
}
