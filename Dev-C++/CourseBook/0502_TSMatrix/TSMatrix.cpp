/*=======================
 * ��Ԫ��˳���ϡ�����
 *
 * �����㷨: 5.1��5.2
 ========================*/

#include "TSMatrix.h"   //**��05 ����͹����**//

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
Status CreateSMatrix(TSMatrix* M, char* path) {
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
    
    return OK;
}

/*
 * ����ϡ�����
 *
 *��ע��
 * ��Ԫ��˳���Ľṹ�޷����١�
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
 * ������
 *
 * ����һ���¾���T���þ�������˴Ӿ���M�а��������ݡ�
 */
Status CopySMatrix(TSMatrix M, TSMatrix* T) {
    (*T) = M;   // �ṹ��֮�����ֱ�Ӹ��ƣ���ʹ�ڲ���������Ҳ����
    
    return OK;
}

/*
 * ����ӷ�
 *
 * Q = M + N��
 */
Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q) {
    int m, n, k;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // ��ʼ��Q
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
    
    return OK;
}

/*
 * �������
 *
 * Q = M - N��
 */
Status SubSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q) {
    int m, n, k;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // ��ʼ��Q
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
    
    return OK;
}

/*
 * ����˷�
 *
 * Q = M * N������ʵ�ֵ��Ǵ�ͳ����˷���
 */
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q) {
    int m, n, i, j, k;
    ElemType c, c1, c2;
    
    // M��������Ҫ����N������
    if(M.nu != N.mu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // ��ʼ��Q
    (*Q).mu = M.mu;
    (*Q).nu = N.nu;
    (*Q).tu = 0;
    
    // ������������
    if(M.tu * N.tu == 0) {
        return OK;
    }
    
    // ��������M����
    for(i = 1; i <= M.mu; i++) {
        // ��������N����
        for(j = 1; j <= N.nu; j++) {
            c = 0;
            for(k = 1; k <= M.nu; k++) {
                // ��¼M[i][k]��ֵ
                c1 = 0;
                // ����Ѱ��λ��ָ��λ�õ�M��Ԫ��
                for(m = 1; m <= M.tu; m++) {
                    if(M.data[m].i == i && M.data[m].j == k) {
                        c1 = M.data[m].e;
                        break;
                    }
                }
                
                // ��¼N[k][j]��ֵ
                c2 = 0;
                //����Ѱ��λ��ָ��λ�õ�N��Ԫ��
                for(n = 1; n <= N.tu; n++) {
                    if(N.data[n].i == k && N.data[n].j == j) {
                        c2 = N.data[n].e;
                        break;
                    }
                }
                
                // ����Q[i][j]��ֵ
                if(c1 && c2) {
                    c += c1 * c2;
                }
            }
            
            // �����������Ϊ0������д洢
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
 * ���������������� �㷨5.1 ����������������
 *
 * ����ת��
 */
Status TransposeSMatrix(TSMatrix M, TSMatrix* T) {
    int p, q, col;
    
    (*T).mu = M.nu;
    (*T).nu = M.mu;
    (*T).tu = M.tu;
    
    if((*T).tu != 0) {
        q = 1;  // q����T�з���Ԫ�ļ���
        
        // col����M���У�T����
        for(col = 1; col <= M.nu; ++col) {
            // ��M�в��ҵ�j�е�Ԫ�أ����ν���ת�õ�T��
            for(p = 1; p <= M.tu; ++p) {
                if(M.data[p].j == col) {
                    (*T).data[q].i = M.data[p].j;    // M���б�ΪT����
                    (*T).data[q].j = M.data[p].i;    // M���б�ΪT����
                    (*T).data[q].e = M.data[p].e;    // ÿ����Ԫ��ֵ����
                    ++q;
                }
            }
        }
    }
    
    return OK;
}

/*
 * ���������������� �㷨5.2 ����������������
 *
 * �������ת��
 */
Status FastTransposeSMatrix(TSMatrix M, TSMatrix* T) {
    int col, t, p, q;
    int* num;       // num[col] ��ʾM��col���з���Ԫ�ĸ���
    int* copt;      // copt[col]��ʾM��col�е�һ������Ԫ��ת�ú�����е�λ��
    
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
        col = M.data[p].j;                // ���㵱ǰ����Ԫ��������
        q = copt[col];                    // ���㵱ǰ����Ԫ��ת�þ����е�λ��
        (*T).data[q].i = M.data[p].j;
        (*T).data[q].j = M.data[p].i;
        (*T).data[q].e = M.data[p].e;
        ++copt[col];                      // ����������Ԫ��ʱ������ת�þ����е�λ��Ӧ����һ���ò������Ҫ��
    }
    
    return OK;
}

/*
 * �������
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
