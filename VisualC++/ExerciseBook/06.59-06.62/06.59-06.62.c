#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "CSTree.h"     //**��06 ���Ͷ�����**//

#define MAX_TREE_SIZE  1024  // ����Ԫ���������ֵ

/*
 * ������ĸ�����
 */
void Algo_6_59(CSTree T);

/*
 * ������Ҷ�ӽ�����
 */
int Algo_6_60(CSTree T);

/*
 * �����Ķȣ����и����ȵ����ֵ
 */
int Algo_6_61(CSTree T);

/*
 * ���������
 */
int Algo_6_62(CSTree T);


int main(int argc, char* argv[]) {
    CSTree T;
    
    printf("���������������У�T...\n");
    InitTree(&T);
    CreateTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("�������� 6.59 ��֤...������\n");
    {
        printf("������б�...\n");
        Algo_6_59(T);
        printf("\n\n");
    }
    
    printf("�������� 6.60 ��֤...������\n");
    {
        int count;
        
        count = Algo_6_60(T);
        printf("Ҷ�ӽ�����Ϊ��count = %d\n", count);
        printf("\n");
    }
    
    printf("�������� 6.61 ��֤...������\n");
    {
        int degree;
        
        degree = Algo_6_61(T);
        printf("���Ķ�Ϊ��degree = %d\n", degree);
        printf("\n");
    }
    
    printf("�������� 6.62 ��֤...������\n");
    {
        int depth;
        
        depth = Algo_6_62(T);
        printf("�������Ϊ��depth = %d\n", depth);
        printf("\n");
    }
    
    return 0;
}


/*
 * ������ĸ�����
 */
void Algo_6_59(CSTree T) {
    CSTree p, q;
    
    if(T == NULL) {
        return;
    }
    
    p = T;
    q = T->firstchild;
    
    while(q != NULL) {
        printf("(%c, %c) ", p->data, q->data);
        q = q->nextsibling;
    }
    
    Algo_6_59(T->firstchild);
    Algo_6_59(T->nextsibling);
}

/*
 * ������Ҷ�ӽ�����
 */
int Algo_6_60(CSTree T) {
    if(T == NULL) {
        return 0;
    }
    
    // ����Ҷ�ӽ��
    if(T->firstchild == NULL) {
        return 1 + Algo_6_60(T->nextsibling);
    } else {
        return Algo_6_60(T->firstchild) + Algo_6_60(T->nextsibling);
    }
}

/*
 * �����Ķȣ����и����ȵ����ֵ
 */
int Algo_6_61(CSTree T) {
    CSTree queue[MAX_TREE_SIZE];    // ������洢���ʹ��Ľ��
    int parent[MAX_TREE_SIZE];      // �洢ÿ�����ĸ����
    int order[MAX_TREE_SIZE];       // �洢ÿ�����ı��
    CSTree p, r;
    int col, max;
    int m, n;
    int curParent;                  // ��¼���ʽ��ĸ����
    
    if(T == NULL || T->firstchild == NULL) {
        return 0;
    }
    
    curParent = -2;
    max = 0;
    
    m = n = 0;
    
    queue[n] = T;
    parent[n] = -1;
    order[n] = 0;
    n++;
    
    while(m < n) {
        p = queue[m];
        
        // �����µĸ����
        if(parent[m] != curParent) {
            curParent = parent[m];
            col = 1;                // ������
        } else {
            col++;
        }
        
        if(col > max) {
            max = col;
        }
        
        // �洢�ӽ��
        for(r = p->firstchild; r != NULL; r = r->nextsibling) {
            queue[n] = r;
            parent[n] = order[m];   // Ϊ�ӽ��洢�������
            order[n] = n;           // ��¼��ǰ���ı��
            n++;
        }
        
        m++;
    }
    
    return max;
}

/*
 * ���������
 */
int Algo_6_62(CSTree T) {
    return TreeDepth(T);    // �Ѷ���
}
