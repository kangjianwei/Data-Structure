#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "BiTree.h"     //**▲06 树和二叉树**//

#define MAX_TREE_SIZE  1024  // 二叉树元素数量最大值

/*
 * 读取预定格式的结点信息，按层序创建二叉树。
 */
Status Algo_6_50(BiTree* T, FILE* fp);


int main(int argc, char* argv[]) {
    BiTree T;
    FILE* fp;
    
    printf("创建二叉树（层序序列）...\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_50(&T, fp);
    fclose(fp);
    printf("\n");
    
    printf("二叉树T为：\n");
    PrintTree(T);
    
    return 0;
}


/*
 * 读取预定格式的结点信息，按层序创建二叉树。
 */
Status Algo_6_50(BiTree* T, FILE* fp) {
    char s[4];
    BiTree tmp[MAX_TREE_SIZE];    // 按层序存储遇到的每个结点的指针
    int m, n;
    BiTree p;
    
    m = n = 0;
    
    *T= NULL;
    
    while(TRUE) {
        ReadData(fp, "%s", s);
        printf("%s\n", s);
        
        // 退出标志
        if(s[1] == '^') {
            return OK;
        }
    
        p = (BiTree) malloc(sizeof(BiTNode));
        if(p==NULL) {
            exit(OVERFLOW);
        }
        p->data = s[1];
        p->lchild = p->rchild = NULL;
    
        // 根结点
        if(s[0] == '^') {
            *T = p;
            tmp[n++] = p;
        } else {
            // 寻找子树结点
            while(m<n && tmp[m]->data != s[0]) {
                m++;
            }
    
            if(m>=n) {
                return ERROR;
            }
            
            if(s[2] == 'L') {
                tmp[m]->lchild = p;
            } else {
                tmp[m]->rchild = p;
            }
        }
    
        tmp[n++] = p;
    }
}
