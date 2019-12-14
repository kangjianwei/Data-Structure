#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "PTree.h"      //**��06 ���Ͷ�����**//

/*
 * ����˫�ױ��ʾ���������
 */
int Algo_6_64(PTree T);


int main(int argc, char* argv[]) {
    PTree T;
    
    printf("������T...\n");
    InitTree(&T);
    CreateTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("���������Ϊ�� %d\n", Algo_6_64(T));
    printf("\n");
    
    return 0;
}


/*
 * ����˫�ױ��ʾ���������
 */
int Algo_6_64(PTree T) {
    return TreeDepth(T);    // �Ѷ���
}
