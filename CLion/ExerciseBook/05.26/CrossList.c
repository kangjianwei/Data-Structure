/*===================
 * 十字链表（稀疏矩阵）
 *
 * 包含算法: 5.4
 ====================*/

#include "CrossList.h"                        //**▲05 数组和广义表**//

/*
 * ████████ 算法5.4 ████████
 *
 * 创建稀疏矩阵M
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
Status CreateSMatrix(CrossList* M, char* path) {
    int i, j, k;
    OLNode* p, * q;
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("请输入行数：");
        scanf("%d", &((*M).mu));
        printf("请输入列数：");
        scanf("%d", &((*M).nu));
        printf("请输入非零元素个数：");
        scanf("%d", &((*M).tu));
        printf("请输入%d个三元组信息\n", (*M).tu);
    } else {
        fp = fopen(path, "r");
        ReadData(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));
    }
    
    // 创建行链（类似行索引，0号单元弃用）
    (*M).rhead = (OLink*) malloc(((*M).mu + 1) * sizeof(OLink));
    if((*M).rhead == NULL) {
        exit(OVERFLOW);
    }
    
    // 创建列链（类似列索引，0号单元弃用）
    (*M).chead = (OLink*) malloc(((*M).nu + 1) * sizeof(OLink));
    if((*M).chead == NULL) {
        exit(OVERFLOW);
    }
    
    // 初始化行链索引为NULL
    for(k = 0; k <= (*M).mu; ++k) {
        (*M).rhead[k] = NULL;
    }
    
    // 初始化列链索引为NULL
    for(k = 0; k <= (*M).nu; ++k) {
        (*M).chead[k] = NULL;
    }
    
    // 依次录入非零元
    for(k = 1; k <= (*M).tu; ++k) {
        // 创建三元组结点
        p = (OLNode*) malloc(sizeof(OLNode));
        if(p == NULL) {
            exit(OVERFLOW);
        }
        
        if(readFromConsole) {
            printf("第%2d组：", k);
            scanf("%d%d%d", &i, &j, &(p->e));
        } else {
            ReadData(fp, "%d%d%d", &i, &j, &(p->e));
        }
        
        p->i = i;   // 行号
        p->j = j;   // 列号
        p->right = p->down = NULL;
        
        /*
         * 开始行的插入
         */
        
        // 如果该行还没有元素，或已有元素均位于该元素右侧，则可以直接插入
        if((*M).rhead[i] == NULL || (*M).rhead[i]->j > j) {
            // 定位行表中的插入位置
            p->right = (*M).rhead[i];
            (*M).rhead[i] = p;
        } else {
            // 寻找插入位置的前一个位置
            for(q = (*M).rhead[i]; (q->right) && (q->right->j < j); q = q->right) {
            }
            
            if(q->j == p->j || ((q->right) && q->right->j == p->j)) {
                printf("此位置已被占用！！\n");
                exit(ERROR);
            }
            
            p->right = q->right;
            q->right = p;
        }
        
        /*
         * 开始列的插入
         */
        
        // 如果该列还没有元素，或已有元素均位于该元素下侧，则可以直接插入
        if((*M).chead[j] == NULL || (*M).chead[j]->i > i) {
            // 定位列表中的插入位置
            p->down = (*M).chead[j];
            (*M).chead[j] = p;
        } else {
            // 寻找插入位置的前一个位置
            for(q = (*M).chead[j]; (q->down) && (q->down->i < i); q = q->down) {
            }
            
            if(q->i == p->i || ((q->down) && q->down->i == p->i)) {
                printf("此位置已被占用！！\n");
                exit(ERROR);
            }
            
            p->down = q->down;
            q->down = p;
        }
    }
    
    if(!readFromConsole) {
        fclose(fp);
    }
    
    return OK;
}

/*
 * 销毁稀疏矩阵
 */
