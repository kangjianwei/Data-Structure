/*==============
 * �Թ�Ѱ·����
 *
 * �����㷨: 3.3
 ===============*/

#include "Maze.h"                            //**��03 ջ�Ͷ���**//

/*
 * ���������������� �㷨3.3 ����������������
 *
 * �Թ�Ѱ·
 *
 * ʹ����ٷ����ҵ�һ������ͨ·������
 */
Status MazePath(MazeType maze, PosType start, PosType end) {
    SqStack S;              // �洢̽������ͨ����
    SElemType e;            // e�洢��ǰͨ������Ϣ
    PosType curPos;         // ��ǰλ��
    int curStep;            // ��ǰͨ�������
    
    // ��ʼ���켣ջ
    InitStack(&S);
    
    curPos = start;     // �趨��ǰλ��Ϊ"����λ��"
    curStep = 1;        // ̽����һ��
    
    do {
        // �����ǰλ�ÿ�ͨ����Ҫ���λ���Ǵ�δ��̽����ͨ���飩
        if(Pass(maze, curPos)) {
            // ���³�ʼ�㼣���������򶫷��ʵı��
            FootPrint(maze, curPos);
            
            // ����һ��ͨ������Ϣ������
            e = Construct(curStep, curPos, East);
            
            // ����·��
            Push(&S, e);
            
            // ��������յ�
            if(Equals(curPos, end) == TRUE) {
                printf("\nѰ·�ɹ�����\n\n");
                return TRUE;
            }
            
            // ��ȡ��һ��Ӧ��̽����λ�ã�����ǰλ�õĶ���
            curPos = NextPos(curPos, East);
            
            // ̽����һ��
            curStep++;
            
            // �����ǰλ���Ѿ�̽�����ˣ������޸�̽������
        } else {
            // ���ջ��Ϊ�գ�����̽���ı�Ҫ��
            if(!StackEmpty(S)) {
                // ���˵���һ��λ��
                Pop(&S, &e);
                
                // �����̽��λ�õ�4������̽����������Ҫ�����
                while(e.di == North && !StackEmpty(S)) {
                    // ����"����ͬ"��ǣ����Ӹ�λ�ó�����·����û��ͨ·
                    MarkPrint(maze, e.seat, Impasse);
                    
                    // ��������
                    Pop(&S, &e);
                }
                
                // �����̽��λ�û���ʣ���̽���ķ���
                if(e.di < North) {
                    // �ı�̽�����򣬰����������ķ�����ѯ
                    ++e.di;
                    
                    // ���Թ������·��ʱ�ǣ������۲��Թ�״̬���̲���û�иò��裩
                    MarkPrint(maze, e.seat, e.di);
                    
                    // ���½���λ�ü��뵽·����
                    Push(&S, e);
                    
                    // ��ȡ��һ��Ӧ��̽����λ��
                    curPos = NextPos(e.seat, e.di);
                }
            }
        }
        
        // ջ��Ϊ�գ���ζ�Ż���̽���ı�Ҫ
    } while(!StackEmpty(S));
    
    printf("\nѰ·ʧ�ܣ���\n\n");
    
    return FALSE;
}

/*
 * ��ʼ��һ����ģΪN��N�Թ�
 * start��end�ֱ�Ϊ�Թ����������ͳ�������
 *
 *��ע��
 * �̲����޴˲��������ò����Ǳ�����ڵ�
 */
void InitMaze(MazeType maze, PosType* start, PosType* end) {
    int i, j, tmp;
    
    srand((unsigned) time(NULL));                // ��ϵͳʱ�������������
    
    for(i = 0; i < M; i++) {
        for(j = 0; j < N; j++) {
            
            // ���Թ������������ǽ
            if(i == 0 || j == 0 || i == M - 1 || j == N - 1) {
                maze[i][j] = Wall;
                
                // �Թ��ڲ������
            } else {
                tmp = rand() % X;   // ���������[0, X-1]����Թ�
                
                if(tmp == 0) {
                    // 1/X�ĸ��������ϰ�
                    maze[i][j] = Obstacle;
                } else {
                    // �����ط���Ϊ�ɱ�����ͨ·
                    maze[i][j] = Way;
                }
            }
        }
    }
    
    // �Թ��������
    (*start).x = 1;
    (*start).y = 0;
    
    // �Թ���������
    (*end).x = M - 2;
    (*end).y = N - 1;
    
    // ������ںͳ���
    maze[1][0] = maze[M - 2][N - 1] = Way;
    
    // Ϊ�����Ѱ·�ɹ��ʣ�����ڴ��ͳ��ڴ��ٽ��Ľ����Ϊͨ·���Ǳ��������
    maze[1][1] = maze[M - 2][N - 2] = Way;
    
    // ��ʾ�Թ��ĳ�ʼ״̬
    PaintMaze(maze);
}

