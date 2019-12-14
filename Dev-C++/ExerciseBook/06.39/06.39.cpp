#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//

/* ������Ԫ�����ͣ���������Ϊ�ַ� */
typedef char TElemType;

/* �������Ľ�㶨�� */
typedef struct BiTNode {
    TElemType data;             // ���Ԫ��
    struct BiTNode* lchild;     // ����ָ��
    struct BiTNode* rchild;     // �Һ���ָ��
    struct BiTNode* parent;
    int mark;
} BiTNode;

/* ָ�����������ָ�� */
typedef BiTNode* BiTree;

/*
 * ��������ĵ�����ʽ
 */
void Algo_6_39(BiTree T);

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
    Algo_6_39(T);
    
    return 0;
}


/*
 * ��������ĵ�����ʽ
 */
void Algo_6_39(BiTree T) {
    BiTree p = T;
    
    while(p != NULL) {
        // mark==0����δ���ʣ������������
        if(p->mark == 0) {
            p->mark = 1;
            if(p->lchild != NULL) {
                p = p->lchild;
            }
            
            // mark==1������ѷ��ʣ��������ҷ���
        } else if(p->mark == 1) {
            p->mark = 2;
            if(p->rchild != NULL) {
                p = p->rchild;
            }
            
            // mark==2�����Ҷ��������ˣ����ӡ�����
        } else {
            printf("%c ", p->data);
            p->mark = 0;            // �������
            p = p->parent;
        }
    }
    
    printf("\n");
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
        (*T)->mark = 0;
        CreateTree(&(*T)->lchild, *T, fp);
        CreateTree(&(*T)->rchild, *T, fp);
    }
}

// ��ͼ�λ���ʽ�����ǰ������
void PrintGraph(BiTree T) {
    BiTree p = T;
    int i = 1;
    
    while(p != NULL) {
        // mark==0����δ���ʣ������������
        if(p->mark == 0) {
            printf("%c ", p->data);
            i++;
            p->mark = 1;
            if(p->lchild != NULL) {
                p = p->lchild;
            } else {
                printf("^\n");
                i--;
            }
            
            // mark==1������ѷ��ʣ��������ҷ���
        } else if(p->mark == 1) {
            p->mark = 2;
            i++;
            
            if(p->rchild != NULL) {
                printf("%*c", 2 * (i - 1), ' ');
                p = p->rchild;
            } else {
                printf("%*c^\n", 2 * (i - 1), ' ');
                i--;
            }
            
            // mark==2�����Ҷ��������ˣ����ӡ�����
        } else {
            p->mark = 0;            // �������
            p = p->parent;
            i--;
        }
    }
    
    printf("\n");
}
