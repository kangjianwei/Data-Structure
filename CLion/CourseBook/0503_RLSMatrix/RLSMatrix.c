/*=============================
 * 行逻辑链接的顺序表（稀疏矩阵）
 *
 * 包含算法: 5.3
 ==============================*/

#include "RLSMatrix.h"  //**▲05 数组和广义表**//

/*
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
Status CreateSMatrix(RLSMatrix* M, char* path) {
    int k;
    FILE* fp;
    int readFromConsole;    // 是否从控制台读取数据
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    // 如果没有文件路径信息，则从控制台读取输入
    if(readFromConsole) {
        printf("请输入行数：");
        scanf("%d", &((*M).mu));
        printf("请输入列数：");
        scanf("%d", &((*M).nu));
        printf("请输入非零元素个数：");
        scanf("%d", &((*M).tu));
        printf("请输入%d个三元组信息\n", (*M).tu);
        for(k = 1; k <= (*M).tu; k++) {
            printf("第%2d组：", k);
            scanf("%d%d%d", &((*M).data[k].i), &((*M).data[k].j), &((*M).data[k].e));
        }
    } else {
        fp = fopen(path, "r");
        
        ReadData(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));
        
        for(k = 1; k <= (*M).tu; k++) {
            ReadData(fp, "%d%d%d", &((*M).data[k].i), &((*M).data[k].j), &((*M).data[k].e));
        }
        
        fclose(fp);
    }
    
    // 为rpos数组赋值
    AssignRpos(M);
    
    return OK;
}

/*
 * 销毁稀疏矩阵
 *
 *【注】
 * 行逻辑链接的顺序表结构无法销毁。
 */
Status DestroySMatrix(RLSMatrix* M) {
    int i;
    
    if(M == NULL) {
        return ERROR;
    }
    
    M->mu = 0;
    M->nu = 0;
    M->tu = 0;
    
    for(i = 0; i <= MAXRC; ++i) {
        M->rpos[i] = 0;
    }
    
    return OK;
}

/*
 * 矩阵复制
 *
 * 创建一个新矩阵T，该矩阵包含了从矩阵M中包含的数据。
 */
Status CopySMatrix(RLSMatrix M, RLSMatrix* T) {
    (*T) = M;   // 结构体之间可以直接复制，即使内部包含数组也可以
    
    return OK;
}

/*
 * 矩阵加法
 *
 * Q = M + N。
 */
Status AddSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix* Q) {
    int m, n, k;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("两矩阵的行数、列数不满足相加条件！！\n");
        return ERROR;
    }
    
    // 初始化Q的行列信息
    (*Q).mu = M.mu;
    (*Q).nu = M.nu;
    (*Q).tu = 0;
    
    m = n = k = 1;
    
    // 依次遍历M与N的三元组
    while(m <= M.tu && n <= N.tu) {
        // M中的三元组行下标较小
        if(M.data[m].i < N.data[n].i) {
            (*Q).data[k] = M.data[m];
            m++;
            
            // N中的三元组行下标较小
        } else if(M.data[m].i > N.data[n].i) {
            (*Q).data[k] = N.data[n];
            n++;
            
            // M与N中的三元组行下标一致，需要进一步比较列坐标
        } else {
            // M中的三元组列下标较小
            if(M.data[m].j < N.data[n].j) {
                (*Q).data[k] = M.data[m];
                m++;
                
                // N中的三元组列下标较小
            } else if(M.data[m].j > N.data[n].j) {
                (*Q).data[k] = N.data[n];
                n++;
                
                // M与N中的三元组列下标一致，需要进行加法运算
            } else {
                // 值已经加为0的话，不需要存储该元素
                if((M.data[m].e + N.data[n].e) == 0) {
                    m++;
                    n++;
                    continue;
                } else {
                    (*Q).data[k].i = M.data[m].i;
                    (*Q).data[k].j = M.data[m].j;
                    (*Q).data[k].e = M.data[m].e + N.data[n].e;
                    m++;
                    n++;
                }
            }
        }
        
        k++;
        (*Q).tu++;
    }
    
    // 遍历M中剩余的三元组
    while(m <= M.tu) {
        (*Q).data[k] = M.data[m];
        m++;
        k++;
        (*Q).tu++;
    }
    
    // 遍历N中剩余的三元组
    while(n <= N.tu) {
        (*Q).data[k] = N.data[n];
        n++;
        k++;
        (*Q).tu++;
    }
    
    // 为rpos数组赋值
    AssignRpos(Q);
    
    return OK;
}

/*
 * 矩阵减法
 *
 * Q = M - N。
 */
