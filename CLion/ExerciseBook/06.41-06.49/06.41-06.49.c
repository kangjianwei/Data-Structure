#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status.h"     //**▲01 绪论**//
#include "BiTree.h"     //**▲06 树和二叉树**//

#define MAX_TREE_DEPTH 20    // 二叉树最大层数
#define MAX_TREE_SIZE  1024  // 二叉树元素数量最大值

/*
 * 求先序序列中第k个结点的值，order用来计数。
 */
Status Algo_6_41(BiTree T, int k, int* order, TElemType* e);

/*
 * 计算二叉树中叶子结点数目
 */
int Algo_6_42(BiTree T);

/*
 * 交换二叉树的左右子树
 */
void Algo_6_43(BiTree T);

/*
 * 求二叉树中子树'x'的深度
 */
int Algo_6_44(BiTree T, TElemType x);

/*
 * 删除二叉树T中的子树x
 */
Status Algo_6_45(BiTree* T, TElemType x);

/*
 * 复制二叉树的非递归算法
 */
void Algo_6_46(BiTree T, BiTree* Tx);

/*
 * 层序遍历二叉树
 */
void Algo_6_47(BiTree T);

/*
 * 求两结点的共同祖先
 */
BiTree Algo_6_48(BiTree T, TElemType a, TElemType b);

/*
 * 判断二叉树是否为完全二叉树
 */
Status Algo_6_49(BiTree T);

/*
 * 遍历树寻找根结点到p结点的路径，path存储路径上各结点指针(不包含p结点的指针)
 */
static int FindPath(BiTree T, TElemType e, BiTree path[]);

// 返回指向二叉树结点e的指针
static BiTree EPtr(BiTree T, TElemType e);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("创建二叉树 T ...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintTree(T);
    printf("\n");
    
    printf("███题 6.41 验证...███\n");
    {
        int k = 9;
        int order = 0;  // 计数
        TElemType e;
        
        if(Algo_6_41(T, k, &order, &e)) {
            printf("先序序列中第 %d 个元素为 %c \n", k, e);
        } else {
            printf("此处元素不存在！\n");
        }
        
        printf("\n");
    }
    
    printf("███题 6.42 验证...███\n");
    {
        printf("二叉树的叶子结点个数为：%d\n", Algo_6_42(T));
        printf("\n");
    }
    
    printf("███题 6.43 验证...███\n");
    {
        printf("交换二叉树左右子树后二叉树变为：\n");
        Algo_6_43(T);
        PrintTree(T);
        printf("\n");
    }
    
    printf("███题 6.44 验证...███\n");
    {
        char x = 'E';
        
        printf("子树 %c 的深度为： %d\n", x, Algo_6_44(T, x));
        printf("\n");
    }
    
    printf("███题 6.45 验证...███\n");
    {
        char x = 'D';
        
        printf("删除子树 %c 后，二叉树为：\n", x);
        if(Algo_6_45(&T, x)) {
            PrintTree(T);
        }
        printf("\n");
    }
    
    printf("███题 6.46 验证...███\n");
    {
        BiTree Tx;
        
        printf("复制 T 到 Tx 后，二叉树Tx为：\n");
        Algo_6_46(T, &Tx);
        PrintTree(Tx);
        printf("\n");
    }
    
    printf("███题 6.47 验证...███\n");
    {
        printf("二叉树层序遍历序列为：");
        Algo_6_47(T);
        printf("\n");
    }
    
    printf("███题 6.48 验证...███\n");
    {
        BiTree Tmp = NULL;
        TElemType a = 'I';
        TElemType b = 'H';
        
        if((Tmp = Algo_6_48(T, a, b)) != NULL) {
            printf("'%c' 和 '%c' 的最近共同祖先为：'%c'\n", a, b, Tmp->data);
        }
        printf("\n");
    }
    
    printf("███题 6.49 验证...███\n");
    {
        if(Algo_6_49(T)) {
            printf("此二叉树是完全二叉树！\n");
        } else {
            printf("此二叉树不是完全二叉树!！\n");
        }
    }
    
    return 0;
}


