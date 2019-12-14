/*===================================
 * ���Ķ�����������-�ֵܣ��ṹ�洢��ʾ
 ====================================*/

#include "CSTree.h"
#include "LinkQueue.h"  //**��03 ջ�Ͷ���**//

/*
 * ��ʼ��
 *
 * ���������
 */
Status InitTree(CSTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    *T = NULL;
    
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
Status DestroyTree(CSTree* T) {
    // �������٣�ʹ���ÿվͿ���
    return ERROR;
}

/*
 * �ÿ�
 *
 * �������е����ݣ�ʹ���Ϊ������
 */
Status ClearTree(CSTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    // ��*T��Ϊ��ʱ���еݹ�����
    if(*T) {
        if((*T)->firstchild != NULL) {
            ClearTree(&((*T)->firstchild));
        }
        
        if((*T)->nextsibling != NULL) {
            ClearTree(&((*T)->nextsibling));
        }
        
        free(*T);
        *T = NULL;
    }
    
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
Status CreateTree(CSTree* T, char* path) {
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("�����������������У����û�к��ӽ���û���ֵܽڵ㣬ʹ��^���棺");
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
Status TreeEmpty(CSTree T) {
    return T == NULL ? TRUE : FALSE;
}

/*
 * ����
 *
 * ����������ȣ���������
 */
int TreeDepth(CSTree T) {
    int max = 0;
    
    Depth(T, 0, &max);
    
    return max;
}

/*
 * ȡֵ
 *
 * ��������ָ������ֵ��
 */
TElemType Value(CSTree T, TElemType e) {
    CSTree p;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e��ָ��
    p = EPtr(T, e);
    
    // ���û���ҵ�Ԫ��e
    if(p == NULL) {
        return '\0';
    } else {
        return p->data;
    }
}

/*
 * ��ֵ
 *
 * Ϊ��ָ���Ľ�㸳ֵ��
 */
Status Assign(CSTree T, TElemType e, TElemType value) {
    CSTree p;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return ERROR;
    }
    
    // ��ȡ���e��ָ��
    p = EPtr(T, e);
    
    // ���û���ҵ�Ԫ��e
    if(p == NULL) {
        return ERROR;
    } else {
        // ���и�ֵ
        p->data = value;
        return OK;
    }
}

/*
 * ��
 *
 * �������ĸ���㡣
 */
TElemType Root(CSTree T) {
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    return T->data;
}

/*
 * ˫��
 *
 * �������н��e��˫�׽�㡣
 */
TElemType Parent(CSTree T, TElemType e) {
    CSTree p;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e��˫�׽���ָ��
    p = PPtr(T, e);
    
    // ���û���ҵ�Ԫ��e��˫��
    if(p == NULL) {
        return '\0';
    } else {
        return p->data;
    }
}

/*
 * ��������
 *
 * ������T�н��e�ĺ���������
 */
int ChildCount(CSTree T, TElemType e) {
    CSTree p;
    int count;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return 0;
    }
    
    // ��ȡ���e��ָ��
    p = EPtr(T, e);
    
    // ���û���ҵ�Ԫ��e
    if(p == NULL) {
        return 0;
    }
    
    count = 0;
    
    for(p = p->firstchild; p != NULL; p = p->nextsibling) {
        count++;
    }
    
    return count;
}

/*
 * ����
 *
 * �������н��e�ĵ�i�����ӡ�
 */
TElemType Child(CSTree T, TElemType e, int i) {
    CSTree p;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return 0;
    }
    
    // i�ķ�ΧԽ��
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return '\0';
    }
    
    // ��ȡ���e�ĵ�i�����ӵ�ָ��
    p = CPtr(T, e, i);
    
    if(p != NULL) {
        return p->data;
    } else {
        return '\0';
    }
}

/*
 * ���ֵ�
 *
 * �������н��e�����ֵܽ�㡣
 */
TElemType LeftSibling(CSTree T, TElemType e) {
    CSTree p;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e��˫�׽���ָ��
    p = PPtr(T, e);
    
    // ���û���ҵ�Ԫ��e��˫��
    if(p == NULL) {
        return '\0';
    }
    
    // ����e���ڶ��ֵ�
    for(p = p->firstchild; p != NULL; p = p->nextsibling) {
        if(p->nextsibling != NULL && p->nextsibling->data == e) {
            return p->data;
        }
    }
    
    return '\0';
}

/*
 * ���ֵ�
 *
 * �������н��e�����ֵܽ�㡣
 */
