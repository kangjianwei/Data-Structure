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
 * 创建
 *
 * 按照预设的定义来创建树。
 * 这里约定使用【层序序列】来创建树。
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
Status CreateTree(CTree* T, char* path) {
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("请输入树的元素信息，对于空结点，使用^代替...\n");
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

// 创建树的内部函数
static void Create(CTree* T, FILE* fp) {
    int r;          // 树的根结点的位置（索引）
    int n;          // 记录元素数量
    int cur;        // 游标
    TElemType ch;
    LinkQueue Q;
    QElemType e;    // 队列元素指示结点的位置
    char s[MAX_CHILD_COUNT + 1];
    int i;
    ChildPtr p, pc;
    
    InitQueue(&Q);
    
    n = 0;
    
    // 读取根结点的位置
    if(fp == NULL) {
        printf("请输入根结点的位置(0~%d)：", MAX_TREE_SIZE - 1);
        scanf("%d", &r);
        cur = r;
        
        printf("请输入根结点的值：");
        scanf("%s", s);
        ch = s[0];
        
        // 树根入队
        EnQueue(&Q, cur);
        T->nodes[cur].data = ch;
        T->nodes[cur].parent = -1;
        T->nodes[cur].firstchild = NULL;
        cur = (cur + 1) % MAX_TREE_SIZE;
        n++;
        
        while(!QueueEmpty(Q)) {
            DeQueue(&Q, &e);    // 父结点的位置出队
            
            printf("请依次输入 %c 的孩子结点，不存在孩子时输入一个^：", T->nodes[e].data);
            scanf("%s", s);
            for(i = 0; i < strlen(s); i++) {
                if(s[i] == '^') {
                    break;
                }
                
                EnQueue(&Q, cur); // 当前结点位置入队
                T->nodes[cur].data = s[i];
                T->nodes[cur].parent = e;
                T->nodes[cur].firstchild = NULL;
                
                // 父结点的长子
                p = T->nodes[e].firstchild;
                
                // 包装当前结点
                pc = (ChildPtr) malloc(sizeof(CTNode));
                pc->child = cur;
                pc->next = NULL;
                
                // 将当前结点添加到父结点的孩子链表中
                if(p == NULL) {
                    T->nodes[e].firstchild = pc;
                } else {
                    // 找到链表尾部
                    while(p->next != NULL) {
                        p = p->next;
                    }
                    
                    p->next = pc;
                }
                
                cur = (cur + 1) % MAX_TREE_SIZE;
                n++;
            }
        }
    } else {
        // 录入根结点的位置
        ReadData(fp, "%d", &r);
        cur = r;
        
        // 录入根结点的值
        ReadData(fp, "%s", s);
        ch = s[0];
        printf("录入根结点的值：%c\n", ch);
        
        // 树根入队
        EnQueue(&Q, cur);
        T->nodes[cur].data = ch;
        T->nodes[cur].parent = -1;
        T->nodes[cur].firstchild = NULL;
        cur = (cur + 1) % MAX_TREE_SIZE;
        n++;
        
        while(!QueueEmpty(Q)) {
            ReadData(fp, "%s", s);
            ch = s[0];
            printf("依次录入 %c 结点的孩子：", ch);
            
            // 录入孩子结点
            ReadData(fp, "%s", s);
            printf("%s\n", s);
            
            DeQueue(&Q, &e);    // 父结点位置出队
            
            // 遍历孩子
            for(i = 0; i < strlen(s); i++) {
                if(s[i] == '^') {
                    break;
                }
                
                EnQueue(&Q, cur); // 当前结点位置入队
                T->nodes[cur].data = s[i];
                T->nodes[cur].parent = e;
                T->nodes[cur].firstchild = NULL;
                
                // 包装当前结点
                pc = (ChildPtr) malloc(sizeof(CTNode));
                pc->child = cur;
                pc->next = NULL;
                
                // 父结点的长子
                p = T->nodes[e].firstchild;
                
                // 将当前结点添加到父结点的孩子链表中
                if(p == NULL) {
                    T->nodes[e].firstchild = pc;
                } else {
                    // 找到链表尾部
                    while(p->next != NULL) {
                        p = p->next;
                    }
                    
                    p->next = pc;
                }
                
                cur = (cur + 1) % MAX_TREE_SIZE;
                n++;
            }
        }
    }
    
    T->r = r;
    T->n = n;
}

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
