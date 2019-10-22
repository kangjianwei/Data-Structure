#include "Maze.h"                        //**▲03 栈和队列**//

int main(int argc, char* argv[]) {
    MazeType maze;
    PosType start, end;
    char n, Re = 'Y';
    
    while(Re == 'Y' || Re == 'y') {
        InitMaze(maze, &start, &end);    // 初始化迷宫，包括出入口

        MazePath(maze, start, end);      // 迷宫寻路

        printf("重置？（Y/N）：");
        scanf("%c%c", &Re, &n);
    
        printf("\n");
    }
    
    return 0;
}

