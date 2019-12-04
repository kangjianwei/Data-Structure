/*====================
 * 赫夫曼树
 *
 * 包含算法: 6.12、6.13
 ====================*/

#include "HuffmanTree.h"

/*
 * 初始化环境
 *
 * 主要用来初始化权值信息。
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
Status InitEnvironment(int** w, int* n, char* path) {
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("请输入赫夫曼树结点信息...\n");
        Init(w, n, NULL);
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        Init(w, n, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * ████████ 算法6.12 ████████
 *
 * 编码
 * 1.根据指定的n个权值信息w来创建赫夫曼树HT。
 * 2.由赫夫曼树HT逆序计算赫夫曼编码值HC。
 *
 *【注】
 * 该算法与【算法6.13】作用一致。
 */
Status HuffmanCodeing_1(HuffmanTree* HT, HuffmanCode* HC, int* w, int n) {
    int m, i;
    HuffmanTree p;
    int s1, s2;
    char* cd;
    int start, c;
    unsigned int f;
    
    if(n <= 1) {
        return ERROR;
    }
    
    // 计算赫夫曼树结点数
    m = 2 * n - 1;
    
    *HT = (HuffmanTree) malloc((m + 1) * sizeof(HTNode));   // 0号单元未使用，但其weight域记录了原始的权值数量
    (*HT)[0].weight = n;
    
    // 记录权值信息（注意p应当指向索引1处，因为0号单元弃用了，而教材中错误地指向了0号单元）
    for(p = (*HT) + 1, i = 1; i <= n; ++i, ++p, ++w) {
        (*p).weight = *w;
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).rchild = 0;
    }
    
    // 后面的部分需要计算
    for(; i <= m; ++i, ++p) {
        (*p).weight = 0;
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).rchild = 0;
    }
    
    // 建赫夫曼树
    for(i = n + 1; i <= m; ++i) {
        // 在HT[1,i-1]中选择parent为0（未加入树），且weight最小的两个结点，其序号分别为s1和s2
        Select(*HT, i - 1, &s1, &s2);
        
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
    
    
    /* 从叶子到根逆向求每个字符的赫夫曼编码 */
    
    (*HC) = (HuffmanCode) malloc((n + 1) * sizeof(char*));  // 分配n个字符编码的头指针向量（0号单元弃用）
    cd = (char*) malloc(n * sizeof(char));  // 分配求编码的工作空间（每个编码长度最大为n-1）
    cd[n - 1] = '\0';   // 编码结束符
    
    // 逐个字符求赫夫曼编码
    for(i = 1; i <= n; ++i) {
        start = n - 1;    // 编码结束符位置
        
        // 从叶子到根逆向求编码
        for(c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent) {
            if((*HT)[f].lchild == c) {
                cd[--start] = '0';
            } else {
                cd[--start] = '1';
            }
        }
        
        (*HC)[i] = (char*) malloc((n - start) * sizeof(char));  // 为第i个字符编码分配空间
        strcpy((*HC)[i], &cd[start]);   // 从cd复制编码（串）到HC
    }
    
    free(cd);   // 释放工作空间
    
    return OK;
}

/*
 * ████████ 算法6.13 ████████
 *
 * 编码
 * 1.根据指定的n个权值信息w来创建赫夫曼树HT。
 * 2.先序遍历赫夫曼树HT计算赫夫曼编码值HC。
 *
 *【注】
 * 该算法与【算法6.12】作用一致。
 */
Status HuffmanCodeing_2(HuffmanTree* HT, HuffmanCode* HC, int* w, int n) {
    int m, i;
    HuffmanTree p;
    int s1, s2;
    unsigned int r;
    int cdlen;
    char* cd;
    HuffmanTree H;  // HT的一个副本
    
    if(n <= 1) {
        return ERROR;
    }
    
    // 计算赫夫曼树结点数
    m = 2 * n - 1;
    
    *HT = (HuffmanTree) malloc((m + 1) * sizeof(HTNode));   // 0号单元未使用，但其weight域记录了原始的权值数量
    (*HT)[0].weight = n;
    
    // 记录权值信息（注意p应当指向索引1处，因为0号单元弃用了，而教材中错误地指向了0号单元）
    for(p = (*HT) + 1, i = 1; i <= n; ++i, ++p, ++w) {
        (*p).weight = *w;
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).rchild = 0;
    }
    
    // 后面的部分需要计算
    for(; i <= m; ++i, ++p) {
        (*p).weight = 0;
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).rchild = 0;
    }
    
    // 建赫夫曼树
    for(i = n + 1; i <= m; ++i) {
        // 在HT[1,i-1]中选择parent为0（未加入树），且weight最小的两个结点，其序号分别为s1和s2
        Select(*HT, i - 1, &s1, &s2);
        
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
    
    
    /* 无栈非递归遍历赫夫曼树，求赫夫曼编码 */
    
    (*HC) = (HuffmanCode) malloc((n + 1) * sizeof(char*));  // 分配n个字符编码的头指针向量（0号单元弃用）
    cd = (char*) malloc(n * sizeof(char));  // 分配求编码的工作空间（每个编码长度最大为n-1）
    
    r = m;
    cdlen = 0;
    
    // 后续再赫夫曼树的副本上进行操作
    H = (HuffmanTree) malloc((m + 1) * sizeof(HTNode));
    for(i = 0; i <= m; ++i) {
        H[i] = (*HT)[i];
        H[i].weight = 0;
    }
    
    while(r != 0) {
        // 第一次访问此结点，需要向左遍历
        if(H[r].weight == 0) {
            H[r].weight = 1;
            
            // 存在左孩子
            if(H[r].lchild != 0) {
                // 向左走一步
                r = H[r].lchild;
                cd[cdlen++] = '0';
                
                // 不存在左孩子，也不存在右孩子，即遇到了叶子结点
            } else if(H[r].rchild == 0) {
                (*HC)[r] = (char*) malloc((cdlen + 1) * sizeof(char));
                cd[cdlen] = '\0';
                strcpy((*HC)[r], cd);   // 复制编码串
            }
            
            // 第二次访问此结点，需要向右遍历
        } else if(H[r].weight == 1) {
            H[r].weight = 2;
            
            if(H[r].rchild != 0) {
                r = H[r].rchild;
                cd[cdlen++] = '1';
            }
            
            // 第三次访问，需要回退到父结点
        } else {
            r = H[r].parent;    // 退回到父结点
            cdlen--;                // 编码长度减1
        }
    }
    
    return OK;
}

