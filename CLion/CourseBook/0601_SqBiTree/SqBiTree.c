/*==================
 * 二叉树顺序存储结构
 ===================*/

#include "SqBiTree.h"   //**▲06 树和二叉树**//

/*
 * 初始化
 *
 * 构造空二叉树。
 */
Status InitBiTree(SqBiTree T) {
    // 使用空字符填充二叉树的顺序结构
    memset(T, '\0', sizeof(SqBiTree));
    
    return OK;
}

/*
 * 销毁
 *
 * 释放二叉树所占内存。
 *
 *【注】
 * 二叉树的顺序存储结构无法销毁。
 */
Status DestroyBiTree(SqBiTree T) {
    // 二叉树的顺序存储结构无法销毁
    return ERROR;
}

/*
 * 置空
 *
 * 清理二叉树中的数据，使其成为空树。
 */
Status ClearBiTree(SqBiTree T) {
    // 使用空字符填充二叉树的顺序结构
    memset(T, '\0', sizeof(SqBiTree));
    
    return OK;
}

/*
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
Status CreateBiTree(SqBiTree T, char* path) {
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("请输入二叉树的先序序列，如果没有子结点，使用^代替：");
        CreateTree(T, 0, NULL);
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        CreateTree(T, 0, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * 判空
 *
 * 判断二叉树是否为空树。
 */
Status BiTreeEmpty(SqBiTree T) {
    return T[0] == '\0' ? TRUE : FALSE;
}

/*
 * 树深
 *
 * 返回二叉树的深度（层数）。
 */
int BiTreeDepth(SqBiTree T) {
    return TreeDepth(T, 0);
}

/*
 * 取值
 *
 * 返回二叉树中指定结点的值。
 */
TElemType Value(SqBiTree T, TElemType e) {
    int index;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的索引
    index = EIndex(T, e, 0);
    
    // 如果没有找到元素e
    if(index == -1) {
        return '\0';
    } else {
        return T[index];
    }
}

/*
 * 赋值
 *
 * 为二叉树指定的结点赋值。
 */
Status Assign(SqBiTree T, TElemType e, TElemType value) {
    int index;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return ERROR;
    }
    
    // 获取结点e的索引
    index = EIndex(T, e, 0);
    
    // 如果没有找到元素e
    if(index == -1) {
        return ERROR;
    } else {
        // 进行赋值
        T[index] = value;
        return OK;
    }
}

/*
 * 根
 *
 * 返回二叉树的根结点。
 */
TElemType Root(SqBiTree T) {
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    return T[0];
}

/*
 * 双亲
 *
 * 返回二叉树中结点e的双亲结点。
 */
TElemType Parent(SqBiTree T, TElemType e) {
    int index;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的索引
    index = EIndex(T, e, 0);
    
    // 如果没有找到元素e
    if(index == -1) {
        return '\0';
        
        // 如果e是根结点
    } else if(index == 0) {
        return '\0';
    } else {
        // 返回父结点
        return T[(index - 1) / 2];
    }
}

/*
 * 左孩子
 *
 * 返回二叉树中结点e的左孩子结点。
 */
TElemType LeftChild(SqBiTree T, TElemType e) {
    int index;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的索引
    index = EIndex(T, e, 0);
    
    // 如果没有找到元素e
    if(index == -1) {
        return '\0';
    } else {
        // 返回左孩子
        return T[2 * index + 1];
    }
}

/*
 * 右孩子
 *
 * 返回二叉树中结点e的右孩子结点。
 */
TElemType RightChild(SqBiTree T, TElemType e) {
    int index;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的索引
    index = EIndex(T, e, 0);
    
    // 如果没有找到元素e
    if(index == -1) {
        return '\0';
    } else {
        // 返回右孩子
        return T[2 * index + 2];
    }
}

/*
 * 左兄弟
 *
 * 返回二叉树中结点e的左兄弟结点。
 */
TElemType LeftSibling(SqBiTree T, TElemType e) {
    int index, p;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的索引
    index = EIndex(T, e, 0);
    
    // 如果没有找到元素e
    if(index == -1) {
        return '\0';
        
        // 如果e是根结点
    } else if(index == 0) {
        return '\0';
    } else {
        // 获取父结点的索引
        p = (index - 1) / 2;
        
        // 如果结点e是右孩子，则返回其左兄弟
        if(T[2 * p + 2] == e) {
            return T[2 * p + 1];
        } else {
            return '\0';
        }
    }
}

