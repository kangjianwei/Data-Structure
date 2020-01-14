/*===================================
 * 树的二叉链表（孩子-兄弟）结构存储表示
 ====================================*/

#include "CSTree.h"
#include "LinkQueue.h"  //**▲03 栈和队列**//

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
 * 销毁
 *
 * 释放树所占内存。
 *
 *【注】
 * 与置空操作是一致的
 */
Status DestroyTree(CSTree* T) {
    // 无需销毁，使用置空就可以
    return ERROR;
}

/*
 * 置空
 *
 * 清理树中的数据，使其成为空树。
 */
Status ClearTree(CSTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    // 在*T不为空时进行递归清理
    if(*T) {
        if((*T)->firstchild != NULL) {
            ClearTree(&((*T)->firstchild));
        }
        
        if((*T)->nextsibling != NULL) {
            ClearTree(&((*T)->nextsibling));
        }
        
        free(*T);
        *T = NULL;
    }
    
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

/*
 * 取值
 *
 * 返回树中指定结点的值。
 */
TElemType Value(CSTree T, TElemType e) {
    CSTree p;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的指针
    p = EPtr(T, e);
    
    // 如果没有找到元素e
    if(p == NULL) {
        return '\0';
    } else {
        return p->data;
    }
}

/*
 * 赋值
 *
 * 为树指定的结点赋值。
 */
Status Assign(CSTree T, TElemType e, TElemType value) {
    CSTree p;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return ERROR;
    }
    
    // 获取结点e的指针
    p = EPtr(T, e);
    
    // 如果没有找到元素e
    if(p == NULL) {
        return ERROR;
    } else {
        // 进行赋值
        p->data = value;
        return OK;
    }
}

/*
 * 根
 *
 * 返回树的根结点。
 */
TElemType Root(CSTree T) {
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    return T->data;
}

/*
 * 双亲
 *
 * 返回树中结点e的双亲结点。
 */
TElemType Parent(CSTree T, TElemType e) {
    CSTree p;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的双亲结点的指针
    p = PPtr(T, e);
    
    // 如果没有找到元素e的双亲
    if(p == NULL) {
        return '\0';
    } else {
        return p->data;
    }
}

/*
 * 孩子数量
 *
 * 返回树T中结点e的孩子数量。
 */
int ChildCount(CSTree T, TElemType e) {
    CSTree p;
    int count;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return 0;
    }
    
    // 获取结点e的指针
    p = EPtr(T, e);
    
    // 如果没有找到元素e
    if(p == NULL) {
        return 0;
    }
    
    count = 0;
    
    for(p = p->firstchild; p != NULL; p = p->nextsibling) {
        count++;
    }
    
    return count;
}

/*
 * 孩子
 *
 * 返回树中结点e的第i个孩子。
 */
TElemType Child(CSTree T, TElemType e, int i) {
    CSTree p;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return 0;
    }
    
    // i的范围越界
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return '\0';
    }
    
    // 获取结点e的第i个孩子的指针
    p = CPtr(T, e, i);
    
    if(p != NULL) {
        return p->data;
    } else {
        return '\0';
    }
}

/*
 * 左兄弟
 *
 * 返回树中结点e的左兄弟结点。
 */
TElemType LeftSibling(CSTree T, TElemType e) {
    CSTree p;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的双亲结点的指针
    p = PPtr(T, e);
    
    // 如果没有找到元素e的双亲
    if(p == NULL) {
        return '\0';
    }
    
    // 遍历e的众多兄弟
    for(p = p->firstchild; p != NULL; p = p->nextsibling) {
        if(p->nextsibling != NULL && p->nextsibling->data == e) {
            return p->data;
        }
    }
    
    return '\0';
}

/*
 * 右兄弟
 *
 * 返回树中结点e的右兄弟结点。
 */
TElemType RightSibling(CSTree T, TElemType e) {
    CSTree p;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的指针
    p = EPtr(T, e);
    
    // 如果没有找到元素e的双亲
    if(p == NULL) {
        return '\0';
    }
    
    if(p->nextsibling != NULL) {
        return p->nextsibling->data;
    } else {
        return '\0';
    }
}

/*
 * 插入
 *
 * 将树c插入为树T中p结点的第i个孩子。
 */
Status InsertChild(CSTree* T, TElemType p, int i, CSTree c) {
    CSTree r;
    
    // 如果树为空树则无需继续计算
    if(TreeEmpty(*T) || TreeEmpty(c)) {
        return ERROR;
    }
    
    // i的范围过于小
    if(i < 1) {
        return ERROR;
    }
    
    // 插入为第一棵子树
    if(i == 1) {
        r = (*T)->firstchild;
        (*T)->firstchild = c;
        c->nextsibling = r;
    } else {
        // 获取结点p的第i-1个孩子的指针
        r = CPtr(*T, p, i - 1);
        if(r == NULL) {
            return ERROR;
        }
        
        c->nextsibling = r->nextsibling;
        r->nextsibling = c;
    }
    
    return OK;
}

/*
 * 删除
 *
 * 删除树T中p结点的第i个孩子。
 */
