#include "Hanoi.h"                        //**03 ջ�Ͷ���**//

int main(int argc, char** argv) {
    char x = 'x';
    char y = 'y';
    char z = 'z';
    
    printf("��Ϊʾ��������Բ�̸���Ϊ %d ��������������...\n", N);
    
    init(N);
    
    hanoi(N, x, y, z);
    
    return 0;
}
