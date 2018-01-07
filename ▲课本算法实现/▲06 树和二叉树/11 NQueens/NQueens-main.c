/**************************************
 *							          *
 * 文件夹: ▲06 树和二叉树\11 NQueens *
 * 							          *
 * 文件名: NQueens-main.c             *
 * 							          *
 * 内  容: N皇后问题相关函数测        *
 *                                    *
 *************************************/

#include <stdio.h>
#include "NQueens.c" 										//**▲06 树和二叉树**//

int main(int argc, char *argv[])
{
	ChessBoard c[N][N];
	
	printf("▼1\n▲函数 InitChessBoard_CB 测试...\n");		//1.函数InitChessBoard_CB测试
	{
		printf("初始化一个 %2d * %-2d 的空棋盘...\n", N, N);
		InitChessBoard_CB(c);
		printf("\n");
	}
	PressEnter;	

	printf("▼4\n▲函数 Output_CB 测试...\n");				//4.函数Output_CB测试
	{ 
		printf("展示当前棋盘中的皇后布局...\n");
		Output_CB(c);
		printf("\n");
	}
	PressEnter;	

	printf("▼2、3\n▲函数 Trial_CB等 测试...\n");			//2、3.函数Trial_CB、Layout_CB测试
	{
		printf("计算N皇后问题的各解...\n");
		Trial_CB(1, c);
		printf("\n");
	}
	PressEnter;
}
