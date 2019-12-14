/*=============================
 * ���߼����ӵ�˳���ϡ�����
 *
 * �����㷨: 5.3
 ==============================*/

#include "RLSMatrix.h"  //**��05 ����͹����**//

/*
 * ����ϡ�����M
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status CreateSMatrix(RLSMatrix* M, char* path) {
    int k;
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    if(readFromConsole) {
        printf("������������");
        scanf("%d", &((*M).mu));
        printf("������������");
        scanf("%d", &((*M).nu));
        printf("���������Ԫ�ظ�����");
        scanf("%d", &((*M).tu));
        printf("������%d����Ԫ����Ϣ\n", (*M).tu);
        for(k = 1; k <= (*M).tu; k++) {
            printf("��%2d�飺", k);
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
    
    // Ϊrpos���鸳ֵ
    AssignRpos(M);
    
    return OK;
}

/*
 * ����ϡ�����
 *
 *��ע��
 * ���߼����ӵ�˳���ṹ�޷����١�
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
 * ������
 *
 * ����һ���¾���T���þ�������˴Ӿ���M�а��������ݡ�
 */
Status CopySMatrix(RLSMatrix M, RLSMatrix* T) {
    (*T) = M;   // �ṹ��֮�����ֱ�Ӹ��ƣ���ʹ�ڲ���������Ҳ����
    
    return OK;
}

/*
 * ����ӷ�
 *
 * Q = M + N��
 */