/*
 * �жϵ�ǰλ���Ƿ��ͨ����Ҫ���λ���Ǵ�δ��̽����ͨ����
 *
 *��ע��
 * �����Ϊ�жϵ�ǰλ���Ƿ�Ϊ�״�̽��
 */
Status Pass(MazeType maze, PosType seat) {
    int x = seat.x;
    int y = seat.y;
    
    // ���ȼ���Ƿ�Խ�磬�����Խ���ˣ���ǰλ�ÿ϶��޷�ͨ��
    if(x < 0 || y < 0 || x > M - 1 || y > N - 1) {
        return FALSE;                    //Խ��
    }
    
    // Ҫ���λ�ñ����Ǵ�δ��̽����ͨ����
    if(maze[x][y] != Way) {
        return FALSE;
    }
    
    return TRUE;
}

/*
 * ��ȡ��һ��Ӧ��̽����λ��
 * diָʾ��ǰ����λ�õ�̽�����򣬰���East, South, West, North
 */
PosType NextPos(PosType seat, int di) {
    PosType tmp = seat;
    
    switch(di) {
        case East:
            tmp.y++;            //��
            break;
        case South:
            tmp.x++;            //����
            break;
        case West:
            tmp.y--;            //����
            break;
        case North:
            tmp.x--;            //��
            break;
    }
    
    return tmp;
}

/*
 * ���³�ʼ�����㼣
 *
 * ��ʼ�����㼣���򶫷���
 */
void FootPrint(MazeType maze, PosType seat) {
    //��ʼ������̽��
    MarkPrint(maze, seat, East);
}

/*
 * ���Թ���seat������mark���
 *
 *��ע��
 * �ú�����̲��ϵĺ���������
 * �̲���ֻ���ô˺�������"����̽��"�ı��
 * ���˴��ĺ����Ľ�Ϊ�������������ǣ�����̽������ı��
 */
void MarkPrint(MazeType maze, PosType seat, int mark) {
    int x = seat.x;
    int y = seat.y;
    
    maze[x][y] = mark;                //���²���ͨ���ı��
    
    // �����Թ�
    PaintMaze(maze);
}

/*
 * ����һ��ͨ������Ϣ������
 *
 *��ע��
 * �̲����д˲��������޴˺���
 */
SElemType Construct(int ord, PosType seat, int di) {
    SElemType e;
    
    e.ord = ord;
    e.seat = seat;
    e.di = di;
    
    return e;
}

/*
 * �ж����������Ƿ����
 *
 *��ע��
 * �̲����д˲��������޴˺���
 * ��Ϊ������Ҫ�Ƚ������ṹ�壬���Բ���ֱ����"=="����
 */
Status Equals(PosType seat1, PosType seat2) {
    if(seat1.x == seat2.x && seat1.y == seat2.y) {
        return TRUE;
    } else {
        return ERROR;
    }
}

/*
 * �����Թ�
 * ��ͼ�εķ�ʽ�����Թ���ǰ��״̬
 *
 *��ע��
 * 1.�̲����޴˲������˴����Ӹò�����Ŀ���ǹ۲�Ѱ·���̵�ÿһ��
 * 2.��ʵ��������CLion�Ŀ���̨
 */
void PaintMaze(MazeType maze) {
    int i, j;
    
    Wait(SleepTime);                // ��ͣһ��
    
	system("cls");					// �������Ļ�������� 

    for(i = 0; i < M; i++) {
        for(j = 0; j < N; j++) {
            if(maze[i][j] == Wall) {                   // ��ǽ
                printf("�~");
            } else if(maze[i][j] == Obstacle) {        // �Թ��ڲ����ϰ�
                printf("��");
            } else if(maze[i][j] == East) {            // ���ڳ���̽��
                printf("��");
            } else if(maze[i][j] == South) {           // ���ڳ���̽��
                printf("��");
            } else if(maze[i][j] == West) {            // ���ڳ���̽��
                printf("��");
            } else if(maze[i][j] == North) {           // ���ڳ���̽��
                printf("��");
            } else if(maze[i][j] == Impasse) {         // ����ͬ�����ĸ�����̽���������޷�ͨ����λ��
                printf("��");
            } else {                                   // ��δ̽������·�����
                printf("��");
            }
            
            if(j != 0 && j % (N - 1) == 0) {           // ÿ��N����㻻��
                printf("\n");
            }
        }
    }
    
    printf("\n");
}
