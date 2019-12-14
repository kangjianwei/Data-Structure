#include <stdio.h>
#include <math.h>       // �ṩpow��logԭ��
#include "BiTree.h"     //**��06 ���Ͷ�����**//

#define MAX_TREE_SIZE  1024  // ������Ԫ���������ֵ

/*
 * ����������ķ�ï�ȣ����x�߶�
 * ע�����Ϊ�������������ֵ
 */
int Algo_6_52(BiTree T);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("�������������������У�T...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("���ķ�ï��Ϊ�� %d", Algo_6_52(T));
    printf("\n");
    
    return 0;
}


/*
 * ����������ķ�ï�ȣ����x�߶�
 * ע�����Ϊ�������������ֵ
 */
int Algo_6_52(BiTree T) {
    int lux;         // ��ï��
    int col, width;  // �����Ⱥ������
    int row, high;   // ��ǰ������ڲ��������߶�
    BiTree queue[MAX_TREE_SIZE];    // ��ָ�����飬ģ�����
    int level[MAX_TREE_SIZE];       // ��¼��ǰ����ڵڼ���
    BiTree p;
    int m, n;
    
    if(T==NULL) {
        return 0;
    }
    
    width = high = 0;
    m = n = 0;
    col = 1;
    
    queue[n] = T;
    level[n] = 1;
    n++;
    
    while(m<n){
        p = queue[m];
        row = level[m];     // ��ǰ������ڵĲ�
        m++;
        
        // �����µ�һ��
        if(row>high) {
            high = row;
            col = 1;    // ����ʱҪ��������
        } else {
            col++;
        }
    
        if(col>width) {
            width = col;
        }
        
        if(p->lchild!=NULL) {
            queue[n] = p->lchild;
            level[n] = row+1;
            n++;
        }
    
        if(p->rchild!=NULL) {
            queue[n] = p->rchild;
            level[n] = row+1;
            n++;
        }
        
        
    }
    
    lux = width * high;
    
    return lux;
}
