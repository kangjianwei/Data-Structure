#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "BiTree.h"     //**��06 ���Ͷ�����**//

#define MAX_TREE_DEPTH 20    // ������������
#define MAX_TREE_SIZE  1024  // ������Ԫ���������ֵ

/*
 * �����������е�k������ֵ��order����������
 */
Status Algo_6_41(BiTree T, int k, int* order, TElemType* e);

/*
 * �����������Ҷ�ӽ����Ŀ
 */
int Algo_6_42(BiTree T);

/*
 * ��������������������
 */
void Algo_6_43(BiTree T);

/*
 * �������������'x'�����
 */
int Algo_6_44(BiTree T, TElemType x);

/*
 * ɾ��������T�е�����x
 */
Status Algo_6_45(BiTree* T, TElemType x);

/*
 * ���ƶ������ķǵݹ��㷨
 */
void Algo_6_46(BiTree T, BiTree* Tx);

/*
 * �������������
 */
void Algo_6_47(BiTree T);

/*
 * �������Ĺ�ͬ����
 */
BiTree Algo_6_48(BiTree T, TElemType a, TElemType b);

/*
 * �ж϶������Ƿ�Ϊ��ȫ������
 */
Status Algo_6_49(BiTree T);

/*
 * ������Ѱ�Ҹ���㵽p����·����path�洢·���ϸ����ָ��(������p����ָ��)
 */
static int FindPath(BiTree T, TElemType e, BiTree path[]);

// ����ָ����������e��ָ��
static BiTree EPtr(BiTree T, TElemType e);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("���������� T ...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("�������� 6.41 ��֤...������\n");
    {
        int k = 9;
        int order = 0;  // ����
        TElemType e;
        
        if(Algo_6_41(T, k, &order, &e)) {
            printf("���������е� %d ��Ԫ��Ϊ %c \n", k, e);
        } else {
            printf("�˴�Ԫ�ز����ڣ�\n");
        }
        
        printf("\n");
    }
    
    printf("�������� 6.42 ��֤...������\n");
    {
        printf("��������Ҷ�ӽ�����Ϊ��%d\n", Algo_6_42(T));
        printf("\n");
    }
    
    printf("�������� 6.43 ��֤...������\n");
    {
        printf("���������������������������Ϊ��\n");
        Algo_6_43(T);
        PrintGraph(T);
        printf("\n");
    }
    
    printf("�������� 6.44 ��֤...������\n");
    {
        char x = 'E';
        
        printf("���� %c �����Ϊ�� %d\n", x, Algo_6_44(T, x));
        printf("\n");
    }
    
    printf("�������� 6.45 ��֤...������\n");
    {
        char x = 'D';
        
        printf("ɾ������ %c �󣬶�����Ϊ��\n", x);
        if(Algo_6_45(&T, x)) {
            PrintGraph(T);
        }
        printf("\n");
    }
    
    printf("�������� 6.46 ��֤...������\n");
    {
        BiTree Tx;
        
        printf("���� T �� Tx �󣬶�����TxΪ��\n");
        Algo_6_46(T, &Tx);
        PrintGraph(Tx);
        printf("\n");
    }
    
    printf("�������� 6.47 ��֤...������\n");
    {
        printf("�����������������Ϊ��");
        Algo_6_47(T);
        printf("\n");
    }
    
    printf("�������� 6.48 ��֤...������\n");
    {
        BiTree Tmp = NULL;
        TElemType a = 'I';
        TElemType b = 'H';
        
        if((Tmp = Algo_6_48(T, a, b)) != NULL) {
            printf("'%c' �� '%c' �������ͬ����Ϊ��'%c'\n", a, b, Tmp->data);
        }
        printf("\n");
    }
    
    printf("�������� 6.49 ��֤...������\n");
    {
        if(Algo_6_49(T)) {
            printf("�˶���������ȫ��������\n");
        } else {
            printf("�˶�����������ȫ������!��\n");
        }
    }
    
    return 0;
}


/*
 * �����������е�k������ֵ��order����������
 */
Status Algo_6_41(BiTree T, int k, int* order, TElemType* e) {
    
    if(T == NULL) {
        *e = '\0';
        return ERROR;
    }
    
    (*order)++;
    
    if(*order == k) {
        *e = T->data;
        return OK;
    } else {
        if(Algo_6_41(T->lchild, k, order, e)) {
            return OK;
        }
        
        if(Algo_6_41(T->rchild, k, order, e)) {
            return OK;
        }
    }
    
    return ERROR;
}

/*
 * �����������Ҷ�ӽ����Ŀ
 */
int Algo_6_42(BiTree T) {
    int count = 0;
    
    if(T != NULL) {
        if(T->lchild == NULL && T->rchild == NULL) {
            count++;
        } else {
            count += Algo_6_42(T->lchild);  // ������Ҷ�ӽ������
            count += Algo_6_42(T->rchild);  // ������Ҷ�ӽ������
        }
    }
    
    return count;
}

/*
 * ��������������������
 */
void Algo_6_43(BiTree T) {
    BiTree p;
    
    if(T != NULL) {
        p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
        
        // �ݹ齻��
        Algo_6_43(T->lchild);
        Algo_6_43(T->rchild);
    }
}

/*
 * �������T������'x'�����
 */
int Algo_6_44(BiTree T, TElemType x) {
    BiTree p;
    
    p = EPtr(T, x);         // ��һ���ݹ����x��λ�ã���ָ����ʽ����
    
    return BiTreeDepth(p);  // �ڶ����ݹ��������x�����
}

/*
 * ɾ��������T�е�����x
 */
