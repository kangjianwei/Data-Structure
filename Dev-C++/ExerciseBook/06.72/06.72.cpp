#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "CTree.h"      //**��06 ���Ͷ�����**//

/*
 * ���������������ӡ��
 * ����1��ֱ��ʹ�õݹ飬i��ʼ��Ϊ0
 */
void Algo_6_72_1(CTree T, int order, int i);

/*
 * ���������������ӡ��
 * ����2����ѭ����ʹ�õݹ飬i��ʼ��Ϊ0
 */
void Algo_6_72_2(CTree T, int order, int i);


int main(int argc, char* argv[]) {
    CTree T;
    
    printf("������T...\n");
    InitTree(&T);
    CreateTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("���������������ӡ����\n");
    Algo_6_72_1(T, T.r, 0);
    printf("\n");
    
    printf("���������������ӡ����\n");
    Algo_6_72_2(T, T.r, 0);
    printf("\n");
    
    return 0;
}


/*
 * ���������������ӡ��
 * ����1��ֱ��ʹ�õݹ飬i��ʼ��Ϊ0
 */
void Algo_6_72_1(CTree T, int order, int i) {
    int j, k;
    
    if(!T.n) {
        return;
    }
    
    for(j = 1; j <= 2 * i; j++) {
        printf(" ");
    }
    printf("%c\n", T.nodes[order].data);
    
    // ���ʺ��ӽ��
    if(T.nodes[order].firstchild) {
        Algo_6_72_1(T, T.nodes[order].firstchild->child, i + 1);
    }
    
    // ��ȡ���order���ҽ���λ��
    k = (order + 1) % MAX_TREE_SIZE;
    
    // ����������ֵ�
    if(T.nodes[order].parent == T.nodes[k].parent) {
        // �������ֵܽ��
        Algo_6_72_1(T, k, i);
    }
}

/*
 * ���������������ӡ��
 * ����2����ѭ����ʹ�õݹ飬i��ʼ��Ϊ0
 */
void Algo_6_72_2(CTree T, int order, int i) {
    int j;
    ChildPtr p;
    
    if(!T.n) {
        return;
    }
    
    for(j = 1; j <= 2 * i; j++) {
        printf(" ");
    }
    printf("%c\n", T.nodes[order].data);
    
    // �������ӽ��
    for(p = T.nodes[order].firstchild; p; p = p->next) {
        Algo_6_72_2(T, p->child, i + 1);
    }
}
