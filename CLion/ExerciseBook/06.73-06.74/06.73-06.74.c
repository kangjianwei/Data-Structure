#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "CSTree.h"     //**▲06 树和二叉树**//

/*
 * 创建孩子-兄弟链表
 */
Status Algo_6_73(CSTree* T, FILE* fp);

/*
 * 按广义表方式打印孩子-兄弟链表
 */
void Algo_6_74(CSTree T);


int main(int argc, char* argv[]) {
    CSTree T;
    FILE* fp;
    
    printf("███ 题 6.73 验证... ███\n");
    printf("创建孩子-兄弟二叉树：\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_73(&T, fp);
    fclose(fp);
    PrintTree(T);
    printf("\n");
    
    printf("███ 题 6.74 验证... ███\n");
    printf("按广义表打印孩子-兄弟链表...\n");
    Algo_6_74(T);
    printf("\n");
    
    return 0;
}


/*
 * 创建孩子-兄弟链表
 */
Status Algo_6_73(CSTree* T, FILE* fp) {
    char c;
    
    while(TRUE) {
        if(feof(fp) != 0) {
            break;
        }
        
        ReadData(fp, "%c", &c);
        
        if(c >= 'A' && c <= 'Z') {
            *T = (CSTree) malloc(sizeof(CSNode));    //根结点
            if(*T == NULL) {
                exit(OVERFLOW);
            }
            (*T)->data = c;
            (*T)->firstchild = (*T)->nextsibling = NULL;
        } else if(c == '(') {
            Algo_6_73(&(*T)->firstchild, fp);
        } else if(c == ',') {
            Algo_6_73(&(*T)->nextsibling, fp);
            break;  // 注意此处应该返回
        } else {
            break;
        }
    }
    
    return OK;
}

/*
 * 按广义表方式打印孩子-兄弟链表
 */
void Algo_6_74(CSTree T) {
    CSTree p;
    
    if(!T) {
        return;
    }
    
    printf("%c", T->data);
    
    if(T->firstchild) {
        printf("(");
        
        for(p = T->firstchild; p; p = p->nextsibling) {
            Algo_6_74(p);
            
            // 若不是最后一个兄弟，加","
            if(p->nextsibling) {
                printf(",");
            }
        }
        
        printf(")");
    }
}
