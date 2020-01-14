#include <stdio.h>
#include "CTree.h"      //**▲06 树和二叉树**//

/*
 * 先序遍历按凹入表打印树
 * 方法1：直接使用递归，i初始设为0
 */
void Algo_6_72_1(CTree T, int order, int i);

/*
 * 先序遍历按凹入表打印树
 * 方法2：在循环中使用递归，i初始设为0
 */
void Algo_6_72_2(CTree T, int order, int i);


int main(int argc, char* argv[]) {
    CTree T;
    
    printf("创建树T...\n");
    InitTree(&T);
    CreateTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("先序遍历按凹入表打印树：\n");
    Algo_6_72_1(T, T.r, 0);
    printf("\n");
    
    printf("先序遍历按凹入表打印树：\n");
    Algo_6_72_2(T, T.r, 0);
    printf("\n");
    
    return 0;
}


/*
 * 先序遍历按凹入表打印树
 * 方法1：直接使用递归，i初始设为0
 */
void Algo_6_72_1(CTree T, int order, int i) {
    int j, k;
    
    if(!T.n) {
        return;
    }
    
    for(j = 1; j <= 2 * i; j++) {
        printf(" ");
    }
    printf("%c\n", T.nodes[order].data);
    
    // 访问孩子结点
    if(T.nodes[order].firstchild) {
        Algo_6_72_1(T, T.nodes[order].firstchild->child, i + 1);
    }
    
    // 获取结点order的右结点的位置
    k = (order + 1) % MAX_TREE_SIZE;
    
    // 如果存在右兄弟
    if(T.nodes[order].parent == T.nodes[k].parent) {
        // 访问右兄弟结点
        Algo_6_72_1(T, k, i);
    }
}

/*
 * 先序遍历按凹入表打印树
 * 方法2：在循环中使用递归，i初始设为0
 */
void Algo_6_72_2(CTree T, int order, int i) {
    int j;
    ChildPtr p;
    
    if(!T.n) {
        return;
    }
    
    for(j = 1; j <= 2 * i; j++) {
        printf(" ");
    }
    printf("%c\n", T.nodes[order].data);
    
    // 遍历孩子结点
    for(p = T.nodes[order].firstchild; p; p = p->next) {
        Algo_6_72_2(T, p->child, i + 1);
    }
}
