/*=======================
 * 二叉树的三叉链表存储结构
 ========================*/

#include "BiTriTree.h"
#include "LinkQueue.h"  //**▲03 栈和队列**//
#include "SqStack.h"    //**▲03 栈和队列**//

/*
 * 初始化
 *
 * 构造空二叉树。
 */
Status InitBiTree(BiTriTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    *T = NULL;
    
    return OK;
}

/*
 * 销毁
 *
 * 释放二叉树所占内存。
 *
 *【注】
 * 二叉树的三叉链表存储结构可以销毁，但是没必要销毁。
 * 因为三叉链表销毁后的状态与置空后的状态是一致的。
 */
Status DestroyBiTree(BiTriTree* T) {
    // 无需销毁，使用置空就可以
    return ERROR;
}

/*
 * 置空
 *
 * 清理二叉树中的数据，使其成为空树。
 */
Status ClearBiTree(BiTriTree* T) {
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
Status CreateBiTree(BiTriTree* T, char* path) {
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
Status BiTreeEmpty(BiTriTree T) {
    return T == NULL ? TRUE : FALSE;
}

/*
 * 树深
 *
 * 返回二叉树的深度（层数）。
 */
int BiTreeDepth(BiTriTree T) {
    int LD, RD;
    
    if(T == NULL) {
        return 0;                       // 空树深度为0
    } else {
        LD = BiTreeDepth(T->lchild);    // 求左子树深度
        RD = BiTreeDepth(T->rchild);    // 求右子树深度
        
        return (LD >= RD ? LD : RD) + 1;
    }
}

/*
 * 取值
 *
 * 返回二叉树中指定结点的值。
 */
TElemType Value(BiTriTree T, TElemType e) {
    BiTriTree p;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
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
 * 为二叉树指定的结点赋值。
 */
Status Assign(BiTriTree T, TElemType e, TElemType value) {
    BiTriTree p;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
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
 * 返回二叉树的根结点。
 */
TElemType Root(BiTriTree T) {
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    return T->data;
}

/*
 * 双亲
 *
 * 返回二叉树中结点e的双亲结点。
 */
TElemType Parent(BiTriTree T, TElemType e) {
    BiTriTree p;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的指针
    p = EPtr(T, e);
    
    // 如果没有找到元素e
    if(p == NULL || p->parent==NULL) {
        return '\0';
    } else {
        return p->parent->data;
    }
}

/*
 * 左孩子
 *
 * 返回二叉树中结点e的左孩子结点。
 */
TElemType LeftChild(BiTriTree T, TElemType e) {
    BiTriTree p;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的指针
    p = EPtr(T, e);
    
    // 如果找到了元素e
    if(p != NULL && p->lchild != NULL) {
        return p->lchild->data;
    }
    
    return '\0';
}

/*
 * 右孩子
 *
 * 返回二叉树中结点e的右孩子结点。
 */
TElemType RightChild(BiTriTree T, TElemType e) {
    BiTriTree p;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的指针
    p = EPtr(T, e);
    
    // 如果找到了元素e
    if(p != NULL && p->rchild != NULL) {
        return p->rchild->data;
    }
    
    return '\0';
}

/*
 * 左兄弟
 *
 * 返回二叉树中结点e的左兄弟结点。
 */
TElemType LeftSibling(BiTriTree T, TElemType e) {
    BiTriTree p;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的指针
    p = EPtr(T, e);
    
    // 如果找到了元素e的双亲
    if(p != NULL && p->parent!=NULL && p->parent->lchild != NULL) {
        return p->parent->lchild->data;
    }
    
    return '\0';
}

/*
 * 右兄弟
 *
 * 返回二叉树中结点e的右兄弟结点。
 */
TElemType RightSibling(BiTriTree T, TElemType e) {
    BiTriTree p;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的指针
    p = EPtr(T, e);
    
    // 如果找到了元素e的双亲
    if(p != NULL && p->parent!=NULL && p->parent->rchild != NULL) {
        return p->parent->rchild->data;
    }
    
    return '\0';
}

/*
 * 插入
 *
 * 已知c为与T不相交的非空二叉树，且c的右子树为空，
 * 根据LR的取值(0或1)，将c插入为T中结点p的左子树/右子树，
 * 并且，将p结点原有的左子树/右子树嫁接为二叉树c的右子树。
 */
Status InsertChild(BiTriTree T, TElemType p, int LR, BiTriTree c) {
    BiTriTree p_ptr;
    
    // 如果待插入的树为空树则无需继续计算
    if(BiTreeEmpty(c)) {
        return ERROR;
    }
    
    // 获取结点p的指针
    p_ptr = EPtr(T, p);
    
    // 如果p结点不存在，则返回错误提示
    if(p_ptr == NULL) {
        return ERROR;
    }
    
    // 将c插入为p的左子树
    if(LR==0) {
        // 如果p处存在左子树，则摘下p的左子树，插入为c的右子树
        if(p_ptr->lchild!=NULL) {
            c->rchild = p_ptr->lchild;
            p_ptr->lchild->parent = c;
        }
        
        p_ptr->lchild = c;
        c->parent = p_ptr;
    } else {
        // 如果p处存在右子树，则摘下p的右子树，插入为c的右子树
        if(p_ptr->rchild!=NULL) {
            c->rchild = p_ptr->rchild;
            p_ptr->rchild->parent = c;
        }
    
        p_ptr->rchild = c;
        c->parent = p_ptr;
    }
    
    return OK;
}

/*
 * 删除
 *
 * 根据LR的取值(0或1)，删除结点p的左子树/右子树。
 */
Status DeleteChild(BiTriTree T, TElemType p, int LR) {
    BiTriTree p_ptr;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return ERROR;
    }
    
    // 获取结点p的指针
    p_ptr = EPtr(T, p);
    
    // 如果p结点不存在，则返回错误提示
    if(p_ptr == NULL) {
        return ERROR;
    }
    
    // 如果需要删除p的左子树
    if(LR == 0) {
        ClearBiTree(&(p_ptr->lchild));
        
        // 如果需要删除p的右子树
    } else {
        ClearBiTree(&(p_ptr->rchild));
    }
    
    return OK;
}

/*
 * ████████ 算法6.1 ████████
 *
 * 先序遍历
 */
Status PreOrderTraverse(BiTriTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = PreTraverse(T, Visit);
    printf("\n");
    
    return status;
}

/*
 * 中序遍历
 */
Status InOrderTraverse(BiTriTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = InTraverse(T, Visit);
    printf("\n");
    
    return status;
}

/*
 * 后序遍历
 */
Status PostOrderTraverse(BiTriTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = PostTraverse(T, Visit);
    printf("\n");
    
    return status;
}

/*
 * 层序遍历
 */
Status LevelOrderTraverse(BiTriTree T, Status(Visit)(TElemType)) {
    LinkQueue Q;
    BiTriTree e;
    
    // 二叉树为空
    if(T == NULL) {
        printf("\n");
        return OK;
    }
    
    // 借助队列实现层序遍历
    InitQueue(&Q);
    
    // 根指针入队
    EnQueue(&Q, T);
    
    // 一直循环，直到队列为空
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &e);
        
        // 访问元素
        if(!Visit(e->data)) {
            return ERROR;
        }
        
        // 左孩子入队
        if(e->lchild != NULL) {
            EnQueue(&Q, e->lchild);
        }
        
        // 右孩子入队
        if(e->rchild != NULL) {
            EnQueue(&Q, e->rchild);
        }
    }
    
    printf("\n");
    
    return OK;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建二叉树的内部函数
static void CreateTree(BiTriTree* T, FILE* fp) {
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
        *T = (BiTriTree) malloc(sizeof(BiTriTNode));
        if(!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        (*T)->parent = NULL;
        
        CreateTree(&((*T)->lchild), fp); // 创建左子树
        if((*T)->lchild != NULL) {
            (*T)->lchild->parent = *T;
        }
        
        CreateTree(&((*T)->rchild), fp); // 创建右子树
        if((*T)->rchild != NULL) {
            (*T)->rchild->parent = *T;
        }
    }
}

// 返回指向二叉树结点e的指针
static BiTriTree EPtr(BiTriTree T, TElemType e) {
    BiTriTree pl, pr;
    
    if(T == NULL) {
        return NULL;
    }
    
    // 如果找到了目标结点，直接返回其指针
    if(T->data == e) {
        return T;
    }
    
    // 在左子树中查找e
    pl = EPtr(T->lchild, e);
    if(pl != NULL) {
        return pl;
    }
    
    // 在右子树中查找e
    pr = EPtr(T->rchild, e);
    if(pr != NULL) {
        return pr;
    }
    
    return NULL;
}

// 先序遍历的内部实现
static Status PreTraverse(BiTriTree T, Status(Visit)(TElemType)) {
    if(T) {
        if(Visit(T->data)) {
            if(PreTraverse(T->lchild, Visit)) {
                if(PreTraverse(T->rchild, Visit)) {
                    return OK;
                }
            }
        }
        
        return ERROR;
    
        // 遇到空树则无需继续计算
    } else {
        return OK;
    }
}

// 中序遍历的内部实现
static Status InTraverse(BiTriTree T, Status(Visit)(TElemType)) {
    if(T) {
        if(InTraverse(T->lchild, Visit)) {
            if(Visit(T->data)) {
                if(InTraverse(T->rchild, Visit)) {
                    return OK;
                }
            }
        }
        
        return ERROR;
        
        // 遇到空树则无需继续计算
    } else {
        return OK;
    }
}

// 后序遍历的内部实现
static Status PostTraverse(BiTriTree T, Status(Visit)(TElemType)) {
    if(T) {
        if(PostTraverse(T->lchild, Visit)) {
            if(PostTraverse(T->rchild, Visit)) {
                if(Visit(T->data)) {
                    return OK;
                }
            }
        }
        
        return ERROR;
        
        // 遇到空树则无需继续计算
    } else {
        return OK;
    }
}


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构，仅限内部测试使用
void PrintTree(BiTriTree T) {
    int level, width;
    int i, j, k, w;
    int begin;
    int distance;
    TElemType** tmp;
    LinkQueue Q;
    BiTriTree e;
    
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
