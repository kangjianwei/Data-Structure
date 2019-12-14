/*===================
 * ʮ������ϡ�����
 *
 * �����㷨: 5.4
 ====================*/

#include "CrossList.h"                        //**��05 ����͹����**//

/*
 * ���������������� �㷨5.4 ����������������
 *
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
Status CreateSMatrix(CrossList* M, char* path) {
    int i, j, k;
    OLNode* p, * q;
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("������������");
        scanf("%d", &((*M).mu));
        printf("������������");
        scanf("%d", &((*M).nu));
        printf("���������Ԫ�ظ�����");
        scanf("%d", &((*M).tu));
        printf("������%d����Ԫ����Ϣ\n", (*M).tu);
    } else {
        fp = fopen(path, "r");
        ReadData(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));
    }
    
    // ����������������������0�ŵ�Ԫ���ã�
    (*M).rhead = (OLink*) malloc(((*M).mu + 1) * sizeof(OLink));
    if((*M).rhead == NULL) {
        exit(OVERFLOW);
    }
    
    // ����������������������0�ŵ�Ԫ���ã�
    (*M).chead = (OLink*) malloc(((*M).nu + 1) * sizeof(OLink));
    if((*M).chead == NULL) {
        exit(OVERFLOW);
    }
    
    // ��ʼ����������ΪNULL
    for(k = 0; k <= (*M).mu; ++k) {
        (*M).rhead[k] = NULL;
    }
    
    // ��ʼ����������ΪNULL
    for(k = 0; k <= (*M).nu; ++k) {
        (*M).chead[k] = NULL;
    }
    
    // ����¼�����Ԫ
    for(k = 1; k <= (*M).tu; ++k) {
        // ������Ԫ����
        p = (OLNode*) malloc(sizeof(OLNode));
        if(p == NULL) {
            exit(OVERFLOW);
        }
        
        if(readFromConsole) {
            printf("��%2d�飺", k);
            scanf("%d%d%d", &i, &j, &(p->e));
        } else {
            ReadData(fp, "%d%d%d", &i, &j, &(p->e));
        }
        
        p->i = i;   // �к�
        p->j = j;   // �к�
        p->right = p->down = NULL;
        
        /*
         * ��ʼ�еĲ���
         */
        
        // ������л�û��Ԫ�أ�������Ԫ�ؾ�λ�ڸ�Ԫ���Ҳ࣬�����ֱ�Ӳ���
        if((*M).rhead[i] == NULL || (*M).rhead[i]->j > j) {
            // ��λ�б��еĲ���λ��
            p->right = (*M).rhead[i];
            (*M).rhead[i] = p;
        } else {
            // Ѱ�Ҳ���λ�õ�ǰһ��λ��
            for(q = (*M).rhead[i]; (q->right) && (q->right->j < j); q = q->right) {
            }
            
            if(q->j == p->j || ((q->right) && q->right->j == p->j)) {
                printf("��λ���ѱ�ռ�ã���\n");
                exit(ERROR);
            }
            
            p->right = q->right;
            q->right = p;
        }
        
        /*
         * ��ʼ�еĲ���
         */
        
        // ������л�û��Ԫ�أ�������Ԫ�ؾ�λ�ڸ�Ԫ���²࣬�����ֱ�Ӳ���
        if((*M).chead[j] == NULL || (*M).chead[j]->i > i) {
            // ��λ�б��еĲ���λ��
            p->down = (*M).chead[j];
            (*M).chead[j] = p;
        } else {
            // Ѱ�Ҳ���λ�õ�ǰһ��λ��
            for(q = (*M).chead[j]; (q->down) && (q->down->i < i); q = q->down) {
            }
            
            if(q->i == p->i || ((q->down) && q->down->i == p->i)) {
                printf("��λ���ѱ�ռ�ã���\n");
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
 * ����ϡ�����
 */
Status DestroySMatrix(CrossList* M) {
    int i;
    OLNode* p, * q;
    
    // ���۴Ӱ��л��ǰ��У�ֻ��Ҫ����һ������ȥ�������پͿ�����
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
 * ������
 *
 * ����һ���¾���T���þ�������˴Ӿ���M�а��������ݡ�
 */
Status CopySMatrix(CrossList M, CrossList* T) {
    int k;
    OLNode* p, * q, * r, * l;
    
    if(T == NULL) {
        return ERROR;
    }
    
    // ����������Ϣ
    (*T).mu = M.mu;
    (*T).nu = M.nu;
    (*T).tu = M.tu;
    
    // ����������������������0�ŵ�Ԫ���ã�
    (*T).rhead = (OLink*) malloc(((*T).mu + 1) * sizeof(OLink));
    if((*T).rhead == NULL) {
        exit(OVERFLOW);
    }
    
    // ����������������������0�ŵ�Ԫ���ã�
    (*T).chead = (OLink*) malloc(((*T).nu + 1) * sizeof(OLink));
    if((*T).chead == NULL) {
        exit(OVERFLOW);
    }
    
    // ��ʼ����������ΪNULL
    for(k = 0; k <= (*T).mu; ++k) {                                //��ʼ������ͷָ������Ϊ��
        (*T).rhead[k] = NULL;
    }
    
    // ��ʼ����������ΪNULL
    for(k = 0; k <= (*T).nu; ++k) {
        (*T).chead[k] = NULL;
    }
    
    // ����ɨ�裬���θ��Ʒ���Ԫ
    for(k = 1; k <= M.mu; ++k) {
        q = M.rhead[k];
        
        // �����ǰ��û��Ԫ�أ�ֱ������
        if(q == NULL) {
            continue;
        }
        
        r = NULL;
        
        while(q != NULL) {
            // ������Ԫ����
            p = (OLNode*) malloc(sizeof(OLNode));
            if(p == NULL) {
                exit(OVERFLOW);
            }
            
            // Ϊ��㸳ֵ
            p->i = q->i;
            p->j = q->j;
            p->e = q->e;
            p->right = p->down = NULL;
            
            /*
             * ��ʼ�еĲ���
             */
            
            if(r == NULL) {
                (*T).rhead[q->i] = p;
            } else {
                r->right = p;
            }
            
            // rָ��ǰ���²���Ľ��
            r = p;
            
            /*
             * ��ʼ�еĲ���
             */
            
            // ��������Ѱ�Ҳ���λ��
            if((*T).chead[q->j] == NULL || (*T).chead[q->j]->i > q->i) {
                r->down = (*T).chead[q->j];
                (*T).chead[q->j] = r;
            } else {
                // Ѱ�Ҳ���λ�õ�ǰһ��λ��
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
 * ����ӷ�
 *
 * Q = M + N��
 */
Status AddSMatrix(CrossList M, CrossList N, CrossList* Q) {
    int i;
    OLNode* pm, * pn, * p, * r, * l;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // ��ʼ��Q��������Ϣ
    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;
    
    // ����������������������0�ŵ�Ԫ���ã�
    Q->rhead = (OLink*) malloc((Q->mu + 1) * sizeof(OLink));
    if(!Q->rhead) {
        exit(OVERFLOW);
    }
    
    // ����������������������0�ŵ�Ԫ���ã�
    Q->chead = (OLink*) malloc((Q->nu + 1) * sizeof(OLink));
    if(!Q->chead) {
        exit(OVERFLOW);
    }
    
    // ��ʼ����������ΪNULL
    for(i = 0; i <= Q->mu; ++i) {
        Q->rhead[i] = NULL;
    }
    
    // ��ʼ����������ΪNULL
    for(i = 0; i <= Q->nu; ++i) {
        Q->chead[i] = NULL;
    }
    
    // �ӵ�һ�����±���
    for(i = 1; i <= M.mu; ++i) {
        pm = M.rhead[i];
        pn = N.rhead[i];
        
        // ���M��N�ĵ�ǰ���о���δ����ķ���Ԫ
        while(pm != NULL && pn != NULL) {
            // ������������
            if(pm->j == pn->j && pm->e + pn->e == 0) {
                pm = pm->right;
                pn = pn->right;
                continue;
            }
            
            // �������
            p = (OLNode*) malloc(sizeof(OLNode));
            if(!p) {
                exit(OVERFLOW);
            }
            
            // M�е���Ԫ�����±��С
            if(pm->j < pn->j) {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e;
                pm = pm->right;
                
                // N�е���Ԫ�����±��С
            } else if(pm->j > pn->j) {
                p->i = pn->i;
                p->j = pn->j;
                p->e = pn->e;
                pn = pn->right;
                
                // M��N�е���Ԫ�����±�һ�£���Ҫ���мӷ�����
            } else {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e + pn->e;
                pm = pm->right;
                pn = pn->right;
            }
            
            p->right = p->down = NULL;
            
            Q->tu++;    // Q�з���Ԫ������һ
            
            /*
             * ��ʼ�еĲ���
             */
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // rָ��ǰ���²���Ľ��
            r = p;
            
            /*
             * ��ʼ�еĲ���
             */
            
            // ��������Ѱ�Ҳ���λ��
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                // Ѱ�Ҳ���λ�õ�ǰһ��λ��
                for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
        }
        
        // ���M�ĵ�ǰ��������δ����ķ���Ԫ
        while(pm != NULL) {
            p = (OLNode*) malloc(sizeof(OLNode));
            if(p == NULL) {
                exit(OVERFLOW);
            }
            p->i = pm->i;
            p->j = pm->j;
            p->e = pm->e;
            p->right = p->down = NULL;
            
            Q->tu++;    // Q�з���Ԫ������һ
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // rָ��ǰ���²���Ľ��
            r = p;
            
            // ��������Ѱ�Ҳ���λ��
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                // Ѱ�Ҳ���λ�õ�ǰһ��λ��
                for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
            
            pm = pm->right;
        }
        
        // ���N�ĵ�ǰ��������δ����ķ���Ԫ
        while(pn != NULL) {
            p = (OLNode*) malloc(sizeof(OLNode));
            if(p == NULL) {
                exit(OVERFLOW);
            }
            p->i = pn->i;
            p->j = pn->j;
            p->e = pn->e;
            p->right = p->down = NULL;
            
            Q->tu++;    // Q�з���Ԫ������һ
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // rָ��ǰ���²���Ľ��
            r = p;
            
            // ��������Ѱ�Ҳ���λ��
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                // Ѱ�Ҳ���λ�õ�ǰһ��λ��
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
 * �������
 *
 * Q = M - N��
 */
Status SubSMatrix(CrossList M, CrossList N, CrossList* Q) {
    int i;
    OLNode* pm, * pn, * p, * r, * l;
    
    if(M.mu != N.mu || M.nu != N.nu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // ��ʼ��Q��������Ϣ
    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;
    
    // ����������������������0�ŵ�Ԫ���ã�
    Q->rhead = (OLink*) malloc((Q->mu + 1) * sizeof(OLink));
    if(!Q->rhead) {
        exit(OVERFLOW);
    }
    
    // ����������������������0�ŵ�Ԫ���ã�
    Q->chead = (OLink*) malloc((Q->nu + 1) * sizeof(OLink));
    if(!Q->chead) {
        exit(OVERFLOW);
    }
    
    // ��ʼ����������ΪNULL
    for(i = 0; i <= Q->mu; ++i) {
        Q->rhead[i] = NULL;
    }
    
    // ��ʼ����������ΪNULL
    for(i = 0; i <= Q->nu; ++i) {
        Q->chead[i] = NULL;
    }
    
    // �ӵ�һ�����±���
    for(i = 1; i <= M.mu; ++i) {
        pm = M.rhead[i];
        pn = N.rhead[i];
        
        // ���M��N�ĵ�ǰ���о���δ����ķ���Ԫ
        while(pm != NULL && pn != NULL) {
            // ������������
            if(pm->j == pn->j && pm->e - pn->e == 0) {
                pm = pm->right;
                pn = pn->right;
                continue;
            }
            
            // �������
            p = (OLNode*) malloc(sizeof(OLNode));
            if(!p) {
                exit(OVERFLOW);
            }
            
            // M�е���Ԫ�����±��С
            if(pm->j < pn->j) {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e;
                pm = pm->right;
                
                // N�е���Ԫ�����±��С
            } else if(pm->j > pn->j) {
                p->i = pn->i;
                p->j = pn->j;
                p->e = -pn->e;      // �Ӹ���
                pn = pn->right;
                
                // M��N�е���Ԫ�����±�һ�£���Ҫ���м�������
            } else {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e - pn->e;
                pm = pm->right;
                pn = pn->right;
            }
            
            p->right = p->down = NULL;
            
            Q->tu++;    // Q�з���Ԫ������һ
            
            /*
             * ��ʼ�еĲ���
             */
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // rָ��ǰ���²���Ľ��
            r = p;
            
            /*
             * ��ʼ�еĲ���
             */
            
            // ��������Ѱ�Ҳ���λ��
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                //Ѱ�Ҳ���λ�õ�ǰһ��λ��
                for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
        }
        
        // ���M�ĵ�ǰ��������δ����ķ���Ԫ
        while(pm != NULL) {
            p = (OLNode*) malloc(sizeof(OLNode));
            if(!p) {
                exit(OVERFLOW);
            }
            p->i = pm->i;
            p->j = pm->j;
            p->e = pm->e;
            p->right = p->down = NULL;
            
            Q->tu++;    // Q�з���Ԫ������һ
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // rָ��ǰ���²���Ľ��
            r = p;
            
            // ��������Ѱ�Ҳ���λ��
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                // Ѱ�Ҳ���λ�õ�ǰһ��λ��
                for(l = Q->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down) {
                }
                r->down = l->down;
                l->down = r;
            }
            
            pm = pm->right;
        }
        
        // ���N�ĵ�ǰ��������δ����ķ���Ԫ
        while(pn != NULL) {
            p = (OLNode*) malloc(sizeof(OLNode));
            if(!p) {
                exit(OVERFLOW);
            }
            p->i = pn->i;
            p->j = pn->j;
            p->e = -pn->e;              // �Ӹ���
            p->right = p->down = NULL;
            
            Q->tu++;    // Q�з���Ԫ������һ
            
            if(Q->rhead[p->i] == NULL) {
                Q->rhead[p->i] = p;
            } else {
                r->right = p;
            }
            
            // rָ��ǰ���²���Ľ��
            r = p;
            
            // ��������Ѱ�Ҳ���λ��
            if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                // Ѱ�Ҳ���λ�õ�ǰһ��λ��
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
 * ����˷�
 *
 * Q = M * N��
 */
Status MultSMatrix(CrossList M, CrossList N, CrossList* Q) {
    int m_row, n_col, i;
    ElemType e;
    OLNode* pm, * pn, * p, * r, * l;
    
    // M��������Ҫ����N������
    if(M.nu != N.mu) {
        printf("����������������������������������\n");
        return ERROR;
    }
    
    // ��ʼ��Q��������Ϣ
    Q->mu = M.mu;
    Q->nu = N.nu;
    Q->tu = 0;
    
    // ����������������������0�ŵ�Ԫ���ã�
    Q->rhead = (OLink*) malloc((Q->mu + 1) * sizeof(OLink));
    if(!Q->rhead) {
        exit(OVERFLOW);
    }
    
    // ����������������������0�ŵ�Ԫ���ã�
    Q->chead = (OLink*) malloc((Q->nu + 1) * sizeof(OLink));
    if(!Q->chead) {
        exit(OVERFLOW);
    }
    
    // ��ʼ����������ΪNULL
    for(i = 0; i <= Q->mu; ++i) {
        Q->rhead[i] = NULL;
    }
    
    // ��ʼ����������ΪNULL
    for(i = 0; i <= Q->nu; ++i) {
        Q->chead[i] = NULL;
    }
    
    // Q�Ƿ������
    if(M.tu * N.tu) {
        for(m_row = 1; m_row <= M.mu; ++m_row) {
            for(n_col = 1; n_col <= N.nu; ++n_col) {
                pm = M.rhead[m_row];
                pn = N.chead[n_col];
                
                e = 0;
                
                // M������N�������
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
                
                // Ϊ��㸳ֵ
                p->i = M.rhead[m_row]->i;
                p->j = N.chead[n_col]->j;
                p->e = e;
                p->right = p->down = NULL;
                
                Q->tu++;    // Q�з���Ԫ������һ
                
                if(Q->rhead[p->i] == NULL) {
                    Q->rhead[p->i] = p;
                } else {
                    r->right = p;
                }
                
                // rָ��ǰ���²���Ľ��
                r = p;
                
                // ��������Ѱ�Ҳ���λ��
                if(Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                    r->down = Q->chead[p->j];
                    Q->chead[p->j] = r;
                } else {
                    // Ѱ�Ҳ���λ�õ�ǰһ��λ��
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
 * ����ת��
 */
Status TransposeSMatrix(CrossList M, CrossList* T) {
    int i;
    OLNode* p, * q, * r, * l;
    
    // ��ʼ��Q��������Ϣ
    (*T).mu = M.nu;
    (*T).nu = M.mu;
    (*T).tu = M.tu;
    
    // ����������������������0�ŵ�Ԫ���ã�
    (*T).rhead = (OLink*) malloc(((*T).mu + 1) * sizeof(OLink));
    if(!(*T).rhead) {
        exit(OVERFLOW);
    }
    
    // ����������������������0�ŵ�Ԫ���ã�
    (*T).chead = (OLink*) malloc(((*T).nu + 1) * sizeof(OLink));
    if(!(*T).chead) {
        exit(OVERFLOW);
    }
    
    // ��ʼ����������ΪNULL
    for(i = 0; i <= (*T).mu; ++i) {
        (*T).rhead[i] = NULL;
    }
    
    // ��ʼ����������ΪNULL
    for(i = 0; i <= (*T).nu; ++i) {
        (*T).chead[i] = NULL;
    }
    
    // �����
    if(!(*T).tu) {
        return OK;
    }
    
    // ����ɨ��
    for(i = 1; i <= M.nu; ++i) {
        q = M.chead[i];
        
        // �����ǰ��û��Ԫ�أ�ֱ������
        if(q == NULL) {
            continue;
        }
        
        while(q != NULL) {
            // ������Ԫ����
            p = (OLNode*) malloc(sizeof(OLNode));
            if(!p) {
                exit(OVERFLOW);
            }
            
            // Ϊ��㸳ֵ���б��У��б���
            p->i = q->j;
            p->j = q->i;
            p->e = q->e;
            p->right = p->down = NULL;
    
            /*
             * ��ʼ�еĲ���
             */
            
            if((*T).rhead[p->i] == NULL) {
                (*T).rhead[p->i] = p;
            } else {
                r->right = p;
            }
    
            // rָ��ǰ���²���Ľ��
            r = p;
    
            /*
             * ��ʼ�еĲ���
             */
    
            // ��������Ѱ�Ҳ���λ��
            if((*T).chead[p->j] == NULL || (*T).chead[p->j]->i > p->i) {
                r->down = (*T).chead[p->j];
                (*T).chead[p->j] = r;
            } else {
                // Ѱ�Ҳ���λ�õ�ǰһ��λ��
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
 * �������
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
