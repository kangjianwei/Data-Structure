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