Status AddSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix* Q) {
    int m, n, k;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // ��ʼ��Q��������Ϣ
    (*Q).mu = M.mu;
    (*Q).nu = M.nu;
    (*Q).tu = 0;
    
    m = n = k = 1;
    
    // ���α���M��N����Ԫ��
    while(m <= M.tu && n <= N.tu) {
        // M�е���Ԫ�����±��С
        if(M.data[m].i < N.data[n].i) {
            (*Q).data[k] = M.data[m];
            m++;
            
            // N�е���Ԫ�����±��С
        } else if(M.data[m].i > N.data[n].i) {
            (*Q).data[k] = N.data[n];
            n++;
            
            // M��N�е���Ԫ�����±�һ�£���Ҫ��һ���Ƚ�������
        } else {
            // M�е���Ԫ�����±��С
            if(M.data[m].j < N.data[n].j) {
                (*Q).data[k] = M.data[m];
                m++;
                
                // N�е���Ԫ�����±��С
            } else if(M.data[m].j > N.data[n].j) {
                (*Q).data[k] = N.data[n];
                n++;
                
                // M��N�е���Ԫ�����±�һ�£���Ҫ���мӷ�����
            } else {
                // ֵ�Ѿ���Ϊ0�Ļ�������Ҫ�洢��Ԫ��
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
    
    // ����M��ʣ�����Ԫ��
    while(m <= M.tu) {
        (*Q).data[k] = M.data[m];
        m++;
        k++;
        (*Q).tu++;
    }
    
    // ����N��ʣ�����Ԫ��
    while(n <= N.tu) {
        (*Q).data[k] = N.data[n];
        n++;
        k++;
        (*Q).tu++;
    }
    
    // Ϊrpos���鸳ֵ
    AssignRpos(Q);
    
    return OK;
}

/*
 * �������
 *
 * Q = M - N��
 */
Status SubSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix* Q) {
    int m, n, k;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // ��ʼ��Q��������Ϣ
    (*Q).mu = M.mu;
    (*Q).nu = M.nu;
    (*Q).tu = 0;
    
    m = n = k = 1;
    
    // ���α���M��N����Ԫ��
    while(m <= M.tu && n <= N.tu) {
        // M�е���Ԫ�����±��С
        if(M.data[m].i < N.data[n].i) {
            (*Q).data[k] = M.data[m];
            m++;
            
            // N�е���Ԫ�����±��С
        } else if(M.data[m].i > N.data[n].i) {
            (*Q).data[k].i = N.data[n].i;
            (*Q).data[k].j = N.data[n].j;
            (*Q).data[k].e = -N.data[n].e;  // ���������������Ҫ��Ԫ��ֵȡ�෴��
            n++;
            
            // M��N�е���Ԫ�����±�һ�£���Ҫ��һ���Ƚ�������
        } else {
            // M�е���Ԫ�����±��С
            if(M.data[m].j < N.data[n].j) {
                (*Q).data[k] = M.data[m];
                m++;
                
                // N�е���Ԫ�����±��С
            } else if(M.data[m].j > N.data[n].j) {
                (*Q).data[k].i = N.data[n].i;
                (*Q).data[k].j = N.data[n].j;
                (*Q).data[k].e = -N.data[n].e;  // ���������������Ҫ��Ԫ��ֵȡ�෴��
                n++;
                
                // M��N�е���Ԫ�����±�һ�£���Ҫ���м�������
            } else {
                // ֵ�Ѿ���Ϊ0�Ļ�������Ҫ�洢��Ԫ��
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
    
    // ����M��ʣ�����Ԫ��
    while(m <= M.tu) {
        (*Q).data[k] = M.data[m];
        m++;
        k++;
        (*Q).tu++;
    }
    
    // ����N��ʣ�����Ԫ��
    while(n <= N.tu) {
        (*Q).data[k].i = N.data[n].i;
        (*Q).data[k].j = N.data[n].j;
        (*Q).data[k].e = -N.data[n].e;
        n++;
        k++;
        (*Q).tu++;
    }
    
    // Ϊrpos���鸳ֵ
    AssignRpos(Q);
    
    return OK;
}

/*
 * ���������������� �㷨5.3 ����������������
 *
 * ����˷�
 *
 * Q = M * N��
 */
Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix* Q) {
    int arow, p, tp;
    int brow, q, tq;
    int ccol;
    int* ctemp;    // Q�и���Ԫ��ֵ�ۼ�����ctemp[0]��Ԫ����
    int i;
    
    // M��������Ҫ����N������
    if(M.nu != N.mu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // ��ʼ��Q��������Ϣ
    (*Q).mu = M.mu;
    (*Q).nu = N.nu;
    (*Q).tu = 0;
    
    // ������������
    if(M.tu * N.tu == 0) {
        return OK;
    }
    
    ctemp = (int*) malloc((N.nu + 1) * sizeof(int));
    
    // ����M��ÿһ��
    for(arow = 1; arow <= M.mu; ++arow) {
        // ��ʼ��Q����Ԫ��ֵ������
        for(i = 0; i <= N.nu; ++i) {
            ctemp[i] = 0;
        }
        
        // tpָ��M��ǰ�е���һ�е�һ������Ԫλ��
        if(arow < M.mu) {
            tp = M.rpos[arow + 1];
        } else {
            tp = M.tu + 1;
        }
        
        // ����M��arow�е����з���Ԫ
        for(p = M.rpos[arow]; p < tp; ++p) {
            // ��ȡ�÷���Ԫ��N�е��к�
            brow = M.data[p].j;
    
            // tqָ��N��ǰ�е���һ�е�һ������Ԫλ��
            if(brow < N.mu) {
                tq = N.rpos[brow + 1];
            } else {
                tq = N.tu + 1;
            }
    
            // ����N��brow�е����з���Ԫ
            for(q = N.rpos[brow]; q < tq; ++q) {
                // �˻�Ԫ����Q�е��к�
                ccol = N.data[q].j;
                
                // �ۼӳ˻�
                ctemp[ccol] += M.data[p].e * N.data[q].e;
            }
        }
    
        /*
         * ���ˣ�Q�е�arow��Ԫ�������
         */
        
        // ���������ĳ˻���ѡȡ����Ԫ����Q��
        for(ccol = 1; ccol <= (*Q).nu; ++ccol) {
            // ��Q�е�arow��ccol��Ԫ�ز�Ϊ0
            if(ctemp[ccol]) {
                ++(*Q).tu;
                
                // ����Ԫ������������
                if((*Q).tu > MAXSIZE) {
                    return ERROR;
                }
                
                (*Q).data[(*Q).tu].i = arow;
                (*Q).data[(*Q).tu].j = ccol;
                (*Q).data[(*Q).tu].e = ctemp[ccol];
            }
        }
    }
    
    // Ϊrpos���鸳ֵ
    AssignRpos(Q);
    
    return OK;
}

/*
 * ����ת��
 */
Status TransposeSMatrix(RLSMatrix M, RLSMatrix* T) {
    int p, q, col;
    
    (*T).mu = M.nu;
    (*T).nu = M.mu;
    (*T).tu = M.tu;
    
    if((*T).tu) {
        q = 1;  // q����T�з���Ԫ�ļ���
        
        // col����M���У�T����
        for(col = 1; col <= M.nu; ++col) {
            // ��M�в��ҵ�j�е�Ԫ�أ����ν���ת�õ�T��
            for(p = 1; p <= M.tu; ++p) {
                if(M.data[p].j == col) {
                    (*T).data[q].i = M.data[p].j;     // M���б�ΪT����
                    (*T).data[q].j = M.data[p].i;     // M���б�ΪT����
                    (*T).data[q].e = M.data[p].e;     // ÿ����Ԫ��ֵ����
                    
                    ++q;
                }
            }
        }
    }
    
    // Ϊrpos���鸳ֵ
    AssignRpos(T);
    
    return OK;
}

/*
 * �������ת��
 */
Status FastTransposeSMatrix(RLSMatrix M, RLSMatrix* T) {
    int col, t, p, q;
    int* num;      // num[col] ��ʾM��col���з���Ԫ�ĸ���
    int* copt;     // copt[col]��ʾM��col�е�һ������Ԫ��ת�ú�����е�λ��
    
    (*T).mu = M.nu;
    (*T).nu = M.mu;
    (*T).tu = M.tu;
    
    // ��ǰ����
    if((*T).tu == 0) {
        return ERROR;
    }
    
    num  = (int*) malloc(M.nu * sizeof(int));
    copt = (int*) malloc(M.nu * sizeof(int));
    
    // ��ʼ������num
    for(col = 1; col <= M.nu; ++col) {
        num[col] = 0;
    }
    
    // ͳ��M�еķ���Ԫ��ͳ��ÿ�з���Ԫ�ĸ���
    for(t = 1; t <= M.tu; ++t) {
        num[M.data[t].j]++;
    }
    
    // ��1�е�1������Ԫ����λ��ת�ú�����е���λ
    copt[1] = 1;
    // ������е�1������Ԫ��ת�þ����е�λ��
    for(col = 2; col <= M.nu; ++col) {
        copt[col] = copt[col - 1] + num[col - 1];
    }
    
    // ����ɨ��M�е���Ԫ��
    for(p = 1; p <= M.tu; ++p) {
        col = M.data[p].j;              // ���㵱ǰ����Ԫ��������
        q = copt[col];                  // ���㵱ǰ����Ԫ��ת�þ����е�λ��
        (*T).data[q].i = M.data[p].j;
        (*T).data[q].j = M.data[p].i;
        (*T).data[q].e = M.data[p].e;
        ++copt[col];                    // ����������Ԫ��ʱ������ת�þ����е�λ��Ӧ����һ���ò������Ҫ��
    }
    
    // Ϊrpos���鸳ֵ
    AssignRpos(T);
    
    return OK;
}

/*
 * �������
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

// Ϊrpos���鸳ֵ
static void AssignRpos(RLSMatrix* M) {
    int k, m;
    
    // ��ʼ������rpos
    for(k = 0; k <= MAXRC; ++k) {
        (*M).rpos[k] = 0;
    }
    
    for(k = 1; k <= (*M).tu; k++) {
        m = (*M).data[k].i;     // ��ǰ��Ԫ��Ԫ���ھ����е���λ��
        
        // ��¼ÿ�е�һ������Ԫ������Ԫ����е�λ��
        if((*M).rpos[m] == 0) {
            (*M).rpos[m] = k;   // ֻ���ڵ�ǰ���з���Ԫ������¼�¼
        }
    }
    
    // ������Щû�з���Ԫ����
    for(k = (*M).mu; k >= 1; k--) {
        // �����ǰ��û�з���Ԫ����˴���ֱ��ȡ����һ�еĲ���
        if((*M).rpos[k] == 0) {
            // ��������һ���޷���Ԫ����Ϊ�Ѿ���������һ���ˣ����������⴦��
            if(k == (*M).mu) {
                (*M).rpos[k] = (*M).tu + 1;
            } else {
                (*M).rpos[k] = (*M).rpos[k + 1];
            }
        }
    }
}
