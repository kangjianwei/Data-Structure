#include "Maze.h"                        //**��03 ջ�Ͷ���**//

int main(int argc, char* argv[]) {
    MazeType maze;
    PosType start, end;
    char n, Re = 'Y';
    
    while(Re == 'Y' || Re == 'y') {
        InitMaze(maze, &start, &end);    // ��ʼ���Թ������������

        MazePath(maze, start, end);      // �Թ�Ѱ·

        printf("���ã���Y/N����");
        scanf("%c%c", &Re, &n);

		printf("\n");
    }
    
    return 0;
}
