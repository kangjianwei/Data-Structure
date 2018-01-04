/**********************************
 *                                *
 * 文件夹: ▲03 栈和队列\06 Hanoi *
 *                                *
 * 文件名: Hanoi.c                *
 *                                *
 * 算  法: 3.5                    * 
 *                                *
 **********************************/

#ifndef HANOI_C
#define HANOI_C

#include "Hanoi.h"						//**03 栈和队列**//

/*════╗
║ 算法3.5║ 
╚════*/
void hanoi(int n, char x, char y, char z)
{
	if(n==1)							//欲移动n个圆盘，需先移动其上的n-1个圆盘 
		move(x, 1, z);					//将编号为1的圆盘从x移到z 
	else
	{
		hanoi(n-1, x, z, y);			//将x上编号为1至n-1的圆盘移到y，z作辅助塔 
		move(x, n, z);					//将编号为n的圆盘从x移到z 
		hanoi(n-1, y, x, z);			//将y上编号为1至n-1的圆盘移动到z，x作辅助塔 
	}	
} 

void move(char x, int n, char z)
{
	gStep++;							//step为全局变量，在main函数之外定义 
	printf("第%2d步：将第 %d 个圆盘从 %c 移到 %c \n", gStep, n, x, z); 
} 

#endif
