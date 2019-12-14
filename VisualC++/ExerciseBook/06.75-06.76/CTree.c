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
