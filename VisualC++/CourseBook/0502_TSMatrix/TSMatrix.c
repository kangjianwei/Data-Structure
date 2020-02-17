/*=======================
 * 三元组顺序表（稀疏矩阵）
 *
 * 包含算法: 5.1、5.2
 ========================*/

#include "TSMatrix.h"   //**▲05 数组和广义表**//

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
Status CreateSMatrix(TSMatrix* M, char* path) {
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
    
    return OK;
}

/*
 * 销毁稀疏矩阵
 *
 *【注】
 * 三元组顺序表的结构无法销毁。
 */
Status DestroySMatrix(TSMatrix* M) {
    if(M == NULL) {
        return ERROR;
    }
    
    (*M).mu = 0;
    (*M).nu = 0;
    (*M).tu = 0;
    
    return OK;
}

/*
 * 矩阵复制
 *
 * 创建一个新矩阵T，该矩阵包含了从矩阵M中包含的数据。
 */
Status CopySMatrix(TSMatrix M, TSMatrix* T) {
    (*T) = M;   // 结构体之间可以直接复制，即使内部包含数组也可以
    
    return OK;
}

/*
 * 矩阵加法
 *
 * Q = M + N。
 */
Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q) {
    int m, n, k;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("两矩阵的行数、列数不满足相加条件！！\n");
        return ERROR;
    }
    
    // 初始化Q
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
    
    return OK;
}

/*
 * 矩阵减法
 *
 * Q = M - N。
 */
Status SubSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q) {
    int m, n, k;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("两矩阵的行数、列数不满足相减条件！！\n");
        return ERROR;
    }
    
    // 初始化Q
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
    
    return OK;
}

/*
 * 矩阵乘法
 *
 * Q = M * N，这里实现的是传统矩阵乘法。
 */
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q) {
    int m, n, i, j, k;
    ElemType c, c1, c2;
    
    // M的列数需要等于N的行数
    if(M.nu != N.mu) {
        printf("两矩阵的行数、列数不满足相乘条件！！\n");
        return ERROR;
    }
    
    // 初始化Q
    (*Q).mu = M.mu;
    (*Q).nu = N.nu;
    (*Q).tu = 0;
    
    // 如果存在零矩阵
    if(M.tu * N.tu == 0) {
        return OK;
    }
    
    // 遍历矩阵M的行
    for(i = 1; i <= M.mu; i++) {
        // 遍历矩阵N的列
        for(j = 1; j <= N.nu; j++) {
            c = 0;
            for(k = 1; k <= M.nu; k++) {
                // 记录M[i][k]的值
                c1 = 0;
                // 依次寻找位于指定位置的M三元组
                for(m = 1; m <= M.tu; m++) {
                    if(M.data[m].i == i && M.data[m].j == k) {
                        c1 = M.data[m].e;
                        break;
                    }
                }
                
                // 记录N[k][j]的值
                c2 = 0;
                //依次寻找位于指定位置的N三元组
                for(n = 1; n <= N.tu; n++) {
                    if(N.data[n].i == k && N.data[n].j == j) {
                        c2 = N.data[n].e;
                        break;
                    }
                }
                
                // 计算Q[i][j]的值
                if(c1 && c2) {
                    c += c1 * c2;
                }
            }
            
            // 如果计算结果不为0，则进行存储
            if(c != 0) {
                (*Q).tu++;
                (*Q).data[(*Q).tu].i = i;
                (*Q).data[(*Q).tu].j = j;
                (*Q).data[(*Q).tu].e = c;
            }
        }
    }
    
    return OK;
}

/*
 * ████████ 算法5.1 ████████
 *
 * 矩阵转置
 */
Status TransposeSMatrix(TSMatrix M, TSMatrix* T) {
    int p, q, col;
    
    (*T).mu = M.nu;
    (*T).nu = M.mu;
    (*T).tu = M.tu;
    
    if((*T).tu != 0) {
        q = 1;  // q用于T中非零元的计数
        
        // col代表M的列，T的行
        for(col = 1; col <= M.nu; ++col) {
            // 在M中查找第j列的元素，依次将其转置到T中
            for(p = 1; p <= M.tu; ++p) {
                if(M.data[p].j == col) {
                    (*T).data[q].i = M.data[p].j;    // M的列变为T的行
                    (*T).data[q].j = M.data[p].i;    // M的行变为T的列
                    (*T).data[q].e = M.data[p].e;    // 每个三元组值不变
                    ++q;
                }
            }
        }
    }
    
    return OK;
}

/*
 * ████████ 算法5.2 ████████
 *
 * 矩阵快速转置
 */
Status FastTransposeSMatrix(TSMatrix M, TSMatrix* T) {
    int col, t, p, q;
    int* num;       // num[col] 表示M第col列中非零元的个数
    int* copt;      // copt[col]表示M第col列第一个非零元在转置后矩阵中的位置
    
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
        col = M.data[p].j;                // 计算当前非零元所处的列
        q = copt[col];                    // 计算当前非零元在转置矩阵中的位置
        (*T).data[q].i = M.data[p].j;
        (*T).data[q].j = M.data[p].i;
        (*T).data[q].e = M.data[p].e;
        ++copt[col];                      // 再遇到此列元素时，其在转置矩阵中的位置应当增一（该步骤很重要）
    }
    
    return OK;
}

/*
 * 输出矩阵
 */
void PrintSMatrix(TSMatrix M) {
    int r, c;
    int k = 1;
    
    for(r = 1; r <= M.mu; r++) {
        for(c = 1; c <= M.nu; c++) {
            if(r == M.data[k].i && c == M.data[k].j) {
                printf("%3d ", M.data[k].e);
                k++;
            } else {
                printf("%3d ", 0);
            }
        }
        printf("\n");
    }
}
