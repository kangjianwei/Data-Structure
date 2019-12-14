#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "BiTree.h"     //**��06 ���Ͷ�����**//

#define MAX_TREE_SIZE  1024  // ������Ԫ���������ֵ

/*
 * ���ݶ������Ĳ������д�����ʽ������
 */
Status Algo_6_54(BiTree* T, TElemType sa[100]);


int main(int argc, char* argv[]) {
    BiTree T;
    TElemType sa[MAX_TREE_SIZE] = "ABCDEF^G^HI^J";  // ��������
   
    printf("�������������������У�...\n");
    Algo_6_54(&T, sa);
    PrintGraph(T);
    
    return 0;
}


/*
 * ���ݶ������Ĳ������д�����ʽ������
 */
Status Algo_6_54(BiTree* T, TElemType sa[]) {
    BiTree tree[MAX_TREE_SIZE];   // ��ʱ��ű����и����ָ��ĸ���Ʒ
    int p, i;
    
    i = 0;
    
    while(sa[i] != '\0') {
        if(sa[i] == '^') {
            tree[i] = NULL;
        } else {
            tree[i] = (BiTree) malloc(sizeof(BiTNode));
            if(tree[i] == NULL) {
                exit(OVERFLOW);
            }
            tree[i]->data = sa[i];
            tree[i]->lchild = tree[i]->rchild = NULL;
        }
        
        if(i > 0) {
            p = (i - 1) / 2;   // ��������
            
            // ��ǰ���������
            if(2 * p + 1 == i) {
                tree[p]->lchild = tree[i];
            } else {
                tree[p]->rchild = tree[i];
            }
        }
        
        i++;
    }
    
    *T = tree[0];
    
    return OK;
}
