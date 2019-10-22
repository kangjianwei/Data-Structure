/*==============
 * 迷宫寻路程序
 *
 * 包含算法: 3.3
 ===============*/

#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>         // 提供system、rand、srand原型
#include <time.h>           // 提供time原型
#include "Status.h"         //**▲01 绪论**//
#include "SqStack.h"        //**▲03 栈和队列**//

/* 宏定义 */
#define M 15    // 迷宫的行数
#define N 30    // 迷宫的列数

#define X 4     // X指示迷宫障碍出现的概率。例如，X=4，意味着遍历迷宫时遇到障碍的概率是1/4=25%

#define SleepTime 3     //SleepTime代表打印地图时的时间间隔

/* 迷宫类型定义 */
typedef enum {
    Wall,                       // 外墙
    Obstacle,                   // 迷宫内部的障碍
    Way,                        // 通路
    Impasse,                    // “死胡同”
    East, South, West, North    // 当前探索方向：东南西北
} MazeNode;

typedef int MazeType[M][N];      // 迷宫类型


/*
 * ████████ 算法3.3 ████████
 *
 * 迷宫寻路
 *
 * 使用穷举法，找到一条可行通路即返回
 */
Status MazePath(MazeType maze, PosType start, PosType end);

/*
 * 初始化一个规模为N×N迷宫
 * start和end分别为迷宫的入口坐标和出口坐标
 *
 *【注】
 * 教材中无此操作，但该操作是必须存在的
 */
void InitMaze(MazeType maze, PosType* start, PosType* end);

/*
 * 判断当前位置是否可通过：要求该位置是从未曾探索的通道块
 *
 *【注】
 * 可理解为判断当前位置是否为首次探索
 */
Status Pass(MazeType maze, PosType seat);

/*
 * 获取下一个应当探索的位置
 * di指示当前所处位置的探索方向，包括East, South, West, North
 */
PosType NextPos(PosType seat, int di);

/*
 * 留下初始访问足迹
 *
 * 初始访问足迹即向东访问
 */
void FootPrint(MazeType maze, PosType seat);

/*
 * 在迷宫的seat处留下mark标记
 *
 *【注】
 * 该函数与教材上的函数有区别
 * 教材上只是用此函数留下"不可探索"的标记
 * 而此处的函数改进为可以留下任意标记，包括探索方向的标记
 */
void MarkPrint(MazeType maze, PosType seat, int mark);

/*
 * 构造一个通道块信息并返回
 *
 *【注】
 * 教材中有此操作，但无此函数
 */
SElemType Construct(int ord, PosType seat, int di);

/*
 * 判断两个坐标是否相等
 *
 *【注】
 * 教材中有此操作，但无此函数
 * 因为这里需要比较两个结构体，所以不能直接用"=="符号
 */
Status Equals(PosType a, PosType b);

/*
 * 绘制迷宫
 * 以图形的方式呈现迷宫当前的状态
 *
 *【注】
 * 教材中无此操作
 * 此处增加该操作的目的是观察寻路过程的每一步
 */
void PaintMaze(MazeType maze);

#endif
