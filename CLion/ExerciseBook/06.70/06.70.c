#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "BiTree.h"     //**▲06 树和二叉树**//

/*
 * 创建二叉树的二叉链表结构
 */
Status Algo_6_70(BiTree* T, FILE* fp);


int main(int argc, char* argv[]) {
    BiTree T;
    FILE* fp;
    
    printf("创建二叉树T...\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_70(&T, fp);
    fclose(fp);
    PrintTree(T);
    
    return 0;
}


/*
 * 创建二叉树的二叉链表结构
 */
Status Algo_6_70(BiTree* T, FILE* fp) {
    char c;
    
    while(TRUE) {
        // 字符读取完毕
        if(feof(fp)!=0) {
            return OK;
        }
        
        ReadData(fp, "%c", &c);
        
        if(c == '#') {
            *T = NULL;
        } else if(c >= 'A' && c <= 'Z') {
            *T = (BiTree) malloc(sizeof(BiTNode));    //根结点
            if(*T==NULL) {
                exit(OVERFLOW);
            }
            (*T)->data = c;
            (*T)->lchild = (*T)->rchild = NULL;
        } else if(c == '(') {
            Algo_6_70(&(*T)->lchild, fp);
            Algo_6_70(&(*T)->rchild, fp);
        } else {
            break;
        }
    }
    
    return OK;
}