Status SubSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix* Q) {
    int m, n, k;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("两矩阵的行数、列数不满足相减条件！！\n");
        return ERROR;
    }
    
    // 初始化Q的行列信息
    (*Q).mu = M.mu;
    (*Q).nu = M.nu;
    (*Q).tu = 0;
    
    m = n = k = 1;
    
    // 依次遍历M与N的三元组
    while(m <= M.tu && n <= N.tu) {
        // M中的三元组行下标较小
        if(M.data[m].i < N.data[n].i) {
            (*Q).data[k] = M.data[m];
            m++;
            
            // N中的三元组行下标较小
        } else if(M.data[m].i > N.data[n].i) {
            (*Q).data[k].i = N.data[n].i;
            (*Q).data[k].j = N.data[n].j;
            (*Q).data[k].e = -N.data[n].e;  // 由于是相减，所以要对元素值取相反数
            n++;
            
            // M与N中的三元组行下标一致，需要进一步比较列坐标
        } else {
            // M中的三元组列下标较小
            if(M.data[m].j < N.data[n].j) {
                (*Q).data[k] = M.data[m];
                m++;
                
                // N中的三元组列下标较小
            } else if(M.data[m].j > N.data[n].j) {
                (*Q).data[k].i = N.data[n].i;
                (*Q).data[k].j = N.data[n].j;
                (*Q).data[k].e = -N.data[n].e;  // 由于是相减，所以要对元素值取相反数
                n++;
                
                // M与N中的三元组列下标一致，需要进行减法运算
            } else {
                // 值已经减为0的话，不需要存储该元素
                if((M.data[m].e - N.data[n].e) == 0) {
                    m++;
                    n++;
                    continue;
                } else {
                    (*Q).data[k].i = M.data[m].i;
                    (*Q).data[k].j = M.data[m].j;
                    (*Q).data[k].e = M.data[m].e - N.data[n].e;
                    m++;
                    n++;
                }
            }
        }
        
        k++;
        (*Q).tu++;
    }
    
    // 遍历M中剩余的三元组
    while(m <= M.tu) {
        (*Q).data[k] = M.data[m];
        m++;
        k++;
        (*Q).tu++;
    }
    
    // 遍历N中剩余的三元组
    while(n <= N.tu) {
        (*Q).data[k].i = N.data[n].i;
        (*Q).data[k].j = N.data[n].j;
        (*Q).data[k].e = -N.data[n].e;
        n++;
        k++;
        (*Q).tu++;
    }
    
    // 为rpos数组赋值
    AssignRpos(Q);
    
    return OK;
}

/*
 * ████████ 算法5.3 ████████
 *
 * 矩阵乘法
 *
 * Q = M * N。
 */
Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix* Q) {
    int arow, p, tp;
    int brow, q, tq;
    int ccol;
    int* ctemp;    // Q中各行元素值累加器，ctemp[0]单元弃用
    int i;
    
    // M的列数需要等于N的行数
    if(M.nu != N.mu) {
        printf("两矩阵的行数、列数不满足相乘条件！！\n");
        return ERROR;
    }
    
    // 初始化Q的行列信息
    (*Q).mu = M.mu;
    (*Q).nu = N.nu;
    (*Q).tu = 0;
    
    // 如果存在零矩阵
    if(M.tu * N.tu == 0) {
        return OK;
    }
    
    ctemp = (int*) malloc((N.nu + 1) * sizeof(int));
    
    // 处理M的每一行
    for(arow = 1; arow <= M.mu; ++arow) {
        // 初始化Q中行元素值计数器
        for(i = 0; i <= N.nu; ++i) {
            ctemp[i] = 0;
        }
        
        // tp指向M当前行的下一行第一个非零元位置
        if(arow < M.mu) {
            tp = M.rpos[arow + 1];
        } else {
            tp = M.tu + 1;
        }
        
        // 遍历M中arow行的所有非零元
        for(p = M.rpos[arow]; p < tp; ++p) {
            // 获取该非零元在N中的行号
            brow = M.data[p].j;
    
            // tq指向N当前行的下一行第一个非零元位置
            if(brow < N.mu) {
                tq = N.rpos[brow + 1];
            } else {
                tq = N.tu + 1;
            }
    
            // 遍历N中brow行的所有非零元
            for(q = N.rpos[brow]; q < tq; ++q) {
                // 乘积元素在Q中的列号
                ccol = N.data[q].j;
                
                // 累加乘积
                ctemp[ccol] += M.data[p].e * N.data[q].e;
            }
        }
    
        /*
         * 至此，Q中第arow行元素已求出
         */
        
        // 遍历计算后的乘积，选取非零元存入Q中
        for(ccol = 1; ccol <= (*Q).nu; ++ccol) {
            // 若Q中第arow行ccol列元素不为0
            if(ctemp[ccol]) {
                ++(*Q).tu;
                
                // 非零元个数超出限制
                if((*Q).tu > MAXSIZE) {
                    return ERROR;
                }
                
                (*Q).data[(*Q).tu].i = arow;
                (*Q).data[(*Q).tu].j = ccol;
                (*Q).data[(*Q).tu].e = ctemp[ccol];
            }
        }
    }
    
    // 为rpos数组赋值
    AssignRpos(Q);
    
    return OK;
}

