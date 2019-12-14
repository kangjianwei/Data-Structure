#include <stdio.h>
#include "BiTree.h" //**��06 ���Ͷ�����**//

/*
 * ����������Ұ������ӡ��
 * i������Ը�������˼����������˲�����Ϣ
 */
void Algo_6_69(BiTree T, int i);


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("�������������������У�T...\n");
    InitBiTree(&T);
    CreateBiTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("�����������Ұ������ӡ����\n");
    Algo_6_69(T, 0);
    printf("\n");
    
    return 0;
}


/*
 * ����������Ұ������ӡ��
 * i������Ը�������˼����������˲�����Ϣ
 */
void Algo_6_69(BiTree T, int i) {
    int j;
    
    if(T) {
        Algo_6_69(T->rchild, i + 1);    // �ȷ���������
        
        for(j = 1; j <= 2 * i; j++) {   // i����2��Ϊ�����Ч�����ۣ�ʵ�ʿո�������
            printf(" ");
        }
        printf("%c\n", T->data);
        
        Algo_6_69(T->lchild, i + 1);    // ������������
    }
}
