#include <stdio.h>
#include "NQueens.h"    //**▲06 树和二叉树**//

int main(int argc, char* argv[]) {
    
    printf("████████ InitChessBoard \n");
    {
        printf("初始化一个 %2d * %-2d 的空棋盘...\n", N, N);
        InitChessBoard();
    }
    PressEnterToContinue(debug);
    
    printf("████████ ShowChessBoard \n");
    {
        printf("展示当前棋盘中的皇后布局...\n");
        ShowChessBoard();
    }
    PressEnterToContinue(debug);
    
    printf("████████ Trial \n");
    {
        printf("计算 %d 皇后问题的各解...\n", N);
        Trial(1, N);
    }
    PressEnterToContinue(debug);
    
    return OK;
}
