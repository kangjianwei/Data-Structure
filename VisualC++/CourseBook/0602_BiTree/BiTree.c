/*=============================
 * �������Ķ�������洢�ṹ
 *
 * �����㷨: 6.1��6.2��6.3��6.4
 =============================*/

#include "BiTree.h"
#include "LinkQueue.h"  //**��03 ջ�Ͷ���**//
#include "SqStack.h"    //**��03 ջ�Ͷ���**//

/*
 * ��ʼ��
 *
 * ����ն�������
 */
Status InitBiTree(BiTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    *T = NULL;
    
    return OK;
}

/*
 * ����
 *
 * �ͷŶ�������ռ�ڴ档
 *
 *��ע��
 * �������Ķ�������洢�ṹ�������٣�����û��Ҫ���١�
 * ��Ϊ�����������ٺ��״̬���ÿպ��״̬��һ�µġ�
 */
Status DestroyBiTree(BiTree* T) {
    // �������٣�ʹ���ÿվͿ���
    return ERROR;
}

/*
 * �ÿ�
 *
 * ����������е����ݣ�ʹ���Ϊ������
 */
Status ClearBiTree(BiTree* T) {
    if(T == NULL) {
        return ERROR;
    }
    
    // ��*T��Ϊ��ʱ���еݹ�����
    if(*T) {
        if((*T)->lchild!=NULL) {
            ClearBiTree(&((*T)->lchild));
        }
        
        if((*T)->rchild!=NULL) {
            ClearBiTree(&((*T)->rchild));
        }
        
        free(*T);
        *T = NULL;
    }
    
    return OK;
}

/*
 * ���������������� �㷨6.4 ����������������
 *
 * ����
 *
 * ����Ԥ��Ķ�����������������
 * ����Լ��ʹ�á��������С���������������
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
Status CreateBiTree(BiTree* T, char* path) {
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("��������������������У����û���ӽ�㣬ʹ��^���棺");
        CreateTree(T, NULL);
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        CreateTree(T, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * �п�
 *
 * �ж϶������Ƿ�Ϊ������
 */
Status BiTreeEmpty(BiTree T) {
    return T == NULL ? TRUE : FALSE;
}

/*
 * ����
 *
 * ���ض���������ȣ���������
 */
int BiTreeDepth(BiTree T) {
    int LD, RD;
    
    if(T == NULL) {
        return 0;                       // �������Ϊ0
    } else {
        LD = BiTreeDepth(T->lchild);    // �����������
        RD = BiTreeDepth(T->rchild);    // �����������
        
        return (LD >= RD ? LD : RD) + 1;
    }
}

/*
 * ȡֵ
 *
 * ���ض�������ָ������ֵ��
 */
