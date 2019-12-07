#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//

/* 二叉树元素类型，这里设置为字符 */
typedef char TElemType;

/* 二叉树的结点定义 */
typedef struct BiTNode {
    TElemType data;         // 结点元素
    struct BiTNode* lchild; // 左孩子指针
    struct BiTNode* rchild; // 右孩子指针
    struct BiTNode* parent;
} BiTNode;

/* 指向二叉树结点的指针 */
typedef BiTNode* BiTree;

/*
 * 中序遍历的递推形式
 *
 *【注】
 * 遍历的关键是分辨当前结点第几次被访问。
 */
void Algo_6_40(BiTree T);

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
    
    printf("二叉树中序遍历序列为：");
    Algo_6_40(T);
    
    return 0;
}


/*
 * 中序遍历的递推形式
 *
 *【注】
 * 遍历的关键是分辨当前结点第几次被访问。
 */
void Algo_6_40(BiTree T) {
    BiTree p = T;
    
    while(p != NULL) {
        // 第一次访问结点，向左访问
        if(p->lchild != NULL) {
            p = p->lchild;
        } else {
            // 从左子树返回的结点第二次被访问,要输出
            printf("%c ", p->data);
            
            // 若当前结点属于右分支，返回到父结点后要跳过父结点
            while(p->rchild == NULL) {
                // 从右子树返回的结点第三次被访问，不输出
                while(p->parent != NULL && p->parent->rchild == p) {
                    p = p->parent;
                }
                
                if(p->parent != NULL) {
                    // 若当前结点属于左分支，返回到父结点后要访问父结点
                    if(p->parent->lchild == p) {
                        p = p->parent;
                        printf("%c ", p->data); // 同样返回自左子树
                    }
                } else {
                    printf("\n");
                    
                    // 从右子树返回到根结点时，遍历完成
                    return;
                }
            }
            
            p = p->rchild;
        }
    }
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
        CreateTree(&(*T)->lchild, *T, fp);
        CreateTree(&(*T)->rchild, *T, fp);
    }
}

// 以图形化形式输出当前二叉树
void PrintGraph(BiTree T) {
    BiTree p = T;
    int i = 1;
    
    while(p != NULL) {
        // 从左子树返回的结点第二次被访问,要输出
        printf("%c ", p->data);
        i++;
        
        // 第一次访问结点，向左访问
        if(p->lchild != NULL) {
            p = p->lchild;
        } else {
            printf("^\n");
            
            // 若当前结点属于右分支，返回到父结点后要跳过父结点
            while(p->rchild == NULL) {
                printf("%*c^\n", 2 * (i - 1), ' ');
                i--;
                
                // 从右子树返回的结点第三次被访问，不输出
                while(p->parent != NULL && p->parent->rchild == p) {
                    p = p->parent;
                    i--;
                }
                
                if(p->parent != NULL) {
                    // 若当前结点属于左分支，返回到父结点后要访问父结点
                    if(p->parent->lchild == p) {
                        p = p->parent;
                    }
                } else {
                    printf("\n");
                    
                    // 从右子树返回到根结点时，遍历完成
                    return;
                }
            }
            
            printf("%*c", 2 * (i - 1), ' ');
            p = p->rchild;
        }
    }
}