/*
 * 右兄弟
 *
 * 返回二叉树中结点e的右兄弟结点。
 */
TElemType RightSibling(SqBiTree T, TElemType e) {
    int index, p;
    
    // 遇到空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // 获取结点e的索引
    index = EIndex(T, e, 0);
    
    // 如果没有找到元素e
    if(index == -1) {
        return '\0';
        
        // 如果e是根结点
    } else if(index == 0) {
        return '\0';
    } else {
        // 获取父结点的索引
        p = (index - 1) / 2;
        
        // 如果结点e是左孩子，则返回其右兄弟
        if(T[2 * p + 1] == e) {
            return T[2 * p + 2];
        } else {
            return '\0';
        }
    }
}

/*
 * 插入
 *
 * 已知c为与T不相交的非空二叉树，且c的右子树为空，
 * 根据LR的取值(0或1)，将c插入为T中结点p的左子树/右子树，
 * 并且，将p结点原有的左子树/右子树嫁接为二叉树c的右子树。
 */
Status InsertChild(SqBiTree T, TElemType p, int LR, SqBiTree c) {
    int index;
    
    // 如果待插入的树为空树则无需继续计算
    if(BiTreeEmpty(c)) {
        return ERROR;
    }
    
    // 获取结点p的索引
    index = EIndex(T, p, 0);
    
    // 如果p结点不存在，则返回错误提示
    if(index == -1) {
        return ERROR;
    }
    
    // 将c插入为p的左子树
    if(LR==0) {
        // 如果p处存在左子树
        if(T[2*index+1]!='\0') {
            // 将p的左子树插入为c的右子树
            Transfer(T, 2*index+1, c, 2);
        }
    
        Transfer(c, 0, T, 2*index+1);
        
        // 将c插入为p的右子树
    } else {
        // 如果p处存在右子树
        if(T[2*index+2]!='\0') {
            // 将p的右子树插入为c的右子树
            Transfer(T, 2*index+2, c, 2);
        }
    
        Transfer(c, 0, T, 2*index+2);
    }
    
    return OK;
}

/*
 * 删除
 *
 * 根据LR的取值(0或1)，删除结点p的左子树/右子树。
 */
Status DeleteChild(SqBiTree T, TElemType p, int LR) {
    int index;
    
    // 如果待删除的树为空树则无需继续计算
    if(BiTreeEmpty(T)) {
        return ERROR;
    }
    
    // 获取结点p的索引
    index = EIndex(T, p, 0);
    
    // 如果待删除结点不存在，则返回错误提示
    if(index == -1) {
        return ERROR;
    }
    
    // 如果需要删除p的左子树
    if(LR == 0) {
        Delete(T, 2 * index + 1);
        
        // 如果需要删除p的右子树
    } else {
        Delete(T, 2 * index + 2);
    }
    
    return OK;
}

/*
 * 先序遍历
 */
Status PreOrderTraverse(SqBiTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = PreTraverse(T, Visit, 0);
    printf("\n");
    
    return status;
}

/*
 * 中序遍历
 */
Status InOrderTraverse(SqBiTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = InTraverse(T, Visit, 0);
    printf("\n");
    
    return status;
}

/*
 * 后序遍历
 */
Status PostOrderTraverse(SqBiTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = PostTraverse(T, Visit, 0);
    printf("\n");
    
    return status;
}

/*
 * 层序遍历
 */