TElemType Value(BiTree T, TElemType e) {
    BiTree p;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
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
 * Ϊ������ָ���Ľ�㸳ֵ��
 */
Status Assign(BiTree T, TElemType e, TElemType value) {
    BiTree p;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
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
 * ���ض������ĸ���㡣
 */
TElemType Root(BiTree T) {
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    return T->data;
}

/*
 * ˫��
 *
 * ���ض������н��e��˫�׽�㡣
 */
TElemType Parent(BiTree T, TElemType e) {
    BiTree p;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
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
 * ����
 *
 * ���ض������н��e�����ӽ�㡣
 */
TElemType LeftChild(BiTree T, TElemType e) {
    BiTree p;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e��ָ��
    p = EPtr(T, e);
    
    // ����ҵ���Ԫ��e
    if(p != NULL && p->lchild != NULL) {
        return p->lchild->data;
    }
    
    return '\0';
}

/*
 * �Һ���
 *
 * ���ض������н��e���Һ��ӽ�㡣
 */
TElemType RightChild(BiTree T, TElemType e) {
    BiTree p;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e��ָ��
    p = EPtr(T, e);
    
    // ����ҵ���Ԫ��e
    if(p != NULL && p->rchild != NULL) {
        return p->rchild->data;
    }
    
    return '\0';
}

/*
 * ���ֵ�
 *
 * ���ض������н��e�����ֵܽ�㡣
 */
TElemType LeftSibling(BiTree T, TElemType e) {
    BiTree p;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e��˫�׽���ָ��
    p = PPtr(T, e);
    
    // ����ҵ���Ԫ��e��˫��
    if(p != NULL && p->lchild != NULL) {
        return p->lchild->data;
    }
    
    return '\0';
}

/*
 * ���ֵ�
 *
 * ���ض������н��e�����ֵܽ�㡣
 */
TElemType RightSibling(BiTree T, TElemType e) {
    BiTree p;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e��˫�׽���ָ��
    p = PPtr(T, e);
    
    // ����ҵ���Ԫ��e��˫��
    if(p != NULL && p->rchild != NULL) {
        return p->rchild->data;
    }
    
    return '\0';
}

/*
 * ����
 *
 * ��֪cΪ��T���ཻ�ķǿն���������c��������Ϊ�գ�
 * ����LR��ȡֵ(0��1)����c����ΪT�н��p��������/��������
 * ���ң���p���ԭ�е�������/�������޽�Ϊ������c����������
 */
Status InsertChild(BiTree T, TElemType p, int LR, BiTree c) {
    BiTree p_ptr;
    
    // ������������Ϊ�����������������
    if(BiTreeEmpty(c)) {
        return ERROR;
    }
    
    // ��ȡ���p��ָ��
    p_ptr = EPtr(T, p);
    
    // ���p��㲻���ڣ��򷵻ش�����ʾ
    if(p_ptr == NULL) {
        return ERROR;
    }
    
    // ��c����Ϊp��������
    if(LR==0) {
        // ���p����������������ժ��p��������������Ϊc��������
        if(p_ptr->lchild!=NULL) {
            c->rchild = p_ptr->lchild;
        }
        
        p_ptr->lchild = c;
    } else {
        // ���p����������������ժ��p��������������Ϊc��������
        if(p_ptr->rchild!=NULL) {
            c->rchild = p_ptr->rchild;
        }
    
        p_ptr->rchild = c;
    }
    
    return OK;
}

/*
 * ɾ��
 *
 * ����LR��ȡֵ(0��1)��ɾ�����p��������/��������
 */
Status DeleteChild(BiTree T, TElemType p, int LR) {
    BiTree p_ptr;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return ERROR;
    }
    
    // ��ȡ���p��ָ��
    p_ptr = EPtr(T, p);
    
    // ���p��㲻���ڣ��򷵻ش�����ʾ
    if(p_ptr == NULL) {
        return ERROR;
    }
    
    // �����Ҫɾ��p��������
    if(LR == 0) {
        ClearBiTree(&(p_ptr->lchild));
        
        // �����Ҫɾ��p��������
    } else {
        ClearBiTree(&(p_ptr->rchild));
    }
    
    return OK;
}

/*
 * ���������������� �㷨6.1 ����������������
 *
 * �������
 */
Status PreOrderTraverse(BiTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = PreTraverse(T, Visit);
    printf("\n");
    
    return status;
}

/*
 * �������
 */
Status InOrderTraverse(BiTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = InTraverse(T, Visit);
    printf("\n");
    
    return status;
}

/*
 * ���������������� �㷨6.2 ����������������
 *
 * �������
 *
 *��ע��
 * �ǵݹ��㷨
 */
Status InOrderTraverse_2(BiTree T, Status(Visit)(TElemType)) {
    SqStack S;
    BiTree p;
    
    InitStack(&S);
    Push(&S, T);    // ��ָ����ջ
    
    while(!StackEmpty(S)) {
        // �����ߵ���ͷ
        while(GetTop(S, &p) && p != NULL) {
            Push(&S, p->lchild);
        }
        
        Pop(&S, &p);    // ��ָ����ջ
        
        if(!StackEmpty(S)) {
            // ���ʽ��
            Pop(&S, &p);
            if(!Visit(p->data)) {
                return ERROR;
            }
            
            // ����һ��
            Push(&S, p->rchild);
        }
    }
    
    printf("\n");
    
    return OK;
}

/*
 * ���������������� �㷨6.3 ����������������
 *
 * �������
 *
 *��ע��
 * �ǵݹ��㷨
 */
Status InOrderTraverse_3(BiTree T, Status(Visit)(TElemType)) {
    SqStack S;
    BiTree p;
    
    InitStack(&S);
    
    p = T;
    
    while(p != NULL || !StackEmpty(S)) {
        if(p != NULL) {
            Push(&S, p);    // ��ָ���ջ
            p = p->lchild;  // ����������
        } else {
            // ���ʽ��
            Pop(&S, &p);
            if(!Visit(p->data)) {
                return ERROR;
            }
            
            p = p->rchild;
        }
    }
    
    printf("\n");
    
    return OK;
}

/*
 * �������
 */
Status PostOrderTraverse(BiTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = PostTraverse(T, Visit);
    printf("\n");
    
    return status;
}

/*
 * �������
 */
Status LevelOrderTraverse(BiTree T, Status(Visit)(TElemType)) {
    LinkQueue Q;
    BiTree e;
    
    // ������Ϊ��
    if(T == NULL) {
        printf("\n");
        return OK;
    }
    
    // ��������ʵ�ֲ������
    InitQueue(&Q);
    
    // ��ָ�����
    EnQueue(&Q, T);
    
    // һֱѭ����ֱ������Ϊ��
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &e);
        
        // ����Ԫ��
        if(!Visit(e->data)) {
            return ERROR;
        }
        
        // �������
        if(e->lchild != NULL) {
            EnQueue(&Q, e->lchild);
        }
        
        // �Һ������
        if(e->rchild != NULL) {
            EnQueue(&Q, e->rchild);
        }
    }
    
    printf("\n");
    
    return OK;
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������������ڲ�����
static void CreateTree(BiTree* T, FILE* fp) {
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
        *T = (BiTree) malloc(sizeof(BiTNode));
        if(!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        CreateTree(&((*T)->lchild), fp); // ����������
        CreateTree(&((*T)->rchild), fp); // ����������
    }
}

// ����ָ����������e��ָ��
static BiTree EPtr(BiTree T, TElemType e) {
    BiTree pl, pr;
    
    if(T == NULL) {
        return NULL;
    }
    
    // ����ҵ���Ŀ���㣬ֱ�ӷ�����ָ��
    if(T->data == e) {
        return T;
    }
    
    // ���������в���e
    pl = EPtr(T->lchild, e);
    if(pl != NULL) {
        return pl;
    }
    
    // ���������в���e
    pr = EPtr(T->rchild, e);
    if(pr != NULL) {
        return pr;
    }
    
    return NULL;
}

// ����ָ����������e��˫�׽���ָ��
static BiTree PPtr(BiTree T, TElemType e) {
    BiTree pl, pr;
    
    if(T == NULL || T->data == e) {
        return NULL;
    }
    
    // e��T������
    if(T->lchild != NULL && T->lchild->data == e) {
        return T;
    }
    
    // e��T���Һ���
    if(T->rchild != NULL && T->rchild->data == e) {
        return T;
    }
    
    // ���������в���e
    pl = PPtr(T->lchild, e);
    if(pl != NULL) {
        return pl;
    }
    
    // ���������в���e
    pr = PPtr(T->rchild, e);
    if(pr != NULL) {
        return pr;
    }
    
    return NULL;
}

// ����������ڲ�ʵ��
static Status PreTraverse(BiTree T, Status(Visit)(TElemType)) {
    if(T) {
        if(Visit(T->data)) {
            if(PreTraverse(T->lchild, Visit)) {
                if(PreTraverse(T->rchild, Visit)) {
                    return OK;
                }
            }
        }
        
        return ERROR;
    
        // ���������������������
    } else {
        return OK;
    }
}

// ����������ڲ�ʵ��
static Status InTraverse(BiTree T, Status(Visit)(TElemType)) {
    if(T) {
        if(InTraverse(T->lchild, Visit)) {
            if(Visit(T->data)) {
                if(InTraverse(T->rchild, Visit)) {
                    return OK;
                }
            }
        }
        
        return ERROR;
        
        // ���������������������
    } else {
        return OK;
    }
}

// ����������ڲ�ʵ��
static Status PostTraverse(BiTree T, Status(Visit)(TElemType)) {
    if(T) {
        if(PostTraverse(T->lchild, Visit)) {
            if(PostTraverse(T->rchild, Visit)) {
                if(Visit(T->data)) {
                    return OK;
                }
            }
        }
        
        return ERROR;
        
        // ���������������������
    } else {
        return OK;
    }
}


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

// ��ͼ�λ���ʽ�����ǰ�ṹ�������ڲ�����ʹ��
void PrintGraph(BiTree T) {
    int level, width;
    int i, j, k, w;
    int begin;
    int distance;
    TElemType** tmp;
    LinkQueue Q;
    BiTree e;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        printf("\n");
        return;
    }
    
    level = BiTreeDepth(T);         // ����ȫ���������ṹ�߶�
    width = (int)pow(2, level)-1;   // ����ȫ���������ṹ���
    
    // ��̬������
    tmp = (TElemType**)malloc(level* sizeof(TElemType*));
    
    // ��̬������
    for(i = 0; i < level; i++) {
        tmp[i] = (TElemType*)malloc(width* sizeof(TElemType));
        
        // ��ʼ���ڴ�ֵΪ���ַ�
        memset(tmp[i], '\0', width);
    }
    
    // ��������ʵ�ֲ������
    InitQueue(&Q);
    EnQueue(&Q, T);
    
    // ������������Ԫ�أ����䰲�ŵ���ά����tmp�к��ʵ�λ��
    for(i = 0; i < level; i++) {
        w        = (int) pow(2, i);             // ��������ǰ��Ŀ��
        distance = width / w;                   // ��������ǰ���Ԫ�ؼ��
        begin    = width / (int) pow(2, i + 1); // ��������ǰ���׸�Ԫ��֮ǰ�Ŀո���
        
        for(k = 0; k < w; k++) {
            DeQueue(&Q, &e);
            
            if(e == NULL) {
                EnQueue(&Q, NULL);
                EnQueue(&Q, NULL);
            } else {
                j = begin + k * (1 + distance);
                tmp[i][j] = e->data;
                
                // �������
                EnQueue(&Q, e->lchild);
                
                // �Һ������
                EnQueue(&Q, e->rchild);
            }
        }
    }
    
    for(i = 0; i < level; i++) {
        for(j = 0; j < width; j++) {
            if(tmp[i][j] != '\0') {
                printf("%c", tmp[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
