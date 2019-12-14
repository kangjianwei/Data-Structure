/**************************************
 *							          *
 * 文件夹: ▲06 树和二叉树\11 NQueens *
 * 							          *
 * 文件名: NQueens.h                  *
 * 							          *
 * 内  容: N皇后问题相关操作列表      *
 *                                    *
 *************************************/

#ifndef NQUEENS_H
#define NQUEENS_H

#include <stdio.h>
#include "../../▲01 绪论/Status.h"				//**▲01 绪论**//

/* 宏定义 */
#define N 8										//棋盘最大范围N*N

/* N皇后问题类型定义 */
typedef int ChessBoard;							//棋盘类型 

/* 全局变量 */
int order;										//跟踪每一种解法 

/* N皇后问题函数列表 */ 
void InitChessBoard_CB(ChessBoard c[N][N]);
/*━━━━━━━━━━━┓
┃(01)初始化N*N的棋盘c。┃
┗━━━━━━━━━━━*/

void Trial_CB(int i, ChessBoard c[N][N]);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法6.16：在指定大小棋盘上求出N皇后问题的各解。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status Layout_CB(int x, int y, ChessBoard c[N][N]);
/*━━━━━━━━━━━━━━━━━━━━━━┓
┃(03)判断在x行y列放入棋子后棋盘布局是否合理。┃
┗━━━━━━━━━━━━━━━━━━━━━━*/

void Output_CB(ChessBoard c[N][N]);
/*━━━━━━━━━━━━━┓
┃(04)展示棋盘中的皇后布局。┃
┗━━━━━━━━━━━━━*/

#endif