/*
 * 求先序序列中第k个结点的值，order用来计数。
 */
Status Algo_6_41(BiTree T, int k, int* order, TElemType* e) {
    
    if(T == NULL) {
        *e = '\0';
        return ERROR;
    }
    
    (*order)++;
    
    if(*order == k) {
        *e = T->data;
        return OK;
    } else {
        if(Algo_6_41(T->lchild, k, order, e)) {
            return OK;
        }
        
        if(Algo_6_41(T->rchild, k, order, e)) {
            return OK;
        }
    }
    
    return ERROR;
}

/*
 * 计算二叉树中叶子结点数目
 */
int Algo_6_42(BiTree T) {
    int count = 0;
    
    if(T != NULL) {
        if(T->lchild == NULL && T->rchild == NULL) {
            count++;
        } else {
            count += Algo_6_42(T->lchild);  // 左子树叶子结点数量
            count += Algo_6_42(T->rchild);  // 右子树叶子结点数量
        }
    }
    
    return count;
}

/*
 * 交换二叉树的左右子树
 */
void Algo_6_43(BiTree T) {
    BiTree p;
    
    if(T != NULL) {
        p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
        
        // 递归交换
        Algo_6_43(T->lchild);
        Algo_6_43(T->rchild);
    }
}

/*
 * 求二叉树T中子树'x'的深度
 */
int Algo_6_44(BiTree T, TElemType x) {
    BiTree p;
    
    p = EPtr(T, x);         // 第一个递归求出x的位置，以指针形式返回
    
    return BiTreeDepth(p);  // 第二个递归求出子树x的深度
}

/*
 * 删除二叉树T中的子树x
 */
Status Algo_6_45(BiTree* T, TElemType x) {
    
    if(*T == NULL) {
        return ERROR;
    }
    
    // 如果找到了该结点，则递归清空子树
    if((*T)->data == x) {
        ClearBiTree(T);
        return OK;
        // 递归向左右子树寻找该结点
    } else {
        if(Algo_6_45(&((*T)->lchild), x)) {
            return OK;
        }
        
        if(Algo_6_45(&((*T)->rchild), x)) {
            return OK;
        }
        
        return ERROR;
    }
}

/*
 * 复制二叉树的非递归算法
 */
void Algo_6_46(BiTree T, BiTree* Tx) {
    int front, rear;
    BiTree queue[MAX_TREE_SIZE] = {NULL};   // 树指针数组，用来模拟队列，初始化元素为NULL
    BiTree tree[MAX_TREE_SIZE];     // 新建的二叉树
    BiTree p;
    int parent;
    
    if(T == NULL) {
        *Tx = NULL;
        return;
    }
    
    front = rear = 0;
    
    queue[rear] = T;
    
    while(front <= rear) {
        p = queue[front];
        
        if(p == NULL) {
            front++;
            continue;
        }
        
        // 创建新结点
        tree[front] = (BiTree) malloc(sizeof(BiTNode));
        tree[front]->data = p->data;
        tree[front]->lchild = tree[front]->rchild = NULL;
        
        // 为该结点挂接在父结点上
        if(front > 0) {
            parent = (front - 1) / 2;
            
            // 如果当前结点作为左孩子
            if(2 * parent + 1 == front) {
                tree[parent]->lchild = tree[front];
            } else {
                tree[parent]->rchild = tree[front];
            }
        }
        
        if(p->lchild != NULL) {
            rear = 2 * front + 1;
            queue[rear] = p->lchild;
        }
        
        if(p->rchild != NULL) {
            rear = 2 * front + 2;
            queue[rear] = p->rchild;
        }
        
        front++;
    }
    
    *Tx = tree[0];
}