Status DeleteChild(CSTree* T, TElemType p, int i) {
    CSTree r, q;
    
    // 如果待删除的树为空树则无需继续计算
    if(TreeEmpty(*T)) {
        return ERROR;
    }
    
    // i的范围越界（初步判断）
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return ERROR;
    }
    
    // 删除第一个孩子（及其子树）
    if(i == 1) {
        // 树结点p的指针
        r = EPtr(*T, p);
        if(r == NULL) {
            return ERROR;
        }
        
        q = r->firstchild;
        r->firstchild = q->nextsibling;
        q->nextsibling = NULL;
    } else {
        // 获取结点p的第i-1个孩子的指针
        r = CPtr(*T, p, i - 1);
        if(r == NULL) {
            return ERROR;
        }
        
        // 第i个孩子
        q = r->nextsibling;
        r->nextsibling = q->nextsibling;
        q->nextsibling = NULL;
    }
    
    ClearTree(&q);
    
    return OK;
}

/*
 * 先序遍历
 */
Status PreOrderTraverse(CSTree T, Status(Visit)(TElemType)) {
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    PreTraverse(T, Visit);
    
    printf("\n");
    
    return OK;
}

/*
 * 后序遍历
 */
Status PostOrderTraverse(CSTree T, Status(Visit)(TElemType)) {
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    PostTraverse(T, Visit);
    
    printf("\n");
    
    return OK;
}

/*
 * 层序遍历
 */
Status LevelOrderTraverse(CSTree T, Status(Visit)(TElemType)) {
    LinkQueue Q;
    QElemType p, pc;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    InitQueue(&Q);
    EnQueue(&Q, T);
    
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &p);    // 弹出的结点作为父结点
    
        if(!Visit(p->data)) {
            return ERROR;
        }
        
        // 将该结点的孩子入队
        for(pc = p->firstchild; pc != NULL; pc = pc->nextsibling) {
            EnQueue(&Q, pc);
        }
    }
    
    printf("\n");
    
    return OK;
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

// 返回树结点e的指针，如果不存在，返回NULL
static CSTree EPtr(CSTree T, TElemType e) {
    CSTree pc, ps;
    
    if(T == NULL) {
        return NULL;
    }
    
    // 如果找到了目标结点，直接返回其指针
    if(T->data == e) {
        return T;
    }
    
    // 向下查找e
    pc = EPtr(T->firstchild, e);
    if(pc != NULL) {
        return pc;
    }
    
    // 向右查找e
    ps = EPtr(T->nextsibling, e);
    if(ps != NULL) {
        return ps;
    }
    
    return NULL;
}

// 返回树结点e的双亲结点的指针，如果不存在，返回NULL
static CSTree PPtr(CSTree T, TElemType e) {
    LinkQueue Q;
    QElemType p, pc;
    
    // 根结点没有双亲
    if(T == NULL || T->data == e) {
        return NULL;
    }
    
    InitQueue(&Q);
    EnQueue(&Q, T);
    
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &p);    // 弹出的结点作为父结点
        
        // 将该结点的孩子入队
        for(pc = p->firstchild; pc != NULL; pc = pc->nextsibling) {
            if(pc->data == e) {
                return p;
            }
            
            EnQueue(&Q, pc);
        }
    }
    
    return NULL;
}

// 返回树结点e的第i个孩子的指针，如果不存在，返回NULL
static CSTree CPtr(CSTree T, TElemType e, int i) {
    CSTree p;
    int count;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return NULL;
    }
    
    // i的范围越界
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return NULL;
    }
    
    // 获取结点e的指针
    p = EPtr(T, e);
    
    // 如果没有找到元素e
    if(p == NULL) {
        return NULL;
    }
    
    p = p->firstchild;
    count = 1;
    
    while(p != NULL && count < i) {
        p = p->nextsibling;
        count++;
    }
    
    if(p != NULL) {
        return p;
    } else {
        return NULL;
    }
}

// 先序遍历的内部实现
static Status PreTraverse(CSTree T, Status(Visit)(TElemType)) {
    CSTree firstChild;
    CSTree rightBrother;
    
    // 访问当前结点
    if(!Visit(T->data)) {
        return ERROR;
    }
    
    firstChild = T->firstchild;
    
    // 遍历长子（需要先确定长子的身份）
    if(firstChild != NULL && !PreTraverse(T->firstchild, Visit)) {
        return ERROR;
    }
    
    rightBrother = T->nextsibling;
    
    // 遍历右兄弟（需要先确定右兄弟的身份）
    if(rightBrother != NULL && !PreTraverse(rightBrother, Visit)) {
        return ERROR;
    }
    
    return OK;
}

// 后序遍历的内部实现
static Status PostTraverse(CSTree T, Status(Visit)(TElemType)) {
    CSTree firstChild;
    CSTree rightBrother;
    
    firstChild = T->firstchild;
    
    // 遍历长子（需要先确定长子的身份）
    if(firstChild != NULL && !PostTraverse(T->firstchild, Visit)) {
        return ERROR;
    }
    
    // 访问当前结点
    if(!Visit(T->data)) {
        return ERROR;
    }
    
    rightBrother = T->nextsibling;
    
    // 遍历右兄弟（需要先确定右兄弟的身份）
    if(rightBrother != NULL && !PostTraverse(rightBrother, Visit)) {
        return ERROR;
    }
    
    return OK;
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
