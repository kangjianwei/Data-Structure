#include <stdio.h>
#include <math.h>       // 提供pow、log原型
#include "BiTree.h"     //**▲06 树和二叉树**//

#define MAX_TREE_SIZE  1024  // 二叉树元素数量最大值

/*
 * 计算二叉树的繁茂度：宽度x高度
 * 注：宽度为各层结点数的最大值
 */
int Algo_6_52(BiTree T);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("创建二叉树（先序序列）T...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("树的繁茂度为： %d", Algo_6_52(T));
    printf("\n");
    
    return 0;
}


/*
 * 计算二叉树的繁茂度：宽度x高度
 * 注：宽度为各层结点数的最大值
 */
int Algo_6_52(BiTree T) {
    int lux;         // 繁茂度
    int col, width;  // 各层宽度和最大宽度
    int row, high;   // 当前结点所在层数和最大高度
    BiTree queue[MAX_TREE_SIZE];    // 树指针数组，模拟队列
    int level[MAX_TREE_SIZE];       // 记录当前结点在第几层
    BiTree p;
    int m, n;
    
    if(T==NULL) {
        return 0;
    }
    
    width = high = 0;
    m = n = 0;
    col = 1;
    
    queue[n] = T;
    level[n] = 1;
    n++;
    
    while(m<n){
        p = queue[m];
        row = level[m];     // 当前结点所在的层
        m++;
        
        // 进入新的一层
        if(row>high) {
            high = row;
            col = 1;    // 换行时要重置列数
        } else {
            col++;
        }
    
        if(col>width) {
            width = col;
        }
        
        if(p->lchild!=NULL) {
            queue[n] = p->lchild;
            level[n] = row+1;
            n++;
        }
    
        if(p->rchild!=NULL) {
            queue[n] = p->rchild;
            level[n] = row+1;
            n++;
        }
        
        
    }
    
    lux = width * high;
    
    return lux;
}
