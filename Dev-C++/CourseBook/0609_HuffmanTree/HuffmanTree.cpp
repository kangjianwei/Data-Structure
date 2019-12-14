/*====================
 * �շ�����
 *
 * �����㷨: 6.12��6.13
 ====================*/

#include "HuffmanTree.h"

/*
 * ��ʼ������
 *
 * ��Ҫ������ʼ��Ȩֵ��Ϣ��
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
Status InitEnvironment(int** w, int* n, char* path) {
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("������շ����������Ϣ...\n");
        Init(w, n, NULL);
    } else {
        // ���ļ���׼����ȡ��������
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
 * ���������������� �㷨6.12 ����������������
 *
 * ����
 * 1.����ָ����n��Ȩֵ��Ϣw�������շ�����HT��
 * 2.�ɺշ�����HT�������շ�������ֵHC��
 *
 *��ע��
 * ���㷨�롾�㷨6.13������һ�¡�
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
    
    // ����շ����������
    m = 2 * n - 1;
    
    *HT = (HuffmanTree) malloc((m + 1) * sizeof(HTNode));   // 0�ŵ�Ԫδʹ�ã�����weight���¼��ԭʼ��Ȩֵ����
    (*HT)[0].weight = n;
    
    // ��¼Ȩֵ��Ϣ��ע��pӦ��ָ������1������Ϊ0�ŵ�Ԫ�����ˣ����̲��д����ָ����0�ŵ�Ԫ��
    for(p = (*HT) + 1, i = 1; i <= n; ++i, ++p, ++w) {
        (*p).weight = *w;
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).rchild = 0;
    }
    
    // ����Ĳ�����Ҫ����
    for(; i <= m; ++i, ++p) {
        (*p).weight = 0;
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).rchild = 0;
    }
    
    // ���շ�����
    for(i = n + 1; i <= m; ++i) {
        // ��HT[1,i-1]��ѡ��parentΪ0��δ������������weight��С��������㣬����ŷֱ�Ϊs1��s2
        Select(*HT, i - 1, &s1, &s2);
        
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
    
    
    /* ��Ҷ�ӵ���������ÿ���ַ��ĺշ������� */
    
    (*HC) = (HuffmanCode) malloc((n + 1) * sizeof(char*));  // ����n���ַ������ͷָ��������0�ŵ�Ԫ���ã�
    cd = (char*) malloc(n * sizeof(char));  // ���������Ĺ����ռ䣨ÿ�����볤�����Ϊn-1��
    cd[n - 1] = '\0';   // ���������
    
    // ����ַ���շ�������
    for(i = 1; i <= n; ++i) {
        start = n - 1;    // ���������λ��
        
        // ��Ҷ�ӵ������������
        for(c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent) {
            if((*HT)[f].lchild == c) {
                cd[--start] = '0';
            } else {
                cd[--start] = '1';
            }
        }
        
        (*HC)[i] = (char*) malloc((n - start) * sizeof(char));  // Ϊ��i���ַ��������ռ�
        strcpy((*HC)[i], &cd[start]);   // ��cd���Ʊ��루������HC
    }
    
    free(cd);   // �ͷŹ����ռ�
    
    return OK;
}

/*
 * ���������������� �㷨6.13 ����������������
 *
 * ����
 * 1.����ָ����n��Ȩֵ��Ϣw�������շ�����HT��
 * 2.��������շ�����HT����շ�������ֵHC��
 *
 *��ע��
 * ���㷨�롾�㷨6.12������һ�¡�
 */
