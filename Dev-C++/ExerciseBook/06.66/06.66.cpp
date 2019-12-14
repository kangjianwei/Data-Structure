#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "PTree.h"      //**��06 ���Ͷ�����**//
#include "CSTree.h"     //**��06 ���Ͷ�����**//

/*
 * ����˫�ױ�ʾ��תΪ���ĺ���-�ֵܱ�ʾ��
 */
CSTree Algo_6_66(PTree T);


int main(int argc, char* argv[]) {
    PTree PT;
    CSTree CST;
    
    printf("������T...\n");
    InitTree_P(&PT);
    CreateTree_P(&PT, "TestData.txt");
    PrintGraph_P(PT);
    printf("\n");
    
    printf("����˫�ױ�ʾ��תΪ���ĺ���-�ֵܱ�ʾ����\n");
    CST = Algo_6_66(PT);
    PrintGraph_CS(CST);
    printf("\n");
    
    return 0;
}


/*
 * ����˫�ױ�ʾ��תΪ���ĺ���-�ֵܱ�ʾ��
 */
CSTree Algo_6_66(PTree T) {
    CSTree p, q;
    CSTree tree[MAX_TREE_SIZE] = {NULL};
    int i, j, k;
    
    // ˫�ױ�����洢
    for(i = T.r, j = T.r; i != (T.r + T.n) % MAX_TREE_SIZE; i = (i + 1) % MAX_TREE_SIZE) {
        // ��ȡ�ý��ĸ����
        k = T.nodes[i].parent;
        
        // ���ƽ����Ϣ
        p = (CSTree) malloc(sizeof(CSNode));
        if(p == NULL) {
            exit(OVERFLOW);
        }
        p->data = T.nodes[i].data;
        p->firstchild = p->nextsibling = NULL;
        
        // ��ǰ�����ڸ����
        if(k != -1) {
            // ��ǰ�����Ϊ�˵�һ������
            if(tree[k]->firstchild == NULL) {
                tree[k]->firstchild = p;
                
                // ��ǰ��㲻�ǵ�һ�����ӣ������Ȳ����丸���ĺ��������β��
            } else {
                for(q = tree[k]->firstchild; q->nextsibling != NULL; q = q->nextsibling) {
                    // Ѱ�Һ��������ĩ��
                }
                
                q->nextsibling = p;
            }
        }
        
        tree[j] = p;
        j = (j + 1) % MAX_TREE_SIZE;
    }
    
    return tree[T.r];
}
