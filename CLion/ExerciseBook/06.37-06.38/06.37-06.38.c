#include <stdio.h>
#include "Status.h"     //**01 绪论**//
#include "SqStack.h"    //**03 栈和队列**//
#include "BiTree.h"     //**06 树和二叉树**//

/*
 * 先序遍历的非递归形式
 */
Status Algo_6_37(BiTree T);

/*
 * 后序遍历的非递归形式
 */
Status Algo_6_38(BiTree T);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("创建二叉树 T ：...\n");
    CreateBiTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("███题 6.37 验证...███\n");
    {
        printf("二叉树先序遍历序列为：");
        Algo_6_37(T);
        printf("\n");
    }
    
    printf("███题 6.38 验证...███\n");
    {
        printf("二叉树后序遍历序列为：");
        Algo_6_38(T);
        printf("\n");
    }
    
    return 0;
}


/*
 * 先序遍历的非递归形式
 */
Status Algo_6_37(BiTree T) {
    SqStack S;
    SElemType e;
    
    if(BiTreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    InitStack(&S);
    Push(&S, T);
    
    while(!StackEmpty(S)) {
        GetTop(S, &e);
        printf("%c ", e->data);
        
        if(e->lchild) {
            Push(&S, e->lchild);
        } else {
            while(!StackEmpty(S)) {
                Pop(&S, &e);
                
                if(e->rchild) {
                    Push(&S, e->rchild);
                    break;
                }
            }
        }
    }
    
    printf("\n");
    return OK;
}

/*
 * 后序遍历的非递归形式
 */
Status Algo_6_38(BiTree T) {
    SqStack S;
    BiTree p;
    SElemType e;
    int StackMark[100] = {0};    // 标记栈，设置各结点访问标记（初始化为0）
    int k;
    
    if(BiTreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    InitStack(&S);
    p = T;
    k = -1;
    
    while(TRUE) {
        while(p) {
            Push(&S, p);
            k++;
            StackMark[k] = 1;   // 设置第一次访问的标记
            p = p->lchild;
        }
        
        // p为空但栈不为空
        while(!p && !StackEmpty(S)) {
            GetTop(S, &p);
            
            // 已访问过一次，当前是第二次访问
            if(StackMark[k] == 1) {
                StackMark[k] = 2;
                p = p->rchild;
                
                // 已访问过两次，当前是第三次访问
            } else {
                printf("%c ", p->data);
                Pop(&S, &e);
                StackMark[k] = 0;
                k--;
                p = NULL;
            }
        }
        
        if(StackEmpty(S)) {
            break;
        }
    }
    
    printf("\n");
    return OK;
}
