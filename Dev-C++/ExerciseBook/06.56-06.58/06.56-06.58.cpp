#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "BiThrTree.h"  //**▲06 树和二叉树**//

/*
 * 在先序后继线索二叉树中寻找结点p的后继
 */
BiThrTree Algo_6_56(BiThrTree p);

// 测试方法Algo_6_56：输出树的先序序列
void PreTraverse(BiThrTree Thrt);


/*
 * 在后序后继线索二叉树中寻找结点p的后继
 */
BiThrTree Algo_6_57(BiThrTree p);

// 测试方法Algo_6_57：输出树的后序序列
void PosTraverse(BiThrTree Thrt);


/*
 * 将根结点为x，且结点x只有左子树的中序全线索二叉树插入为结点p的左子树，
 * 其中，结点p所在的树也是中序全线索二叉树，Thrx指向线索二叉树x的头结点。
 * 注：如果结点p已经包含左子树，则将其左子树摘下，嫁接为根结点x的右子树
 */
Status Algo_6_58(BiThrTree p, BiThrTree x, BiThrTree Thrx);


// 先序遍历二叉树T，并将其后继线索化
Status PreOrderThreading(BiThrTree* Thrt, BiThrTree T);

// 先序后继线索化的内部实现
void PreTheading(BiThrTree p);

// 对先序后继线索二叉树进行先序遍历（非递归算法）
Status PreOrderTraverse_Thr(BiThrTree Thrt, Status(Visit)(TElemType));


// 后序遍历二叉树T，并将其后继线索化（顺便会初始化parent域）
Status PosOrderThreading(BiThrTree* Thrt, BiThrTree T);

// 后序后继线索化的内部实现（采用了逆先序的遍历方式）
void PosTheading(BiThrTree p);

// 对后序后继线索二叉树进行后序遍历（非递归算法）
Status PosOrderTraverse_Thr(BiThrTree Thrt, Status(Visit)(TElemType));


// 测试函数，打印元素
Status PrintElem(TElemType c);



int main(int argc, char* argv[]) {

    printf("███题 6.56 验证...███\n");
    {
        BiThrTree T;    // 二叉树
        BiThrTree Thr;  // 先序后继线索二叉树

        printf("█ 按先序序列(ABDG^^^EH^^I^^CF^J^^^)创建二叉树...\n");
        CreateBiTree(&T, "TestData_T.txt");

        printf("█ 对二叉树进行先序后继线索化...\n");
        PreOrderThreading(&Thr, T);

        printf("█ 先序遍历先序后继线索二叉树：");
        PreOrderTraverse_Thr(Thr, PrintElem);

        printf("█ 测试方法Algo_6_56：输出树的先序序列：");
        PreTraverse(Thr);
    }
    PressEnterToContinue(debug);


    printf("███题 6.57 验证...███\n");
    {
        BiThrTree T;    // 二叉树
        BiThrTree Thr;  // 后序后继线索二叉树

        printf("█ 按先序序列(ABDG^^^EH^^I^^CF^J^^^)创建二叉树...\n");
        CreateBiTree(&T, "TestData_T.txt");

        printf("█ 对二叉树进行后序后继线索化...\n");
        PosOrderThreading(&Thr, T);

        printf("█ 后序遍历后序后继线索二叉树：");
        PosOrderTraverse_Thr(Thr, PrintElem);

        printf("█ 测试方法Algo_6_57：输出树的后序序列：");
        PosTraverse(Thr);
    }
    PressEnterToContinue(debug);


    printf("███题 6.58 验证...███\n");
    {
        BiThrTree T;    // 二叉树
        BiThrTree Thr;  // 中序全线索二叉树

        BiThrTree Tx;       // 待插入的二叉树
        BiThrTree Thrx;     // 待插入的中序全线索二叉树

        BiThrTree p;

        printf("█ 按先序序列(ABDG^^^EH^^I^^CF^J^^^)创建二叉树...\n");
        CreateBiTree(&T, "TestData_T.txt");

        printf("█ 对二叉树进行中序全线索化...\n");
        InOrderThreading(&Thr, T);

        printf("█ 中序遍历中序全线索二叉树：");
        InOrderTraverse_Thr(Thr, PrintElem);
        // 逆中序遍历，用来验证前驱线索是否正确
//        InOrderTraverse_Thr_Inverse(Thr, PrintElem);

        printf("█ ===============================================\n");

        printf("█ 按先序序列(012^47^^^35^^68^^9^^^)创建二叉树...\n");
        CreateBiTree(&Tx, "TestData_x.txt");

        printf("█ 对二叉树进行中序全线索化...\n");
        InOrderThreading(&Thrx, Tx);

        printf("█ 中序遍历中序全线索二叉树：");
        InOrderTraverse_Thr(Thrx, PrintElem);
        // 逆中序遍历，用来验证前驱线索是否正确
//        InOrderTraverse_Thr_Inverse(Thrx, PrintElem);

        printf("█ ===============================================\n");

        p = T->lchild->rchild;
        printf("█ 按照题意，将子树 x 插入到树 T 的 %c 结点上...\n", p->data);
        Algo_6_58(p, Tx, Thrx);

        printf("█ 插入完成后的中序全线索二叉树为：");
        InOrderTraverse_Thr(Thr, PrintElem);
        // 逆中序遍历，用来验证前驱线索是否正确
//        InOrderTraverse_Thr_Inverse(Thr, PrintElem);
    }
    PressEnterToContinue(debug);

}



