#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "CTree.h"      //**��06 ���Ͷ�����**//

/*
 * ���㺢�������ʾ���������
 */
int Algo_6_63(CTree T);


int main(int argc, char* argv[]) {
    CTree T;
    
    printf("������T...\n");
    InitTree(&T);
    CreateTree(&T, "TestData.txt");
    PrintGraph(T);
    printf("\n");
    
    printf("���������Ϊ�� %d\n", Algo_6_63(T));
    printf("\n");
    
    return 0;
}


/*
 * ���㺢�������ʾ���������
 */
int Algo_6_63(CTree T) {
    return TreeDepth(T);    // �Ѷ���
}
