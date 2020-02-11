/*==============================
 * 集合
 *
 * 包含算法: 6.8、6.9、6.10、6.11
 ===============================*/

#include "MFSet.h"

/*
 * 初始化一个由多个子集（每个子集只包含单个成员）构成的集合S。
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
Status initial_mfset(MFSet* S, char* path) {
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("请输入集合的元素信息...\n");
        mfset(S, NULL);
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        mfset(S, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * 初始化集合的二元等价关系。
 */
Status initial_relation(Relation* R, char* path) {
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("请输入集合的二元关系对...\n");
        relation(R, NULL);
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        relation(R, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * ████████ 算法6.9 ████████
 *
 * 求两个互不相交的子集Si和子集Sj的并集。
 */
Status merge_mfset(MFSet* S, int i, int j) {
    
    // 索引越界
    if(i < 1 || i > S->n || j < 1 || j > S->n) {
        return ERROR;
    }
    
    /*
     * 相同的子集无需合并，直接返回
     * 注：教材中没有此步，需要修正
     */
    if(i == j) {
        return OK;
    }
    
    S->nodes[i].parent = j;
    
    return OK;
}

/*
 * ████████ 算法6.8 ████████
 *
 * 在集合S中查找元素i当前所属的子集。
 */
int find_mfset(MFSet S, int i) {
    int j;
    
    // 索引越界
    if(i < 1 || i > S.n) {
        return -1;
    }
    
    // 查找i所属的子集的根结点
    for(j = i; S.nodes[j].parent > 0; j = S.nodes[j].parent) {
        // 从下往上查找
    }
    
    return j;
}

/*
 * ████████ 算法6.10 ████████
 *
 * 求两个互不相交的子集Si和子集Sj的并集。
 *
 * 该算法是【算法6.9】的改进，改进之处在于：
 * 1.子集根结点的绝对值为该子集元素的数量
 * 2.坚持将规模小的集合合并到规模大的集合上
 */
Status mix_mfset(MFSet* S, int i, int j) {
    
    // 索引越界
    if(i < 1 || i > S->n || j < 1 || j > S->n) {
        return ERROR;
    }
    
    /*
     * 相同的子集无需合并，直接返回
     * 注：教材中没有此步，需要修正
     */
    if(i == j) {
        return OK;
    }
    
    // Si所含成员数比sj少（根结点的parent域是负数，所以元素少的其值反而大）
    if(S->nodes[i].parent > S->nodes[j].parent) {
        S->nodes[j].parent += S->nodes[i].parent;
        S->nodes[i].parent = j;
    } else {
        S->nodes[i].parent += S->nodes[j].parent;
        S->nodes[j].parent = i;
    }
    
    return OK;
}

/*
 * ████████ 算法6.11 ████████
 *
 * 在集合S中查找元素i当前所属的子集。
 *
 * 该算法是【算法6.8】的改进，改进之处在于：
 * 查找完成后，会对树的高度进行摊平，即尽量让元素直接挂载到子集根结点上。
 *
 *【注】
 * 该操作会对集合造成改动
 */
int fix_mfset(MFSet* S, int i) {
    int j, k, t;
    
    // 索引越界
    if(i < 1 || i > S->n) {
        return -1;
    }
    
    // 查找i所属的子集的根结点
    for(j = i; S->nodes[j].parent > 0; j = S->nodes[j].parent) {
        // 从下往上查找
    }
    
    // 顺着结点i到其所在子集的根结点，将路过的元素直接嫁接到子集的根上，相当于摊平了树的高度
    for(k = i; k != j; k = t) {
        t = S->nodes[k].parent;
        S->nodes[k].parent = j;
    }
    
    return j;
}

/*
 * 根据等价关系R来整理/建立集合S中的元素(子集)。
 *
 *【注】
 * 该方法与bix_relation方法目的一致，
 * 但该方法调用的是【算法6.8】和【算法6.9】，
 * 是未优化的版本。
 */
Status build_mfset(MFSet* S, Relation R) {
    int k;
    int i, j;
    
    for(k = 0; k < R.n; k++) {
        // 先获取子集根结点
        i = find_mfset(*S, R.pairs[k].i);
        j = find_mfset(*S, R.pairs[k].j);
        
        // 对两个互不相交的子集进行归并
        if(!merge_mfset(S, i, j)) {
            return ERROR;
        }
    }
    
    return OK;
}

/*
 * 根据等价关系R来整理/建立集合S中的元素(子集)。
 *
 *【注】
 * 该方法与build_relation方法目的一致，
 * 但该方法调用的是【算法6.10】和【算法6.11】，
 * 是优化后的版本。
 */
Status bix_mfset(MFSet* S, Relation R) {
    int k;
    int i, j;
    
    for(k = 0; k < R.n; k++) {
        // 先获取子集根结点
        i = fix_mfset(S, R.pairs[k].i);
        j = fix_mfset(S, R.pairs[k].j);
        
        // 对两个互不相交的子集进行归并
        if(!mix_mfset(S, i, j)) {
            return ERROR;
        }
    }
    
    return OK;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建集合的内部函数
static void mfset(MFSet* S, FILE* fp) {
    int n, i;
    
    S->r = 0;
    
    if(fp == NULL) {
        printf("请输入元素(子集)数量：");
        scanf("%d", &n);
    } else {
        // 录入元素数量
        ReadData(fp, "%d", &n);
    }
    
    if(n <= 0) {
        return;
    }
    
    S->n = n;
    S->r = 1;
    
    // 子集编号默认从1开始计数
    for(i = 1; i <= n; i++) {
        S->nodes[i].parent = -1;
    }
}

// 创建集合二元关系的内部函数
static void relation(Relation* R, FILE* fp) {
    int n, k;
    
    R->n = 0;
    
    if(fp == NULL) {
        printf("请输入二元关系对的数量：");
        scanf("%d", &n);
        
        if(n <= 0) {
            return;
        }
        
        R->n = n;
        
        for(k = 0; k < n; k++) {
            printf("请输入第 %2d 对二元关系：", k + 1);
            scanf("%d%d", &(R->pairs[k].i), &(R->pairs[k].j));
        }
    } else {
        // 录入二元关系对的数量
        ReadData(fp, "%d", &n);
        
        if(n <= 0) {
            return;
        }
        
        R->n = n;
        
        for(k = 0; k < n; k++) {
            ReadData(fp, "%d%d", &(R->pairs[k].i), &(R->pairs[k].j));
        }
    }
}


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构
void PrintSet(MFSet S) {
    typedef struct Elem {
        int x;
        struct Elem* next;
    } Elem;
    
    int count;  // 统计S中的子集数量
    int k, i, cur;
    Elem* set;
    Elem* p;
    
    if(S.n == 0) {
        printf("\n");
        return;
    }
    
    // 初次遍历，先确定子集数量
    for(k = 1, count = 0; k <= S.n; k++) {
        if(S.nodes[k].parent < 0) {
            count++;
        }
    }
    
    set = (Elem*) malloc((count + 1) * sizeof(Elem));
    memset(set, 0, (count + 1) * sizeof(Elem));
    
    // 0号单元的数据域存储子集数量
    set[0].x = count;
    
    // 再次遍历，确定每个子集下包含哪些元素
    for(k = 1; k <= S.n; k++) {
        // 遇到了子集根结点
        if(S.nodes[k].parent < 0) {
            // 在set中查找根结点位置，如果找不到，则定位到插入位置
            for(i = 1; i <= set[0].x && set[i].x != 0; i++) {
                if(set[i].next->x == k) {
                    break;
                }
            }
            
            // 未找到该根结点，需要插入
            if(set[i].x == 0) {
                set[i].x++;   // 0号单元依然计数
                
                // 记录根结点信息
                set[i].next = (Elem*) malloc(sizeof(Elem));
                set[i].next->x = k;
                set[i].next->next = NULL;
            }
            
            // 遇到子集中其他元素
        } else {
            for(cur = k; S.nodes[cur].parent > 0; cur = S.nodes[cur].parent) {
                // 查找其所属的子集，一定可以找到某个根结点cur
            }
            
            // 在set中查找根结点位置，如果找不到，则定位到插入位置
            for(i = 1; i <= set[0].x && set[i].x != 0; i++) {
                if(set[i].next->x == cur) {
                    break;
                }
            }
            
            // 未找到该根结点，需要插入
            if(set[i].x == 0) {
                set[i].x++;   // 0号单元依然计数
                
                // 记录根结点信息
                set[i].next = (Elem*) malloc(sizeof(Elem));
                set[i].next->x = cur;
                set[i].next->next = NULL;
            }
            
            // 插入当前结点到最尾部
            set[i].x++;
            
            for(p = set[i].next; p->next != NULL; p = p->next) {
                // 查找链表尾部
            }
            
            p->next = (Elem*) malloc(sizeof(Elem));
            p->next->x = k;
            p->next->next = NULL;
        }
    }
    
    printf("集合中共有 %d 个子集：\n", set[0].x);
    
    for(i = 1; i <= set[0].x; i++) {
        printf("子集 %2d 中共有 %2d 个元素：", set[i].next->x, set[i].x);
        
        for(p = set[i].next; p != NULL; p = p->next) {
            printf("%2d ", p->x);
        }
        
        printf("\n");
    }
    
    printf("存储结构：\n");
    PrintFramework(S);
}

// 图形化输出树的排列结构，仅限内部测试使用
static void PrintFramework(MFSet S) {
    int k;
    
    if(S.n == 0) {
        printf("\n");
        return;
    }
    
    printf("+----------+\n");
    printf("|  i |   p |\n");
    printf("+----------+\n");
    
    for(k = 1; k <= S.n; k++) {
        printf("| %2d |  %2d |\n", k, S.nodes[k].parent);
    }
    
    printf("+----------+\n");
}