Status DestroySMatrix(CrossList* M) {
    int i;
    OLNode* p, * q;
    
    // 无论从按行还是按列，只需要朝着一个方向去遍历销毁就可以了
    for(i = 1; i <= (*M).mu; ++i) {
        p = (*M).rhead[i];
        while(p != NULL) {
            q = p;
            p = p->right;
            free(q);
        }
    }
    
    free((*M).rhead);
    free((*M).chead);
    
    (*M).rhead = (*M).chead = NULL;
    (*M).mu = (*M).nu = (*M).tu = 0;
    
    return OK;
}

/*
 * 矩阵复制
 *
 * 创建一个新矩阵T，该矩阵包含了从矩阵M中包含的数据。
 */
Status CopySMatrix(CrossList M, CrossList* T) {
    int k;
    OLNode* p, * q, * r, * l;
    
    if(T == NULL) {
        return ERROR;
    }
    
    // 复制行列信息
    (*T).mu = M.mu;
    (*T).nu = M.nu;
    (*T).tu = M.tu;
    
    // 创建行链（类似行索引，0号单元弃用）
    (*T).rhead = (OLink*) malloc(((*T).mu + 1) * sizeof(OLink));
    if((*T).rhead == NULL) {
        exit(OVERFLOW);
    }
    
    // 创建列链（类似列索引，0号单元弃用）
    (*T).chead = (OLink*) malloc(((*T).nu + 1) * sizeof(OLink));
    if((*T).chead == NULL) {
        exit(OVERFLOW);
    }
    
    // 初始化行链索引为NULL
    for(k = 0; k <= (*T).mu; ++k) {                                //初始化行列头指针向量为空
        (*T).rhead[k] = NULL;
    }
    
    // 初始化列链索引为NULL
    for(k = 0; k <= (*T).nu; ++k) {
        (*T).chead[k] = NULL;
    }
    
    // 按行扫描，依次复制非零元
    for(k = 1; k <= M.mu; ++k) {
        q = M.rhead[k];
        
        // 如果当前行没有元素，直接跳过
        if(q == NULL) {
            continue;
        }
        
        r = NULL;
        
        while(q != NULL) {
            // 创建三元组结点
            p = (OLNode*) malloc(sizeof(OLNode));
            if(p == NULL) {
                exit(OVERFLOW);
            }
            
            // 为结点赋值
            p->i = q->i;
            p->j = q->j;
            p->e = q->e;
            p->right = p->down = NULL;
            
            /*
             * 开始行的插入
             */
            
            if(r == NULL) {
                (*T).rhead[q->i] = p;
            } else {
                r->right = p;
            }
            
            // r指向当前行新插入的结点
            r = p;
            
            /*
             * 开始列的插入
             */
            
            // 在列链中寻找插入位置
            if((*T).chead[q->j] == NULL || (*T).chead[q->j]->i > q->i) {
                r->down = (*T).chead[q->j];
                (*T).chead[q->j] = r;
            } else {
                // 寻找插入位置的前一个位置
                for(l = (*T).chead[q->j]; (l->down) && (l->down->i < q->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
            
            q = q->right;
        }
    }
    
    return OK;
}

/*
 * 矩阵加法
 *
 * Q = M + N。
 */
Status AddSMatrix(CrossList M, CrossList N, CrossList* Q) {
    int i;
    OLNode* pm, * pn, * p, * r, * l;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("两矩阵的行数、列数不满足相加条件！！\n");
        return ERROR;
    }
    
    // 初始化Q的行列信息
    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;
    
    // 创建行链（类似行索引，0号单元弃用）
    Q->rhead = (OLink*) malloc((Q->mu + 1) * sizeof(OLink));
    if(!Q->rhead) {
        exit(OVERFLOW);
    }
    
    // 创建列链（类似列索引，0号单元弃用）
    Q->chead = (OLink*) malloc((Q->nu + 1) * sizeof(OLink));
    if(!Q->chead) {
        exit(OVERFLOW);
    }
    
    // 初始化行链索引为NULL
    for(i = 0; i <= Q->mu; ++i) {
        Q->rhead[i] = NULL;
    }
    
    // 初始化列链索引为NULL
    for(i = 0; i <= Q->nu; ++i) {
        Q->chead[i] = NULL;
    }
    
    // 从第一行往下遍历
    for(i = 1; i <= M.mu; ++i) {
        pm = M.rhead[i];
        pn = N.rhead[i];
        
        // 如果M与N的当前行中均有未处理的非零元
        while(pm != NULL && pn != NULL) {
            // 处理特殊情形
            if(pm->j == pn->j && pm->e + pn->e == 0) {
                pm = pm->right;
                pn = pn->right;
                continue;
            }
            
            // 创建结点
            p = (OLNode*) malloc(sizeof(OLNode));
            if(!p) {
                exit(OVERFLOW);
            }
            
            // M中的三元组列下标较小
            if(pm->j < pn->j) {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e;
                pm = pm->right;
                
                // N中的三元组列下标较小
            } else if(pm->j > pn->j) {
                p->i = pn->i;
                p->j = pn->j;
                p->e = pn->e;
                pn = pn->right;
                
                // M与N中的三元组列下标一致，需要进行加法运算
            } else {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e + pn->e;
                pm = pm->right;
                pn = pn->right;
            }
            
            p->right = p->down = NULL;
            
            Q->tu++;    // Q中非零元个数增一
            
            /*
             * 开始行的插入
             */
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // r指向当前行新插入的结点
            r = p;
            
            /*
             * 开始列的插入
             */
            
            // 在列链中寻找插入位置
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                // 寻找插入位置的前一个位置
                for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
        }
        
        // 如果M的当前行中仍有未处理的非零元
        while(pm != NULL) {
            p = (OLNode*) malloc(sizeof(OLNode));
            if(p == NULL) {
                exit(OVERFLOW);
            }
            p->i = pm->i;
            p->j = pm->j;
            p->e = pm->e;
            p->right = p->down = NULL;
            
            Q->tu++;    // Q中非零元个数增一
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // r指向当前行新插入的结点
            r = p;
            
            // 在列链中寻找插入位置
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                // 寻找插入位置的前一个位置
                for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
            
            pm = pm->right;
        }
        
        // 如果N的当前行中仍有未处理的非零元
        while(pn != NULL) {
            p = (OLNode*) malloc(sizeof(OLNode));
            if(p == NULL) {
                exit(OVERFLOW);
            }
            p->i = pn->i;
            p->j = pn->j;
            p->e = pn->e;
            p->right = p->down = NULL;
            
            Q->tu++;    // Q中非零元个数增一
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // r指向当前行新插入的结点
            r = p;
            
            // 在列链中寻找插入位置
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                // 寻找插入位置的前一个位置
                for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
            
            pn = pn->right;
        }
    }
    
    return OK;
}

/*
 * 矩阵减法
 *
 * Q = M - N。
 */
Status SubSMatrix(CrossList M, CrossList N, CrossList* Q) {
    int i;
    OLNode* pm, * pn, * p, * r, * l;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("两矩阵的行数、列数不满足相减条件！！\n");
        return ERROR;
    }
    
    // 初始化Q的行列信息
    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;
    
    // 创建行链（类似行索引，0号单元弃用）
    Q->rhead = (OLink*) malloc((Q->mu + 1) * sizeof(OLink));
    if(!Q->rhead) {
        exit(OVERFLOW);
    }
    
    // 创建列链（类似列索引，0号单元弃用）
    Q->chead = (OLink*) malloc((Q->nu + 1) * sizeof(OLink));
    if(!Q->chead) {
        exit(OVERFLOW);
    }
    
    // 初始化行链索引为NULL
    for(i = 0; i <= Q->mu; ++i) {
        Q->rhead[i] = NULL;
    }
    
    // 初始化列链索引为NULL
    for(i = 0; i <= Q->nu; ++i) {
        Q->chead[i] = NULL;
    }
    
    // 从第一行往下遍历
    for(i = 1; i <= M.mu; ++i) {
        pm = M.rhead[i];
        pn = N.rhead[i];
        
        // 如果M与N的当前行中均有未处理的非零元
        while(pm != NULL && pn != NULL) {
            // 处理特殊情形
            if(pm->j == pn->j && pm->e - pn->e == 0) {
                pm = pm->right;
                pn = pn->right;
                continue;
            }
            
            // 创建结点
            p = (OLNode*) malloc(sizeof(OLNode));
            if(!p) {
                exit(OVERFLOW);
            }
            
            // M中的三元组列下标较小
            if(pm->j < pn->j) {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e;
                pm = pm->right;
                
                // N中的三元组列下标较小
            } else if(pm->j > pn->j) {
                p->i = pn->i;
                p->j = pn->j;
                p->e = -pn->e;      // 加负号
                pn = pn->right;
                
                // M与N中的三元组列下标一致，需要进行减法运算
            } else {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e - pn->e;
                pm = pm->right;
                pn = pn->right;
            }
            
            p->right = p->down = NULL;
            
            Q->tu++;    // Q中非零元个数增一
            
            /*
             * 开始行的插入
             */
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // r指向当前行新插入的结点
            r = p;
            
            /*
             * 开始列的插入
             */
            
            // 在列链中寻找插入位置
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                //寻找插入位置的前一个位置
                for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
        }
        
        // 如果M的当前行中仍有未处理的非零元
        while(pm != NULL) {
            p = (OLNode*) malloc(sizeof(OLNode));
            if(!p) {
                exit(OVERFLOW);
            }
            p->i = pm->i;
            p->j = pm->j;
            p->e = pm->e;
            p->right = p->down = NULL;
            
            Q->tu++;    // Q中非零元个数增一
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // r指向当前行新插入的结点
            r = p;
            
            // 在列链中寻找插入位置
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                // 寻找插入位置的前一个位置
                for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
            
            pm = pm->right;
        }
        
        // 如果N的当前行中仍有未处理的非零元
        while(pn != NULL) {
            p = (OLNode*) malloc(sizeof(OLNode));
            if(!p) {
                exit(OVERFLOW);
            }
            p->i = pn->i;
            p->j = pn->j;
            p->e = -pn->e;              // 加负号
            p->right = p->down = NULL;
            
            Q->tu++;    // Q中非零元个数增一
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // r指向当前行新插入的结点
            r = p;
            
            // 在列链中寻找插入位置
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                // 寻找插入位置的前一个位置
                for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
            
            pn = pn->right;
        }
    }
    
    return OK;
}

/*
 * 矩阵乘法
 *
 * Q = M * N。
 */
Status MultSMatrix(CrossList M, CrossList N, CrossList* Q) {
    int m_row, n_col, i;
    ElemType e;
    OLNode* pm, * pn, * p, * r, * l;
    
    // M的列数需要等于N的行数
    if(M.nu != N.mu) {
        printf("两矩阵的行数、列数不满足相乘条件！！\n");
        return ERROR;
    }
    
    // 初始化Q的行列信息
    Q->mu = M.mu;
    Q->nu = N.nu;
    Q->tu = 0;
    
    // 创建行链（类似行索引，0号单元弃用）
    Q->rhead = (OLink*) malloc((Q->mu + 1) * sizeof(OLink));
    if(!Q->rhead) {
        exit(OVERFLOW);
    }
    
    // 创建列链（类似列索引，0号单元弃用）
    Q->chead = (OLink*) malloc((Q->nu + 1) * sizeof(OLink));
    if(!Q->chead) {
        exit(OVERFLOW);
    }
    
    // 初始化行链索引为NULL
    for(i = 0; i <= Q->mu; ++i) {
        Q->rhead[i] = NULL;
    }
    
    // 初始化列链索引为NULL
    for(i = 0; i <= Q->nu; ++i) {
        Q->chead[i] = NULL;
    }
    
    // Q是非零矩阵
    if(M.tu * N.tu) {
        for(m_row = 1; m_row <= M.mu; ++m_row) {
            for(n_col = 1; n_col <= N.nu; ++n_col) {
                pm = M.rhead[m_row];
                pn = N.chead[n_col];
                
                e = 0;
                
                // M的行与N的列相乘
                while(pm && pn) {
                    if(pm->j < pn->i) {
                        pm = pm->right;
                    } else if(pm->j > pn->i) {
                        pn = pn->down;
                    } else {
                        e += pm->e * pn->e;
                        pm = pm->right;
                        pn = pn->down;
                    }
                }
                
                if(e == 0) {
                    continue;
                }
                
                p = (OLNode*) malloc(sizeof(OLNode));
                if(!p) {
                    exit(OVERFLOW);
                }
                
                // 为结点赋值
                p->i = M.rhead[m_row]->i;
                p->j = N.chead[n_col]->j;
                p->e = e;
                p->right = p->down = NULL;
                
                Q->tu++;    // Q中非零元个数增一
                
                if(Q->rhead[p->i] == NULL) {
                    Q->rhead[p->i] = p;
                } else {
                    r->right = p;
                }
                
                // r指向当前行新插入的结点
                r = p;
                
                // 在列链中寻找插入位置
                if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                    r->down = Q->chead[p->j];
                    Q->chead[p->j] = r;
                } else {
                    // 寻找插入位置的前一个位置
                    for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                    }
                    
                    r->down = l->down;
                    l->down = r;
                }
            }
        }
    }
    
    return OK;
}