Status HuffmanCodeing_2(HuffmanTree* HT, HuffmanCode* HC, int* w, int n) {
    int m, i;
    HuffmanTree p;
    int s1, s2;
    unsigned int r;
    int cdlen;
    char* cd;
    HuffmanTree H;  // HT��һ������
    
    if(n <= 1) {
        return ERROR;
    }
    
    // ����շ����������
    m = 2 * n - 1;
    
    *HT = (HuffmanTree) malloc((m + 1) * sizeof(HTNode));   // 0�ŵ�Ԫδʹ�ã�����weight���¼��ԭʼ��Ȩֵ����
    (*HT)[0].weight = n;
    
    // ��¼Ȩֵ��Ϣ��ע��pӦ��ָ������1������Ϊ0�ŵ�Ԫ�����ˣ����̲��д����ָ����0�ŵ�Ԫ��
    for(p = (*HT) + 1, i = 1; i <= n; ++i, ++p, ++w) {
        (*p).weight = *w;
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).rchild = 0;
    }
    
    // ����Ĳ�����Ҫ����
    for(; i <= m; ++i, ++p) {
        (*p).weight = 0;
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).rchild = 0;
    }
    
    // ���շ�����
    for(i = n + 1; i <= m; ++i) {
        // ��HT[1,i-1]��ѡ��parentΪ0��δ������������weight��С��������㣬����ŷֱ�Ϊs1��s2
        Select(*HT, i - 1, &s1, &s2);
        
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
    
    
    /* ��ջ�ǵݹ�����շ���������շ������� */
    
    (*HC) = (HuffmanCode) malloc((n + 1) * sizeof(char*));  // ����n���ַ������ͷָ��������0�ŵ�Ԫ���ã�
    cd = (char*) malloc(n * sizeof(char));  // ���������Ĺ����ռ䣨ÿ�����볤�����Ϊn-1��
    
    r = m;
    cdlen = 0;
    
    // �����ٺշ������ĸ����Ͻ��в���
    H = (HuffmanTree) malloc((m + 1) * sizeof(HTNode));
    for(i = 0; i <= m; ++i) {
        H[i] = (*HT)[i];
        H[i].weight = 0;
    }
    
    while(r != 0) {
        // ��һ�η��ʴ˽�㣬��Ҫ�������
        if(H[r].weight == 0) {
            H[r].weight = 1;
            
            // ��������
            if(H[r].lchild != 0) {
                // ������һ��
                r = H[r].lchild;
                cd[cdlen++] = '0';
                
                // ���������ӣ�Ҳ�������Һ��ӣ���������Ҷ�ӽ��
            } else if(H[r].rchild == 0) {
                (*HC)[r] = (char*) malloc((cdlen + 1) * sizeof(char));
                cd[cdlen] = '\0';
                strcpy((*HC)[r], cd);   // ���Ʊ��봮
            }
            
            // �ڶ��η��ʴ˽�㣬��Ҫ���ұ���
        } else if(H[r].weight == 1) {
            H[r].weight = 2;
            
            if(H[r].rchild != 0) {
                r = H[r].rchild;
                cd[cdlen++] = '1';
            }
            
            // �����η��ʣ���Ҫ���˵������
        } else {
            r = H[r].parent;    // �˻ص������
            cdlen--;                // ���볤�ȼ�1
        }
    }
    
    return OK;
}

/*
 * ����
 * ���ݸ�����n���շ�������HC������������Ȩֵ��
 */
Status HuffmanDecoding(HuffmanTree HT, HuffmanCode HC, int** w, int n) {
    int i, j, k;
    int r;
    char* s;
    
    if(n <= 0) {
        return ERROR;
    }
    
    (*w) = (int*) malloc(n * sizeof(int));
    
    // �����λ��
    r = 2 * n - 1;
    
    for(i = 1; i <= n; i++) {
        s = HC[i];
        
        k = r;
        
        // �Ӹ����������
        for(j = 0; j < strlen(s); j++) {
            if(s[j] == '0') {
                k = HT[k].lchild;   // ����
            } else if(s[j] == '1') {
                k = HT[k].rchild;   // ����
            } else {
                return ERROR;
            }
        }
        
        (*w)[i - 1] = HT[k].weight;
    }
    
    return OK;
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// ��ʼ���������ڲ�ʵ��
static Status Init(int** w, int* n, FILE* fp) {
    int i;
    
    if(fp == NULL) {
        printf("������շ�����Ҷ�ӽ��������");
        scanf("%d", n);
        
        if(*n <= 0) {
            *w = NULL;
            return ERROR;
        }
        
        *w = (int*) malloc((*n) * sizeof(int));
        
        printf("������ %d ��Ȩֵ��Ϣ��", *n);
        for(i = 0; i < *n; i++) {
            scanf("%d", *w + i);
        }
    } else {
        // ¼��Ԫ������
        ReadData(fp, "%d", n);
        
        if(*n <= 0) {
            *w = NULL;
            return ERROR;
        }
        
        *w = (int*) malloc((*n) * sizeof(int));
        
        // ¼����Ȩֵ��Ϣ
        for(i = 0; i < *n; i++) {
            ReadData(fp, "%d", *w + i);
        }
    }
    
    return OK;
}

// �ںշ��������[1...end]������ѡ��Ȩֵ��С��δ�������������������s1��s2��
static void Select(HuffmanTree HT, int end, int* s1, int* s2) {
    int i;
    int w1, w2;
    
    w1 = w2 = INT_MAX;
    
    for(i = 1; i <= end; i++) {
        // �����Ѿ��������Ľ��
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


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ӡ�շ������ṹ��
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

// ��ӡ�շ������롣
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

// ��ӡ�շ��������Ӧ��Ȩֵ��Ϣ��
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
