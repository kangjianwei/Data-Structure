/*=============================
 * ���ĺ�������(��˫��)�Ĵ洢��ʾ
 =============================*/

#include "CTree.h"

/*
 * ��ʼ��
 *
 * ���������
 */
Status InitTree(CTree* T) {
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
 * ���ÿղ�����һ�µ�
 */
Status DestroyTree(CTree* T) {
    // �������٣�ʹ���ÿվͿ���
    return ERROR;
}

/*
 * �ÿ�
 *
 * �������е����ݣ�ʹ���Ϊ������
 */
Status ClearTree(CTree* T) {
    int k;
    ChildPtr p, q;
    
    if(T == NULL) {
        return ERROR;
    }
    
    // �ͷź��ӽ��ռ�õĿռ�
    for(k = T->r; k != (T->r + T->n) % MAX_TREE_SIZE; k = (k + 1) % MAX_TREE_SIZE) {
        p = T->nodes[k].firstchild;
        
        while(p != NULL) {
            q = p;
            p = p->next;
            free(q);
        }
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
Status CreateTree(CTree* T, char* path) {
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
Status TreeEmpty(CTree T) {
    return T.n == 0 ? TRUE : FALSE;
}

/*
 * ����
 *
 * ����������ȣ���������
 */
int TreeDepth(CTree T) {
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
TElemType Value(CTree T, TElemType e) {
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
Status Assign(CTree* T, TElemType e, TElemType value) {
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
TElemType Root(CTree T) {
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
TElemType Parent(CTree T, TElemType e) {
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
int ChildCount(CTree T, TElemType e) {
    int p, count;
    ChildPtr r;
    
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
    
    r = T.nodes[p].firstchild;
    count = 0;
    
    // ͳ�ƽ��e�ĺ�������
    while(r != NULL) {
        count++;
        r = r->next;
    }
    
    return count;
}

/*
 * ����
 *
 * �������н��e�ĵ�i�����ӡ�
 */
TElemType Child(CTree T, TElemType e, int i) {
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
TElemType LeftSibling(CTree T, TElemType e) {
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
TElemType RightSibling(CTree T, TElemType e) {
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
Status InsertChild(CTree* T, TElemType p, int i, CTree c) {
    Pos pt[MAX_TREE_SIZE], pc[MAX_TREE_SIZE];
    int pIndex;
    int lastChild, bound;
    int level;
    int m, n, k;
    int tCur, cCur;
    
    CTree R;
    int tParent[MAX_TREE_SIZE], cParent[MAX_TREE_SIZE];
    int x, y, z;
    
    ChildPtr cp, s;
    int count;
    
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
                
                // ָ�򸸽��ĵ�һ������
                cp = R.nodes[R.nodes[z].parent].firstchild;
                
                // �����ǰ��㲻�ǵ�һ�����ӣ�����Ҫ��ѯ��ȷ��λ��
                if(pt[x].childIndex != 1) {
                    for(count = 1; count < pt[x].childIndex; count++) {
                        cp = cp->next;
                    }
                }
                
                /*
                 * ���µ�ǰ����ں��������е�λ��
                 *
                 * ע���˴��ĸ��»�ʹ��λ�ñ�󣬹���Ҫ���⸲�Ǻ����Ԫ��ֵ������ķ�֧���Դ�����
                 */
                cp->child = z;
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
                
                // ָ�򸸽��ĵ�һ������
                cp = R.nodes[R.nodes[z].parent].firstchild;
                
                // �����ǰ��㲻�ǵ�һ�����ӣ�����Ҫ��ѯ��ȷ��λ��
                if(pc[y].childIndex != 1) {
                    for(count = 1; count < pc[y].childIndex; count++) {
                        cp = cp->next;
                    }
                }
                
                // ���µ�ǰ����ں��������е�λ��
                cp->child = z;
            } else {
                // ������������һ�𣬼���c�ĸ����ĸ����Ϊp
                R.nodes[z].parent = tParent[pIndex];
                
                // ��װ��ǰ���
                s = (ChildPtr) malloc(sizeof(CTNode));
                s->child = z;
                
                // ָ��ý��ĸ������׸�����
                cp = R.nodes[R.nodes[z].parent].firstchild;
                
                if(cp == NULL || i == 1) {
                    s->next = R.nodes[R.nodes[z].parent].firstchild;
                    R.nodes[R.nodes[z].parent].firstchild = s;
                } else {
                    // ����
                    count = 1;
                    
                    // ���ҵ�i-1�����
                    while(cp != NULL && count < i - 1) {
                        count++;
                        cp = cp->next;
                    }
                    
                    s->next = cp->next;
                    cp->next = s;
                }
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
            
            // ָ�򸸽����׸�����
            cp = R.nodes[R.nodes[z].parent].firstchild;
            
            // �����ǰ��㲻�ǵ�һ�����ӣ�����Ҫ��ѯ��ȷ��λ��
            if(pt[x].childIndex != 1) {
                for(count = 1; count < pt[x].childIndex; count++) {
                    cp = cp->next;
                }
            }
            
            // ���µ�ǰ����ں��������е�λ��
            cp->child = z;
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
            
            // ָ�򸸽����׸�����
            cp = R.nodes[R.nodes[z].parent].firstchild;
            
            // �����ǰ��㲻�ǵ�һ�����ӣ�����Ҫ��ѯ��ȷ��λ��
            if(pc[y].childIndex != 1) {
                for(count = 1; count < pc[y].childIndex; count++) {
                    cp = cp->next;
                }
            }
            
            // ���µ�ǰ����ں��������е�λ��
            cp->child = z;
        } else {
            // ������������һ�𣬼���c�ĸ����ĸ����Ϊp
            R.nodes[z].parent = tParent[pIndex];
            
            // ��װ��ǰ���
            s = (ChildPtr) malloc(sizeof(CTNode));
            s->child = z;
            
            // ָ��ý��ĸ������׸�����
            cp = R.nodes[R.nodes[z].parent].firstchild;
            
            if(cp == NULL || i == 1) {
                s->next = R.nodes[R.nodes[z].parent].firstchild;
                R.nodes[R.nodes[z].parent].firstchild = s;
            } else {
                // ����
                count = 1;
                
                // ���ҵ�i-1�����
                while(cp != NULL && count < i - 1) {
                    count++;
                    cp = cp->next;
                }
                
                s->next = cp->next;
                cp->next = s;
            }
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
Status DeleteChild(CTree* T, TElemType p, int i) {
    LinkQueue Q;
    QElemType e;    // ����Ԫ��ָʾ����λ��
    
    int index;
    int k, m, n;
    
    CTree R;
    int parent[MAX_TREE_SIZE];
    ChildPtr cp, q, s;
    
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
    
    // ָ��ǰ���ĸ����ĵ�һ������
    cp = T->nodes[T->nodes[index].parent].firstchild;
    
    // �ڸ�������ҵ��˵�ǰ���Ӳ��Ƴ���
    if(cp->child==index) {
        T->nodes[T->nodes[index].parent].firstchild = cp->next;
    } else {
        // �ڸ�����в��ҵ�ǰ���Ӳ��Ƴ�����һ�����ҵ���
        while(cp != NULL && cp->child!=index) {
            s = cp;
            cp = cp->next;
        }
        
        s->next = cp->next;
    }
    free(cp);
    
    InitQueue(&Q);
    
    // ��ɾ���������ĸ�������
    EnQueue(&Q, index);
    
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &e);    // ������λ�ó���
        
        // Ĩ����ǰ���
        T->nodes[e].data = '\0';
        
        // ָ��ý��ĺ�������
        cp = T->nodes[e].firstchild;
    
        // �ͷŸý�㴦�ĺ���������ռ�ڴ�
        while(cp != NULL) {
            EnQueue(&Q, cp->child); // ��ǰ���λ�����
            
            q = cp;
            cp = cp->next;
            free(q);
        }
        
        T->nodes[e].firstchild = NULL;
    }
    
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
            
            if(R.nodes[m].parent!=-1) {
                // ���¸����λ��
                R.nodes[m].parent = parent[R.nodes[m].parent];
    
                // ָ�򸸽����׸�����
                cp = R.nodes[R.nodes[m].parent].firstchild;
    
                // �ڸ����ĺ��������в��ҵ�ǰ���
                while(cp->child != k) {
                    cp = cp->next;
                }
                
                /*
                 * ���µ�ǰ����ں��������е�λ��
                 *
                 * ע�������ֵλ��ֻ����µ���С�����Բ��õ��ĸ��Ǻ����Ԫ��λ��
                 * �����ڲ��Ҹú���ʱ����Ҫ��ȡInsertChild�еĲ�����
                 */
                cp->child = m;
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
Status PreOrderTraverse(CTree T, Status(Visit)(TElemType)) {
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    PreTraverse(T, T.r, Visit);
    
    printf("\n");
    
    return OK;
}

/*
 * �������
 */
Status PostOrderTraverse(CTree T, Status(Visit)(TElemType)) {
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    PostTraverse(T, T.r, Visit);
    
    printf("\n");
    
    return OK;
}

/*
 * �������
 */
Status LevelOrderTraverse(CTree T, Status(Visit)(TElemType)) {
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
static void Create(CTree* T, FILE* fp) {
    int r;          // ���ĸ�����λ�ã�������
    int n;          // ��¼Ԫ������
    int cur;        // �α�
    TElemType ch;
    LinkQueue Q;
    QElemType e;    // ����Ԫ��ָʾ����λ��
    char s[MAX_CHILD_COUNT + 1];
    int i;
    ChildPtr p, pc;
    
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
        T->nodes[cur].firstchild = NULL;
        cur = (cur + 1) % MAX_TREE_SIZE;
        n++;
        
        while(!QueueEmpty(Q)) {
            DeQueue(&Q, &e);    // ������λ�ó���
            
            printf("���������� %c �ĺ��ӽ�㣬�����ں���ʱ����һ��^��", T->nodes[e].data);
            scanf("%s", s);
            for(i = 0; i < strlen(s); i++) {
                if(s[i] == '^') {
                    break;
                }
                
                EnQueue(&Q, cur); // ��ǰ���λ�����
                T->nodes[cur].data = s[i];
                T->nodes[cur].parent = e;
                T->nodes[cur].firstchild = NULL;
                
                // �����ĳ���
                p = T->nodes[e].firstchild;
                
                // ��װ��ǰ���
                pc = (ChildPtr) malloc(sizeof(CTNode));
                pc->child = cur;
                pc->next = NULL;
                
                // ����ǰ�����ӵ������ĺ���������
                if(p == NULL) {
                    T->nodes[e].firstchild = pc;
                } else {
                    // �ҵ�����β��
                    while(p->next != NULL) {
                        p = p->next;
                    }
                    
                    p->next = pc;
                }
                
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
        T->nodes[cur].firstchild = NULL;
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
                T->nodes[cur].firstchild = NULL;
                
                // ��װ��ǰ���
                pc = (ChildPtr) malloc(sizeof(CTNode));
                pc->child = cur;
                pc->next = NULL;
                
                // �����ĳ���
                p = T->nodes[e].firstchild;
                
                // ����ǰ�����ӵ������ĺ���������
                if(p == NULL) {
                    T->nodes[e].firstchild = pc;
                } else {
                    // �ҵ�����β��
                    while(p->next != NULL) {
                        p = p->next;
                    }
                    
                    p->next = pc;
                }
                
                cur = (cur + 1) % MAX_TREE_SIZE;
                n++;
            }
        }
    }
    
    T->r = r;
    T->n = n;
}

// ���������e����������������ڣ�����-1
static int EIndex(CTree T, TElemType e) {
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
static int CIndex(CTree T, TElemType e, int i) {
    int p, count;
    ChildPtr s;
    
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
    
    // ָ��ý����׸�����
    s = T.nodes[p].firstchild;
    // ����
    count = 1;
    
    while(s != NULL && count < i) {
        count++;
        s = s->next;
    }
    
    if(s != NULL) {
        return s->child;
    } else {
        return -1;
    }
}

// ��ȡ��T�Ľ����Ϣ�����������Щ��Ϣ�������Pos���͵Ķ���
static void getPos(CTree T, Pos pt[]) {
    LinkQueue Q;
    QElemType e;
    ChildPtr cp;
    
    int level, n, count;
    
    memset(pt, 0, MAX_TREE_SIZE * sizeof(Pos));
    
    // ���������������������
    if(TreeEmpty(T)) {
        return;
    }
    
    InitQueue(&Q);
    
    // ������λ�����
    EnQueue(&Q, T.r);
    pt[T.r].row = 1;
    pt[T.r].col = 1;
    pt[T.r].childIndex = 1;
    
    // ��������ڵĲ�
    level = 0;
    
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &e);
        
        // ������������˸ı�
        if(pt[e].row != level) {
            count = 0;
            level = pt[e].row;
        }
        
        n = 0;  // ���e�ĺ��Ӽ�����0
        
        // ÿ��������ʱ�������������һ��������ϢΪ��Ч����Ϊ����ÿ����㶼�к��ӽ��
        pt[e].lastChild = -1;
        
        // ָ��ý��ĺ�������
        cp = T.nodes[e].firstchild;
        
        // �ͷŸý�㴦�ĺ���������ռ�ڴ�
        while(cp != NULL) {
            // ��ǰ���λ�����
            EnQueue(&Q, cp->child);
            
            // ��¼����
            pt[cp->child].row = pt[e].row + 1;
            
            // ��¼����
            pt[cp->child].col = ++count;
            
            // ��¼��ǰ����ǵڼ�������
            pt[cp->child].childIndex = ++n;
            
            // Ϊ�����������һ�����ӵ���Ϣ
            pt[e].lastChild = cp->child;
            
            cp = cp->next;
        }
    }
}

// ����������ڲ�ʵ��
static Status PreTraverse(CTree T, int i, Status(Visit)(TElemType)) {
    int firstChild = -1;    // ��ʼ��Ϊ��Ч������
    int rightBrother;
    
    // ���ʵ�ǰ���
    if(!Visit(T.nodes[i].data)) {
        return ERROR;
    }
    
    // ���˫�ױ�洢�ṹ�����Ӹ�������
    if(T.nodes[i].firstchild!=NULL) {
        firstChild = T.nodes[i].firstchild->child;
    }
    
    // �������ӣ���Ҫ��ȷ�����ӵ���ݣ�
    if(firstChild != -1 && !PreTraverse(T, firstChild, Visit)) {
        return ERROR;
    }
    
    rightBrother = (i + 1) % MAX_TREE_SIZE;
    
    // �������ֵܣ���Ҫ��ȷ�����ֵܵ���ݣ�
    if(T.nodes[i].parent == T.nodes[rightBrother].parent && !PreTraverse(T, rightBrother, Visit)) {
        return ERROR;
    }
    
    return OK;
}

// ����������ڲ�ʵ��
static Status PostTraverse(CTree T, int i, Status(Visit)(TElemType)) {
    int firstChild = -1;    // ��ʼ��Ϊ��Ч������
    int rightBrother;
    
    // ���˫�ױ�洢�ṹ�����Ӹ�������
    if(T.nodes[i].firstchild!=NULL) {
        firstChild = T.nodes[i].firstchild->child;
    }
    
    // �������ӣ���Ҫ��ȷ�����ӵ���ݣ�
    if(firstChild != -1 && !PostTraverse(T, firstChild, Visit)) {
        return ERROR;
    }
    
    // ���ʵ�ǰ���
    if(!Visit(T.nodes[i].data)) {
        return ERROR;
    }
    
    rightBrother = (i + 1) % MAX_TREE_SIZE;
    
    // �������ֵܣ���Ҫ��ȷ�����ֵܵ���ݣ�
    if(T.nodes[i].parent == T.nodes[rightBrother].parent && !PostTraverse(T, rightBrother, Visit)) {
        return ERROR;
    }
    
    return OK;
}

// ���pos��Ϣ�������ڲ�����ʹ��
static void printPos(CTree T, Pos pt[]) {
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
    
    for(i = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        printf("%2d ", pt[i].childIndex);
    }
    printf("\n");
    
}


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph(CTree T) {
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
static void Print(CTree T, Pos pt[], int i) {
    int firstChild = -1;    // ��ʼ��Ϊ��Ч������
    int rightBrother;
    int k;
    
    // ���ʵ�ǰ���
    printf("%c ", T.nodes[i].data);
    
    // ���˫�ױ�洢�ṹ�����Ӹ�������
    if(T.nodes[i].firstchild!=NULL) {
        firstChild = T.nodes[i].firstchild->child;
    }
    
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
static void PrintFramework(CTree T) {
    int k;
    ChildPtr cp;
    
    if(T.n == 0) {
        return;
    }
    
    printf("+---------+-----------\n");
    printf("|  i e  p | child list\n");
    printf("+---------+-----------\n");
    
    for(k = T.r; k != (T.r + T.n) % MAX_TREE_SIZE; k = (k + 1) % MAX_TREE_SIZE) {
        
        printf("| %2d %c %2d", k, T.nodes[k].data, T.nodes[k].parent);
        
        cp = T.nodes[k].firstchild;
        if(cp != NULL) {
            printf(" ->");
        } else {
            printf(" | ");
        }
        
        while(cp != NULL) {
            printf(" %2d", cp->child);
            cp = cp->next;
        }
        
        printf("\n");
    }
    
    printf("+---------+-----------\n");
}
