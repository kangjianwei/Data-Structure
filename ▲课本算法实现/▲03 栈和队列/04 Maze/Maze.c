/*********************************
 *					             *
 * 文件夹: ▲03 栈和队列\04 Maze *
 * 					             *
 * 文件名: Maze.c                *
 * 				                 *
 * 算  法: 3.3                   *
 *                               *
 *********************************/

#ifndef MAZE_C
#define MAZE_C

#include "Maze.h"							//**▲03 栈和队列**//

/*════╗
║ 算法3.3║ 
╚════*/
Status MazePath(MazeType maze[][N], PosType start, PosType end)
{
	SqStack S;
	SElemType_Sq nodeInf;					//nodeInf存储当前通道块信息 
	PosType curPos;							//当前位置 
	int curStep;							//当前通道块序号 
	
	InitStack_Sq(&S);
	curPos = start;							//设定当前位置为"出口位置" 
	curStep = 1;
	
	do
	{
		if(Pass(curPos, maze))				//当前位置可通过，即是未曾访问的通道块 
		{
			FootPrint(curPos, maze);		//留下足迹
			ShowMaze(maze); 

			SetSElemType(&nodeInf, curStep, curPos, East);	//设置通道块信息
			Push_Sq(&S, nodeInf); 			//加入路径 

			if(EqualPosType(curPos, end))	//到达终点
			{
				printf("\n寻路成功！！\n\n");
				return TRUE;	
			}
			
			curPos = NextPos(curPos, East);	//下一位置是当前位置的东邻 
			curStep++;						//探索下一步 
		}
		else								//当前位置不能通过 
		{
			if(!StackEmpty_Sq(S))
			{
				Pop_Sq(&S, &nodeInf);		//修改结点指向
				 
				while(nodeInf.di==North && !StackEmpty_Sq(S))	//此通道块4个方向都遍历过 
				{
					MarkPrint(nodeInf.seat, maze);				//留下不能通过的标记，并退回一步 
					ShowMaze(maze);

					Pop_Sq(&S, &nodeInf);
				}

				if(nodeInf.di<North)
				{
					maze[nodeInf.seat.x][nodeInf.seat.y] = ++nodeInf.di;//改变探索方向，在迷宫数组中留下标记	
					ShowMaze(maze);

					Push_Sq(&S, nodeInf);

					curPos = NextPos(nodeInf.seat, nodeInf.di);
				}
			}
		}		
	}while(!StackEmpty_Sq(S));	
	
	printf("\n寻路失败！！\n\n");
	
	return FALSE;	
}

void InitMaze(MazeType maze[][N], PosType *start, PosType *end) 
{												//迷宫规模为N×N 
	int i, j, tmp;
		
	srand((unsigned)time(NULL));				//用系统时间做随机数种子 
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(i==0 || j==0 || i==N-1 || j==N-1)
				maze[i][j] = Wall;				//迷宫外墙
			else
			{
				tmp = rand()%X;					//生成随机数填充迷宫 		
				if(!tmp)
					maze[i][j] = Obstacle;		//1/X的概率生成障碍 
				else
					maze[i][j] = Way;			//其它地方加入路径 
			}
		}	
	}
	
	(*start).x = 1;								//迷宫入口
	(*start).y = 0;
	(*end).x = N-2;								//迷宫出口 
	(*end).y = N-1;	
	
	maze[1][0] = maze[N-2][N-1] = Way;			//开放入口和出口 
	maze[1][1] = maze[N-2][N-2] = Way;			//为了提高成功率，入口处和出口处临近的结点一直设为通路 
}

void PaintMaze(MazeType maze[][N])
{
	int i, j;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			if(maze[i][j]==Wall)				//外墙 
				printf("▇");
			else if(maze[i][j]==Obstacle)		//内部障碍 
				printf("▓");
			else if(maze[i][j]==East)			//朝东探索
				printf("→");
			else if(maze[i][j]==South)			//朝南探索
				printf("↓");
			else if(maze[i][j]==West)			//朝西探索
				printf("←");
			else if(maze[i][j]==North)			//朝北探索
				printf("↑");
			else if(maze[i][j]==DeadLock)		//访问过且不能通过的结点 
				printf("★");
			else								//未访问过的路径结点 
				printf("  ");

			if(j!=0 && j%(N-1)==0)				//每隔N个结点换行 
				printf("\n");
		}
}

void ShowMaze(MazeType maze[][N])	//相当于刷新操作 
{
	Wait(SleepTime);				//暂停 
	system("cls");					//先清除屏幕现有内容 
	PaintMaze(maze);				//在屏幕上画出迷宫 
} 

Status EqualPosType(PosType seat1, PosType seat2)
{
	if(seat1.x==seat2.x && seat1.y==seat2.y)
		return TRUE;	//两通道块坐标相等返回1 
	else
		return ERROR;
}

Status Pass(PosType seat, MazeType maze[][N])		 
{
	int x = seat.x;
	int y = seat.y;
	
	if(!IsCross(seat) && maze[x][y]==Way)	//结点不能越界
		return TRUE;
	else
		return ERROR;
}

void FootPrint(PosType seat, MazeType maze[][N])	//所谓留下足迹即设置其下一次访问方向 
{	
	maze[seat.x][seat.y] = East; 					//初始设置向东探索 
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
		case East:  tmp.y++;			//向东 
			break;	
		case South: tmp.x++;			//向南
			break;
		case West:  tmp.y--;			//向西 
			break;
		case North: tmp.x--;			//向北
			break;
	}
	
	return tmp;
}

Status IsCross(PosType seat)
{
	int x = seat.x;
	int y = seat.y;
	
	if(x<0 || y<0 || x>N-1 || y>N-1)
		return TRUE;					//越界 
	else
		return FALSE; 
}

void MarkPrint(PosType seat, MazeType maze[][N])
{
	int x = seat.x;
	int y = seat.y;
	
	maze[x][y] = DeadLock;			    //留下不能通过的标记 
}

#endif