Status LevelOrderTraverse(SqBiTree T, Status(Visit)(TElemType)) {
    int i;
    int deep;
    int len;
    
    // 二叉树层数
    deep = BiTreeDepth(T);
    if(deep == 0) {
        return OK;
    }
    
    // 二叉树元素数量（最大值）
    len = (int) pow(2, deep) - 1;
    
    for(i = 0; i < len; i++) {
        if(T[i] != '\0') {
            if(!Visit(T[i])) {
                // 如果遇到访问错误，会即时返回
                return ERROR;
            }
        }
    }
    
    printf("\n");
    
    return OK;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建二叉树的内部函数
static void CreateTree(SqBiTree T, int i, FILE* fp) {
    char ch;
    
    // 读取当前结点的值
    if(fp == NULL) {
        scanf("%c", &ch);
    } else {
        ReadData(fp, "%c", &ch);
    }
    
    if(ch == '^') {
        T[i] = '\0';
    } else {
        T[i] = ch;
        CreateTree(T, 2 * i + 1, fp); // 创建左子树
        CreateTree(T, 2 * i + 2, fp); // 创建右子树
    }
}

// 求二叉树深度的内部函数
static int TreeDepth(SqBiTree T, int i) {
    int ld, rd;     // 记录左右子树的深度
    
    if(T[i] == '\0') {
        return 0;
    } else {
        ld = TreeDepth(T, 2 * i + 1);
        rd = TreeDepth(T, 2 * i + 2);
        
        return (ld >= rd ? ld : rd) + 1;
    }
}

// 返回二叉树结点e的索引号，i是结点p的索引号
static int EIndex(SqBiTree T, TElemType e, int i) {
    int cl, cr;
    
    // 已经越界
    if(i >= MAX_TREE_SIZE) {
        return -1;
    }
    
    // e的值不合规
    if(e == '\0') {
        return -1;
    }
    
    // 找到了元素e
    if(T[i] == e) {
        return i;
    }
    
    // 在左子树中查找
    cl = EIndex(T, e, 2 * i + 1);
    if(cl != -1) {
        return cl;
    }
    
    // 在右子树中查找
    cr = EIndex(T, e, 2 * i + 2);
    if(cr != -1) {
        return cr;
    }
    
    return -1;
}

// 摘下二叉树T中的子树i，将其插入为二叉树R的子树j
static void Transfer(SqBiTree T, int i, SqBiTree R, int j) {
    R[j] = T[i];
    
    if(T[i] != '\0') {
        Transfer(T, 2 * i + 1, R, 2 * j + 1);
        Transfer(T, 2 * i + 2, R, 2 * j + 2);
        T[i] = '\0';
    }
}

// 删除二叉树T中的子树i
static void Delete(SqBiTree T, int i) {
    if(T[i] != '\0') {
        T[i] = '\0';
        Delete(T, 2 * i + 1);
        Delete(T, 2 * i + 2);
    }
}

// 先序遍历的内部实现
static Status PreTraverse(SqBiTree T, Status(Visit)(TElemType), int i) {
    // 越界
    if(i >= MAX_TREE_SIZE) {
        return ERROR;
    }
    
    if(T[i]) {
        if(Visit(T[i])) {
            if(PreTraverse(T, Visit, 2 * i + 1)) {
                if(PreTraverse(T, Visit, 2 * i + 2)) {
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
static Status InTraverse(SqBiTree T, Status(Visit)(TElemType), int i) {
    // 越界
    if(i >= MAX_TREE_SIZE) {
        return ERROR;
    }
    
    if(T[i]) {
        if(InTraverse(T, Visit, 2 * i + 1)) {
            if(Visit(T[i])) {
                if(InTraverse(T, Visit, 2 * i + 2)) {
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
static Status PostTraverse(SqBiTree T, Status(Visit)(TElemType), int i) {
    // 越界
    if(i >= MAX_TREE_SIZE) {
        return ERROR;
    }
    
    if(T[i]) {
        if(PostTraverse(T, Visit, 2 * i + 1)) {
            if(PostTraverse(T, Visit, 2 * i + 2)) {
                if(Visit(T[i])) {
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

void PrintTree(SqBiTree T) {
    int level, width;
    int i, j, k, w;
    int begin;
    int distance;
    TElemType** tmp;
    
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
    
    // 遍历树中所有元素，将其安排到二维数组tmp中合适的位置
    for(i = 0; i < level; i++) {
        w        = (int) pow(2, i);             // 二叉树当前层的宽度
        distance = width / w;                   // 二叉树当前层的元素间隔
        begin    = width / (int) pow(2, i + 1); // 二叉树当前层首个元素之前的空格数
        
        for(k = 0; k < w; k++) {
            j = begin + k * (1 + distance);
            tmp[i][j] = T[(int) pow(2, i) + k - 1];
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