/*
 * 矩阵转置
 */
Status TransposeSMatrix(CrossList M, CrossList* T) {
    int i;
    OLNode* p, * q, * r, * l;
    
    // 初始化Q的行列信息
    (*T).mu = M.nu;
    (*T).nu = M.mu;
    (*T).tu = M.tu;
    
    // 创建行链（类似行索引，0号单元弃用）
    (*T).rhead = (OLink*) malloc(((*T).mu + 1) * sizeof(OLink));
    if(!(*T).rhead) {
        exit(OVERFLOW);
    }
    
    // 创建列链（类似列索引，0号单元弃用）
    (*T).chead = (OLink*) malloc(((*T).nu + 1) * sizeof(OLink));
    if(!(*T).chead) {
        exit(OVERFLOW);
    }
    
    // 初始化行链索引为NULL
    for(i = 0; i <= (*T).mu; ++i) {
        (*T).rhead[i] = NULL;
    }
    
    // 初始化列链索引为NULL
    for(i = 0; i <= (*T).nu; ++i) {
        (*T).chead[i] = NULL;
    }
    
    // 零矩阵
    if(!(*T).tu) {
        return OK;
    }
    
    // 按列扫描
    for(i = 1; i <= M.nu; ++i) {
        q = M.chead[i];
        
        // 如果当前行没有元素，直接跳过
        if(q == NULL) {
            continue;
        }
        
        while(q != NULL) {
            // 创建三元组结点
            p = (OLNode*) malloc(sizeof(OLNode));
            if(!p) {
                exit(OVERFLOW);
            }
            
            // 为结点赋值，行变列，列变行
            p->i = q->j;
            p->j = q->i;
            p->e = q->e;
            p->right = p->down = NULL;
    
            /*
             * 开始行的插入
             */
            
            if((*T).rhead[p->i] == NULL) {
                (*T).rhead[p->i] = p;
            } else {
                r->right = p;
            }
    
            // r指向当前行新插入的结点
            r = p;
    
            /*
             * 开始列的插入
             */
    
            // 在列链中寻找插入位置
            if((*T).chead[p->j] == NULL || (*T).chead[p->j]->i > p->i) {
                r->down = (*T).chead[p->j];
                (*T).chead[p->j] = r;
            } else {
                // 寻找插入位置的前一个位置
                for(l = (*T).chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
            
            q = q->down;
        }
    }
    
    return OK;
}

/*
 * 输出矩阵
 */
void PrintSMatrix(CrossList M) {
    int i, j;
    OLNode* p;
    
    for(i = 1; i <= M.mu; ++i) {
        p = M.rhead[i];
        for(j = 1; j <= M.nu; ++j) {
            if(p && p->j == j) {
                printf("%3d ", p->e);
                p = p->right;
            } else {
                printf("%3d ", 0);
            }
        }
        printf("\n");
    }
}
