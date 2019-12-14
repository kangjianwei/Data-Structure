#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "CSTree.h"     //**��06 ���Ͷ�����**//

/*
 * ���������������ӡ��
 * ����1��ֱ��ʹ�õݹ飬i��ʼ��Ϊ0
 */
void Algo_6_71_1(CSTree T, int i);

/*
 * ���������������ӡ��
 * ����2����ѭ����ʹ�õݹ飬i��ʼ��Ϊ0
 */
void Algo_6_71_2(CSTree T, int i);


int main(int argc, char* argv[]) {
    CSTree T;
    
    printf("���������������У�T...\n");
    InitTree(&T);
    CreateTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("���� 1�����������������ӡ����\n");
    Algo_6_71_1(T, 0);
    printf("\n");
    
    printf("���� 2�����������������ӡ����\n");
    Algo_6_71_2(T, 0);
    printf("\n");
    
    return 0;
}


/*
 * ���������������ӡ��
 * ����1��ֱ��ʹ�õݹ飬i��ʼ��Ϊ0
 */
void Algo_6_71_1(CSTree T, int i) {
    int j;
    
    if(!T) {
        return;
    }
    
    for(j = 1; j <= 2 * i; j++) {
        printf(" ");
    }
    printf("%c\n", T->data);
    
    Algo_6_71_1(T->firstchild, i + 1);
    Algo_6_71_1(T->nextsibling, i);     // �˴�Ϊi
}

/*
 * ���������������ӡ��
 * ����2����ѭ����ʹ�õݹ飬i��ʼ��Ϊ0
 */
void Algo_6_71_2(CSTree T, int i) {
    int j;
    CSTree p;
    
    if(!T) {
        return;
    }
    
    for(j = 1; j <= 2 * i; j++) {
        printf(" ");
    }
    printf("%c\n", T->data);
    
    // �������ӽ��
    for(p = T->firstchild; p; p = p->nextsibling) {
        Algo_6_71_2(p, i + 1);
    }
}
