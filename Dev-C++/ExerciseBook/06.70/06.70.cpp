#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "BiTree.h"     //**��06 ���Ͷ�����**//

/*
 * �����������Ķ�������ṹ
 */
Status Algo_6_70(BiTree* T, FILE* fp);


int main(int argc, char* argv[]) {
    BiTree T;
    FILE* fp;
    
    printf("����������T...\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_70(&T, fp);
    fclose(fp);
    PrintGraph(T);
    
    return 0;
}


/*
 * �����������Ķ�������ṹ
 */
Status Algo_6_70(BiTree* T, FILE* fp) {
    char c;
    
    while(TRUE) {
        // �ַ���ȡ���
        if(feof(fp)!=0) {
            return OK;
        }
        
        ReadData(fp, "%c", &c);
        
        if(c == '#') {
            *T = NULL;
        } else if(c >= 'A' && c <= 'Z') {
            *T = (BiTree) malloc(sizeof(BiTNode));    //�����
            if(*T==NULL) {
                exit(OVERFLOW);
            }
            (*T)->data = c;
            (*T)->lchild = (*T)->rchild = NULL;
        } else if(c == '(') {
            Algo_6_70(&(*T)->lchild, fp);
            Algo_6_70(&(*T)->rchild, fp);
        } else {
            break;
        }
    }
    
    return OK;
}
