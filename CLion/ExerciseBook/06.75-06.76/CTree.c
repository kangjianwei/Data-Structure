/*=============================
 * 树的孩子链表(带双亲)的存储表示
 =============================*/

#include "CTree.h"

/*
 * 初始化
 *
 * 构造空树。
 */
Status InitTree(CTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    T->n = 0;
    
    // 所有数据清零
    memset(T->nodes, 0, sizeof(T->nodes));
    
    return OK;
}

/*
 * 判空
 *
 * 判断树是否为空树。
 */
Status TreeEmpty(CTree T) {
    return T.n == 0 ? TRUE : FALSE;
}

/*
 * 树深
 *
 * 返回树的深度（层数）。
 */
int TreeDepth(CTree T) {
    int k, level;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return 0;
    }
    
    /*
     * 将k初始化为最后一个结点的位置
     * 由于树的结点按层序存储，故最后存储的结点必定位于最大层
     */
    k = (T.r + T.n - 1) % MAX_TREE_SIZE;
    level = 0;
    
    do {
        level++;
        k = T.nodes[k].parent;
    } while(k != -1);
    
    return level;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 获取树T的结点信息，具体包含哪些信息，请参照Pos类型的定义
static void getPos(CTree T, Pos pt[]) {
    LinkQueue Q;
    QElemType e;
    ChildPtr cp;
    
    int level, n, count;
    
    memset(pt, 0, MAX_TREE_SIZE * sizeof(Pos));
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return;
    }
    
    InitQueue(&Q);
    
    // 根结点的位置入队
    EnQueue(&Q, T.r);
    pt[T.r].row = 1;
    pt[T.r].col = 1;
    pt[T.r].childIndex = 1;
    
    // 父结点所在的层
    level = 0;
    
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &e);
        
        // 如果行数发生了改变
        if(pt[e].row != level) {
            count = 0;
            level = pt[e].row;
        }
        
        n = 0;  // 结点e的孩子计数归0
        
        // 每个结点出队时，先设置其最后一个孩子信息为无效，因为不是每个结点都有孩子结点
        pt[e].lastChild = -1;
        
        // 指向该结点的孩子链表
        cp = T.nodes[e].firstchild;
        
        // 释放该结点处的孩子链表所占内存
        while(cp != NULL) {
            // 当前结点位置入队
            EnQueue(&Q, cp->child);
            
            // 记录行数
            pt[cp->child].row = pt[e].row + 1;
            
            // 记录列数
            pt[cp->child].col = ++count;
            
            // 记录当前结点是第几个孩子
            pt[cp->child].childIndex = ++n;
            
            // 为父结点跟新最后一个孩子的信息
            pt[e].lastChild = cp->child;
            
            cp = cp->next;
        }
    }
}


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构
void PrintTree(CTree T) {
    Pos pt[MAX_TREE_SIZE];
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        printf("\n");
        return;
    }
    
    // 计算T中结点的位置信息
    getPos(T, pt);
    
    Print(T, pt, T.r);
    
    printf("\n");
    
    printf("存储结构：\n");
    PrintFramework(T);
}

// 图形化输出当前结构内部实现
static void Print(CTree T, Pos pt[], int i) {
    int firstChild = -1;    // 初始化为无效的索引
    int rightBrother;
    int k;
    
    // 访问当前结点
    printf("%c ", T.nodes[i].data);
    
    // 相比双亲表存储结构，求长子更容易了
    if(T.nodes[i].firstchild!=NULL) {
        firstChild = T.nodes[i].firstchild->child;
    }
    
    // 遍历长子（需要先确定长子的身份）
    if(firstChild != -1) {
        Print(T, pt, firstChild);
    }
    
    rightBrother = (i + 1) % MAX_TREE_SIZE;
    
    // 遍历右兄弟（需要先确定右兄弟的身份）
    if(rightBrother != (T.r + T.n) % MAX_TREE_SIZE && T.nodes[i].parent == T.nodes[rightBrother].parent) {
        // 访问当前结点的右兄弟前，如果当前结点不是最后一个孩子，则进行一次换行
        if(pt[T.nodes[i].parent].lastChild != i) {
            printf("\n");
            
            for(k = 0; k < pt[rightBrother].row - 1; k++) {
                printf(". ");
            }
        }
        
        Print(T, pt, rightBrother);
    }
}

// 图形化输出树的排列结构，仅限内部测试使用
static void PrintFramework(CTree T) {
    int k;
    ChildPtr cp;
    
    if(T.n == 0) {
        return;
    }
    
    printf("+---------+-----------\n");
    printf("|  i e  p | child list\n");
    printf("+---------+-----------\n");
    
    for(k = T.r; k != (T.r + T.n) % MAX_TREE_SIZE; k = (k + 1) % MAX_TREE_SIZE) {
        
        printf("| %2d %c %2d", k, T.nodes[k].data, T.nodes[k].parent);
        
        cp = T.nodes[k].firstchild;
        if(cp != NULL) {
            printf(" ->");
        } else {
            printf(" | ");
        }
        
        while(cp != NULL) {
            printf(" %2d", cp->child);
            cp = cp->next;
        }
        
        printf("\n");
    }
    
    printf("+---------+-----------\n");
}
