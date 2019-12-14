/*==================
 * ����˫�ױ�洢��ʾ
 ===================*/

#include "PTree.h"

/*
 * ��ʼ��
 *
 * ���������
 */
Status InitTree(PTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    T->n = 0;
    
    // ������������
    memset(T->nodes, 0, sizeof(T->nodes));
    
    return OK;
}

/*
 * ����
 *
 * �ͷ�����ռ�ڴ档
 *
 *��ע��
 * ����˫�ױ�ṹ�޷�������
 */
Status DestroyTree(PTree* T) {
    // �޷�����
    return ERROR;
}

/*
 * �ÿ�
 *
 * �������е����ݣ�ʹ���Ϊ������
 */
Status ClearTree(PTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    // ��Ԫ���������㼴��
    T->n = 0;
    
    // ������������
    memset(T->nodes, 0, sizeof(T->nodes));
    
    return OK;
}

/*
 * ����
 *
 * ����Ԥ��Ķ�������������
 * ����Լ��ʹ�á��������С�����������
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
Status CreateTree(PTree* T, char* path) {
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("����������Ԫ����Ϣ�����ڿս�㣬ʹ��^����...\n");
        Create(T, NULL);
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        Create(T, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * �п�
 *
 * �ж����Ƿ�Ϊ������
 */
Status TreeEmpty(PTree T) {
    return T.n == 0 ? TRUE : FALSE;
}

/*
 * ����
 *
 * ����������ȣ���������
 */
int TreeDepth(PTree T) {
    int k, level;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return 0;
    }
    
    /*
     * ��k��ʼ��Ϊ���һ������λ��
     * �������Ľ�㰴����洢�������洢�Ľ��ض�λ������
     */
    k = (T.r + T.n - 1) % MAX_TREE_SIZE;
    level = 0;
    
    do {
        level++;
        k = T.nodes[k].parent;
    } while(k != -1);
    
    return level;
}

/*
 * ȡֵ
 *
 * ��������ָ������ֵ��
 */
TElemType Value(PTree T, TElemType e) {
    int p;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e������
    p = EIndex(T, e);
    
    // ���û���ҵ�Ԫ��e
    if(p == -1) {
        return '\0';
    } else {
        return T.nodes[p].data;
    }
}

/*
 * ��ֵ
 *
 * Ϊ��ָ���Ľ�㸳ֵ��
 */
Status Assign(PTree* T, TElemType e, TElemType value) {
    int p;
    
    // ���������������������
    if(TreeEmpty(*T)) {
        return ERROR;
    }
    
    // ��ȡ���e������
    p = EIndex(*T, e);
    
    // ���û���ҵ�Ԫ��e
    if(p == -1) {
        return ERROR;
    } else {
        // ���и�ֵ
        T->nodes[p].data = value;
        return OK;
    }
}

/*
 * ��
 *
 * �������ĸ���㡣
 */
TElemType Root(PTree T) {
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    return T.nodes[T.r].data;
}

/*
 * ˫��
 *
 * �������н��e��˫�׽�㡣
 */
TElemType Parent(PTree T, TElemType e) {
    int p, parent;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e������
    p = EIndex(T, e);
    
    // ���û���ҵ�Ԫ��e
    if(p == -1) {
        return '\0';
    } else {
        parent = T.nodes[p].parent;
        
        // �������˫��
        if(parent == -1) {
            return '\0';
        } else {
            return T.nodes[parent].data;
        }
    }
}

/*
 * ��������
 *
 * ������T�н��e�ĺ���������
 */
int ChildCount(PTree T, TElemType e) {
    int p, k, count;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return -1;
    }
    
    // ��ȡ���e������
    p = EIndex(T, e);
    // ���e������
    if(p == -1) {
        return -1;
    }
    
    // ���ҵ�һ������
    for(k = (p + 1) % MAX_TREE_SIZE; k != (T.r + T.n) % MAX_TREE_SIZE; k = (k + 1) % MAX_TREE_SIZE) {
        if(T.nodes[k].parent == p) {
            break;
        }
    }
    
    count = 0;
    
    // ͳ�ƽ��e�ĺ�������
    while(k != (T.r + T.n) % MAX_TREE_SIZE && T.nodes[k].parent == p) {
        count++;
        k = (k + 1) % MAX_TREE_SIZE;
    }
    
    return count;
}

