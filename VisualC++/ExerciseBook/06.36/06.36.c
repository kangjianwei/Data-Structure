#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "BiTree.h"     //**��06 ���Ͷ�����**//

/*
 * �ж����ö������Ƿ�����
 */
Status Algo_6_36(BiTree B1, BiTree B2);


int main(int argc, char* argv[]) {
    BiTree B1, B2, B3;
    
    printf("���������� B1 ��...\n");
    CreateBiTree(&B1, "TestData_B1.txt");
    PrintGraph(B1);
    printf("\n");
    
    printf("���������� B2 ��...\n");
    CreateBiTree(&B2, "TestData_B2.txt");
    PrintGraph(B2);
    printf("\n");
    
    printf("���������� B3 ��...\n");
    CreateBiTree(&B3, "TestData_B3.txt");
    PrintGraph(B3);
    printf("\n");
    
    if(Algo_6_36(B1, B2) == TRUE) {
        printf("B1��B2���ƣ�\n");
    } else {
        printf("B1��B2�����ƣ���\n");
    }
    
    if(Algo_6_36(B2, B3) == TRUE) {
        printf("B2��B3���ƣ�\n");
    } else {
        printf("B2��B3�����ƣ���\n");
    }
    
    return 0;
}


/*
 * �ж����ö������Ƿ�����
 */
Status Algo_6_36(BiTree B1, BiTree B2) {
    // ��Ϊ����
    if(BiTreeEmpty(B1) && BiTreeEmpty(B2)) {
        return TRUE;
    } else {
        // ����Ϊ����
        if(!BiTreeEmpty(B1) && !BiTreeEmpty(B2)) {
            // �ж���������
            if(Algo_6_36(B1->lchild, B2->lchild) && Algo_6_36(B1->rchild, B2->rchild)) {
                return TRUE;
            }
        }
    }
    
    return FALSE;
}
