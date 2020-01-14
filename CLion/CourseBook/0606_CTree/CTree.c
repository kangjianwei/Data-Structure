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
 * 销毁
 *
 * 释放树所占内存。
 *
 *【注】
 * 与置空操作是一致的
 */
Status DestroyTree(CTree* T) {
    // 无需销毁，使用置空就可以
    return ERROR;
}

/*
 * 置空
 *
 * 清理树中的数据，使其成为空树。
 */
Status ClearTree(CTree* T) {
    int k;
    ChildPtr p, q;
    
    if(T == NULL) {
        return ERROR;
    }
    
    // 释放孩子结点占用的空间
    for(k = T->r; k != (T->r + T->n) % MAX_TREE_SIZE; k = (k + 1) % MAX_TREE_SIZE) {
        p = T->nodes[k].firstchild;
        
        while(p != NULL) {
            q = p;
            p = p->next;
            free(q);
        }
    }
    
    // 将元素数量归零即可
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

/*
 * 取值
 *
 * 返回树中指定结点的值。
 */
TElemType Value(CTree T, TElemType e) {
    int p;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的索引
    p = EIndex(T, e);
    
    // 如果没有找到元素e
    if(p == -1) {
        return '\0';
    } else {
        return T.nodes[p].data;
    }
}

/*
 * 赋值
 *
 * 为树指定的结点赋值。
 */
Status Assign(CTree* T, TElemType e, TElemType value) {
    int p;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(*T)) {
        return ERROR;
    }
    
    // 获取结点e的索引
    p = EIndex(*T, e);
    
    // 如果没有找到元素e
    if(p == -1) {
        return ERROR;
    } else {
        // 进行赋值
        T->nodes[p].data = value;
        return OK;
    }
}

/*
 * 根
 *
 * 返回树的根结点。
 */
TElemType Root(CTree T) {
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    return T.nodes[T.r].data;
}

/*
 * 双亲
 *
 * 返回树中结点e的双亲结点。
 */
TElemType Parent(CTree T, TElemType e) {
    int p, parent;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的索引
    p = EIndex(T, e);
    
    // 如果没有找到元素e
    if(p == -1) {
        return '\0';
    } else {
        parent = T.nodes[p].parent;
        
        // 根结点无双亲
        if(parent == -1) {
            return '\0';
        } else {
            return T.nodes[parent].data;
        }
    }
}

/*
 * 孩子数量
 *
 * 返回树T中结点e的孩子数量。
 */
int ChildCount(CTree T, TElemType e) {
    int p, count;
    ChildPtr r;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return -1;
    }
    
    // 获取结点e的索引
    p = EIndex(T, e);
    // 结点e不存在
    if(p == -1) {
        return -1;
    }
    
    r = T.nodes[p].firstchild;
    count = 0;
    
    // 统计结点e的孩子数量
    while(r != NULL) {
        count++;
        r = r->next;
    }
    
    return count;
}

/*
 * 孩子
 *
 * 返回树中结点e的第i个孩子。
 */
TElemType Child(CTree T, TElemType e, int i) {
    int p;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // i的范围越界
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return '\0';
    }
    
    // 获取结点e的第i个孩子索引
    p = CIndex(T, e, i);
    // 结点e第i个孩子不存在
    if(p == -1) {
        return '\0';
    }
    
    return T.nodes[p].data;
}

/*
 * 左兄弟
 *
 * 返回树中结点e的左兄弟结点。
 *
 *【注】
 * 由于树的结点可能会包含多个孩子，
 * 因此这里的左兄弟特指左边紧邻该结点的兄弟。
 */
TElemType LeftSibling(CTree T, TElemType e) {
    int p, ls;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的索引
    p = EIndex(T, e);
    // 结点e不存在
    if(p == -1) {
        return '\0';
    }
    
    // 假设存在左兄弟
    ls = (p - 1 + MAX_TREE_SIZE) % MAX_TREE_SIZE;
    
    // 如果该结点有效，且与结点e的双亲相同，说明它是兄弟
    if(ls != p && T.nodes[ls].data != '\0' && T.nodes[ls].parent == T.nodes[p].parent) {
        return T.nodes[ls].data;
    }
    
    return '\0';
}

