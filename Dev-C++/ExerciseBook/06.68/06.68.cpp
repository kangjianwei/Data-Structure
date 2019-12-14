#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "CSTree.h"     //**��06 ���Ͷ�����**//

#define MAX_TREE_SIZE  1024  // ����Ԫ���������ֵ

/*
 * �������ĺ���-�ֵܽṹ
 */
Status Algo_6_68(CSTree* T, FILE* fp);


int main(int argc, char* argv[]) {
    CSTree T;
    FILE* fp;
    
    printf("��������-�ֵܶ�������\n");
    fp = fopen("TestData.txt", "r");
    Algo_6_68(&T, fp);
    fclose(fp);
    printf("\n");
    
    PrintGraph(T);
    printf("\n");
    
    return 0;
}


/*
 * �������ĺ���-�ֵܽṹ
 */
Status Algo_6_68(CSTree* T, FILE* fp) {
    CSTree queue[MAX_TREE_SIZE] = {NULL};   // ������洢�����Ľ��
    int d[MAX_TREE_SIZE];       // �洢�ý��Ķ�
    int parent[MAX_TREE_SIZE];  // �洢�ý��ĸ������Ϣ
    CSTree p;
    int x;
    char ch;
    int m, n;
    int i;
    
    d[0] = 1;
    
    for(m = 0, n = 1; m < n; m++) {
        p = NULL;
        i = 0;
        
        while(i < d[m]) {
            // �������б��
            ch = getc(fp);
            if(ch == '\n' || ch == '\r') {
                continue;
            } else {
                ungetc(ch, fp);
            }
            
            // ��ȡ�����Ϣ
            ReadData(fp, "%c%d", &ch, &x);
            printf("%c %d\n", ch, x);
            if(x < 0) {
                return ERROR;
            }
            
            d[n] = x;
            parent[n] = m;
            
            // �����½��
            queue[n] = (CSTree) malloc(sizeof(CSNode));
            if(queue[n] == NULL) {
                exit(OVERFLOW);
            }
            queue[n]->data = ch;
            queue[n]->firstchild = queue[n]->nextsibling = NULL;
            
            // ׷�ٸò��׸����
            if(p == NULL) {
                p = queue[n];
            } else {
                // �����ӽ�㴮����һ��
                queue[n - 1]->nextsibling = queue[n];
            }
            
            n++;
            i++;
        }
        
        if(m > 0 && queue[m]->firstchild == NULL) {
            queue[m]->firstchild = p;
        }
    }
    
    *T = queue[1];
    
    return OK;
}