TElemType RightSibling(CSTree T, TElemType e) {
    CSTree p;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e��ָ��
    p = EPtr(T, e);
    
    // ���û���ҵ�Ԫ��e��˫��
    if(p == NULL) {
        return '\0';
    }
    
    if(p->nextsibling != NULL) {
        return p->nextsibling->data;
    } else {
        return '\0';
    }
}

/*
 * ����
 *
 * ����c����Ϊ��T��p���ĵ�i�����ӡ�
 */
Status InsertChild(CSTree* T, TElemType p, int i, CSTree c) {
    CSTree r;
    
    // �����Ϊ�����������������
    if(TreeEmpty(*T) || TreeEmpty(c)) {
        return ERROR;
    }
    
    // i�ķ�Χ����С
    if(i < 1) {
        return ERROR;
    }
    
    // ����Ϊ��һ������
    if(i == 1) {
        r = (*T)->firstchild;
        (*T)->firstchild = c;
        c->nextsibling = r;
    } else {
        // ��ȡ���p�ĵ�i-1�����ӵ�ָ��
        r = CPtr(*T, p, i - 1);
        if(r == NULL) {
            return ERROR;
        }
        
        c->nextsibling = r->nextsibling;
        r->nextsibling = c;
    }
    
    return OK;
}

/*
 * ɾ��
 *
 * ɾ����T��p���ĵ�i�����ӡ�
 */
Status DeleteChild(CSTree* T, TElemType p, int i) {
    CSTree r, q;
    
    // �����ɾ������Ϊ�����������������
    if(TreeEmpty(*T)) {
        return ERROR;
    }
    
    // i�ķ�ΧԽ�磨�����жϣ�
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return ERROR;
    }
    
    // ɾ����һ�����ӣ�����������
    if(i == 1) {
        // �����p��ָ��
        r = EPtr(*T, p);
        if(r == NULL) {
            return ERROR;
        }
        
        q = r->firstchild;
        r->firstchild = q->nextsibling;
        q->nextsibling = NULL;
    } else {
        // ��ȡ���p�ĵ�i-1�����ӵ�ָ��
        r = CPtr(*T, p, i - 1);
        if(r == NULL) {
            return ERROR;
        }
        
        // ��i������
        q = r->nextsibling;
        r->nextsibling = q->nextsibling;
        q->nextsibling = NULL;
    }
    
    ClearTree(&q);
    
    return OK;
}

/*
 * �������
 */
Status PreOrderTraverse(CSTree T, Status(Visit)(TElemType)) {
    
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    PreTraverse(T, Visit);
    
    printf("\n");
    
    return OK;
}

/*
 * �������
 */
Status PostOrderTraverse(CSTree T, Status(Visit)(TElemType)) {
    
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    PostTraverse(T, Visit);
    
    printf("\n");
    
    return OK;
}

/*
 * �������
 */
Status LevelOrderTraverse(CSTree T, Status(Visit)(TElemType)) {
    LinkQueue Q;
    QElemType p, pc;
    
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return ERROR;
    }
    
    InitQueue(&Q);
    EnQueue(&Q, T);
    
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &p);    // �����Ľ����Ϊ�����
    
        if(!Visit(p->data)) {
            return ERROR;
        }
        
        // ���ý��ĺ������
        for(pc = p->firstchild; pc != NULL; pc = pc->nextsibling) {
            EnQueue(&Q, pc);
        }
    }
    
    printf("\n");
    
    return OK;
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// ���������ڲ�����
static void Create(CSTree* T, FILE* fp) {
    char ch;
    
    // ��ȡ��ǰ����ֵ
    if(fp == NULL) {
        scanf("%c", &ch);
    } else {
        ReadData(fp, "%c", &ch);
    }
    
    if(ch == '^') {
        *T = NULL;
    } else {
        // ���ɸ����
        *T = (CSTree) malloc(sizeof(CSNode));
        if(!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        Create(&((*T)->firstchild), fp);    // ��������
        Create(&((*T)->nextsibling), fp);   // �������ֵ�
    }
}

// ����������ȵ��ڲ�ʵ��
static void Depth(CSTree T, int d, int* max) {
    if(T == NULL) {
        return;
    }
    
    d++;    // ָʾ��ǰ���ڵĲ���
    
    if(d > *max) {
        *max = d;
    }
    
    Depth(T->firstchild, d, max);       // ���±���
    Depth(T->nextsibling, --d, max);    // ���ұ���
}

// ���������e��ָ�룬��������ڣ�����NULL
static CSTree EPtr(CSTree T, TElemType e) {
    CSTree pc, ps;
    
    if(T == NULL) {
        return NULL;
    }
    
    // ����ҵ���Ŀ���㣬ֱ�ӷ�����ָ��
    if(T->data == e) {
        return T;
    }
    
    // ���²���e
    pc = EPtr(T->firstchild, e);
    if(pc != NULL) {
        return pc;
    }
    
    // ���Ҳ���e
    ps = EPtr(T->nextsibling, e);
    if(ps != NULL) {
        return ps;
    }
    
    return NULL;
}

// ���������e��˫�׽���ָ�룬��������ڣ�����NULL
static CSTree PPtr(CSTree T, TElemType e) {
    LinkQueue Q;
    QElemType p, pc;
    
    // �����û��˫��
    if(T == NULL || T->data == e) {
        return NULL;
    }
    
    InitQueue(&Q);
    EnQueue(&Q, T);
    
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &p);    // �����Ľ����Ϊ�����
        
        // ���ý��ĺ������
        for(pc = p->firstchild; pc != NULL; pc = pc->nextsibling) {
            if(pc->data == e) {
                return p;
            }
            
            EnQueue(&Q, pc);
        }
    }
    
    return NULL;
}

