#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "BiTree.h"     //**▲06 树和二叉树**//

#define MAX_TREE_DEPTH 20    // 二叉树最大层数

/*
 * 寻找根结点到叶子结点最长路径中最靠左的一条
 */
int Algo_6_53(BiTree T, BiTree path[]);


int main(int argc, char* argv[]) {
    BiTree T;
    BiTree way[MAX_TREE_DEPTH] = {NULL};
    int i, n;
    
    printf("创建二叉树（先序序列）T...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("输出根结点到叶子结点最长路径中最靠左的一条：");
    n = Algo_6_53(T, way);
    for(i = 0; i < n; i++) {
        printf("%c ", way[i]->data);
    }
    printf("\n");
    
    return 0;
}


/*
 * 寻找根结点到叶子结点最长路径中最靠左的一条
 */
int Algo_6_53(BiTree T, BiTree path[]) {
    int i = -1;
    int mark[MAX_TREE_DEPTH] = {0}; // 访问标记栈
    BiTree p;
    int depth;
    
    // 先判断树的深度
    depth = BiTreeDepth(T);
    
    p = T;
    
    while(TRUE) {
        // 先尝试向左子树查找
        while(p != NULL) {
            i++;
            
            // 记下当前结点的指针
            path[i] = p;
            
            // 已访问过该结点的左子树
            mark[i] = 1;
            p = p->lchild;
        }
        
        // 向左走向尽头，判断其路径长度是否符合题意
        if(i + 1 == depth) {
            return depth;
        }
        
        // 回到父结点
        p = path[i];
        
        // 如果右子树不存在，或者该右子树已被访问过，则回到它的父结点
        while(p->rchild == NULL || mark[i] == 2) {
            path[i] = NULL;     // 置空该位置
            
            i--;
            if(i == -1) {
                return 0;
            }
            
            // 回退到父结点
            p = path[i];
        }
        
        // 已访问过该结点的右子树
        mark[i] = 2;
        p = p->rchild;
    }
}
