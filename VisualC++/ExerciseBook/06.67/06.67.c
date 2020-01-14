#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "CSTree.h"     //**▲06 树和二叉树**//

#define MAX_TREE_SIZE  1024  // 树中元素数量最大值

/*
 * 创建树的孩子-兄弟结构
 */
Status Algo_6_67(CSTree* T, FILE* fp);


int main(int argc, char* argv[]) {
    CSTree T;
    FILE* fp;
    
    printf("创建孩子-兄弟二叉树：\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_67(&T, fp);
    fclose(fp);
    printf("\n");
    
    PrintTree(T);
    printf("\n");
    
    return 0;
}


/*
 * 创建树的孩子-兄弟结构
 */
Status Algo_6_67(CSTree* T, FILE* fp) {
    char input[3];
    CSTree tree[MAX_TREE_SIZE];    // 顺序存储遇到的每个结点
    CSTree p, q;
    int m, n, count;
    
    m = n = 0;
    count = 0;
    
    while(TRUE) {
        printf("录入第 %2d 个二元组：", ++count);
        ReadData(fp, "%s", input);
        printf("%s\n", input);
        
        // 退出标志
        if(input[1] == '^') {
            return OK;
        }
        
        p = (CSTree) malloc(sizeof(CSNode));
        if(p == NULL) {
            exit(OVERFLOW);
        }
        p->data = input[1]; // 当前结点信息
        p->firstchild = p->nextsibling = NULL;
        
        // 根结点
        if(input[0] == '^') {
            *T = p;
        } else {
            // 查找根结点在tree中的位置
            while(tree[m]->data != input[0]) {
                m++;
            }
            
            // 当前结点作为第一个孩子
            if(tree[m]->firstchild == NULL) {
                tree[m]->firstchild = p;
            } else {
                for(q = tree[m]->firstchild; q->nextsibling != NULL; q = q->nextsibling) {
                    // 寻找孩子链表的末端
                }
                
                // 插入当前结点
                q->nextsibling = p;
            }
        }
        
        tree[n++] = p;
    }
}
