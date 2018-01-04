/*********************************
 *							     *
 * 文件夹: ▲03 栈和队列\04 Maze *
 * 							     *
 * 文件名: Maze.h                *
 * 							     *
 * 内  容: 迷宫相关操作列表      *
 *                               *
 *********************************/

#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>		
#include <stdlib.h> 					//提供system、rand、srand原型 
#include <time.h>						//提供time原型
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//

/* 宏定义 */ 
#define N 15							//迷宫的大小为N×N
#define X 4								//X用于随机数取余，其生成的随机数范围是0到X-1
															//X越大，生成可通行迷宫的概率就越大
#define SleepTime 3						//SleepTime代表休眠时间间隔

/* 迷宫类型定义 */
typedef enum							//迷宫通道块类型
{ 
	Wall,								//外墙 
	Obstacle,							//迷宫障碍 
	Way,								//路径 
	DeadLock,							//路径上的“死胡同” 
	East,South,West,North				//访问方向-东南西北 
}MazeNode;
typedef struct							//迷宫通道块坐标
{
	int x;								//通道块的横、纵坐标定义 
	int y;
}PosType;
typedef struct							//通道块信息 
{
	int		ord;						//通道块的“序号” 
	PosType seat;						//通道块的“坐标位置” 
	int		di;							//下一个该访问的“方向” 
}SElemType_Sq;
#include "../01 SequenceStack/SequenceStack.c" 	//**▲03 栈和队列**//
typedef int MazeType;					//迷宫元素类型 

/* 迷宫函数列表 */ 
Status MazePath(MazeType maze[][N], PosType start, PosType end); 
/*━━━━━━━━━━━━━━━━┓
┃(01)算法3.3：迷宫寻路（穷举法） ┃
┗━━━━━━━━━━━━━━━━*/

void InitMaze(MazeType maze[][N], PosType *start, PosType *end);
/*━━━━━━━━━━━━━━━━━━┓
┃(02)迷宫的初始化,包括出入口的初始化 ┃
┗━━━━━━━━━━━━━━━━━━*/

void PaintMaze(MazeType maze[][N]);
/*━━━━━━━━━━┓
┃(03)在屏幕上画出迷宫┃
┗━━━━━━━━━━*/

void ShowMaze(MazeType maze[][N]);
/*━━━━━━━┓
┃(04)迷宫的显示┃
┗━━━━━━━*/ 

Status EqualPosType(PosType a, PosType b);
/*━━━━━━━━━━━━━━━━━━━┓
┃(05)比较迷宫中两个通道块是否为同一通道块┃
┗━━━━━━━━━━━━━━━━━━━*/ 

Status Pass(PosType seat, MazeType maze[][N]);
/*━━━━━━━━━━━━━┓
┃(06)判定此通道块是否未访问┃
┗━━━━━━━━━━━━━*/ 

void FootPrint(PosType seat, MazeType maze[][N]); 
/*━━━━━━━━━━━━━━━━┓
┃(07)遇到未访问结点时留下初始足迹┃
┗━━━━━━━━━━━━━━━━*/ 

void SetSElemType(SElemType_Sq *e, int ord, PosType seat, int di);
/*━━━━━━━━━━┓
┃(08)更新通道块的信息┃
┗━━━━━━━━━━*/ 

PosType NextPos(PosType seat, int di); 
/*━━━━━━━━━━┓
┃(09)当前通道块的后继┃
┗━━━━━━━━━━*/ 

Status IsCross(PosType seat);
/*━━━━━━━━━━━━┓
┃(10)判断当前位置是否越界┃
┗━━━━━━━━━━━━*/ 

void MarkPrint(PosType seat, MazeType maze[][N]);
/*━━━━━━━━━━━━━━━━━┓
┃(11)标记当前位置上的通道块不可访问┃
┗━━━━━━━━━━━━━━━━━*/  

#endif
