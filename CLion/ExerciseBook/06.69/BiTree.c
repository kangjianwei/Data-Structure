/*=============================
 * 二叉树的二叉链表存储结构
 *
 * 包含算法: 6.1、6.2、6.3、6.4
 =============================*/

#include "BiTree.h"
#include "LinkQueue.h"  //**▲03 栈和队列**//

/*
 * 初始化
 *
 * 构造空二叉树。
 */
Status InitBiTree(BiTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    *T = NULL;
    
    return OK;
}

/*
 * 置空
 *
 * 清理二叉树中的数据，使其成为空树。
 */
Status ClearBiTree(BiTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    // 在*T不为空时进行递归清理
    if(*T) {
        if((*T)->lchild!=NULL) {
            ClearBiTree(&((*T)->lchild));
        }
        
        if((*T)->rchild!=NULL) {
            ClearBiTree(&((*T)->rchild));
        }
        
        free(*T);
        *T = NULL;
    }
    
    return OK;
}

/*
 * ████████ 算法6.4 ████████
 *
 * 创建
 *
 * 按照预设的定义来创建二叉树。
 * 这里约定使用【先序序列】来创建二叉树。
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
Status CreateBiTree(BiTree* T, char* path) {
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("请输入二叉树的先序序列，如果没有子结点，使用^代替：");
        CreateTree(T, NULL);
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        CreateTree(T, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * 判空
 *
 * 判断二叉树是否为空树。
 */
Status BiTreeEmpty(BiTree T) {
    return T == NULL ? TRUE : FALSE;
}

/*
 * 树深
 *
 * 返回二叉树的深度（层数）。
 */
int BiTreeDepth(BiTree T) {
    int LD, RD;
    
    if(T == NULL) {
        return 0;                       // 空树深度为0
    } else {
        LD = BiTreeDepth(T->lchild);    // 求左子树深度
        RD = BiTreeDepth(T->rchild);    // 求右子树深度
        
        return (LD >= RD ? LD : RD) + 1;
    }
}


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建二叉树的内部函数
static void CreateTree(BiTree* T, FILE* fp) {
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
        *T = (BiTree) malloc(sizeof(BiTNode));
        if(!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        CreateTree(&((*T)->lchild), fp); // 创建左子树
        CreateTree(&((*T)->rchild), fp); // 创建右子树
    }
}


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构，仅限内部测试使用
void PrintTree(BiTree T) {
    int level, width;
    int i, j, k, w;
    int begin;
    int distance;
    TElemType** tmp;
    LinkQueue Q;
    BiTree e;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        printf("\n");
        return;
    }
    
    level = BiTreeDepth(T);         // （完全）二叉树结构高度
    width = (int)pow(2, level)-1;   // （完全）二叉树结构宽度
    
    // 动态创建行
    tmp = (TElemType**)malloc(level* sizeof(TElemType*));
    
    // 动态创建列
    for(i = 0; i < level; i++) {
        tmp[i] = (TElemType*)malloc(width* sizeof(TElemType));
        
        // 初始化内存值为空字符
        memset(tmp[i], '\0', width);
    }
    
    // 借助队列实现层序遍历
    InitQueue(&Q);
    EnQueue(&Q, T);
    
    // 遍历树中所有元素，将其安排到二维数组tmp中合适的位置
    for(i = 0; i < level; i++) {
        w        = (int) pow(2, i);             // 二叉树当前层的宽度
        distance = width / w;                   // 二叉树当前层的元素间隔
        begin    = width / (int) pow(2, i + 1); // 二叉树当前层首个元素之前的空格数
        
        for(k = 0; k < w; k++) {
            DeQueue(&Q, &e);
            
            if(e == NULL) {
                EnQueue(&Q, NULL);
                EnQueue(&Q, NULL);
            } else {
                j = begin + k * (1 + distance);
                tmp[i][j] = e->data;
                
                // 左孩子入队
                EnQueue(&Q, e->lchild);
                
                // 右孩子入队
                EnQueue(&Q, e->rchild);
            }
        }
    }
    
    for(i = 0; i < level; i++) {
        for(j = 0; j < width; j++) {
            if(tmp[i][j] != '\0') {
                printf("%c", tmp[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
