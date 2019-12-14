/*********************************
 *					             *
 * �ļ���: ��03 ջ�Ͷ���\04 Maze *
 * 					             *
 * �ļ���: Maze.c                *
 * 				                 *
 * ��  ��: 3.3                   *
 *                               *
 *********************************/

#ifndef MAZE_C
#define MAZE_C

#include "Maze.h"							//**��03 ջ�Ͷ���**//

/*�T�T�T�T�[
�U �㷨3.3�U 
�^�T�T�T�T*/
Status MazePath(MazeType maze[][N], PosType start, PosType end)
{
	SqStack S;
	SElemType_Sq nodeInf;					//nodeInf�洢��ǰͨ������Ϣ 
	PosType curPos;							//��ǰλ�� 
	int curStep;							//��ǰͨ������� 
	
	InitStack_Sq(&S);
	curPos = start;							//�趨��ǰλ��Ϊ"����λ��" 
	curStep = 1;
	
	do
	{
		if(Pass(curPos, maze))				//��ǰλ�ÿ�ͨ��������δ�����ʵ�ͨ���� 
		{
			FootPrint(curPos, maze);		//�����㼣
			ShowMaze(maze); 

			SetSElemType(&nodeInf, curStep, curPos, East);	//����ͨ������Ϣ
			Push_Sq(&S, nodeInf); 			//����·�� 

			if(EqualPosType(curPos, end))	//�����յ�
			{
				printf("\nѰ·�ɹ�����\n\n");
				return TRUE;	
			}
			
			curPos = NextPos(curPos, East);	//��һλ���ǵ�ǰλ�õĶ��� 
			curStep++;						//̽����һ�� 
		}
		else								//��ǰλ�ò���ͨ�� 
		{
			if(!StackEmpty_Sq(S))
			{
				Pop_Sq(&S, &nodeInf);		//�޸Ľ��ָ��
				 
				while(nodeInf.di==North && !StackEmpty_Sq(S))	//��ͨ����4�����򶼱����� 
				{
					MarkPrint(nodeInf.seat, maze);				//���²���ͨ���ı�ǣ����˻�һ�� 
					ShowMaze(maze);

					Pop_Sq(&S, &nodeInf);
				}

				if(nodeInf.di<North)
				{
					maze[nodeInf.seat.x][nodeInf.seat.y] = ++nodeInf.di;//�ı�̽���������Թ����������±��	
					ShowMaze(maze);

					Push_Sq(&S, nodeInf);

					curPos = NextPos(nodeInf.seat, nodeInf.di);
				}
			}
		}		
	}while(!StackEmpty_Sq(S));	
	
	printf("\nѰ·ʧ�ܣ���\n\n");
	
	return FALSE;	
}

void InitMaze(MazeType maze[][N], PosType *start, PosType *end) 
{												//�Թ���ģΪN��N 
	int i, j, tmp;
		
	srand((unsigned)time(NULL));				//��ϵͳʱ������������� 
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(i==0 || j==0 || i==N-1 || j==N-1)
				maze[i][j] = Wall;				//�Թ���ǽ
			else
			{
				tmp = rand()%X;					//�������������Թ� 		
				if(!tmp)
					maze[i][j] = Obstacle;		//1/X�ĸ��������ϰ� 
				else
					maze[i][j] = Way;			//�����ط�����·�� 
			}
		}	
	}
	
	(*start).x = 1;								//�Թ����
	(*start).y = 0;
	(*end).x = N-2;								//�Թ����� 
	(*end).y = N-1;	
	
	maze[1][0] = maze[N-2][N-1] = Way;			//������ںͳ��� 
	maze[1][1] = maze[N-2][N-2] = Way;			//Ϊ����߳ɹ��ʣ���ڴ��ͳ��ڴ��ٽ��Ľ��һֱ��Ϊͨ· 
}

void PaintMaze(MazeType maze[][N])
{
	int i, j;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			if(maze[i][j]==Wall)				//��ǽ 
				printf("�~");
			else if(maze[i][j]==Obstacle)		//�ڲ��ϰ� 
				printf("��");
			else if(maze[i][j]==East)			//����̽��
				printf("��");
			else if(maze[i][j]==South)			//����̽��
				printf("��");
			else if(maze[i][j]==West)			//����̽��
				printf("��");
			else if(maze[i][j]==North)			//����̽��
				printf("��");
			else if(maze[i][j]==DeadLock)		//���ʹ��Ҳ���ͨ���Ľ�� 
				printf("��");
			else								//δ���ʹ���·����� 
				printf("  ");

			if(j!=0 && j%(N-1)==0)				//ÿ��N����㻻�� 
				printf("\n");
		}
}

void ShowMaze(MazeType maze[][N])	//�൱��ˢ�²��� 
{
	Wait(SleepTime);				//��ͣ 
	system("cls");					//�������Ļ�������� 
	PaintMaze(maze);				//����Ļ�ϻ����Թ� 
} 

Status EqualPosType(PosType seat1, PosType seat2)
{
	if(seat1.x==seat2.x && seat1.y==seat2.y)
		return TRUE;	//��ͨ����������ȷ���1 
	else
		return ERROR;
}

Status Pass(PosType seat, MazeType maze[][N])		 
{
	int x = seat.x;
	int y = seat.y;
	
	if(!IsCross(seat) && maze[x][y]==Way)	//��㲻��Խ��
		return TRUE;
	else
		return ERROR;
}

void FootPrint(PosType seat, MazeType maze[][N])	//��ν�����㼣����������һ�η��ʷ��� 
{	
	maze[seat.x][seat.y] = East; 					//��ʼ������̽�� 
} 

void SetSElemType (SElemType_Sq *e, int ord, PosType seat, int di)
{
	(*e).ord = ord;
	(*e).seat = seat;
	(*e).di = di;
}

PosType NextPos(PosType seat, int di)
{	
	PosType tmp = seat;

	switch(di)
	{
		case East:  tmp.y++;			//�� 
			break;	
		case South: tmp.x++;			//����
			break;
		case West:  tmp.y--;			//���� 
			break;
		case North: tmp.x--;			//��
			break;
	}
	
	return tmp;
}

Status IsCross(PosType seat)
{
	int x = seat.x;
	int y = seat.y;
	
	if(x<0 || y<0 || x>N-1 || y>N-1)
		return TRUE;					//Խ�� 
	else
		return FALSE; 
}

void MarkPrint(PosType seat, MazeType maze[][N])
{
	int x = seat.x;
	int y = seat.y;
	
	maze[x][y] = DeadLock;			    //���²���ͨ���ı�� 
}

#endif