/*
 * 右兄弟
 *
 * 返回树中结点e的右兄弟结点。
 *
 *【注】
 * 由于树的结点可能会包含多个孩子，
 * 因此这里的右兄弟特指右边紧邻该结点的兄弟。
 */
TElemType RightSibling(CTree T, TElemType e) {
    int p, rs;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的索引
    p = EIndex(T, e);
    // 结点e不存在
    if(p == -1) {
        return '\0';
    }
    
    // 假设存在右兄弟
    rs = (p + 1) % MAX_TREE_SIZE;
    
    // 如果该结点有效，且与结点e的双亲相同，说明它是兄弟
    if(rs != p && T.nodes[rs].data != '\0' && T.nodes[rs].parent == T.nodes[p].parent) {
        return T.nodes[rs].data;
    }
    
    return '\0';
}

/*
 * 插入
 *
 * 将树c插入为树T中p结点的第i个孩子。
 */
Status InsertChild(CTree* T, TElemType p, int i, CTree c) {
    Pos pt[MAX_TREE_SIZE], pc[MAX_TREE_SIZE];
    int pIndex;
    int lastChild, bound;
    int level;
    int m, n, k;
    int tCur, cCur;
    
    CTree R;
    int tParent[MAX_TREE_SIZE], cParent[MAX_TREE_SIZE];
    int x, y, z;
    
    ChildPtr cp, s;
    int count;
    
    // 如果树为空树则无需继续计算
    if(TreeEmpty(*T) || TreeEmpty(c)) {
        return ERROR;
    }
    
    // i的范围过于小
    if(i < 1) {
        return ERROR;
    }
    
    // 获取结点p的索引
    pIndex = EIndex(*T, p);
    
    // 如果p结点不存在，则返回错误提示
    if(pIndex == -1) {
        return ERROR;
    }
    
    // 计算T中结点的位置信息
    getPos(*T, pt);
    
    // 结点p最后一个孩子的索引
    lastChild = pt[pIndex].lastChild;
    
    // i的范围过大
    if(lastChild != -1 && i > pt[lastChild].childIndex + 1) {
        return ERROR;
    }
    
    if(i == 1) {
        // 结点p本身是第一个孩子
        if(pt[pIndex].childIndex == 1) {
            bound = -1;
        } else {
            // 从p的左兄弟起，向左查找
            for(k = (pIndex - 1) % MAX_TREE_SIZE; pt[k].lastChild == -1 && pt[k].childIndex != 1; k = (k - 1) % MAX_TREE_SIZE) {
                // 查找右边界的父结点的索引
            }
            
            // 已经遍历到该层第一个结点，但该结点仍然没有孩子
            if(pt[k].lastChild == -1) {
                bound = -1;
            } else {
                bound = pt[k].lastChild;    // k结点最后一个孩子的索引
            }
        }
    } else {
        // 结点p没有孩子
        if(lastChild == -1) {
            return ERROR;
        } else {
            for(k = pt[pIndex].lastChild; pt[k].childIndex != i - 1; k = (k - 1) % MAX_TREE_SIZE) {
                // 查找插入位置的前一个孩子的索引
            }
            bound = k;
        }
    }
    
    level = pt[pIndex].row + 1;   // 待插入的树的根结点所在的行
    
    // 计算c中结点的位置信息
    getPos(c, pc);
    // 处理新插入的树中各元素的行数
    for(k = c.r; k != (c.r + c.n) % MAX_TREE_SIZE; k = (k + 1) % MAX_TREE_SIZE) {
        pc[k].row += level - 1;
    }
    
    // tCur指向第level行的第一个结点
    for(tCur = pIndex; tCur != (T->r + T->n) % MAX_TREE_SIZE; tCur = (tCur + 1) % MAX_TREE_SIZE) {
        if(pt[tCur].row == level) {
            break;
        }
    }
    
    // cCur指向树c中的根结点，该根结点也应当插入到树T中的level行
    cCur = c.r;
    
    while(tCur != (T->r + T->n) % MAX_TREE_SIZE && cCur != (c.r + c.n) % MAX_TREE_SIZE) {
        // 跳过树T右界的前半部分
        if(bound != -1) {
            tCur = (bound + 1) % MAX_TREE_SIZE;
        }
        
        if(bound == -1) {
            m = 0;
        } else {
            m = pt[bound].col;
        }
        
        n = 0;
        
        // 将c插入到T的中间
        while(cCur != (c.r + c.n) % MAX_TREE_SIZE && pc[cCur].row == level) {
            // 改变列
            
            pc[cCur].col += m;
            n++;
            
            cCur++;
        }
        
        // 处理T的后半部分
        while(tCur != (T->r + T->n) % MAX_TREE_SIZE && pt[tCur].row == level) {
            
            pt[tCur].col += n;
            
            tCur++;
        }
        
        // 计算下一层的边界
        if(bound != -1) {
            // 从bound起，向左查找
            for(k = bound; pt[k].lastChild == -1 && pt[k].childIndex != 1; k = (k - 1) % MAX_TREE_SIZE) {
                // 查找右边界的父结点的索引
            }
            
            // 已经遍历到该层第一个结点，但该结点仍然没有孩子
            if(pt[k].lastChild == -1) {
                bound = -1;
            } else {
                bound = pt[k].lastChild;    // k结点最后一个孩子的索引
            }
        }
        
        level++;
    }
    
    // 检验pos信息
//    printPos(*T, pt);
//    printPos(c, pc);
    
    InitTree(&R);
    
    R.r = T->r;
    n = 0;
    
    x = T->r;   // 遍历T的游标
    y = c.r;    // 遍历c的游标
    z = R.r;    // 遍历R的游标
    
    while(x != (T->r + T->n) % MAX_TREE_SIZE && y != (c.r + c.n) % MAX_TREE_SIZE) {
        if(pt[x].row < pc[y].row || (pt[x].row == pc[y].row && pt[x].col < pc[y].col)) {
            
            // 记录结点x的新位置
            tParent[x] = z;
            
            // 有效元素放到新位置上
            R.nodes[z] = T->nodes[x];
            
            if(R.nodes[z].parent != -1) {
                // 更新父结点位置
                R.nodes[z].parent = tParent[R.nodes[z].parent];
                
                // 指向父结点的第一个孩子
                cp = R.nodes[R.nodes[z].parent].firstchild;
                
                // 如果当前结点不是第一个孩子，则需要查询正确的位置
                if(pt[x].childIndex != 1) {
                    for(count = 1; count < pt[x].childIndex; count++) {
                        cp = cp->next;
                    }
                }
                
                /*
                 * 更新当前结点在孩子链表中的位置
                 *
                 * 注：此处的更新会使其位置变大，故需要避免覆盖后面的元素值，下面的分支中以此类推
                 */
                cp->child = z;
            }
            
            x = (x + 1) % MAX_TREE_SIZE;
        } else if(pt[x].row > pc[y].row || (pt[x].row == pc[y].row && pt[x].col > pc[y].col)) {
            // 记录结点y的新位置
            cParent[y] = z;
            
            // 有效元素放到新位置上
            R.nodes[z] = c.nodes[y];
            
            if(R.nodes[z].parent != -1) {
                // 更新父结点位置
                R.nodes[z].parent = cParent[R.nodes[z].parent];
                
                // 指向父结点的第一个孩子
                cp = R.nodes[R.nodes[z].parent].firstchild;
                
                // 如果当前结点不是第一个孩子，则需要查询正确的位置
                if(pc[y].childIndex != 1) {
                    for(count = 1; count < pc[y].childIndex; count++) {
                        cp = cp->next;
                    }
                }
                
                // 更新当前结点在孩子链表中的位置
                cp->child = z;
            } else {
                // 将两棵树连到一起，即树c的根结点的父结点为p
                R.nodes[z].parent = tParent[pIndex];
                
                // 包装当前结点
                s = (ChildPtr) malloc(sizeof(CTNode));
                s->child = z;
                
                // 指向该结点的父结点的首个孩子
                cp = R.nodes[R.nodes[z].parent].firstchild;
                
                if(cp == NULL || i == 1) {
                    s->next = R.nodes[R.nodes[z].parent].firstchild;
                    R.nodes[R.nodes[z].parent].firstchild = s;
                } else {
                    // 计数
                    count = 1;
                    
                    // 查找第i-1个结点
                    while(cp != NULL && count < i - 1) {
                        count++;
                        cp = cp->next;
                    }
                    
                    s->next = cp->next;
                    cp->next = s;
                }
            }
            
            y = (y + 1) % MAX_TREE_SIZE;
        }
        
        z = (z + 1) % MAX_TREE_SIZE;
        n++;
    }
    
    while(x != (T->r + T->n) % MAX_TREE_SIZE) {
        // 记录结点k的新位置
        tParent[x] = z;
        
        // 有效元素放到新位置上
        R.nodes[z] = T->nodes[x];
        
        if(R.nodes[z].parent != -1) {
            // 更新父结点位置
            R.nodes[z].parent = tParent[R.nodes[z].parent];
            
            // 指向父结点的首个孩子
            cp = R.nodes[R.nodes[z].parent].firstchild;
            
            // 如果当前结点不是第一个孩子，则需要查询正确的位置
            if(pt[x].childIndex != 1) {
                for(count = 1; count < pt[x].childIndex; count++) {
                    cp = cp->next;
                }
            }
            
            // 更新当前结点在孩子链表中的位置
            cp->child = z;
        }
        
        x = (x + 1) % MAX_TREE_SIZE;
        z = (z + 1) % MAX_TREE_SIZE;
        n++;
    }
    
    while(y != (c.r + c.n) % MAX_TREE_SIZE) {
        // 记录结点k的新位置
        cParent[y] = z;
        
        // 有效元素放到新位置上
        R.nodes[z] = c.nodes[y];
        
        if(R.nodes[z].parent != -1) {
            // 更新父结点位置
            R.nodes[z].parent = cParent[R.nodes[z].parent];
            
            // 指向父结点的首个孩子
            cp = R.nodes[R.nodes[z].parent].firstchild;
            
            // 如果当前结点不是第一个孩子，则需要查询正确的位置
            if(pc[y].childIndex != 1) {
                for(count = 1; count < pc[y].childIndex; count++) {
                    cp = cp->next;
                }
            }
            
            // 更新当前结点在孩子链表中的位置
            cp->child = z;
        } else {
            // 将两棵树连到一起，即树c的根结点的父结点为p
            R.nodes[z].parent = tParent[pIndex];
            
            // 包装当前结点
            s = (ChildPtr) malloc(sizeof(CTNode));
            s->child = z;
            
            // 指向该结点的父结点的首个孩子
            cp = R.nodes[R.nodes[z].parent].firstchild;
            
            if(cp == NULL || i == 1) {
                s->next = R.nodes[R.nodes[z].parent].firstchild;
                R.nodes[R.nodes[z].parent].firstchild = s;
            } else {
                // 计数
                count = 1;
                
                // 查找第i-1个结点
                while(cp != NULL && count < i - 1) {
                    count++;
                    cp = cp->next;
                }
                
                s->next = cp->next;
                cp->next = s;
            }
        }
        
        y = (y + 1) % MAX_TREE_SIZE;
        z = (z + 1) % MAX_TREE_SIZE;
        n++;
    }
    
    R.n = n;
    *T = R;
    
    return OK;
}