// ���������e�ĵ�i�����ӵ�ָ�룬��������ڣ�����NULL
static CSTree CPtr(CSTree T, TElemType e, int i) {
    CSTree p;
    int count;
    
    // ���������������������
    if(TreeEmpty(T)) {
        return NULL;
    }
    
    // i�ķ�ΧԽ��
    if(i < 1 || i > MAX_CHILD_COUNT) {
        return NULL;
    }
    
    // ��ȡ���e��ָ��
    p = EPtr(T, e);
    
    // ���û���ҵ�Ԫ��e
    if(p == NULL) {
        return NULL;
    }
    
    p = p->firstchild;
    count = 1;
    
    while(p != NULL && count < i) {
        p = p->nextsibling;
        count++;
    }
    
    if(p != NULL) {
        return p;
    } else {
        return NULL;
    }
}

// ����������ڲ�ʵ��
static Status PreTraverse(CSTree T, Status(Visit)(TElemType)) {
    CSTree firstChild;
    CSTree rightBrother;
    
    // ���ʵ�ǰ���
    if(!Visit(T->data)) {
        return ERROR;
    }
    
    firstChild = T->firstchild;
    
    // �������ӣ���Ҫ��ȷ�����ӵ���ݣ�
    if(firstChild != NULL && !PreTraverse(T->firstchild, Visit)) {
        return ERROR;
    }
    
    rightBrother = T->nextsibling;
    
    // �������ֵܣ���Ҫ��ȷ�����ֵܵ���ݣ�
    if(rightBrother != NULL && !PreTraverse(rightBrother, Visit)) {
        return ERROR;
    }
    
    return OK;
}

// ����������ڲ�ʵ��
static Status PostTraverse(CSTree T, Status(Visit)(TElemType)) {
    CSTree firstChild;
    CSTree rightBrother;
    
    firstChild = T->firstchild;
    
    // �������ӣ���Ҫ��ȷ�����ӵ���ݣ�
    if(firstChild != NULL && !PostTraverse(T->firstchild, Visit)) {
        return ERROR;
    }
    
    // ���ʵ�ǰ���
    if(!Visit(T->data)) {
        return ERROR;
    }
    
    rightBrother = T->nextsibling;
    
    // �������ֵܣ���Ҫ��ȷ�����ֵܵ���ݣ�
    if(rightBrother != NULL && !PostTraverse(rightBrother, Visit)) {
        return ERROR;
    }
    
    return OK;
}


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ
void PrintGraph(CSTree T) {
    
    // ���������������������
    if(TreeEmpty(T)) {
        printf("\n");
        return;
    }
    
    Print(T, 0);
    
    printf("\n");
}

// ͼ�λ������ǰ�ṹ�ڲ�ʵ��
static void Print(CSTree T, int row) {
    int k;
    
    if(T == NULL) {
        return;
    }
    
    // ���ʵ�ǰ���
    printf("%c ", T->data);
    
    Print(T->firstchild, row + 1);
    
    if(T->nextsibling != NULL) {
        printf("\n");
        
        for(k = 0; k < row; k++) {
            printf(". ");
        }
        
        Print(T->nextsibling, row);
    }
}
