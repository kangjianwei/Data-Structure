#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "CSTree.h"     //**▲06 树和二叉树**//

#define MAX_TREE_SIZE  1024  // 树中元素数量最大值

/*
 * 创建树的孩子-兄弟结构
 */
Status Algo_6_68(CSTree* T, FILE* fp);


int main(int argc, char* argv[]) {
    CSTree T;
    FILE* fp;
    
    printf("创建孩子-兄弟二叉树：\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_68(&T, fp);
    fclose(fp);
    printf("\n");
    
    PrintTree(T);
    printf("\n");
    
    return 0;
}


/*
 * 创建树的孩子-兄弟结构
 */
Status Algo_6_68(CSTree* T, FILE* fp) {
    CSTree queue[MAX_TREE_SIZE] = {NULL};   // 按层序存储遇到的结点
    int d[MAX_TREE_SIZE];       // 存储该结点的度
    int parent[MAX_TREE_SIZE];  // 存储该结点的父结点信息
    CSTree p;
    int x;
    char ch;
    int m, n;
    int i;
    
    d[0] = 1;
    
    for(m = 0, n = 1; m < n; m++) {
        p = NULL;
        i = 0;
        
        while(i < d[m]) {
            // 跳过换行标记
            ch = getc(fp);
            if(ch == '\n' || ch == '\r') {
                continue;
            } else {
                ungetc(ch, fp);
            }
            
            // 读取结点信息
            ReadData(fp, "%c%d", &ch, &x);
            printf("%c %d\n", ch, x);
            if(x < 0) {
                return ERROR;
            }
            
            d[n] = x;
            parent[n] = m;
            
            // 创建新结点
            queue[n] = (CSTree) malloc(sizeof(CSNode));
            if(queue[n] == NULL) {
                exit(OVERFLOW);
            }
            queue[n]->data = ch;
            queue[n]->firstchild = queue[n]->nextsibling = NULL;
            
            // 追踪该层首个结点
            if(p == NULL) {
                p = queue[n];
            } else {
                // 将孩子结点串联到一起
                queue[n - 1]->nextsibling = queue[n];
            }
            
            n++;
            i++;
        }
        
        if(m > 0 && queue[m]->firstchild == NULL) {
            queue[m]->firstchild = p;
        }
    }
    
    *T = queue[1];
    
    return OK;
}