/*
 * ����
 *
 * �������н��e�ĵ�i�����ӡ�
 */
TElemType Child(PTree T, TElemType e, int i) {
    int p;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // i�ķ�ΧԽ��
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return '\0';
    }
    
    // ��ȡ���e�ĵ�i����������
    p = CIndex(T, e, i);
    // ���e��i�����Ӳ�����
    if(p == -1) {
        return '\0';
    }
    
    return T.nodes[p].data;
}

/*
 * ���ֵ�
 *
 * �������н��e�����ֵܽ�㡣
 *
 *��ע��
 * �������Ľ����ܻ����������ӣ�
 * �����������ֵ���ָ��߽��ڸý����ֵܡ�
 */
TElemType LeftSibling(PTree T, TElemType e) {
    int p, ls;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e������
    p = EIndex(T, e);
    // ���e������
    if(p == -1) {
        return '\0';
    }
    
    // ����������ֵ�
    ls = (p - 1 + MAX_TREE_SIZE) % MAX_TREE_SIZE;
    
    // ����ý����Ч��������e��˫����ͬ��˵�������ֵ�
    if(ls != p && T.nodes[ls].data != '\0' && T.nodes[ls].parent == T.nodes[p].parent) {
        return T.nodes[ls].data;
    }
    
    return '\0';
}

/*
 * ���ֵ�
 *
 * �������н��e�����ֵܽ�㡣
 *
 *��ע��
 * �������Ľ����ܻ����������ӣ�
 * �����������ֵ���ָ�ұ߽��ڸý����ֵܡ�
 */
TElemType RightSibling(PTree T, TElemType e) {
    int p, rs;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e������
    p = EIndex(T, e);
    // ���e������
    if(p == -1) {
        return '\0';
    }
    
    // ����������ֵ�
    rs = (p + 1) % MAX_TREE_SIZE;
    
    // ����ý����Ч��������e��˫����ͬ��˵�������ֵ�
    if(rs != p && T.nodes[rs].data != '\0' && T.nodes[rs].parent == T.nodes[p].parent) {
        return T.nodes[rs].data;
    }
    
    return '\0';
}

/*
 * ����
 *
 * ����c����Ϊ��T��p���ĵ�i�����ӡ�
 */
