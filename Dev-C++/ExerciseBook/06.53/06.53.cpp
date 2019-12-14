#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "BiTree.h"     //**��06 ���Ͷ�����**//

#define MAX_TREE_DEPTH 20    // ������������

/*
 * Ѱ�Ҹ���㵽Ҷ�ӽ���·��������һ��
 */
int Algo_6_53(BiTree T, BiTree path[]);


int main(int argc, char* argv[]) {
    BiTree T;
    BiTree way[MAX_TREE_DEPTH] = {NULL};
    int i, n;
    
    printf("�������������������У�T...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("�������㵽Ҷ�ӽ���·��������һ����");
    n = Algo_6_53(T, way);
    for(i = 0; i < n; i++) {
        printf("%c ", way[i]->data);
    }
    printf("\n");
    
    return 0;
}


/*
 * Ѱ�Ҹ���㵽Ҷ�ӽ���·��������һ��
 */
int Algo_6_53(BiTree T, BiTree path[]) {
    int i = -1;
    int mark[MAX_TREE_DEPTH] = {0}; // ���ʱ��ջ
    BiTree p;
    int depth;
    
    // ���ж��������
    depth = BiTreeDepth(T);
    
    p = T;
    
    while(TRUE) {
        // �ȳ���������������
        while(p != NULL) {
            i++;
            
            // ���µ�ǰ����ָ��
            path[i] = p;
            
            // �ѷ��ʹ��ý���������
            mark[i] = 1;
            p = p->lchild;
        }
        
        // ��������ͷ���ж���·�������Ƿ��������
        if(i + 1 == depth) {
            return depth;
        }
        
        // �ص������
        p = path[i];
        
        // ��������������ڣ����߸��������ѱ����ʹ�����ص����ĸ����
        while(p->rchild == NULL || mark[i] == 2) {
            path[i] = NULL;     // �ÿո�λ��
            
            i--;
            if(i == -1) {
                return 0;
            }
            
            // ���˵������
            p = path[i];
        }
        
        // �ѷ��ʹ��ý���������
        mark[i] = 2;
        p = p->rchild;
    }
}
