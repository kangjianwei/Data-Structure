#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "CSTree.h"     //**��06 ���Ͷ�����**//

#define MAX_TREE_SIZE  1024  // ����Ԫ���������ֵ

/*
 * �������ĺ���-�ֵܽṹ
 */
Status Algo_6_67(CSTree* T, FILE* fp);


int main(int argc, char* argv[]) {
    CSTree T;
    FILE* fp;
    
    printf("��������-�ֵܶ�������\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_67(&T, fp);
    fclose(fp);
    printf("\n");
    
    PrintGraph(T);
    printf("\n");
    
    return 0;
}


/*
 * �������ĺ���-�ֵܽṹ
 */
Status Algo_6_67(CSTree* T, FILE* fp) {
    char input[3];
    CSTree tree[MAX_TREE_SIZE];    // ˳��洢������ÿ�����
    CSTree p, q;
    int m, n, count;
    
    m = n = 0;
    count = 0;
    
    while(TRUE) {
        printf("¼��� %2d ����Ԫ�飺", ++count);
        ReadData(fp, "%s", input);
        printf("%s\n", input);
        
        // �˳���־
        if(input[1] == '^') {
            return OK;
        }
        
        p = (CSTree) malloc(sizeof(CSNode));
        if(p == NULL) {
            exit(OVERFLOW);
        }
        p->data = input[1]; // ��ǰ�����Ϣ
        p->firstchild = p->nextsibling = NULL;
        
        // �����
        if(input[0] == '^') {
            *T = p;
        } else {
            // ���Ҹ������tree�е�λ��
            while(tree[m]->data != input[0]) {
                m++;
            }
            
            // ��ǰ�����Ϊ��һ������
            if(tree[m]->firstchild == NULL) {
                tree[m]->firstchild = p;
            } else {
                for(q = tree[m]->firstchild; q->nextsibling != NULL; q = q->nextsibling) {
                    // Ѱ�Һ��������ĩ��
                }
                
                // ���뵱ǰ���
                q->nextsibling = p;
            }
        }
        
        tree[n++] = p;
    }
}