/*
 * 解码
 * 根据给定的n个赫夫曼编码HC，计算其代表的权值。
 */
Status HuffmanDecoding(HuffmanTree HT, HuffmanCode HC, int** w, int n) {
    int i, j, k;
    int r;
    char* s;
    
    if(n <= 0) {
        return ERROR;
    }
    
    (*w) = (int*) malloc(n * sizeof(int));
    
    // 根结点位置
    r = 2 * n - 1;
    
    for(i = 1; i <= n; i++) {
        s = HC[i];
        
        k = r;
        
        // 从根结点往下找
        for(j = 0; j < strlen(s); j++) {
            if(s[j] == '0') {
                k = HT[k].lchild;   // 向左
            } else if(s[j] == '1') {
                k = HT[k].rchild;   // 向右
            } else {
                return ERROR;
            }
        }
        
        (*w)[i - 1] = HT[k].weight;
    }
    
    return OK;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 初始化环境的内部实现
static Status Init(int** w, int* n, FILE* fp) {
    int i;
    
    if(fp == NULL) {
        printf("请输入赫夫曼树叶子结点数量：");
        scanf("%d", n);
        
        if(*n <= 0) {
            *w = NULL;
            return ERROR;
        }
        
        *w = (int*) malloc((*n) * sizeof(int));
        
        printf("请输入 %d 个权值信息：", *n);
        for(i = 0; i < *n; i++) {
            scanf("%d", *w + i);
        }
    } else {
        // 录入元素数量
        ReadData(fp, "%d", n);
        
        if(*n <= 0) {
            *w = NULL;
            return ERROR;
        }
        
        *w = (int*) malloc((*n) * sizeof(int));
        
        // 录入结点权值信息
        for(i = 0; i < *n; i++) {
            ReadData(fp, "%d", *w + i);
        }
    }
    
    return OK;
}

// 在赫夫曼树结点[1...end]中依次选出权值最小且未编入树的两个结点的序号s1、s2。
static void Select(HuffmanTree HT, int end, int* s1, int* s2) {
    int i;
    int w1, w2;
    
    w1 = w2 = INT_MAX;
    
    for(i = 1; i <= end; i++) {
        // 忽略已经加入树的结点
        if(HT[i].parent != 0) {
            continue;
        }
        
        if(HT[i].weight < w1) {
            *s2 = *s1;
            w2 = w1;
            
            *s1 = i;
            w1 = HT[i].weight;
        } else if(HT[i].weight >= w1 && HT[i].weight < w2) {
            *s2 = i;
            w2 = HT[i].weight;
        } else {
            // HT[i].weight>=w2
        }
    }
}


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 打印赫夫曼树结构。
void PrintHuffmanTree(HuffmanTree HT) {
    int i;
    
    printf("+-------+--------+--------+--------+--------+\n");
    printf("| index | weight | parent | lchild | rchild |\n");
    printf("+-------+--------+--------+--------+--------+\n");
    printf("|  %3d  |  %4d  |        |        |        |\n", 0, HT[0].weight);
    printf("+-------+--------+--------+--------+--------+\n");
    for(i = 1; i <= 2 * HT[0].weight - 1; i++) {
        printf("|  %3d  |  %4d  |   %2d   |   %2d   |   %2d   |\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
    }
    printf("+-------+--------+--------+--------+--------+\n");
}

// 打印赫夫曼编码。
void PrintHuffmanCode(HuffmanTree HT, HuffmanCode HC) {
    int i;
    
    printf("+-------+--------+-------------\n");
    printf("| index | weight | HuffmanCode \n");
    printf("+-------+--------+-------------\n");
    printf("|  %3d  |  %4d  | \n", 0, HT[0].weight);
    printf("+-------+--------+-------------\n");
    for(i = 1; i <= HT[0].weight; i++) {
        printf("|  %3d  |  %4d  -> %s\n", i, HT[i].weight, HC[i]);
    }
    printf("+-------+--------+-------------\n");
}

// 打印赫夫曼编码对应的权值信息。
void PrintWeight(HuffmanCode HC, int* w, int n) {
    int i;
    
    printf("+-------+-------------+--------+\n");
    printf("| index | HuffmanCode | weight |\n");
    printf("+-------+-------------+--------+\n");
    for(i = 1; i <= n; i++) {
        printf("|  %3d  | %11s |  %4d  |\n", i, HC[i], w[i - 1]);
    }
    printf("+-------+-------------+--------+\n");
}