/*
 * 在先序后继线索二叉树中寻找结点p的后继
 */
BiThrTree Algo_6_56(BiThrTree p) {
    if(p == NULL) {
        return NULL;
    }

    // 如果存在后继线索，直接获取后继信息
    if(p->RTag == Thread) {
        p = p->rchild;
    } else {
        if(p->lchild != NULL) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }

    return p;
}

// 测试方法Algo_6_56：输出树的先序序列
void PreTraverse(BiThrTree Thrt) {
    BiThrTree p = Thrt->rchild;

    while(p != Thrt) {
        printf("%c", p->data);
        p = Algo_6_56(p);
    }

    printf("\n");
}


/*
 * 在后序后继线索二叉树中寻找结点p的后继
 */
BiThrTree Algo_6_57(BiThrTree p) {
    if(p == NULL) {
        return NULL;
    }

    // 如果存在后继线索，直接获取后继信息
    if(p->RTag == Thread) {
        p = p->rchild;
    } else {
        // 如果当前结点是左孩子
        if(p == p->parent->rchild) {
            p = p->parent;
        } else {
            // 如果父结点没有右孩子
            if(p->parent->rchild == NULL || p->parent->RTag == Thread) {
                p = p->parent;
            } else {
                p = p->parent->rchild;

                /* 查找右兄弟结点的左子树的最右端 */

                while(p->lchild != NULL) {
                    p = p->lchild;
                }

                while(p->rchild != NULL && p->RTag == Link) {
                    p = p->rchild;
                }
            }
        }
    }

    return p;
}

// 测试方法Algo_6_57：输出树的后序序列
void PosTraverse(BiThrTree Thrt) {
    BiThrTree p = Thrt->rchild;

    while(p != Thrt) {
        printf("%c", p->data);
        p = Algo_6_57(p);
    }

    printf("\n");
}


/*
 * 将根结点为x，且结点x只有左子树的中序全线索二叉树插入为结点p的左子树，
 * 其中，结点p所在的树也是中序全线索二叉树，Thrx指向线索二叉树x的头结点。
 * 注：如果结点p已经包含左子树，则将其左子树摘下，嫁接为根结点x的右子树
 */
Status Algo_6_58(BiThrTree p, BiThrTree x, BiThrTree Thrx) {
    BiThrTree pPre; // 结点p的前驱

    BiThrTree xFirst;    // 树x的中序序列的第一个结点
    BiThrTree xLast;     // 树x的中序序列的最后一个结点

    BiThrTree lt;        // p的左子树
    BiThrTree ltFirst;   // 子树lt的中序序列的第一个结点

    if(p==NULL || x==NULL) {
        return ERROR;
    }

    // x结点不允许存在右孩子
    if(x->RTag==Link) {
        return ERROR;
    }

    // 获取树x的中序序列的第一个结点和最后一个结点
    xFirst = Thrx->lchild;
    // 如果存在左子树，一直向左遍历
    while(xFirst->LTag==Link){
        xFirst = xFirst->lchild;
    }
    xLast = Thrx->rchild;

    // 如果结点p不存在左子树
    if(p->LTag==Thread) {
        pPre = p->lchild;   // 直接获取p的前驱

        p->LTag = Link;     // 修改p的左线索为左孩子
        p->lchild = x;      // 插入子树x

        xFirst->lchild = pPre;  // 重置xFirst的左线索
        xLast->rchild = p;      // 重置xLast的右线索

        // 如果结点p存在左子树
    } else {
        // 指向结点p的左子树
        lt = p->lchild;

        // 查找子树lt的中序序列的第一个结点
        ltFirst = lt;
        // 如果存在左孩子，则一直向左遍历
        while(ltFirst->LTag==Link){
            ltFirst = ltFirst->lchild;
        }

        x->RTag = Link;     // 将lt插入为x的右子树
        x->rchild = lt;

        /*
         * 这里需要一点：
         * 左子树lt变成子树x的根结点的右子树时，lt中序序列上最后一个结点的后继线索不会变
         */
        xFirst->lchild = ltFirst->lchild;   // 接管子树lt的左线索
        ltFirst->lchild = x;                // 子树lt的左线索指向x

        p->lchild = x;  // 更新p的左子树
    }

    // 将x从Thrx上移除
    Thrx->lchild = Thrx->rchild = Thrx;

    return OK;
}


