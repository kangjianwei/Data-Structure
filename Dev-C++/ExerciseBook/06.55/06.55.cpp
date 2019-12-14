#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include "Status.h"     //**��01 ����**//
#include "BiTree.h"     //**��06 ���Ͷ�����**//

/*
 * �����������ÿ������������Ŀ
 */
int Algo_6_55(BiTree T);

// ����������������������������Ŀ
void PreOrderPrint(BiTree T);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("�������������������У�T...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("����������������ֵ������Ӧ��������Ŀ��\n");
    Algo_6_55(T);
    PreOrderPrint(T);
    
    return 0;
}


/*
 * �����������ÿ������������Ŀ
 */
int Algo_6_55(BiTree T) {
    int l, r;
    
    if(T == NULL) {
        return 0;
    } else {
        T->DescNum = 0;
        
        if(T->lchild != NULL) {
            l = Algo_6_55(T->lchild);
            T->DescNum += l + 1;
        }
        
        if(T->rchild != NULL) {
            r = Algo_6_55(T->rchild);
            T->DescNum += r + 1;
        }
    }
    
    return T->DescNum;
}

// ����������������������������Ŀ
void PreOrderPrint(BiTree T) {
    if(T != NULL) {
        printf("��� %c ��������Ŀ %d\n", T->data, T->DescNum);
        PreOrderPrint(T->lchild);
        PreOrderPrint(T->rchild);
    }
}
