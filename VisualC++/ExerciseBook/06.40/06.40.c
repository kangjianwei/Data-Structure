#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* ������Ԫ�����ͣ���������Ϊ�ַ� */
typedef char TElemType;

/* �������Ľ�㶨�� */
typedef struct BiTNode {
    TElemType data;         // ���Ԫ��
    struct BiTNode* lchild; // ����ָ��
    struct BiTNode* rchild; // �Һ���ָ��
    struct BiTNode* parent;
} BiTNode;

/* ָ�����������ָ�� */
typedef BiTNode* BiTree;

/*
 * ��������ĵ�����ʽ
 *
 *��ע��
 * �����Ĺؼ��Ƿֱ浱ǰ���ڼ��α����ʡ�
 */
void Algo_6_40(BiTree T);

// ���������(��������)
Status CreateBiTree(BiTree* T, char* path);

// ������������ڲ�ʵ�֣�p����׷�����������
void CreateTree(BiTree* T, BiTree p, FILE* fp);

// ��ͼ�λ���ʽ�����ǰ������
void PrintGraph(BiTree T);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("���������� T ...\n");
    CreateBiTree(&T, NULL);
    PrintGraph(T);
    
    printf("�����������������Ϊ��");
    Algo_6_40(T);
    
    return 0;
}


/*
 * ��������ĵ�����ʽ
 *
 *��ע��
 * �����Ĺؼ��Ƿֱ浱ǰ���ڼ��α����ʡ�
 */
void Algo_6_40(BiTree T) {
    BiTree p = T;
    
    while(p != NULL) {
        // ��һ�η��ʽ�㣬�������
        if(p->lchild != NULL) {
            p = p->lchild;
        } else {
            // �����������صĽ��ڶ��α�����,Ҫ���
            printf("%c ", p->data);
            
            // ����ǰ��������ҷ�֧�����ص�������Ҫ���������
            while(p->rchild == NULL) {
                // �����������صĽ������α����ʣ������
                while(p->parent != NULL && p->parent->rchild == p) {
                    p = p->parent;
                }
                
                if(p->parent != NULL) {
                    // ����ǰ����������֧�����ص�������Ҫ���ʸ����
                    if(p->parent->lchild == p) {
                        p = p->parent;
                        printf("%c ", p->data); // ͬ��������������
                    }
                } else {
                    printf("\n");
                    
                    // �����������ص������ʱ���������
                    return;
                }
            }
            
            p = p->rchild;
        }
    }
}

// ���������(��������)
Status CreateBiTree(BiTree* T, char* path) {
    FILE* fp;
    
    fp = fopen("TestData.txt", "r");
    CreateTree(T, NULL, fp);
    fclose(fp);
    
    return OK;
}

// ������������ڲ�ʵ�֣�p����׷�����������
void CreateTree(BiTree* T, BiTree p, FILE* fp) {
    char ch;
    
    ReadData(fp, "%c", &ch);
    
    if(ch == '^') {
        *T = NULL;
    } else {
        *T = (BiTree) malloc(sizeof(BiTNode));
        if(!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        (*T)->parent = p;
        CreateTree(&(*T)->lchild, *T, fp);
        CreateTree(&(*T)->rchild, *T, fp);
    }
}

// ��ͼ�λ���ʽ�����ǰ������
void PrintGraph(BiTree T) {
    BiTree p = T;
    int i = 1;
    
    while(p != NULL) {
        // �����������صĽ��ڶ��α�����,Ҫ���
        printf("%c ", p->data);
        i++;
        
        // ��һ�η��ʽ�㣬�������
        if(p->lchild != NULL) {
            p = p->lchild;
        } else {
            printf("^\n");
            
            // ����ǰ��������ҷ�֧�����ص�������Ҫ���������
            while(p->rchild == NULL) {
                printf("%*c^\n", 2 * (i - 1), ' ');
                i--;
                
                // �����������صĽ������α����ʣ������
                while(p->parent != NULL && p->parent->rchild == p) {
                    p = p->parent;
                    i--;
                }
                
                if(p->parent != NULL) {
                    // ����ǰ����������֧�����ص�������Ҫ���ʸ����
                    if(p->parent->lchild == p) {
                        p = p->parent;
                    }
                } else {
                    printf("\n");
                    
                    // �����������ص������ʱ���������
                    return;
                }
            }
            
            printf("%*c", 2 * (i - 1), ' ');
            p = p->rchild;
        }
    }
}
