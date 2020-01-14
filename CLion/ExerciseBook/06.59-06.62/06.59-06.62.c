#include <stdio.h>
#include "CSTree.h"     //**▲06 树和二叉树**//

#define MAX_TREE_SIZE  1024  // 树中元素数量最大值

/*
 * 输出树的各条边
 */
void Algo_6_59(CSTree T);

/*
 * 求树的叶子结点个数
 */
int Algo_6_60(CSTree T);

/*
 * 求树的度：树中各结点度的最大值
 */
int Algo_6_61(CSTree T);

/*
 * 求树的深度
 */
int Algo_6_62(CSTree T);


int main(int argc, char* argv[]) {
    CSTree T;
    
    printf("创建树（先序序列）T...\n");
    InitTree(&T);
    CreateTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("███题 6.59 验证...███\n");
    {
        printf("输出所有边...\n");
        Algo_6_59(T);
        printf("\n\n");
    }
    
    printf("███题 6.60 验证...███\n");
    {
        int count;
        
        count = Algo_6_60(T);
        printf("叶子结点个数为：count = %d\n", count);
        printf("\n");
    }
    
    printf("███题 6.61 验证...███\n");
    {
        int degree;
        
        degree = Algo_6_61(T);
        printf("树的度为：degree = %d\n", degree);
        printf("\n");
    }
    
    printf("███题 6.62 验证...███\n");
    {
        int depth;
        
        depth = Algo_6_62(T);
        printf("树的深度为：depth = %d\n", depth);
        printf("\n");
    }
    
    return 0;
}


/*
 * 输出树的各条边
 */
void Algo_6_59(CSTree T) {
    CSTree p, q;
    
    if(T == NULL) {
        return;
    }
    
    p = T;
    q = T->firstchild;
    
    while(q != NULL) {
        printf("(%c, %c) ", p->data, q->data);
        q = q->nextsibling;
    }
    
    Algo_6_59(T->firstchild);
    Algo_6_59(T->nextsibling);
}

/*
 * 求树的叶子结点个数
 */
int Algo_6_60(CSTree T) {
    if(T == NULL) {
        return 0;
    }
    
    // 遇到叶子结点
    if(T->firstchild == NULL) {
        return 1 + Algo_6_60(T->nextsibling);
    } else {
        return Algo_6_60(T->firstchild) + Algo_6_60(T->nextsibling);
    }
}

/*
 * 求树的度：树中各结点度的最大值
 */
int Algo_6_61(CSTree T) {
    CSTree queue[MAX_TREE_SIZE];    // 按层序存储访问过的结点
    int parent[MAX_TREE_SIZE];      // 存储每个结点的父结点
    int order[MAX_TREE_SIZE];       // 存储每个结点的编号
    CSTree p, r;
    int col, max;
    int m, n;
    int curParent;                  // 记录访问结点的父结点
    
    if(T == NULL || T->firstchild == NULL) {
        return 0;
    }
    
    curParent = -2;
    max = 0;
    
    m = n = 0;
    
    queue[n] = T;
    parent[n] = -1;
    order[n] = 0;
    n++;
    
    while(m < n) {
        p = queue[m];
        
        // 遇到新的父结点
        if(parent[m] != curParent) {
            curParent = parent[m];
            col = 1;                // 重置列
        } else {
            col++;
        }
        
        if(col > max) {
            max = col;
        }
        
        // 存储子结点
        for(r = p->firstchild; r != NULL; r = r->nextsibling) {
            queue[n] = r;
            parent[n] = order[m];   // 为子结点存储父结点编号
            order[n] = n;           // 记录当前结点的编号
            n++;
        }
        
        m++;
    }
    
    return max;
}

/*
 * 求树的深度
 */
int Algo_6_62(CSTree T) {
    return TreeDepth(T);    // 已定义
}
