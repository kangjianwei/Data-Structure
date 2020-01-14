#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "CSTree.h"     //**▲06 树和二叉树**//

/*
 * 先序遍历按凹入表打印树
 * 方法1：直接使用递归，i初始设为0
 */
void Algo_6_71_1(CSTree T, int i);

/*
 * 先序遍历按凹入表打印树
 * 方法2：在循环中使用递归，i初始设为0
 */
void Algo_6_71_2(CSTree T, int i);


int main(int argc, char* argv[]) {
    CSTree T;
    
    printf("创建树（先序序列）T...\n");
    InitTree(&T);
    CreateTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("方法 1：先序遍历按凹入表打印树：\n");
    Algo_6_71_1(T, 0);
    printf("\n");
    
    printf("方法 2：先序遍历按凹入表打印树：\n");
    Algo_6_71_2(T, 0);
    printf("\n");
    
    return 0;
}


/*
 * 先序遍历按凹入表打印树
 * 方法1：直接使用递归，i初始设为0
 */
void Algo_6_71_1(CSTree T, int i) {
    int j;
    
    if(!T) {
        return;
    }
    
    for(j = 1; j <= 2 * i; j++) {
        printf(" ");
    }
    printf("%c\n", T->data);
    
    Algo_6_71_1(T->firstchild, i + 1);
    Algo_6_71_1(T->nextsibling, i);     // 此处为i
}

/*
 * 先序遍历按凹入表打印树
 * 方法2：在循环中使用递归，i初始设为0
 */
void Algo_6_71_2(CSTree T, int i) {
    int j;
    CSTree p;
    
    if(!T) {
        return;
    }
    
    for(j = 1; j <= 2 * i; j++) {
        printf(" ");
    }
    printf("%c\n", T->data);
    
    // 遍历孩子结点
    for(p = T->firstchild; p; p = p->nextsibling) {
        Algo_6_71_2(p, i + 1);
    }
}
