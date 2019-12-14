/*==============================
 * ����
 *
 * �����㷨: 6.8��6.9��6.10��6.11
 ===============================*/

#include "MFSet.h"

/*
 * ��ʼ��һ���ɶ���Ӽ���ÿ���Ӽ�ֻ����������Ա�����ɵļ���S��
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
Status initial_mfset(MFSet* S, char* path) {
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("�����뼯�ϵ�Ԫ����Ϣ...\n");
        mfset(S, NULL);
    } else {
        // ���ļ���׼����ȡ��������
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
 * ��ʼ�����ϵĶ�Ԫ�ȼ۹�ϵ��
 */
Status initial_relation(Relation* R, char* path) {
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("�����뼯�ϵĶ�Ԫ��ϵ��...\n");
        relation(R, NULL);
    } else {
        // ���ļ���׼����ȡ��������
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
 * ���������������� �㷨6.9 ����������������
 *
 * �����������ཻ���Ӽ�Si���Ӽ�Sj�Ĳ�����
 */
Status merge_mfset(MFSet* S, int i, int j) {
    
    // ����Խ��
    if(i < 1 || i > S->n || j < 1 || j > S->n) {
        return ERROR;
    }
    
    S->nodes[i].parent = j;
    
    return OK;
}

/*
 * ���������������� �㷨6.8 ����������������
 *
 * �ڼ���S�в���Ԫ��i��ǰ�������Ӽ���
 */
int find_mfset(MFSet S, int i) {
    int j;
    
    // ����Խ��
    if(i < 1 || i > S.n) {
        return -1;
    }
    
    // ����i�������Ӽ��ĸ����
    for(j = i; S.nodes[j].parent > 0; j = S.nodes[j].parent) {
        // �������ϲ���
    }
    
    return j;
}

/*
 * ���������������� �㷨6.10 ����������������
 *
 * �����������ཻ���Ӽ�Si���Ӽ�Sj�Ĳ�����
 *
 * ���㷨�ǡ��㷨6.9���ĸĽ����Ľ�֮�����ڣ�
 * 1.�Ӽ������ľ���ֵΪ���Ӽ�Ԫ�ص�����
 * 2.��ֽ���ģС�ļ��Ϻϲ�����ģ��ļ�����
 */
Status mix_mfset(MFSet* S, int i, int j) {
    
    // ����Խ��
    if(i < 1 || i > S->n || j < 1 || j > S->n) {
        return ERROR;
    }
    
    // Si������Ա����sj�٣�������parent���Ǹ���������Ԫ���ٵ���ֵ������
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
 * ���������������� �㷨6.11 ����������������
 *
 * �ڼ���S�в���Ԫ��i��ǰ�������Ӽ���
 *
 * ���㷨�ǡ��㷨6.8���ĸĽ����Ľ�֮�����ڣ�
 * ������ɺ󣬻�����ĸ߶Ƚ���̯ƽ����������Ԫ��ֱ�ӹ��ص��Ӽ�������ϡ�
 *
 *��ע��
 * �ò�����Լ�����ɸĶ�
 */
int fix_mfset(MFSet* S, int i) {
    int j, k, t;
    
    // ����Խ��
    if(i < 1 || i > S->n) {
        return -1;
    }
    
    // ����i�������Ӽ��ĸ����
    for(j = i; S->nodes[j].parent > 0; j = S->nodes[j].parent) {
        // �������ϲ���
    }
    
    // ˳�Ž��i���������Ӽ��ĸ���㣬��·����Ԫ��ֱ�Ӽ޽ӵ��Ӽ��ĸ��ϣ��൱��̯ƽ�����ĸ߶�
    for(k = i; k != j; k = t) {
        t = S->nodes[k].parent;
        S->nodes[k].parent = j;
    }
    
    return j;
}

/*
 * ���ݵȼ۹�ϵR������/��������S�е�Ԫ��(�Ӽ�)��
 *
 *��ע��
 * �÷�����bix_relation����Ŀ��һ�£�
 * ���÷������õ��ǡ��㷨6.8���͡��㷨6.9����
 * ��δ�Ż��İ汾��
 */
Status build_mfset(MFSet* S, Relation R) {
    int k;
    int i, j;
    
    for(k = 0; k < R.n; k++) {
        // �Ȼ�ȡ�Ӽ������
        i = find_mfset(*S, R.pairs[k].i);
        j = find_mfset(*S, R.pairs[k].j);
        
        // �����������ཻ���Ӽ����й鲢
        if(!merge_mfset(S, i, j)) {
            return ERROR;
        }
    }
    
    return OK;
}

/*
 * ���ݵȼ۹�ϵR������/��������S�е�Ԫ��(�Ӽ�)��
 *
 *��ע��
 * �÷�����build_relation����Ŀ��һ�£�
 * ���÷������õ��ǡ��㷨6.10���͡��㷨6.11����
 * ���Ż���İ汾��
 */
Status bix_mfset(MFSet* S, Relation R) {
    int k;
    int i, j;
    
    for(k = 0; k < R.n; k++) {
        // �Ȼ�ȡ�Ӽ������
        i = fix_mfset(S, R.pairs[k].i);
        j = fix_mfset(S, R.pairs[k].j);
        
        // �����������ཻ���Ӽ����й鲢
        if(!mix_mfset(S, i, j)) {
            return ERROR;
        }
    }
    
    return OK;
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������ϵ��ڲ�����
static void mfset(MFSet* S, FILE* fp) {
    int n, i;
    
    S->r = 0;
    
    if(fp == NULL) {
        printf("������Ԫ��(�Ӽ�)������");
        scanf("%d", &n);
    } else {
        // ¼��Ԫ������
        ReadData(fp, "%d", &n);
    }
    
    if(n <= 0) {
        return;
    }
    
    S->n = n;
    S->r = 1;
    
    // �Ӽ����Ĭ�ϴ�1��ʼ����
    for(i = 1; i <= n; i++) {
        S->nodes[i].parent = -1;
    }
}

// �������϶�Ԫ��ϵ���ڲ�����
static void relation(Relation* R, FILE* fp) {
    int n, k;
    
    R->n = 0;
    
    if(fp == NULL) {
        printf("�������Ԫ��ϵ�Ե�������");
        scanf("%d", &n);
        
        if(n <= 0) {
            return;
        }
        
        R->n = n;
        
        for(k = 0; k < n; k++) {
            printf("������� %2d �Զ�Ԫ��ϵ��", k + 1);
            scanf("%d%d", &(R->pairs[k].i), &(R->pairs[k].j));
        }
    } else {
        // ¼���Ԫ��ϵ�Ե�����
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


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph(MFSet S) {
    typedef struct Elem {
        int x;
        struct Elem* next;
    } Elem;
    
    int count;  // ͳ��S�е��Ӽ�����
    int k, i, cur;
    Elem* set;
    Elem* p;
    
    if(S.n == 0) {
        printf("\n");
        return;
    }
    
    // ���α�������ȷ���Ӽ�����
    for(k = 1, count = 0; k <= S.n; k++) {
        if(S.nodes[k].parent < 0) {
            count++;
        }
    }
    
    set = (Elem*) malloc((count + 1) * sizeof(Elem));
    memset(set, 0, (count + 1) * sizeof(Elem));
    
    // 0�ŵ�Ԫ��������洢�Ӽ�����
    set[0].x = count;
    
    // �ٴα�����ȷ��ÿ���Ӽ��°�����ЩԪ��
    for(k = 1; k <= S.n; k++) {
        // �������Ӽ������
        if(S.nodes[k].parent < 0) {
            // ��set�в��Ҹ����λ�ã�����Ҳ�������λ������λ��
            for(i = 1; i <= set[0].x && set[i].x != 0; i++) {
                if(set[i].next->x == k) {
                    break;
                }
            }
            
            // δ�ҵ��ø���㣬��Ҫ����
            if(set[i].x == 0) {
                set[i].x++;   // 0�ŵ�Ԫ��Ȼ����
                
                // ��¼�������Ϣ
                set[i].next = (Elem*) malloc(sizeof(Elem));
                set[i].next->x = k;
                set[i].next->next = NULL;
            }
            
            // �����Ӽ�������Ԫ��
        } else {
            for(cur = k; S.nodes[cur].parent > 0; cur = S.nodes[cur].parent) {
                // �������������Ӽ���һ�������ҵ�ĳ�������cur
            }
            
            // ��set�в��Ҹ����λ�ã�����Ҳ�������λ������λ��
            for(i = 1; i <= set[0].x && set[i].x != 0; i++) {
                if(set[i].next->x == cur) {
                    break;
                }
            }
            
            // δ�ҵ��ø���㣬��Ҫ����
            if(set[i].x == 0) {
                set[i].x++;   // 0�ŵ�Ԫ��Ȼ����
                
                // ��¼�������Ϣ
                set[i].next = (Elem*) malloc(sizeof(Elem));
                set[i].next->x = cur;
                set[i].next->next = NULL;
            }
            
            // ���뵱ǰ��㵽��β��
            set[i].x++;
            
            for(p = set[i].next; p->next != NULL; p = p->next) {
                // ��������β��
            }
            
            p->next = (Elem*) malloc(sizeof(Elem));
            p->next->x = k;
            p->next->next = NULL;
        }
    }
    
    printf("�����й��� %d ���Ӽ���\n", set[0].x);
    
    for(i = 1; i <= set[0].x; i++) {
        printf("�Ӽ� %2d �й��� %2d ��Ԫ�أ�", set[i].next->x, set[i].x);
        
        for(p = set[i].next; p != NULL; p = p->next) {
            printf("%2d ", p->x);
        }
        
        printf("\n");
    }
    
    printf("�洢�ṹ��\n");
    PrintFramework(S);
}

// ͼ�λ�����������нṹ�������ڲ�����ʹ��
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
