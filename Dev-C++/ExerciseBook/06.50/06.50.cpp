#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "BiTree.h"     //**��06 ���Ͷ�����**//

#define MAX_TREE_SIZE  1024  // ������Ԫ���������ֵ

/*
 * ��ȡԤ����ʽ�Ľ����Ϣ�������򴴽���������
 */
Status Algo_6_50(BiTree* T, FILE* fp);


int main(int argc, char* argv[]) {
    BiTree T;
    FILE* fp;
    
    printf("�������������������У�...\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_50(&T, fp);
    fclose(fp);
    printf("\n");
    
    printf("������TΪ��\n");
    PrintGraph(T);
    
    return 0;
}


/*
 * ��ȡԤ����ʽ�Ľ����Ϣ�������򴴽���������
 */
Status Algo_6_50(BiTree* T, FILE* fp) {
    char s[4];
    BiTree tmp[MAX_TREE_SIZE];    // ������洢������ÿ������ָ��
    int m, n;
    BiTree p;
    
    m = n = 0;
    
    *T= NULL;
    
    while(TRUE) {
        ReadData(fp, "%s", s);
        printf("%s\n", s);
        
        // �˳���־
        if(s[1] == '^') {
            return OK;
        }
    
        p = (BiTree) malloc(sizeof(BiTNode));
        if(p==NULL) {
            exit(OVERFLOW);
        }
        p->data = s[1];
        p->lchild = p->rchild = NULL;
    
        // �����
        if(s[0] == '^') {
            *T = p;
            tmp[n++] = p;
        } else {
            // Ѱ���������
            while(m<n && tmp[m]->data != s[0]) {
                m++;
            }
    
            if(m>=n) {
                return ERROR;
            }
            
            if(s[2] == 'L') {
                tmp[m]->lchild = p;
            } else {
                tmp[m]->rchild = p;
            }
        }
    
        tmp[n++] = p;
    }
}
