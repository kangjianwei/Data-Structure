#include <stdio.h>
#include "NQueens.h"    //**��06 ���Ͷ�����**//

int main(int argc, char* argv[]) {
    
    printf("���������������� InitChessBoard \n");
    {
        printf("��ʼ��һ�� %2d * %-2d �Ŀ�����...\n", N, N);
        InitChessBoard();
    }
    PressEnterToContinue();
    
    printf("���������������� ShowChessBoard \n");
    {
        printf("չʾ��ǰ�����еĻʺ󲼾�...\n");
        ShowChessBoard();
    }
    PressEnterToContinue();
    
    printf("���������������� Trial \n");
    {
        printf("���� %d �ʺ�����ĸ���...\n", N);
        Trial(1, N);
    }
    PressEnterToContinue();
    
    return OK;
}
