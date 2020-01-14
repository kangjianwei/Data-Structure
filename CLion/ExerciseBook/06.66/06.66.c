#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "PTree.h"      //**▲06 树和二叉树**//
#include "CSTree.h"     //**▲06 树和二叉树**//

/*
 * 树的双亲表示法转为树的孩子-兄弟表示法
 */
CSTree Algo_6_66(PTree T);


int main(int argc, char* argv[]) {
    PTree PT;
    CSTree CST;
    
    printf("创建树T...\n");
    InitTree_P(&PT);
    CreateTree_P(&PT, "TestData.txt");
    PrintTree_P(PT);
    printf("\n");
    
    printf("树的双亲表示法转为树的孩子-兄弟表示法：\n");
    CST = Algo_6_66(PT);
    PrintTree_CS(CST);
    printf("\n");
    
    return 0;
}


/*
 * 树的双亲表示法转为树的孩子-兄弟表示法
 */
CSTree Algo_6_66(PTree T) {
    CSTree p, q;
    CSTree tree[MAX_TREE_SIZE] = {NULL};
    int i, j, k;
    
    // 双亲表按层序存储
    for(i = T.r, j = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        // 获取该结点的父结点
        k = T.nodes[i].parent;
        
        // 复制结点信息
        p = (CSTree) malloc(sizeof(CSNode));
        if(p == NULL) {
            exit(OVERFLOW);
        }
        p->data = T.nodes[i].data;
        p->firstchild = p->nextsibling = NULL;
        
        // 当前结点存在父结点
        if(k != -1) {
            // 当前结点作为了第一个孩子
            if(tree[k]->firstchild == NULL) {
                tree[k]->firstchild = p;
                
                // 当前结点不是第一个孩子，则首先查找其父结点的孩子链表的尾部
            } else {
                for(q = tree[k]->firstchild; q->nextsibling != NULL; q = q->nextsibling) {
                    // 寻找孩子链表的末端
                }
                
                q->nextsibling = p;
            }
        }
        
        tree[j] = p;
        j = (j + 1) % MAX_TREE_SIZE;
    }
    
    return tree[T.r];
}
