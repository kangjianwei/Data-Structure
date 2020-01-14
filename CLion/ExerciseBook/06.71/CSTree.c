/*===================================
 * 树的二叉链表（孩子-兄弟）结构存储表示
 ====================================*/

#include "CSTree.h"

/*
 * 初始化
 *
 * 构造空树。
 */
Status InitTree(CSTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    *T = NULL;
    
    return OK;
}

/*
 * 创建
 *
 * 按照预设的定义来创建树。
 * 这里约定使用【先序序列】来创建树。
 *
 *
 *【备注】
 *
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 *
 * 如果需要从控制台读取数据，则path为NULL或者为空串，
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
Status CreateTree(CSTree* T, char* path) {
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("请输入树的先序序列，如果没有孩子结点或没有兄弟节点，使用^代替：");
        Create(T, NULL);
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        Create(T, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * 判空
 *
 * 判断树是否为空树。
 */
Status TreeEmpty(CSTree T) {
    return T == NULL ? TRUE : FALSE;
}

/*
 * 树深
 *
 * 返回树的深度（层数）。
 */
int TreeDepth(CSTree T) {
    int max = 0;
    
    Depth(T, 0, &max);
    
    return max;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建树的内部函数
static void Create(CSTree* T, FILE* fp) {
    char ch;
    
    // 读取当前结点的值
    if(fp == NULL) {
        scanf("%c", &ch);
    } else {
        ReadData(fp, "%c", &ch);
    }
    
    if(ch == '^') {
        *T = NULL;
    } else {
        // 生成根结点
        *T = (CSTree) malloc(sizeof(CSNode));
        if(!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        Create(&((*T)->firstchild), fp);    // 创建长子
        Create(&((*T)->nextsibling), fp);   // 创建右兄弟
    }
}

// 计算树的深度的内部实现
static void Depth(CSTree T, int d, int* max) {
    if(T == NULL) {
        return;
    }
    
    d++;    // 指示当前所在的层数
    
    if(d > *max) {
        *max = d;
    }
    
    Depth(T->firstchild, d, max);       // 向下遍历
    Depth(T->nextsibling, --d, max);    // 向右遍历
}


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构
void PrintTree(CSTree T) {
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        printf("\n");
        return;
    }
    
    Print(T, 0);
    
    printf("\n");
}

// 图形化输出当前结构内部实现
static void Print(CSTree T, int row) {
    int k;
    
    if(T == NULL) {
        return;
    }
    
    // 访问当前结点
    printf("%c ", T->data);
    
    Print(T->firstchild, row + 1);
    
    if(T->nextsibling != NULL) {
        printf("\n");
        
        for(k = 0; k < row; k++) {
            printf(". ");
        }
        
        Print(T->nextsibling, row);
    }
}