// 先序遍历二叉树T，并将其后继线索化
Status PreOrderThreading(BiThrTree* Thrt, BiThrTree T) {
    *Thrt = (BiThrTree) malloc(sizeof(BiThrNode));
    if(*Thrt == NULL) {
        exit(OVERFLOW);
    }

    (*Thrt)->data = '\0';
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = NULL;

    // 空树只有线索头结点
    if(!T) {
        (*Thrt)->lchild = (*Thrt)->rchild = *Thrt;
    } else {
        (*Thrt)->lchild = T;
        pre = *Thrt;    // 指向头结点

        PreTheading(T); // 开始线索化

        pre->RTag = Thread;     // 最后一个结点线索化
        pre->rchild = *Thrt;    // 最后一个结点指回头结点

        (*Thrt)->rchild = T;    // 头结点指向第一个结点，建立【循环】联系
    }

    return OK;
}

// 先序后继线索化的内部实现
void PreTheading(BiThrTree p) {
    if(p == NULL) {
        return;
    }

    // 为上一个结点右子树建立后继线索
    if(pre->rchild == NULL) {
        pre->RTag = Thread;
        pre->rchild = p;
    } else {
        // 如果右子树不为空，则添加Link标记
        pre->RTag = Link;
    }

    // pre向前挪一步
    pre = p;

    // 线索化左子树
    PreTheading(p->lchild);

    // 如果存在右子树，线索化右子树
    if(p->rchild != NULL && p->RTag == Link) {
        PreTheading(p->rchild);
    }
}

// 遍历：对先序后继线索二叉树进行先序遍历（非递归算法）
Status PreOrderTraverse_Thr(BiThrTree Thrt, Status(Visit)(TElemType)) {
    BiThrTree p = Thrt;     // p指向二叉树线索结点

    while(p->rchild != Thrt) {
        // 先向左访问，直到尽头
        while(p->lchild != NULL) {
            p = p->lchild;
            if(Visit(p->data) == ERROR) {
                return ERROR;
            }
        }

        // 向左访问到头，则向右访问（通过线索）
        if(p->rchild != Thrt) {
            p = p->rchild;
            if(Visit(p->data) == ERROR) {
                return ERROR;
            }
        }
    }

    printf("\n");

    return OK;
}


// 后序遍历二叉树T，并将其后继线索化（顺便会初始化parent域）
Status PosOrderThreading(BiThrTree* Thrt, BiThrTree T) {
    *Thrt = (BiThrTree) malloc(sizeof(BiThrNode));
    if(*Thrt == NULL) {
        exit(OVERFLOW);
    }

    (*Thrt)->data = '\0';
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = *Thrt;

    if(T == NULL) {
        (*Thrt)->lchild = (*Thrt)->rchild = *Thrt;
    } else {
        (*Thrt)->lchild = T;
        pre = *Thrt;    // 指向头结点

        T->parent = *Thrt;

        PosTheading(T); // 开始线索化

        (*Thrt)->rchild = pre;    // 头结点的右线索指向后序第一个结点，建立【循环】联系
    }

    return OK;
}

// 后序后继线索化的内部实现（采用了逆先序的遍历方式）
void PosTheading(BiThrTree p) {
    if(p == NULL) {
        return;
    }

    // 为当前结点右子树建立后继线索
    if(p->rchild == NULL) {
        p->RTag = Thread;
        p->rchild = pre;
    } else {
        // 如果右子树不为空，则添加Link标记
        p->RTag = Link;
    }

    // pre在正常顺序中为后一个结点
    pre = p;

    // 线索化右子树
    if(p->RTag != Thread) {
        if(p->rchild != NULL) {
            p->rchild->parent = p;
        }

        PosTheading(p->rchild);
    }

    if(p->lchild != NULL) {
        p->lchild->parent = p;
    }

    // 线索化左子树
    PosTheading(p->lchild);
}

// 遍历：对后序后继线索二叉树进行后序遍历（非递归算法）
Status PosOrderTraverse_Thr(BiThrTree Thrt, Status(Visit)(TElemType)) {
    BiThrTree r = Thrt->rchild; // p指向后序第一个结点
    BiThrTree p;

    // 树不为空
    while(r != Thrt) {
        if(Visit(r->data) == ERROR) {
            return ERROR;
        }

        // 存在后继线索
        if(r->RTag == Thread) {
            r = r->rchild;
        } else {
            p = r->parent;
            if(p == Thrt) {
                break;  // 已经遍历完成
            }

            // 如果当前结点是右孩子
            if(r == p->rchild) {
                r = p;

                // 如果当前结点是左孩子
            } else {
                // 父结点的右孩子为NULL
                if(p->rchild == NULL || p->RTag == Thread) {
                    r = p;
                } else {
                    r = p->rchild;

                    /* 查找r结点左子树的最右端 */

                    while(r->lchild != NULL) {
                        r = r->lchild;
                    }

                    while(r->rchild != NULL && r->RTag == Link) {
                        r = r->rchild;
                    }
                }
            }
        }
    }

    printf("\n");

    return OK;
}


// 测试函数，打印元素
Status PrintElem(TElemType c) {
    printf("%c", c);
    return OK;
}