/*
 * 矩阵转置
 */
Status TransposeSMatrix(RLSMatrix M, RLSMatrix* T) {
    int p, q, col;
    
    (*T).mu = M.nu;
    (*T).nu = M.mu;
    (*T).tu = M.tu;
    
    if((*T).tu) {
        q = 1;  // q用于T中非零元的计数
        
        // col代表M的列，T的行
        for(col = 1; col <= M.nu; ++col) {
            // 在M中查找第j列的元素，依次将其转置到T中
            for(p = 1; p <= M.tu; ++p) {
                if(M.data[p].j == col) {
                    (*T).data[q].i = M.data[p].j;     // M的列变为T的行
                    (*T).data[q].j = M.data[p].i;     // M的行变为T的列
                    (*T).data[q].e = M.data[p].e;     // 每个三元组值不变
                    
                    ++q;
                }
            }
        }
    }
    
    // 为rpos数组赋值
    AssignRpos(T);
    
    return OK;
}

/*
 * 矩阵快速转置
 */
Status FastTransposeSMatrix(RLSMatrix M, RLSMatrix* T) {
    int col, t, p, q;
    int* num;      // num[col] 表示M第col列中非零元的个数
    int* copt;     // copt[col]表示M第col列第一个非零元在转置后矩阵中的位置
    
    (*T).mu = M.nu;
    (*T).nu = M.mu;
    (*T).tu = M.tu;
    
    // 提前返回
    if((*T).tu == 0) {
        return ERROR;
    }
    
    num  = (int*) malloc((M.nu + 1) * sizeof(int));
    copt = (int*) malloc((M.nu + 1) * sizeof(int));
    
    // 初始化数组num
    for(col = 1; col <= M.nu; ++col) {
        num[col] = 0;
    }
    
    // 统计M中的非零元，统计每列非零元的个数
    for(t = 1; t <= M.tu; ++t) {
        num[M.data[t].j]++;
    }
    
    // 第1列第1个非零元总是位于转置后矩阵中的首位
    copt[1] = 1;
    // 计算各列第1个非零元在转置矩阵中的位置
    for(col = 2; col <= M.nu; ++col) {
        copt[col] = copt[col - 1] + num[col - 1];
    }
    
    // 依次扫描M中的三元组
    for(p = 1; p <= M.tu; ++p) {
        col = M.data[p].j;              // 计算当前非零元所处的列
        q = copt[col];                  // 计算当前非零元在转置矩阵中的位置
        (*T).data[q].i = M.data[p].j;
        (*T).data[q].j = M.data[p].i;
        (*T).data[q].e = M.data[p].e;
        ++copt[col];                    // 再遇到此列元素时，其在转置矩阵中的位置应当增一（该步骤很重要）
    }
    
    // 为rpos数组赋值
    AssignRpos(T);
    
    return OK;
}

/*
 * 输出矩阵
 */
void PrintSMatrix(RLSMatrix M) {
    int r, c;
    int k = 1;
    
    for(r = 1; r <= M.mu; ++r) {
        for(c = 1; c <= M.nu; ++c) {
            if(r == M.data[k].i && c == M.data[k].j) {
                printf("%3d ", M.data[k].e);
                k++;
            } else {
                printf("%3d ", 0);
            }
        }
        printf("\n");
    }
    
    printf("rpos = ");
    for(k = 1; k <= M.mu; ++k) {
        printf("%d ", M.rpos[k]);
    }
    printf("\n");
}

// 为rpos数组赋值
static void AssignRpos(RLSMatrix* M) {
    int k, m;
    
    // 初始化数组rpos
    for(k = 0; k <= MAXRC; ++k) {
        (*M).rpos[k] = 0;
    }
    
    for(k = 1; k <= (*M).tu; k++) {
        m = (*M).data[k].i;     // 当前三元组元素在矩阵中的行位置
        
        // 记录每行第一个非零元的在三元组表中的位置
        if((*M).rpos[m] == 0) {
            (*M).rpos[m] = k;   // 只会在当前行有非零元的情况下记录
        }
    }
    
    // 处理那些没有非零元的行
    for(k = (*M).mu; k >= 1; k--) {
        // 如果当前行没有非零元，则此处会直接取用下一行的参数
        if((*M).rpos[k] == 0) {
            // 如果是最后一行无非零元，因为已经不存在下一行了，所以需特殊处理
            if(k == (*M).mu) {
                (*M).rpos[k] = (*M).tu + 1;
            } else {
                (*M).rpos[k] = (*M).rpos[k + 1];
            }
        }
    }
}