Status InsertChild(PTree* T, TElemType p, int i, PTree c) {
    Pos pt[MAX_TREE_SIZE], pc[MAX_TREE_SIZE];
    int pIndex;
    int lastChild, bound;
    int level;
    int m, n, k;
    int tCur, cCur;
    
    PTree R;
    int tParent[MAX_TREE_SIZE], cParent[MAX_TREE_SIZE];
    int x, y, z;
    
    // �����Ϊ�����������������
    if(TreeEmpty(*T) || TreeEmpty(c)) {
        return ERROR;
    }
    
    // i�ķ�Χ����С
    if(i < 1) {
        return ERROR;
    }
    
    // ��ȡ���p������
    pIndex = EIndex(*T, p);
    
    // ���p��㲻���ڣ��򷵻ش�����ʾ
    if(pIndex == -1) {
        return ERROR;
    }
    
    // ����T�н���λ����Ϣ
    getPos(*T, pt);
    
    // ���p���һ�����ӵ�����
    lastChild = pt[pIndex].lastChild;
    
    // i�ķ�Χ����
    if(lastChild != -1 && i > pt[lastChild].childIndex + 1) {
        return ERROR;
    }
    
    if(i == 1) {
        // ���p�����ǵ�һ������
        if(pt[pIndex].childIndex == 1) {
            bound = -1;
        } else {
            // ��p�����ֵ����������
            for(k = (pIndex - 1) % MAX_TREE_SIZE; pt[k].lastChild == -1 && pt[k].childIndex != 1; k = (k - 1) % MAX_TREE_SIZE) {
                // �����ұ߽�ĸ���������
            }
            
            // �Ѿ��������ò��һ����㣬���ý����Ȼû�к���
            if(pt[k].lastChild == -1) {
                bound = -1;
            } else {
                bound = pt[k].lastChild;    // k������һ�����ӵ�����
            }
        }
    } else {
        // ���pû�к���
        if(lastChild == -1) {
            return ERROR;
        } else {
            for(k = pt[pIndex].lastChild; pt[k].childIndex != i - 1; k = (k - 1) % MAX_TREE_SIZE) {
                // ���Ҳ���λ�õ�ǰһ�����ӵ�����
            }
            bound = k;
        }
    }
    
    level = pt[pIndex].row + 1;   // ����������ĸ�������ڵ���
    
    // ����c�н���λ����Ϣ
    getPos(c, pc);
    // �����²�������и�Ԫ�ص�����
    for(k = c.r; k != (c.r + c.n) % MAX_TREE_SIZE; k = (k + 1) % MAX_TREE_SIZE) {
        pc[k].row += level - 1;
    }
    
    // tCurָ���level�еĵ�һ�����
    for(tCur = pIndex; tCur != (T->r + T->n) % MAX_TREE_SIZE; tCur = (tCur + 1) % MAX_TREE_SIZE) {
        if(pt[tCur].row == level) {
            break;
        }
    }
    
    // cCurָ����c�еĸ���㣬�ø����ҲӦ�����뵽��T�е�level��
    cCur = c.r;
    
    while(tCur != (T->r + T->n) % MAX_TREE_SIZE && cCur != (c.r + c.n) % MAX_TREE_SIZE) {
        // ������T�ҽ��ǰ�벿��
        if(bound != -1) {
            tCur = (bound + 1) % MAX_TREE_SIZE;
        }
        
        if(bound == -1) {
            m = 0;
        } else {
            m = pt[bound].col;
        }
        
        n = 0;
        
        // ��c���뵽T���м�
        while(cCur != (c.r + c.n) % MAX_TREE_SIZE && pc[cCur].row == level) {
            // �ı���
            
            pc[cCur].col += m;
            n++;
            
            cCur++;
        }
        
        // ����T�ĺ�벿��
        while(tCur != (T->r + T->n) % MAX_TREE_SIZE && pt[tCur].row == level) {
            
            pt[tCur].col += n;
            
            tCur++;
        }
        
        // ������һ��ı߽�
        if(bound != -1) {
            // ��bound���������
            for(k = bound; pt[k].lastChild == -1 && pt[k].childIndex != 1; k = (k - 1) % MAX_TREE_SIZE) {
                // �����ұ߽�ĸ���������
            }
            
            // �Ѿ��������ò��һ����㣬���ý����Ȼû�к���
            if(pt[k].lastChild == -1) {
                bound = -1;
            } else {
                bound = pt[k].lastChild;    // k������һ�����ӵ�����
            }
        }
        
        level++;
    }
    
    // ����pos��Ϣ
//    printPos(*T, pt);
//    printPos(c, pc);
    
    InitTree(&R);
    
    R.r = T->r;
    n = 0;
    
    x = T->r;   // ����T���α�
    y = c.r;    // ����c���α�
    z = R.r;    // ����R���α�
    
    while(x != (T->r + T->n) % MAX_TREE_SIZE && y != (c.r + c.n) % MAX_TREE_SIZE) {
        if(pt[x].row < pc[y].row || (pt[x].row == pc[y].row && pt[x].col < pc[y].col)) {
            
            // ��¼���x����λ��
            tParent[x] = z;
            
            // ��ЧԪ�طŵ���λ����
            R.nodes[z] = T->nodes[x];
            
            if(R.nodes[z].parent != -1) {
                // ���¸����λ��
                R.nodes[z].parent = tParent[R.nodes[z].parent];
            }
    
            x = (x + 1) % MAX_TREE_SIZE;
        } else if(pt[x].row > pc[y].row || (pt[x].row == pc[y].row && pt[x].col > pc[y].col)) {
            // ��¼���y����λ��
            cParent[y] = z;
            
            // ��ЧԪ�طŵ���λ����
            R.nodes[z] = c.nodes[y];
            
            if(R.nodes[z].parent != -1) {
                // ���¸����λ��
                R.nodes[z].parent = cParent[R.nodes[z].parent];
            } else {
                // ������������һ�𣬼���c�ĸ����ĸ����Ϊp
                R.nodes[z].parent = tParent[pIndex];
            }
    
            y = (y + 1) % MAX_TREE_SIZE;
        }
        
        z = (z + 1) % MAX_TREE_SIZE;
        n++;
    }
    
    while(x != (T->r + T->n) % MAX_TREE_SIZE) {
        // ��¼���k����λ��
        tParent[x] = z;
    
        // ��ЧԪ�طŵ���λ����
        R.nodes[z] = T->nodes[x];
        
        if(R.nodes[z].parent != -1) {
            // ���¸����λ��
            R.nodes[z].parent = tParent[R.nodes[z].parent];
        }
        
        x = (x + 1) % MAX_TREE_SIZE;
        z = (z + 1) % MAX_TREE_SIZE;
        n++;
    }
    
    while(y != (c.r + c.n) % MAX_TREE_SIZE) {
        // ��¼���k����λ��
        cParent[y] = z;
    
        // ��ЧԪ�طŵ���λ����
        R.nodes[z] = c.nodes[y];
        
        if(R.nodes[z].parent != -1) {
            // ���¸����λ��
            R.nodes[z].parent = cParent[R.nodes[z].parent];
        } else {
            // ������������һ�𣬼���c�ĸ����ĸ����Ϊp
            R.nodes[z].parent = tParent[pIndex];
        }
        
        y = (y + 1) % MAX_TREE_SIZE;
        z = (z + 1) % MAX_TREE_SIZE;
        n++;
    }
    
    R.n = n;
    *T = R;
    
    return OK;
}

