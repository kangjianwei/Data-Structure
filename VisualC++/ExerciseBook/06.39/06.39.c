#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 二叉树元素类型，这里设置为字符 */
typedef char TElemType;

/* 二叉树的结点定义 */
typedef struct BiTNode {
    TElemType data;             // 结点元素
    struct BiTNode* lchild;     // 左孩子指针
    struct BiTNode* rchild;     // 右孩子指针
    struct BiTNode* parent;
    int mark;
} BiTNode;

/* 指向二叉树结点的指针 */
typedef BiTNode* BiTree;

/*
 * 后序遍历的递推形式
 */
void Algo_6_39(BiTree T);

// 构造二叉树(先序序列)
Status CreateBiTree(BiTree* T, char* path);

// 构造二叉树的内部实现，p用来追踪子树根结点
void CreateTree(BiTree* T, BiTree p, FILE* fp);

// 以图形化形式输出当前二叉树
void PrintGraph(BiTree T);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("创建二叉树 T ...\n");
    CreateBiTree(&T, NULL);
    PrintGraph(T);
    
    printf("二叉树后序遍历序列为：");
    Algo_6_39(T);
    
    return 0;
}


/*
 * 后序遍历的递推形式
 */
void Algo_6_39(BiTree T) {
    BiTree p = T;
    
    while(p != NULL) {
        // mark==0：还未访问，则先向左访问
        if(p->mark == 0) {
            p->mark = 1;
            if(p->lchild != NULL) {
                p = p->lchild;
            }
            
            // mark==1：左侧已访问，则再向右访问
        } else if(p->mark == 1) {
            p->mark = 2;
            if(p->rchild != NULL) {
                p = p->rchild;
            }
            
            // mark==2：左右都访问完了，则打印根结点
        } else {
            printf("%c ", p->data);
            p->mark = 0;            // 标记重置
            p = p->parent;
        }
    }
    
    printf("\n");
}

// 构造二叉树(先序序列)
Status CreateBiTree(BiTree* T, char* path) {
    FILE* fp;
    
    fp = fopen("TestData.txt", "r");
    CreateTree(T, NULL, fp);
    fclose(fp);
    
    return OK;
}

// 构造二叉树的内部实现，p用来追踪子树根结点
void CreateTree(BiTree* T, BiTree p, FILE* fp) {
    char ch;
    
    ReadData(fp, "%c", &ch);
    
    if(ch == '^') {
        *T = NULL;
    } else {
        *T = (BiTree) malloc(sizeof(BiTNode));
        if(!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        (*T)->parent = p;
        (*T)->mark = 0;
        CreateTree(&(*T)->lchild, *T, fp);
        CreateTree(&(*T)->rchild, *T, fp);
    }
}

// 以图形化形式输出当前二叉树
void PrintGraph(BiTree T) {
    BiTree p = T;
    int i = 1;
    
    while(p != NULL) {
        // mark==0：还未访问，则先向左访问
        if(p->mark == 0) {
            printf("%c ", p->data);
            i++;
            p->mark = 1;
            if(p->lchild != NULL) {
                p = p->lchild;
            } else {
                printf("^\n");
                i--;
            }
            
            // mark==1：左侧已访问，则再向右访问
        } else if(p->mark == 1) {
            p->mark = 2;
            i++;
            
            if(p->rchild != NULL) {
                printf("%*c", 2 * (i - 1), ' ');
                p = p->rchild;
            } else {
                printf("%*c^\n", 2 * (i - 1), ' ');
                i--;
            }
            
            // mark==2：左右都访问完了，则打印根结点
        } else {
            p->mark = 0;            // 标记重置
            p = p->parent;
            i--;
        }
    }
    
    printf("\n");
}
