#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "BiThrTree.h"  //**��06 ���Ͷ�����**//

// ���Ժ�������ӡԪ��
Status PrintElem(TElemType c) {
    printf("%c", c);
    return OK;
}


int main(int argc, char* argv[]) {
    BiThrTree T;    // ������
    BiThrTree Thr;  // ����ȫ����������
    
    printf("���������������� ����ȫ������������ \n");
    {
        printf("�� ���������д���������...\n");
        CreateBiTree(&T, "TestData_Pre.txt");

        printf("�� �Զ�������������ȫ������...\n");
        InOrderThreading(&Thr, T);

        printf("�� �����������ȫ����������...\n");
        InOrderTraverse_Thr(Thr, PrintElem);
    }
    PressEnterToContinue();
}