/*
 * ɾ��
 *
 * ɾ����T��p���ĵ�i�����ӡ�
 */
Status DeleteChild(PTree* T, TElemType p, int i) {
    LinkList Lt;
    int index;
    int k, m, n;
    PTree R;
    int parent[MAX_TREE_SIZE];
    
    // �����ɾ������Ϊ�����������������
    if(TreeEmpty(*T)) {
        return ERROR;
    }
    
    // i�ķ�ΧԽ�磨�����жϣ�
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return ERROR;
    }
    
    // ��ȡ���p�ĵ�i����������
    index = CIndex(*T, p, i);
    
    // �����ɾ����㲻���ڣ��򷵻ش�����ʾ
    if(index == -1) {
        return ERROR;
    }
    
    InitList(&Lt);
    
    m = 0;
    // �����p���뵽����
    ListInsert(Lt, ++m, index);
    T->nodes[index].data = '\0';
    
    k = (index + 1) % MAX_TREE_SIZE;
    
    while(k != (T->r + T->n) % MAX_TREE_SIZE) {
        // �жϵ�ǰ����Ƿ�Ϊ���k���ڲ���ĺ���
        if(LocateElem(Lt, T->nodes[k].parent, Equal)) {
            ListInsert(Lt, ++m, k);
            
            T->nodes[k].data = '\0';
        }
        
        k = (k + 1) % MAX_TREE_SIZE;
    }
    
    DestroyList(&Lt);
    
    InitTree(&R);
    
    R.r = T->r;
    n = 0;
    
    m = R.r;    // ����R���α�
    
    for(k = T->r; k != (T->r + T->n) % MAX_TREE_SIZE; k = (k + 1) % MAX_TREE_SIZE) {
        if(T->nodes[k].data != '\0') {
            // ��¼���k����λ��
            parent[k] = m;
            
            // ��ЧԪ�طŵ���λ����
            R.nodes[m] = T->nodes[k];
    
            // ���¸����λ��
            if(R.nodes[m].parent!=-1) {
                R.nodes[m].parent = parent[R.nodes[m].parent];
            }
            
            m = (m + 1) % MAX_TREE_SIZE;
            n++;
        }
    }
    
    R.n = n;
    *T = R;
    
    return OK;
}