/*
 * 层序遍历二叉树
 */
void Algo_6_47(BiTree T) {
    int front, rear;
    BiTree queue[MAX_TREE_SIZE];  // 树指针数组，用来模拟队列
    BiTree p;
    
    if(T == NULL) {
        return;
    }
    
    front = rear = 0;
    
    queue[rear++] = T;
    
    while(front != rear) {
        p = queue[front++];
        
        printf("%c ", p->data);
        
        if(p->lchild != NULL) {
            queue[rear++] = p->lchild;
        }
        
        if(p->rchild != NULL) {
            queue[rear++] = p->rchild;
        }
    }
    
    printf("\n");
}

/*
 * 求两结点的共同祖先
 */
BiTree Algo_6_48(BiTree T, TElemType a, TElemType b) {
    BiTree pa[MAX_TREE_DEPTH] = {NULL};
    BiTree pb[MAX_TREE_DEPTH] = {NULL};
    int lenA, lenB;
    int i, j;
    
    // 借助于路径寻找函数
    if((lenA = FindPath(T, a, pa)) != 0 && (lenB = FindPath(T, b, pb)) != 0) {
        for(i = lenA - 1; pa[i] != NULL; i--) {
            for(j = lenB - 1; pb[j] != NULL; j--) {
                if(pa[i]->data == pb[j]->data) {
                    return pa[i];
                }
            }
        }
    }
    
    return NULL;
}

/*
 * 判断二叉树是否为完全二叉树
 *
 * 完全二叉树的特点是层序遍历时序号与满二叉树一致
 */
Status Algo_6_49(BiTree T) {
    int front, rear;
    BiTree queue[MAX_TREE_SIZE];     // 树指针数组，模拟队列
    int order[MAX_TREE_SIZE];
    BiTree p;
    int count;
    
    if(T == NULL) {
        return OK;
    }
    
    front = rear = 0;
    count = 1;
    
    queue[rear] = T;
    order[rear] = 1;
    rear++;
    
    // 遍历的同时为各结点编号
    while(front < rear) {
        if(order[front] != count) {
            return ERROR;
        }
        
        p = queue[front];   // 获取队头元素
        
        if(p->lchild != NULL) {
            queue[rear] = p->lchild;
            order[rear] = 2 * order[front];
            rear++;
        }
        
        if(p->rchild != NULL) {
            queue[rear] = p->rchild;
            order[rear] = 2 * order[front] + 1;
            rear++;
        }
        
        front++;
        count++;    // 每出队一个，计数增一
    }
    
    return OK;
}

// 返回指向二叉树结点e的指针
static BiTree EPtr(BiTree T, TElemType e) {
    BiTree pl, pr;
    
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

// 遍历树寻找根结点到p结点的路径，path存储路径上各结点指针(不包含p结点的指针)
static int FindPath(BiTree T, TElemType e, BiTree path[]) {
    int i = -1;
    int mark[MAX_TREE_DEPTH] = {0}; // 访问标记栈
    BiTree p;
    
    p = T;
    
    while(TRUE) {
        // 如果没有遇到满足条件的结点，先尝试向左子树查找
        while(p != NULL && p->data != e) {
            i++;
            
            // 记下当前结点的指针
            path[i] = p;
            
            // 已访问过该结点的左子树
            mark[i] = 1;
            p = p->lchild;
        }
        
        // 遇到了满足条件的结点
        if(p != NULL) {
            return i + 1;
        }
        
        // 回到父结点
        p = path[i];
        
        // 如果右子树不存在，或者该右子树已被访问过，则回到它的父结点
        while(p->rchild == NULL || mark[i] == 2) {
            path[i] = NULL;     // 置空该位置
            
            i--;
            if(i == -1) {
                return 0;
            }
            
            // 回退到父结点
            p = path[i];
        }
        
        // 已访问过该结点的右子树
        mark[i] = 2;
        p = p->rchild;
    }
}
