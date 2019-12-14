#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "CSTree.h"     //**��06 ���Ͷ�����**//

/*
 * ��������-�ֵ�����
 */
Status Algo_6_73(CSTree* T, FILE* fp);

/*
 * �������ʽ��ӡ����-�ֵ�����
 */
void Algo_6_74(CSTree T);


int main(int argc, char* argv[]) {
    CSTree T;
    FILE* fp;
    
    printf("������ �� 6.73 ��֤... ������\n");
    printf("��������-�ֵܶ�������\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_73(&T, fp);
    fclose(fp);
    PrintGraph(T);
    printf("\n");
    
    printf("������ �� 6.74 ��֤... ������\n");
    printf("��������ӡ����-�ֵ�����...\n");
    Algo_6_74(T);
    printf("\n");
    
    return 0;
}


/*
 * ��������-�ֵ�����
 */
Status Algo_6_73(CSTree* T, FILE* fp) {
    char c;
    
    while(TRUE) {
        if(feof(fp) != 0) {
            break;
        }
        
        ReadData(fp, "%c", &c);
        
        if(c >= 'A' && c <= 'Z') {
            *T = (CSTree) malloc(sizeof(CSNode));    //�����
            if(*T == NULL) {
                exit(OVERFLOW);
            }
            (*T)->data = c;
            (*T)->firstchild = (*T)->nextsibling = NULL;
        } else if(c == '(') {
            Algo_6_73(&(*T)->firstchild, fp);
        } else if(c == ',') {
            Algo_6_73(&(*T)->nextsibling, fp);
            break;  // ע��˴�Ӧ�÷���
        } else {
            break;
        }
    }
    
    return OK;
}

/*
 * �������ʽ��ӡ����-�ֵ�����
 */
void Algo_6_74(CSTree T) {
    CSTree p;
    
    if(!T) {
        return;
    }
    
    printf("%c", T->data);
    
    if(T->firstchild) {
        printf("(");
        
        for(p = T->firstchild; p; p = p->nextsibling) {
            Algo_6_74(p);
            
            // ���������һ���ֵܣ���","
            if(p->nextsibling) {
                printf(",");
            }
        }
        
        printf(")");
    }
}
