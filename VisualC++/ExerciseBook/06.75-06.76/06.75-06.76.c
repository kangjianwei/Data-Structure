#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "CTree.h"      //**��06 ���Ͷ�����**//

/*
 * ������������(�ѿ���˫�׽��)
 */
void Algo_6_75(CTree* T, FILE* fp);

// ���������ڲ�ʵ�֣�parent��ǵ�ǰλ�ý���˫�׽��λ��
void Create(CTree* T, int parent, FILE* fp);

/*
 * �������ʽ��ӡ��������
 */
void Algo_6_76(CTree T, int i);


int main(int argc, char* argv[]) {
    FILE* fp;
    CTree T;
    
    printf("�� 6.75 ��֤...\n");
    printf("��������������ʽ������\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_75(&T, fp);
    fclose(fp);
    PrintGraph(T);
    printf("\n");
    
    printf("�� 6.76 ��֤...\n");
    printf("�������ʽ��ӡ��������...\n");
    Algo_6_76(T, T.r);
    printf("\n");
    
    return 0;
}


/*
 * ������������(�ѿ���˫�׽��)
 */
void Algo_6_75(CTree* T, FILE* fp) {
    CTree CT;
    ChildPtr r;
    int mark[MAX_TREE_SIZE];
    int i, j, p;
    
    CT.r = 0;   // �������Ĭ�����õ�0�ŵ�Ԫ��
    CT.n = 0;   // ��0�ŵ�Ԫ��ʼ�洢
    Create(&CT, -1, fp);    // �˴����������������������������
    
    T->n = CT.n;
    T->r = 0;
    j = T->r;
    
    // �������˳��Ϊ����
    for(p = -1; p < CT.n; p++) {
        // ѡ�������Ϊp��Ԫ��
        for(i = 0; i < CT.n; i++) {
            if(CT.nodes[i].parent == p) {
                T->nodes[j] = CT.nodes[i];
                mark[i] = j;    // �±�Ϊi��Ԫ���ƶ�������������±�j��
                j++;
            }
        }
    }
    
    // �±����
    for(i = 0; i < T->n; i++) {
        p = T->nodes[i].parent;
        if(p != -1) {
            // �޸�parent����±�
            T->nodes[i].parent = mark[p];
        }
    
        // �޸ĺ��������е�Ԫ���±�
        for(r = T->nodes[i].firstchild; r != NULL; r = r->next) {
            r->child = mark[r->child];
        }
    }
}

// ���������ڲ�ʵ�֣�parent��ǵ�ǰλ�ý���˫�׽��λ��
void Create(CTree* T, int parent, FILE* fp) {
    char c;
    ChildPtr p, q;
    
    while(TRUE) {
        if(feof(fp) != 0) {
            break;
        }
        
        ReadData(fp, "%c", &c);
        
        if(c >= 'A' && c <= 'Z') {
            T->nodes[T->n].data = c;            // T.n����׷�ٽ�����
            T->nodes[T->n].parent = parent;
            T->nodes[T->n].firstchild = NULL;
            
            // �Ǹ����
            if(parent != -1) {
                // �������ӽ��
                p = (ChildPtr) malloc(sizeof(CTNode));
                p->child = T->n;
                p->next = NULL;
                
                // ��ȡ��ǰ���ӽ��ĸ����ĺ�������
                q = T->nodes[parent].firstchild;
                
                // �����ĺ�������Ϊ��
                if(q == NULL) {
                    T->nodes[parent].firstchild = p;
                } else {
                    // ���Ҹ���㺢�������β��
                    while(q->next != NULL) {
                        q = q->next;
                    }
                    
                    // �򸸽��ĺ����������ú��ӽ��
                    q->next = p;
                }
            }
            
            T->n++;
        } else if(c == '(') {
            Create(T, T->n - 1, fp);  // T.n-1���ĵ�һ������
            
        } else if(c == ',') {
            Create(T, parent, fp);    // �����ֵܽ��
            break;
        } else {
            break;
        }
    }
}

/*
 * �������ʽ��ӡ��������
 */
void Algo_6_76(CTree T, int i) {
    ChildPtr p;
    
    if(!T.n) {
        return;
    }
    
    // ��ӡ˫�׽��
    printf("%c", T.nodes[i].data);
    
    if(T.nodes[i].firstchild) {
        printf("(");
        
        // �������ӽ��
        for(p = T.nodes[i].firstchild; p; p = p->next) {
            Algo_6_76(T, p->child);
            
            // ������һ������
            if(p->next != NULL) {
                printf(",");
            }
        }
        
        printf(")");
    }
}