/*
 * �������
 */
Status PreOrderTraverse(PTree T, Status(Visit)(TElemType)) {
    Pos pt[MAX_TREE_SIZE];
    
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    // ����T�н���λ����Ϣ
    getPos(T, pt);
    
    PreTraverse(T, pt, T.r, Visit);
    
    printf("\n");
    
    return OK;
}

/*
 * �������
 */
Status PostOrderTraverse(PTree T, Status(Visit)(TElemType)) {
    Pos pt[MAX_TREE_SIZE];
    
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    // ����T�н���λ����Ϣ
    getPos(T, pt);
    
    PostTraverse(T, pt, T.r, Visit);
    
    printf("\n");
    
    return OK;
}

/*
 * �������
 */
Status LevelOrderTraverse(PTree T, Status(Visit)(TElemType)) {
    int i;
    
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    // ˳�α�������Ԫ��
    for(i = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        if(!Visit(T.nodes[i].data)) {
            return ERROR;
        }
    }
    
    printf("\n");
    
    return OK;
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// ���������ڲ�����
static void Create(PTree* T, FILE* fp) {
    int r;          // ���ĸ�����λ�ã�������
    int n;          // ��¼Ԫ������
    int cur;        // �α�
    TElemType ch;
    LinkQueue Q;
    QElemType e;    // ����Ԫ��ָʾ����λ��
    char s[MAX_CHILD_COUNT + 1];
    int i;
    
    InitQueue(&Q);
    
    n = 0;
    
    // ��ȡ������λ��
    if(fp == NULL) {
        printf("�����������λ��(0~%d)��", MAX_TREE_SIZE - 1);
        scanf("%d", &r);
        cur = r;
        
        printf("�����������ֵ��");
        scanf("%s", s);
        ch = s[0];
        
        // �������
        EnQueue(&Q, cur);
        T->nodes[cur].data = ch;
        T->nodes[cur].parent = -1;
        cur = (cur + 1) % MAX_TREE_SIZE;
        n++;
        
        while(!QueueEmpty(Q)) {
            DeQueue(&Q, &e);    // �����λ�ó���
            
            printf("���������� %c �ĺ��ӽ�㣬�����ں���ʱ����һ��^��", T->nodes[e].data);
            scanf("%s", s);
            for(i = 0; i < strlen(s); i++) {
                if(s[i] == '^') {
                    break;
                }
                
                EnQueue(&Q, cur); // ��ǰ���λ�����
                T->nodes[cur].data = s[i];
                T->nodes[cur].parent = e;
                cur = (cur + 1) % MAX_TREE_SIZE;
                n++;
            }
        }
    } else {
        // ¼�������λ��
        ReadData(fp, "%d", &r);
        cur = r;
        
        // ¼�������ֵ
        ReadData(fp, "%s", s);
        ch = s[0];
        printf("¼�������ֵ��%c\n", ch);
        
        // �������
        EnQueue(&Q, cur);
        T->nodes[cur].data = ch;
        T->nodes[cur].parent = -1;
        cur = (cur + 1) % MAX_TREE_SIZE;
        n++;
        
        while(!QueueEmpty(Q)) {
            ReadData(fp, "%s", s);
            ch = s[0];
            printf("����¼�� %c ���ĺ��ӣ�", ch);
            
            // ¼�뺢�ӽ��
            ReadData(fp, "%s", s);
            printf("%s\n", s);
            
            DeQueue(&Q, &e);    // �����λ�ó���
            
            // ��������
            for(i = 0; i < strlen(s); i++) {
                if(s[i] == '^') {
                    break;
                }
                
                EnQueue(&Q, cur); // ��ǰ���λ�����
                T->nodes[cur].data = s[i];
                T->nodes[cur].parent = e;
                cur = (cur + 1) % MAX_TREE_SIZE;
                n++;
            }
        }
    }
    
    T->r = r;
    T->n = n;
}

// ���������e����������������ڣ�����-1
static int EIndex(PTree T, TElemType e) {
    int i = T.r;    // ָ������
    int p = -1;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return -1;
    }
    
    // �����в��ҽ��e
    while(i != (T.r + T.n) % MAX_TREE_SIZE) {
        if(T.nodes[i].data == e) {
            p = i;
            break;
        }
        
        i = (i + 1) % MAX_TREE_SIZE;
    }
    
    return p;
}