/*
 * 删除
 *
 * 删除树T中p结点的第i个孩子。
 */
Status DeleteChild(CTree* T, TElemType p, int i) {
    LinkQueue Q;
    QElemType e;    // 队列元素指示结点的位置
    
    int index;
    int k, m, n;
    
    CTree R;
    int parent[MAX_TREE_SIZE];
    ChildPtr cp, q, s;
    
    // 如果待删除的树为空树则无需继续计算
    if(TreeEmpty(*T)) {
        return ERROR;
    }
    
    // i的范围越界（初步判断）
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return ERROR;
    }
    
    // 获取结点p的第i个孩子索引
    index = CIndex(*T, p, i);
    
    // 如果待删除结点不存在，则返回错误提示
    if(index == -1) {
        return ERROR;
    }
    
    // 指向当前结点的父结点的第一个孩子
    cp = T->nodes[T->nodes[index].parent].firstchild;
    
    // 在父结点中找到了当前孩子并移除它
    if(cp->child==index) {
        T->nodes[T->nodes[index].parent].firstchild = cp->next;
    } else {
        // 在父结点中查找当前孩子并移除它（一定能找到）
        while(cp != NULL && cp->child!=index) {
            s = cp;
            cp = cp->next;
        }
        
        s->next = cp->next;
    }
    free(cp);
    
    InitQueue(&Q);
    
    // 待删除的子树的根结点入队
    EnQueue(&Q, index);
    
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &e);    // 父结点的位置出队
        
        // 抹掉当前结点
        T->nodes[e].data = '\0';
        
        // 指向该结点的孩子链表
        cp = T->nodes[e].firstchild;
    
        // 释放该结点处的孩子链表所占内存
        while(cp != NULL) {
            EnQueue(&Q, cp->child); // 当前结点位置入队
            
            q = cp;
            cp = cp->next;
            free(q);
        }
        
        T->nodes[e].firstchild = NULL;
    }
    
    InitTree(&R);
    
    R.r = T->r;
    n = 0;
    
    m = R.r;    // 遍历R的游标
    
    for(k = T->r; k != (T->r + T->n) % MAX_TREE_SIZE; k = (k + 1) % MAX_TREE_SIZE) {
        if(T->nodes[k].data != '\0') {
            // 记录结点k的新位置
            parent[k] = m;
            
            // 有效元素放到新位置上
            R.nodes[m] = T->nodes[k];
            
            if(R.nodes[m].parent!=-1) {
                // 更新父结点位置
                R.nodes[m].parent = parent[R.nodes[m].parent];
    
                // 指向父结点的首个孩子
                cp = R.nodes[R.nodes[m].parent].firstchild;
    
                // 在父结点的孩子链表中查找当前结点
                while(cp->child != k) {
                    cp = cp->next;
                }
                
                /*
                 * 更新当前结点在孩子链表中的位置
                 *
                 * 注：这里的值位置只会更新到更小，所以不用担心覆盖后面的元素位置
                 * 否则，在查找该孩子时，就要采取InsertChild中的策略了
                 */
                cp->child = m;
            }
            
            m = (m + 1) % MAX_TREE_SIZE;
            n++;
        }
    }
    
    R.n = n;
    *T = R;
    
    return OK;
}