Status Algo_6_45(BiTree* T, TElemType x) {
    
    if(*T == NULL) {
        return ERROR;
    }
    
    // ����ҵ��˸ý�㣬��ݹ��������
    if((*T)->data == x) {
        ClearBiTree(T);
        return OK;
        // �ݹ�����������Ѱ�Ҹý��
    } else {
        if(Algo_6_45(&((*T)->lchild), x)) {
            return OK;
        }
        
        if(Algo_6_45(&((*T)->rchild), x)) {
            return OK;
        }
        
        return ERROR;
    }
}

/*
 * ���ƶ������ķǵݹ��㷨
 */
void Algo_6_46(BiTree T, BiTree* Tx) {
    int front, rear;
    BiTree queue[MAX_TREE_SIZE] = {NULL};   // ��ָ�����飬����ģ����У���ʼ��Ԫ��ΪNULL
    BiTree tree[MAX_TREE_SIZE];     // �½��Ķ�����
    BiTree p;
    int parent;
    
    if(T == NULL) {
        *Tx = NULL;
        return;
    }
    
    front = rear = 0;
    
    queue[rear] = T;
    
    while(front <= rear) {
        p = queue[front];
        
        if(p == NULL) {
            front++;
            continue;
        }
        
        // �����½��
        tree[front] = (BiTree) malloc(sizeof(BiTNode));
        tree[front]->data = p->data;
        tree[front]->lchild = tree[front]->rchild = NULL;
        
        // Ϊ�ý��ҽ��ڸ������
        if(front > 0) {
            parent = (front - 1) / 2;
            
            // �����ǰ�����Ϊ����
            if(2 * parent + 1 == front) {
                tree[parent]->lchild = tree[front];
            } else {
                tree[parent]->rchild = tree[front];
            }
        }
        
        if(p->lchild != NULL) {
            rear = 2 * front + 1;
            queue[rear] = p->lchild;
        }
        
        if(p->rchild != NULL) {
            rear = 2 * front + 2;
            queue[rear] = p->rchild;
        }
        
        front++;
    }
    
    *Tx = tree[0];
}

/*
 * �������������
 */
void Algo_6_47(BiTree T) {
    int front, rear;
    BiTree queue[MAX_TREE_SIZE];  // ��ָ�����飬����ģ�����
    BiTree p;
    
    if(T == NULL) {
        return;
    }
    
    front = rear = 0;
    
    queue[rear++] = T;
    
    while(front != rear) {
        p = queue[front++];
        
        printf("%c ", p->data);
        
        if(p->lchild != NULL) {
            queue[rear++] = p->lchild;
        }
        
        if(p->rchild != NULL) {
            queue[rear++] = p->rchild;
        }
    }
    
    printf("\n");
}

/*
 * �������Ĺ�ͬ����
 */
BiTree Algo_6_48(BiTree T, TElemType a, TElemType b) {
    BiTree pa[MAX_TREE_DEPTH] = {NULL};
    BiTree pb[MAX_TREE_DEPTH] = {NULL};
    int lenA, lenB;
    int i, j;
    
    // ������·��Ѱ�Һ���
    if((lenA = FindPath(T, a, pa)) != 0 && (lenB = FindPath(T, b, pb)) != 0) {
        for(i = lenA - 1; pa[i] != NULL; i--) {
            for(j = lenB - 1; pb[j] != NULL; j--) {
                if(pa[i]->data == pb[j]->data) {
                    return pa[i];
                }
            }
        }
    }
    
    return NULL;
}

/*
 * �ж϶������Ƿ�Ϊ��ȫ������
 *
 * ��ȫ���������ص��ǲ������ʱ�������������һ��
 */
Status Algo_6_49(BiTree T) {
    int front, rear;
    BiTree queue[MAX_TREE_SIZE];     // ��ָ�����飬ģ�����
    int order[MAX_TREE_SIZE];
    BiTree p;
    int count;
    
    if(T == NULL) {
        return OK;
    }
    
    front = rear = 0;
    count = 1;
    
    queue[rear] = T;
    order[rear] = 1;
    rear++;
    
    // ������ͬʱΪ�������
    while(front < rear) {
        if(order[front] != count) {
            return ERROR;
        }
        
        p = queue[front];   // ��ȡ��ͷԪ��
        
        if(p->lchild != NULL) {
            queue[rear] = p->lchild;
            order[rear] = 2 * order[front];
            rear++;
        }
        
        if(p->rchild != NULL) {
            queue[rear] = p->rchild;
            order[rear] = 2 * order[front] + 1;
            rear++;
        }
        
        front++;
        count++;    // ÿ����һ����������һ
    }
    
    return OK;
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

// ������Ѱ�Ҹ���㵽p����·����path�洢·���ϸ����ָ��(������p����ָ��)
static int FindPath(BiTree T, TElemType e, BiTree path[]) {
    int i = -1;
    int mark[MAX_TREE_DEPTH] = {0}; // ���ʱ��ջ
    BiTree p;
    
    p = T;
    
    while(TRUE) {
        // ���û���������������Ľ�㣬�ȳ���������������
        while(p != NULL && p->data != e) {
            i++;
            
            // ���µ�ǰ����ָ��
            path[i] = p;
            
            // �ѷ��ʹ��ý���������
            mark[i] = 1;
            p = p->lchild;
        }
        
        // ���������������Ľ��
        if(p != NULL) {
            return i + 1;
        }
        
        // �ص������
        p = path[i];
        
        // ��������������ڣ����߸��������ѱ����ʹ�����ص����ĸ����
        while(p->rchild == NULL || mark[i] == 2) {
            path[i] = NULL;     // �ÿո�λ��
            
            i--;
            if(i == -1) {
                return 0;
            }
            
            // ���˵������
            p = path[i];
        }
        
        // �ѷ��ʹ��ý���������
        mark[i] = 2;
        p = p->rchild;
    }
}