// ���������e�ĵ�i��������������������ڣ�����-1
static int CIndex(PTree T, TElemType e, int i) {
    int p, k, r, count;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return -1;
    }
    
    // i�ķ�ΧԽ��
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return -1;
    }
    
    // ��ȡ���e������
    p = EIndex(T, e);
    // ���e������
    if(p == -1) {
        return -1;
    }
    
    k = (p + 1) % MAX_TREE_SIZE;
    
    // ���ҵ�һ�����ӣ���k��¼
    while(k != (T.r + T.n) % MAX_TREE_SIZE && T.nodes[k].parent < p) {
        k = (k + 1) % MAX_TREE_SIZE;
    }
    
    // ȷ����һ�����Ӵ���
    if(k != (T.r + T.n) % MAX_TREE_SIZE) {
        count = 1;
        r = k;
        
        while(count < i && T.nodes[r].parent==p) {
            r = (r + 1) % MAX_TREE_SIZE;
            count++;
        }
        
        if(count == i) {
            return r;
        }
    }
    
    return -1;
}

// ��ȡ��T�Ľ����Ϣ�����������Щ��Ϣ�������Pos���͵Ķ���
static void getPos(PTree T, Pos pt[]) {
    LinkList Lt, Lt_parent, Lt_child;
    int m, n, p, k, s;
    int level;
    
    memset(pt, 0, MAX_TREE_SIZE * sizeof(Pos));
    
    // ���������������������
    if(TreeEmpty(T)) {
        return;
    }
    
    InitList(&Lt_parent);
    InitList(&Lt_child);
    
    // ������parentΪ-1
    ListInsert(Lt_parent, 1, -1);
    
    level = 1;
    k = T.r;
    m = n = 0;
    s = -1; // ��ʼ��ͷ���ĸ����Ϊ-1
    
    while(k != (T.r + T.n) % MAX_TREE_SIZE) {
        // ���k��һ�����������е�������ʼ��Ϊ-1
        pt[k].firstChild = -1;
        
        // ���k���һ�����������е�������ʼ��Ϊ-1
        pt[k].lastChild = -1;
        
        // ��ǰ���k�ĸ����
        p = T.nodes[k].parent;
        if(p != s) {
            s = p;  // ׷�ٸ����ı仯
            n = 0;  // �����ı�ʱ����Ҫ���¼���
        }
        
        // �жϵ�ǰ����Ƿ�Ϊ��level-1����ĺ���
        if(LocateElem(Lt_parent, p, Equal)) {
            ListInsert(Lt_child, ++m, k);
            
            pt[k].row = level;
            pt[k].col = m;
            pt[k].childIndex = ++n;
            
            // ȷ����ǰ��㸸������
            if(p != -1) {
                // ��һ�����������е�����
                if(pt[p].firstChild==-1) {
                    pt[p].firstChild = k;
                }
                
                // ���һ�����������е�����
                pt[p].lastChild = k;
            }
            
            k = (k + 1) % MAX_TREE_SIZE;
        } else {
            Lt = Lt_parent;
            Lt_parent = Lt_child;
            Lt_child = Lt;
            ClearList(Lt_child);
            
            level++;
            m = 0;
        }
    }
    
    DestroyList(&Lt_parent);
    DestroyList(&Lt_child);
}