/*
 * 先序遍历
 */
Status PreOrderTraverse(CTree T, Status(Visit)(TElemType)) {
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    PreTraverse(T, T.r, Visit);
    
    printf("\n");
    
    return OK;
}

/*
 * 后序遍历
 */
Status PostOrderTraverse(CTree T, Status(Visit)(TElemType)) {
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    PostTraverse(T, T.r, Visit);
    
    printf("\n");
    
    return OK;
}

/*
 * 层序遍历
 */
Status LevelOrderTraverse(CTree T, Status(Visit)(TElemType)) {
    int i;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    // 顺次遍历所有元素
    for(i = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        if(!Visit(T.nodes[i].data)) {
            return ERROR;
        }
    }
    
    printf("\n");
    
    return OK;
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

// 返回树结点e的索引，如果不存在，返回-1
static int EIndex(CTree T, TElemType e) {
    int i = T.r;    // 指向根结点
    int p = -1;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return -1;
    }
    
    // 在树中查找结点e
    while(i != (T.r + T.n) % MAX_TREE_SIZE) {
        if(T.nodes[i].data == e) {
            p = i;
            break;
        }
        
        i = (i + 1) % MAX_TREE_SIZE;
    }
    
    return p;
}

// 返回树结点e的第i个孩子索引，如果不存在，返回-1
static int CIndex(CTree T, TElemType e, int i) {
    int p, count;
    ChildPtr s;
    
    // 遇到空树则无需继续计算
    if(TreeEmpty(T)) {
        return -1;
    }
    
    // i的范围越界
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return -1;
    }
    
    // 获取结点e的索引
    p = EIndex(T, e);
    // 结点e不存在
    if(p == -1) {
        return -1;
    }
    
    // 指向该结点的首个孩子
    s = T.nodes[p].firstchild;
    // 计数
    count = 1;
    
    while(s != NULL && count < i) {
        count++;
        s = s->next;
    }
    
    if(s != NULL) {
        return s->child;
    } else {
        return -1;
    }
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

