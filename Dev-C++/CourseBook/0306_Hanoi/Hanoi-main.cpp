#include "Hanoi.h"                        //**03 栈和队列**//

int main(int argc, char** argv) {
    char x = 'x';
    char y = 'y';
    char z = 'z';
    
    printf("作为示例，假设圆盘个数为 %d ，操作步骤如下...\n", N);
    
    init(N);
    
    hanoi(N, x, y, z);
    
    return 0;
}