// ����������ڲ�ʵ��
static Status PreTraverse(PTree T, Pos pt[], int i, Status(Visit)(TElemType)) {
    int firstChild;
    int rightBrother;
    
    // ���ʵ�ǰ���
    if(!Visit(T.nodes[i].data)) {
        return ERROR;
    }
    
    firstChild = pt[i].firstChild;
    
    // �������ӣ���Ҫ��ȷ�����ӵ���ݣ�
    if(firstChild != -1 && !PreTraverse(T, pt, firstChild, Visit)) {
        return ERROR;
    }
    
    rightBrother = (i + 1) % MAX_TREE_SIZE;
    
    // �������ֵܣ���Ҫ��ȷ�����ֵܵ���ݣ�
    if(T.nodes[i].parent == T.nodes[rightBrother].parent && !PreTraverse(T, pt, rightBrother, Visit)) {
        return ERROR;
    }
    
    return OK;
}

// ����������ڲ�ʵ��
static Status PostTraverse(PTree T, Pos pt[], int i, Status(Visit)(TElemType)) {
    int firstChild;
    int rightBrother;
    
    firstChild = pt[i].firstChild;
    
    // �������ӣ���Ҫ��ȷ�����ӵ���ݣ�
    if(firstChild != -1 && !PostTraverse(T, pt, firstChild, Visit)) {
        return ERROR;
    }
    
    // ���ʵ�ǰ���
    if(!Visit(T.nodes[i].data)) {
        return ERROR;
    }
    
    rightBrother = (i + 1) % MAX_TREE_SIZE;
    
    // �������ֵܣ���Ҫ��ȷ�����ֵܵ���ݣ�
    if(T.nodes[i].parent == T.nodes[rightBrother].parent && !PostTraverse(T, pt, rightBrother, Visit)) {
        return ERROR;
    }
    
    return OK;
}

// ���pos��Ϣ�������ڲ�����ʹ��
static void printPos(PTree T, Pos pt[]) {
    int i;
    
    for(i = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        printf("%2c ", T.nodes[i].data);
    }
    printf("\n");
    
    for(i = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        printf("%2d ", pt[i].row);
    }
    printf("\n");
    
    for(i = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        printf("%2d ", pt[i].col);
    }
    printf("\n");
}


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph(PTree T) {
    Pos pt[MAX_TREE_SIZE];
    
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return;
    }
    
    // ����T�н���λ����Ϣ
    getPos(T, pt);
    
    Print(T, pt, T.r);
    
    printf("\n");
    
    printf("�洢�ṹ��\n");
    PrintFramework(T);
}

// ͼ�λ������ǰ�ṹ�ڲ�ʵ��
static void Print(PTree T, Pos pt[], int i) {
    int firstChild;
    int rightBrother;
    int k;
    
    // ���ʵ�ǰ���
    printf("%c ", T.nodes[i].data);
    
    firstChild = pt[i].firstChild;
    
    // �������ӣ���Ҫ��ȷ�����ӵ���ݣ�
    if(firstChild != -1) {
        Print(T, pt, firstChild);
    }
    
    rightBrother = (i + 1) % MAX_TREE_SIZE;
    
    // �������ֵܣ���Ҫ��ȷ�����ֵܵ���ݣ�
    if(rightBrother != (T.r + T.n) % MAX_TREE_SIZE && T.nodes[i].parent == T.nodes[rightBrother].parent) {
        // ���ʵ�ǰ�������ֵ�ǰ�������ǰ��㲻�����һ�����ӣ������һ�λ���
        if(pt[T.nodes[i].parent].lastChild != i) {
            printf("\n");
            
            for(k = 0; k < pt[rightBrother].row - 1; k++) {
                printf(". ");
            }
        }
        
        Print(T, pt, rightBrother);
    }
}

// ͼ�λ�����������нṹ�������ڲ�����ʹ��
static void PrintFramework(PTree T) {
    int k;
    
    if(T.n == 0) {
        printf("\n");
        return;
    }
    
    printf("+---------+\n");
    printf("|  i e  p |\n");
    printf("+---------+\n");
    
    for(k = T.r; k != (T.r + T.n) % MAX_TREE_SIZE; k = (k + 1) % MAX_TREE_SIZE) {
        printf("| %2d %c %2d |\n", k, T.nodes[k].data, T.nodes[k].parent);
    }
    
    printf("+---------+\n");
}