// 先序遍历的内部实现
static Status PreTraverse(CTree T, int i, Status(Visit)(TElemType)) {
    int firstChild = -1;    // 初始化为无效的索引
    int rightBrother;
    
    // 访问当前结点
    if(!Visit(T.nodes[i].data)) {
        return ERROR;
    }
    
    // 相比双亲表存储结构，求长子更容易了
    if(T.nodes[i].firstchild!=NULL) {
        firstChild = T.nodes[i].firstchild->child;
    }
    
    // 遍历长子（需要先确定长子的身份）
    if(firstChild != -1 && !PreTraverse(T, firstChild, Visit)) {
        return ERROR;
    }
    
    rightBrother = (i + 1) % MAX_TREE_SIZE;
    
    // 遍历右兄弟（需要先确定右兄弟的身份）
    if(T.nodes[i].parent == T.nodes[rightBrother].parent && !PreTraverse(T, rightBrother, Visit)) {
        return ERROR;
    }
    
    return OK;
}

// 后序遍历的内部实现
static Status PostTraverse(CTree T, int i, Status(Visit)(TElemType)) {
    int firstChild = -1;    // 初始化为无效的索引
    int rightBrother;
    
    // 相比双亲表存储结构，求长子更容易了
    if(T.nodes[i].firstchild!=NULL) {
        firstChild = T.nodes[i].firstchild->child;
    }
    
    // 遍历长子（需要先确定长子的身份）
    if(firstChild != -1 && !PostTraverse(T, firstChild, Visit)) {
        return ERROR;
    }
    
    // 访问当前结点
    if(!Visit(T.nodes[i].data)) {
        return ERROR;
    }
    
    rightBrother = (i + 1) % MAX_TREE_SIZE;
    
    // 遍历右兄弟（需要先确定右兄弟的身份）
    if(T.nodes[i].parent == T.nodes[rightBrother].parent && !PostTraverse(T, rightBrother, Visit)) {
        return ERROR;
    }
    
    return OK;
}

// 输出pos信息，仅限内部测试使用
static void printPos(CTree T, Pos pt[]) {
    int i;
    
    for(i = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        printf("%2c ", T.nodes[i].data);
    }
    printf("\n");
    
    for(i = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        printf("%2d ", pt[i].row);
    }
    printf("\n");
    
    for(i = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        printf("%2d ", pt[i].col);
    }
    printf("\n");
    
    for(i = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        printf("%2d ", pt[i].childIndex);
    }
    printf("\n");
    
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
